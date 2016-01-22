## GCN Kernel Machine State

This chapter is describing the state of the machine compliant with GCN 1.0/1.1/1.2.


Table with available registers:

Name | Long name | Size | Description
-----|-----------|------|-----------------------
PC   | Program counter | 40 bits | Current instruction address in memory
V0-V255 | VGPR         | 32 bits | Vector general purpose register
S0-S103 | SGPR         | 32 bits | Scalar general purpose register (GCN 1.0/1.1)
S0-S101 | SGPR         | 32 bits | Scalar general purpose register (GCN 1.2)
LDS     | Local Data Share | 32 kB | Local Data Share memory (R/W)
EXEC    | Execute Mask | 64-bits | One bit of that mask control execution for one lane
EXECZ   | Execute Is Zero | 1 bit | Set if EXEC mask is zero
VCC     | Vector Condition Code | 64-bits | Bit mask with bit per lane
VCCZ    | VCC Is zero | 1 bit | Set if VCC is zero
SCC     | Scalar Condition Code | 1 bit | Condition code for scalar operations
FLAT_SCRATCH | Flat scratch address | 64 bits | The base address of scratch memory (GCN 1.1 or later)
XNACK_MASK | Address Trans. Failure | 64 bits | Bit indicates failure of address translation. Carrizo APU only
STATUS  | Status      | 32 bits | Read-only status register
MODE    | Mode        | 32 bits | R/W mode register
M0      | Memory Register | 32-bit | Additional register that used in various cases
TRAPSTS | Trap Status | 32 bits | Holds information about exceptions and pending traps.
TBA     | Trap Base Address | 64 bits | Pointer to current trap handler program
TMA     | Trap Memory Address | 64 bits | Temporary register for shader operations.
TTMP0-TTMP11 | Trap Temporary SGPRs | 32 bits | SGPRs only to the Trap Handler for temp. storage.
VMCNT   | VM Instruction Count | 4 bits | Counts the number of not completed VM instructions
EXPCNT  | Export Count        | 3 bits | 
LGKMCNT | LDS, GDS, Kmem, Message Count | 5 bits | Counts the number of LDS, GDS, K mem and message instrs.

## STATUS Register

Table of fields for STATUS Register:

 Bits   | Name      | Description
--------|-----------|------------------------------------
 1      | SCC       | Scalar condition code
 1-2    | SPI_PRIO  | Wavefront priority set by SPI while creating wave
 3-4    | WAVE_PRIO | Wavefront priority set by the shader program
 5      | PRIV      | Privileged mode
 6      | TRAP_EN   | Indicates that trap handler is present
 7      | TTRACE_EN | Indicates whether thread trace is enabled for this wavefront
 8      | EXPORT_RDY | ...
 9      | EXECZ     | Set if EXEC is zero
 10     | VCCZ      | Set if VCC is zero
 11     | IN_TG     | Set if workgroup is greater than one wavefront
 12     | IN_BARRIER | Set if wavefront waiting for barrier
 13     | HALT      | Wavefront is halted or scheduled to halt
 14     | TRAP      | Wavefront will be entered to trap handler as soon as possible
 15     | TTRACE_CU_EN | Enables/disables thread trace for this compute unit (CU)
 16     | VALID     | Wavefront is active
 17     | ECC_ERR   | An ECC error has occurred
 18     | SKIP_EXPORT | ???
 19     | PERF_EN   | Performance counters enabled for this wavefront
 20     | COND_DBG_USER | Conditional debug indicator for user mode
 21     | COND_DBG_SYS  | Conditional debug indicator for system mode
 22     | ALLOW_REPLAY | Indicates that ATC replay is enable
 23     | INST_ACC  | ???
 24-26  | DISPATCH_CACHE_CTRL | Indicates the cache policies for this dispatch
 27     | MUST_EXPORT | ???

## MODE Register

Table of fields for STATUS Register:

 Bits   | Name      | Description
--------|-----------|------------------------------------
 0-3    | FP_ROUND  | Set round modes for single and double precision
 4-7    | FP_DENORM | Set denormal mode for single and double precision
 8      | DX10_CLAMP | Treat NaNs as In DX10 mode (used by vector ALU)
 9      | IEEE      | IEEE mode ???
 10     | LOD_CLAMPED | Sticky bit for LOD clamping
 11     | DEBUG     | Forces the wavefront to jump to exception handler
 12-18  | EXCP_EN   | Enable mask for exceptions
 27     | GPR_IDX_EN | GPR index enable
 29-31  | CSP       | Conditional branch stack pointer

The single floating point rounding mode is controlled by 0-1 bits in MODE register.
A rounding mode for double precision is controlled by 2-3 bits. List of possible values:

 Value | Description
-------|---------------------------------
 0     | Nearest to even
 1     | +Infinity
 2     | -Infinity
 3     | Toward zero

The denormal mode for single precision controlled by 4-5 bits in MODE register. The 6-7
bits of MODE register controls denormal mode for double precision ops.
List of possible values:

 Value | Description
-------|---------------------------------
 0     | flush input and output denormals
 1     | allow input denormals, flush output denormals.
 2     | flush input denormals, allow output denormals
 3     | allow input and output denormals

The initial value of FP_ROUND and FP_DENORM fields (first 8 bits in MODE register)
can be given by including .floatmode pseudo-operation.
