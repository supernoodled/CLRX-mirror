## CLRadeonExtender CLRXWrapper

CLRXWrapper embeds and integrates the assembler into AMD Catalyst OpenCL implementation.
It make possible to call an assembler from OpenCL applications. Assembler will be called
when special build options will be added: `-xasm` or `-x asm`.

### Installation

By default, CLRXWrapper is not enabled. To enable CLRX wrapper few step should be done:

* remove `amdocl32.icd` or `amdocl64.icd` (if 64-bit systems) in `/etc/OpenCL/vendors`
directory
* write `clrx.icd` with content `libCLRXWrapper.so` in  `/etc/OpenCL/vendors`
directory

Before below steps, we recommend to make copy of `/etc/OpenCL/vendors` directory.

### Additional build options

* **-xasm**, **-x asm**

    compile program by using CLRX assembler

* **-D SYMBOL=[VALUE]**, **-defsym=SYMBOL[=VALUE]**

    Define symbol. Value is optional and if it is not given then assembler set 0 by default.
This option can be occurred many times to defining many symbols.

* **-I PATH**, **-includePath=PATH**

    Add an include path to search path list. Assembler begins search from current directory
and follows to next include paths.
This option can be occurred many times to adding many include paths.

* **-forceAddSymbols**

    Add all non-local symbols to binaries. By default any assembler does not add any symbols
to keep compatibility with original format.

* **-w**
    Do not print all warnings.

### Environment variables

* CLRX_FORCE_ORIGINAL_AMDOCL=1|0 - enable forcing of the original AMDOCL
* CLRX_AMDOCL_PATH=PATH - set path to AMDOCL library

### Usage

Sample call: `clBuildProgram(program, num_devices, devices, "-xasm", NULL, NULL);`