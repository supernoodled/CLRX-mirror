/*
 *  CLRadeonExtender - Unofficial OpenCL Radeon Extensions Library
 *  Copyright (C) 2014-2018 Mateusz Szpakowski
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <CLRX/Config.h>
#include "GCNAsmOpc.h"

const GCNAsmOpcodeCase encGCN15OpcodeCases[] =
{
    { "    s_add_u32  flat_scratch_lo, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  flat_scratch_hi, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  xnack_mask_lo, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  xnack_mask_hi, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "        s_add_u32       s21, s4, s61\n", 0x80153d04U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, s100\n", 0x80156404U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, s102\n", 0x80156604U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, s103\n", 0x80156704U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, s104\n", 0x80156804U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, s105\n", 0x80156904U, 0, false, true, "" },
    { "xrv = %s105; s_add_u32 s21, s4, xrv\n", 0x80156904U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, vcc_lo\n", 0x80156a04U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, vcc_hi\n", 0x80156b04U, 0, false, true, "" },
    { "    s_add_u32  s21, 0.15915494, s61", 0x80153df8U, 0, false, true, "" },
    { "vval=%0.15915494; s_add_u32  s21, vval, s61",
        0x80153df8U, 0, false, true, "" },
    { "        s_add_u32       s21, s4, null\n", 0x80157d04U, 0, false, true, "" },
    { "        s_add_u32       s21, null, s61\n", 0x80153d7dU, 0, false, true, "" },
    { "        s_add_u32       null, s4, s61\n", 0x807d3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc[1:1], s4, s61", 0x806b3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc[1], s4, s61", 0x806b3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc[0:0], s4, s61", 0x806a3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc[0], s4, s61", 0x806a3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc_lo, s4, s61", 0x806a3d04U, 0, false, true, "" },
    { "    s_add_u32  vcc_hi, s4, s61", 0x806b3d04U, 0, false, true, "" },
    { "    s_add_u32  ttmp0, s4, s61", 0x806c3d04U, 0, false, true, "" },
    { "    s_add_u32  ttmp1, s4, s61", 0x806d3d04U, 0, false, true, "" },
    { "    s_add_u32  ttmp[2:2], s4, s61", 0x806e3d04U, 0, false, true, "" },
    { "    s_add_u32  ttmp12, s4, s61", 0x80783d04U, 0, false, true, "" },
    { "    s_add_u32  ttmp15, s4, s61", 0x807b3d04U, 0, false, true, "" },
    { "s_add_u32 ttmp16, s4, s61", 0x807b3d04U, 0, false, false,
        "test.s:1:11: Error: TTMPRegister number out of range (0-15)\n" },
    { "    s_add_u32  tba_lo, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  tba_hi, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  tma_lo, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "    s_add_u32  tma_hi, s4, s61", 0, 0, false, false,
        "test.s:1:16: Error: Expected 1 scalar register\n" },
    { "s_add_u32 s21, shared_base, s61\n", 0x80153debU, 0, false, true, "" },
    { "s_add_u32 s21, src_shared_base, s61\n", 0x80153debU, 0, false, true, "" },
    { "s_add_u32 s21, shared_limit, s61\n", 0x80153decU, 0, false, true, "" },
    { "s_add_u32 s21, src_shared_limit, s61\n", 0x80153decU, 0, false, true, "" },
    { "s_add_u32 s21, private_base, s61\n", 0x80153dedU, 0, false, true, "" },
    { "s_add_u32 s21, src_private_base, s61\n", 0x80153dedU, 0, false, true, "" },
    { "s_add_u32 s21, private_limit, s61\n", 0x80153deeU, 0, false, true, "" },
    { "s_add_u32 s21, src_private_limit, s61\n", 0x80153deeU, 0, false, true, "" },
    { "s_add_u32 s21, pops_exiting_wave_id, s61\n", 0x80153defU, 0, false, true, "" },
    { "s_add_u32 s21, src_pops_exiting_wave_id, s61\n", 0x80153defU, 0, false, true, "" },
    { "s_add_u32 s21, execz, s61\n", 0x80153dfcU, 0, false, true, "" },
    { "s_add_u32 s21, src_execz, s61\n", 0x80153dfcU, 0, false, true, "" },
    { "s_add_u32 s21, vccz, s61\n", 0x80153dfbU, 0, false, true, "" },
    { "s_add_u32 s21, src_vccz, s61\n", 0x80153dfbU, 0, false, true, "" },
    { "s_add_u32 s21, scc, s61\n", 0x80153dfdU, 0, false, true, "" },
    { "s_add_u32 s21, src_scc, s61\n", 0x80153dfdU, 0, false, true, "" },
    /* register's symbols */
    { "zx=%s[20:23]; ss=%s4; b=%s[57:67];s_add_u32  zx[1], ss, b[4]",
            0x80153d04U, 0, false, true, "" },
    { "xv=2; zx=%s[xv+18:xv+19]; ss=%s[xv+2]; b=%s[xv+55:xv+65];"
        "s_add_u32  zx[1], ss, b[4]", 0x80153d04U, 0, false, true, "" },
    { "zx=%s[20:23]; ss=%execz; b=%s[57:67];s_add_u32  zx[1], ss, b[4]",
            0x80153dfcU, 0, false, true, "" },
    /* literals */
    { "    s_add_u32  s21, s4, 0x2a", 0x8015aa04U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, -7", 0x8015c704U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, lit(-7)", 0x8015ff04U, 0xfffffff9, true, true, "" },
    { "    s_add_u32_e64  s21, s4, -7", 0x8015ff04U, 0xfffffff9, true, true, "" },
    { "    s_add_u32  s21, s4, lit(0)", 0x8015ff04U, 0x0, true, true, "" },
    { "    s_add_u32  s21, s4, lit(32)", 0x8015ff04U, 0x20, true, true, "" },
    { "    s_add_u32_e64 s21, s4, 32", 0x8015ff04U, 0x20, true, true, "" },
    { "    s_add_u32_e64 s21, 32, s4", 0x801504ffU, 0x20, true, true, "" },
    { "    s_add_u32  s21, s4, lit  (  32  )  ", 0x8015ff04U, 0x20, true, true, "" },
    { "    s_add_u32  s21, s4, LiT  (  32  )  ", 0x8015ff04U, 0x20, true, true, "" },
    { "    s_add_u32  s21, s4, lit(0.0)", 0x8015ff04U, 0x0, true, true, "" },
    { "    s_add_u32  s21, s4, lit(-.5)", 0x8015ff04U, 0xbf000000, true, true, "" },
    { "    s_add_u32_e64  s21, s4, -.5", 0x8015ff04U, 0xbf000000, true, true, "" },
    { "    s_add_u32  s21, s4, lit(2.0)", 0x8015ff04U, 0x40000000, true, true, "" },
    { "    s_add_u32  s21, s4, lit  ( 2.0 )", 0x8015ff04U, 0x40000000, true, true, "" },
    { "    s_add_u32_e64  s21, s4, 2.0", 0x8015ff04U, 0x40000000, true, true, "" },
    { "    s_add_u32  s21, s4, 1.", 0x8015f204U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, -1.", 0x8015f304U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, 2.", 0x8015f404U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, -2.", 0x8015f504U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, 4.", 0x8015f604U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, -4.", 0x8015f704U, 0, false, true, "" },
    { "    s_add_u32  s21, s4, 1234", 0x8015ff04U, 1234, true, true, "" },
    { "    s_add_u32  s21, 1234, s4", 0x801504ffU, 1234, true, true, "" },
    { "    s_add_u32  s21, s4, -4.5", 0x8015ff04U, 0xc0900000U, true, true, "" },
    { "    s_add_u32  s21, s4, -4.5s", 0x8015ff04U, 0xc0900000U, true, true, "" },
    { "    s_add_u32  s21, s4, -4.5h", 0x8015ff04U, 0xc480U, true, true, "" },
    { "    s_add_u32  s21, s4, 3e-7", 0x8015ff04U, 0x34a10fb0U, true, true, "" },
    /* 64-bit registers and literals */
    { "    s_xor_b64 s[22:23], s[4:5], s[62:63]\n", 0x89963e04U, 0, false, true, "" },
    { "s1=22; s2=4;s3=62;s_xor_b64 s[s1:s1+1], s[s2:s2+1], s[s3:s3+1]\n",
        0x89963e04U, 0, false, true, "" },
    { "    s_xor_b64 vcc, s[4:5], s[62:63]\n", 0x89ea3e04U, 0, false, true, "" },
    { "    s_xor_b64 vcc[0:1], s[4:5], s[62:63]\n", 0x89ea3e04U, 0, false, true, "" },
    { "    s_xor_b64 s[22:23], 1.0, s[62:63]\n", 0x89963ef2U, 0, false, true, "" },
    { "    s_xor_b64 s[22:23], vccz, s[62:63]\n", 0x89963efbU, 0, false, true, "" },
    { "    s_xor_b64 s[22:23], execz, s[62:63]\n", 0x89963efcU, 0, false, true, "" },
    { "    s_xor_b64 s[22:23], scc, s[62:63]\n", 0x89963efdU, 0, false, true, "" },
    /* SOP2 encodings */
    { "    s_sub_u32  s21, s4, s61", 0x80953d04U, 0, false, true, "" },
    { "    s_sub_u32_e32  s21, s4, s61", 0x80953d04U, 0, false, true, "" },
    { "    s_add_i32  s21, s4, s61", 0x81153d04U, 0, false, true, "" },
    { "    s_sub_i32  s21, s4, s61", 0x81953d04U, 0, false, true, "" },
    { "    s_addc_u32  s21, s4, s61", 0x82153d04U, 0, false, true, "" },
    { "    s_subb_u32  s21, s4, s61", 0x82953d04U, 0, false, true, "" },
    { "    s_min_i32  s21, s4, s61", 0x83153d04U, 0, false, true, "" },
    { "    s_min_u32  s21, s4, s61", 0x83953d04U, 0, false, true, "" },
    { "    s_max_i32  s21, s4, s61", 0x84153d04U, 0, false, true, "" },
    { "    s_max_u32  s21, s4, s61", 0x84953d04U, 0, false, true, "" },
    { "    s_cselect_b32  s21, s4, s61", 0x85153d04U, 0, false, true, "" },
    { "    s_cselect_b64  s[20:21], s[4:5], s[62:63]", 0x85943e04U, 0, false, true, "" },
    { "    s_and_b32  s21, s4, s61", 0x87153d04U, 0, false, true, "" },
    { "    s_and_b64  s[20:21], s[4:5], s[62:63]", 0x87943e04U, 0, false, true, "" },
    { "    s_or_b32  s21, s4, s61", 0x88153d04U, 0, false, true, "" },
    { "    s_or_b64  s[20:21], s[4:5], s[62:63]", 0x88943e04U, 0, false, true, "" },
    { "    s_xor_b32  s21, s4, s61", 0x89153d04U, 0, false, true, "" },
    { "    s_xor_b64  s[20:21], s[4:5], s[62:63]", 0x89943e04U, 0, false, true, "" },
    { "    s_andn2_b32  s21, s4, s61", 0x8a153d04U, 0, false, true, "" },
    { "    s_andn2_b64  s[20:21], s[4:5], s[62:63]", 0x8a943e04U, 0, false, true, "" },
    { "    s_orn2_b32  s21, s4, s61", 0x8b153d04U, 0, false, true, "" },
    { "    s_orn2_b64  s[20:21], s[4:5], s[62:63]", 0x8b943e04U, 0, false, true, "" },
    { "    s_nand_b32  s21, s4, s61", 0x8c153d04U, 0, false, true, "" },
    { "    s_nand_b64  s[20:21], s[4:5], s[62:63]", 0x8c943e04U, 0, false, true, "" },
    { "    s_nor_b32  s21, s4, s61", 0x8d153d04U, 0, false, true, "" },
    { "    s_nor_b64  s[20:21], s[4:5], s[62:63]", 0x8d943e04U, 0, false, true, "" },
    { "    s_xnor_b32  s21, s4, s61", 0x8e153d04U, 0, false, true, "" },
    { "    s_xnor_b64  s[20:21], s[4:5], s[62:63]", 0x8e943e04U, 0, false, true, "" },
    { "    s_lshl_b32  s21, s4, s61", 0x8f153d04U, 0, false, true, "" },
    { "    s_lshl_b64  s[20:21], s[4:5], s61", 0x8f943d04U, 0, false, true, "" },
    { "    s_lshr_b32  s21, s4, s61", 0x90153d04U, 0, false, true, "" },
    { "    s_lshr_b64  s[20:21], s[4:5], s61", 0x90943d04U, 0, false, true, "" },
    { "    s_ashr_i32  s21, s4, s61", 0x91153d04U, 0, false, true, "" },
    { "    s_ashr_i64  s[20:21], s[4:5], s61", 0x91943d04U, 0, false, true, "" },
    { "    s_bfm_b32  s21, s4, s61", 0x92153d04U, 0, false, true, "" },
    { "    s_bfm_b64  s[20:21], s4, s62", 0x92943e04U, 0, false, true, "" },
    { "    s_mul_i32  s21, s4, s61", 0x93153d04U, 0, false, true, "" },
    { "    s_bfe_u32  s21, s4, s61", 0x93953d04U, 0, false, true, "" },
    { "    s_bfe_i32  s21, s4, s61", 0x94153d04U, 0, false, true, "" },
    { "    s_bfe_u64  s[20:21], s[4:5], s61", 0x94943d04U, 0, false, true, "" },
    { "    s_bfe_i64  s[20:21], s[4:5], s61", 0x95143d04U, 0, false, true, "" },
    { "    s_cbranch_g_fork  s[4:5], s[62:63]", 0, 0, false, false,
        "test.s:1:5: Error: Unknown instruction\n" },
    { "    s_absdiff_i32  s21, s4, s61", 0x96153d04U, 0, false, true, "" },
    { "        s_lshl1_add_u32 s21, s4, s61\n", 0x97153d04U, 0, false, true, "" },
    { "        s_lshl2_add_u32 s21, s4, s61\n", 0x97953d04U, 0, false, true, "" },
    { "        s_lshl3_add_u32 s21, s4, s61\n", 0x98153d04U, 0, false, true, "" },
    { "        s_lshl4_add_u32 s21, s4, s61\n", 0x98953d04U, 0, false, true, "" },
    { "        s_pack_ll_b32_b16 s21, s4, s61\n", 0x99153d04U, 0, false, true, "" },
    { "        s_pack_lh_b32_b16 s21, s4, s61\n", 0x99953d04U, 0, false, true, "" },
    { "        s_pack_hh_b32_b16 s21, s4, s61\n", 0x9a153d04U, 0, false, true, "" },
    { "        s_mul_hi_u32    s21, s4, s61\n", 0x9a953d04U, 0, false, true, "" },
    { "        s_mul_hi_i32    s21, s4, s61\n", 0x9b153d04U, 0, false, true, "" },
    /* SOP1 */
    { "    s_mov_b32  s86, s20", 0xbed60314U, 0, false, true, "" },
    { "    s_mov_b32_e64  s86, -4", 0xbed603ffU, 0xfffffffcU, true, true, "" },
    { "    s_mov_b32  s86, 0xadbc", 0xbed603ff, 0xadbc, true, true, "" },
    { "    s_mov_b32  s86, xx; xx=0xadbc", 0xbed603ff, 0xadbc, true, true, "" },
    { "    s_mov_b64  s[86:87], s[20:21]", 0xbed60414U, 0, false, true, "" },
    { "    s_cmov_b32  s86, s20", 0xbed60514U, 0, false, true, "" },
    { "    s_cmov_b64  s[86:87], s[20:21]", 0xbed60614U, 0, false, true, "" },
    { "    s_not_b32  s86, s20", 0xbed60714U, 0, false, true, "" },
    { "    s_not_b64  s[86:87], s[20:21]", 0xbed60814U, 0, false, true, "" },
    { "    s_wqm_b32  s86, s20", 0xbed60914U, 0, false, true, "" },
    { "    s_wqm_b64  s[86:87], s[20:21]", 0xbed60a14U, 0, false, true, "" },
    { "    s_brev_b32  s86, s20", 0xbed60b14U, 0, false, true, "" },
    { "    s_brev_b64  s[86:87], s[20:21]", 0xbed60c14U, 0, false, true, "" },
    { "    s_bcnt0_i32_b32  s86, s20", 0xbed60d14U, 0, false, true, "" },
    { "    s_bcnt0_i32_b64  s86, s[20:21]", 0xbed60e14U, 0, false, true, "" },
    { "    s_bcnt1_i32_b32  s86, s20", 0xbed60f14U, 0, false, true, "" },
    { "    s_bcnt1_i32_b64  s86, s[20:21]", 0xbed61014U, 0, false, true, "" },
    { "    s_ff0_i32_b32  s86, s20", 0xbed61114U, 0, false, true, "" },
    { "    s_ff0_i32_b64  s86, s[20:21]", 0xbed61214U, 0, false, true, "" },
    { "    s_ff1_i32_b32  s86, s20", 0xbed61314U, 0, false, true, "" },
    { "    s_ff1_i32_b64  s86, s[20:21]", 0xbed61414U, 0, false, true, "" },
    { "    s_flbit_i32_b32  s86, s20", 0xbed61514U, 0, false, true, "" },
    { "    s_flbit_i32_b64  s86, s[20:21]", 0xbed61614U, 0, false, true, "" },
    { "    s_flbit_i32  s86, s20", 0xbed61714U, 0, false, true, "" },
    { "    s_flbit_i32_i64  s86, s[20:21]", 0xbed61814U, 0, false, true, "" },
    { "    s_sext_i32_i8  s86, s20", 0xbed61914U, 0, false, true, "" },
    { "    s_sext_i32_i16  s86, s20", 0xbed61a14U, 0, false, true, "" },
    { "    s_bitset0_b32  s86, s20", 0xbed61b14U, 0, false, true, "" },
    { "    s_bitset0_b64  s[86:87], s20", 0xbed61c14U, 0, false, true, "" },
    { "    s_bitset1_b32  s86, s20", 0xbed61d14U, 0, false, true, "" },
    { "    s_bitset1_b64  s[86:87], s20", 0xbed61e14U, 0, false, true, "" },
    { "    s_getpc_b64  s[86:87]", 0xbed61f00U, 0, false, true, "" },
    { "    s_setpc_b64  s[20:21]", 0xbe802014U, 0, false, true, "" },
    { "    s_swappc_b64  s[86:87], s[20:21]", 0xbed62114U, 0, false, true, "" },
    { "    s_rfe_b64  s[20:21]", 0xbe802214U, 0, false, true, "" },
    { "    s_and_saveexec_b64 s[86:87], s[20:21]", 0xbed62414U, 0, false, true, "" },
    { "    s_or_saveexec_b64 s[86:87], s[20:21]", 0xbed62514U, 0, false, true, "" },
    { "    s_xor_saveexec_b64 s[86:87], s[20:21]", 0xbed62614U, 0, false, true, "" },
    { "    s_andn2_saveexec_b64 s[86:87], s[20:21]", 0xbed62714U, 0, false, true, "" },
    { "    s_orn2_saveexec_b64 s[86:87], s[20:21]", 0xbed62814U, 0, false, true, "" },
    { "    s_nand_saveexec_b64 s[86:87], s[20:21]", 0xbed62914U, 0, false, true, "" },
    { "    s_nor_saveexec_b64 s[86:87], s[20:21]", 0xbed62a14U, 0, false, true, "" },
    { "    s_xnor_saveexec_b64 s[86:87], s[20:21]", 0xbed62b14U, 0, false, true, "" },
    { "    s_quadmask_b32  s86, s20",  0xbed62c14U, 0, false, true, "" },
    { "    s_quadmask_b64  s[86:87], s[20:21]",  0xbed62d14U, 0, false, true, "" },
    { "    s_movrels_b32  s86, s20",  0xbed62e14U, 0, false, true, "" },
    { "    s_movrels_b64  s[86:87], s[20:21]",  0xbed62f14U, 0, false, true, "" },
    { "    s_movreld_b32  s86, s20",  0xbed63014U, 0, false, true, "" },
    { "    s_movreld_b64  s[86:87], s[20:21]",  0xbed63114U, 0, false, true, "" },
    { "    s_cbranch_join  s20", 0xbe803214U, 0, false, false,
        "test.s:1:5: Error: Unknown instruction\n" },
    { "    s_mov_regrd_b32 s86, s20", 0xbed63314U, 0, false, false,
        "test.s:1:5: Error: Unknown instruction\n" },
    { "    s_abs_i32  s86, s20", 0xbed63414U, 0, false, true, "" },
    { "    s_mov_fed_b32  s86, s20", 0xbed63514U, 0, false, true, "" },
    { "    s_andn1_saveexec_b64 s[86:87], s[20:21]", 0xbed63714U, 0, false, true, "" },
    { "    s_orn1_saveexec_b64 s[86:87], s[20:21]", 0xbed63814U, 0, false, true, "" },
    { "    s_andn1_wrexec_b64 s[86:87], s[20:21]", 0xbed63914U, 0, false, true, "" },
    { "    s_andn2_wrexec_b64 s[86:87], s[20:21]", 0xbed63a14U, 0, false, true, "" },
    { "s_bitreplicate_b64_b32 s[86:87], s20\n", 0xbed63b14U, 0, false, true, "" },
    { "    s_and_saveexec_b32 s86, s20", 0xbed63c14U, 0, false, true, "" },
    { "    s_or_saveexec_b32 s86, s20", 0xbed63d14U, 0, false, true, "" },
    { "    s_xor_saveexec_b32 s86, s20", 0xbed63e14U, 0, false, true, "" },
    { "    s_andn2_saveexec_b32 s86, s20", 0xbed63f14U, 0, false, true, "" },
    { "    s_orn2_saveexec_b32 s86, s20", 0xbed64014U, 0, false, true, "" },
    { "    s_nand_saveexec_b32 s86, s20", 0xbed64114U, 0, false, true, "" },
    { "    s_nor_saveexec_b32 s86, s20", 0xbed64214U, 0, false, true, "" },
    { "    s_xnor_saveexec_b32 s86, s20", 0xbed64314U, 0, false, true, "" },
    { "    s_andn1_saveexec_b32 s86, s20", 0xbed64414U, 0, false, true, "" },
    { "    s_orn1_saveexec_b32 s86, s20", 0xbed64514U, 0, false, true, "" },
    { "    s_andn1_wrexec_b32 s86, s20", 0xbed64614U, 0, false, true, "" },
    { "    s_andn2_wrexec_b32 s86, s20", 0xbed64714U, 0, false, true, "" },
    { "    s_movrelsd_2_b32 s86, s20", 0xbed64914U, 0, false, true, "" },
    /* SOPC */
    { "    s_cmp_eq_i32  s29, s69", 0xbf00451dU, 0, false, true, "" },
    { "    s_cmp_eq_i32_e64  s29, 51", 0xbf00ff1dU, 51, true, true, "" },
    { "    s_cmp_eq_i32_e64  51, s69", 0xbf0045ffU, 51, true, true, "" },
    { "    s_cmp_eq_i32  12222, s69", 0xbf0045ffU, 12222, true, true, "" },
    { "    s_cmp_eq_i32  xx, s69; xx=12222", 0xbf0045ffU, 12222, true, true, "" },
    { "    s_cmp_eq_i32  s29, 32545", 0xbf00ff1dU, 32545, true, true, "" },
    { "    s_cmp_eq_i32  s29, xx; xx=32545", 0xbf00ff1dU, 32545, true, true, "" },
    { "    s_cmp_lg_i32  s29, s69", 0xbf01451dU, 0, false, true, "" },
    { "    s_cmp_gt_i32  s29, s69", 0xbf02451dU, 0, false, true, "" },
    { "    s_cmp_ge_i32  s29, s69", 0xbf03451dU, 0, false, true, "" },
    { "    s_cmp_lt_i32  s29, s69", 0xbf04451dU, 0, false, true, "" },
    { "    s_cmp_le_i32  s29, s69", 0xbf05451dU, 0, false, true, "" },
    { "    s_cmp_eq_u32  s29, s69", 0xbf06451dU, 0, false, true, "" },
    { "    s_cmp_lg_u32  s29, s69", 0xbf07451dU, 0, false, true, "" },
    { "    s_cmp_gt_u32  s29, s69", 0xbf08451dU, 0, false, true, "" },
    { "    s_cmp_ge_u32  s29, s69", 0xbf09451dU, 0, false, true, "" },
    { "    s_cmp_lt_u32  s29, s69", 0xbf0a451dU, 0, false, true, "" },
    { "    s_cmp_le_u32  s29, s69", 0xbf0b451dU, 0, false, true, "" },
    { "    s_bitcmp0_b32  s29, s69", 0xbf0c451dU, 0, false, true, "" },
    { "    s_bitcmp1_b32  s29, s69", 0xbf0d451dU, 0, false, true, "" },
    { "    s_bitcmp0_b64  s[28:29], s69", 0xbf0e451cU, 0, false, true, "" },
    { "    s_bitcmp1_b64  s[28:29], s69", 0xbf0f451cU, 0, false, true, "" },
    { "    s_setvskip  s29, s69", 0xbf10451dU, 0, false, false,
        "test.s:1:5: Error: Unknown instruction\n" },
    { "    s_cmp_eq_u64  s[28:29], s[68:69]", 0xbf12441cU, 0, false, true, "" },
    { "    s_cmp_lg_u64  s[28:29], s[68:69]", 0xbf13441cU, 0, false, true, "" },
    { "    s_cmp_ne_u64  s[28:29], s[68:69]", 0xbf13441cU, 0, false, true, "" },
    /* SOPK */
    { "    s_movk_i32  s43, 0xd3b9", 0xb02bd3b9U, 0, false, true, "" },
    { "xc = 0xd4ba\n    s_movk_i32  s43, xc", 0xb02bd4baU, 0, false, true, "" },
    { "    s_movk_i32  s43, xc; xc = 0xd4ba", 0xb02bd4baU, 0, false, true, "" },
    { "xc = 0x11d4ba\n    s_movk_i32  s43, xc", 0xb02bd4baU, 0, false, true,
        "test.s:2:22: Warning: Value 0x11d4ba truncated to 0xd4ba\n" },
    { "    s_movk_i32  s43, xc; xc = 0x22d4ba", 0xb02bd4baU, 0, false, true,
        "test.s:1:22: Warning: Value 0x22d4ba truncated to 0xd4ba\n" },
    { "    s_version 4331", 0xb08010ebU, 0, false, true, "" },
    { "    s_cmovk_i32  s43, 0xd3b9", 0xb12bd3b9U, 0, false, true, "" },
    { "    s_cmpk_eq_i32  s43, 0xd3b9", 0xb1abd3b9U, 0, false, true, "" },
    { "    s_cmpk_lg_i32  s43, 0xd3b9", 0xb22bd3b9U, 0, false, true, "" },
    { "    s_cmpk_gt_i32  s43, 0xd3b9", 0xb2abd3b9U, 0, false, true, "" },
    { "    s_cmpk_ge_i32  s43, 0xd3b9", 0xb32bd3b9U, 0, false, true, "" },
    { "    s_cmpk_lt_i32  s43, 0xd3b9", 0xb3abd3b9U, 0, false, true, "" },
    { "    s_cmpk_le_i32  s43, 0xd3b9", 0xb42bd3b9U, 0, false, true, "" },
    { "    s_cmpk_eq_u32  s43, 0xd3b9", 0xb4abd3b9U, 0, false, true, "" },
    { "    s_cmpk_lg_u32  s43, 0xd3b9", 0xb52bd3b9U, 0, false, true, "" },
    { "    s_cmpk_gt_u32  s43, 0xd3b9", 0xb5abd3b9U, 0, false, true, "" },
    { "    s_cmpk_ge_u32  s43, 0xd3b9", 0xb62bd3b9U, 0, false, true, "" },
    { "    s_cmpk_lt_u32  s43, 0xd3b9", 0xb6abd3b9U, 0, false, true, "" },
    { "    s_cmpk_le_u32  s43, 0xd3b9", 0xb72bd3b9U, 0, false, true, "" },
    { "    s_addk_i32  s43, 0xd3b9", 0xb7abd3b9U, 0, false, true, "" },
    { "    s_mulk_i32  s43, 0xd3b9", 0xb82bd3b9U, 0, false, true, "" },
    { "    s_cbranch_i_fork s[44:45], xxxx-8\nxxxx:\n", 0, 0, false, false,
        "test.s:1:5: Error: Unknown instruction\n" },
    { "    s_getreg_b32    s43, hwreg(mode, 0, 1)", 0xb92b0001U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg  (mode, 0, 1)", 0xb92b0001U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg  (mode  ,   0  , 1  )",
                    0xb92b0001U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_MODE, 0, 1)", 0xb92b0001U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(status, 0, 1)", 0xb92b0002U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_STATUS, 0, 1)",
        0xb92b0002U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(trapsts, 0, 1)", 0xb92b0003U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_TRAPSTS, 0, 1)",
                    0xb92b0003U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(hw_id, 0, 1)", 0xb92b0004U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_HW_ID, 0, 1)",
                    0xb92b0004U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(gpr_alloc, 0, 1)", 0xb92b0005U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_GPR_ALLOC, 0, 1)",
                    0xb92b0005U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(lds_alloc, 0, 1)", 0xb92b0006U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_LDS_ALLOC, 0, 1)",
                    0xb92b0006U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(ib_sts, 0, 1)", 0xb92b0007U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_IB_STS, 0, 1)",
                    0xb92b0007U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(pc_lo, 0, 1)", 0xb92b0008U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_PC_LO, 0, 1)",
                    0xb92b0008U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(pc_hi, 0, 1)", 0xb92b0009U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_PC_HI, 0, 1)",
                    0xb92b0009U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(inst_dw0, 0, 1)", 0xb92b000aU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_INST_DW0, 0, 1)",
                    0xb92b000aU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(inst_dw1, 0, 1)", 0xb92b000bU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_INST_DW1, 0, 1)",
                    0xb92b000bU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(ib_dbg0, 0, 1)", 0xb92b000cU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_IB_DBG0, 0, 1)",
                    0xb92b000cU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(trapsts, 10, 1)", 0xb92b0283u, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(trapsts, 3, 10)", 0xb92b48c3u, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(trapsts, 3, 32)", 0xb92bf8c3u, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(@10, 0, 1)", 0xb92b000aU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(@8, 0, 1)", 0xb92b0008U, 0, false, true, "" },
    { "    s_setreg_imm32_b32 hwreg(trapsts, 3, 10), 0x24da4f",
                    0xba8048c3u, 0x24da4fU, true, true, "" },
    { "    s_setreg_imm32_b32 hwreg(trapsts, 3, 10), xx; xx=0x24da4f",
                    0xba8048c3u, 0x24da4fU, true, true, "" },
    { "xx=0x24da4e;    s_setreg_imm32_b32 hwreg(trapsts, 3, 10), xx",
                    0xba8048c3u, 0x24da4eU, true, true, "" },
    { "     s_setreg_b32  hwreg(trapsts, 3, 10), s43", 0xb9ab48c3u, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(ib_dbg1, 0, 1)", 0xb92b000dU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(flush_ib, 0, 1)", 0xb92b000eU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_FLUSH_IB, 0, 1)",
                0xb92b000eU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(sh_mem_bases, 0, 1)",
                0xb92b000fU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_SH_MEM_BASES, 0, 1)",
                0xb92b000fU, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(sq_shader_tba_lo, 0, 1)",
                0xb92b0010U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_SQ_SHADER_TBA_LO, 0, 1)",
                0xb92b0010U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(sq_shader_tba_hi, 0, 1)",
                0xb92b0011U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_SQ_SHADER_TBA_HI, 0, 1)",
                0xb92b0011U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(sq_shader_tma_lo, 0, 1)",
                0xb92b0012U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_SQ_SHADER_TMA_LO, 0, 1)",
                0xb92b0012U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(sq_shader_tma_hi, 0, 1)",
                0xb92b0013U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_SQ_SHADER_TMA_HI, 0, 1)",
                0xb92b0013U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(tba_lo, 0, 1)", 0xb92b0010U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_TBA_LO, 0, 1)",
                0xb92b0010U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(tba_hi, 0, 1)", 0xb92b0011U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_TBA_HI, 0, 1)",
                0xb92b0011U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(tma_lo, 0, 1)", 0xb92b0012U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_TMA_LO, 0, 1)",
                0xb92b0012U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(tma_hi, 0, 1)", 0xb92b0013U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_TMA_HI, 0, 1)",
                0xb92b0013U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(flat_scr_lo, 0, 1)",
                0xb92b0014U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_FLAT_SCR_LO, 0, 1)",
                0xb92b0014U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(flat_scr_hi, 0, 1)",
                0xb92b0015U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_FLAT_SCR_HI, 0, 1)",
                0xb92b0015U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(xnack_mask, 0, 1)",
                0xb92b0016U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_XNACK_MASK, 0, 1)",
                0xb92b0016U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(pops_packer, 0, 1)",
                0xb92b0017U, 0, false, true, "" },
    { "    s_getreg_b32    s43, hwreg(HWREG_POPS_PACKER, 0, 1)",
                0xb92b0017U, 0, false, true, "" },
    // SOPK instructions
    { "s_call_b64 s[44:45], xxxx+8\nxxxx:", 0xbb2c0002U, 0, false, true, "" },
    { "    s_waitcnt_vscnt  s43, 0xd3b9", 0xbbabd3b9U, 0, false, true, "" },
    { "    s_waitcnt_vmcnt  s43, 0xd3b9", 0xbc2bd3b9U, 0, false, true, "" },
    { "    s_waitcnt_expcnt s43, 0xd3b9", 0xbcabd3b9U, 0, false, true, "" },
    { "    s_waitcnt_lgkmcnt s43, 0xd3b9", 0xbd2bd3b9U, 0, false, true, "" },
    { "    s_subvector_loop_begin s43, 0xd3b9", 0xbdabd3b9U, 0, false, true, "" },
    { "    s_subvector_loop_end s43, 0xd3b9", 0xbe2bd3b9U, 0, false, true, "" },
    { nullptr, 0, 0, false, false, 0 }
};
