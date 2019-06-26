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
#include "GCNDisasmOpc.h"

/* for Radeon NAVI series with GCN1.5 */
const GCNDisasmOpcodeCase decGCNOpcodeGCN15Cases[] =
{
    { 0x80153d04U, 0, false, "        s_add_u32       s21, s4, s61\n" },
    { 0x80156404U, 0, false, "        s_add_u32       s21, s4, s100\n" },
    { 0x80156604U, 0, false, "        s_add_u32       s21, s4, s102\n" },
    { 0x80156704U, 0, false, "        s_add_u32       s21, s4, s103\n" },
    { 0x80156804U, 0, false, "        s_add_u32       s21, s4, s104\n" },
    { 0x80156904U, 0, false, "        s_add_u32       s21, s4, s105\n" },
    { 0x80156a04U, 0, false, "        s_add_u32       s21, s4, vcc_lo\n" },
    { 0x80156b04U, 0, false, "        s_add_u32       s21, s4, vcc_hi\n" },
    { 0x80156c04U, 0, false, "        s_add_u32       s21, s4, ttmp0\n" },
    { 0x80156d04U, 0, false, "        s_add_u32       s21, s4, ttmp1\n" },
    { 0x80156e04U, 0, false, "        s_add_u32       s21, s4, ttmp2\n" },
    { 0x80156f04U, 0, false, "        s_add_u32       s21, s4, ttmp3\n" },
    { 0x80157004U, 0, false, "        s_add_u32       s21, s4, ttmp4\n" },
    { 0x80157104U, 0, false, "        s_add_u32       s21, s4, ttmp5\n" },
    { 0x80157204U, 0, false, "        s_add_u32       s21, s4, ttmp6\n" },
    { 0x80157304U, 0, false, "        s_add_u32       s21, s4, ttmp7\n" },
    { 0x80157404U, 0, false, "        s_add_u32       s21, s4, ttmp8\n" },
    { 0x80157504U, 0, false, "        s_add_u32       s21, s4, ttmp9\n" },
    { 0x80157604U, 0, false, "        s_add_u32       s21, s4, ttmp10\n" },
    { 0x80157704U, 0, false, "        s_add_u32       s21, s4, ttmp11\n" },
    { 0x80157804U, 0, false, "        s_add_u32       s21, s4, ttmp12\n" },
    { 0x80157904U, 0, false, "        s_add_u32       s21, s4, ttmp13\n" },
    { 0x80157a04U, 0, false, "        s_add_u32       s21, s4, ttmp14\n" },
    { 0x80157b04U, 0, false, "        s_add_u32       s21, s4, ttmp15\n" },
    { 0x80157c04U, 0, false, "        s_add_u32       s21, s4, m0\n" },
    { 0x80157e04U, 0, false, "        s_add_u32       s21, s4, exec_lo\n" },
    { 0x80158004U, 0, false, "        s_add_u32       s21, s4, 0\n" },
    { 0x80158b04U, 0, false, "        s_add_u32       s21, s4, 11\n" },
    { 0x8015c004U, 0, false, "        s_add_u32       s21, s4, 64\n" },
    { 0x8015c404U, 0, false, "        s_add_u32       s21, s4, -4\n" },
    { 0x8015f004U, 0, false, "        s_add_u32       s21, s4, 0.5\n" },
    { 0x8015f104U, 0, false, "        s_add_u32       s21, s4, -0.5\n" },
    { 0x8015f204U, 0, false, "        s_add_u32       s21, s4, 1.0\n" },
    { 0x8015f304U, 0, false, "        s_add_u32       s21, s4, -1.0\n" },
    { 0x8015f404U, 0, false, "        s_add_u32       s21, s4, 2.0\n" },
    { 0x8015f504U, 0, false, "        s_add_u32       s21, s4, -2.0\n" },
    { 0x8015f604U, 0, false, "        s_add_u32       s21, s4, 4.0\n" },
    { 0x8015f704U, 0, false, "        s_add_u32       s21, s4, -4.0\n" },
    { 0x8015f704U, 0, false, "        s_add_u32       s21, s4, -4.0\n" },
    { 0x8015ff04U, 0xfffffff0, true,  "        s_add_u32       s21, s4, lit(-16)\n" },
    { 0x8015ff04U, 1, true,  "        s_add_u32       s21, s4, lit(1)\n" },
    { 0x8015ff04U, 64, true,  "        s_add_u32       s21, s4, lit(64)\n" },
    { 0x8015fb04U, 0, false, "        s_add_u32       s21, s4, vccz\n" },
    { 0x8015fc04U, 0, false, "        s_add_u32       s21, s4, execz\n" },
    { 0x8015fd04U, 0, false, "        s_add_u32       s21, s4, scc\n" },
    { 0x807f3d04U, 0, false, "        s_add_u32       exec_hi, s4, s61\n" },
    { 0x807f3df1U, 0, false, "        s_add_u32       exec_hi, -0.5, s61\n" },
    { 0x807f3dffU, 0xd3abc5f, true, "        s_add_u32       exec_hi, 0xd3abc5f, s61\n" },
    { 0x807fff05U, 0xd3abc5f, true, "        s_add_u32       exec_hi, s5, 0xd3abc5f\n" },
    // SRC - NULL
    { 0x80157d04U, 0, false, "        s_add_u32       s21, s4, null\n" },
    /* SOP2 opcodes */
    { 0x80ff3df1U, 0, false, "        s_sub_u32       exec_hi, -0.5, s61\n" },
    { 0x81153d04U, 0, false, "        s_add_i32       s21, s4, s61\n" },
    { 0x81953d04U, 0, false, "        s_sub_i32       s21, s4, s61\n" },
    { 0x82153d04U, 0, false, "        s_addc_u32      s21, s4, s61\n" },
    { 0x82953d04U, 0, false, "        s_subb_u32      s21, s4, s61\n" },
    { 0x83153d04U, 0, false, "        s_min_i32       s21, s4, s61\n" },
    { 0x83953d04U, 0, false, "        s_min_u32       s21, s4, s61\n" },
    { 0x84153d04U, 0, false, "        s_max_i32       s21, s4, s61\n" },
    { 0x84953d04U, 0, false, "        s_max_u32       s21, s4, s61\n" },
    { 0x85153d04U, 0, false, "        s_cselect_b32   s21, s4, s61\n" },
    { 0x85953d04U, 0, false, "        s_cselect_b64   s[21:22], s[4:5], s[61:62]\n" },
    { 0x86153d04U, 0, false, "        SOP2_ill_12     s21, s4, s61\n" },
    { 0x86953d04U, 0, false, "        SOP2_ill_13     s21, s4, s61\n" },
    { 0x87153d04U, 0, false, "        s_and_b32       s21, s4, s61\n" },
    { 0x87953d04U, 0, false, "        s_and_b64       s[21:22], s[4:5], s[61:62]\n" },
    { 0x88153d04U, 0, false, "        s_or_b32        s21, s4, s61\n" },
    { 0x88953d04U, 0, false, "        s_or_b64        s[21:22], s[4:5], s[61:62]\n" },
    { 0x89153d04U, 0, false, "        s_xor_b32       s21, s4, s61\n" },
    { 0x89953d04U, 0, false, "        s_xor_b64       s[21:22], s[4:5], s[61:62]\n" },
    { 0x8a153d04U, 0, false, "        s_andn2_b32     s21, s4, s61\n" },
    { 0x8a953d04U, 0, false, "        s_andn2_b64     s[21:22], s[4:5], s[61:62]\n" },
    { 0x8b153d04U, 0, false, "        s_orn2_b32      s21, s4, s61\n" },
    { 0x8b953d04U, 0, false, "        s_orn2_b64      s[21:22], s[4:5], s[61:62]\n" },
    { 0x8c153d04U, 0, false, "        s_nand_b32      s21, s4, s61\n" },
    { 0x8c953d04U, 0, false, "        s_nand_b64      s[21:22], s[4:5], s[61:62]\n" },
    { 0x8d153d04U, 0, false, "        s_nor_b32       s21, s4, s61\n" },
    { 0x8d953d04U, 0, false, "        s_nor_b64       s[21:22], s[4:5], s[61:62]\n" },
    { 0x8e153d04U, 0, false, "        s_xnor_b32      s21, s4, s61\n" },
    { 0x8e953d04U, 0, false, "        s_xnor_b64      s[21:22], s[4:5], s[61:62]\n" },
    { 0x8f153d04U, 0, false, "        s_lshl_b32      s21, s4, s61\n" },
    { 0x8f953d04U, 0, false, "        s_lshl_b64      s[21:22], s[4:5], s61\n" },
    { 0x90153d04U, 0, false, "        s_lshr_b32      s21, s4, s61\n" },
    { 0x90953d04U, 0, false, "        s_lshr_b64      s[21:22], s[4:5], s61\n" },
    { 0x91153d04U, 0, false, "        s_ashr_i32      s21, s4, s61\n" },
    { 0x91953d04U, 0, false, "        s_ashr_i64      s[21:22], s[4:5], s61\n" },
    { 0x92153d04U, 0, false, "        s_bfm_b32       s21, s4, s61\n" },
    { 0x92953d04U, 0, false, "        s_bfm_b64       s[21:22], s4, s61\n" },
    { 0x93153d04U, 0, false, "        s_mul_i32       s21, s4, s61\n" },
    { 0x93953d04U, 0, false, "        s_bfe_u32       s21, s4, s61\n" },
    { 0x94153d04U, 0, false, "        s_bfe_i32       s21, s4, s61\n" },
    { 0x94953d04U, 0, false, "        s_bfe_u64       s[21:22], s[4:5], s61\n" },
    { 0x95153d04U, 0, false, "        s_bfe_i64       s[21:22], s[4:5], s61\n" },
    { 0x95953d04U, 0, false, "        SOP2_ill_43     s21, s4, s61\n" },
    { 0x96153d04U, 0, false, "        s_absdiff_i32   s21, s4, s61\n" },
    { 0x96953d04U, 0, false, "        SOP2_ill_45     s21, s4, s61\n" },
    { 0x97153d04U, 0, false, "        s_lshl1_add_u32 s21, s4, s61\n" },
    { 0x97953d04U, 0, false, "        s_lshl2_add_u32 s21, s4, s61\n" },
    { 0x98153d04U, 0, false, "        s_lshl3_add_u32 s21, s4, s61\n" },
    { 0x98953d04U, 0, false, "        s_lshl4_add_u32 s21, s4, s61\n" },
    { 0x99153d04U, 0, false, "        s_pack_ll_b32_b16 s21, s4, s61\n" },
    { 0x99953d04U, 0, false, "        s_pack_lh_b32_b16 s21, s4, s61\n" },
    { 0x9a153d04U, 0, false, "        s_pack_hh_b32_b16 s21, s4, s61\n" },
    { 0x9a953d04U, 0, false, "        s_mul_hi_u32    s21, s4, s61\n" },
    { 0x9b153d04U, 0, false, "        s_mul_hi_i32    s21, s4, s61\n" },
    /* SOPK */
    { 0xb02b0000U, 0, false, "        s_movk_i32      s43, 0x0\n" },
    { 0xb02bd3b9U, 0, false, "        s_movk_i32      s43, 0xd3b9\n" },
    { 0xb0abd3b9U, 0, false, "        s_version       0xd3b9 sdst=0x2b\n" },
    { 0xb080d3b9U, 0, false, "        s_version       0xd3b9\n" },
    { 0xb12bd3b9U, 0, false, "        s_cmovk_i32     s43, 0xd3b9\n" },
    { 0xb1abd3b9U, 0, false, "        s_cmpk_eq_i32   s43, 0xd3b9\n" },
    { 0xb22bd3b9U, 0, false, "        s_cmpk_lg_i32   s43, 0xd3b9\n" },
    { 0xb2abd3b9U, 0, false, "        s_cmpk_gt_i32   s43, 0xd3b9\n" },
    { 0xb32bd3b9U, 0, false, "        s_cmpk_ge_i32   s43, 0xd3b9\n" },
    { 0xb3abd3b9U, 0, false, "        s_cmpk_lt_i32   s43, 0xd3b9\n" },
    { 0xb42bd3b9U, 0, false, "        s_cmpk_le_i32   s43, 0xd3b9\n" },
    { 0xb4abd3b9U, 0, false, "        s_cmpk_eq_u32   s43, 0xd3b9\n" },
    { 0xb52bd3b9U, 0, false, "        s_cmpk_lg_u32   s43, 0xd3b9\n" },
    { 0xb5abd3b9U, 0, false, "        s_cmpk_gt_u32   s43, 0xd3b9\n" },
    { 0xb62bd3b9U, 0, false, "        s_cmpk_ge_u32   s43, 0xd3b9\n" },
    { 0xb6abd3b9U, 0, false, "        s_cmpk_lt_u32   s43, 0xd3b9\n" },
    { 0xb72bd3b9U, 0, false, "        s_cmpk_le_u32   s43, 0xd3b9\n" },
    { 0xb7abd3b9U, 0, false, "        s_addk_i32      s43, 0xd3b9\n" },
    { 0xb82bd3b9U, 0, false, "        s_mulk_i32      s43, 0xd3b9\n" },
    { 0xb8ab0000U, 0, false, "        SOPK_ill_17     s43, 0x0\n" },
    { 0xb92b0000U, 0, false, "        s_getreg_b32    s43, hwreg(@0, 0, 1)\n" },
    { 0xb92b0001u, 0, false, "        s_getreg_b32    s43, hwreg(mode, 0, 1)\n" },
    { 0xb92b0002u, 0, false, "        s_getreg_b32    s43, hwreg(status, 0, 1)\n" },
    { 0xb92b0003u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 0, 1)\n" },
    { 0xb92b0004u, 0, false, "        s_getreg_b32    s43, hwreg(hw_id, 0, 1)\n" },
    { 0xb92b0005u, 0, false, "        s_getreg_b32    s43, hwreg(gpr_alloc, 0, 1)\n" },
    { 0xb92b0006u, 0, false, "        s_getreg_b32    s43, hwreg(lds_alloc, 0, 1)\n" },
    { 0xb92b0007u, 0, false, "        s_getreg_b32    s43, hwreg(ib_sts, 0, 1)\n" },
    { 0xb92b0008u, 0, false, "        s_getreg_b32    s43, hwreg(pc_lo, 0, 1)\n" },
    { 0xb92b0009u, 0, false, "        s_getreg_b32    s43, hwreg(pc_hi, 0, 1)\n" },
    { 0xb92b000au, 0, false, "        s_getreg_b32    s43, hwreg(inst_dw0, 0, 1)\n" },
    { 0xb92b000bu, 0, false, "        s_getreg_b32    s43, hwreg(inst_dw1, 0, 1)\n" },
    { 0xb92b000cu, 0, false, "        s_getreg_b32    s43, hwreg(ib_dbg0, 0, 1)\n" },
    { 0xb92b000eu, 0, false, "        s_getreg_b32    s43, hwreg(flush_ib, 0, 1)\n" },
    { 0xb92b000fu, 0, false, "        s_getreg_b32    s43, hwreg(sh_mem_bases, 0, 1)\n" },
    { 0xb92b0010u, 0, false, "        s_getreg_b32    "
                "s43, hwreg(sq_shader_tba_lo, 0, 1)\n" },
    { 0xb92b0011u, 0, false, "        s_getreg_b32    "
                "s43, hwreg(sq_shader_tba_hi, 0, 1)\n" },
    { 0xb92b0012u, 0, false, "        s_getreg_b32    "
                "s43, hwreg(sq_shader_tma_lo, 0, 1)\n" },
    { 0xb92b0013u, 0, false, "        s_getreg_b32    "
                "s43, hwreg(sq_shader_tma_hi, 0, 1)\n" },
    { 0xb92b0014u, 0, false, "        s_getreg_b32    s43, hwreg(flat_scr_lo, 0, 1)\n" },
    { 0xb92b0015u, 0, false, "        s_getreg_b32    s43, hwreg(flat_scr_hi, 0, 1)\n" },
    { 0xb92b0016u, 0, false, "        s_getreg_b32    s43, hwreg(xnack_mask, 0, 1)\n" },
    { 0xb92b0017u, 0, false, "        s_getreg_b32    s43, hwreg(pops_packer, 0, 1)\n" },
    { 0xb92b0018u, 0, false, "        s_getreg_b32    s43, hwreg(@24, 0, 1)\n" },
    { 0xb92b0019u, 0, false, "        s_getreg_b32    s43, hwreg(@25, 0, 1)\n" },
    { 0xb92b001eU, 0, false, "        s_getreg_b32    s43, hwreg(@30, 0, 1)\n" },
    { 0xb92b003fU, 0, false, "        s_getreg_b32    s43, hwreg(@63, 0, 1)\n" },
    { 0xb92b00c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 3, 1)\n" },
    { 0xb92b03c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 15, 1)\n" },
    { 0xb92b0283u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 10, 1)\n" },
    { 0xb92b0583u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 22, 1)\n" },
    { 0xb92b07c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 31, 1)\n" },
    { 0xb92b28c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 3, 6)\n" },
    { 0xb92b48c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 3, 10)\n" },
    { 0xb92bf8c3u, 0, false, "        s_getreg_b32    s43, hwreg(trapsts, 3, 32)\n" },
    { 0xb9ab48c3u, 0, false, "        s_setreg_b32    hwreg(trapsts, 3, 10), s43\n" },
    { 0xba2bf8c3u, 0, false, "        SOPK_ill_20     s43, 0xf8c3\n" },
    { 0xbaab48c3u, 0x45d2a, true, "        s_setreg_imm32_b32 hwreg(trapsts, 3, 10), "
                "0x45d2a sdst=0x2b\n" },
    { 0xba8048c3u, 0x45d2a, true, "        s_setreg_imm32_b32 hwreg(trapsts, 3, 10), "
                "0x45d2a\n" },
    { 0xbb2b0000U, 0, false, "        s_call_b64      s[43:44], .L4_0\n" },
    { 0xbb2b000aU, 0, false, "        s_call_b64      s[43:44], .L44_0\n" },
    { 0xbbabd3b9U, 0, false, "        s_waitcnt_vscnt s43, 0xd3b9\n" },
    { 0xbc2bd3b9U, 0, false, "        s_waitcnt_vmcnt s43, 0xd3b9\n" },
    { 0xbcabd3b9U, 0, false, "        s_waitcnt_expcnt s43, 0xd3b9\n" },
    { 0xbd2bd3b9U, 0, false, "        s_waitcnt_lgkmcnt s43, 0xd3b9\n" },
    { 0xbdabd3b9U, 0, false, "        s_subvector_begin s43, 0xd3b9\n" },
    { 0xbe2bd3b9U, 0, false, "        s_subvector_end s43, 0xd3b9\n" },
    /* SOP1 opcodes */
    { 0xbed60014U, 0, false, "        SOP1_ill_0      s86, s20\n" },
    { 0xbed60114U, 0, false, "        SOP1_ill_1      s86, s20\n" },
    { 0xbed60214U, 0, false, "        SOP1_ill_2      s86, s20\n" },
    { 0xbed60314U, 0, false, "        s_mov_b32       s86, s20\n" },
    { 0xbed603ffU, 0xddbbaa11, true, "        s_mov_b32       s86, 0xddbbaa11\n" },
    { 0xbed60414U, 0, false, "        s_mov_b64       s[86:87], s[20:21]\n" },
    { 0xbed60514U, 0, false, "        s_cmov_b32      s86, s20\n" },
    { 0xbed60614U, 0, false, "        s_cmov_b64      s[86:87], s[20:21]\n" },
    { 0xbed60714U, 0, false, "        s_not_b32       s86, s20\n" },
    { 0xbed60814U, 0, false, "        s_not_b64       s[86:87], s[20:21]\n" },
    { 0xbed60914U, 0, false, "        s_wqm_b32       s86, s20\n" },
    { 0xbed60a14U, 0, false, "        s_wqm_b64       s[86:87], s[20:21]\n" },
    { 0xbed60b14U, 0, false, "        s_brev_b32      s86, s20\n" },
    { 0xbed60c14U, 0, false, "        s_brev_b64      s[86:87], s[20:21]\n" },
    { 0xbed60d14U, 0, false, "        s_bcnt0_i32_b32 s86, s20\n" },
    { 0xbed60e14U, 0, false, "        s_bcnt0_i32_b64 s86, s[20:21]\n" },
    { 0xbed60f14U, 0, false, "        s_bcnt1_i32_b32 s86, s20\n" },
    { 0xbed61014U, 0, false, "        s_bcnt1_i32_b64 s86, s[20:21]\n" },
    { 0xbed61114U, 0, false, "        s_ff0_i32_b32   s86, s20\n" },
    { 0xbed61214U, 0, false, "        s_ff0_i32_b64   s86, s[20:21]\n" },
    { 0xbed61314U, 0, false, "        s_ff1_i32_b32   s86, s20\n" },
    { 0xbed61414U, 0, false, "        s_ff1_i32_b64   s86, s[20:21]\n" },
    { 0xbed61514U, 0, false, "        s_flbit_i32_b32 s86, s20\n" },
    { 0xbed61614U, 0, false, "        s_flbit_i32_b64 s86, s[20:21]\n" },
    { 0xbed61714U, 0, false, "        s_flbit_i32     s86, s20\n" },
    { 0xbed61814U, 0, false, "        s_flbit_i32_i64 s86, s[20:21]\n" },
    { 0xbed61914U, 0, false, "        s_sext_i32_i8   s86, s20\n" },
    { 0xbed61a14U, 0, false, "        s_sext_i32_i16  s86, s20\n" },
    { 0xbed61b14U, 0, false, "        s_bitset0_b32   s86, s20\n" },
    { 0xbed61c14U, 0, false, "        s_bitset0_b64   s[86:87], s20\n" },
    { 0xbed61d14U, 0, false, "        s_bitset1_b32   s86, s20\n" },
    { 0xbed61e14U, 0, false, "        s_bitset1_b64   s[86:87], s20\n" },
    { 0xbed61f00U, 0, false, "        s_getpc_b64     s[86:87]\n" },
    { 0xbed61f14U, 0, false, "        s_getpc_b64     s[86:87] ssrc=0x14\n" },
    { 0xbe802014U, 0, false, "        s_setpc_b64     s[20:21]\n" },
    { 0xbed62014U, 0, false, "        s_setpc_b64     s[20:21] sdst=0x56\n" },
    { 0xbed62114U, 0, false, "        s_swappc_b64    s[86:87], s[20:21]\n" },
    { 0xbe802214U, 0, false, "        s_rfe_b64       s[20:21]\n" },
    { 0xbed62214U, 0, false, "        s_rfe_b64       s[20:21] sdst=0x56\n" },
    { 0xbed62314U, 0, false, "        SOP1_ill_35     s86, s20\n" },
    { 0xbed62414U, 0, false, "        s_and_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62514U, 0, false, "        s_or_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62614U, 0, false, "        s_xor_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62714U, 0, false, "        s_andn2_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62814U, 0, false, "        s_orn2_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62914U, 0, false, "        s_nand_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62a14U, 0, false, "        s_nor_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62b14U, 0, false, "        s_xnor_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed62c14U, 0, false, "        s_quadmask_b32  s86, s20\n" },
    { 0xbed62d14U, 0, false, "        s_quadmask_b64  s[86:87], s[20:21]\n" },
    { 0xbed62e14U, 0, false, "        s_movrels_b32   s86, s20\n" },
    { 0xbed62f14U, 0, false, "        s_movrels_b64   s[86:87], s[20:21]\n" },
    { 0xbed63014U, 0, false, "        s_movreld_b32   s86, s20\n" },
    { 0xbed63114U, 0, false, "        s_movreld_b64   s[86:87], s[20:21]\n" },
    { 0xbe803214U, 0, false, "        SOP1_ill_50     s0, s20\n" },
    { 0xbe803314U, 0, false, "        SOP1_ill_51     s0, s20\n" },
    { 0xbed63414U, 0, false, "        s_abs_i32       s86, s20\n" },
    { 0xbed63514U, 0, false, "        s_mov_fed_b32   s86, s20\n" },
    { 0xbed63614U, 0, false, "        SOP1_ill_54     s86, s20\n" },
    { 0xbed63714U, 0, false, "        s_andn1_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed63814U, 0, false, "        s_orn1_saveexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed63914U, 0, false, "        s_andn1_wrexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed63a14U, 0, false, "        s_andn2_wrexec_b64 s[86:87], s[20:21]\n" },
    { 0xbed63b14U, 0, false, "        s_bitreplicate_b64_b32 s[86:87], s20\n" },
    { 0xbed63c14U, 0, false, "        s_and_saveexec_b32 s86, s20\n" },
    { 0xbed63d14U, 0, false, "        s_or_saveexec_b32 s86, s20\n" },
    { 0xbed63e14U, 0, false, "        s_xor_saveexec_b32 s86, s20\n" },
    { 0xbed63f14U, 0, false, "        s_andn2_saveexec_b32 s86, s20\n" },
    { 0xbed64014U, 0, false, "        s_orn2_saveexec_b32 s86, s20\n" },
    { 0xbed64114U, 0, false, "        s_nand_saveexec_b32 s86, s20\n" },
    { 0xbed64214U, 0, false, "        s_nor_saveexec_b32 s86, s20\n" },
    { 0xbed64314U, 0, false, "        s_xnor_saveexec_b32 s86, s20\n" },
    { 0xbed64414U, 0, false, "        s_andn1_saveexec_b32 s86, s20\n" },
    { 0xbed64514U, 0, false, "        s_orn1_saveexec_b32 s86, s20\n" },
    { 0xbed64614U, 0, false, "        s_andn1_wrexec_b32 s86, s20\n" },
    { 0xbed64714U, 0, false, "        s_andn2_wrexec_b32 s86, s20\n" },
    { 0xbed64914U, 0, false, "        s_movrelsd_2_b32 s86, s20\n" },
    { 0xbed64a14U, 0, false, "        SOP1_ill_74     s86, s20\n" },
    /* SOPC encoding */
    { 0xbf00451dU, 0, false, "        s_cmp_eq_i32    s29, s69\n" },
    { 0xbf0045ffU, 0x6d894, true, "        s_cmp_eq_i32    0x6d894, s69\n" },
    { 0xbf00ff1dU, 0x6d894, true, "        s_cmp_eq_i32    s29, 0x6d894\n" },
    { 0xbf01451dU, 0, false, "        s_cmp_lg_i32    s29, s69\n" },
    { 0xbf02451dU, 0, false, "        s_cmp_gt_i32    s29, s69\n" },
    { 0xbf03451dU, 0, false, "        s_cmp_ge_i32    s29, s69\n" },
    { 0xbf04451dU, 0, false, "        s_cmp_lt_i32    s29, s69\n" },
    { 0xbf05451dU, 0, false, "        s_cmp_le_i32    s29, s69\n" },
    { 0xbf06451dU, 0, false, "        s_cmp_eq_u32    s29, s69\n" },
    { 0xbf07451dU, 0, false, "        s_cmp_lg_u32    s29, s69\n" },
    { 0xbf08451dU, 0, false, "        s_cmp_gt_u32    s29, s69\n" },
    { 0xbf09451dU, 0, false, "        s_cmp_ge_u32    s29, s69\n" },
    { 0xbf0a451dU, 0, false, "        s_cmp_lt_u32    s29, s69\n" },
    { 0xbf0b451dU, 0, false, "        s_cmp_le_u32    s29, s69\n" },
    { 0xbf0c451dU, 0, false, "        s_bitcmp0_b32   s29, s69\n" },
    { 0xbf0d451dU, 0, false, "        s_bitcmp1_b32   s29, s69\n" },
    { 0xbf0e451dU, 0, false, "        s_bitcmp0_b64   s[29:30], s69\n" },
    { 0xbf0f451dU, 0, false, "        s_bitcmp1_b64   s[29:30], s69\n" },
    { 0xbf10451dU, 0, false, "        SOPC_ill_16     s29, s69\n" },
    { 0xbf11451dU, 0, false, "        SOPC_ill_17     s29, s69\n" },
    { 0xbf12451dU, 0, false, "        s_cmp_eq_u64    s[29:30], s[69:70]\n" },
    { 0xbf13451dU, 0, false, "        s_cmp_lg_u64    s[29:30], s[69:70]\n" },
    { 0xbf14451dU, 0, false, "        SOPC_ill_20     s29, s69\n" },
    { 0xbf15451dU, 0, false, "        SOPC_ill_21     s29, s69\n" },
    { 0xbf16451dU, 0, false, "        SOPC_ill_22     s29, s69\n" },
    { 0xbf17451dU, 0, false, "        SOPC_ill_23     s29, s69\n" },
    { 0, 0, false, nullptr }
};
