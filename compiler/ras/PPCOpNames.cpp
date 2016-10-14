/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

// DO NOT EDIT THIS FILE!!!
// This file was created by a tool.  In order to change the information in this
// file you must edit the file PPCOps.ops and then run the ftops tool.

#ifndef TR_TARGET_POWER
int ppcOpNames;
#else
const char* ppcOpCodeToNameMap[][2] = {
    { "bad", "bad" },
    { "add", "add" },
    { "add_r", "add." },
    { "addc", "addc" },
    { "addc_r", "addc." },
    { "addco", "addco" },
    { "addco_r", "addco." },
    { "adde", "adde" },
    { "adde_r", "adde." },
    { "addeo", "addeo" },
    { "addeo_r", "addeo." },
    { "addi", "addi" },
    { "addic", "addic" },
    { "addic_r", "addic." },
    { "addi2", "addi" },
    { "addi2_r", "addic." },
    { "addis", "addis" },
    { "addme", "addme" },
    { "addme_r", "addme." },
    { "addmeo", "addmeo" },
    { "addmeo_r", "addmeo." },
    { "addo", "addo" },
    { "addo_r", "addo." },
    { "addpcis", "addpcis" },
    { "addze", "addze" },
    { "addze_r", "addze." },
    { "addzeo", "addzeo" },
    { "addzeo_r", "addzeo." },
    { "and", "and" },
    { "and_r", "and." },
    { "andc", "andc" },
    { "andc_r", "andc." },
    { "addex", "addex" },
    { "addex_r", "addex." },
    { "andi_r", "andi." },
    { "andis_r", "andis." },
    { "b", "b" },
    { "ba", "ba" },
    { "bctr", "bctr" },
    { "bctrl", "bctrl" },
    { "bdnz", "bdnz" },
    { "bdz", "bdz" },
    { "beq", "beq" },
    { "beql", "beql" },
    { "bfctr", "bfctr" },
    { "bge", "bge" },
    { "bgel", "bgel" },
    { "bgt", "bgt" },
    { "bgtl", "bgtl" },
    { "bl", "bl" },
    { "ble", "ble" },
    { "blel", "blel" },
    { "blt", "blt" },
    { "bltl", "bltl" },
    { "bla", "bla" },
    { "blr", "blr" },
    { "blrl", "blrl" },
    { "bne", "bne" },
    { "bnel", "bnel" },
    { "bnun", "bnu" },
    { "btctr", "btctr" },
    { "bun", "bun" },
    { "beqlr", "beqlr" },
    { "bgelr", "bgelr" },
    { "bgtlr", "bgtlr" },
    { "blelr", "blelr" },
    { "bltlr", "bltlr" },
    { "bnelr", "bnelr" },
    { "cmp4", "cmpw" },
    { "cmp8", "cmpd" },
    { "cmpi4", "cmpwi" },
    { "cmpi8", "cmpdi" },
    { "cmpl4", "cmplw" },
    { "cmpl8", "cmpld" },
    { "cmpli4", "cmplwi" },
    { "cmpli8", "cmpldi" },
    { "cmprb", "cmprb" },
    { "cmpeqb", "cmpeqb" },
    { "cntlzd", "cntlzd" },
    { "cntlzd_r", "cntlzd." },
    { "cntlzw", "cntlzw" },
    { "cntlzw_r", "cntlzw." },
    { "crand", "crand" },
    { "crandc", "crandc" },
    { "creqv", "creqv" },
    { "crnand", "crnand" },
    { "crnor", "crnor" },
    { "cror", "cror" },
    { "crorc", "crorc" },
    { "crxor", "crxor" },
    { "dadd", "dadd" },
    { "dadd_r", "dadd." },
    { "darn", "darn" },
    { "dcbt", "dcbt" },
    { "dcbtst", "dcbtst" },
    { "dcbtstt", "dcbtstt" },
    { "dcbtt", "dcbtt" },
    { "dcbz", "dcbz" },
    { "dcffix", "dcffix" },
    { "dcffix_r", "dcffix." },
    { "dcffixq", "dcffixq" },
    { "dcffixq_r", "dcffixq." },
    { "dcmpu", "dcmpu" },
    { "dctfix", "dctfix" },
    { "dctfix_r", "dctfix." },
    { "ddedpd", "ddedpd" },
    { "ddedpd_r", "ddedpd." },
    { "ddiv", "ddiv" },
    { "ddiv_r", "ddiv." },
    { "denbcdu", "denbcdu" },
    { "denbcdu_r", "denbcdu." },
    { "divd", "divd" },
    { "divd_r", "divd." },
    { "diex", "diex" },
    { "diex_r", "diex." },
    { "divdo", "divdo" },
    { "divdo_r", "divdo." },
    { "divdu", "divdu" },
    { "divdu_r", "divdu." },
    { "divduo", "divduo" },
    { "divduo_r", "divduo." },
    { "divw", "divw" },
    { "divw_r", "divw." },
    { "divwo", "divwo" },
    { "divwo_r", "divwo." },
    { "divwu", "divwu" },
    { "divwu_r", "divwu." },
    { "divwuo", "divwuo" },
    { "divwuo_r", "divwuo." },
    { "dmul", "dmul" },
    { "dmul_r", "dmul." },
    { "dqua", "dqua" },
    { "dqua_r", "dqua." },
    { "drrnd", "drrnd" },
    { "drrnd_r", "drrnd." },
    { "drdpq", "drdpq" },
    { "drdpq_r", "drdpq." },
    { "dsub", "dsub" },
    { "dsub_r", "dsub." },
    { "dtstdc", "dtstdc" },
    { "dtstdg", "dtstdg" },
    { "dxex", "dxex" },
    { "dxex_r", "dxex." },
    { "eieio", "eieio" },
    { "eqv", "eqv" },
    { "eqv_r", "eqv." },
    { "extsb", "extsb" },
    { "extsb_r", "extsb." },
    { "extsh", "extsh" },
    { "extsh_r", "extsh." },
    { "extsw", "extsw" },
    { "extsw_r", "extsw." },
    { "extswsli", "extswsli" },
    { "extswsli_r", "extswsli." },
    { "fabs", "fabs" },
    { "fadd", "fadd" },
    { "fadds", "fadds" },
    { "fcfid", "fcfid" },
    { "fcfidu", "fcfidu" },
    { "fcfids", "fcfids" },
    { "fcfidus", "fcfidus" },
    { "fcmpo", "fcmpo" },
    { "fcmpu", "fcmpu" },
    { "fcpsgn", "fcpsgn" },
    { "fctid", "fctid" },
    { "fctidz", "fctidz" },
    { "fctiw", "fctiw" },
    { "fctiwz", "fctiwz" },
    { "fdiv", "fdiv" },
    { "fdivs", "fdivs" },
    { "fmadd", "fmadd" },
    { "fmadds", "fmadds" },
    { "fmr", "fmr" },
    { "fmsub", "fmsub" },
    { "fmsubs", "fmsubs" },
    { "fmul", "fmul" },
    { "fmuls", "fmuls" },
    { "fnabs", "fnabs" },
    { "fneg", "fneg" },
    { "fnmadd", "fnmadd" },
    { "fnmadds", "fnmadds" },
    { "fnmsub", "fnmsub" },
    { "fnmsubs", "fnmsubs" },
    { "fres", "fres" },
    { "frim", "frim" },
    { "frin", "frin" },
    { "frip", "frip" },
    { "frsp", "frsp" },
    { "frsqrte", "frsqrte" },
    { "fsel", "fsel" },
    { "fsqrt", "fsqrt" },
    { "fsqrts", "fsqrts" },
    { "fsub", "fsub" },
    { "fsubs", "fsubs" },
    { "isync", "isync" },
    { "lbz", "lbz" },
    { "lbzu", "lbzu" },
    { "lbzux", "lbzux" },
    { "lbzx", "lbzx" },
    { "ld", "ld" },
    { "ldarx", "ldarx" },
    { "ldmx", "ldmx" },
    { "lwzmx", "lwzmx" },
    { "ldu", "ldu" },
    { "ldux", "ldux" },
    { "ldx", "ldx" },
    { "lfd", "lfd" },
    { "lfdp", "lfdp" },
    { "lfdu", "lfdu" },
    { "lfdux", "lfdux" },
    { "lfdx", "lfdx" },
    { "lfdpx", "lfdpx" },
    { "lfiwax", "lfiwax" },
    { "lfiwzx", "lfiwzx" },
    { "lfs", "lfs" },
    { "lfsu", "lfsu" },
    { "lfsux", "lfsux" },
    { "lfsx", "lfsx" },
    { "lha", "lha" },
    { "lhau", "lhau" },
    { "lhaux", "lhaux" },
    { "lhax", "lhax" },
    { "lhbrx", "lhbrx" },
    { "lhz", "lhz" },
    { "lhzu", "lhzu" },
    { "lhzux", "lhzux" },
    { "lhzx", "lhzx" },
    { "li", "li" },
    { "lis", "lis" },
    { "lmw", "lmw" },
    { "lswi", "lswi" },
    { "lswx", "lswx" },
    { "lwa", "lwa" },
    { "lwarx", "lwarx" },
    { "lwaux", "lwaux" },
    { "lwax", "lwax" },
    { "lwbrx", "lwbrx" },
    { "ldbrx", "ldbrx" },
    { "lwsync", "lwsync" },
    { "lwz", "lwz" },
    { "lwzu", "lwzu" },
    { "lwzux", "lwzux" },
    { "lwzx", "lwzx" },
    { "maddld", "maddld" },
    { "mcrf", "mcrf" },
    { "mcrfs", "mcrfs" },
    { "mcrxr", "mcrxr" },
    { "mfcr", "mfcr" },
    { "mfocrf", "mfocrf" },
    { "mfctr", "mfctr" },
    { "mffgpr", "mffgpr" },
    { "mffs", "mffs" },
    { "mflr", "mflr" },
    { "mfmsr", "mfmsr" },
    { "mfspr", "mfspr" },
    { "mftexasr", "mftexasr" },
    { "mftexasru", "mftexasru" },
    { "mftgpr", "mftgpr" },
    { "modud", "modud" },
    { "modsd", "modsd" },
    { "moduw", "moduw" },
    { "modsw", "modsw" },
    { "mr", "ori" },
    { "mtcrf", "mtcrf" },
    { "mtctr", "mtctr" },
    { "mtfsb0", "mtfsb0" },
    { "mtfsb1", "mtfsb1" },
    { "mtfsfl", "mtfsf" },
    { "mtfsfl_r", "mtfsf." },
    { "mtfsf", "mtfsf" },
    { "mtfsf_r", "mtfsf." },
    { "mtfsfw", "mtfsf" },
    { "mtfsfw_r", "mtfsf." },
    { "mtfsfi", "mtfsfi" },
    { "mtfsfi_r", "mtfsfi." },
    { "mtlr", "mtlr" },
    { "mtmsr", "mtmsr" },
    { "mtspr", "mtspr" },
    { "mfvsrd", "mfvsrd" },
    { "mfvsrwz", "mfvsrwz" },
    { "mtvsrd", "mtvsrd" },
    { "mtvsrwz", "mtvsrwz" },
    { "mtvsrwa", "mtvsrwa" },
    { "mulhd", "mulhd" },
    { "mulhd_r", "mulhd." },
    { "mulhdu", "mulhdu" },
    { "mulhdu_r", "mulhdu." },
    { "mulhw", "mulhw" },
    { "mulhw_r", "mulhw." },
    { "mulhwu", "mulhwu" },
    { "mulhwu_r", "mulhwu." },
    { "mulld", "mulld" },
    { "mulld_r", "mulld." },
    { "mulldo", "mulldo" },
    { "mulldo_r", "mulldo." },
    { "mulli", "mulli" },
    { "mullw", "mullw" },
    { "mullw_r", "mullw." },
    { "mullwo", "mullwo" },
    { "mullwo_r", "mullwo." },
    { "nand", "nand" },
    { "nand_r", "nand." },
    { "neg", "neg" },
    { "neg_r", "neg." },
    { "nego", "nego" },
    { "nego_r", "nego." },
    { "nor", "nor" },
    { "nor_r", "nor." },
    { "or", "or" },
    { "or_r", "or." },
    { "orc", "orc" },
    { "orc_r", "orc." },
    { "ori", "ori" },
    { "oris", "oris" },
    { "popcntd", "popcntd" },
    { "popcntw", "popcntw" },
    { "rfi", "rfi" },
    { "rldcl", "rldcl" },
    { "rldcl_r", "rldcl." },
    { "rldcr", "rldcr" },
    { "rldcr_r", "rldcr." },
    { "rldic", "rldic" },
    { "rldic_r", "rldic." },
    { "rldicl", "rldicl" },
    { "rldicl_r", "rldicl." },
    { "rldicr", "rldicr" },
    { "rldicr_r", "rldicr." },
    { "rldimi", "rldimi" },
    { "rldimi_r", "rldimi." },
    { "rlwimi", "rlwimi" },
    { "rlwimi_r", "rlwimi." },
    { "rlwinm", "rlwinm" },
    { "rlwinm_r", "rlwinm." },
    { "rlwnm", "rlwnm" },
    { "rlwnm_r", "rlwnm." },
    { "setb", "setb" },
    { "sld", "sld" },
    { "sld_r", "sld." },
    { "slw", "slw" },
    { "slw_r", "slw." },
    { "srad", "srad" },
    { "srad_r", "srad." },
    { "sradi", "sradi" },
    { "sradi_r", "sradi." },
    { "sraw", "sraw" },
    { "sraw_r", "sraw." },
    { "srawi", "srawi" },
    { "srawi_r", "srawi." },
    { "srd", "srd" },
    { "srd_r", "srd." },
    { "srw", "srw" },
    { "srw_r", "srw." },
    { "stb", "stb" },
    { "stbu", "stbu" },
    { "stbux", "stbux" },
    { "stbx", "stbx" },
    { "std", "std" },
    { "stdcx_r", "stdcx." },
    { "stdu", "stdu" },
    { "stdux", "stdux" },
    { "stdx", "stdx" },
    { "stfd", "stfd" },
    { "stfdp", "stfdp" },
    { "stfdu", "stfdu" },
    { "stfdux", "stfdux" },
    { "stfdx", "stfdx" },
    { "stfdpx", "stfdpx" },
    { "stfiwx", "stfiwx" },
    { "stfs", "stfs" },
    { "stfsu", "stfsu" },
    { "stfsux", "stfsux" },
    { "stfsx", "stfsx" },
    { "sth", "sth" },
    { "sthbrx", "sthbrx" },
    { "sthu", "sthu" },
    { "sthux", "sthux" },
    { "sthx", "sthx" },
    { "stmw", "stmw" },
    { "stswi", "stswi" },
    { "stswx", "stswx" },
    { "stw", "stw" },
    { "stwbrx", "stwbrx" },
    { "stdbrx", "stdbrx" },
    { "stwcx_r", "stwcx." },
    { "stwu", "stwu" },
    { "stwux", "stwux" },
    { "stwx", "stwx" },
    { "subf", "subf" },
    { "subf_r", "subf." },
    { "subfc", "subfc" },
    { "subfc_r", "subfc." },
    { "subfco", "subfco" },
    { "subfco_r", "subfco." },
    { "subfe", "subfe" },
    { "subfe_r", "subfe." },
    { "subfeo", "subfeo" },
    { "subfeo_r", "subfeo." },
    { "subfic", "subfic" },
    { "subfme", "subfme" },
    { "subfme_r", "subfme." },
    { "subfmeo", "subfmeo" },
    { "subfmeo_r", "subfmeo." },
    { "subfze", "subfze" },
    { "subfze_r", "subfze." },
    { "subfzeo", "subfzeo" },
    { "subfzeo_r", "subfzeo." },
    { "sync", "sync" },
    { "tabort_r", "tabort." },
    { "tabortdeq_r", "tabortdeq." },
    { "tabortdeqi_r", "tabortdeqi." },
    { "tabortdge_r", "tabortdge." },
    { "tabortdgei_r", "tabortdgei." },
    { "tabortdgt_r", "tabortdgt." },
    { "tabortdgti_r", "tabortdgti." },
    { "tabortdle_r", "tabortdle." },
    { "tabortdlei_r", "tabortdlei." },
    { "tabortdlge_r", "tabortdlge." },
    { "tabortdlgei_r", "tabortdlgei." },
    { "tabortdlgt_r", "tabortdlgt." },
    { "tabortdlgti_r", "tabortdlgti." },
    { "tabortdlle_r", "tabortdlle." },
    { "tabortdllei_r", "tabortdllei." },
    { "tabortdllt_r", "tabortdllt." },
    { "tabortdllti_r", "tabortdllti." },
    { "tabortdlt_r", "tabortdlt." },
    { "tabortdlti_r", "tabortdlti." },
    { "tabortdneq_r", "tabortdneq." },
    { "tabortdneqi_r", "tabortdneqi." },
    { "tabortweq_r", "tabortweq." },
    { "tabortweqi_r", "tabortweqi." },
    { "tabortwge_r", "tabortwge." },
    { "tabortwgei_r", "tabortwgei." },
    { "tabortwgt_r", "tabortwgt." },
    { "tabortwgti_r", "tabortwgti." },
    { "tabortwle_r", "tabortwle." },
    { "tabortwlei_r", "tabortwlei." },
    { "tabortwlge_r", "tabortwlge." },
    { "tabortwlgei_r", "tabortwlgei." },
    { "tabortwlgt_r", "tabortwlgt." },
    { "tabortwlgti_r", "tabortwlgti." },
    { "tabortwlle_r", "tabortwlle." },
    { "tabortwllei_r", "tabortwllei." },
    { "tabortwllt_r", "tabortwllt." },
    { "tabortwllti_r", "tabortwllti." },
    { "tabortwlt_r", "tabortwlt." },
    { "tabortwlti_r", "tabortwlti." },
    { "tabortwneq_r", "tabortwneq." },
    { "tabortwneqi_r", "tabortwneqi." },
    { "tbegin_r", "tbegin." },
    { "tbeginro_r", "tbeginro." },
    { "tend_r", "tend." },
    { "tendall_r", "tendall." },
    { "tdeq", "tdeq" },
    { "tdeqi", "tdeqi" },
    { "tdge", "tdge" },
    { "tdgei", "tdgei" },
    { "tdgt", "tdgt" },
    { "tdgti", "tdgti" },
    { "tdle", "tdle" },
    { "tdlei", "tdlei" },
    { "tdlge", "tdlge" },
    { "tdlgei", "tdlgei" },
    { "tdlgt", "tdlgt" },
    { "tdlgti", "tdlgti" },
    { "tdlle", "tdlle" },
    { "tdllei", "tdllei" },
    { "tdllt", "tdllt" },
    { "tdllti", "tdllti" },
    { "tdlt", "tdlt" },
    { "tdlti", "tdlti" },
    { "tdneq", "tdneq" },
    { "tdneqi", "tdneqi" },
    { "trap", "trap" },
    { "tweq", "tweq" },
    { "tweqi", "tweqi" },
    { "twge", "twge" },
    { "twgei", "twgei" },
    { "twgt", "twgt" },
    { "twgti", "twgti" },
    { "twle", "twle" },
    { "twlei", "twlei" },
    { "twlge", "twlge" },
    { "twlgei", "twlgei" },
    { "twlgt", "twlgt" },
    { "twlgti", "twlgti" },
    { "twlle", "twlle" },
    { "twllei", "twllei" },
    { "twllt", "twllt" },
    { "twllti", "twllti" },
    { "twlt", "twlt" },
    { "twlti", "twlti" },
    { "twneq", "twneq" },
    { "twneqi", "twneqi" },
    { "xor", "xor" },
    { "xor_r", "xor." },
    { "xori", "xori" },
    { "xoris", "xoris" },
    { "nop", "nop" },
    { "genop", "nop" },
    { "fence", "fence" },
    { "shdfence", "shdfence" },
    { "ret", "ret" },
    { "wrtbar", "wrtbar" },
    { "proc", "proc" },
    { "dd", ".long" },
    { "assocreg", "assocreg" },
    { "vgdnop", "vgdnop" },
    { "depend", "depend" },
    { "probenop", "nop" },
    { "iflong", "iflong" },
    { "setblong", "setblong" },
    { "setbool", "setbool" },
    { "setbflt", "setbflt" },
    { "lcmp", "lcmp" },
    { "flcmpl", "flcmpl" },
    { "flcmpg", "flcmpg" },
    { "idiv", "idiv" },
    { "ldiv", "ldiv" },
    { "irem", "irem" },
    { "lrem", "lrem" },
    { "cdnan", "cdnan" },
    { "cfnan", "cfnan" },
    { "d2i", "d2i" },
    { "d2l", "d2l" },
    { "ifx", "ifx" },
    { "setbx", "setbx" },
    { "iternary", "iternary" },
    { "lvsl", "lvsl" },
    { "lvsr", "lvsr" },
    { "lvx", "lvx" },
    { "lvebx", "lvebx" },
    { "lvehx", "lvehx" },
    { "lvewx", "lvewx" },
    { "stvx", "stvx" },
    { "stvebx", "stvebx" },
    { "stvehx", "stvehx" },
    { "stvewx", "stvewx" },
    { "vand", "vand" },
    { "vandc", "vandc" },
    { "vor", "vor" },
    { "vxor", "vxor" },
    { "vnor", "vnor" },
    { "vperm", "vperm" },
    { "vsel", "vsel" },
    { "vsumsws", "vsumsws" },
    { "vsum2sws", "vsum2sws" },
    { "vsum4sbs", "vsum4sbs" },
    { "vsum4shs", "vsum4shs" },
    { "vsum4ubs", "vsum4ubs" },
    { "vspltb", "vspltb" },
    { "vsplth", "vsplth" },
    { "vspltw", "vspltw" },
    { "vspltisb", "vspltisb" },
    { "vspltish", "vspltish" },
    { "vspltisw", "vspltisw" },
    { "vsl", "vsl" },
    { "vslb", "vslb" },
    { "vsldoi", "vsldoi" },
    { "vslh", "vslh" },
    { "vslo", "vslo" },
    { "vslw", "vslw" },
    { "vsr", "vsr" },
    { "vsrab", "vsrab" },
    { "vsrah", "vsrah" },
    { "vsraw", "vsraw" },
    { "vsrb", "vsrb" },
    { "vsrh", "vsrh" },
    { "vsro", "vsro" },
    { "vsrw", "vsrw" },
    { "vrlb", "vrlb" },
    { "vrlh", "vrlh" },
    { "vrlw", "vrlw" },
    { "vaddsbs", "vaddsbs" },
    { "vaddshs", "vaddshs" },
    { "vaddsws", "vaddsws" },
    { "vaddubm", "vaddubm" },
    { "vaddubs", "vaddubs" },
    { "vadduhm", "vadduhm" },
    { "vadduhs", "vadduhs" },
    { "vadduwm", "vadduwm" },
    { "vadduws", "vadduws" },
    { "vsubsbs", "vsubsbs" },
    { "vsubshs", "vsubshs" },
    { "vsubsws", "vsubsws" },
    { "vsububm", "vsububm" },
    { "vsububs", "vsububs" },
    { "vsubuhm", "vsubuhm" },
    { "vsubuhs", "vsubuhs" },
    { "vsubuwm", "vsubuwm" },
    { "vsubuws", "vsubuws" },
    { "vmulesh", "vmulesh" },
    { "vmulosh", "vmulosh" },
    { "vmulouh", "vmulouh" },
    { "vmuluwm", "vmuluwm" },
    { "vminsb", "vminsb" },
    { "vminsh", "vminsh" },
    { "vminsw", "vminsw" },
    { "vminub", "vminub" },
    { "vminuh", "vminuh" },
    { "vminuw", "vminuw" },
    { "vmaxsb", "vmaxsb" },
    { "vmaxsh", "vmaxsh" },
    { "vmaxsw", "vmaxsw" },
    { "vmaxub", "vmaxub" },
    { "vmaxuh", "vmaxuh" },
    { "vmaxuw", "vmaxuw" },
    { "vmsumuhm", "vmsumuhm" },
    { "vcmpequb", "vcmpequb" },
    { "vcmpeubr", "vcmpeubr" },
    { "vcmpequh", "vcmpequh" },
    { "vcmpeuhr", "vcmpeuhr" },
    { "vcmpequw", "vcmpequw" },
    { "vcmpeuwr", "vcmpeuwr" },
    { "vcmpgtsb", "vcmpgtsb" },
    { "vcmpgsbr", "vcmpgsbr" },
    { "vcmpgtsh", "vcmpgtsh" },
    { "vcmpgshr", "vcmpgshr" },
    { "vcmpgtsw", "vcmpgtsw" },
    { "vcmpgswr", "vcmpgswr" },
    { "vcmpgtub", "vcmpgtub" },
    { "vcmpgubr", "vcmpgubr" },
    { "vcmpgtuh", "vcmpgtuh" },
    { "vcmpguhr", "vcmpguhr" },
    { "vcmpgtuw", "vcmpgtuw" },
    { "vcmpguwr", "vcmpguwr" },
    { "vupkhsb", "vupkhsb" },
    { "vupkhsh", "vupkhsh" },
    { "vupklsb", "vupklsb" },
    { "vupklsh", "vupklsh" },
    { "vpkuhum", "vpkuhum" },
    { "vpkuwum", "vpkuwum" },
    { "vmrghb", "vmrghb" },
    { "vmrghh", "vmrghh" },
    { "vmrghw", "vmrghw" },
    { "vmrglb", "vmrglb" },
    { "vmrglh", "vmrglh" },
    { "vmrglw", "vmrglw" },
    { "lxsdx", "lxsdx" },
    { "lxsdux", "lxsdux" },
    { "stxsdx", "stxsdx" },
    { "stxsdux", "stxsdux" },
    { "lxvd2x", "lxvd2x" },
    { "lxvd2ux", "lxvd2ux" },
    { "lxvdsx", "lxvdsx" },
    { "lxvw4x", "lxvw4x" },
    { "lxvw4ux", "lxvw4ux" },
    { "stxvd2x", "stxvd2x" },
    { "stxvd2ux", "stxvd2ux" },
    { "stxvw4x", "stxvw4x" },
    { "stxvw4ux", "stxvw4ux" },
    { "xsabsdp", "xsabsdp" },
    { "xsadddp", "xsadddp" },
    { "xscmpodp", "xscmpodp" },
    { "xscmpudp", "xscmpudp" },
    { "xscpsgndp", "xscpsgndp" },
    { "xscvdpsxds", "xscvdpsxds" },
    { "xscvdpsxws", "xscvdpsxws" },
    { "xsdivdp", "xsdivdp" },
    { "xsmaddadp", "xsmaddadp" },
    { "xsmaddmdp", "xsmaddmdp" },
    { "xsmsubadp", "xsmsubadp" },
    { "xsmsubmdp", "xsmsubmdp" },
    { "xsmuldp", "xsmuldp" },
    { "xsnabsdp", "xsnabsdp" },
    { "xsnegdp", "xsnegdp" },
    { "xsnmaddadp", "xsnmaddadp" },
    { "xsnmaddmdp", "xsnmaddmdp" },
    { "xsnmsubadp", "xsnmsubadp" },
    { "xsnmsubmdp", "xsnmsubmdp" },
    { "xsrdpic", "xsrdpic" },
    { "xsredp", "xsredp" },
    { "xsrsqrtedp", "xsrsqrtedp" },
    { "xxlor", "xxlor" },
    { "xxlnor", "xxlnor" },
    { "xxsel", "xxsel" },
    { "xxsldwi", "xxsldwi" },
    { "xxspltw", "xxspltw" },
    { "xxpermdi", "xxpermdi" },
    { "xssqrtdp", "xssqrtdp" },
    { "xssubdp", "xssubdp" },
    { "xscvsxddp", "xscvsxddp" },
    { "xscvdpsp", "xscvdpsp" },
    { "xvadddp", "xvadddp" },
    { "xvmindp", "xvmindp" },
    { "xvmaxdp", "xvmaxdp" },
    { "xvcmpeqdp", "xvcmpeqdp" },
    { "xvcmpeqdp_r", "xvcmpeqdp." },
    { "xvcmpgedp", "xvcmpgedp" },
    { "xvcmpgedp_r", "xvcmpgedp." },
    { "xvcmpgtdp", "xvcmpgtdp" },
    { "xvcmpgtdp_r", "xvcmpgtdp." },
    { "xvdivdp", "xvdivdp" },
    { "xvmuldp", "xvmuldp" },
    { "xvnegdp", "xvnegdp" },
    { "xvnmsubadp", "xvnmsubadp" },
    { "xvnmsubmdp", "xvnmsubmdp" },
    { "xvsubdp", "xvsubdp" },
    { "xvmaddadp", "xvmaddadp" },
    { "xvmaddmdp", "xvmaddmdp" },
    { "xvmsubadp", "xvmsubadp" },
    { "xvmsubmdp", "xvmsubmdp" },
    { "xvsqrtdp", "xvsqrtdp" },
    { "fmrgew", "fmrgew" },
    { "fmrgow", "fmrgow" },
    { "lxsiwax", "lxsiwax" },
    { "lxsiwzx", "lxsiwzx" },
    { "lxsspx", "lxsspx" },
    { "stxsiwx", "stxsiwx" },
    { "stxsspx", "stxsspx" },
    { "xsaddsp", "xsaddsp" },
    { "xscvdpspn", "xscvdpspn" },
    { "xscvdpuxds", "xscvdpuxds" },
    { "xscvdpuxws", "xscvdpuxws" },
    { "xscvspdp", "xscvspdp" },
    { "xscvspdpn", "xscvspdpn" },
    { "xscvsxdsp", "xscvsxdsp" },
    { "xscvuxddp", "xscvuxddp" },
    { "xscvuxdsp", "xscvuxdsp" },
    { "xsdivsp", "xsdivsp" },
    { "xsmaddasp", "xsmaddasp" },
    { "xsmaddmsp", "xsmaddmsp" },
    { "xsmaxdp", "xsmaxdp" },
    { "xsmindp", "xsmindp" },
    { "xsmsubasp", "xsmsubasp" },
    { "xsmsubmsp", "xsmsubmsp" },
    { "xsmulsp", "xsmulsp" },
    { "xsnmaddasp", "xsnmaddasp" },
    { "xsnmaddmsp", "xsnmaddmsp" },
    { "xsnmsubasp", "xsnmsubasp" },
    { "xsnmsubmsp", "xsnmsubmsp" },
    { "xsrdpi", "xsrdpi" },
    { "xsrdpim", "xsrdpim" },
    { "xsrdpip", "xsrdpip" },
    { "xsrdpiz", "xsrdpiz" },
    { "xsresp", "xsresp" },
    { "xsrsp", "xsrsp" },
    { "xsrsqrtesp", "xsrsqrtesp" },
    { "xssqrtsp", "xssqrtsp" },
    { "xssubsp", "xssubsp" },
    { "xxland", "xxland" },
    { "xxlandc", "xxlandc" },
    { "xxleqv", "xxleqv" },
    { "xxlnand", "xxlnand" },
    { "xxlorc", "xxlorc" },
    { "xxlxor", "xxlxor" },
    { "xxmrghw", "xxmrghw" },
    { "xxmrglw", "xxmrglw" },
    { "vmrgew", "vmrgew" },
    { "vmrgow", "vmrgow" },
    { "xvabsdp", "xvabsdp" },
    { "xvabssp", "xvabssp" },
    { "xvaddsp", "xvaddsp" },
    { "xvcmpeqsp", "xvcmpeqsp" },
    { "xvcmpeqsp_r", "xvcmpeqsp." },
    { "xvcmpgesp", "xvcmpgesp" },
    { "xvcmpgesp_r", "xvcmpgesp." },
    { "xvcmpgtsp", "xvcmpgtsp" },
    { "xvcmpgtsp_r", "xvcmpgtsp." },
    { "xvcpsgndp", "xvcpsgndp" },
    { "xvcpsgnsp", "xvcpsgnsp" },
    { "xvcvdpsp", "xvcvdpsp" },
    { "xvcvdpsxds", "xvcvdpsxds" },
    { "xvcvdpsxws", "xvcvdpsxws" },
    { "xvcvdpuxds", "xvcvdpuxds" },
    { "xvcvdpuxws", "xvcvdpuxws" },
    { "xvcvspdp", "xvcvspdp" },
    { "xvcvspsxds", "xvcvspsxds" },
    { "xvcvspsxws", "xvcvspsxws" },
    { "xvcvspuxds", "xvcvspuxds" },
    { "xvcvspuxws", "xvcvspuxws" },
    { "xvcvsxddp", "xvcvsxddp" },
    { "xvcvsxdsp", "xvcvsxdsp" },
    { "xvcvsxwdp", "xvcvsxwdp" },
    { "xvcvsxwsp", "xvcvsxwsp" },
    { "xvcvuxddp", "xvcvuxddp" },
    { "xvcvuxdsp", "xvcvuxdsp" },
    { "xvcvuxwdp", "xvcvuxwdp" },
    { "xvcvuxwsp", "xvcvuxwsp" },
    { "xvdivsp", "xvdivsp" },
    { "xvmaddasp", "xvmaddasp" },
    { "xvmaddmsp", "xvmaddmsp" },
    { "xvmaxsp", "xvmaxsp" },
    { "xvminsp", "xvminsp" },
    { "xvmsubasp", "xvmsubasp" },
    { "xvmsubmsp", "xvmsubmsp" },
    { "xvmulsp", "xvmulsp" },
    { "xvnabsdp", "xvnabsdp" },
    { "xvnabssp", "xvnabssp" },
    { "xvnegsp", "xvnegsp" },
    { "xvnmaddadp", "xvnmaddadp" },
    { "xvnmaddasp", "xvnmaddasp" },
    { "xvnmaddmdp", "xvnmaddmdp" },
    { "xvnmaddmsp", "xvnmaddmsp" },
    { "xvnmsubasp", "xvnmsubasp" },
    { "xvnmsubmsp", "xvnmsubmsp" },
    { "xvrdpi", "xvrdpi" },
    { "xvrdpic", "xvrdpic" },
    { "xvrdpim", "xvrdpim" },
    { "xvrdpip", "xvrdpip" },
    { "xvrdpiz", "xvrdpiz" },
    { "xvredp", "xvredp" },
    { "xvresp", "xvresp" },
    { "xvrspi", "xvrspi" },
    { "xvrspic", "xvrspic" },
    { "xvrspim", "xvrspim" },
    { "xvrspip", "xvrspip" },
    { "xvrspiz", "xvrspiz" },
    { "xvrsqrtedp", "xvrsqrtedp" },
    { "xvrsqrtesp", "xvrsqrtesp" },
    { "xvsqrtsp", "xvsqrtsp" },
    { "xvsubsp", "xvsubsp" },
    { "label", "label" }
};
#endif
