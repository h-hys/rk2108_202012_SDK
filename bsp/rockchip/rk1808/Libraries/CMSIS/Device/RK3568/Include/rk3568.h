/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

#ifndef __RK3568_H
#define __RK3568_H
#ifdef __cplusplus
  extern "C" {
#endif
/****************************************************************************************/
/*                                                                                      */
/*                               Module Structure Section                               */
/*                                                                                      */
/****************************************************************************************/
#ifndef __ASSEMBLY__
/* PMU_GRF Register Structure Define */
struct PMU_GRF_REG {
    __IO uint32_t GPIO0A_IOMUX_L;                     /* Address Offset: 0x0000 */
    __IO uint32_t GPIO0A_IOMUX_H;                     /* Address Offset: 0x0004 */
    __IO uint32_t GPIO0B_IOMUX_L;                     /* Address Offset: 0x0008 */
    __IO uint32_t GPIO0B_IOMUX_H;                     /* Address Offset: 0x000C */
    __IO uint32_t GPIO0C_IOMUX_L;                     /* Address Offset: 0x0010 */
    __IO uint32_t GPIO0C_IOMUX_H;                     /* Address Offset: 0x0014 */
    __IO uint32_t GPIO0D_IOMUX_L;                     /* Address Offset: 0x0018 */
         uint32_t RESERVED001C;                       /* Address Offset: 0x001C */
    __IO uint32_t GPIO0A_P;                           /* Address Offset: 0x0020 */
    __IO uint32_t GPIO0B_P;                           /* Address Offset: 0x0024 */
    __IO uint32_t GPIO0C_P;                           /* Address Offset: 0x0028 */
    __IO uint32_t GPIO0D_P;                           /* Address Offset: 0x002C */
    __IO uint32_t GPIO0A_IE;                          /* Address Offset: 0x0030 */
    __IO uint32_t GPIO0B_IE;                          /* Address Offset: 0x0034 */
    __IO uint32_t GPIO0C_IE;                          /* Address Offset: 0x0038 */
    __IO uint32_t GPIO0D_IE;                          /* Address Offset: 0x003C */
    __IO uint32_t GPIO0A_OPD;                         /* Address Offset: 0x0040 */
    __IO uint32_t GPIO0B_OPD;                         /* Address Offset: 0x0044 */
    __IO uint32_t GPIO0C_OPD;                         /* Address Offset: 0x0048 */
    __IO uint32_t GPIO0D_OPD;                         /* Address Offset: 0x004C */
    __IO uint32_t GPIO0A_SUS;                         /* Address Offset: 0x0050 */
    __IO uint32_t GPIO0B_SUS;                         /* Address Offset: 0x0054 */
    __IO uint32_t GPIO0C_SUS;                         /* Address Offset: 0x0058 */
    __IO uint32_t GPIO0D_SUS;                         /* Address Offset: 0x005C */
    __IO uint32_t GPIO0A_SL;                          /* Address Offset: 0x0060 */
    __IO uint32_t GPIO0B_SL;                          /* Address Offset: 0x0064 */
    __IO uint32_t GPIO0C_SL;                          /* Address Offset: 0x0068 */
    __IO uint32_t GPIO0D_SL;                          /* Address Offset: 0x006C */
    __IO uint32_t GPIO0A_DS_0;                        /* Address Offset: 0x0070 */
    __IO uint32_t GPIO0A_DS_1;                        /* Address Offset: 0x0074 */
    __IO uint32_t GPIO0A_DS_2;                        /* Address Offset: 0x0078 */
    __IO uint32_t GPIO0A_DS_3;                        /* Address Offset: 0x007C */
    __IO uint32_t GPIO0B_DS_0;                        /* Address Offset: 0x0080 */
    __IO uint32_t GPIO0B_DS_1;                        /* Address Offset: 0x0084 */
    __IO uint32_t GPIO0B_DS_2;                        /* Address Offset: 0x0088 */
    __IO uint32_t GPIO0B_DS_3;                        /* Address Offset: 0x008C */
    __IO uint32_t GPIO0C_DS_0;                        /* Address Offset: 0x0090 */
    __IO uint32_t GPIO0C_DS_1;                        /* Address Offset: 0x0094 */
    __IO uint32_t GPIO0C_DS_2;                        /* Address Offset: 0x0098 */
    __IO uint32_t GPIO0C_DS_3;                        /* Address Offset: 0x009C */
    __IO uint32_t GPIO0D_DS_0;                        /* Address Offset: 0x00A0 */
    __IO uint32_t GPIO0D_DS_1;                        /* Address Offset: 0x00A4 */
    __IO uint32_t GPIO0D_DS_2;                        /* Address Offset: 0x00A8 */
    __IO uint32_t GPIO0D_DS_3;                        /* Address Offset: 0x00AC */
         uint32_t RESERVED00B0[20];                   /* Address Offset: 0x00B0 */
    __IO uint32_t SOC_CON0;                           /* Address Offset: 0x0100 */
    __IO uint32_t SOC_CON1;                           /* Address Offset: 0x0104 */
    __IO uint32_t SOC_CON2;                           /* Address Offset: 0x0108 */
    __IO uint32_t SOC_CON3;                           /* Address Offset: 0x010C */
    __IO uint32_t SOC_CON4;                           /* Address Offset: 0x0110 */
    __IO uint32_t SOC_CON5;                           /* Address Offset: 0x0114 */
         uint32_t RESERVED0118[3];                    /* Address Offset: 0x0118 */
    __IO uint32_t IO_VSEL0;                           /* Address Offset: 0x0124 */
    __IO uint32_t IO_VSEL1;                           /* Address Offset: 0x0128 */
    __IO uint32_t IO_VSEL2;                           /* Address Offset: 0x012C */
         uint32_t RESERVED0130[20];                   /* Address Offset: 0x0130 */
    __IO uint32_t DLL_CON0;                           /* Address Offset: 0x0180 */
         uint32_t RESERVED0184[31];                   /* Address Offset: 0x0184 */
    __IO uint32_t OS_REG0;                            /* Address Offset: 0x0200 */
    __IO uint32_t OS_REG1;                            /* Address Offset: 0x0204 */
    __IO uint32_t OS_REG2;                            /* Address Offset: 0x0208 */
    __IO uint32_t OS_REG3;                            /* Address Offset: 0x020C */
    __IO uint32_t OS_REG4;                            /* Address Offset: 0x0210 */
    __IO uint32_t OS_REG5;                            /* Address Offset: 0x0214 */
    __IO uint32_t OS_REG6;                            /* Address Offset: 0x0218 */
    __IO uint32_t OS_REG7;                            /* Address Offset: 0x021C */
    __IO uint32_t OS_REG8;                            /* Address Offset: 0x0220 */
    __IO uint32_t OS_REG9;                            /* Address Offset: 0x0224 */
    __IO uint32_t OS_REG10;                           /* Address Offset: 0x0228 */
    __IO uint32_t OS_REG11;                           /* Address Offset: 0x022C */
    __IO uint32_t RESET_FUNCTION_STATUS;              /* Address Offset: 0x0230 */
    __IO uint32_t RESET_FUNCTION_CLR;                 /* Address Offset: 0x0234 */
         uint32_t RESERVED0238[82];                   /* Address Offset: 0x0238 */
    __IO uint32_t SIG_DETECT_CON;                     /* Address Offset: 0x0380 */
         uint32_t RESERVED0384[3];                    /* Address Offset: 0x0384 */
    __IO uint32_t SIG_DETECT_STATUS;                  /* Address Offset: 0x0390 */
         uint32_t RESERVED0394[3];                    /* Address Offset: 0x0394 */
    __IO uint32_t SIG_DETECT_STATUS_CLEAR;            /* Address Offset: 0x03A0 */
         uint32_t RESERVED03A4[3];                    /* Address Offset: 0x03A4 */
    __IO uint32_t SDMMC_DET_COUNTER;                  /* Address Offset: 0x03B0 */
};
/* PMUCRU Register Structure Define */
struct PMUCRU_REG {
    __IO uint32_t PPLL_CON0;                          /* Address Offset: 0x0000 */
    __IO uint32_t PPLL_CON1;                          /* Address Offset: 0x0004 */
    __IO uint32_t PPLL_CON2;                          /* Address Offset: 0x0008 */
    __IO uint32_t PPLL_CON3;                          /* Address Offset: 0x000C */
    __IO uint32_t PPLL_CON4;                          /* Address Offset: 0x0010 */
         uint32_t RESERVED0014[3];                    /* Address Offset: 0x0014 */
    __IO uint32_t HPLL_CON0;                          /* Address Offset: 0x0020 */
    __IO uint32_t HPLL_CON1;                          /* Address Offset: 0x0024 */
    __IO uint32_t HPLL_CON2;                          /* Address Offset: 0x0028 */
    __IO uint32_t HPLL_CON3;                          /* Address Offset: 0x002C */
    __IO uint32_t HPLL_CON4;                          /* Address Offset: 0x0030 */
         uint32_t RESERVED0034[19];                   /* Address Offset: 0x0034 */
    __IO uint32_t MODE_CON00;                         /* Address Offset: 0x0080 */
         uint32_t RESERVED0084[31];                   /* Address Offset: 0x0084 */
    __IO uint32_t PMUCLKSEL_CON00;                    /* Address Offset: 0x0100 */
    __IO uint32_t PMUCLKSEL_CON01;                    /* Address Offset: 0x0104 */
    __IO uint32_t PMUCLKSEL_CON02;                    /* Address Offset: 0x0108 */
    __IO uint32_t PMUCLKSEL_CON03;                    /* Address Offset: 0x010C */
    __IO uint32_t PMUCLKSEL_CON04;                    /* Address Offset: 0x0110 */
    __IO uint32_t PMUCLKSEL_CON05;                    /* Address Offset: 0x0114 */
    __IO uint32_t PMUCLKSEL_CON06;                    /* Address Offset: 0x0118 */
    __IO uint32_t PMUCLKSEL_CON07;                    /* Address Offset: 0x011C */
    __IO uint32_t PMUCLKSEL_CON08;                    /* Address Offset: 0x0120 */
    __IO uint32_t PMUCLKSEL_CON09;                    /* Address Offset: 0x0124 */
         uint32_t RESERVED0128[22];                   /* Address Offset: 0x0128 */
    __IO uint32_t PMUGATE_CON00;                      /* Address Offset: 0x0180 */
    __IO uint32_t PMUGATE_CON01;                      /* Address Offset: 0x0184 */
    __IO uint32_t PMUGATE_CON02;                      /* Address Offset: 0x0188 */
         uint32_t RESERVED018C[29];                   /* Address Offset: 0x018C */
    __IO uint32_t PMUSOFTRST_CON00;                   /* Address Offset: 0x0200 */
};
/* CRU Register Structure Define */
struct CRU_REG {
    __IO uint32_t APLL_CON0;                          /* Address Offset: 0x0000 */
    __IO uint32_t APLL_CON1;                          /* Address Offset: 0x0004 */
    __IO uint32_t APLL_CON2;                          /* Address Offset: 0x0008 */
    __IO uint32_t APLL_CON3;                          /* Address Offset: 0x000C */
    __IO uint32_t APLL_CON4;                          /* Address Offset: 0x0010 */
         uint32_t RESERVED0014[3];                    /* Address Offset: 0x0014 */
    __IO uint32_t DPLL_CON0;                          /* Address Offset: 0x0020 */
    __IO uint32_t DPLL_CON1;                          /* Address Offset: 0x0024 */
    __IO uint32_t DPLL_CON2;                          /* Address Offset: 0x0028 */
    __IO uint32_t DPLL_CON3;                          /* Address Offset: 0x002C */
    __IO uint32_t DPLL_CON4;                          /* Address Offset: 0x0030 */
         uint32_t RESERVED0034[3];                    /* Address Offset: 0x0034 */
    __IO uint32_t GPLL_CON0;                          /* Address Offset: 0x0040 */
    __IO uint32_t GPLL_CON1;                          /* Address Offset: 0x0044 */
    __IO uint32_t GPLL_CON2;                          /* Address Offset: 0x0048 */
    __IO uint32_t GPLL_CON3;                          /* Address Offset: 0x004C */
    __IO uint32_t GPLL_CON4;                          /* Address Offset: 0x0050 */
         uint32_t RESERVED0054[3];                    /* Address Offset: 0x0054 */
    __IO uint32_t CPLL_CON0;                          /* Address Offset: 0x0060 */
    __IO uint32_t CPLL_CON1;                          /* Address Offset: 0x0064 */
    __IO uint32_t CPLL_CON2;                          /* Address Offset: 0x0068 */
    __IO uint32_t CPLL_CON3;                          /* Address Offset: 0x006C */
    __IO uint32_t CPLL_CON4;                          /* Address Offset: 0x0070 */
         uint32_t RESERVED0074[3];                    /* Address Offset: 0x0074 */
    __IO uint32_t NPLL_CON0;                          /* Address Offset: 0x0080 */
    __IO uint32_t NPLL_CON1;                          /* Address Offset: 0x0084 */
         uint32_t RESERVED0088[6];                    /* Address Offset: 0x0088 */
    __IO uint32_t VPLL_CON0;                          /* Address Offset: 0x00A0 */
    __IO uint32_t VPLL_CON1;                          /* Address Offset: 0x00A4 */
         uint32_t RESERVED00A8[6];                    /* Address Offset: 0x00A8 */
    __IO uint32_t MODE_CON00;                         /* Address Offset: 0x00C0 */
    __IO uint32_t MISC_CON0;                          /* Address Offset: 0x00C4 */
    __IO uint32_t MISC_CON1;                          /* Address Offset: 0x00C8 */
    __IO uint32_t MISC_CON2;                          /* Address Offset: 0x00CC */
    __IO uint32_t GLB_CNT_TH;                         /* Address Offset: 0x00D0 */
    __IO uint32_t GLB_SRST_FST;                       /* Address Offset: 0x00D4 */
    __IO uint32_t GLB_SRST_SND;                       /* Address Offset: 0x00D8 */
    __IO uint32_t GLB_RST_CON;                        /* Address Offset: 0x00DC */
    __IO uint32_t GLB_RST_ST;                         /* Address Offset: 0x00E0 */
         uint32_t RESERVED00E4[7];                    /* Address Offset: 0x00E4 */
    __IO uint32_t CLKSEL_CON00;                       /* Address Offset: 0x0100 */
    __IO uint32_t CLKSEL_CON01;                       /* Address Offset: 0x0104 */
    __IO uint32_t CLKSEL_CON02;                       /* Address Offset: 0x0108 */
    __IO uint32_t CLKSEL_CON03;                       /* Address Offset: 0x010C */
    __IO uint32_t CLKSEL_CON04;                       /* Address Offset: 0x0110 */
    __IO uint32_t CLKSEL_CON05;                       /* Address Offset: 0x0114 */
    __IO uint32_t CLKSEL_CON06;                       /* Address Offset: 0x0118 */
    __IO uint32_t CLKSEL_CON07;                       /* Address Offset: 0x011C */
    __IO uint32_t CLKSEL_CON08;                       /* Address Offset: 0x0120 */
    __IO uint32_t CLKSEL_CON09;                       /* Address Offset: 0x0124 */
    __IO uint32_t CLKSEL_CON10;                       /* Address Offset: 0x0128 */
    __IO uint32_t CLKSEL_CON11;                       /* Address Offset: 0x012C */
    __IO uint32_t CLKSEL_CON12;                       /* Address Offset: 0x0130 */
    __IO uint32_t CLKSEL_CON13;                       /* Address Offset: 0x0134 */
    __IO uint32_t CLKSEL_CON14;                       /* Address Offset: 0x0138 */
    __IO uint32_t CLKSEL_CON15;                       /* Address Offset: 0x013C */
    __IO uint32_t CLKSEL_CON16;                       /* Address Offset: 0x0140 */
    __IO uint32_t CLKSEL_CON17;                       /* Address Offset: 0x0144 */
    __IO uint32_t CLKSEL_CON18;                       /* Address Offset: 0x0148 */
    __IO uint32_t CLKSEL_CON19;                       /* Address Offset: 0x014C */
    __IO uint32_t CLKSEL_CON20;                       /* Address Offset: 0x0150 */
    __IO uint32_t CLKSEL_CON21;                       /* Address Offset: 0x0154 */
    __IO uint32_t CLKSEL_CON22;                       /* Address Offset: 0x0158 */
    __IO uint32_t CLKSEL_CON23;                       /* Address Offset: 0x015C */
    __IO uint32_t CLKSEL_CON24;                       /* Address Offset: 0x0160 */
    __IO uint32_t CLKSEL_CON25;                       /* Address Offset: 0x0164 */
    __IO uint32_t CLKSEL_CON26;                       /* Address Offset: 0x0168 */
    __IO uint32_t CLKSEL_CON27;                       /* Address Offset: 0x016C */
    __IO uint32_t CLKSEL_CON28;                       /* Address Offset: 0x0170 */
    __IO uint32_t CLKSEL_CON29;                       /* Address Offset: 0x0174 */
    __IO uint32_t CLKSEL_CON30;                       /* Address Offset: 0x0178 */
    __IO uint32_t CLKSEL_CON31;                       /* Address Offset: 0x017C */
    __IO uint32_t CLKSEL_CON32;                       /* Address Offset: 0x0180 */
    __IO uint32_t CLKSEL_CON33;                       /* Address Offset: 0x0184 */
    __IO uint32_t CLKSEL_CON34;                       /* Address Offset: 0x0188 */
    __IO uint32_t CLKSEL_CON35;                       /* Address Offset: 0x018C */
    __IO uint32_t CLKSEL_CON36;                       /* Address Offset: 0x0190 */
    __IO uint32_t CLKSEL_CON37;                       /* Address Offset: 0x0194 */
    __IO uint32_t CLKSEL_CON38;                       /* Address Offset: 0x0198 */
    __IO uint32_t CLKSEL_CON39;                       /* Address Offset: 0x019C */
    __IO uint32_t CLKSEL_CON40;                       /* Address Offset: 0x01A0 */
    __IO uint32_t CLKSEL_CON41;                       /* Address Offset: 0x01A4 */
    __IO uint32_t CLKSEL_CON42;                       /* Address Offset: 0x01A8 */
    __IO uint32_t CLKSEL_CON43;                       /* Address Offset: 0x01AC */
    __IO uint32_t CLKSEL_CON44;                       /* Address Offset: 0x01B0 */
    __IO uint32_t CLKSEL_CON45;                       /* Address Offset: 0x01B4 */
         uint32_t RESERVED01B8;                       /* Address Offset: 0x01B8 */
    __IO uint32_t CLKSEL_CON47;                       /* Address Offset: 0x01BC */
    __IO uint32_t CLKSEL_CON48;                       /* Address Offset: 0x01C0 */
    __IO uint32_t CLKSEL_CON49;                       /* Address Offset: 0x01C4 */
    __IO uint32_t CLKSEL_CON50;                       /* Address Offset: 0x01C8 */
    __IO uint32_t CLKSEL_CON51;                       /* Address Offset: 0x01CC */
    __IO uint32_t CLKSEL_CON52;                       /* Address Offset: 0x01D0 */
    __IO uint32_t CLKSEL_CON53;                       /* Address Offset: 0x01D4 */
    __IO uint32_t CLKSEL_CON54;                       /* Address Offset: 0x01D8 */
    __IO uint32_t CLKSEL_CON55;                       /* Address Offset: 0x01DC */
    __IO uint32_t CLKSEL_CON56;                       /* Address Offset: 0x01E0 */
    __IO uint32_t CLKSEL_CON57;                       /* Address Offset: 0x01E4 */
    __IO uint32_t CLKSEL_CON58;                       /* Address Offset: 0x01E8 */
    __IO uint32_t CLKSEL_CON59;                       /* Address Offset: 0x01EC */
    __IO uint32_t CLKSEL_CON60;                       /* Address Offset: 0x01F0 */
    __IO uint32_t CLKSEL_CON61;                       /* Address Offset: 0x01F4 */
    __IO uint32_t CLKSEL_CON62;                       /* Address Offset: 0x01F8 */
    __IO uint32_t CLKSEL_CON63;                       /* Address Offset: 0x01FC */
    __IO uint32_t CLKSEL_CON64;                       /* Address Offset: 0x0200 */
    __IO uint32_t CLKSEL_CON65;                       /* Address Offset: 0x0204 */
    __IO uint32_t CLKSEL_CON66;                       /* Address Offset: 0x0208 */
    __IO uint32_t CLKSEL_CON67;                       /* Address Offset: 0x020C */
    __IO uint32_t CLKSEL_CON68;                       /* Address Offset: 0x0210 */
    __IO uint32_t CLKSEL_CON69;                       /* Address Offset: 0x0214 */
    __IO uint32_t CLKSEL_CON70;                       /* Address Offset: 0x0218 */
    __IO uint32_t CLKSEL_CON71;                       /* Address Offset: 0x021C */
    __IO uint32_t CLKSEL_CON72;                       /* Address Offset: 0x0220 */
    __IO uint32_t CLKSEL_CON73;                       /* Address Offset: 0x0224 */
    __IO uint32_t CLKSEL_CON74;                       /* Address Offset: 0x0228 */
    __IO uint32_t CLKSEL_CON75;                       /* Address Offset: 0x022C */
    __IO uint32_t CLKSEL_CON76;                       /* Address Offset: 0x0230 */
    __IO uint32_t CLKSEL_CON77;                       /* Address Offset: 0x0234 */
    __IO uint32_t CLKSEL_CON78;                       /* Address Offset: 0x0238 */
    __IO uint32_t CLKSEL_CON79;                       /* Address Offset: 0x023C */
    __IO uint32_t CLKSEL_CON80;                       /* Address Offset: 0x0240 */
    __IO uint32_t CLKSEL_CON81;                       /* Address Offset: 0x0244 */
    __IO uint32_t CLKSEL_CON82;                       /* Address Offset: 0x0248 */
    __IO uint32_t CLKSEL_CON83;                       /* Address Offset: 0x024C */
    __IO uint32_t CLKSEL_CON84;                       /* Address Offset: 0x0250 */
         uint32_t RESERVED0254[43];                   /* Address Offset: 0x0254 */
    __IO uint32_t GATE_CON00;                         /* Address Offset: 0x0300 */
    __IO uint32_t GATE_CON01;                         /* Address Offset: 0x0304 */
    __IO uint32_t GATE_CON02;                         /* Address Offset: 0x0308 */
    __IO uint32_t GATE_CON03;                         /* Address Offset: 0x030C */
    __IO uint32_t GATE_CON04;                         /* Address Offset: 0x0310 */
    __IO uint32_t GATE_CON05;                         /* Address Offset: 0x0314 */
    __IO uint32_t GATE_CON06;                         /* Address Offset: 0x0318 */
    __IO uint32_t GATE_CON07;                         /* Address Offset: 0x031C */
    __IO uint32_t GATE_CON08;                         /* Address Offset: 0x0320 */
    __IO uint32_t GATE_CON09;                         /* Address Offset: 0x0324 */
    __IO uint32_t GATE_CON10;                         /* Address Offset: 0x0328 */
    __IO uint32_t GATE_CON11;                         /* Address Offset: 0x032C */
    __IO uint32_t GATE_CON12;                         /* Address Offset: 0x0330 */
    __IO uint32_t GATE_CON13;                         /* Address Offset: 0x0334 */
    __IO uint32_t GATE_CON14;                         /* Address Offset: 0x0338 */
    __IO uint32_t GATE_CON15;                         /* Address Offset: 0x033C */
    __IO uint32_t GATE_CON16;                         /* Address Offset: 0x0340 */
    __IO uint32_t GATE_CON17;                         /* Address Offset: 0x0344 */
    __IO uint32_t GATE_CON18;                         /* Address Offset: 0x0348 */
    __IO uint32_t GATE_CON19;                         /* Address Offset: 0x034C */
    __IO uint32_t GATE_CON20;                         /* Address Offset: 0x0350 */
    __IO uint32_t GATE_CON21;                         /* Address Offset: 0x0354 */
    __IO uint32_t GATE_CON22;                         /* Address Offset: 0x0358 */
    __IO uint32_t GATE_CON23;                         /* Address Offset: 0x035C */
    __IO uint32_t GATE_CON24;                         /* Address Offset: 0x0360 */
    __IO uint32_t GATE_CON25;                         /* Address Offset: 0x0364 */
    __IO uint32_t GATE_CON26;                         /* Address Offset: 0x0368 */
    __IO uint32_t GATE_CON27;                         /* Address Offset: 0x036C */
    __IO uint32_t GATE_CON28;                         /* Address Offset: 0x0370 */
    __IO uint32_t GATE_CON29;                         /* Address Offset: 0x0374 */
    __IO uint32_t GATE_CON30;                         /* Address Offset: 0x0378 */
    __IO uint32_t GATE_CON31;                         /* Address Offset: 0x037C */
    __IO uint32_t GATE_CON32;                         /* Address Offset: 0x0380 */
    __IO uint32_t GATE_CON33;                         /* Address Offset: 0x0384 */
    __IO uint32_t GATE_CON34;                         /* Address Offset: 0x0388 */
    __IO uint32_t GATE_CON35;                         /* Address Offset: 0x038C */
         uint32_t RESERVED0390[28];                   /* Address Offset: 0x0390 */
    __IO uint32_t SOFTRST_CON00;                      /* Address Offset: 0x0400 */
    __IO uint32_t SOFTRST_CON01;                      /* Address Offset: 0x0404 */
    __IO uint32_t SOFTRST_CON02;                      /* Address Offset: 0x0408 */
    __IO uint32_t SOFTRST_CON03;                      /* Address Offset: 0x040C */
    __IO uint32_t SOFTRST_CON04;                      /* Address Offset: 0x0410 */
    __IO uint32_t SOFTRST_CON05;                      /* Address Offset: 0x0414 */
    __IO uint32_t SOFTRST_CON06;                      /* Address Offset: 0x0418 */
    __IO uint32_t SOFTRST_CON07;                      /* Address Offset: 0x041C */
    __IO uint32_t SOFTRST_CON08;                      /* Address Offset: 0x0420 */
    __IO uint32_t SOFTRST_CON09;                      /* Address Offset: 0x0424 */
    __IO uint32_t SOFTRST_CON10;                      /* Address Offset: 0x0428 */
         uint32_t RESERVED042C;                       /* Address Offset: 0x042C */
    __IO uint32_t SOFTRST_CON12;                      /* Address Offset: 0x0430 */
    __IO uint32_t SOFTRST_CON13;                      /* Address Offset: 0x0434 */
    __IO uint32_t SOFTRST_CON14;                      /* Address Offset: 0x0438 */
    __IO uint32_t SOFTRST_CON15;                      /* Address Offset: 0x043C */
    __IO uint32_t SOFTRST_CON16;                      /* Address Offset: 0x0440 */
    __IO uint32_t SOFTRST_CON17;                      /* Address Offset: 0x0444 */
    __IO uint32_t SOFTRST_CON18;                      /* Address Offset: 0x0448 */
    __IO uint32_t SOFTRST_CON19;                      /* Address Offset: 0x044C */
    __IO uint32_t SOFTRST_CON20;                      /* Address Offset: 0x0450 */
    __IO uint32_t SOFTRST_CON21;                      /* Address Offset: 0x0454 */
    __IO uint32_t SOFTRST_CON22;                      /* Address Offset: 0x0458 */
    __IO uint32_t SOFTRST_CON23;                      /* Address Offset: 0x045C */
    __IO uint32_t SOFTRST_CON24;                      /* Address Offset: 0x0460 */
    __IO uint32_t SOFTRST_CON25;                      /* Address Offset: 0x0464 */
    __IO uint32_t SOFTRST_CON26;                      /* Address Offset: 0x0468 */
    __IO uint32_t SOFTRST_CON27;                      /* Address Offset: 0x046C */
    __IO uint32_t SOFTRST_CON28;                      /* Address Offset: 0x0470 */
    __IO uint32_t SOFTRST_CON29;                      /* Address Offset: 0x0474 */
         uint32_t RESERVED0478[2];                    /* Address Offset: 0x0478 */
    __IO uint32_t SSGTBL0_3;                          /* Address Offset: 0x0480 */
    __IO uint32_t SSGTBL4_7;                          /* Address Offset: 0x0484 */
    __IO uint32_t SSGTBL8_11;                         /* Address Offset: 0x0488 */
    __IO uint32_t SSGTBL12_15;                        /* Address Offset: 0x048C */
    __IO uint32_t SSGTBL16_19;                        /* Address Offset: 0x0490 */
    __IO uint32_t SSGTBL20_23;                        /* Address Offset: 0x0494 */
    __IO uint32_t SSGTBL24_27;                        /* Address Offset: 0x0498 */
    __IO uint32_t SSGTBL28_31;                        /* Address Offset: 0x049C */
    __IO uint32_t SSGTBL32_35;                        /* Address Offset: 0x04A0 */
    __IO uint32_t SSGTBL36_39;                        /* Address Offset: 0x04A4 */
    __IO uint32_t SSGTBL40_43;                        /* Address Offset: 0x04A8 */
    __IO uint32_t SSGTBL44_47;                        /* Address Offset: 0x04AC */
    __IO uint32_t SSGTBL48_51;                        /* Address Offset: 0x04B0 */
    __IO uint32_t SSGTBL52_55;                        /* Address Offset: 0x04B4 */
    __IO uint32_t SSGTBL56_59;                        /* Address Offset: 0x04B8 */
    __IO uint32_t SSGTBL60_63;                        /* Address Offset: 0x04BC */
    __IO uint32_t SSGTBL64_67;                        /* Address Offset: 0x04C0 */
    __IO uint32_t SSGTBL68_71;                        /* Address Offset: 0x04C4 */
    __IO uint32_t SSGTBL72_75;                        /* Address Offset: 0x04C8 */
    __IO uint32_t SSGTBL76_79;                        /* Address Offset: 0x04CC */
    __IO uint32_t SSGTBL80_83;                        /* Address Offset: 0x04D0 */
    __IO uint32_t SSGTBL84_87;                        /* Address Offset: 0x04D4 */
    __IO uint32_t SSGTBL88_91;                        /* Address Offset: 0x04D8 */
    __IO uint32_t SSGTBL92_95;                        /* Address Offset: 0x04DC */
    __IO uint32_t SSGTBL96_99;                        /* Address Offset: 0x04E0 */
    __IO uint32_t SSGTBL100_103;                      /* Address Offset: 0x04E4 */
    __IO uint32_t SSGTBL104_107;                      /* Address Offset: 0x04E8 */
    __IO uint32_t SSGTBL108_111;                      /* Address Offset: 0x04EC */
    __IO uint32_t SSGTBL112_115;                      /* Address Offset: 0x04F0 */
    __IO uint32_t SSGTBL116_119;                      /* Address Offset: 0x04F4 */
    __IO uint32_t SSGTBL120_123;                      /* Address Offset: 0x04F8 */
    __IO uint32_t SSGTBL124_127;                      /* Address Offset: 0x04FC */
    __IO uint32_t AUTOCS_CORE_CON0;                   /* Address Offset: 0x0500 */
    __IO uint32_t AUTOCS_CORE_CON1;                   /* Address Offset: 0x0504 */
    __IO uint32_t AUTOCS_GPU_CON0;                    /* Address Offset: 0x0508 */
    __IO uint32_t AUTOCS_GPU_CON1;                    /* Address Offset: 0x050C */
    __IO uint32_t AUTOCS_BUS_CON0;                    /* Address Offset: 0x0510 */
    __IO uint32_t AUTOCS_BUS_CON1;                    /* Address Offset: 0x0514 */
    __IO uint32_t AUTOCS_TOP_CON0;                    /* Address Offset: 0x0518 */
    __IO uint32_t AUTOCS_TOP_CON1;                    /* Address Offset: 0x051C */
    __IO uint32_t AUTOCS_RKVDEC_CON0;                 /* Address Offset: 0x0520 */
    __IO uint32_t AUTOCS_RKVDEC_CON1;                 /* Address Offset: 0x0524 */
    __IO uint32_t AUTOCS_RKVENC_CON0;                 /* Address Offset: 0x0528 */
    __IO uint32_t AUTOCS_RKVENC_CON1;                 /* Address Offset: 0x052C */
    __IO uint32_t AUTOCS_VPU_CON0;                    /* Address Offset: 0x0530 */
    __IO uint32_t AUTOCS_VPU_CON1;                    /* Address Offset: 0x0534 */
    __IO uint32_t AUTOCS_PERI_CON0;                   /* Address Offset: 0x0538 */
    __IO uint32_t AUTOCS_PERI_CON1;                   /* Address Offset: 0x053C */
    __IO uint32_t AUTOCS_GPLL_CON0;                   /* Address Offset: 0x0540 */
    __IO uint32_t AUTOCS_GPLL_CON1;                   /* Address Offset: 0x0544 */
    __IO uint32_t AUTOCS_CPLL_CON0;                   /* Address Offset: 0x0548 */
    __IO uint32_t AUTOCS_CPLL_CON1;                   /* Address Offset: 0x054C */
         uint32_t RESERVED0550[12];                   /* Address Offset: 0x0550 */
    __IO uint32_t SDMMC0_CON0;                        /* Address Offset: 0x0580 */
    __IO uint32_t SDMMC0_CON1;                        /* Address Offset: 0x0584 */
    __IO uint32_t SDMMC1_CON0;                        /* Address Offset: 0x0588 */
    __IO uint32_t SDMMC1_CON1;                        /* Address Offset: 0x058C */
    __IO uint32_t SDMMC2_CON0;                        /* Address Offset: 0x0590 */
    __IO uint32_t SDMMC2_CON1;                        /* Address Offset: 0x0594 */
    __IO uint32_t EMMC_CON0;                          /* Address Offset: 0x0598 */
    __IO uint32_t EMMC_CON1;                          /* Address Offset: 0x059C */
};
/* PMU Register Structure Define */
struct PMU_REG {
    __I  uint32_t VERSION;                            /* Address Offset: 0x0000 */
    __IO uint32_t PWR_CON;                            /* Address Offset: 0x0004 */
    __I  uint32_t MAIN_PWR_STATE;                     /* Address Offset: 0x0008 */
    __IO uint32_t INT_MASK_CON;                       /* Address Offset: 0x000C */
    __IO uint32_t WAKEUP_INT_CON;                     /* Address Offset: 0x0010 */
    __I  uint32_t WAKEUP_INT_ST;                      /* Address Offset: 0x0014 */
    __IO uint32_t WAKEUP_EDGE_CON;                    /* Address Offset: 0x0018 */
    __IO uint32_t WAKEUP_EDGE_ST;                     /* Address Offset: 0x001C */
         uint32_t RESERVED0020[8];                    /* Address Offset: 0x0020 */
    __IO uint32_t BUS_IDLE_CON0;                      /* Address Offset: 0x0040 */
    __IO uint32_t BUS_IDLE_CON1;                      /* Address Offset: 0x0044 */
         uint32_t RESERVED0048[2];                    /* Address Offset: 0x0048 */
    __IO uint32_t BUS_IDLE_SFTCON0;                   /* Address Offset: 0x0050 */
    __IO uint32_t BUS_IDLE_SFTCON1;                   /* Address Offset: 0x0054 */
         uint32_t RESERVED0058[2];                    /* Address Offset: 0x0058 */
    __I  uint32_t BUS_IDLE_ACK;                       /* Address Offset: 0x0060 */
         uint32_t RESERVED0064;                       /* Address Offset: 0x0064 */
    __I  uint32_t BUS_IDLE_ST;                        /* Address Offset: 0x0068 */
         uint32_t RESERVED006C;                       /* Address Offset: 0x006C */
    __IO uint32_t NOC_AUTO_CON0;                      /* Address Offset: 0x0070 */
    __IO uint32_t NOC_AUTO_CON1;                      /* Address Offset: 0x0074 */
         uint32_t RESERVED0078[2];                    /* Address Offset: 0x0078 */
    __IO uint32_t DDR_PWR_CON;                        /* Address Offset: 0x0080 */
    __IO uint32_t DDR_PWR_SFTCON;                     /* Address Offset: 0x0084 */
    __I  uint32_t DDR_PWR_STATE;                      /* Address Offset: 0x0088 */
    __I  uint32_t DDR_PWR_ST;                         /* Address Offset: 0x008C */
    __IO uint32_t PWR_GATE_CON;                       /* Address Offset: 0x0090 */
    __I  uint32_t PWR_GATE_STATE;                     /* Address Offset: 0x0094 */
    __I  uint32_t PWR_DWN_ST;                         /* Address Offset: 0x0098 */
         uint32_t RESERVED009C;                       /* Address Offset: 0x009C */
    __IO uint32_t PWR_GATE_SFTCON;                    /* Address Offset: 0x00A0 */
         uint32_t RESERVED00A4;                       /* Address Offset: 0x00A4 */
    __IO uint32_t VOL_GATE_SFTCON;                    /* Address Offset: 0x00A8 */
         uint32_t RESERVED00AC;                       /* Address Offset: 0x00AC */
    __IO uint32_t CRU_PWR_CON;                        /* Address Offset: 0x00B0 */
    __IO uint32_t CRU_PWR_SFTCON;                     /* Address Offset: 0x00B4 */
    __I  uint32_t CRU_PWR_STATE;                      /* Address Offset: 0x00B8 */
         uint32_t RESERVED00BC;                       /* Address Offset: 0x00BC */
    __IO uint32_t PLLPD_CON;                          /* Address Offset: 0x00C0 */
    __IO uint32_t PLLPD_SFTCON;                       /* Address Offset: 0x00C4 */
         uint32_t RESERVED00C8[2];                    /* Address Offset: 0x00C8 */
    __IO uint32_t INFO_TX_CON;                        /* Address Offset: 0x00D0 */
         uint32_t RESERVED00D4[11];                   /* Address Offset: 0x00D4 */
    __IO uint32_t DSU_STABLE_CNT;                     /* Address Offset: 0x0100 */
    __IO uint32_t PMIC_STABLE_CNT;                    /* Address Offset: 0x0104 */
    __IO uint32_t OSC_STABLE_CNT;                     /* Address Offset: 0x0108 */
    __IO uint32_t WAKEUP_RSTCLR_CNT;                  /* Address Offset: 0x010C */
    __IO uint32_t PLL_LOCK_CNT;                       /* Address Offset: 0x0110 */
         uint32_t RESERVED0114;                       /* Address Offset: 0x0114 */
    __IO uint32_t DSU_PWRUP_CNT;                      /* Address Offset: 0x0118 */
    __IO uint32_t DSU_PWRDN_CNT;                      /* Address Offset: 0x011C */
    __IO uint32_t GPU_VOLUP_CNT;                      /* Address Offset: 0x0120 */
    __IO uint32_t GPU_VOLDN_CNT;                      /* Address Offset: 0x0124 */
    __IO uint32_t WAKEUP_TIMEOUT_CNT;                 /* Address Offset: 0x0128 */
    __IO uint32_t PWM_SWITCH_CNT;                     /* Address Offset: 0x012C */
    __IO uint32_t DBG_RST_CNT;                        /* Address Offset: 0x0130 */
         uint32_t RESERVED0134[19];                   /* Address Offset: 0x0134 */
    __IO uint32_t SYS_REG0;                           /* Address Offset: 0x0180 */
    __IO uint32_t SYS_REG1;                           /* Address Offset: 0x0184 */
    __IO uint32_t SYS_REG2;                           /* Address Offset: 0x0188 */
    __IO uint32_t SYS_REG3;                           /* Address Offset: 0x018C */
    __IO uint32_t SYS_REG4;                           /* Address Offset: 0x0190 */
    __IO uint32_t SYS_REG5;                           /* Address Offset: 0x0194 */
    __IO uint32_t SYS_REG6;                           /* Address Offset: 0x0198 */
    __IO uint32_t SYS_REG7;                           /* Address Offset: 0x019C */
         uint32_t RESERVED01A0[88];                   /* Address Offset: 0x01A0 */
    __IO uint32_t DSU_PWR_CON;                        /* Address Offset: 0x0300 */
    __IO uint32_t DSU_PWR_SFTCON;                     /* Address Offset: 0x0304 */
    __IO uint32_t DSU_AUTO_CON;                       /* Address Offset: 0x0308 */
    __I  uint32_t DSU_PWR_STATE;                      /* Address Offset: 0x030C */
    __IO uint32_t CPU_AUTO_PWR_CON0;                  /* Address Offset: 0x0310 */
    __IO uint32_t CPU_AUTO_PWR_CON1;                  /* Address Offset: 0x0314 */
    __IO uint32_t CPU_PWR_SFTCON;                     /* Address Offset: 0x0318 */
    __I  uint32_t CLUSTER_PWR_ST;                     /* Address Offset: 0x031C */
    __IO uint32_t CLUSTER_IDLE_CON;                   /* Address Offset: 0x0320 */
    __IO uint32_t CLUSTER_IDLE_SFTCON;                /* Address Offset: 0x0324 */
    __I  uint32_t CLUSTER_IDLE_ACK;                   /* Address Offset: 0x0328 */
    __I  uint32_t CLUSTER_IDLE_ST;                    /* Address Offset: 0x032C */
    __IO uint32_t DBG_PWR_CON;                        /* Address Offset: 0x0330 */
};
/* TIMER Register Structure Define */
struct TIMER_REG {
    __IO uint32_t LOAD_COUNT[2];                      /* Address Offset: 0x0000 */
    __I  uint32_t CURRENT_VALUE[2];                   /* Address Offset: 0x0008 */
    __IO uint32_t CONTROLREG;                         /* Address Offset: 0x0010 */
         uint32_t RESERVED0014;                       /* Address Offset: 0x0014 */
    __IO uint32_t INTSTATUS;                          /* Address Offset: 0x0018 */
};
/* UART Register Structure Define */
struct UART_REG {
    union {
        __I  uint32_t RBR;                                /* Address Offset: 0x0000 */
        __IO uint32_t DLL;                                /* Address Offset: 0x0000 */
        __O  uint32_t THR;                                /* Address Offset: 0x0000 */
    };
    union {
        __IO uint32_t DLH;                                /* Address Offset: 0x0004 */
        __IO uint32_t IER;                                /* Address Offset: 0x0004 */
    };
    union {
        __O  uint32_t FCR;                                /* Address Offset: 0x0008 */
        __I  uint32_t IIR;                                /* Address Offset: 0x0008 */
    };
    __IO uint32_t LCR;                                /* Address Offset: 0x000C */
    __IO uint32_t MCR;                                /* Address Offset: 0x0010 */
    __I  uint32_t LSR;                                /* Address Offset: 0x0014 */
    __I  uint32_t MSR;                                /* Address Offset: 0x0018 */
    __IO uint32_t SCR;                                /* Address Offset: 0x001C */
         uint32_t RESERVED0020[4];                    /* Address Offset: 0x0020 */
    union {
        __I  uint32_t SRBR;                               /* Address Offset: 0x0030 */
        __O  uint32_t STHR;                               /* Address Offset: 0x0030 */
    };
         uint32_t RESERVED0034[15];                   /* Address Offset: 0x0034 */
    __IO uint32_t FAR;                                /* Address Offset: 0x0070 */
    __I  uint32_t TFR;                                /* Address Offset: 0x0074 */
    __O  uint32_t RFW;                                /* Address Offset: 0x0078 */
    __I  uint32_t USR;                                /* Address Offset: 0x007C */
    __I  uint32_t TFL;                                /* Address Offset: 0x0080 */
    __I  uint32_t RFL;                                /* Address Offset: 0x0084 */
    __O  uint32_t SRR;                                /* Address Offset: 0x0088 */
    __IO uint32_t SRTS;                               /* Address Offset: 0x008C */
    __IO uint32_t SBCR;                               /* Address Offset: 0x0090 */
    __IO uint32_t SDMAM;                              /* Address Offset: 0x0094 */
    __IO uint32_t SFE;                                /* Address Offset: 0x0098 */
    __IO uint32_t SRT;                                /* Address Offset: 0x009C */
    __IO uint32_t STET;                               /* Address Offset: 0x00A0 */
    __IO uint32_t HTX;                                /* Address Offset: 0x00A4 */
    __O  uint32_t DMASA;                              /* Address Offset: 0x00A8 */
         uint32_t RESERVED00AC[18];                   /* Address Offset: 0x00AC */
    __I  uint32_t CPR;                                /* Address Offset: 0x00F4 */
    __I  uint32_t UCV;                                /* Address Offset: 0x00F8 */
    __I  uint32_t CTR;                                /* Address Offset: 0x00FC */
};
#endif /*  __ASSEMBLY__  */
/****************************************************************************************/
/*                                                                                      */
/*                                Module Address Section                                */
/*                                                                                      */
/****************************************************************************************/
/* Memory Base */
#define PMU_GRF_BASE        0xFDC20000U /* PMU_GRF base address */
#define PMUCRU_BASE         0xFDD00000U /* PMUCRU base address */
#define CRU_BASE            0xFDD10000U /* CRU base address */
#define PMU_BASE            0xFDD90000U /* PMU base address */
#define PMU_NS_BASE         0xFDD90000U /* PMU_NS base address */
#define TIMER0_BASE         0xFE5F0000U /* TIMER0 base address */
#define TIMER1_BASE         0xFE5F0020U /* TIMER1 base address */
#define TIMER2_BASE         0xFE5F0040U /* TIMER2 base address */
#define TIMER3_BASE         0xFE5F0060U /* TIMER3 base address */
#define TIMER4_BASE         0xFE5F0080U /* TIMER4 base address */
#define TIMER5_BASE         0xFE5F00A0U /* TIMER5 base address */
#define UART2_BASE          0xFE660000U /* UART2 base address */
/****************************************************************************************/
/*                                                                                      */
/*                               Module Variable Section                                */
/*                                                                                      */
/****************************************************************************************/
/* Module Variable Define */

#define PMU_GRF             ((struct PMU_GRF_REG *) PMU_GRF_BASE)
#define PMUCRU              ((struct PMUCRU_REG *) PMUCRU_BASE)
#define CRU                 ((struct CRU_REG *) CRU_BASE)
#define PMU                 ((struct PMU_REG *) PMU_BASE)
#define PMU_NS              ((struct PMU_NS_REG *) PMU_NS_BASE)
#define TIMER0              ((struct TIMER_REG *) TIMER0_BASE)
#define TIMER1              ((struct TIMER_REG *) TIMER1_BASE)
#define TIMER2              ((struct TIMER_REG *) TIMER2_BASE)
#define TIMER3              ((struct TIMER_REG *) TIMER3_BASE)
#define TIMER4              ((struct TIMER_REG *) TIMER4_BASE)
#define TIMER5              ((struct TIMER_REG *) TIMER5_BASE)
#define UART2               ((struct UART_REG *) UART2_BASE)

#define IS_PMU_GRF_INSTANCE(instance) ((instance) == PMU_GRF)
#define IS_PMUCRU_INSTANCE(instance) ((instance) == PMUCRU)
#define IS_CRU_INSTANCE(instance) ((instance) == CRU)
#define IS_PMU_INSTANCE(instance) ((instance) == PMU)
#define IS_PMU_NS_INSTANCE(instance) ((instance) == PMU_NS)
#define IS_TIMER_INSTANCE(instance) (((instance) == TIMER0) || ((instance) == TIMER1) || ((instance) == TIMER2) || ((instance) == TIMER3) || ((instance) == TIMER4) || ((instance) == TIMER5))
#define IS_UART_INSTANCE(instance) ((instance) == UART2)
/****************************************************************************************/
/*                                                                                      */
/*                               Register Bitmap Section                                */
/*                                                                                      */
/****************************************************************************************/
/****************************************PMU_GRF*****************************************/
/* GPIO0A_IOMUX_L */
#define PMU_GRF_GPIO0A_IOMUX_L_OFFSET                      (0x0U)
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A0_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A0_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_L_GPIO0A0_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A1_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A1_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_L_GPIO0A1_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A2_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A2_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_L_GPIO0A2_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A3_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0A_IOMUX_L_GPIO0A3_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_L_GPIO0A3_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0A_IOMUX_H */
#define PMU_GRF_GPIO0A_IOMUX_H_OFFSET                      (0x4U)
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A4_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A4_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_H_GPIO0A4_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A5_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A5_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_H_GPIO0A5_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A6_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A6_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_H_GPIO0A6_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A7_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0A_IOMUX_H_GPIO0A7_SEL_MASK            (0x7U << PMU_GRF_GPIO0A_IOMUX_H_GPIO0A7_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0B_IOMUX_L */
#define PMU_GRF_GPIO0B_IOMUX_L_OFFSET                      (0x8U)
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B0_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B0_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_L_GPIO0B0_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B1_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B1_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_L_GPIO0B1_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B2_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B2_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_L_GPIO0B2_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B3_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0B_IOMUX_L_GPIO0B3_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_L_GPIO0B3_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0B_IOMUX_H */
#define PMU_GRF_GPIO0B_IOMUX_H_OFFSET                      (0xCU)
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B4_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B4_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_H_GPIO0B4_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B5_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B5_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_H_GPIO0B5_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B6_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B6_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_H_GPIO0B6_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B7_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0B_IOMUX_H_GPIO0B7_SEL_MASK            (0x7U << PMU_GRF_GPIO0B_IOMUX_H_GPIO0B7_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0C_IOMUX_L */
#define PMU_GRF_GPIO0C_IOMUX_L_OFFSET                      (0x10U)
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C0_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C0_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_L_GPIO0C0_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C1_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C1_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_L_GPIO0C1_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C2_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C2_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_L_GPIO0C2_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C3_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0C_IOMUX_L_GPIO0C3_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_L_GPIO0C3_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0C_IOMUX_H */
#define PMU_GRF_GPIO0C_IOMUX_H_OFFSET                      (0x14U)
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C4_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C4_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_H_GPIO0C4_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C5_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C5_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_H_GPIO0C5_SEL_SHIFT)           /* 0x00000070 */
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C6_SEL_SHIFT           (8U)
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C6_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_H_GPIO0C6_SEL_SHIFT)           /* 0x00000700 */
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C7_SEL_SHIFT           (12U)
#define PMU_GRF_GPIO0C_IOMUX_H_GPIO0C7_SEL_MASK            (0x7U << PMU_GRF_GPIO0C_IOMUX_H_GPIO0C7_SEL_SHIFT)           /* 0x00007000 */
/* GPIO0D_IOMUX_L */
#define PMU_GRF_GPIO0D_IOMUX_L_OFFSET                      (0x18U)
#define PMU_GRF_GPIO0D_IOMUX_L_GPIO0D0_SEL_SHIFT           (0U)
#define PMU_GRF_GPIO0D_IOMUX_L_GPIO0D0_SEL_MASK            (0x7U << PMU_GRF_GPIO0D_IOMUX_L_GPIO0D0_SEL_SHIFT)           /* 0x00000007 */
#define PMU_GRF_GPIO0D_IOMUX_L_GPIO0D1_SEL_SHIFT           (4U)
#define PMU_GRF_GPIO0D_IOMUX_L_GPIO0D1_SEL_MASK            (0x7U << PMU_GRF_GPIO0D_IOMUX_L_GPIO0D1_SEL_SHIFT)           /* 0x00000070 */
/* GPIO0A_P */
#define PMU_GRF_GPIO0A_P_OFFSET                            (0x20U)
#define PMU_GRF_GPIO0A_P_GPIO0A0_P_SHIFT                   (0U)
#define PMU_GRF_GPIO0A_P_GPIO0A0_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A0_P_SHIFT)                   /* 0x00000003 */
#define PMU_GRF_GPIO0A_P_GPIO0A1_P_SHIFT                   (2U)
#define PMU_GRF_GPIO0A_P_GPIO0A1_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A1_P_SHIFT)                   /* 0x0000000C */
#define PMU_GRF_GPIO0A_P_GPIO0A2_P_SHIFT                   (4U)
#define PMU_GRF_GPIO0A_P_GPIO0A2_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A2_P_SHIFT)                   /* 0x00000030 */
#define PMU_GRF_GPIO0A_P_GPIO0A3_P_SHIFT                   (6U)
#define PMU_GRF_GPIO0A_P_GPIO0A3_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A3_P_SHIFT)                   /* 0x000000C0 */
#define PMU_GRF_GPIO0A_P_GPIO0A4_P_SHIFT                   (8U)
#define PMU_GRF_GPIO0A_P_GPIO0A4_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A4_P_SHIFT)                   /* 0x00000300 */
#define PMU_GRF_GPIO0A_P_GPIO0A5_P_SHIFT                   (10U)
#define PMU_GRF_GPIO0A_P_GPIO0A5_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A5_P_SHIFT)                   /* 0x00000C00 */
#define PMU_GRF_GPIO0A_P_GPIO0A6_P_SHIFT                   (12U)
#define PMU_GRF_GPIO0A_P_GPIO0A6_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A6_P_SHIFT)                   /* 0x00003000 */
#define PMU_GRF_GPIO0A_P_GPIO0A7_P_SHIFT                   (14U)
#define PMU_GRF_GPIO0A_P_GPIO0A7_P_MASK                    (0x3U << PMU_GRF_GPIO0A_P_GPIO0A7_P_SHIFT)                   /* 0x0000C000 */
/* GPIO0B_P */
#define PMU_GRF_GPIO0B_P_OFFSET                            (0x24U)
#define PMU_GRF_GPIO0B_P_GPIO0B0_P_SHIFT                   (0U)
#define PMU_GRF_GPIO0B_P_GPIO0B0_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B0_P_SHIFT)                   /* 0x00000003 */
#define PMU_GRF_GPIO0B_P_GPIO0B1_P_SHIFT                   (2U)
#define PMU_GRF_GPIO0B_P_GPIO0B1_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B1_P_SHIFT)                   /* 0x0000000C */
#define PMU_GRF_GPIO0B_P_GPIO0B2_P_SHIFT                   (4U)
#define PMU_GRF_GPIO0B_P_GPIO0B2_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B2_P_SHIFT)                   /* 0x00000030 */
#define PMU_GRF_GPIO0B_P_GPIO0B3_P_SHIFT                   (6U)
#define PMU_GRF_GPIO0B_P_GPIO0B3_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B3_P_SHIFT)                   /* 0x000000C0 */
#define PMU_GRF_GPIO0B_P_GPIO0B4_P_SHIFT                   (8U)
#define PMU_GRF_GPIO0B_P_GPIO0B4_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B4_P_SHIFT)                   /* 0x00000300 */
#define PMU_GRF_GPIO0B_P_GPIO0B5_P_SHIFT                   (10U)
#define PMU_GRF_GPIO0B_P_GPIO0B5_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B5_P_SHIFT)                   /* 0x00000C00 */
#define PMU_GRF_GPIO0B_P_GPIO0B6_P_SHIFT                   (12U)
#define PMU_GRF_GPIO0B_P_GPIO0B6_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B6_P_SHIFT)                   /* 0x00003000 */
#define PMU_GRF_GPIO0B_P_GPIO0B7_P_SHIFT                   (14U)
#define PMU_GRF_GPIO0B_P_GPIO0B7_P_MASK                    (0x3U << PMU_GRF_GPIO0B_P_GPIO0B7_P_SHIFT)                   /* 0x0000C000 */
/* GPIO0C_P */
#define PMU_GRF_GPIO0C_P_OFFSET                            (0x28U)
#define PMU_GRF_GPIO0C_P_GPIO0C0_P_SHIFT                   (0U)
#define PMU_GRF_GPIO0C_P_GPIO0C0_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C0_P_SHIFT)                   /* 0x00000003 */
#define PMU_GRF_GPIO0C_P_GPIO0C1_P_SHIFT                   (2U)
#define PMU_GRF_GPIO0C_P_GPIO0C1_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C1_P_SHIFT)                   /* 0x0000000C */
#define PMU_GRF_GPIO0C_P_GPIO0C2_P_SHIFT                   (4U)
#define PMU_GRF_GPIO0C_P_GPIO0C2_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C2_P_SHIFT)                   /* 0x00000030 */
#define PMU_GRF_GPIO0C_P_GPIO0C3_P_SHIFT                   (6U)
#define PMU_GRF_GPIO0C_P_GPIO0C3_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C3_P_SHIFT)                   /* 0x000000C0 */
#define PMU_GRF_GPIO0C_P_GPIO0C4_P_SHIFT                   (8U)
#define PMU_GRF_GPIO0C_P_GPIO0C4_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C4_P_SHIFT)                   /* 0x00000300 */
#define PMU_GRF_GPIO0C_P_GPIO0C5_P_SHIFT                   (10U)
#define PMU_GRF_GPIO0C_P_GPIO0C5_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C5_P_SHIFT)                   /* 0x00000C00 */
#define PMU_GRF_GPIO0C_P_GPIO0C6_P_SHIFT                   (12U)
#define PMU_GRF_GPIO0C_P_GPIO0C6_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C6_P_SHIFT)                   /* 0x00003000 */
#define PMU_GRF_GPIO0C_P_GPIO0C7_P_SHIFT                   (14U)
#define PMU_GRF_GPIO0C_P_GPIO0C7_P_MASK                    (0x3U << PMU_GRF_GPIO0C_P_GPIO0C7_P_SHIFT)                   /* 0x0000C000 */
/* GPIO0D_P */
#define PMU_GRF_GPIO0D_P_OFFSET                            (0x2CU)
#define PMU_GRF_GPIO0D_P_GPIO0D0_P_SHIFT                   (0U)
#define PMU_GRF_GPIO0D_P_GPIO0D0_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D0_P_SHIFT)                   /* 0x00000003 */
#define PMU_GRF_GPIO0D_P_GPIO0D1_P_SHIFT                   (2U)
#define PMU_GRF_GPIO0D_P_GPIO0D1_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D1_P_SHIFT)                   /* 0x0000000C */
#define PMU_GRF_GPIO0D_P_GPIO0D2_P_SHIFT                   (4U)
#define PMU_GRF_GPIO0D_P_GPIO0D2_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D2_P_SHIFT)                   /* 0x00000030 */
#define PMU_GRF_GPIO0D_P_GPIO0D3_P_SHIFT                   (6U)
#define PMU_GRF_GPIO0D_P_GPIO0D3_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D3_P_SHIFT)                   /* 0x000000C0 */
#define PMU_GRF_GPIO0D_P_GPIO0D4_P_SHIFT                   (8U)
#define PMU_GRF_GPIO0D_P_GPIO0D4_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D4_P_SHIFT)                   /* 0x00000300 */
#define PMU_GRF_GPIO0D_P_GPIO0D5_P_SHIFT                   (10U)
#define PMU_GRF_GPIO0D_P_GPIO0D5_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D5_P_SHIFT)                   /* 0x00000C00 */
#define PMU_GRF_GPIO0D_P_GPIO0D6_P_SHIFT                   (12U)
#define PMU_GRF_GPIO0D_P_GPIO0D6_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D6_P_SHIFT)                   /* 0x00003000 */
#define PMU_GRF_GPIO0D_P_GPIO0D7_P_SHIFT                   (14U)
#define PMU_GRF_GPIO0D_P_GPIO0D7_P_MASK                    (0x3U << PMU_GRF_GPIO0D_P_GPIO0D7_P_SHIFT)                   /* 0x0000C000 */
/* GPIO0A_IE */
#define PMU_GRF_GPIO0A_IE_OFFSET                           (0x30U)
#define PMU_GRF_GPIO0A_IE_GPIO0A0_IE_SHIFT                 (0U)
#define PMU_GRF_GPIO0A_IE_GPIO0A0_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A0_IE_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0A_IE_GPIO0A1_IE_SHIFT                 (2U)
#define PMU_GRF_GPIO0A_IE_GPIO0A1_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A1_IE_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0A_IE_GPIO0A2_IE_SHIFT                 (4U)
#define PMU_GRF_GPIO0A_IE_GPIO0A2_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A2_IE_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0A_IE_GPIO0A3_IE_SHIFT                 (6U)
#define PMU_GRF_GPIO0A_IE_GPIO0A3_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A3_IE_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0A_IE_GPIO0A4_IE_SHIFT                 (8U)
#define PMU_GRF_GPIO0A_IE_GPIO0A4_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A4_IE_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0A_IE_GPIO0A5_IE_SHIFT                 (10U)
#define PMU_GRF_GPIO0A_IE_GPIO0A5_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A5_IE_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0A_IE_GPIO0A6_IE_SHIFT                 (12U)
#define PMU_GRF_GPIO0A_IE_GPIO0A6_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A6_IE_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0A_IE_GPIO0A7_IE_SHIFT                 (14U)
#define PMU_GRF_GPIO0A_IE_GPIO0A7_IE_MASK                  (0x3U << PMU_GRF_GPIO0A_IE_GPIO0A7_IE_SHIFT)                 /* 0x0000C000 */
/* GPIO0B_IE */
#define PMU_GRF_GPIO0B_IE_OFFSET                           (0x34U)
#define PMU_GRF_GPIO0B_IE_GPIO0B0_IE_SHIFT                 (0U)
#define PMU_GRF_GPIO0B_IE_GPIO0B0_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B0_IE_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0B_IE_GPIO0B1_IE_SHIFT                 (2U)
#define PMU_GRF_GPIO0B_IE_GPIO0B1_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B1_IE_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0B_IE_GPIO0B2_IE_SHIFT                 (4U)
#define PMU_GRF_GPIO0B_IE_GPIO0B2_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B2_IE_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0B_IE_GPIO0B3_IE_SHIFT                 (6U)
#define PMU_GRF_GPIO0B_IE_GPIO0B3_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B3_IE_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0B_IE_GPIO0B4_IE_SHIFT                 (8U)
#define PMU_GRF_GPIO0B_IE_GPIO0B4_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B4_IE_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0B_IE_GPIO0B5_IE_SHIFT                 (10U)
#define PMU_GRF_GPIO0B_IE_GPIO0B5_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B5_IE_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0B_IE_GPIO0B6_IE_SHIFT                 (12U)
#define PMU_GRF_GPIO0B_IE_GPIO0B6_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B6_IE_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0B_IE_GPIO0B7_IE_SHIFT                 (14U)
#define PMU_GRF_GPIO0B_IE_GPIO0B7_IE_MASK                  (0x3U << PMU_GRF_GPIO0B_IE_GPIO0B7_IE_SHIFT)                 /* 0x0000C000 */
/* GPIO0C_IE */
#define PMU_GRF_GPIO0C_IE_OFFSET                           (0x38U)
#define PMU_GRF_GPIO0C_IE_GPIO0C0_IE_SHIFT                 (0U)
#define PMU_GRF_GPIO0C_IE_GPIO0C0_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C0_IE_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0C_IE_GPIO0C1_IE_SHIFT                 (2U)
#define PMU_GRF_GPIO0C_IE_GPIO0C1_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C1_IE_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0C_IE_GPIO0C2_IE_SHIFT                 (4U)
#define PMU_GRF_GPIO0C_IE_GPIO0C2_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C2_IE_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0C_IE_GPIO0C3_IE_SHIFT                 (6U)
#define PMU_GRF_GPIO0C_IE_GPIO0C3_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C3_IE_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0C_IE_GPIO0C4_IE_SHIFT                 (8U)
#define PMU_GRF_GPIO0C_IE_GPIO0C4_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C4_IE_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0C_IE_GPIO0C5_IE_SHIFT                 (10U)
#define PMU_GRF_GPIO0C_IE_GPIO0C5_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C5_IE_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0C_IE_GPIO0C6_IE_SHIFT                 (12U)
#define PMU_GRF_GPIO0C_IE_GPIO0C6_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C6_IE_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0C_IE_GPIO0C7_IE_SHIFT                 (14U)
#define PMU_GRF_GPIO0C_IE_GPIO0C7_IE_MASK                  (0x3U << PMU_GRF_GPIO0C_IE_GPIO0C7_IE_SHIFT)                 /* 0x0000C000 */
/* GPIO0D_IE */
#define PMU_GRF_GPIO0D_IE_OFFSET                           (0x3CU)
#define PMU_GRF_GPIO0D_IE_GPIO0D0_IE_SHIFT                 (0U)
#define PMU_GRF_GPIO0D_IE_GPIO0D0_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D0_IE_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0D_IE_GPIO0D1_IE_SHIFT                 (2U)
#define PMU_GRF_GPIO0D_IE_GPIO0D1_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D1_IE_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0D_IE_GPIO0D2_IE_SHIFT                 (4U)
#define PMU_GRF_GPIO0D_IE_GPIO0D2_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D2_IE_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0D_IE_GPIO0D3_IE_SHIFT                 (6U)
#define PMU_GRF_GPIO0D_IE_GPIO0D3_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D3_IE_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0D_IE_GPIO0D4_IE_SHIFT                 (8U)
#define PMU_GRF_GPIO0D_IE_GPIO0D4_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D4_IE_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0D_IE_GPIO0D5_IE_SHIFT                 (10U)
#define PMU_GRF_GPIO0D_IE_GPIO0D5_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D5_IE_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0D_IE_GPIO0D6_IE_SHIFT                 (12U)
#define PMU_GRF_GPIO0D_IE_GPIO0D6_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D6_IE_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0D_IE_GPIO0D7_IE_SHIFT                 (14U)
#define PMU_GRF_GPIO0D_IE_GPIO0D7_IE_MASK                  (0x3U << PMU_GRF_GPIO0D_IE_GPIO0D7_IE_SHIFT)                 /* 0x0000C000 */
/* GPIO0A_OPD */
#define PMU_GRF_GPIO0A_OPD_OFFSET                          (0x40U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A0_OPD_SHIFT               (0U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A0_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A0_OPD_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A1_OPD_SHIFT               (1U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A1_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A1_OPD_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A2_OPD_SHIFT               (2U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A2_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A2_OPD_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A3_OPD_SHIFT               (3U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A3_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A3_OPD_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A4_OPD_SHIFT               (4U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A4_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A4_OPD_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A5_OPD_SHIFT               (5U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A5_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A5_OPD_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A6_OPD_SHIFT               (6U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A6_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A6_OPD_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0A_OPD_GPIO0A7_OPD_SHIFT               (7U)
#define PMU_GRF_GPIO0A_OPD_GPIO0A7_OPD_MASK                (0x1U << PMU_GRF_GPIO0A_OPD_GPIO0A7_OPD_SHIFT)               /* 0x00000080 */
/* GPIO0B_OPD */
#define PMU_GRF_GPIO0B_OPD_OFFSET                          (0x44U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B0_OPD_SHIFT               (0U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B0_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B0_OPD_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B1_OPD_SHIFT               (1U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B1_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B1_OPD_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B2_OPD_SHIFT               (2U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B2_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B2_OPD_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B3_OPD_SHIFT               (3U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B3_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B3_OPD_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B4_OPD_SHIFT               (4U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B4_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B4_OPD_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B5_OPD_SHIFT               (5U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B5_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B5_OPD_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B6_OPD_SHIFT               (6U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B6_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B6_OPD_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0B_OPD_GPIO0B7_OPD_SHIFT               (7U)
#define PMU_GRF_GPIO0B_OPD_GPIO0B7_OPD_MASK                (0x1U << PMU_GRF_GPIO0B_OPD_GPIO0B7_OPD_SHIFT)               /* 0x00000080 */
/* GPIO0C_OPD */
#define PMU_GRF_GPIO0C_OPD_OFFSET                          (0x48U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C0_OPD_SHIFT               (0U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C0_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C0_OPD_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C1_OPD_SHIFT               (1U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C1_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C1_OPD_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C2_OPD_SHIFT               (2U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C2_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C2_OPD_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C3_OPD_SHIFT               (3U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C3_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C3_OPD_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C4_OPD_SHIFT               (4U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C4_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C4_OPD_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C5_OPD_SHIFT               (5U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C5_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C5_OPD_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C6_OPD_SHIFT               (6U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C6_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C6_OPD_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0C_OPD_GPIO0C7_OPD_SHIFT               (7U)
#define PMU_GRF_GPIO0C_OPD_GPIO0C7_OPD_MASK                (0x1U << PMU_GRF_GPIO0C_OPD_GPIO0C7_OPD_SHIFT)               /* 0x00000080 */
/* GPIO0D_OPD */
#define PMU_GRF_GPIO0D_OPD_OFFSET                          (0x4CU)
#define PMU_GRF_GPIO0D_OPD_GPIO0A0_OPD_SHIFT               (0U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A0_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A0_OPD_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A1_OPD_SHIFT               (1U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A1_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A1_OPD_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A2_OPD_SHIFT               (2U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A2_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A2_OPD_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A3_OPD_SHIFT               (3U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A3_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A3_OPD_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A4_OPD_SHIFT               (4U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A4_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A4_OPD_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A5_OPD_SHIFT               (5U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A5_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A5_OPD_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A6_OPD_SHIFT               (6U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A6_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A6_OPD_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0D_OPD_GPIO0A7_OPD_SHIFT               (7U)
#define PMU_GRF_GPIO0D_OPD_GPIO0A7_OPD_MASK                (0x1U << PMU_GRF_GPIO0D_OPD_GPIO0A7_OPD_SHIFT)               /* 0x00000080 */
/* GPIO0A_SUS */
#define PMU_GRF_GPIO0A_SUS_OFFSET                          (0x50U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A0_SUS_SHIFT               (0U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A0_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A0_SUS_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A1_SUS_SHIFT               (1U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A1_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A1_SUS_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A2_SUS_SHIFT               (2U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A2_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A2_SUS_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A3_SUS_SHIFT               (3U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A3_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A3_SUS_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A4_SUS_SHIFT               (4U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A4_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A4_SUS_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A5_SUS_SHIFT               (5U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A5_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A5_SUS_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A6_SUS_SHIFT               (6U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A6_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A6_SUS_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0A_SUS_GPIO0A7_SUS_SHIFT               (7U)
#define PMU_GRF_GPIO0A_SUS_GPIO0A7_SUS_MASK                (0x1U << PMU_GRF_GPIO0A_SUS_GPIO0A7_SUS_SHIFT)               /* 0x00000080 */
/* GPIO0B_SUS */
#define PMU_GRF_GPIO0B_SUS_OFFSET                          (0x54U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B0_SUS_SHIFT               (0U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B0_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B0_SUS_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B1_SUS_SHIFT               (1U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B1_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B1_SUS_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B2_SUS_SHIFT               (2U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B2_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B2_SUS_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B3_SUS_SHIFT               (3U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B3_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B3_SUS_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B4_SUS_SHIFT               (4U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B4_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B4_SUS_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B5_SUS_SHIFT               (5U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B5_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B5_SUS_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B6_SUS_SHIFT               (6U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B6_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B6_SUS_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0B_SUS_GPIO0B7_SUS_SHIFT               (7U)
#define PMU_GRF_GPIO0B_SUS_GPIO0B7_SUS_MASK                (0x1U << PMU_GRF_GPIO0B_SUS_GPIO0B7_SUS_SHIFT)               /* 0x00000080 */
/* GPIO0C_SUS */
#define PMU_GRF_GPIO0C_SUS_OFFSET                          (0x58U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C0_SUS_SHIFT               (0U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C0_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C0_SUS_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C1_SUS_SHIFT               (1U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C1_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C1_SUS_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C2_SUS_SHIFT               (2U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C2_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C2_SUS_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C3_SUS_SHIFT               (3U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C3_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C3_SUS_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C4_SUS_SHIFT               (4U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C4_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C4_SUS_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C5_SUS_SHIFT               (5U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C5_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C5_SUS_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C6_SUS_SHIFT               (6U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C6_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C6_SUS_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0C_SUS_GPIO0C7_SUS_SHIFT               (7U)
#define PMU_GRF_GPIO0C_SUS_GPIO0C7_SUS_MASK                (0x1U << PMU_GRF_GPIO0C_SUS_GPIO0C7_SUS_SHIFT)               /* 0x00000080 */
/* GPIO0D_SUS */
#define PMU_GRF_GPIO0D_SUS_OFFSET                          (0x5CU)
#define PMU_GRF_GPIO0D_SUS_GPIO0D0_SUS_SHIFT               (0U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D0_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D0_SUS_SHIFT)               /* 0x00000001 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D1_SUS_SHIFT               (1U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D1_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D1_SUS_SHIFT)               /* 0x00000002 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D2_SUS_SHIFT               (2U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D2_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D2_SUS_SHIFT)               /* 0x00000004 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D3_SUS_SHIFT               (3U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D3_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D3_SUS_SHIFT)               /* 0x00000008 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D4_SUS_SHIFT               (4U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D4_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D4_SUS_SHIFT)               /* 0x00000010 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D5_SUS_SHIFT               (5U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D5_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D5_SUS_SHIFT)               /* 0x00000020 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D6_SUS_SHIFT               (6U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D6_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D6_SUS_SHIFT)               /* 0x00000040 */
#define PMU_GRF_GPIO0D_SUS_GPIO0D7_SUS_SHIFT               (7U)
#define PMU_GRF_GPIO0D_SUS_GPIO0D7_SUS_MASK                (0x1U << PMU_GRF_GPIO0D_SUS_GPIO0D7_SUS_SHIFT)               /* 0x00000080 */
/* GPIO0A_SL */
#define PMU_GRF_GPIO0A_SL_OFFSET                           (0x60U)
#define PMU_GRF_GPIO0A_SL_GPIO0A0_SL_SHIFT                 (0U)
#define PMU_GRF_GPIO0A_SL_GPIO0A0_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A0_SL_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0A_SL_GPIO0A1_SL_SHIFT                 (2U)
#define PMU_GRF_GPIO0A_SL_GPIO0A1_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A1_SL_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0A_SL_GPIO0A2_SL_SHIFT                 (4U)
#define PMU_GRF_GPIO0A_SL_GPIO0A2_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A2_SL_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0A_SL_GPIO0A3_SL_SHIFT                 (6U)
#define PMU_GRF_GPIO0A_SL_GPIO0A3_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A3_SL_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0A_SL_GPIO0A4_SL_SHIFT                 (8U)
#define PMU_GRF_GPIO0A_SL_GPIO0A4_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A4_SL_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0A_SL_GPIO0A5_SL_SHIFT                 (10U)
#define PMU_GRF_GPIO0A_SL_GPIO0A5_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A5_SL_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0A_SL_GPIO0A6_SL_SHIFT                 (12U)
#define PMU_GRF_GPIO0A_SL_GPIO0A6_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A6_SL_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0A_SL_GPIO0A7_SL_SHIFT                 (14U)
#define PMU_GRF_GPIO0A_SL_GPIO0A7_SL_MASK                  (0x3U << PMU_GRF_GPIO0A_SL_GPIO0A7_SL_SHIFT)                 /* 0x0000C000 */
/* GPIO0B_SL */
#define PMU_GRF_GPIO0B_SL_OFFSET                           (0x64U)
#define PMU_GRF_GPIO0B_SL_GPIO0B0_SL_SHIFT                 (0U)
#define PMU_GRF_GPIO0B_SL_GPIO0B0_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B0_SL_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0B_SL_GPIO0B1_SL_SHIFT                 (2U)
#define PMU_GRF_GPIO0B_SL_GPIO0B1_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B1_SL_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0B_SL_GPIO0B2_SL_SHIFT                 (4U)
#define PMU_GRF_GPIO0B_SL_GPIO0B2_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B2_SL_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0B_SL_GPIO0B3_SL_SHIFT                 (6U)
#define PMU_GRF_GPIO0B_SL_GPIO0B3_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B3_SL_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0B_SL_GPIO0B4_SL_SHIFT                 (8U)
#define PMU_GRF_GPIO0B_SL_GPIO0B4_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B4_SL_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0B_SL_GPIO0B5_SL_SHIFT                 (10U)
#define PMU_GRF_GPIO0B_SL_GPIO0B5_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B5_SL_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0B_SL_GPIO0B6_SL_SHIFT                 (12U)
#define PMU_GRF_GPIO0B_SL_GPIO0B6_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B6_SL_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0B_SL_GPIO0B7_SL_SHIFT                 (14U)
#define PMU_GRF_GPIO0B_SL_GPIO0B7_SL_MASK                  (0x3U << PMU_GRF_GPIO0B_SL_GPIO0B7_SL_SHIFT)                 /* 0x0000C000 */
/* GPIO0C_SL */
#define PMU_GRF_GPIO0C_SL_OFFSET                           (0x68U)
#define PMU_GRF_GPIO0C_SL_GPIO0C0_SL_SHIFT                 (0U)
#define PMU_GRF_GPIO0C_SL_GPIO0C0_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C0_SL_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0C_SL_GPIO0C1_SL_SHIFT                 (2U)
#define PMU_GRF_GPIO0C_SL_GPIO0C1_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C1_SL_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0C_SL_GPIO0C2_SL_SHIFT                 (4U)
#define PMU_GRF_GPIO0C_SL_GPIO0C2_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C2_SL_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0C_SL_GPIO0C3_SL_SHIFT                 (6U)
#define PMU_GRF_GPIO0C_SL_GPIO0C3_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C3_SL_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0C_SL_GPIO0C4_SL_SHIFT                 (8U)
#define PMU_GRF_GPIO0C_SL_GPIO0C4_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C4_SL_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0C_SL_GPIO0C5_SL_SHIFT                 (10U)
#define PMU_GRF_GPIO0C_SL_GPIO0C5_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C5_SL_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0C_SL_GPIO0C6_SL_SHIFT                 (12U)
#define PMU_GRF_GPIO0C_SL_GPIO0C6_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C6_SL_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0C_SL_GPIO0C7_SL_SHIFT                 (14U)
#define PMU_GRF_GPIO0C_SL_GPIO0C7_SL_MASK                  (0x3U << PMU_GRF_GPIO0C_SL_GPIO0C7_SL_SHIFT)                 /* 0x0000C000 */
/* GPIO0D_SL */
#define PMU_GRF_GPIO0D_SL_OFFSET                           (0x6CU)
#define PMU_GRF_GPIO0D_SL_GPIO0D0_SL_SHIFT                 (0U)
#define PMU_GRF_GPIO0D_SL_GPIO0D0_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D0_SL_SHIFT)                 /* 0x00000003 */
#define PMU_GRF_GPIO0D_SL_GPIO0D1_SL_SHIFT                 (2U)
#define PMU_GRF_GPIO0D_SL_GPIO0D1_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D1_SL_SHIFT)                 /* 0x0000000C */
#define PMU_GRF_GPIO0D_SL_GPIO0D2_SL_SHIFT                 (4U)
#define PMU_GRF_GPIO0D_SL_GPIO0D2_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D2_SL_SHIFT)                 /* 0x00000030 */
#define PMU_GRF_GPIO0D_SL_GPIO0D3_SL_SHIFT                 (6U)
#define PMU_GRF_GPIO0D_SL_GPIO0D3_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D3_SL_SHIFT)                 /* 0x000000C0 */
#define PMU_GRF_GPIO0D_SL_GPIO0D4_SL_SHIFT                 (8U)
#define PMU_GRF_GPIO0D_SL_GPIO0D4_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D4_SL_SHIFT)                 /* 0x00000300 */
#define PMU_GRF_GPIO0D_SL_GPIO0D5_SL_SHIFT                 (10U)
#define PMU_GRF_GPIO0D_SL_GPIO0D5_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D5_SL_SHIFT)                 /* 0x00000C00 */
#define PMU_GRF_GPIO0D_SL_GPIO0D6_SL_SHIFT                 (12U)
#define PMU_GRF_GPIO0D_SL_GPIO0D6_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D6_SL_SHIFT)                 /* 0x00003000 */
#define PMU_GRF_GPIO0D_SL_GPIO0D7_SL_SHIFT                 (14U)
#define PMU_GRF_GPIO0D_SL_GPIO0D7_SL_MASK                  (0x3U << PMU_GRF_GPIO0D_SL_GPIO0D7_SL_SHIFT)                 /* 0x0000C000 */
/* GPIO0A_DS_0 */
#define PMU_GRF_GPIO0A_DS_0_OFFSET                         (0x70U)
#define PMU_GRF_GPIO0A_DS_0_GPIO0A0_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0A_DS_0_GPIO0A0_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_0_GPIO0A0_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0A_DS_0_GPIO0A1_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0A_DS_0_GPIO0A1_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_0_GPIO0A1_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0A_DS_1 */
#define PMU_GRF_GPIO0A_DS_1_OFFSET                         (0x74U)
#define PMU_GRF_GPIO0A_DS_1_GPIO0A2_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0A_DS_1_GPIO0A2_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_1_GPIO0A2_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0A_DS_1_GPIO0A3_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0A_DS_1_GPIO0A3_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_1_GPIO0A3_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0A_DS_2 */
#define PMU_GRF_GPIO0A_DS_2_OFFSET                         (0x78U)
#define PMU_GRF_GPIO0A_DS_2_GPIO0A4_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0A_DS_2_GPIO0A4_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_2_GPIO0A4_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0A_DS_2_GPIO0A5_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0A_DS_2_GPIO0A5_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_2_GPIO0A5_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0A_DS_3 */
#define PMU_GRF_GPIO0A_DS_3_OFFSET                         (0x7CU)
#define PMU_GRF_GPIO0A_DS_3_GPIO0A6_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0A_DS_3_GPIO0A6_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_3_GPIO0A6_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0A_DS_3_GPIO0A7_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0A_DS_3_GPIO0A7_DS_MASK                (0x3FU << PMU_GRF_GPIO0A_DS_3_GPIO0A7_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0B_DS_0 */
#define PMU_GRF_GPIO0B_DS_0_OFFSET                         (0x80U)
#define PMU_GRF_GPIO0B_DS_0_GPIO0B0_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0B_DS_0_GPIO0B0_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_0_GPIO0B0_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0B_DS_0_GPIO0B1_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0B_DS_0_GPIO0B1_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_0_GPIO0B1_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0B_DS_1 */
#define PMU_GRF_GPIO0B_DS_1_OFFSET                         (0x84U)
#define PMU_GRF_GPIO0B_DS_1_GPIO0B2_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0B_DS_1_GPIO0B2_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_1_GPIO0B2_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0B_DS_1_GPIO0B3_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0B_DS_1_GPIO0B3_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_1_GPIO0B3_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0B_DS_2 */
#define PMU_GRF_GPIO0B_DS_2_OFFSET                         (0x88U)
#define PMU_GRF_GPIO0B_DS_2_GPIO0B4_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0B_DS_2_GPIO0B4_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_2_GPIO0B4_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0B_DS_2_GPIO0B5_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0B_DS_2_GPIO0B5_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_2_GPIO0B5_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0B_DS_3 */
#define PMU_GRF_GPIO0B_DS_3_OFFSET                         (0x8CU)
#define PMU_GRF_GPIO0B_DS_3_GPIO0B6_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0B_DS_3_GPIO0B6_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_3_GPIO0B6_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0B_DS_3_GPIO0B7_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0B_DS_3_GPIO0B7_DS_MASK                (0x3FU << PMU_GRF_GPIO0B_DS_3_GPIO0B7_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0C_DS_0 */
#define PMU_GRF_GPIO0C_DS_0_OFFSET                         (0x90U)
#define PMU_GRF_GPIO0C_DS_0_GPIO0C0_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0C_DS_0_GPIO0C0_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_0_GPIO0C0_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0C_DS_0_GPIO0C1_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0C_DS_0_GPIO0C1_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_0_GPIO0C1_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0C_DS_1 */
#define PMU_GRF_GPIO0C_DS_1_OFFSET                         (0x94U)
#define PMU_GRF_GPIO0C_DS_1_GPIO0C2_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0C_DS_1_GPIO0C2_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_1_GPIO0C2_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0C_DS_1_GPIO0C3_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0C_DS_1_GPIO0C3_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_1_GPIO0C3_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0C_DS_2 */
#define PMU_GRF_GPIO0C_DS_2_OFFSET                         (0x98U)
#define PMU_GRF_GPIO0C_DS_2_GPIO0C4_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0C_DS_2_GPIO0C4_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_2_GPIO0C4_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0C_DS_2_GPIO0C5_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0C_DS_2_GPIO0C5_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_2_GPIO0C5_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0C_DS_3 */
#define PMU_GRF_GPIO0C_DS_3_OFFSET                         (0x9CU)
#define PMU_GRF_GPIO0C_DS_3_GPIO0C6_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0C_DS_3_GPIO0C6_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_3_GPIO0C6_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0C_DS_3_GPIO0C7_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0C_DS_3_GPIO0C7_DS_MASK                (0x3FU << PMU_GRF_GPIO0C_DS_3_GPIO0C7_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0D_DS_0 */
#define PMU_GRF_GPIO0D_DS_0_OFFSET                         (0xA0U)
#define PMU_GRF_GPIO0D_DS_0_GPIO0D0_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0D_DS_0_GPIO0D0_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_0_GPIO0D0_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0D_DS_0_GPIO0D1_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0D_DS_0_GPIO0D1_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_0_GPIO0D1_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0D_DS_1 */
#define PMU_GRF_GPIO0D_DS_1_OFFSET                         (0xA4U)
#define PMU_GRF_GPIO0D_DS_1_GPIO0D2_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0D_DS_1_GPIO0D2_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_1_GPIO0D2_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0D_DS_1_GPIO0D3_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0D_DS_1_GPIO0D3_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_1_GPIO0D3_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0D_DS_2 */
#define PMU_GRF_GPIO0D_DS_2_OFFSET                         (0xA8U)
#define PMU_GRF_GPIO0D_DS_2_GPIO0D4_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0D_DS_2_GPIO0D4_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_2_GPIO0D4_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0D_DS_2_GPIO0D5_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0D_DS_2_GPIO0D5_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_2_GPIO0D5_DS_SHIFT)              /* 0x00003F00 */
/* GPIO0D_DS_3 */
#define PMU_GRF_GPIO0D_DS_3_OFFSET                         (0xACU)
#define PMU_GRF_GPIO0D_DS_3_GPIO0D6_DS_SHIFT               (0U)
#define PMU_GRF_GPIO0D_DS_3_GPIO0D6_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_3_GPIO0D6_DS_SHIFT)              /* 0x0000003F */
#define PMU_GRF_GPIO0D_DS_3_GPIO0D7_DS_SHIFT               (8U)
#define PMU_GRF_GPIO0D_DS_3_GPIO0D7_DS_MASK                (0x3FU << PMU_GRF_GPIO0D_DS_3_GPIO0D7_DS_SHIFT)              /* 0x00003F00 */
/* SOC_CON0 */
#define PMU_GRF_SOC_CON0_OFFSET                            (0x100U)
#define PMU_GRF_SOC_CON0_CON_32K_IOE_SHIFT                 (0U)
#define PMU_GRF_SOC_CON0_CON_32K_IOE_MASK                  (0x1U << PMU_GRF_SOC_CON0_CON_32K_IOE_SHIFT)                 /* 0x00000001 */
#define PMU_GRF_SOC_CON0_I2C0_IOMUX_SEL_SHIFT              (1U)
#define PMU_GRF_SOC_CON0_I2C0_IOMUX_SEL_MASK               (0x1U << PMU_GRF_SOC_CON0_I2C0_IOMUX_SEL_SHIFT)              /* 0x00000002 */
#define PMU_GRF_SOC_CON0_APLL_OSC_SOURCE_SEL_SHIFT         (2U)
#define PMU_GRF_SOC_CON0_APLL_OSC_SOURCE_SEL_MASK          (0x1U << PMU_GRF_SOC_CON0_APLL_OSC_SOURCE_SEL_SHIFT)         /* 0x00000004 */
#define PMU_GRF_SOC_CON0_DPLL_OSC_SOURCE_SEL_SHIFT         (3U)
#define PMU_GRF_SOC_CON0_DPLL_OSC_SOURCE_SEL_MASK          (0x1U << PMU_GRF_SOC_CON0_DPLL_OSC_SOURCE_SEL_SHIFT)         /* 0x00000008 */
#define PMU_GRF_SOC_CON0_UART0_RTS_SEL_SHIFT               (5U)
#define PMU_GRF_SOC_CON0_UART0_RTS_SEL_MASK                (0x1U << PMU_GRF_SOC_CON0_UART0_RTS_SEL_SHIFT)               /* 0x00000020 */
#define PMU_GRF_SOC_CON0_UART0_CTS_SEL_SHIFT               (6U)
#define PMU_GRF_SOC_CON0_UART0_CTS_SEL_MASK                (0x1U << PMU_GRF_SOC_CON0_UART0_CTS_SEL_SHIFT)               /* 0x00000040 */
#define PMU_GRF_SOC_CON0_GRF_CON_PMIC_SLEEP_SEL_SHIFT      (7U)
#define PMU_GRF_SOC_CON0_GRF_CON_PMIC_SLEEP_SEL_MASK       (0x1U << PMU_GRF_SOC_CON0_GRF_CON_PMIC_SLEEP_SEL_SHIFT)      /* 0x00000080 */
#define PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_SEL_SHIFT         (12U)
#define PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_SEL_MASK          (0x1U << PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_SEL_SHIFT)         /* 0x00001000 */
#define PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_CORE_SHIFT        (13U)
#define PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_CORE_MASK         (0x1U << PMU_GRF_SOC_CON0_DDRPHY_BUFFEREN_CORE_SHIFT)        /* 0x00002000 */
#define PMU_GRF_SOC_CON0_PVTM_FRQ_DONE_SHIFT               (14U)
#define PMU_GRF_SOC_CON0_PVTM_FRQ_DONE_MASK                (0x1U << PMU_GRF_SOC_CON0_PVTM_FRQ_DONE_SHIFT)               /* 0x00004000 */
/* SOC_CON1 */
#define PMU_GRF_SOC_CON1_OFFSET                            (0x104U)
#define PMU_GRF_SOC_CON1_RESETN_HOLD_SHIFT                 (0U)
#define PMU_GRF_SOC_CON1_RESETN_HOLD_MASK                  (0xFFFFU << PMU_GRF_SOC_CON1_RESETN_HOLD_SHIFT)              /* 0x0000FFFF */
/* SOC_CON2 */
#define PMU_GRF_SOC_CON2_OFFSET                            (0x108U)
#define PMU_GRF_SOC_CON2_RESETN_HOLD_SHIFT                 (0U)
#define PMU_GRF_SOC_CON2_RESETN_HOLD_MASK                  (0xFFFFU << PMU_GRF_SOC_CON2_RESETN_HOLD_SHIFT)              /* 0x0000FFFF */
/* SOC_CON3 */
#define PMU_GRF_SOC_CON3_OFFSET                            (0x10CU)
#define PMU_GRF_SOC_CON3_TSADC_SHUT_RESET_TRIGGER_EN_SHIFT (0U)
#define PMU_GRF_SOC_CON3_TSADC_SHUT_RESET_TRIGGER_EN_MASK  (0x1U << PMU_GRF_SOC_CON3_TSADC_SHUT_RESET_TRIGGER_EN_SHIFT) /* 0x00000001 */
#define PMU_GRF_SOC_CON3_WDT_SHUT_RESET_TRIGGER_EN_SHIFT   (1U)
#define PMU_GRF_SOC_CON3_WDT_SHUT_RESET_TRIGGER_EN_MASK    (0x1U << PMU_GRF_SOC_CON3_WDT_SHUT_RESET_TRIGGER_EN_SHIFT)   /* 0x00000002 */
#define PMU_GRF_SOC_CON3_DDRIO_RET_EN_SHIFT                (2U)
#define PMU_GRF_SOC_CON3_DDRIO_RET_EN_MASK                 (0x1U << PMU_GRF_SOC_CON3_DDRIO_RET_EN_SHIFT)                /* 0x00000004 */
#define PMU_GRF_SOC_CON3_SREF_ENTER_EN_SHIFT               (3U)
#define PMU_GRF_SOC_CON3_SREF_ENTER_EN_MASK                (0x1U << PMU_GRF_SOC_CON3_SREF_ENTER_EN_SHIFT)               /* 0x00000008 */
#define PMU_GRF_SOC_CON3_DDRC_GATING_EN_SHIFT              (4U)
#define PMU_GRF_SOC_CON3_DDRC_GATING_EN_MASK               (0x1U << PMU_GRF_SOC_CON3_DDRC_GATING_EN_SHIFT)              /* 0x00000010 */
#define PMU_GRF_SOC_CON3_DDR_IO_RET_DE_REQ_SHIFT           (5U)
#define PMU_GRF_SOC_CON3_DDR_IO_RET_DE_REQ_MASK            (0x1U << PMU_GRF_SOC_CON3_DDR_IO_RET_DE_REQ_SHIFT)           /* 0x00000020 */
#define PMU_GRF_SOC_CON3_DDR_IO_RET_CFG_SHIFT              (6U)
#define PMU_GRF_SOC_CON3_DDR_IO_RET_CFG_MASK               (0x1U << PMU_GRF_SOC_CON3_DDR_IO_RET_CFG_SHIFT)              /* 0x00000040 */
#define PMU_GRF_SOC_CON3_DDR_IO_RET_OEN_CFG_SHIFT          (7U)
#define PMU_GRF_SOC_CON3_DDR_IO_RET_OEN_CFG_MASK           (0x1U << PMU_GRF_SOC_CON3_DDR_IO_RET_OEN_CFG_SHIFT)          /* 0x00000080 */
#define PMU_GRF_SOC_CON3_UPCTL_C_SYSREQ_CFG_SHIFT          (8U)
#define PMU_GRF_SOC_CON3_UPCTL_C_SYSREQ_CFG_MASK           (0x1U << PMU_GRF_SOC_CON3_UPCTL_C_SYSREQ_CFG_SHIFT)          /* 0x00000100 */
#define PMU_GRF_SOC_CON3_CORE_WFI_EN_SHIFT                 (9U)
#define PMU_GRF_SOC_CON3_CORE_WFI_EN_MASK                  (0x1U << PMU_GRF_SOC_CON3_CORE_WFI_EN_SHIFT)                 /* 0x00000200 */
#define PMU_GRF_SOC_CON3_CORE_OFF_EN_SHIFT                 (10U)
#define PMU_GRF_SOC_CON3_CORE_OFF_EN_MASK                  (0x1U << PMU_GRF_SOC_CON3_CORE_OFF_EN_SHIFT)                 /* 0x00000400 */
#define PMU_GRF_SOC_CON3_CORE_RET_EN_SHIFT                 (11U)
#define PMU_GRF_SOC_CON3_CORE_RET_EN_MASK                  (0x1U << PMU_GRF_SOC_CON3_CORE_RET_EN_SHIFT)                 /* 0x00000800 */
#define PMU_GRF_SOC_CON3_CORE_PACTIVE_EN_SHIFT             (12U)
#define PMU_GRF_SOC_CON3_CORE_PACTIVE_EN_MASK              (0x1U << PMU_GRF_SOC_CON3_CORE_PACTIVE_EN_SHIFT)             /* 0x00001000 */
#define PMU_GRF_SOC_CON3_DSU_OFF_EN_SHIFT                  (13U)
#define PMU_GRF_SOC_CON3_DSU_OFF_EN_MASK                   (0x1U << PMU_GRF_SOC_CON3_DSU_OFF_EN_SHIFT)                  /* 0x00002000 */
#define PMU_GRF_SOC_CON3_DSU_RET_EN_SHIFT                  (14U)
#define PMU_GRF_SOC_CON3_DSU_RET_EN_MASK                   (0x1U << PMU_GRF_SOC_CON3_DSU_RET_EN_SHIFT)                  /* 0x00004000 */
#define PMU_GRF_SOC_CON3_DSU_PACTIVE_EN_SHIFT              (15U)
#define PMU_GRF_SOC_CON3_DSU_PACTIVE_EN_MASK               (0x1U << PMU_GRF_SOC_CON3_DSU_PACTIVE_EN_SHIFT)              /* 0x00008000 */
/* SOC_CON4 */
#define PMU_GRF_SOC_CON4_OFFSET                            (0x110U)
#define PMU_GRF_SOC_CON4_PWM0_IOMUX_SEL_SHIFT              (0U)
#define PMU_GRF_SOC_CON4_PWM0_IOMUX_SEL_MASK               (0x3U << PMU_GRF_SOC_CON4_PWM0_IOMUX_SEL_SHIFT)              /* 0x00000003 */
#define PMU_GRF_SOC_CON4_PWM1_IOMUX_SEL_SHIFT              (2U)
#define PMU_GRF_SOC_CON4_PWM1_IOMUX_SEL_MASK               (0x3U << PMU_GRF_SOC_CON4_PWM1_IOMUX_SEL_SHIFT)              /* 0x0000000C */
#define PMU_GRF_SOC_CON4_PWM2_IOMUX_SEL_SHIFT              (4U)
#define PMU_GRF_SOC_CON4_PWM2_IOMUX_SEL_MASK               (0x3U << PMU_GRF_SOC_CON4_PWM2_IOMUX_SEL_SHIFT)              /* 0x00000030 */
#define PMU_GRF_SOC_CON4_GPU_PWREN_POL_SHIFT               (10U)
#define PMU_GRF_SOC_CON4_GPU_PWREN_POL_MASK                (0x3U << PMU_GRF_SOC_CON4_GPU_PWREN_POL_SHIFT)               /* 0x00000C00 */
#define PMU_GRF_SOC_CON4_SPRA_HD_WTSEL_SHIFT               (12U)
#define PMU_GRF_SOC_CON4_SPRA_HD_WTSEL_MASK                (0x3U << PMU_GRF_SOC_CON4_SPRA_HD_WTSEL_SHIFT)               /* 0x00003000 */
#define PMU_GRF_SOC_CON4_SPRA_HD_RTSEL_SHIFT               (14U)
#define PMU_GRF_SOC_CON4_SPRA_HD_RTSEL_MASK                (0x3U << PMU_GRF_SOC_CON4_SPRA_HD_RTSEL_SHIFT)               /* 0x0000C000 */
/* SOC_CON5 */
#define PMU_GRF_SOC_CON5_OFFSET                            (0x114U)
#define PMU_GRF_SOC_CON5_OUT2CHIP_RST_INIT_SHIFT           (0U)
#define PMU_GRF_SOC_CON5_OUT2CHIP_RST_INIT_MASK            (0x1FFFU << PMU_GRF_SOC_CON5_OUT2CHIP_RST_INIT_SHIFT)        /* 0x00001FFF */
/* IO_VSEL0 */
#define PMU_GRF_IO_VSEL0_OFFSET                            (0x124U)
#define PMU_GRF_IO_VSEL0_VCCIO2_VOLTAGE_CONTROL_SELECT_SHIFT (0U)
#define PMU_GRF_IO_VSEL0_VCCIO2_VOLTAGE_CONTROL_SELECT_MASK (0x1U << PMU_GRF_IO_VSEL0_VCCIO2_VOLTAGE_CONTROL_SELECT_SHIFT) /* 0x00000001 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL18_SHIFT            (1U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL18_SHIFT)            /* 0x00000002 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL18_SHIFT            (2U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL18_SHIFT)            /* 0x00000004 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL18_SHIFT            (3U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL18_SHIFT)            /* 0x00000008 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL18_SHIFT            (4U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL18_SHIFT)            /* 0x00000010 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL18_SHIFT            (5U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL18_SHIFT)            /* 0x00000020 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL18_SHIFT            (6U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL18_SHIFT)            /* 0x00000040 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL18_SHIFT            (7U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL18_SHIFT)            /* 0x00000080 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL25_SHIFT            (8U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO1_SEL25_SHIFT)            /* 0x00000100 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL25_SHIFT            (9U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO2_SEL25_SHIFT)            /* 0x00000200 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL25_SHIFT            (10U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO3_SEL25_SHIFT)            /* 0x00000400 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL25_SHIFT            (11U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO4_SEL25_SHIFT)            /* 0x00000800 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL25_SHIFT            (12U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO5_SEL25_SHIFT)            /* 0x00001000 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL25_SHIFT            (13U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO6_SEL25_SHIFT)            /* 0x00002000 */
#define PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL25_SHIFT            (14U)
#define PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL0_POC_VCCIO7_SEL25_SHIFT)            /* 0x00004000 */
/* IO_VSEL1 */
#define PMU_GRF_IO_VSEL1_OFFSET                            (0x128U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO1_SEL33_SHIFT            (1U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO1_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO1_SEL33_SHIFT)            /* 0x00000002 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO2_SEL33_SHIFT            (2U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO2_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO2_SEL33_SHIFT)            /* 0x00000004 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO3_SEL33_SHIFT            (3U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO3_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO3_SEL33_SHIFT)            /* 0x00000008 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO4_SEL33_SHIFT            (4U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO4_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO4_SEL33_SHIFT)            /* 0x00000010 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO5_SEL33_SHIFT            (5U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO5_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO5_SEL33_SHIFT)            /* 0x00000020 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO6_SEL33_SHIFT            (6U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO6_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO6_SEL33_SHIFT)            /* 0x00000040 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO7_SEL33_SHIFT            (7U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO7_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO7_SEL33_SHIFT)            /* 0x00000080 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO1_IDDQ_SHIFT             (8U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO1_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO1_IDDQ_SHIFT)             /* 0x00000100 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO2_IDDQ_SHIFT             (9U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO2_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO2_IDDQ_SHIFT)             /* 0x00000200 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO3_IDDQ_SHIFT             (10U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO3_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO3_IDDQ_SHIFT)             /* 0x00000400 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO4_IDDQ_SHIFT             (11U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO4_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO4_IDDQ_SHIFT)             /* 0x00000800 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO5_IDDQ_SHIFT             (12U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO5_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO5_IDDQ_SHIFT)             /* 0x00001000 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO6_IDDQ_SHIFT             (13U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO6_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO6_IDDQ_SHIFT)             /* 0x00002000 */
#define PMU_GRF_IO_VSEL1_POC_VCCIO7_IDDQ_SHIFT             (14U)
#define PMU_GRF_IO_VSEL1_POC_VCCIO7_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL1_POC_VCCIO7_IDDQ_SHIFT)             /* 0x00004000 */
/* IO_VSEL2 */
#define PMU_GRF_IO_VSEL2_OFFSET                            (0x12CU)
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL18_SHIFT            (0U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL18_SHIFT)            /* 0x00000001 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL18_SHIFT            (1U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL18_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL18_SHIFT)            /* 0x00000002 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL25_SHIFT            (2U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL25_SHIFT)            /* 0x00000004 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL25_SHIFT            (3U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL25_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL25_SHIFT)            /* 0x00000008 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL33_SHIFT            (4U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO1_SEL33_SHIFT)            /* 0x00000010 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL33_SHIFT            (5U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL33_MASK             (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO2_SEL33_SHIFT)            /* 0x00000020 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_IDDQ_SHIFT             (6U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO1_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO1_IDDQ_SHIFT)             /* 0x00000040 */
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_IDDQ_SHIFT             (7U)
#define PMU_GRF_IO_VSEL2_POC_PMUIO2_IDDQ_MASK              (0x1U << PMU_GRF_IO_VSEL2_POC_PMUIO2_IDDQ_SHIFT)             /* 0x00000080 */
/* DLL_CON0 */
#define PMU_GRF_DLL_CON0_OFFSET                            (0x180U)
#define PMU_GRF_DLL_CON0_PVTM_CLKOUT_DIV_SHIFT             (0U)
#define PMU_GRF_DLL_CON0_PVTM_CLKOUT_DIV_MASK              (0xFFFU << PMU_GRF_DLL_CON0_PVTM_CLKOUT_DIV_SHIFT)           /* 0x00000FFF */
/* OS_REG0 */
#define PMU_GRF_OS_REG0_OFFSET                             (0x200U)
#define PMU_GRF_OS_REG0_PMU_OS_REG0_SHIFT                  (0U)
#define PMU_GRF_OS_REG0_PMU_OS_REG0_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG0_PMU_OS_REG0_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG1 */
#define PMU_GRF_OS_REG1_OFFSET                             (0x204U)
#define PMU_GRF_OS_REG1_PMU_OS_REG1_SHIFT                  (0U)
#define PMU_GRF_OS_REG1_PMU_OS_REG1_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG1_PMU_OS_REG1_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG2 */
#define PMU_GRF_OS_REG2_OFFSET                             (0x208U)
#define PMU_GRF_OS_REG2_PMU_OS_REG2_SHIFT                  (0U)
#define PMU_GRF_OS_REG2_PMU_OS_REG2_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG2_PMU_OS_REG2_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG3 */
#define PMU_GRF_OS_REG3_OFFSET                             (0x20CU)
#define PMU_GRF_OS_REG3_PMU_OS_REG3_SHIFT                  (0U)
#define PMU_GRF_OS_REG3_PMU_OS_REG3_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG3_PMU_OS_REG3_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG4 */
#define PMU_GRF_OS_REG4_OFFSET                             (0x210U)
#define PMU_GRF_OS_REG4_PMU_OS_REG4_SHIFT                  (0U)
#define PMU_GRF_OS_REG4_PMU_OS_REG4_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG4_PMU_OS_REG4_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG5 */
#define PMU_GRF_OS_REG5_OFFSET                             (0x214U)
#define PMU_GRF_OS_REG5_PMU_OS_REG5_SHIFT                  (0U)
#define PMU_GRF_OS_REG5_PMU_OS_REG5_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG5_PMU_OS_REG5_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG6 */
#define PMU_GRF_OS_REG6_OFFSET                             (0x218U)
#define PMU_GRF_OS_REG6_PMU_OS_REG6_SHIFT                  (0U)
#define PMU_GRF_OS_REG6_PMU_OS_REG6_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG6_PMU_OS_REG6_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG7 */
#define PMU_GRF_OS_REG7_OFFSET                             (0x21CU)
#define PMU_GRF_OS_REG7_PMU_OS_REG7_SHIFT                  (0U)
#define PMU_GRF_OS_REG7_PMU_OS_REG7_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG7_PMU_OS_REG7_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG8 */
#define PMU_GRF_OS_REG8_OFFSET                             (0x220U)
#define PMU_GRF_OS_REG8_PMU_OS_REG8_SHIFT                  (0U)
#define PMU_GRF_OS_REG8_PMU_OS_REG8_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG8_PMU_OS_REG8_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG9 */
#define PMU_GRF_OS_REG9_OFFSET                             (0x224U)
#define PMU_GRF_OS_REG9_PMU_OS_REG9_SHIFT                  (0U)
#define PMU_GRF_OS_REG9_PMU_OS_REG9_MASK                   (0xFFFFFFFFU << PMU_GRF_OS_REG9_PMU_OS_REG9_SHIFT)           /* 0xFFFFFFFF */
/* OS_REG10 */
#define PMU_GRF_OS_REG10_OFFSET                            (0x228U)
#define PMU_GRF_OS_REG10_PMU_OS_REG10_SHIFT                (0U)
#define PMU_GRF_OS_REG10_PMU_OS_REG10_MASK                 (0xFFFFFFFFU << PMU_GRF_OS_REG10_PMU_OS_REG10_SHIFT)         /* 0xFFFFFFFF */
/* OS_REG11 */
#define PMU_GRF_OS_REG11_OFFSET                            (0x22CU)
#define PMU_GRF_OS_REG11_PMU_OS_REG11_SHIFT                (0U)
#define PMU_GRF_OS_REG11_PMU_OS_REG11_MASK                 (0xFFFFFFFFU << PMU_GRF_OS_REG11_PMU_OS_REG11_SHIFT)         /* 0xFFFFFFFF */
/* RESET_FUNCTION_STATUS */
#define PMU_GRF_RESET_FUNCTION_STATUS_OFFSET               (0x230U)
#define PMU_GRF_RESET_FUNCTION_STATUS_FIRST_RESET_SRC_SHIFT (0U)
#define PMU_GRF_RESET_FUNCTION_STATUS_FIRST_RESET_SRC_MASK (0x1U << PMU_GRF_RESET_FUNCTION_STATUS_FIRST_RESET_SRC_SHIFT) /* 0x00000001 */
#define PMU_GRF_RESET_FUNCTION_STATUS_WDT_RESET_SRC_SHIFT  (1U)
#define PMU_GRF_RESET_FUNCTION_STATUS_WDT_RESET_SRC_MASK   (0x1U << PMU_GRF_RESET_FUNCTION_STATUS_WDT_RESET_SRC_SHIFT)  /* 0x00000002 */
#define PMU_GRF_RESET_FUNCTION_STATUS_TSADC_SHUT_RESET_SRC_SHIFT (2U)
#define PMU_GRF_RESET_FUNCTION_STATUS_TSADC_SHUT_RESET_SRC_MASK (0x1U << PMU_GRF_RESET_FUNCTION_STATUS_TSADC_SHUT_RESET_SRC_SHIFT) /* 0x00000004 */
#define PMU_GRF_RESET_FUNCTION_STATUS_DDR_FAIL_SAFE_SRC_SHIFT (3U)
#define PMU_GRF_RESET_FUNCTION_STATUS_DDR_FAIL_SAFE_SRC_MASK (0x1U << PMU_GRF_RESET_FUNCTION_STATUS_DDR_FAIL_SAFE_SRC_SHIFT) /* 0x00000008 */
/* RESET_FUNCTION_CLR */
#define PMU_GRF_RESET_FUNCTION_CLR_OFFSET                  (0x234U)
#define PMU_GRF_RESET_FUNCTION_CLR_FIRST_RESET_SRC_CLR_SHIFT (0U)
#define PMU_GRF_RESET_FUNCTION_CLR_FIRST_RESET_SRC_CLR_MASK (0x1U << PMU_GRF_RESET_FUNCTION_CLR_FIRST_RESET_SRC_CLR_SHIFT) /* 0x00000001 */
#define PMU_GRF_RESET_FUNCTION_CLR_WDT_RESET_SRC_CLR_SHIFT (1U)
#define PMU_GRF_RESET_FUNCTION_CLR_WDT_RESET_SRC_CLR_MASK  (0x1U << PMU_GRF_RESET_FUNCTION_CLR_WDT_RESET_SRC_CLR_SHIFT) /* 0x00000002 */
#define PMU_GRF_RESET_FUNCTION_CLR_TSADC_SHUT_RESET_SRC_CLR_SHIFT (2U)
#define PMU_GRF_RESET_FUNCTION_CLR_TSADC_SHUT_RESET_SRC_CLR_MASK (0x1U << PMU_GRF_RESET_FUNCTION_CLR_TSADC_SHUT_RESET_SRC_CLR_SHIFT) /* 0x00000004 */
#define PMU_GRF_RESET_FUNCTION_CLR_DDR_FAIL_SAFE_SRC_CLR_SHIFT (3U)
#define PMU_GRF_RESET_FUNCTION_CLR_DDR_FAIL_SAFE_SRC_CLR_MASK (0x1U << PMU_GRF_RESET_FUNCTION_CLR_DDR_FAIL_SAFE_SRC_CLR_SHIFT) /* 0x00000008 */
/* SIG_DETECT_CON */
#define PMU_GRF_SIG_DETECT_CON_OFFSET                      (0x380U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_POS_IRQ_MSK_SHIFT (0U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_POS_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_POS_IRQ_MSK_SHIFT) /* 0x00000001 */
#define PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_NEG_IRQ_MSK_SHIFT (1U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_NEG_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC0_DETECTN_NEG_IRQ_MSK_SHIFT) /* 0x00000002 */
#define PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_POS_IRQ_MSK_SHIFT (2U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_POS_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_POS_IRQ_MSK_SHIFT) /* 0x00000004 */
#define PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_NEG_IRQ_MSK_SHIFT (3U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_NEG_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC1_DETECTN_NEG_IRQ_MSK_SHIFT) /* 0x00000008 */
#define PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_POS_IRQ_MSK_SHIFT (4U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_POS_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_POS_IRQ_MSK_SHIFT) /* 0x00000010 */
#define PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_NEG_IRQ_MSK_SHIFT (5U)
#define PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_NEG_IRQ_MSK_MASK (0x1U << PMU_GRF_SIG_DETECT_CON_SDMMC2_DETECTN_NEG_IRQ_MSK_SHIFT) /* 0x00000020 */
/* SIG_DETECT_STATUS */
#define PMU_GRF_SIG_DETECT_STATUS_OFFSET                   (0x390U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_POS_IRQ_SHIFT (0U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_POS_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_POS_IRQ_SHIFT) /* 0x00000001 */
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_NEG_IRQ_SHIFT (1U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_NEG_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC0_DETECTN_NEG_IRQ_SHIFT) /* 0x00000002 */
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_POS_IRQ_SHIFT (2U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_POS_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_POS_IRQ_SHIFT) /* 0x00000004 */
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_NEG_IRQ_SHIFT (3U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_NEG_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC1_DETECTN_NEG_IRQ_SHIFT) /* 0x00000008 */
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_POS_IRQ_SHIFT (4U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_POS_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_POS_IRQ_SHIFT) /* 0x00000010 */
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_NEG_IRQ_SHIFT (5U)
#define PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_NEG_IRQ_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_SDMMC2_DETECTN_NEG_IRQ_SHIFT) /* 0x00000020 */
/* SIG_DETECT_STATUS_CLEAR */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_OFFSET             (0x3A0U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_POS_IRQ_CLR_SHIFT (0U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_POS_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_POS_IRQ_CLR_SHIFT) /* 0x00000001 */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_NEG_IRQ_CLR_SHIFT (1U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_NEG_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC0_DETECTN_NEG_IRQ_CLR_SHIFT) /* 0x00000002 */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_POS_IRQ_CLR_SHIFT (2U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_POS_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_POS_IRQ_CLR_SHIFT) /* 0x00000004 */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_NEG_IRQ_CLR_SHIFT (3U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_NEG_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC1_DETECTN_NEG_IRQ_CLR_SHIFT) /* 0x00000008 */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_POS_IRQ_CLR_SHIFT (4U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_POS_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_POS_IRQ_CLR_SHIFT) /* 0x00000010 */
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_NEG_IRQ_CLR_SHIFT (5U)
#define PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_NEG_IRQ_CLR_MASK (0x1U << PMU_GRF_SIG_DETECT_STATUS_CLEAR_SDMMC2_DETECTN_NEG_IRQ_CLR_SHIFT) /* 0x00000020 */
/* SDMMC_DET_COUNTER */
#define PMU_GRF_SDMMC_DET_COUNTER_OFFSET                   (0x3B0U)
#define PMU_GRF_SDMMC_DET_COUNTER_SDMMC_DETECTN_COUNT_SHIFT (0U)
#define PMU_GRF_SDMMC_DET_COUNTER_SDMMC_DETECTN_COUNT_MASK (0xFFFFFU << PMU_GRF_SDMMC_DET_COUNTER_SDMMC_DETECTN_COUNT_SHIFT) /* 0x000FFFFF */
/*****************************************PMUCRU*****************************************/
/* PPLL_CON0 */
#define PMUCRU_PPLL_CON0_OFFSET                            (0x0U)
#define PMUCRU_PPLL_CON0_FBDIV_SHIFT                       (0U)
#define PMUCRU_PPLL_CON0_FBDIV_MASK                        (0xFFFU << PMUCRU_PPLL_CON0_FBDIV_SHIFT)                     /* 0x00000FFF */
#define PMUCRU_PPLL_CON0_POSTDIV1_SHIFT                    (12U)
#define PMUCRU_PPLL_CON0_POSTDIV1_MASK                     (0x7U << PMUCRU_PPLL_CON0_POSTDIV1_SHIFT)                    /* 0x00007000 */
#define PMUCRU_PPLL_CON0_BYPASS_SHIFT                      (15U)
#define PMUCRU_PPLL_CON0_BYPASS_MASK                       (0x1U << PMUCRU_PPLL_CON0_BYPASS_SHIFT)                      /* 0x00008000 */
/* PPLL_CON1 */
#define PMUCRU_PPLL_CON1_OFFSET                            (0x4U)
#define PMUCRU_PPLL_CON1_REFDIV_SHIFT                      (0U)
#define PMUCRU_PPLL_CON1_REFDIV_MASK                       (0x3FU << PMUCRU_PPLL_CON1_REFDIV_SHIFT)                     /* 0x0000003F */
#define PMUCRU_PPLL_CON1_POSTDIV2_SHIFT                    (6U)
#define PMUCRU_PPLL_CON1_POSTDIV2_MASK                     (0x7U << PMUCRU_PPLL_CON1_POSTDIV2_SHIFT)                    /* 0x000001C0 */
#define PMUCRU_PPLL_CON1_PLL_LOCK_SHIFT                    (10U)
#define PMUCRU_PPLL_CON1_PLL_LOCK_MASK                     (0x1U << PMUCRU_PPLL_CON1_PLL_LOCK_SHIFT)                    /* 0x00000400 */
#define PMUCRU_PPLL_CON1_DSMPD_SHIFT                       (12U)
#define PMUCRU_PPLL_CON1_DSMPD_MASK                        (0x1U << PMUCRU_PPLL_CON1_DSMPD_SHIFT)                       /* 0x00001000 */
#define PMUCRU_PPLL_CON1_PLLPD0_SHIFT                      (13U)
#define PMUCRU_PPLL_CON1_PLLPD0_MASK                       (0x1U << PMUCRU_PPLL_CON1_PLLPD0_SHIFT)                      /* 0x00002000 */
#define PMUCRU_PPLL_CON1_PLLPD1_SHIFT                      (14U)
#define PMUCRU_PPLL_CON1_PLLPD1_MASK                       (0x1U << PMUCRU_PPLL_CON1_PLLPD1_SHIFT)                      /* 0x00004000 */
#define PMUCRU_PPLL_CON1_PLLPDSEL_SHIFT                    (15U)
#define PMUCRU_PPLL_CON1_PLLPDSEL_MASK                     (0x1U << PMUCRU_PPLL_CON1_PLLPDSEL_SHIFT)                    /* 0x00008000 */
/* PPLL_CON2 */
#define PMUCRU_PPLL_CON2_OFFSET                            (0x8U)
#define PMUCRU_PPLL_CON2_FRACDIV_SHIFT                     (0U)
#define PMUCRU_PPLL_CON2_FRACDIV_MASK                      (0xFFFFFFU << PMUCRU_PPLL_CON2_FRACDIV_SHIFT)                /* 0x00FFFFFF */
#define PMUCRU_PPLL_CON2_DACPD_SHIFT                       (24U)
#define PMUCRU_PPLL_CON2_DACPD_MASK                        (0x1U << PMUCRU_PPLL_CON2_DACPD_SHIFT)                       /* 0x01000000 */
#define PMUCRU_PPLL_CON2_FOUTPOSTDIVPD_SHIFT               (25U)
#define PMUCRU_PPLL_CON2_FOUTPOSTDIVPD_MASK                (0x1U << PMUCRU_PPLL_CON2_FOUTPOSTDIVPD_SHIFT)               /* 0x02000000 */
#define PMUCRU_PPLL_CON2_FOUTVCOPD_SHIFT                   (26U)
#define PMUCRU_PPLL_CON2_FOUTVCOPD_MASK                    (0x1U << PMUCRU_PPLL_CON2_FOUTVCOPD_SHIFT)                   /* 0x04000000 */
#define PMUCRU_PPLL_CON2_FOUT4PHASEPD_SHIFT                (27U)
#define PMUCRU_PPLL_CON2_FOUT4PHASEPD_MASK                 (0x1U << PMUCRU_PPLL_CON2_FOUT4PHASEPD_SHIFT)                /* 0x08000000 */
/* PPLL_CON3 */
#define PMUCRU_PPLL_CON3_OFFSET                            (0xCU)
#define PMUCRU_PPLL_CON3_SSMOD_BP_SHIFT                    (0U)
#define PMUCRU_PPLL_CON3_SSMOD_BP_MASK                     (0x1U << PMUCRU_PPLL_CON3_SSMOD_BP_SHIFT)                    /* 0x00000001 */
#define PMUCRU_PPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT          (1U)
#define PMUCRU_PPLL_CON3_SSMOD_DISABLE_SSCG_MASK           (0x1U << PMUCRU_PPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)          /* 0x00000002 */
#define PMUCRU_PPLL_CON3_SSMOD_RESET_SHIFT                 (2U)
#define PMUCRU_PPLL_CON3_SSMOD_RESET_MASK                  (0x1U << PMUCRU_PPLL_CON3_SSMOD_RESET_SHIFT)                 /* 0x00000004 */
#define PMUCRU_PPLL_CON3_SSMOD_DOWNSPREAD_SHIFT            (3U)
#define PMUCRU_PPLL_CON3_SSMOD_DOWNSPREAD_MASK             (0x1U << PMUCRU_PPLL_CON3_SSMOD_DOWNSPREAD_SHIFT)            /* 0x00000008 */
#define PMUCRU_PPLL_CON3_SSMOD_DIVVAL_SHIFT                (4U)
#define PMUCRU_PPLL_CON3_SSMOD_DIVVAL_MASK                 (0xFU << PMUCRU_PPLL_CON3_SSMOD_DIVVAL_SHIFT)                /* 0x000000F0 */
#define PMUCRU_PPLL_CON3_SSMOD_SPREAD_SHIFT                (8U)
#define PMUCRU_PPLL_CON3_SSMOD_SPREAD_MASK                 (0x1FU << PMUCRU_PPLL_CON3_SSMOD_SPREAD_SHIFT)               /* 0x00001F00 */
/* PPLL_CON4 */
#define PMUCRU_PPLL_CON4_OFFSET                            (0x10U)
#define PMUCRU_PPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT          (0U)
#define PMUCRU_PPLL_CON4_SSMOD_SEL_EXT_WAVE_MASK           (0x1U << PMUCRU_PPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)          /* 0x00000001 */
#define PMUCRU_PPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT           (8U)
#define PMUCRU_PPLL_CON4_SSMOD_EXT_MAXADDR_MASK            (0xFFU << PMUCRU_PPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)          /* 0x0000FF00 */
/* HPLL_CON0 */
#define PMUCRU_HPLL_CON0_OFFSET                            (0x20U)
#define PMUCRU_HPLL_CON0_FBDIV_SHIFT                       (0U)
#define PMUCRU_HPLL_CON0_FBDIV_MASK                        (0xFFFU << PMUCRU_HPLL_CON0_FBDIV_SHIFT)                     /* 0x00000FFF */
#define PMUCRU_HPLL_CON0_POSTDIV1_SHIFT                    (12U)
#define PMUCRU_HPLL_CON0_POSTDIV1_MASK                     (0x7U << PMUCRU_HPLL_CON0_POSTDIV1_SHIFT)                    /* 0x00007000 */
#define PMUCRU_HPLL_CON0_BYPASS_SHIFT                      (15U)
#define PMUCRU_HPLL_CON0_BYPASS_MASK                       (0x1U << PMUCRU_HPLL_CON0_BYPASS_SHIFT)                      /* 0x00008000 */
/* HPLL_CON1 */
#define PMUCRU_HPLL_CON1_OFFSET                            (0x24U)
#define PMUCRU_HPLL_CON1_REFDIV_SHIFT                      (0U)
#define PMUCRU_HPLL_CON1_REFDIV_MASK                       (0x3FU << PMUCRU_HPLL_CON1_REFDIV_SHIFT)                     /* 0x0000003F */
#define PMUCRU_HPLL_CON1_POSTDIV2_SHIFT                    (6U)
#define PMUCRU_HPLL_CON1_POSTDIV2_MASK                     (0x7U << PMUCRU_HPLL_CON1_POSTDIV2_SHIFT)                    /* 0x000001C0 */
#define PMUCRU_HPLL_CON1_PLL_LOCK_SHIFT                    (10U)
#define PMUCRU_HPLL_CON1_PLL_LOCK_MASK                     (0x1U << PMUCRU_HPLL_CON1_PLL_LOCK_SHIFT)                    /* 0x00000400 */
#define PMUCRU_HPLL_CON1_DSMPD_SHIFT                       (12U)
#define PMUCRU_HPLL_CON1_DSMPD_MASK                        (0x1U << PMUCRU_HPLL_CON1_DSMPD_SHIFT)                       /* 0x00001000 */
#define PMUCRU_HPLL_CON1_PLLPD0_SHIFT                      (13U)
#define PMUCRU_HPLL_CON1_PLLPD0_MASK                       (0x1U << PMUCRU_HPLL_CON1_PLLPD0_SHIFT)                      /* 0x00002000 */
#define PMUCRU_HPLL_CON1_PLLPD1_SHIFT                      (14U)
#define PMUCRU_HPLL_CON1_PLLPD1_MASK                       (0x1U << PMUCRU_HPLL_CON1_PLLPD1_SHIFT)                      /* 0x00004000 */
#define PMUCRU_HPLL_CON1_PLLPDSEL_SHIFT                    (15U)
#define PMUCRU_HPLL_CON1_PLLPDSEL_MASK                     (0x1U << PMUCRU_HPLL_CON1_PLLPDSEL_SHIFT)                    /* 0x00008000 */
/* HPLL_CON2 */
#define PMUCRU_HPLL_CON2_OFFSET                            (0x28U)
#define PMUCRU_HPLL_CON2_FRACDIV_SHIFT                     (0U)
#define PMUCRU_HPLL_CON2_FRACDIV_MASK                      (0xFFFFFFU << PMUCRU_HPLL_CON2_FRACDIV_SHIFT)                /* 0x00FFFFFF */
#define PMUCRU_HPLL_CON2_DACPD_SHIFT                       (24U)
#define PMUCRU_HPLL_CON2_DACPD_MASK                        (0x1U << PMUCRU_HPLL_CON2_DACPD_SHIFT)                       /* 0x01000000 */
#define PMUCRU_HPLL_CON2_FOUTPOSTDIVPD_SHIFT               (25U)
#define PMUCRU_HPLL_CON2_FOUTPOSTDIVPD_MASK                (0x1U << PMUCRU_HPLL_CON2_FOUTPOSTDIVPD_SHIFT)               /* 0x02000000 */
#define PMUCRU_HPLL_CON2_FOUTVCOPD_SHIFT                   (26U)
#define PMUCRU_HPLL_CON2_FOUTVCOPD_MASK                    (0x1U << PMUCRU_HPLL_CON2_FOUTVCOPD_SHIFT)                   /* 0x04000000 */
#define PMUCRU_HPLL_CON2_FOUT4PHASEPD_SHIFT                (27U)
#define PMUCRU_HPLL_CON2_FOUT4PHASEPD_MASK                 (0x1U << PMUCRU_HPLL_CON2_FOUT4PHASEPD_SHIFT)                /* 0x08000000 */
/* HPLL_CON3 */
#define PMUCRU_HPLL_CON3_OFFSET                            (0x2CU)
#define PMUCRU_HPLL_CON3_SSMOD_BP_SHIFT                    (0U)
#define PMUCRU_HPLL_CON3_SSMOD_BP_MASK                     (0x1U << PMUCRU_HPLL_CON3_SSMOD_BP_SHIFT)                    /* 0x00000001 */
#define PMUCRU_HPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT          (1U)
#define PMUCRU_HPLL_CON3_SSMOD_DISABLE_SSCG_MASK           (0x1U << PMUCRU_HPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)          /* 0x00000002 */
#define PMUCRU_HPLL_CON3_SSMOD_RESET_SHIFT                 (2U)
#define PMUCRU_HPLL_CON3_SSMOD_RESET_MASK                  (0x1U << PMUCRU_HPLL_CON3_SSMOD_RESET_SHIFT)                 /* 0x00000004 */
#define PMUCRU_HPLL_CON3_SSMOD_DOWNSPREAD_SHIFT            (3U)
#define PMUCRU_HPLL_CON3_SSMOD_DOWNSPREAD_MASK             (0x1U << PMUCRU_HPLL_CON3_SSMOD_DOWNSPREAD_SHIFT)            /* 0x00000008 */
#define PMUCRU_HPLL_CON3_SSMOD_DIVVAL_SHIFT                (4U)
#define PMUCRU_HPLL_CON3_SSMOD_DIVVAL_MASK                 (0xFU << PMUCRU_HPLL_CON3_SSMOD_DIVVAL_SHIFT)                /* 0x000000F0 */
#define PMUCRU_HPLL_CON3_SSMOD_SPREAD_SHIFT                (8U)
#define PMUCRU_HPLL_CON3_SSMOD_SPREAD_MASK                 (0x1FU << PMUCRU_HPLL_CON3_SSMOD_SPREAD_SHIFT)               /* 0x00001F00 */
/* HPLL_CON4 */
#define PMUCRU_HPLL_CON4_OFFSET                            (0x30U)
#define PMUCRU_HPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT          (0U)
#define PMUCRU_HPLL_CON4_SSMOD_SEL_EXT_WAVE_MASK           (0x1U << PMUCRU_HPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)          /* 0x00000001 */
#define PMUCRU_HPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT           (8U)
#define PMUCRU_HPLL_CON4_SSMOD_EXT_MAXADDR_MASK            (0xFFU << PMUCRU_HPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)          /* 0x0000FF00 */
/* MODE_CON00 */
#define PMUCRU_MODE_CON00_OFFSET                           (0x80U)
#define PMUCRU_MODE_CON00_CLK_PPLL_MODE_SHIFT              (0U)
#define PMUCRU_MODE_CON00_CLK_PPLL_MODE_MASK               (0x3U << PMUCRU_MODE_CON00_CLK_PPLL_MODE_SHIFT)              /* 0x00000003 */
#define PMUCRU_MODE_CON00_CLK_HPLL_MODE_SHIFT              (2U)
#define PMUCRU_MODE_CON00_CLK_HPLL_MODE_MASK               (0x3U << PMUCRU_MODE_CON00_CLK_HPLL_MODE_SHIFT)              /* 0x0000000C */
/* PMUCLKSEL_CON00 */
#define PMUCRU_PMUCLKSEL_CON00_OFFSET                      (0x100U)
#define PMUCRU_PMUCLKSEL_CON00_XIN_OSC0_DIV_DIV_SHIFT      (0U)
#define PMUCRU_PMUCLKSEL_CON00_XIN_OSC0_DIV_DIV_MASK       (0x1FU << PMUCRU_PMUCLKSEL_CON00_XIN_OSC0_DIV_DIV_SHIFT)     /* 0x0000001F */
#define PMUCRU_PMUCLKSEL_CON00_CLK_RTC_32K_SEL_SHIFT       (6U)
#define PMUCRU_PMUCLKSEL_CON00_CLK_RTC_32K_SEL_MASK        (0x3U << PMUCRU_PMUCLKSEL_CON00_CLK_RTC_32K_SEL_SHIFT)       /* 0x000000C0 */
/* PMUCLKSEL_CON01 */
#define PMUCRU_PMUCLKSEL_CON01_OFFSET                      (0x104U)
#define PMUCRU_PMUCLKSEL_CON01_CLK_OSC0_DIV32K_DIV_SHIFT   (0U)
#define PMUCRU_PMUCLKSEL_CON01_CLK_OSC0_DIV32K_DIV_MASK    (0xFFFFFFFFU << PMUCRU_PMUCLKSEL_CON01_CLK_OSC0_DIV32K_DIV_SHIFT) /* 0xFFFFFFFF */
/* PMUCLKSEL_CON02 */
#define PMUCRU_PMUCLKSEL_CON02_OFFSET                      (0x108U)
#define PMUCRU_PMUCLKSEL_CON02_PCLK_PDPMU_PRE_DIV_SHIFT    (0U)
#define PMUCRU_PMUCLKSEL_CON02_PCLK_PDPMU_PRE_DIV_MASK     (0x1FU << PMUCRU_PMUCLKSEL_CON02_PCLK_PDPMU_PRE_DIV_SHIFT)   /* 0x0000001F */
#define PMUCRU_PMUCLKSEL_CON02_CLK_PDPMU_MUX_SEL_SHIFT     (15U)
#define PMUCRU_PMUCLKSEL_CON02_CLK_PDPMU_MUX_SEL_MASK      (0x1U << PMUCRU_PMUCLKSEL_CON02_CLK_PDPMU_MUX_SEL_SHIFT)     /* 0x00008000 */
/* PMUCLKSEL_CON03 */
#define PMUCRU_PMUCLKSEL_CON03_OFFSET                      (0x10CU)
#define PMUCRU_PMUCLKSEL_CON03_CLK_I2C0_DIV_SHIFT          (0U)
#define PMUCRU_PMUCLKSEL_CON03_CLK_I2C0_DIV_MASK           (0x7FU << PMUCRU_PMUCLKSEL_CON03_CLK_I2C0_DIV_SHIFT)         /* 0x0000007F */
/* PMUCLKSEL_CON04 */
#define PMUCRU_PMUCLKSEL_CON04_OFFSET                      (0x110U)
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_DIV_SHIFT    (0U)
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_DIV_MASK     (0x7FU << PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_DIV_SHIFT)   /* 0x0000007F */
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_SEL_SHIFT    (8U)
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_SEL_MASK     (0x3U << PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_DIV_SEL_SHIFT)    /* 0x00000300 */
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_SEL_SHIFT        (10U)
#define PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_SEL_MASK         (0x3U << PMUCRU_PMUCLKSEL_CON04_SCLK_UART0_SEL_SHIFT)        /* 0x00000C00 */
/* PMUCLKSEL_CON05 */
#define PMUCRU_PMUCLKSEL_CON05_OFFSET                      (0x114U)
#define PMUCRU_PMUCLKSEL_CON05_SCLK_UART0_FRACDIV_DIV_SHIFT (0U)
#define PMUCRU_PMUCLKSEL_CON05_SCLK_UART0_FRACDIV_DIV_MASK (0xFFFFFFFFU << PMUCRU_PMUCLKSEL_CON05_SCLK_UART0_FRACDIV_DIV_SHIFT) /* 0xFFFFFFFF */
/* PMUCLKSEL_CON06 */
#define PMUCRU_PMUCLKSEL_CON06_OFFSET                      (0x118U)
#define PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_DIV_SHIFT          (0U)
#define PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_DIV_MASK           (0x7FU << PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_DIV_SHIFT)         /* 0x0000007F */
#define PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_SEL_SHIFT          (7U)
#define PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_SEL_MASK           (0x1U << PMUCRU_PMUCLKSEL_CON06_CLK_PWM0_SEL_SHIFT)          /* 0x00000080 */
#define PMUCRU_PMUCLKSEL_CON06_DBCLK_GPIO0_SEL_SHIFT       (15U)
#define PMUCRU_PMUCLKSEL_CON06_DBCLK_GPIO0_SEL_MASK        (0x1U << PMUCRU_PMUCLKSEL_CON06_DBCLK_GPIO0_SEL_SHIFT)       /* 0x00008000 */
/* PMUCLKSEL_CON07 */
#define PMUCRU_PMUCLKSEL_CON07_OFFSET                      (0x11CU)
#define PMUCRU_PMUCLKSEL_CON07_CLK_REF24M_DIV_SHIFT        (0U)
#define PMUCRU_PMUCLKSEL_CON07_CLK_REF24M_DIV_MASK         (0x3FU << PMUCRU_PMUCLKSEL_CON07_CLK_REF24M_DIV_SHIFT)       /* 0x0000003F */
/* PMUCLKSEL_CON08 */
#define PMUCRU_PMUCLKSEL_CON08_OFFSET                      (0x120U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY0_REF_SEL_SHIFT   (0U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY0_REF_SEL_MASK    (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY0_REF_SEL_SHIFT)   /* 0x00000001 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY1_REF_SEL_SHIFT   (1U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY1_REF_SEL_MASK    (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_USBPHY1_REF_SEL_SHIFT)   /* 0x00000002 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY0_REF_SEL_SHIFT (2U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY0_REF_SEL_MASK (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY0_REF_SEL_SHIFT) /* 0x00000004 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY1_REF_SEL_SHIFT (3U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY1_REF_SEL_MASK (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_MIPIDSIPHY1_REF_SEL_SHIFT) /* 0x00000008 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_HDMIPHY_REF_SEL_SHIFT   (7U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_HDMIPHY_REF_SEL_MASK    (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_HDMIPHY_REF_SEL_SHIFT)   /* 0x00000080 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_DIV_DIV_SHIFT      (8U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_DIV_DIV_MASK       (0x3FU << PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_DIV_DIV_SHIFT)     /* 0x00003F00 */
#define PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_SEL_SHIFT          (15U)
#define PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_SEL_MASK           (0x1U << PMUCRU_PMUCLKSEL_CON08_CLK_WIFI_SEL_SHIFT)          /* 0x00008000 */
/* PMUCLKSEL_CON09 */
#define PMUCRU_PMUCLKSEL_CON09_OFFSET                      (0x124U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_DIV_DIV_SHIFT  (0U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_DIV_DIV_MASK   (0x7U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_DIV_DIV_SHIFT)  /* 0x00000007 */
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_REF_SEL_SHIFT  (3U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_REF_SEL_MASK   (0x1U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY0_REF_SEL_SHIFT)  /* 0x00000008 */
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_DIV_DIV_SHIFT  (4U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_DIV_DIV_MASK   (0x7U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_DIV_DIV_SHIFT)  /* 0x00000070 */
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_REF_SEL_SHIFT  (7U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_REF_SEL_MASK   (0x1U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY1_REF_SEL_SHIFT)  /* 0x00000080 */
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_DIV_DIV_SHIFT  (8U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_DIV_DIV_MASK   (0x7U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_DIV_DIV_SHIFT)  /* 0x00000700 */
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_REF_SEL_SHIFT  (11U)
#define PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_REF_SEL_MASK   (0x1U << PMUCRU_PMUCLKSEL_CON09_CLK_PCIEPHY2_REF_SEL_SHIFT)  /* 0x00000800 */
/* PMUGATE_CON00 */
#define PMUCRU_PMUGATE_CON00_OFFSET                        (0x180U)
#define PMUCRU_PMUGATE_CON00_XIN_OSC0_DIV_EN_SHIFT         (0U)
#define PMUCRU_PMUGATE_CON00_XIN_OSC0_DIV_EN_MASK          (0x1U << PMUCRU_PMUGATE_CON00_XIN_OSC0_DIV_EN_SHIFT)         /* 0x00000001 */
#define PMUCRU_PMUGATE_CON00_CLK_OSC0_DIV32K_EN_SHIFT      (1U)
#define PMUCRU_PMUGATE_CON00_CLK_OSC0_DIV32K_EN_MASK       (0x1U << PMUCRU_PMUGATE_CON00_CLK_OSC0_DIV32K_EN_SHIFT)      /* 0x00000002 */
#define PMUCRU_PMUGATE_CON00_PCLK_PDPMU_EN_SHIFT           (2U)
#define PMUCRU_PMUGATE_CON00_PCLK_PDPMU_EN_MASK            (0x1U << PMUCRU_PMUGATE_CON00_PCLK_PDPMU_EN_SHIFT)           /* 0x00000004 */
#define PMUCRU_PMUGATE_CON00_PCLK_PDPMU_NIU_EN_SHIFT       (3U)
#define PMUCRU_PMUGATE_CON00_PCLK_PDPMU_NIU_EN_MASK        (0x1U << PMUCRU_PMUGATE_CON00_PCLK_PDPMU_NIU_EN_SHIFT)       /* 0x00000008 */
#define PMUCRU_PMUGATE_CON00_PCLK_PMUCRU_EN_SHIFT          (4U)
#define PMUCRU_PMUGATE_CON00_PCLK_PMUCRU_EN_MASK           (0x1U << PMUCRU_PMUGATE_CON00_PCLK_PMUCRU_EN_SHIFT)          /* 0x00000010 */
#define PMUCRU_PMUGATE_CON00_PCLK_PMUGRF_EN_SHIFT          (5U)
#define PMUCRU_PMUGATE_CON00_PCLK_PMUGRF_EN_MASK           (0x1U << PMUCRU_PMUGATE_CON00_PCLK_PMUGRF_EN_SHIFT)          /* 0x00000020 */
#define PMUCRU_PMUGATE_CON00_PCLK_PMU_EN_SHIFT             (6U)
#define PMUCRU_PMUGATE_CON00_PCLK_PMU_EN_MASK              (0x1U << PMUCRU_PMUGATE_CON00_PCLK_PMU_EN_SHIFT)             /* 0x00000040 */
#define PMUCRU_PMUGATE_CON00_CLK_PMU_EN_SHIFT              (7U)
#define PMUCRU_PMUGATE_CON00_CLK_PMU_EN_MASK               (0x1U << PMUCRU_PMUGATE_CON00_CLK_PMU_EN_SHIFT)              /* 0x00000080 */
/* PMUGATE_CON01 */
#define PMUCRU_PMUGATE_CON01_OFFSET                        (0x184U)
#define PMUCRU_PMUGATE_CON01_PCLK_I2C0_EN_SHIFT            (0U)
#define PMUCRU_PMUGATE_CON01_PCLK_I2C0_EN_MASK             (0x1U << PMUCRU_PMUGATE_CON01_PCLK_I2C0_EN_SHIFT)            /* 0x00000001 */
#define PMUCRU_PMUGATE_CON01_CLK_I2C0_EN_SHIFT             (1U)
#define PMUCRU_PMUGATE_CON01_CLK_I2C0_EN_MASK              (0x1U << PMUCRU_PMUGATE_CON01_CLK_I2C0_EN_SHIFT)             /* 0x00000002 */
#define PMUCRU_PMUGATE_CON01_PCLK_UART0_EN_SHIFT           (2U)
#define PMUCRU_PMUGATE_CON01_PCLK_UART0_EN_MASK            (0x1U << PMUCRU_PMUGATE_CON01_PCLK_UART0_EN_SHIFT)           /* 0x00000004 */
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_DIV_EN_SHIFT       (3U)
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_DIV_EN_MASK        (0x1U << PMUCRU_PMUGATE_CON01_SCLK_UART0_DIV_EN_SHIFT)       /* 0x00000008 */
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_FRACDIV_EN_SHIFT   (4U)
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_FRACDIV_EN_MASK    (0x1U << PMUCRU_PMUGATE_CON01_SCLK_UART0_FRACDIV_EN_SHIFT)   /* 0x00000010 */
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_EN_SHIFT           (5U)
#define PMUCRU_PMUGATE_CON01_SCLK_UART0_EN_MASK            (0x1U << PMUCRU_PMUGATE_CON01_SCLK_UART0_EN_SHIFT)           /* 0x00000020 */
#define PMUCRU_PMUGATE_CON01_PCLK_PWM0_EN_SHIFT            (6U)
#define PMUCRU_PMUGATE_CON01_PCLK_PWM0_EN_MASK             (0x1U << PMUCRU_PMUGATE_CON01_PCLK_PWM0_EN_SHIFT)            /* 0x00000040 */
#define PMUCRU_PMUGATE_CON01_CLK_PWM0_EN_SHIFT             (7U)
#define PMUCRU_PMUGATE_CON01_CLK_PWM0_EN_MASK              (0x1U << PMUCRU_PMUGATE_CON01_CLK_PWM0_EN_SHIFT)             /* 0x00000080 */
#define PMUCRU_PMUGATE_CON01_CLK_CAPTURE_PWM0_EN_SHIFT     (8U)
#define PMUCRU_PMUGATE_CON01_CLK_CAPTURE_PWM0_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON01_CLK_CAPTURE_PWM0_EN_SHIFT)     /* 0x00000100 */
#define PMUCRU_PMUGATE_CON01_PCLK_GPIO0_EN_SHIFT           (9U)
#define PMUCRU_PMUGATE_CON01_PCLK_GPIO0_EN_MASK            (0x1U << PMUCRU_PMUGATE_CON01_PCLK_GPIO0_EN_SHIFT)           /* 0x00000200 */
#define PMUCRU_PMUGATE_CON01_DBCLK_GPIO0_EN_SHIFT          (10U)
#define PMUCRU_PMUGATE_CON01_DBCLK_GPIO0_EN_MASK           (0x1U << PMUCRU_PMUGATE_CON01_DBCLK_GPIO0_EN_SHIFT)          /* 0x00000400 */
#define PMUCRU_PMUGATE_CON01_PCLK_PMUPVTM_EN_SHIFT         (11U)
#define PMUCRU_PMUGATE_CON01_PCLK_PMUPVTM_EN_MASK          (0x1U << PMUCRU_PMUGATE_CON01_PCLK_PMUPVTM_EN_SHIFT)         /* 0x00000800 */
#define PMUCRU_PMUGATE_CON01_CLK_PMUPVTM_EN_SHIFT          (12U)
#define PMUCRU_PMUGATE_CON01_CLK_PMUPVTM_EN_MASK           (0x1U << PMUCRU_PMUGATE_CON01_CLK_PMUPVTM_EN_SHIFT)          /* 0x00001000 */
#define PMUCRU_PMUGATE_CON01_CLK_CORE_PMUPVTM_EN_SHIFT     (13U)
#define PMUCRU_PMUGATE_CON01_CLK_CORE_PMUPVTM_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON01_CLK_CORE_PMUPVTM_EN_SHIFT)     /* 0x00002000 */
/* PMUGATE_CON02 */
#define PMUCRU_PMUGATE_CON02_OFFSET                        (0x188U)
#define PMUCRU_PMUGATE_CON02_CLK_REF24M_EN_SHIFT           (0U)
#define PMUCRU_PMUGATE_CON02_CLK_REF24M_EN_MASK            (0x1U << PMUCRU_PMUGATE_CON02_CLK_REF24M_EN_SHIFT)           /* 0x00000001 */
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY0_EN_SHIFT     (1U)
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY0_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY0_EN_SHIFT)     /* 0x00000002 */
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY1_EN_SHIFT     (2U)
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY1_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON02_XIN_OSC0_USBPHY1_EN_SHIFT)     /* 0x00000004 */
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY0_EN_SHIFT (3U)
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY0_EN_MASK  (0x1U << PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY0_EN_SHIFT) /* 0x00000008 */
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY1_EN_SHIFT (4U)
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY1_EN_MASK  (0x1U << PMUCRU_PMUGATE_CON02_XIN_OSC0_MIPIDSIPHY1_EN_SHIFT) /* 0x00000010 */
#define PMUCRU_PMUGATE_CON02_CLK_WIFI_DIV_EN_SHIFT         (5U)
#define PMUCRU_PMUGATE_CON02_CLK_WIFI_DIV_EN_MASK          (0x1U << PMUCRU_PMUGATE_CON02_CLK_WIFI_DIV_EN_SHIFT)         /* 0x00000020 */
#define PMUCRU_PMUGATE_CON02_CLK_WIFI_OSC0_EN_SHIFT        (6U)
#define PMUCRU_PMUGATE_CON02_CLK_WIFI_OSC0_EN_MASK         (0x1U << PMUCRU_PMUGATE_CON02_CLK_WIFI_OSC0_EN_SHIFT)        /* 0x00000040 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_DIV_EN_SHIFT     (7U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_DIV_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_DIV_EN_SHIFT)     /* 0x00000080 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_OSC0_EN_SHIFT    (8U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_OSC0_EN_MASK     (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY0_OSC0_EN_SHIFT)    /* 0x00000100 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_DIV_EN_SHIFT     (9U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_DIV_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_DIV_EN_SHIFT)     /* 0x00000200 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_OSC0_EN_SHIFT    (10U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_OSC0_EN_MASK     (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY1_OSC0_EN_SHIFT)    /* 0x00000400 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_DIV_EN_SHIFT     (11U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_DIV_EN_MASK      (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_DIV_EN_SHIFT)     /* 0x00000800 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_OSC0_EN_SHIFT    (12U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_OSC0_EN_MASK     (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIEPHY2_OSC0_EN_SHIFT)    /* 0x00001000 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_M_EN_SHIFT  (13U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_M_EN_MASK   (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_M_EN_SHIFT)  /* 0x00002000 */
#define PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_N_EN_SHIFT  (14U)
#define PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_N_EN_MASK   (0x1U << PMUCRU_PMUGATE_CON02_CLK_PCIE30PHY_REF_N_EN_SHIFT)  /* 0x00004000 */
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_EDPPHY_EN_SHIFT      (15U)
#define PMUCRU_PMUGATE_CON02_XIN_OSC0_EDPPHY_EN_MASK       (0x1U << PMUCRU_PMUGATE_CON02_XIN_OSC0_EDPPHY_EN_SHIFT)      /* 0x00008000 */
/* PMUSOFTRST_CON00 */
#define PMUCRU_PMUSOFTRST_CON00_OFFSET                     (0x200U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PDPMU_NIU_SHIFT    (0U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PDPMU_NIU_MASK     (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_PDPMU_NIU_SHIFT)    /* 0x00000001 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUCRU_SHIFT       (1U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUCRU_MASK        (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUCRU_SHIFT)       /* 0x00000002 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUGRF_SHIFT       (2U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUGRF_MASK        (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUGRF_SHIFT)       /* 0x00000004 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_I2C0_SHIFT         (3U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_I2C0_MASK          (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_I2C0_SHIFT)         /* 0x00000008 */
#define PMUCRU_PMUSOFTRST_CON00_RESETN_I2C0_SHIFT          (4U)
#define PMUCRU_PMUSOFTRST_CON00_RESETN_I2C0_MASK           (0x1U << PMUCRU_PMUSOFTRST_CON00_RESETN_I2C0_SHIFT)          /* 0x00000010 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_UART0_SHIFT        (5U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_UART0_MASK         (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_UART0_SHIFT)        /* 0x00000020 */
#define PMUCRU_PMUSOFTRST_CON00_SRESETN_UART0_SHIFT        (6U)
#define PMUCRU_PMUSOFTRST_CON00_SRESETN_UART0_MASK         (0x1U << PMUCRU_PMUSOFTRST_CON00_SRESETN_UART0_SHIFT)        /* 0x00000040 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PWM0_SHIFT         (7U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PWM0_MASK          (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_PWM0_SHIFT)         /* 0x00000080 */
#define PMUCRU_PMUSOFTRST_CON00_RESETN_PWM0_SHIFT          (8U)
#define PMUCRU_PMUSOFTRST_CON00_RESETN_PWM0_MASK           (0x1U << PMUCRU_PMUSOFTRST_CON00_RESETN_PWM0_SHIFT)          /* 0x00000100 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_GPIO0_SHIFT        (9U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_GPIO0_MASK         (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_GPIO0_SHIFT)        /* 0x00000200 */
#define PMUCRU_PMUSOFTRST_CON00_DBRESETN_GPIO0_SHIFT       (10U)
#define PMUCRU_PMUSOFTRST_CON00_DBRESETN_GPIO0_MASK        (0x1U << PMUCRU_PMUSOFTRST_CON00_DBRESETN_GPIO0_SHIFT)       /* 0x00000400 */
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUPVTM_SHIFT      (11U)
#define PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUPVTM_MASK       (0x1U << PMUCRU_PMUSOFTRST_CON00_PRESETN_PMUPVTM_SHIFT)      /* 0x00000800 */
#define PMUCRU_PMUSOFTRST_CON00_RESETN_PMUPVTM_SHIFT       (12U)
#define PMUCRU_PMUSOFTRST_CON00_RESETN_PMUPVTM_MASK        (0x1U << PMUCRU_PMUSOFTRST_CON00_RESETN_PMUPVTM_SHIFT)       /* 0x00001000 */
/******************************************CRU*******************************************/
/* APLL_CON0 */
#define CRU_APLL_CON0_OFFSET                               (0x0U)
#define CRU_APLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_APLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_APLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_APLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_APLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_APLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_APLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_APLL_CON0_BYPASS_MASK                          (0x1U << CRU_APLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* APLL_CON1 */
#define CRU_APLL_CON1_OFFSET                               (0x4U)
#define CRU_APLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_APLL_CON1_REFDIV_MASK                          (0x3FU << CRU_APLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_APLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_APLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_APLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_APLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_APLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_APLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_APLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_APLL_CON1_DSMPD_MASK                           (0x1U << CRU_APLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_APLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_APLL_CON1_PLLPD0_MASK                          (0x1U << CRU_APLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_APLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_APLL_CON1_PLLPD1_MASK                          (0x1U << CRU_APLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_APLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_APLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_APLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* APLL_CON2 */
#define CRU_APLL_CON2_OFFSET                               (0x8U)
#define CRU_APLL_CON2_FRACDIV_SHIFT                        (0U)
#define CRU_APLL_CON2_FRACDIV_MASK                         (0xFFFFFFU << CRU_APLL_CON2_FRACDIV_SHIFT)                   /* 0x00FFFFFF */
#define CRU_APLL_CON2_DACPD_SHIFT                          (24U)
#define CRU_APLL_CON2_DACPD_MASK                           (0x1U << CRU_APLL_CON2_DACPD_SHIFT)                          /* 0x01000000 */
#define CRU_APLL_CON2_FOUTPOSTDIVPD_SHIFT                  (25U)
#define CRU_APLL_CON2_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_APLL_CON2_FOUTPOSTDIVPD_SHIFT)                  /* 0x02000000 */
#define CRU_APLL_CON2_FOUTVCOPD_SHIFT                      (26U)
#define CRU_APLL_CON2_FOUTVCOPD_MASK                       (0x1U << CRU_APLL_CON2_FOUTVCOPD_SHIFT)                      /* 0x04000000 */
#define CRU_APLL_CON2_FOUT4PHASEPD_SHIFT                   (27U)
#define CRU_APLL_CON2_FOUT4PHASEPD_MASK                    (0x1U << CRU_APLL_CON2_FOUT4PHASEPD_SHIFT)                   /* 0x08000000 */
/* APLL_CON3 */
#define CRU_APLL_CON3_OFFSET                               (0xCU)
#define CRU_APLL_CON3_SSMOD_BP_SHIFT                       (0U)
#define CRU_APLL_CON3_SSMOD_BP_MASK                        (0x1U << CRU_APLL_CON3_SSMOD_BP_SHIFT)                       /* 0x00000001 */
#define CRU_APLL_CON3_SSMOD_DISABLE_SSCG_SHIFT             (1U)
#define CRU_APLL_CON3_SSMOD_DISABLE_SSCG_MASK              (0x1U << CRU_APLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)             /* 0x00000002 */
#define CRU_APLL_CON3_SSMOD_RESET_SHIFT                    (2U)
#define CRU_APLL_CON3_SSMOD_RESET_MASK                     (0x1U << CRU_APLL_CON3_SSMOD_RESET_SHIFT)                    /* 0x00000004 */
#define CRU_APLL_CON3_SSMOD_DOWNSPREAD_SHIFT               (3U)
#define CRU_APLL_CON3_SSMOD_DOWNSPREAD_MASK                (0x1U << CRU_APLL_CON3_SSMOD_DOWNSPREAD_SHIFT)               /* 0x00000008 */
#define CRU_APLL_CON3_SSMOD_DIVVAL_SHIFT                   (4U)
#define CRU_APLL_CON3_SSMOD_DIVVAL_MASK                    (0xFU << CRU_APLL_CON3_SSMOD_DIVVAL_SHIFT)                   /* 0x000000F0 */
#define CRU_APLL_CON3_SSMOD_SPREAD_SHIFT                   (8U)
#define CRU_APLL_CON3_SSMOD_SPREAD_MASK                    (0x1FU << CRU_APLL_CON3_SSMOD_SPREAD_SHIFT)                  /* 0x00001F00 */
/* APLL_CON4 */
#define CRU_APLL_CON4_OFFSET                               (0x10U)
#define CRU_APLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT             (0U)
#define CRU_APLL_CON4_SSMOD_SEL_EXT_WAVE_MASK              (0x1U << CRU_APLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)             /* 0x00000001 */
#define CRU_APLL_CON4_SSMOD_EXT_MAXADDR_SHIFT              (8U)
#define CRU_APLL_CON4_SSMOD_EXT_MAXADDR_MASK               (0xFFU << CRU_APLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)             /* 0x0000FF00 */
/* DPLL_CON0 */
#define CRU_DPLL_CON0_OFFSET                               (0x20U)
#define CRU_DPLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_DPLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_DPLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_DPLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_DPLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_DPLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_DPLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_DPLL_CON0_BYPASS_MASK                          (0x1U << CRU_DPLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* DPLL_CON1 */
#define CRU_DPLL_CON1_OFFSET                               (0x24U)
#define CRU_DPLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_DPLL_CON1_REFDIV_MASK                          (0x3FU << CRU_DPLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_DPLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_DPLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_DPLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_DPLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_DPLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_DPLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_DPLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_DPLL_CON1_DSMPD_MASK                           (0x1U << CRU_DPLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_DPLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_DPLL_CON1_PLLPD0_MASK                          (0x1U << CRU_DPLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_DPLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_DPLL_CON1_PLLPD1_MASK                          (0x1U << CRU_DPLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_DPLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_DPLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_DPLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* DPLL_CON2 */
#define CRU_DPLL_CON2_OFFSET                               (0x28U)
#define CRU_DPLL_CON2_FRACDIV_SHIFT                        (0U)
#define CRU_DPLL_CON2_FRACDIV_MASK                         (0xFFFFFFU << CRU_DPLL_CON2_FRACDIV_SHIFT)                   /* 0x00FFFFFF */
#define CRU_DPLL_CON2_DACPD_SHIFT                          (24U)
#define CRU_DPLL_CON2_DACPD_MASK                           (0x1U << CRU_DPLL_CON2_DACPD_SHIFT)                          /* 0x01000000 */
#define CRU_DPLL_CON2_FOUTPOSTDIVPD_SHIFT                  (25U)
#define CRU_DPLL_CON2_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_DPLL_CON2_FOUTPOSTDIVPD_SHIFT)                  /* 0x02000000 */
#define CRU_DPLL_CON2_FOUTVCOPD_SHIFT                      (26U)
#define CRU_DPLL_CON2_FOUTVCOPD_MASK                       (0x1U << CRU_DPLL_CON2_FOUTVCOPD_SHIFT)                      /* 0x04000000 */
#define CRU_DPLL_CON2_FOUT4PHASEPD_SHIFT                   (27U)
#define CRU_DPLL_CON2_FOUT4PHASEPD_MASK                    (0x1U << CRU_DPLL_CON2_FOUT4PHASEPD_SHIFT)                   /* 0x08000000 */
/* DPLL_CON3 */
#define CRU_DPLL_CON3_OFFSET                               (0x2CU)
#define CRU_DPLL_CON3_SSMOD_BP_SHIFT                       (0U)
#define CRU_DPLL_CON3_SSMOD_BP_MASK                        (0x1U << CRU_DPLL_CON3_SSMOD_BP_SHIFT)                       /* 0x00000001 */
#define CRU_DPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT             (1U)
#define CRU_DPLL_CON3_SSMOD_DISABLE_SSCG_MASK              (0x1U << CRU_DPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)             /* 0x00000002 */
#define CRU_DPLL_CON3_SSMOD_RESET_SHIFT                    (2U)
#define CRU_DPLL_CON3_SSMOD_RESET_MASK                     (0x1U << CRU_DPLL_CON3_SSMOD_RESET_SHIFT)                    /* 0x00000004 */
#define CRU_DPLL_CON3_SSMOD_DOWNSPREAD_SHIFT               (3U)
#define CRU_DPLL_CON3_SSMOD_DOWNSPREAD_MASK                (0x1U << CRU_DPLL_CON3_SSMOD_DOWNSPREAD_SHIFT)               /* 0x00000008 */
#define CRU_DPLL_CON3_SSMOD_DIVVAL_SHIFT                   (4U)
#define CRU_DPLL_CON3_SSMOD_DIVVAL_MASK                    (0xFU << CRU_DPLL_CON3_SSMOD_DIVVAL_SHIFT)                   /* 0x000000F0 */
#define CRU_DPLL_CON3_SSMOD_SPREAD_SHIFT                   (8U)
#define CRU_DPLL_CON3_SSMOD_SPREAD_MASK                    (0x1FU << CRU_DPLL_CON3_SSMOD_SPREAD_SHIFT)                  /* 0x00001F00 */
/* DPLL_CON4 */
#define CRU_DPLL_CON4_OFFSET                               (0x30U)
#define CRU_DPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT             (0U)
#define CRU_DPLL_CON4_SSMOD_SEL_EXT_WAVE_MASK              (0x1U << CRU_DPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)             /* 0x00000001 */
#define CRU_DPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT              (8U)
#define CRU_DPLL_CON4_SSMOD_EXT_MAXADDR_MASK               (0xFFU << CRU_DPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)             /* 0x0000FF00 */
/* GPLL_CON0 */
#define CRU_GPLL_CON0_OFFSET                               (0x40U)
#define CRU_GPLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_GPLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_GPLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_GPLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_GPLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_GPLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_GPLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_GPLL_CON0_BYPASS_MASK                          (0x1U << CRU_GPLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* GPLL_CON1 */
#define CRU_GPLL_CON1_OFFSET                               (0x44U)
#define CRU_GPLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_GPLL_CON1_REFDIV_MASK                          (0x3FU << CRU_GPLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_GPLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_GPLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_GPLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_GPLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_GPLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_GPLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_GPLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_GPLL_CON1_DSMPD_MASK                           (0x1U << CRU_GPLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_GPLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_GPLL_CON1_PLLPD0_MASK                          (0x1U << CRU_GPLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_GPLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_GPLL_CON1_PLLPD1_MASK                          (0x1U << CRU_GPLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_GPLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_GPLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_GPLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* GPLL_CON2 */
#define CRU_GPLL_CON2_OFFSET                               (0x48U)
#define CRU_GPLL_CON2_FRACDIV_SHIFT                        (0U)
#define CRU_GPLL_CON2_FRACDIV_MASK                         (0xFFFFFFU << CRU_GPLL_CON2_FRACDIV_SHIFT)                   /* 0x00FFFFFF */
#define CRU_GPLL_CON2_DACPD_SHIFT                          (24U)
#define CRU_GPLL_CON2_DACPD_MASK                           (0x1U << CRU_GPLL_CON2_DACPD_SHIFT)                          /* 0x01000000 */
#define CRU_GPLL_CON2_FOUTPOSTDIVPD_SHIFT                  (25U)
#define CRU_GPLL_CON2_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_GPLL_CON2_FOUTPOSTDIVPD_SHIFT)                  /* 0x02000000 */
#define CRU_GPLL_CON2_FOUTVCOPD_SHIFT                      (26U)
#define CRU_GPLL_CON2_FOUTVCOPD_MASK                       (0x1U << CRU_GPLL_CON2_FOUTVCOPD_SHIFT)                      /* 0x04000000 */
#define CRU_GPLL_CON2_FOUT4PHASEPD_SHIFT                   (27U)
#define CRU_GPLL_CON2_FOUT4PHASEPD_MASK                    (0x1U << CRU_GPLL_CON2_FOUT4PHASEPD_SHIFT)                   /* 0x08000000 */
/* GPLL_CON3 */
#define CRU_GPLL_CON3_OFFSET                               (0x4CU)
#define CRU_GPLL_CON3_SSMOD_BP_SHIFT                       (0U)
#define CRU_GPLL_CON3_SSMOD_BP_MASK                        (0x1U << CRU_GPLL_CON3_SSMOD_BP_SHIFT)                       /* 0x00000001 */
#define CRU_GPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT             (1U)
#define CRU_GPLL_CON3_SSMOD_DISABLE_SSCG_MASK              (0x1U << CRU_GPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)             /* 0x00000002 */
#define CRU_GPLL_CON3_SSMOD_RESET_SHIFT                    (2U)
#define CRU_GPLL_CON3_SSMOD_RESET_MASK                     (0x1U << CRU_GPLL_CON3_SSMOD_RESET_SHIFT)                    /* 0x00000004 */
#define CRU_GPLL_CON3_SSMOD_DOWNSPREAD_SHIFT               (3U)
#define CRU_GPLL_CON3_SSMOD_DOWNSPREAD_MASK                (0x1U << CRU_GPLL_CON3_SSMOD_DOWNSPREAD_SHIFT)               /* 0x00000008 */
#define CRU_GPLL_CON3_SSMOD_DIVVAL_SHIFT                   (4U)
#define CRU_GPLL_CON3_SSMOD_DIVVAL_MASK                    (0xFU << CRU_GPLL_CON3_SSMOD_DIVVAL_SHIFT)                   /* 0x000000F0 */
#define CRU_GPLL_CON3_SSMOD_SPREAD_SHIFT                   (8U)
#define CRU_GPLL_CON3_SSMOD_SPREAD_MASK                    (0x1FU << CRU_GPLL_CON3_SSMOD_SPREAD_SHIFT)                  /* 0x00001F00 */
/* GPLL_CON4 */
#define CRU_GPLL_CON4_OFFSET                               (0x50U)
#define CRU_GPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT             (0U)
#define CRU_GPLL_CON4_SSMOD_SEL_EXT_WAVE_MASK              (0x1U << CRU_GPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)             /* 0x00000001 */
#define CRU_GPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT              (8U)
#define CRU_GPLL_CON4_SSMOD_EXT_MAXADDR_MASK               (0xFFU << CRU_GPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)             /* 0x0000FF00 */
/* CPLL_CON0 */
#define CRU_CPLL_CON0_OFFSET                               (0x60U)
#define CRU_CPLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_CPLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_CPLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_CPLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_CPLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_CPLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_CPLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_CPLL_CON0_BYPASS_MASK                          (0x1U << CRU_CPLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* CPLL_CON1 */
#define CRU_CPLL_CON1_OFFSET                               (0x64U)
#define CRU_CPLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_CPLL_CON1_REFDIV_MASK                          (0x3FU << CRU_CPLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_CPLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_CPLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_CPLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_CPLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_CPLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_CPLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_CPLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_CPLL_CON1_DSMPD_MASK                           (0x1U << CRU_CPLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_CPLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_CPLL_CON1_PLLPD0_MASK                          (0x1U << CRU_CPLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_CPLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_CPLL_CON1_PLLPD1_MASK                          (0x1U << CRU_CPLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_CPLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_CPLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_CPLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* CPLL_CON2 */
#define CRU_CPLL_CON2_OFFSET                               (0x68U)
#define CRU_CPLL_CON2_FRACDIV_SHIFT                        (0U)
#define CRU_CPLL_CON2_FRACDIV_MASK                         (0xFFFFFFU << CRU_CPLL_CON2_FRACDIV_SHIFT)                   /* 0x00FFFFFF */
#define CRU_CPLL_CON2_DACPD_SHIFT                          (24U)
#define CRU_CPLL_CON2_DACPD_MASK                           (0x1U << CRU_CPLL_CON2_DACPD_SHIFT)                          /* 0x01000000 */
#define CRU_CPLL_CON2_FOUTPOSTDIVPD_SHIFT                  (25U)
#define CRU_CPLL_CON2_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_CPLL_CON2_FOUTPOSTDIVPD_SHIFT)                  /* 0x02000000 */
#define CRU_CPLL_CON2_FOUTVCOPD_SHIFT                      (26U)
#define CRU_CPLL_CON2_FOUTVCOPD_MASK                       (0x1U << CRU_CPLL_CON2_FOUTVCOPD_SHIFT)                      /* 0x04000000 */
#define CRU_CPLL_CON2_FOUT4PHASEPD_SHIFT                   (27U)
#define CRU_CPLL_CON2_FOUT4PHASEPD_MASK                    (0x1U << CRU_CPLL_CON2_FOUT4PHASEPD_SHIFT)                   /* 0x08000000 */
/* CPLL_CON3 */
#define CRU_CPLL_CON3_OFFSET                               (0x6CU)
#define CRU_CPLL_CON3_SSMOD_BP_SHIFT                       (0U)
#define CRU_CPLL_CON3_SSMOD_BP_MASK                        (0x1U << CRU_CPLL_CON3_SSMOD_BP_SHIFT)                       /* 0x00000001 */
#define CRU_CPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT             (1U)
#define CRU_CPLL_CON3_SSMOD_DISABLE_SSCG_MASK              (0x1U << CRU_CPLL_CON3_SSMOD_DISABLE_SSCG_SHIFT)             /* 0x00000002 */
#define CRU_CPLL_CON3_SSMOD_RESET_SHIFT                    (2U)
#define CRU_CPLL_CON3_SSMOD_RESET_MASK                     (0x1U << CRU_CPLL_CON3_SSMOD_RESET_SHIFT)                    /* 0x00000004 */
#define CRU_CPLL_CON3_SSMOD_DOWNSPREAD_SHIFT               (3U)
#define CRU_CPLL_CON3_SSMOD_DOWNSPREAD_MASK                (0x1U << CRU_CPLL_CON3_SSMOD_DOWNSPREAD_SHIFT)               /* 0x00000008 */
#define CRU_CPLL_CON3_SSMOD_DIVVAL_SHIFT                   (4U)
#define CRU_CPLL_CON3_SSMOD_DIVVAL_MASK                    (0xFU << CRU_CPLL_CON3_SSMOD_DIVVAL_SHIFT)                   /* 0x000000F0 */
#define CRU_CPLL_CON3_SSMOD_SPREAD_SHIFT                   (8U)
#define CRU_CPLL_CON3_SSMOD_SPREAD_MASK                    (0x1FU << CRU_CPLL_CON3_SSMOD_SPREAD_SHIFT)                  /* 0x00001F00 */
/* CPLL_CON4 */
#define CRU_CPLL_CON4_OFFSET                               (0x70U)
#define CRU_CPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT             (0U)
#define CRU_CPLL_CON4_SSMOD_SEL_EXT_WAVE_MASK              (0x1U << CRU_CPLL_CON4_SSMOD_SEL_EXT_WAVE_SHIFT)             /* 0x00000001 */
#define CRU_CPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT              (8U)
#define CRU_CPLL_CON4_SSMOD_EXT_MAXADDR_MASK               (0xFFU << CRU_CPLL_CON4_SSMOD_EXT_MAXADDR_SHIFT)             /* 0x0000FF00 */
/* NPLL_CON0 */
#define CRU_NPLL_CON0_OFFSET                               (0x80U)
#define CRU_NPLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_NPLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_NPLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_NPLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_NPLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_NPLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_NPLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_NPLL_CON0_BYPASS_MASK                          (0x1U << CRU_NPLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* NPLL_CON1 */
#define CRU_NPLL_CON1_OFFSET                               (0x84U)
#define CRU_NPLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_NPLL_CON1_REFDIV_MASK                          (0x3FU << CRU_NPLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_NPLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_NPLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_NPLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_NPLL_CON1_FOUTPOSTDIVPD_SHIFT                  (9U)
#define CRU_NPLL_CON1_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_NPLL_CON1_FOUTPOSTDIVPD_SHIFT)                  /* 0x00000200 */
#define CRU_NPLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_NPLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_NPLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_NPLL_CON1_FOUTVCOPD_SHIFT                      (11U)
#define CRU_NPLL_CON1_FOUTVCOPD_MASK                       (0x1U << CRU_NPLL_CON1_FOUTVCOPD_SHIFT)                      /* 0x00000800 */
#define CRU_NPLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_NPLL_CON1_DSMPD_MASK                           (0x1U << CRU_NPLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_NPLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_NPLL_CON1_PLLPD0_MASK                          (0x1U << CRU_NPLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_NPLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_NPLL_CON1_PLLPD1_MASK                          (0x1U << CRU_NPLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_NPLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_NPLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_NPLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* VPLL_CON0 */
#define CRU_VPLL_CON0_OFFSET                               (0xA0U)
#define CRU_VPLL_CON0_FBDIV_SHIFT                          (0U)
#define CRU_VPLL_CON0_FBDIV_MASK                           (0xFFFU << CRU_VPLL_CON0_FBDIV_SHIFT)                        /* 0x00000FFF */
#define CRU_VPLL_CON0_POSTDIV1_SHIFT                       (12U)
#define CRU_VPLL_CON0_POSTDIV1_MASK                        (0x7U << CRU_VPLL_CON0_POSTDIV1_SHIFT)                       /* 0x00007000 */
#define CRU_VPLL_CON0_BYPASS_SHIFT                         (15U)
#define CRU_VPLL_CON0_BYPASS_MASK                          (0x1U << CRU_VPLL_CON0_BYPASS_SHIFT)                         /* 0x00008000 */
/* VPLL_CON1 */
#define CRU_VPLL_CON1_OFFSET                               (0xA4U)
#define CRU_VPLL_CON1_REFDIV_SHIFT                         (0U)
#define CRU_VPLL_CON1_REFDIV_MASK                          (0x3FU << CRU_VPLL_CON1_REFDIV_SHIFT)                        /* 0x0000003F */
#define CRU_VPLL_CON1_POSTDIV2_SHIFT                       (6U)
#define CRU_VPLL_CON1_POSTDIV2_MASK                        (0x7U << CRU_VPLL_CON1_POSTDIV2_SHIFT)                       /* 0x000001C0 */
#define CRU_VPLL_CON1_FOUTPOSTDIVPD_SHIFT                  (9U)
#define CRU_VPLL_CON1_FOUTPOSTDIVPD_MASK                   (0x1U << CRU_VPLL_CON1_FOUTPOSTDIVPD_SHIFT)                  /* 0x00000200 */
#define CRU_VPLL_CON1_PLL_LOCK_SHIFT                       (10U)
#define CRU_VPLL_CON1_PLL_LOCK_MASK                        (0x1U << CRU_VPLL_CON1_PLL_LOCK_SHIFT)                       /* 0x00000400 */
#define CRU_VPLL_CON1_FOUTVCOPD_SHIFT                      (11U)
#define CRU_VPLL_CON1_FOUTVCOPD_MASK                       (0x1U << CRU_VPLL_CON1_FOUTVCOPD_SHIFT)                      /* 0x00000800 */
#define CRU_VPLL_CON1_DSMPD_SHIFT                          (12U)
#define CRU_VPLL_CON1_DSMPD_MASK                           (0x1U << CRU_VPLL_CON1_DSMPD_SHIFT)                          /* 0x00001000 */
#define CRU_VPLL_CON1_PLLPD0_SHIFT                         (13U)
#define CRU_VPLL_CON1_PLLPD0_MASK                          (0x1U << CRU_VPLL_CON1_PLLPD0_SHIFT)                         /* 0x00002000 */
#define CRU_VPLL_CON1_PLLPD1_SHIFT                         (14U)
#define CRU_VPLL_CON1_PLLPD1_MASK                          (0x1U << CRU_VPLL_CON1_PLLPD1_SHIFT)                         /* 0x00004000 */
#define CRU_VPLL_CON1_PLLPDSEL_SHIFT                       (15U)
#define CRU_VPLL_CON1_PLLPDSEL_MASK                        (0x1U << CRU_VPLL_CON1_PLLPDSEL_SHIFT)                       /* 0x00008000 */
/* MODE_CON00 */
#define CRU_MODE_CON00_OFFSET                              (0xC0U)
#define CRU_MODE_CON00_CLK_APLL_MODE_SHIFT                 (0U)
#define CRU_MODE_CON00_CLK_APLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_APLL_MODE_SHIFT)                 /* 0x00000003 */
#define CRU_MODE_CON00_CLK_DPLL_MODE_SHIFT                 (2U)
#define CRU_MODE_CON00_CLK_DPLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_DPLL_MODE_SHIFT)                 /* 0x0000000C */
#define CRU_MODE_CON00_CLK_CPLL_MODE_SHIFT                 (4U)
#define CRU_MODE_CON00_CLK_CPLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_CPLL_MODE_SHIFT)                 /* 0x00000030 */
#define CRU_MODE_CON00_CLK_GPLL_MODE_SHIFT                 (6U)
#define CRU_MODE_CON00_CLK_GPLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_GPLL_MODE_SHIFT)                 /* 0x000000C0 */
#define CRU_MODE_CON00_CLK_NPLL_MODE_SHIFT                 (10U)
#define CRU_MODE_CON00_CLK_NPLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_NPLL_MODE_SHIFT)                 /* 0x00000C00 */
#define CRU_MODE_CON00_CLK_VPLL_MODE_SHIFT                 (12U)
#define CRU_MODE_CON00_CLK_VPLL_MODE_MASK                  (0x3U << CRU_MODE_CON00_CLK_VPLL_MODE_SHIFT)                 /* 0x00003000 */
#define CRU_MODE_CON00_USBPHY480M_PLL_MODE_SHIFT           (14U)
#define CRU_MODE_CON00_USBPHY480M_PLL_MODE_MASK            (0x3U << CRU_MODE_CON00_USBPHY480M_PLL_MODE_SHIFT)           /* 0x0000C000 */
/* MISC_CON0 */
#define CRU_MISC_CON0_OFFSET                               (0xC4U)
#define CRU_MISC_CON0_QCHANNEL_ENA_SCLK_CORE_SHIFT         (0U)
#define CRU_MISC_CON0_QCHANNEL_ENA_SCLK_CORE_MASK          (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_SCLK_CORE_SHIFT)         /* 0x00000001 */
#define CRU_MISC_CON0_QCHANNEL_ENA_PCLK_CORE_SHIFT         (1U)
#define CRU_MISC_CON0_QCHANNEL_ENA_PCLK_CORE_MASK          (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_PCLK_CORE_SHIFT)         /* 0x00000002 */
#define CRU_MISC_CON0_QCHANNEL_ENA_ATCLK_CORE_SHIFT        (2U)
#define CRU_MISC_CON0_QCHANNEL_ENA_ATCLK_CORE_MASK         (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_ATCLK_CORE_SHIFT)        /* 0x00000004 */
#define CRU_MISC_CON0_QCHANNEL_ENA_GICCLK_CORE_SHIFT       (3U)
#define CRU_MISC_CON0_QCHANNEL_ENA_GICCLK_CORE_MASK        (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_GICCLK_CORE_SHIFT)       /* 0x00000008 */
#define CRU_MISC_CON0_QCHANNEL_ENA_PDBGCLK_CORE_SHIFT      (4U)
#define CRU_MISC_CON0_QCHANNEL_ENA_PDBGCLK_CORE_MASK       (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_PDBGCLK_CORE_SHIFT)      /* 0x00000010 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_GPU_SHIFT           (5U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_GPU_MASK            (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_GPU_SHIFT)           /* 0x00000020 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_CORE2GIC_SHIFT (6U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_CORE2GIC_MASK (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_CORE2GIC_SHIFT) /* 0x00000040 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_GIC2CORE_SHIFT (7U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_GIC2CORE_MASK (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDCORE_GIC2CORE_SHIFT) /* 0x00000080 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_CORE2GIC_SHIFT (8U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_CORE2GIC_MASK (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_CORE2GIC_SHIFT) /* 0x00000100 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_GIC2CORE_SHIFT (9U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_GIC2CORE_MASK (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_PDGIC_GIC2CORE_SHIFT) /* 0x00000200 */
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_GIC600_SHIFT        (10U)
#define CRU_MISC_CON0_QCHANNEL_ENA_CLK_GIC600_MASK         (0x1U << CRU_MISC_CON0_QCHANNEL_ENA_CLK_GIC600_SHIFT)        /* 0x00000400 */
#define CRU_MISC_CON0_QCHANNEL_GATING_ENABLE_SHIFT         (11U)
#define CRU_MISC_CON0_QCHANNEL_GATING_ENABLE_MASK          (0x1U << CRU_MISC_CON0_QCHANNEL_GATING_ENABLE_SHIFT)         /* 0x00000800 */
#define CRU_MISC_CON0_DBGRST_EN_SHIFT                      (12U)
#define CRU_MISC_CON0_DBGRST_EN_MASK                       (0x1U << CRU_MISC_CON0_DBGRST_EN_SHIFT)                      /* 0x00001000 */
#define CRU_MISC_CON0_HWFFC_CLK_SWITCH2CRU_ENA_SHIFT       (13U)
#define CRU_MISC_CON0_HWFFC_CLK_SWITCH2CRU_ENA_MASK        (0x1U << CRU_MISC_CON0_HWFFC_CLK_SWITCH2CRU_ENA_SHIFT)       /* 0x00002000 */
#define CRU_MISC_CON0_CPU_CLK_GATE_EMA_ENA_SHIFT           (14U)
#define CRU_MISC_CON0_CPU_CLK_GATE_EMA_ENA_MASK            (0x1U << CRU_MISC_CON0_CPU_CLK_GATE_EMA_ENA_SHIFT)           /* 0x00004000 */
#define CRU_MISC_CON0_GPU_CLK_GATE_EMA_ENA_SHIFT           (15U)
#define CRU_MISC_CON0_GPU_CLK_GATE_EMA_ENA_MASK            (0x1U << CRU_MISC_CON0_GPU_CLK_GATE_EMA_ENA_SHIFT)           /* 0x00008000 */
/* MISC_CON1 */
#define CRU_MISC_CON1_OFFSET                               (0xC8U)
#define CRU_MISC_CON1_PD_CORE_DWN_CLK_EN_MASK_SHIFT        (0U)
#define CRU_MISC_CON1_PD_CORE_DWN_CLK_EN_MASK_MASK         (0x1U << CRU_MISC_CON1_PD_CORE_DWN_CLK_EN_MASK_SHIFT)        /* 0x00000001 */
#define CRU_MISC_CON1_PD_GPU_DWN_CLK_EN_MASK_SHIFT         (1U)
#define CRU_MISC_CON1_PD_GPU_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_GPU_DWN_CLK_EN_MASK_SHIFT)         /* 0x00000002 */
#define CRU_MISC_CON1_PD_NPU_DWN_CLK_EN_MASK_SHIFT         (2U)
#define CRU_MISC_CON1_PD_NPU_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_NPU_DWN_CLK_EN_MASK_SHIFT)         /* 0x00000004 */
#define CRU_MISC_CON1_PD_DDR_DWN_CLK_EN_MASK_SHIFT         (3U)
#define CRU_MISC_CON1_PD_DDR_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_DDR_DWN_CLK_EN_MASK_SHIFT)         /* 0x00000008 */
#define CRU_MISC_CON1_PD_PERI_DWN_CLK_EN_MASK_SHIFT        (4U)
#define CRU_MISC_CON1_PD_PERI_DWN_CLK_EN_MASK_MASK         (0x1U << CRU_MISC_CON1_PD_PERI_DWN_CLK_EN_MASK_SHIFT)        /* 0x00000010 */
#define CRU_MISC_CON1_PD_PIPE_DWN_CLK_EN_MASK_SHIFT        (5U)
#define CRU_MISC_CON1_PD_PIPE_DWN_CLK_EN_MASK_MASK         (0x1U << CRU_MISC_CON1_PD_PIPE_DWN_CLK_EN_MASK_SHIFT)        /* 0x00000020 */
#define CRU_MISC_CON1_PD_USB_DWN_CLK_EN_MASK_SHIFT         (8U)
#define CRU_MISC_CON1_PD_USB_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_USB_DWN_CLK_EN_MASK_SHIFT)         /* 0x00000100 */
#define CRU_MISC_CON1_PD_VI_DWN_CLK_EN_MASK_SHIFT          (9U)
#define CRU_MISC_CON1_PD_VI_DWN_CLK_EN_MASK_MASK           (0x1U << CRU_MISC_CON1_PD_VI_DWN_CLK_EN_MASK_SHIFT)          /* 0x00000200 */
#define CRU_MISC_CON1_PD_VO_DWN_CLK_EN_MASK_SHIFT          (10U)
#define CRU_MISC_CON1_PD_VO_DWN_CLK_EN_MASK_MASK           (0x1U << CRU_MISC_CON1_PD_VO_DWN_CLK_EN_MASK_SHIFT)          /* 0x00000400 */
#define CRU_MISC_CON1_PD_RGA_DWN_CLK_EN_MASK_SHIFT         (11U)
#define CRU_MISC_CON1_PD_RGA_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_RGA_DWN_CLK_EN_MASK_SHIFT)         /* 0x00000800 */
#define CRU_MISC_CON1_PD_VPU_DWN_CLK_EN_MASK_SHIFT         (12U)
#define CRU_MISC_CON1_PD_VPU_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_VPU_DWN_CLK_EN_MASK_SHIFT)         /* 0x00001000 */
#define CRU_MISC_CON1_PD_RKVENC_DWN_CLK_EN_MASK_SHIFT      (13U)
#define CRU_MISC_CON1_PD_RKVENC_DWN_CLK_EN_MASK_MASK       (0x1U << CRU_MISC_CON1_PD_RKVENC_DWN_CLK_EN_MASK_SHIFT)      /* 0x00002000 */
#define CRU_MISC_CON1_PD_RKVDEC_DWN_CLK_EN_MASK_SHIFT      (14U)
#define CRU_MISC_CON1_PD_RKVDEC_DWN_CLK_EN_MASK_MASK       (0x1U << CRU_MISC_CON1_PD_RKVDEC_DWN_CLK_EN_MASK_SHIFT)      /* 0x00004000 */
#define CRU_MISC_CON1_PD_BUS_DWN_CLK_EN_MASK_SHIFT         (15U)
#define CRU_MISC_CON1_PD_BUS_DWN_CLK_EN_MASK_MASK          (0x1U << CRU_MISC_CON1_PD_BUS_DWN_CLK_EN_MASK_SHIFT)         /* 0x00008000 */
/* MISC_CON2 */
#define CRU_MISC_CON2_OFFSET                               (0xCCU)
#define CRU_MISC_CON2_CLK_RGA_CORE_IDLE_ENABLE_SHIFT       (0U)
#define CRU_MISC_CON2_CLK_RGA_CORE_IDLE_ENABLE_MASK        (0x1U << CRU_MISC_CON2_CLK_RGA_CORE_IDLE_ENABLE_SHIFT)       /* 0x00000001 */
#define CRU_MISC_CON2_CLK_IEP_CORE_IDLE_ENABLE_SHIFT       (1U)
#define CRU_MISC_CON2_CLK_IEP_CORE_IDLE_ENABLE_MASK        (0x1U << CRU_MISC_CON2_CLK_IEP_CORE_IDLE_ENABLE_SHIFT)       /* 0x00000002 */
#define CRU_MISC_CON2_ACLK_VPU_IDLE_ENABLE_SHIFT           (2U)
#define CRU_MISC_CON2_ACLK_VPU_IDLE_ENABLE_MASK            (0x1U << CRU_MISC_CON2_ACLK_VPU_IDLE_ENABLE_SHIFT)           /* 0x00000004 */
#define CRU_MISC_CON2_ACLK_RKVENC_IDLE_ENABLE_SHIFT        (3U)
#define CRU_MISC_CON2_ACLK_RKVENC_IDLE_ENABLE_MASK         (0x1U << CRU_MISC_CON2_ACLK_RKVENC_IDLE_ENABLE_SHIFT)        /* 0x00000008 */
#define CRU_MISC_CON2_HCLK_RKVENC_IDLE_ENABLE_SHIFT        (4U)
#define CRU_MISC_CON2_HCLK_RKVENC_IDLE_ENABLE_MASK         (0x1U << CRU_MISC_CON2_HCLK_RKVENC_IDLE_ENABLE_SHIFT)        /* 0x00000010 */
#define CRU_MISC_CON2_CLK_RKVENC_CORE_IDLE_ENABLE_SHIFT    (5U)
#define CRU_MISC_CON2_CLK_RKVENC_CORE_IDLE_ENABLE_MASK     (0x1U << CRU_MISC_CON2_CLK_RKVENC_CORE_IDLE_ENABLE_SHIFT)    /* 0x00000020 */
#define CRU_MISC_CON2_ACLK_RKVDEC_IDLE_ENABLE_SHIFT        (6U)
#define CRU_MISC_CON2_ACLK_RKVDEC_IDLE_ENABLE_MASK         (0x1U << CRU_MISC_CON2_ACLK_RKVDEC_IDLE_ENABLE_SHIFT)        /* 0x00000040 */
#define CRU_MISC_CON2_CLK_RKVDEC_CORE_IDLE_ENABLE_SHIFT    (7U)
#define CRU_MISC_CON2_CLK_RKVDEC_CORE_IDLE_ENABLE_MASK     (0x1U << CRU_MISC_CON2_CLK_RKVDEC_CORE_IDLE_ENABLE_SHIFT)    /* 0x00000080 */
#define CRU_MISC_CON2_CLK_RKVDEC_CA_IDLE_ENABLE_SHIFT      (8U)
#define CRU_MISC_CON2_CLK_RKVDEC_CA_IDLE_ENABLE_MASK       (0x1U << CRU_MISC_CON2_CLK_RKVDEC_CA_IDLE_ENABLE_SHIFT)      /* 0x00000100 */
#define CRU_MISC_CON2_CLK_RKVDEC_HEVC_CA_IDLE_ENABLE_SHIFT (9U)
#define CRU_MISC_CON2_CLK_RKVDEC_HEVC_CA_IDLE_ENABLE_MASK  (0x1U << CRU_MISC_CON2_CLK_RKVDEC_HEVC_CA_IDLE_ENABLE_SHIFT) /* 0x00000200 */
#define CRU_MISC_CON2_USBPHY480M_SRC_SEL_SHIFT             (15U)
#define CRU_MISC_CON2_USBPHY480M_SRC_SEL_MASK              (0x1U << CRU_MISC_CON2_USBPHY480M_SRC_SEL_SHIFT)             /* 0x00008000 */
/* GLB_CNT_TH */
#define CRU_GLB_CNT_TH_OFFSET                              (0xD0U)
#define CRU_GLB_CNT_TH_GLOBAL_RESET_COUNTER_THRESHOLD_SHIFT (0U)
#define CRU_GLB_CNT_TH_GLOBAL_RESET_COUNTER_THRESHOLD_MASK (0xFFFFU << CRU_GLB_CNT_TH_GLOBAL_RESET_COUNTER_THRESHOLD_SHIFT) /* 0x0000FFFF */
#define CRU_GLB_CNT_TH_RESERVED_SHIFT                      (16U)
#define CRU_GLB_CNT_TH_RESERVED_MASK                       (0xFFFFU << CRU_GLB_CNT_TH_RESERVED_SHIFT)                   /* 0xFFFF0000 */
/* GLB_SRST_FST */
#define CRU_GLB_SRST_FST_OFFSET                            (0xD4U)
#define CRU_GLB_SRST_FST_GLB_SRST_FST_SHIFT                (0U)
#define CRU_GLB_SRST_FST_GLB_SRST_FST_MASK                 (0xFFFFU << CRU_GLB_SRST_FST_GLB_SRST_FST_SHIFT)             /* 0x0000FFFF */
/* GLB_SRST_SND */
#define CRU_GLB_SRST_SND_OFFSET                            (0xD8U)
#define CRU_GLB_SRST_SND_GLB_SRST_SND_SHIFT                (0U)
#define CRU_GLB_SRST_SND_GLB_SRST_SND_MASK                 (0xFFFFU << CRU_GLB_SRST_SND_GLB_SRST_SND_SHIFT)             /* 0x0000FFFF */
/* GLB_RST_CON */
#define CRU_GLB_RST_CON_OFFSET                             (0xDCU)
#define CRU_GLB_RST_CON_TSADC_GLB_SRST_CTRL_SHIFT          (0U)
#define CRU_GLB_RST_CON_TSADC_GLB_SRST_CTRL_MASK           (0x1U << CRU_GLB_RST_CON_TSADC_GLB_SRST_CTRL_SHIFT)          /* 0x00000001 */
#define CRU_GLB_RST_CON_WDT_GLB_SRST_CTRL_SHIFT            (1U)
#define CRU_GLB_RST_CON_WDT_GLB_SRST_CTRL_MASK             (0x1U << CRU_GLB_RST_CON_WDT_GLB_SRST_CTRL_SHIFT)            /* 0x00000002 */
#define CRU_GLB_RST_CON_PMU_SRST_GLB_CTRL_SHIFT            (2U)
#define CRU_GLB_RST_CON_PMU_SRST_GLB_CTRL_MASK             (0x1U << CRU_GLB_RST_CON_PMU_SRST_GLB_CTRL_SHIFT)            /* 0x00000004 */
#define CRU_GLB_RST_CON_PMU_SRST_GLB_EN_SHIFT              (3U)
#define CRU_GLB_RST_CON_PMU_SRST_GLB_EN_MASK               (0x1U << CRU_GLB_RST_CON_PMU_SRST_GLB_EN_SHIFT)              /* 0x00000008 */
#define CRU_GLB_RST_CON_PMU_SRST_WDT_EN_SHIFT              (4U)
#define CRU_GLB_RST_CON_PMU_SRST_WDT_EN_MASK               (0x1U << CRU_GLB_RST_CON_PMU_SRST_WDT_EN_SHIFT)              /* 0x00000010 */
#define CRU_GLB_RST_CON_TSADC_SHUT_RESET_EXT_EN_SHIFT      (6U)
#define CRU_GLB_RST_CON_TSADC_SHUT_RESET_EXT_EN_MASK       (0x1U << CRU_GLB_RST_CON_TSADC_SHUT_RESET_EXT_EN_SHIFT)      /* 0x00000040 */
#define CRU_GLB_RST_CON_WDT_RESET_EXT_EN_SHIFT             (7U)
#define CRU_GLB_RST_CON_WDT_RESET_EXT_EN_MASK              (0x1U << CRU_GLB_RST_CON_WDT_RESET_EXT_EN_SHIFT)             /* 0x00000080 */
#define CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_ENABLE_SHIFT     (8U)
#define CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_ENABLE_MASK      (0x1U << CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_ENABLE_SHIFT)     /* 0x00000100 */
#define CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT (9U)
#define CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_ENABLE_MASK  (0x1U << CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT) /* 0x00000200 */
#define CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT (10U)
#define CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_MASK (0x1U << CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT) /* 0x00000400 */
#define CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT (11U)
#define CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_MASK (0x1U << CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_ENABLE_SHIFT) /* 0x00000800 */
#define CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_SHIFT            (12U)
#define CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_MASK             (0x1U << CRU_GLB_RST_CON_JDB_GLB_SRST_CTRL_SHIFT)            /* 0x00001000 */
#define CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_SHIFT        (13U)
#define CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_MASK         (0x1U << CRU_GLB_RST_CON_OSC_CHK_GLB_SRST_CTRL_SHIFT)        /* 0x00002000 */
#define CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_SHIFT   (14U)
#define CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_MASK    (0x1U << CRU_GLB_RST_CON_SGRF_CRC_CHK_GLB_SRST_CTRL_SHIFT)   /* 0x00004000 */
#define CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_SHIFT (15U)
#define CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_MASK (0x1U << CRU_GLB_RST_CON_PMUSGRF_CRC_CHK_GLB_SRST_CTRL_SHIFT) /* 0x00008000 */
/* GLB_RST_ST */
#define CRU_GLB_RST_ST_OFFSET                              (0xE0U)
#define CRU_GLB_RST_ST_FST_GLB_RST_ST_SHIFT                (0U)
#define CRU_GLB_RST_ST_FST_GLB_RST_ST_MASK                 (0x1U << CRU_GLB_RST_ST_FST_GLB_RST_ST_SHIFT)                /* 0x00000001 */
#define CRU_GLB_RST_ST_SND_GLB_RST_ST_SHIFT                (1U)
#define CRU_GLB_RST_ST_SND_GLB_RST_ST_MASK                 (0x1U << CRU_GLB_RST_ST_SND_GLB_RST_ST_SHIFT)                /* 0x00000002 */
#define CRU_GLB_RST_ST_FST_GLB_TSADC_RST_ST_SHIFT          (2U)
#define CRU_GLB_RST_ST_FST_GLB_TSADC_RST_ST_MASK           (0x1U << CRU_GLB_RST_ST_FST_GLB_TSADC_RST_ST_SHIFT)          /* 0x00000004 */
#define CRU_GLB_RST_ST_SND_GLB_TSADC_RST_ST_SHIFT          (3U)
#define CRU_GLB_RST_ST_SND_GLB_TSADC_RST_ST_MASK           (0x1U << CRU_GLB_RST_ST_SND_GLB_TSADC_RST_ST_SHIFT)          /* 0x00000008 */
#define CRU_GLB_RST_ST_FST_GLB_WDT_RST_ST_SHIFT            (4U)
#define CRU_GLB_RST_ST_FST_GLB_WDT_RST_ST_MASK             (0x1U << CRU_GLB_RST_ST_FST_GLB_WDT_RST_ST_SHIFT)            /* 0x00000010 */
#define CRU_GLB_RST_ST_SND_GLB_WDT_RST_ST_SHIFT            (5U)
#define CRU_GLB_RST_ST_SND_GLB_WDT_RST_ST_MASK             (0x1U << CRU_GLB_RST_ST_SND_GLB_WDT_RST_ST_SHIFT)            /* 0x00000020 */
#define CRU_GLB_RST_ST_GLB_JDB_RST_ST_SHIFT                (6U)
#define CRU_GLB_RST_ST_GLB_JDB_RST_ST_MASK                 (0x1U << CRU_GLB_RST_ST_GLB_JDB_RST_ST_SHIFT)                /* 0x00000040 */
#define CRU_GLB_RST_ST_GLB_OSC_CHK_RST_ST_SHIFT            (7U)
#define CRU_GLB_RST_ST_GLB_OSC_CHK_RST_ST_MASK             (0x1U << CRU_GLB_RST_ST_GLB_OSC_CHK_RST_ST_SHIFT)            /* 0x00000080 */
#define CRU_GLB_RST_ST_GLB_SGRF_CRC_RST_ST_SHIFT           (8U)
#define CRU_GLB_RST_ST_GLB_SGRF_CRC_RST_ST_MASK            (0x1U << CRU_GLB_RST_ST_GLB_SGRF_CRC_RST_ST_SHIFT)           /* 0x00000100 */
#define CRU_GLB_RST_ST_GLB_PMUSGRF_CRC_RST_ST_SHIFT        (9U)
#define CRU_GLB_RST_ST_GLB_PMUSGRF_CRC_RST_ST_MASK         (0x1U << CRU_GLB_RST_ST_GLB_PMUSGRF_CRC_RST_ST_SHIFT)        /* 0x00000200 */
/* CLKSEL_CON00 */
#define CRU_CLKSEL_CON00_OFFSET                            (0x100U)
#define CRU_CLKSEL_CON00_CLK_CORE0_DIV_SHIFT               (0U)
#define CRU_CLKSEL_CON00_CLK_CORE0_DIV_MASK                (0x1FU << CRU_CLKSEL_CON00_CLK_CORE0_DIV_SHIFT)              /* 0x0000001F */
#define CRU_CLKSEL_CON00_CLK_CORE_I_SEL_SHIFT              (6U)
#define CRU_CLKSEL_CON00_CLK_CORE_I_SEL_MASK               (0x1U << CRU_CLKSEL_CON00_CLK_CORE_I_SEL_SHIFT)              /* 0x00000040 */
#define CRU_CLKSEL_CON00_CLK_CORE_NDFT_SEL_SHIFT           (7U)
#define CRU_CLKSEL_CON00_CLK_CORE_NDFT_SEL_MASK            (0x1U << CRU_CLKSEL_CON00_CLK_CORE_NDFT_SEL_SHIFT)           /* 0x00000080 */
#define CRU_CLKSEL_CON00_CLK_CORE1_DIV_SHIFT               (8U)
#define CRU_CLKSEL_CON00_CLK_CORE1_DIV_MASK                (0x1FU << CRU_CLKSEL_CON00_CLK_CORE1_DIV_SHIFT)              /* 0x00001F00 */
#define CRU_CLKSEL_CON00_CLK_CORE_NDFT_MUX_SEL_SHIFT       (15U)
#define CRU_CLKSEL_CON00_CLK_CORE_NDFT_MUX_SEL_MASK        (0x1U << CRU_CLKSEL_CON00_CLK_CORE_NDFT_MUX_SEL_SHIFT)       /* 0x00008000 */
/* CLKSEL_CON01 */
#define CRU_CLKSEL_CON01_OFFSET                            (0x104U)
#define CRU_CLKSEL_CON01_CLK_CORE2_DIV_SHIFT               (0U)
#define CRU_CLKSEL_CON01_CLK_CORE2_DIV_MASK                (0x1FU << CRU_CLKSEL_CON01_CLK_CORE2_DIV_SHIFT)              /* 0x0000001F */
#define CRU_CLKSEL_CON01_CLK_CORE3_DIV_SHIFT               (8U)
#define CRU_CLKSEL_CON01_CLK_CORE3_DIV_MASK                (0x1FU << CRU_CLKSEL_CON01_CLK_CORE3_DIV_SHIFT)              /* 0x00001F00 */
/* CLKSEL_CON02 */
#define CRU_CLKSEL_CON02_OFFSET                            (0x108U)
#define CRU_CLKSEL_CON02_SCLK_CORE_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON02_SCLK_CORE_SRC_DIV_MASK            (0xFU << CRU_CLKSEL_CON02_SCLK_CORE_SRC_DIV_SHIFT)           /* 0x0000000F */
#define CRU_CLKSEL_CON02_SCLK_CORE_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON02_SCLK_CORE_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON02_SCLK_CORE_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON02_SCLK_CORE_PRE_SEL_SHIFT           (15U)
#define CRU_CLKSEL_CON02_SCLK_CORE_PRE_SEL_MASK            (0x1U << CRU_CLKSEL_CON02_SCLK_CORE_PRE_SEL_SHIFT)           /* 0x00008000 */
/* CLKSEL_CON03 */
#define CRU_CLKSEL_CON03_OFFSET                            (0x10CU)
#define CRU_CLKSEL_CON03_ATCLK_CORE_DIV_SHIFT              (0U)
#define CRU_CLKSEL_CON03_ATCLK_CORE_DIV_MASK               (0x1FU << CRU_CLKSEL_CON03_ATCLK_CORE_DIV_SHIFT)             /* 0x0000001F */
#define CRU_CLKSEL_CON03_GICCLK_CORE_DIV_SHIFT             (8U)
#define CRU_CLKSEL_CON03_GICCLK_CORE_DIV_MASK              (0x1FU << CRU_CLKSEL_CON03_GICCLK_CORE_DIV_SHIFT)            /* 0x00001F00 */
/* CLKSEL_CON04 */
#define CRU_CLKSEL_CON04_OFFSET                            (0x110U)
#define CRU_CLKSEL_CON04_PCLK_CORE_PRE_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON04_PCLK_CORE_PRE_DIV_MASK            (0x1FU << CRU_CLKSEL_CON04_PCLK_CORE_PRE_DIV_SHIFT)          /* 0x0000001F */
#define CRU_CLKSEL_CON04_PERIPHCLK_CORE_PRE_DIV_SHIFT      (8U)
#define CRU_CLKSEL_CON04_PERIPHCLK_CORE_PRE_DIV_MASK       (0x1FU << CRU_CLKSEL_CON04_PERIPHCLK_CORE_PRE_DIV_SHIFT)     /* 0x00001F00 */
/* CLKSEL_CON05 */
#define CRU_CLKSEL_CON05_OFFSET                            (0x114U)
#define CRU_CLKSEL_CON05_RESERVED_SHIFT                    (0U)
#define CRU_CLKSEL_CON05_RESERVED_MASK                     (0xFFU << CRU_CLKSEL_CON05_RESERVED_SHIFT)                   /* 0x000000FF */
#define CRU_CLKSEL_CON05_ACLK_CORE_NDFT_DIV_SHIFT          (8U)
#define CRU_CLKSEL_CON05_ACLK_CORE_NDFT_DIV_MASK           (0x1FU << CRU_CLKSEL_CON05_ACLK_CORE_NDFT_DIV_SHIFT)         /* 0x00001F00 */
#define CRU_CLKSEL_CON05_ACLK_CORE_NIU2BUS_SEL_SHIFT       (14U)
#define CRU_CLKSEL_CON05_ACLK_CORE_NIU2BUS_SEL_MASK        (0x3U << CRU_CLKSEL_CON05_ACLK_CORE_NIU2BUS_SEL_SHIFT)       /* 0x0000C000 */
/* CLKSEL_CON06 */
#define CRU_CLKSEL_CON06_OFFSET                            (0x118U)
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_DIV_SHIFT             (0U)
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_DIV_MASK              (0xFU << CRU_CLKSEL_CON06_CLK_GPU_PRE_DIV_SHIFT)             /* 0x0000000F */
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_SEL_SHIFT             (6U)
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_SEL_MASK              (0x3U << CRU_CLKSEL_CON06_CLK_GPU_PRE_SEL_SHIFT)             /* 0x000000C0 */
#define CRU_CLKSEL_CON06_ACLK_GPU_PRE_DIV_SHIFT            (8U)
#define CRU_CLKSEL_CON06_ACLK_GPU_PRE_DIV_MASK             (0x3U << CRU_CLKSEL_CON06_ACLK_GPU_PRE_DIV_SHIFT)            /* 0x00000300 */
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_MUX_SEL_SHIFT         (11U)
#define CRU_CLKSEL_CON06_CLK_GPU_PRE_MUX_SEL_MASK          (0x1U << CRU_CLKSEL_CON06_CLK_GPU_PRE_MUX_SEL_SHIFT)         /* 0x00000800 */
#define CRU_CLKSEL_CON06_PCLK_GPU_PRE_DIV_SHIFT            (12U)
#define CRU_CLKSEL_CON06_PCLK_GPU_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON06_PCLK_GPU_PRE_DIV_SHIFT)            /* 0x0000F000 */
/* CLKSEL_CON07 */
#define CRU_CLKSEL_CON07_OFFSET                            (0x11CU)
#define CRU_CLKSEL_CON07_CLK_NPU_SRC_DIV_SHIFT             (0U)
#define CRU_CLKSEL_CON07_CLK_NPU_SRC_DIV_MASK              (0xFU << CRU_CLKSEL_CON07_CLK_NPU_SRC_DIV_SHIFT)             /* 0x0000000F */
#define CRU_CLKSEL_CON07_CLK_NPU_NP5_DIV_SHIFT             (4U)
#define CRU_CLKSEL_CON07_CLK_NPU_NP5_DIV_MASK              (0x3U << CRU_CLKSEL_CON07_CLK_NPU_NP5_DIV_SHIFT)             /* 0x00000030 */
#define CRU_CLKSEL_CON07_CLK_NPU_SRC_SEL_SHIFT             (6U)
#define CRU_CLKSEL_CON07_CLK_NPU_SRC_SEL_MASK              (0x1U << CRU_CLKSEL_CON07_CLK_NPU_SRC_SEL_SHIFT)             /* 0x00000040 */
#define CRU_CLKSEL_CON07_CLK_NPU_NP5_SEL_SHIFT             (7U)
#define CRU_CLKSEL_CON07_CLK_NPU_NP5_SEL_MASK              (0x1U << CRU_CLKSEL_CON07_CLK_NPU_NP5_SEL_SHIFT)             /* 0x00000080 */
#define CRU_CLKSEL_CON07_CLK_NPU_PRE_NDFT_SEL_SHIFT        (8U)
#define CRU_CLKSEL_CON07_CLK_NPU_PRE_NDFT_SEL_MASK         (0x1U << CRU_CLKSEL_CON07_CLK_NPU_PRE_NDFT_SEL_SHIFT)        /* 0x00000100 */
#define CRU_CLKSEL_CON07_CLK_NPU_PRE_MUX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON07_CLK_NPU_PRE_MUX_SEL_MASK          (0x1U << CRU_CLKSEL_CON07_CLK_NPU_PRE_MUX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON08 */
#define CRU_CLKSEL_CON08_OFFSET                            (0x120U)
#define CRU_CLKSEL_CON08_HCLK_NPU_PRE_DIV_SHIFT            (0U)
#define CRU_CLKSEL_CON08_HCLK_NPU_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON08_HCLK_NPU_PRE_DIV_SHIFT)            /* 0x0000000F */
#define CRU_CLKSEL_CON08_PCLK_NPU_PRE_DIV_SHIFT            (4U)
#define CRU_CLKSEL_CON08_PCLK_NPU_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON08_PCLK_NPU_PRE_DIV_SHIFT)            /* 0x000000F0 */
/* CLKSEL_CON09 */
#define CRU_CLKSEL_CON09_OFFSET                            (0x124U)
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_DIV_SHIFT        (0U)
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_DIV_MASK         (0x1FU << CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_DIV_SHIFT)       /* 0x0000001F */
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_SEL_SHIFT        (6U)
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_SEL_MASK         (0x3U << CRU_CLKSEL_CON09_CLK_DDRPHY1X_SRC_SEL_SHIFT)        /* 0x000000C0 */
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SEL_SHIFT            (15U)
#define CRU_CLKSEL_CON09_CLK_DDRPHY1X_SEL_MASK             (0x1U << CRU_CLKSEL_CON09_CLK_DDRPHY1X_SEL_SHIFT)            /* 0x00008000 */
/* CLKSEL_CON10 */
#define CRU_CLKSEL_CON10_OFFSET                            (0x128U)
#define CRU_CLKSEL_CON10_CLK_MSCH_DIV_SHIFT                (0U)
#define CRU_CLKSEL_CON10_CLK_MSCH_DIV_MASK                 (0x3U << CRU_CLKSEL_CON10_CLK_MSCH_DIV_SHIFT)                /* 0x00000003 */
#define CRU_CLKSEL_CON10_ACLK_PERIMID_SEL_SHIFT            (4U)
#define CRU_CLKSEL_CON10_ACLK_PERIMID_SEL_MASK             (0x3U << CRU_CLKSEL_CON10_ACLK_PERIMID_SEL_SHIFT)            /* 0x00000030 */
#define CRU_CLKSEL_CON10_HCLK_PERIMID_SEL_SHIFT            (6U)
#define CRU_CLKSEL_CON10_HCLK_PERIMID_SEL_MASK             (0x3U << CRU_CLKSEL_CON10_HCLK_PERIMID_SEL_SHIFT)            /* 0x000000C0 */
#define CRU_CLKSEL_CON10_ACLK_GIC_AUDIO_SEL_SHIFT          (8U)
#define CRU_CLKSEL_CON10_ACLK_GIC_AUDIO_SEL_MASK           (0x3U << CRU_CLKSEL_CON10_ACLK_GIC_AUDIO_SEL_SHIFT)          /* 0x00000300 */
#define CRU_CLKSEL_CON10_HCLK_GIC_AUDIO_SEL_SHIFT          (10U)
#define CRU_CLKSEL_CON10_HCLK_GIC_AUDIO_SEL_MASK           (0x3U << CRU_CLKSEL_CON10_HCLK_GIC_AUDIO_SEL_SHIFT)          /* 0x00000C00 */
#define CRU_CLKSEL_CON10_DCLK_SDMMC_BUFFER_SEL_SHIFT       (12U)
#define CRU_CLKSEL_CON10_DCLK_SDMMC_BUFFER_SEL_MASK        (0x3U << CRU_CLKSEL_CON10_DCLK_SDMMC_BUFFER_SEL_SHIFT)       /* 0x00003000 */
/* CLKSEL_CON11 */
#define CRU_CLKSEL_CON11_OFFSET                            (0x12CU)
#define CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON11_CLK_I2S0_8CH_TX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON11_MCLK_I2S0_8CH_TX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON11_MCLK_I2S0_8CH_TX_SEL_MASK         (0x3U << CRU_CLKSEL_CON11_MCLK_I2S0_8CH_TX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON11_I2S0_MCLKOUT_TX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON11_I2S0_MCLKOUT_TX_SEL_MASK          (0x1U << CRU_CLKSEL_CON11_I2S0_MCLKOUT_TX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON12 */
#define CRU_CLKSEL_CON12_OFFSET                            (0x130U)
#define CRU_CLKSEL_CON12_CLK_I2S0_8CH_TX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON12_CLK_I2S0_8CH_TX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON12_CLK_I2S0_8CH_TX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON13 */
#define CRU_CLKSEL_CON13_OFFSET                            (0x134U)
#define CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON13_CLK_I2S0_8CH_RX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON13_MCLK_I2S0_8CH_RX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON13_MCLK_I2S0_8CH_RX_SEL_MASK         (0x3U << CRU_CLKSEL_CON13_MCLK_I2S0_8CH_RX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON13_I2S0_MCLKOUT_RX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON13_I2S0_MCLKOUT_RX_SEL_MASK          (0x1U << CRU_CLKSEL_CON13_I2S0_MCLKOUT_RX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON14 */
#define CRU_CLKSEL_CON14_OFFSET                            (0x138U)
#define CRU_CLKSEL_CON14_CLK_I2S0_8CH_RX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON14_CLK_I2S0_8CH_RX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON14_CLK_I2S0_8CH_RX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON15 */
#define CRU_CLKSEL_CON15_OFFSET                            (0x13CU)
#define CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON15_CLK_I2S1_8CH_TX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON15_MCLK_I2S1_8CH_TX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON15_MCLK_I2S1_8CH_TX_SEL_MASK         (0x3U << CRU_CLKSEL_CON15_MCLK_I2S1_8CH_TX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON15_I2S1_MCLKOUT_TX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON15_I2S1_MCLKOUT_TX_SEL_MASK          (0x1U << CRU_CLKSEL_CON15_I2S1_MCLKOUT_TX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON16 */
#define CRU_CLKSEL_CON16_OFFSET                            (0x140U)
#define CRU_CLKSEL_CON16_CLK_I2S1_8CH_TX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON16_CLK_I2S1_8CH_TX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON16_CLK_I2S1_8CH_TX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON17 */
#define CRU_CLKSEL_CON17_OFFSET                            (0x144U)
#define CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON17_CLK_I2S1_8CH_RX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON17_MCLK_I2S1_8CH_RX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON17_MCLK_I2S1_8CH_RX_SEL_MASK         (0x3U << CRU_CLKSEL_CON17_MCLK_I2S1_8CH_RX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON17_I2S1_MCLKOUT_RX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON17_I2S1_MCLKOUT_RX_SEL_MASK          (0x1U << CRU_CLKSEL_CON17_I2S1_MCLKOUT_RX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON18 */
#define CRU_CLKSEL_CON18_OFFSET                            (0x148U)
#define CRU_CLKSEL_CON18_CLK_I2S1_8CH_RX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON18_CLK_I2S1_8CH_RX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON18_CLK_I2S1_8CH_RX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON19 */
#define CRU_CLKSEL_CON19_OFFSET                            (0x14CU)
#define CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_DIV_SHIFT        (0U)
#define CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_DIV_MASK         (0x7FU << CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_DIV_SHIFT)       /* 0x0000007F */
#define CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_SEL_SHIFT        (8U)
#define CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_SEL_MASK         (0x3U << CRU_CLKSEL_CON19_CLK_I2S2_2CH_SRC_SEL_SHIFT)        /* 0x00000300 */
#define CRU_CLKSEL_CON19_MCLK_I2S2_2CH_SEL_SHIFT           (10U)
#define CRU_CLKSEL_CON19_MCLK_I2S2_2CH_SEL_MASK            (0x3U << CRU_CLKSEL_CON19_MCLK_I2S2_2CH_SEL_SHIFT)           /* 0x00000C00 */
#define CRU_CLKSEL_CON19_I2S2_MCLKOUT_SEL_SHIFT            (15U)
#define CRU_CLKSEL_CON19_I2S2_MCLKOUT_SEL_MASK             (0x1U << CRU_CLKSEL_CON19_I2S2_MCLKOUT_SEL_SHIFT)            /* 0x00008000 */
/* CLKSEL_CON20 */
#define CRU_CLKSEL_CON20_OFFSET                            (0x150U)
#define CRU_CLKSEL_CON20_CLK_I2S2_2CH_FRAC_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON20_CLK_I2S2_2CH_FRAC_DIV_MASK        (0xFFFFFFFFU << CRU_CLKSEL_CON20_CLK_I2S2_2CH_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON21 */
#define CRU_CLKSEL_CON21_OFFSET                            (0x154U)
#define CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON21_CLK_I2S3_2CH_TX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON21_MCLK_I2S3_2CH_TX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON21_MCLK_I2S3_2CH_TX_SEL_MASK         (0x3U << CRU_CLKSEL_CON21_MCLK_I2S3_2CH_TX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON21_I2S3_MCLKOUT_TX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON21_I2S3_MCLKOUT_TX_SEL_MASK          (0x1U << CRU_CLKSEL_CON21_I2S3_MCLKOUT_TX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON22 */
#define CRU_CLKSEL_CON22_OFFSET                            (0x158U)
#define CRU_CLKSEL_CON22_CLK_I2S3_2CH_TX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON22_CLK_I2S3_2CH_TX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON22_CLK_I2S3_2CH_TX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON23 */
#define CRU_CLKSEL_CON23_OFFSET                            (0x15CU)
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_DIV_SHIFT      (0U)
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_DIV_MASK       (0x7FU << CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_DIV_SHIFT)     /* 0x0000007F */
#define CRU_CLKSEL_CON23_MCLK_PDM_SEL_SHIFT                (8U)
#define CRU_CLKSEL_CON23_MCLK_PDM_SEL_MASK                 (0x3U << CRU_CLKSEL_CON23_MCLK_PDM_SEL_SHIFT)                /* 0x00000300 */
#define CRU_CLKSEL_CON23_CLK_ACDCDIG_I2C_SEL_SHIFT         (10U)
#define CRU_CLKSEL_CON23_CLK_ACDCDIG_I2C_SEL_MASK          (0x3U << CRU_CLKSEL_CON23_CLK_ACDCDIG_I2C_SEL_SHIFT)         /* 0x00000C00 */
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_SEL_SHIFT      (14U)
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_SEL_MASK       (0x1U << CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SRC_SEL_SHIFT)      /* 0x00004000 */
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SEL_SHIFT          (15U)
#define CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SEL_MASK           (0x1U << CRU_CLKSEL_CON23_MCLK_SPDIF_8CH_SEL_SHIFT)          /* 0x00008000 */
/* CLKSEL_CON24 */
#define CRU_CLKSEL_CON24_OFFSET                            (0x160U)
#define CRU_CLKSEL_CON24_MCLK_SPDIF_8CH_FRAC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON24_MCLK_SPDIF_8CH_FRAC_DIV_MASK      (0xFFFFFFFFU << CRU_CLKSEL_CON24_MCLK_SPDIF_8CH_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON25 */
#define CRU_CLKSEL_CON25_OFFSET                            (0x164U)
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_DIV_SHIFT         (0U)
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_DIV_MASK          (0x3FU << CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_DIV_SHIFT)        /* 0x0000003F */
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_SEL_SHIFT         (14U)
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_SEL_MASK          (0x1U << CRU_CLKSEL_CON25_SCLK_AUDPWM_SRC_SEL_SHIFT)         /* 0x00004000 */
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SEL_SHIFT             (15U)
#define CRU_CLKSEL_CON25_SCLK_AUDPWM_SEL_MASK              (0x1U << CRU_CLKSEL_CON25_SCLK_AUDPWM_SEL_SHIFT)             /* 0x00008000 */
/* CLKSEL_CON26 */
#define CRU_CLKSEL_CON26_OFFSET                            (0x168U)
#define CRU_CLKSEL_CON26_SCLK_AUDPWM_FRAC_DIV_SHIFT        (0U)
#define CRU_CLKSEL_CON26_SCLK_AUDPWM_FRAC_DIV_MASK         (0xFFFFFFFFU << CRU_CLKSEL_CON26_SCLK_AUDPWM_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* CLKSEL_CON27 */
#define CRU_CLKSEL_CON27_OFFSET                            (0x16CU)
#define CRU_CLKSEL_CON27_ACLK_SECURE_FLASH_SEL_SHIFT       (0U)
#define CRU_CLKSEL_CON27_ACLK_SECURE_FLASH_SEL_MASK        (0x3U << CRU_CLKSEL_CON27_ACLK_SECURE_FLASH_SEL_SHIFT)       /* 0x00000003 */
#define CRU_CLKSEL_CON27_HCLK_SECURE_FLASH_SEL_SHIFT       (2U)
#define CRU_CLKSEL_CON27_HCLK_SECURE_FLASH_SEL_MASK        (0x3U << CRU_CLKSEL_CON27_HCLK_SECURE_FLASH_SEL_SHIFT)       /* 0x0000000C */
#define CRU_CLKSEL_CON27_CLK_CRYPTO_NS_CORE_SEL_SHIFT      (4U)
#define CRU_CLKSEL_CON27_CLK_CRYPTO_NS_CORE_SEL_MASK       (0x3U << CRU_CLKSEL_CON27_CLK_CRYPTO_NS_CORE_SEL_SHIFT)      /* 0x00000030 */
#define CRU_CLKSEL_CON27_CLK_CRYPTO_NS_PKA_SEL_SHIFT       (6U)
#define CRU_CLKSEL_CON27_CLK_CRYPTO_NS_PKA_SEL_MASK        (0x3U << CRU_CLKSEL_CON27_CLK_CRYPTO_NS_PKA_SEL_SHIFT)       /* 0x000000C0 */
/* CLKSEL_CON28 */
#define CRU_CLKSEL_CON28_OFFSET                            (0x170U)
#define CRU_CLKSEL_CON28_NCLK_NANDC_SEL_SHIFT              (0U)
#define CRU_CLKSEL_CON28_NCLK_NANDC_SEL_MASK               (0x3U << CRU_CLKSEL_CON28_NCLK_NANDC_SEL_SHIFT)              /* 0x00000003 */
#define CRU_CLKSEL_CON28_SCLK_SFC_SEL_SHIFT                (4U)
#define CRU_CLKSEL_CON28_SCLK_SFC_SEL_MASK                 (0x7U << CRU_CLKSEL_CON28_SCLK_SFC_SEL_SHIFT)                /* 0x00000070 */
#define CRU_CLKSEL_CON28_BCLK_EMMC_SEL_SHIFT               (8U)
#define CRU_CLKSEL_CON28_BCLK_EMMC_SEL_MASK                (0x3U << CRU_CLKSEL_CON28_BCLK_EMMC_SEL_SHIFT)               /* 0x00000300 */
#define CRU_CLKSEL_CON28_CCLK_EMMC_SEL_SHIFT               (12U)
#define CRU_CLKSEL_CON28_CCLK_EMMC_SEL_MASK                (0x7U << CRU_CLKSEL_CON28_CCLK_EMMC_SEL_SHIFT)               /* 0x00007000 */
/* CLKSEL_CON29 */
#define CRU_CLKSEL_CON29_OFFSET                            (0x174U)
#define CRU_CLKSEL_CON29_ACLK_PIPE_SEL_SHIFT               (0U)
#define CRU_CLKSEL_CON29_ACLK_PIPE_SEL_MASK                (0x3U << CRU_CLKSEL_CON29_ACLK_PIPE_SEL_SHIFT)               /* 0x00000003 */
#define CRU_CLKSEL_CON29_PCLK_PIPE_DIV_SHIFT               (4U)
#define CRU_CLKSEL_CON29_PCLK_PIPE_DIV_MASK                (0xFU << CRU_CLKSEL_CON29_PCLK_PIPE_DIV_SHIFT)               /* 0x000000F0 */
#define CRU_CLKSEL_CON29_CLK_USB3OTG0_SUSPEND_SEL_SHIFT    (8U)
#define CRU_CLKSEL_CON29_CLK_USB3OTG0_SUSPEND_SEL_MASK     (0x1U << CRU_CLKSEL_CON29_CLK_USB3OTG0_SUSPEND_SEL_SHIFT)    /* 0x00000100 */
#define CRU_CLKSEL_CON29_CLK_USB3OTG1_SUSPEND_SEL_SHIFT    (9U)
#define CRU_CLKSEL_CON29_CLK_USB3OTG1_SUSPEND_SEL_MASK     (0x1U << CRU_CLKSEL_CON29_CLK_USB3OTG1_SUSPEND_SEL_SHIFT)    /* 0x00000200 */
#define CRU_CLKSEL_CON29_CLK_XPCS_EEE_SEL_SHIFT            (13U)
#define CRU_CLKSEL_CON29_CLK_XPCS_EEE_SEL_MASK             (0x1U << CRU_CLKSEL_CON29_CLK_XPCS_EEE_SEL_SHIFT)            /* 0x00002000 */
/* CLKSEL_CON30 */
#define CRU_CLKSEL_CON30_OFFSET                            (0x178U)
#define CRU_CLKSEL_CON30_ACLK_PHP_SEL_SHIFT                (0U)
#define CRU_CLKSEL_CON30_ACLK_PHP_SEL_MASK                 (0x3U << CRU_CLKSEL_CON30_ACLK_PHP_SEL_SHIFT)                /* 0x00000003 */
#define CRU_CLKSEL_CON30_HCLK_PHP_SEL_SHIFT                (2U)
#define CRU_CLKSEL_CON30_HCLK_PHP_SEL_MASK                 (0x3U << CRU_CLKSEL_CON30_HCLK_PHP_SEL_SHIFT)                /* 0x0000000C */
#define CRU_CLKSEL_CON30_PCLK_PHP_DIV_SHIFT                (4U)
#define CRU_CLKSEL_CON30_PCLK_PHP_DIV_MASK                 (0xFU << CRU_CLKSEL_CON30_PCLK_PHP_DIV_SHIFT)                /* 0x000000F0 */
#define CRU_CLKSEL_CON30_CLK_SDMMC0_SEL_SHIFT              (8U)
#define CRU_CLKSEL_CON30_CLK_SDMMC0_SEL_MASK               (0x7U << CRU_CLKSEL_CON30_CLK_SDMMC0_SEL_SHIFT)              /* 0x00000700 */
#define CRU_CLKSEL_CON30_CLK_SDMMC1_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON30_CLK_SDMMC1_SEL_MASK               (0x7U << CRU_CLKSEL_CON30_CLK_SDMMC1_SEL_SHIFT)              /* 0x00007000 */
/* CLKSEL_CON31 */
#define CRU_CLKSEL_CON31_OFFSET                            (0x17CU)
#define CRU_CLKSEL_CON31_RMII0_MODE_SHIFT                  (0U)
#define CRU_CLKSEL_CON31_RMII0_MODE_MASK                   (0x3U << CRU_CLKSEL_CON31_RMII0_MODE_SHIFT)                  /* 0x00000003 */
#define CRU_CLKSEL_CON31_RMII0_EXTCLK_SEL_SHIFT            (2U)
#define CRU_CLKSEL_CON31_RMII0_EXTCLK_SEL_MASK             (0x1U << CRU_CLKSEL_CON31_RMII0_EXTCLK_SEL_SHIFT)            /* 0x00000004 */
#define CRU_CLKSEL_CON31_RMII0_CLK_SEL_SHIFT               (3U)
#define CRU_CLKSEL_CON31_RMII0_CLK_SEL_MASK                (0x1U << CRU_CLKSEL_CON31_RMII0_CLK_SEL_SHIFT)               /* 0x00000008 */
#define CRU_CLKSEL_CON31_RGMII0_CLK_SEL_SHIFT              (4U)
#define CRU_CLKSEL_CON31_RGMII0_CLK_SEL_MASK               (0x3U << CRU_CLKSEL_CON31_RGMII0_CLK_SEL_SHIFT)              /* 0x00000030 */
#define CRU_CLKSEL_CON31_CLK_MAC0_2TOP_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON31_CLK_MAC0_2TOP_SEL_MASK            (0x3U << CRU_CLKSEL_CON31_CLK_MAC0_2TOP_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON31_CLK_GMAC0_PTP_REF_SEL_SHIFT       (12U)
#define CRU_CLKSEL_CON31_CLK_GMAC0_PTP_REF_SEL_MASK        (0x3U << CRU_CLKSEL_CON31_CLK_GMAC0_PTP_REF_SEL_SHIFT)       /* 0x00003000 */
#define CRU_CLKSEL_CON31_CLK_MAC0_OUT_SEL_SHIFT            (14U)
#define CRU_CLKSEL_CON31_CLK_MAC0_OUT_SEL_MASK             (0x3U << CRU_CLKSEL_CON31_CLK_MAC0_OUT_SEL_SHIFT)            /* 0x0000C000 */
/* CLKSEL_CON32 */
#define CRU_CLKSEL_CON32_OFFSET                            (0x180U)
#define CRU_CLKSEL_CON32_ACLK_USB_SEL_SHIFT                (0U)
#define CRU_CLKSEL_CON32_ACLK_USB_SEL_MASK                 (0x3U << CRU_CLKSEL_CON32_ACLK_USB_SEL_SHIFT)                /* 0x00000003 */
#define CRU_CLKSEL_CON32_HCLK_USB_SEL_SHIFT                (2U)
#define CRU_CLKSEL_CON32_HCLK_USB_SEL_MASK                 (0x3U << CRU_CLKSEL_CON32_HCLK_USB_SEL_SHIFT)                /* 0x0000000C */
#define CRU_CLKSEL_CON32_PCLK_USB_DIV_SHIFT                (4U)
#define CRU_CLKSEL_CON32_PCLK_USB_DIV_MASK                 (0xFU << CRU_CLKSEL_CON32_PCLK_USB_DIV_SHIFT)                /* 0x000000F0 */
#define CRU_CLKSEL_CON32_CLK_SDMMC2_SEL_SHIFT              (8U)
#define CRU_CLKSEL_CON32_CLK_SDMMC2_SEL_MASK               (0x7U << CRU_CLKSEL_CON32_CLK_SDMMC2_SEL_SHIFT)              /* 0x00000700 */
/* CLKSEL_CON33 */
#define CRU_CLKSEL_CON33_OFFSET                            (0x184U)
#define CRU_CLKSEL_CON33_RMII1_MODE_SHIFT                  (0U)
#define CRU_CLKSEL_CON33_RMII1_MODE_MASK                   (0x3U << CRU_CLKSEL_CON33_RMII1_MODE_SHIFT)                  /* 0x00000003 */
#define CRU_CLKSEL_CON33_RMII1_EXTCLK_SEL_SHIFT            (2U)
#define CRU_CLKSEL_CON33_RMII1_EXTCLK_SEL_MASK             (0x1U << CRU_CLKSEL_CON33_RMII1_EXTCLK_SEL_SHIFT)            /* 0x00000004 */
#define CRU_CLKSEL_CON33_RMII1_CLK_SEL_SHIFT               (3U)
#define CRU_CLKSEL_CON33_RMII1_CLK_SEL_MASK                (0x1U << CRU_CLKSEL_CON33_RMII1_CLK_SEL_SHIFT)               /* 0x00000008 */
#define CRU_CLKSEL_CON33_RGMII1_CLK_SEL_SHIFT              (4U)
#define CRU_CLKSEL_CON33_RGMII1_CLK_SEL_MASK               (0x3U << CRU_CLKSEL_CON33_RGMII1_CLK_SEL_SHIFT)              /* 0x00000030 */
#define CRU_CLKSEL_CON33_CLK_MAC1_2TOP_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON33_CLK_MAC1_2TOP_SEL_MASK            (0x3U << CRU_CLKSEL_CON33_CLK_MAC1_2TOP_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON33_CLK_GMAC1_PTP_REF_SEL_SHIFT       (12U)
#define CRU_CLKSEL_CON33_CLK_GMAC1_PTP_REF_SEL_MASK        (0x3U << CRU_CLKSEL_CON33_CLK_GMAC1_PTP_REF_SEL_SHIFT)       /* 0x00003000 */
#define CRU_CLKSEL_CON33_CLK_MAC1_OUT_SEL_SHIFT            (14U)
#define CRU_CLKSEL_CON33_CLK_MAC1_OUT_SEL_MASK             (0x3U << CRU_CLKSEL_CON33_CLK_MAC1_OUT_SEL_SHIFT)            /* 0x0000C000 */
/* CLKSEL_CON34 */
#define CRU_CLKSEL_CON34_OFFSET                            (0x188U)
#define CRU_CLKSEL_CON34_ACLK_VI_SEL_SHIFT                 (0U)
#define CRU_CLKSEL_CON34_ACLK_VI_SEL_MASK                  (0x3U << CRU_CLKSEL_CON34_ACLK_VI_SEL_SHIFT)                 /* 0x00000003 */
#define CRU_CLKSEL_CON34_HCLK_VI_DIV_SHIFT                 (4U)
#define CRU_CLKSEL_CON34_HCLK_VI_DIV_MASK                  (0xFU << CRU_CLKSEL_CON34_HCLK_VI_DIV_SHIFT)                 /* 0x000000F0 */
#define CRU_CLKSEL_CON34_PCLK_VI_DIV_SHIFT                 (8U)
#define CRU_CLKSEL_CON34_PCLK_VI_DIV_MASK                  (0xFU << CRU_CLKSEL_CON34_PCLK_VI_DIV_SHIFT)                 /* 0x00000F00 */
#define CRU_CLKSEL_CON34_DCLK_VICAP1_SEL_SHIFT             (14U)
#define CRU_CLKSEL_CON34_DCLK_VICAP1_SEL_MASK              (0x3U << CRU_CLKSEL_CON34_DCLK_VICAP1_SEL_SHIFT)             /* 0x0000C000 */
/* CLKSEL_CON35 */
#define CRU_CLKSEL_CON35_OFFSET                            (0x18CU)
#define CRU_CLKSEL_CON35_CLK_ISP_DIV_SHIFT                 (0U)
#define CRU_CLKSEL_CON35_CLK_ISP_DIV_MASK                  (0x1FU << CRU_CLKSEL_CON35_CLK_ISP_DIV_SHIFT)                /* 0x0000001F */
#define CRU_CLKSEL_CON35_CLK_ISP_SEL_SHIFT                 (6U)
#define CRU_CLKSEL_CON35_CLK_ISP_SEL_MASK                  (0x3U << CRU_CLKSEL_CON35_CLK_ISP_SEL_SHIFT)                 /* 0x000000C0 */
#define CRU_CLKSEL_CON35_CLK_CIF_OUT_DIV_SHIFT             (8U)
#define CRU_CLKSEL_CON35_CLK_CIF_OUT_DIV_MASK              (0x3FU << CRU_CLKSEL_CON35_CLK_CIF_OUT_DIV_SHIFT)            /* 0x00003F00 */
#define CRU_CLKSEL_CON35_CLK_CIF_OUT_SEL_SHIFT             (14U)
#define CRU_CLKSEL_CON35_CLK_CIF_OUT_SEL_MASK              (0x3U << CRU_CLKSEL_CON35_CLK_CIF_OUT_SEL_SHIFT)             /* 0x0000C000 */
/* CLKSEL_CON36 */
#define CRU_CLKSEL_CON36_OFFSET                            (0x190U)
#define CRU_CLKSEL_CON36_CLK_CAM0_OUT_DIV_SHIFT            (0U)
#define CRU_CLKSEL_CON36_CLK_CAM0_OUT_DIV_MASK             (0x3FU << CRU_CLKSEL_CON36_CLK_CAM0_OUT_DIV_SHIFT)           /* 0x0000003F */
#define CRU_CLKSEL_CON36_CLK_CAM0_OUT_SEL_SHIFT            (6U)
#define CRU_CLKSEL_CON36_CLK_CAM0_OUT_SEL_MASK             (0x3U << CRU_CLKSEL_CON36_CLK_CAM0_OUT_SEL_SHIFT)            /* 0x000000C0 */
#define CRU_CLKSEL_CON36_CLK_CAM1_OUT_DIV_SHIFT            (8U)
#define CRU_CLKSEL_CON36_CLK_CAM1_OUT_DIV_MASK             (0x3FU << CRU_CLKSEL_CON36_CLK_CAM1_OUT_DIV_SHIFT)           /* 0x00003F00 */
#define CRU_CLKSEL_CON36_CLK_CAM1_OUT_SEL_SHIFT            (14U)
#define CRU_CLKSEL_CON36_CLK_CAM1_OUT_SEL_MASK             (0x3U << CRU_CLKSEL_CON36_CLK_CAM1_OUT_SEL_SHIFT)            /* 0x0000C000 */
/* CLKSEL_CON37 */
#define CRU_CLKSEL_CON37_OFFSET                            (0x194U)
#define CRU_CLKSEL_CON37_ACLK_VO_SEL_SHIFT                 (0U)
#define CRU_CLKSEL_CON37_ACLK_VO_SEL_MASK                  (0x3U << CRU_CLKSEL_CON37_ACLK_VO_SEL_SHIFT)                 /* 0x00000003 */
#define CRU_CLKSEL_CON37_HCLK_VO_DIV_SHIFT                 (8U)
#define CRU_CLKSEL_CON37_HCLK_VO_DIV_MASK                  (0xFU << CRU_CLKSEL_CON37_HCLK_VO_DIV_SHIFT)                 /* 0x00000F00 */
#define CRU_CLKSEL_CON37_PCLK_VO_DIV_SHIFT                 (12U)
#define CRU_CLKSEL_CON37_PCLK_VO_DIV_MASK                  (0xFU << CRU_CLKSEL_CON37_PCLK_VO_DIV_SHIFT)                 /* 0x0000F000 */
/* CLKSEL_CON38 */
#define CRU_CLKSEL_CON38_OFFSET                            (0x198U)
#define CRU_CLKSEL_CON38_ACLK_VOP_PRE_DIV_SHIFT            (0U)
#define CRU_CLKSEL_CON38_ACLK_VOP_PRE_DIV_MASK             (0x1FU << CRU_CLKSEL_CON38_ACLK_VOP_PRE_DIV_SHIFT)           /* 0x0000001F */
#define CRU_CLKSEL_CON38_ACLK_VOP_PRE_SEL_SHIFT            (6U)
#define CRU_CLKSEL_CON38_ACLK_VOP_PRE_SEL_MASK             (0x3U << CRU_CLKSEL_CON38_ACLK_VOP_PRE_SEL_SHIFT)            /* 0x000000C0 */
#define CRU_CLKSEL_CON38_CLK_EDP_200M_SEL_SHIFT            (8U)
#define CRU_CLKSEL_CON38_CLK_EDP_200M_SEL_MASK             (0x3U << CRU_CLKSEL_CON38_CLK_EDP_200M_SEL_SHIFT)            /* 0x00000300 */
/* CLKSEL_CON39 */
#define CRU_CLKSEL_CON39_OFFSET                            (0x19CU)
#define CRU_CLKSEL_CON39_DCLK0_VOP_DIV_SHIFT               (0U)
#define CRU_CLKSEL_CON39_DCLK0_VOP_DIV_MASK                (0xFFU << CRU_CLKSEL_CON39_DCLK0_VOP_DIV_SHIFT)              /* 0x000000FF */
#define CRU_CLKSEL_CON39_DCLK0_VOP_SEL_SHIFT               (10U)
#define CRU_CLKSEL_CON39_DCLK0_VOP_SEL_MASK                (0x3U << CRU_CLKSEL_CON39_DCLK0_VOP_SEL_SHIFT)               /* 0x00000C00 */
/* CLKSEL_CON40 */
#define CRU_CLKSEL_CON40_OFFSET                            (0x1A0U)
#define CRU_CLKSEL_CON40_DCLK1_VOP_DIV_SHIFT               (0U)
#define CRU_CLKSEL_CON40_DCLK1_VOP_DIV_MASK                (0xFFU << CRU_CLKSEL_CON40_DCLK1_VOP_DIV_SHIFT)              /* 0x000000FF */
#define CRU_CLKSEL_CON40_DCLK1_VOP_SEL_SHIFT               (10U)
#define CRU_CLKSEL_CON40_DCLK1_VOP_SEL_MASK                (0x3U << CRU_CLKSEL_CON40_DCLK1_VOP_SEL_SHIFT)               /* 0x00000C00 */
/* CLKSEL_CON41 */
#define CRU_CLKSEL_CON41_OFFSET                            (0x1A4U)
#define CRU_CLKSEL_CON41_DCLK2_VOP_DIV_SHIFT               (0U)
#define CRU_CLKSEL_CON41_DCLK2_VOP_DIV_MASK                (0xFFU << CRU_CLKSEL_CON41_DCLK2_VOP_DIV_SHIFT)              /* 0x000000FF */
#define CRU_CLKSEL_CON41_DCLK2_VOP_SEL_SHIFT               (10U)
#define CRU_CLKSEL_CON41_DCLK2_VOP_SEL_MASK                (0x3U << CRU_CLKSEL_CON41_DCLK2_VOP_SEL_SHIFT)               /* 0x00000C00 */
/* CLKSEL_CON42 */
#define CRU_CLKSEL_CON42_OFFSET                            (0x1A8U)
#define CRU_CLKSEL_CON42_ACLK_VPU_PRE_DIV_SHIFT            (0U)
#define CRU_CLKSEL_CON42_ACLK_VPU_PRE_DIV_MASK             (0x1FU << CRU_CLKSEL_CON42_ACLK_VPU_PRE_DIV_SHIFT)           /* 0x0000001F */
#define CRU_CLKSEL_CON42_ACLK_VPU_PRE_SEL_SHIFT            (7U)
#define CRU_CLKSEL_CON42_ACLK_VPU_PRE_SEL_MASK             (0x1U << CRU_CLKSEL_CON42_ACLK_VPU_PRE_SEL_SHIFT)            /* 0x00000080 */
#define CRU_CLKSEL_CON42_HCLK_VPU_PRE_DIV_SHIFT            (8U)
#define CRU_CLKSEL_CON42_HCLK_VPU_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON42_HCLK_VPU_PRE_DIV_SHIFT)            /* 0x00000F00 */
/* CLKSEL_CON43 */
#define CRU_CLKSEL_CON43_OFFSET                            (0x1ACU)
#define CRU_CLKSEL_CON43_ACLK_RGA_PRE_SEL_SHIFT            (0U)
#define CRU_CLKSEL_CON43_ACLK_RGA_PRE_SEL_MASK             (0x3U << CRU_CLKSEL_CON43_ACLK_RGA_PRE_SEL_SHIFT)            /* 0x00000003 */
#define CRU_CLKSEL_CON43_CLK_RGA_CORE_SEL_SHIFT            (2U)
#define CRU_CLKSEL_CON43_CLK_RGA_CORE_SEL_MASK             (0x3U << CRU_CLKSEL_CON43_CLK_RGA_CORE_SEL_SHIFT)            /* 0x0000000C */
#define CRU_CLKSEL_CON43_CLK_IEP_CORE_SEL_SHIFT            (4U)
#define CRU_CLKSEL_CON43_CLK_IEP_CORE_SEL_MASK             (0x3U << CRU_CLKSEL_CON43_CLK_IEP_CORE_SEL_SHIFT)            /* 0x00000030 */
#define CRU_CLKSEL_CON43_DCLK_EBC_SEL_SHIFT                (6U)
#define CRU_CLKSEL_CON43_DCLK_EBC_SEL_MASK                 (0x3U << CRU_CLKSEL_CON43_DCLK_EBC_SEL_SHIFT)                /* 0x000000C0 */
#define CRU_CLKSEL_CON43_HCLK_RGA_PRE_DIV_SHIFT            (8U)
#define CRU_CLKSEL_CON43_HCLK_RGA_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON43_HCLK_RGA_PRE_DIV_SHIFT)            /* 0x00000F00 */
#define CRU_CLKSEL_CON43_PCLK_RGA_PRE_DIV_SHIFT            (12U)
#define CRU_CLKSEL_CON43_PCLK_RGA_PRE_DIV_MASK             (0xFU << CRU_CLKSEL_CON43_PCLK_RGA_PRE_DIV_SHIFT)            /* 0x0000F000 */
/* CLKSEL_CON44 */
#define CRU_CLKSEL_CON44_OFFSET                            (0x1B0U)
#define CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_DIV_SHIFT         (0U)
#define CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_DIV_MASK          (0x1FU << CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_DIV_SHIFT)        /* 0x0000001F */
#define CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_SEL_SHIFT         (6U)
#define CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_SEL_MASK          (0x3U << CRU_CLKSEL_CON44_ACLK_RKVENC_PRE_SEL_SHIFT)         /* 0x000000C0 */
#define CRU_CLKSEL_CON44_HCLK_RKVENC_PRE_DIV_SHIFT         (8U)
#define CRU_CLKSEL_CON44_HCLK_RKVENC_PRE_DIV_MASK          (0xFU << CRU_CLKSEL_CON44_HCLK_RKVENC_PRE_DIV_SHIFT)         /* 0x00000F00 */
/* CLKSEL_CON45 */
#define CRU_CLKSEL_CON45_OFFSET                            (0x1B4U)
#define CRU_CLKSEL_CON45_CLK_RKVENC_CORE_DIV_SHIFT         (0U)
#define CRU_CLKSEL_CON45_CLK_RKVENC_CORE_DIV_MASK          (0x1FU << CRU_CLKSEL_CON45_CLK_RKVENC_CORE_DIV_SHIFT)        /* 0x0000001F */
#define CRU_CLKSEL_CON45_CLK_RKVENC_CORE_SEL_SHIFT         (14U)
#define CRU_CLKSEL_CON45_CLK_RKVENC_CORE_SEL_MASK          (0x3U << CRU_CLKSEL_CON45_CLK_RKVENC_CORE_SEL_SHIFT)         /* 0x0000C000 */
/* CLKSEL_CON47 */
#define CRU_CLKSEL_CON47_OFFSET                            (0x1BCU)
#define CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_DIV_SHIFT         (0U)
#define CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_DIV_MASK          (0x1FU << CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_DIV_SHIFT)        /* 0x0000001F */
#define CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_SEL_SHIFT         (7U)
#define CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_SEL_MASK          (0x1U << CRU_CLKSEL_CON47_ACLK_RKVDEC_PRE_SEL_SHIFT)         /* 0x00000080 */
#define CRU_CLKSEL_CON47_HCLK_RKVDEC_PRE_DIV_SHIFT         (8U)
#define CRU_CLKSEL_CON47_HCLK_RKVDEC_PRE_DIV_MASK          (0xFU << CRU_CLKSEL_CON47_HCLK_RKVDEC_PRE_DIV_SHIFT)         /* 0x00000F00 */
/* CLKSEL_CON48 */
#define CRU_CLKSEL_CON48_OFFSET                            (0x1C0U)
#define CRU_CLKSEL_CON48_CLK_RKVDEC_CA_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON48_CLK_RKVDEC_CA_DIV_MASK            (0x1FU << CRU_CLKSEL_CON48_CLK_RKVDEC_CA_DIV_SHIFT)          /* 0x0000001F */
#define CRU_CLKSEL_CON48_CLK_RKVDEC_CA_SEL_SHIFT           (6U)
#define CRU_CLKSEL_CON48_CLK_RKVDEC_CA_SEL_MASK            (0x3U << CRU_CLKSEL_CON48_CLK_RKVDEC_CA_SEL_SHIFT)           /* 0x000000C0 */
/* CLKSEL_CON49 */
#define CRU_CLKSEL_CON49_OFFSET                            (0x1C4U)
#define CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_DIV_SHIFT      (0U)
#define CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_DIV_MASK       (0x1FU << CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_DIV_SHIFT)     /* 0x0000001F */
#define CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_SEL_SHIFT      (6U)
#define CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_SEL_MASK       (0x3U << CRU_CLKSEL_CON49_CLK_RKVDEC_HEVC_CA_SEL_SHIFT)      /* 0x000000C0 */
#define CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_DIV_SHIFT         (8U)
#define CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_DIV_MASK          (0x1FU << CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_DIV_SHIFT)        /* 0x00001F00 */
#define CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_SEL_SHIFT         (14U)
#define CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_SEL_MASK          (0x3U << CRU_CLKSEL_CON49_CLK_RKVDEC_CORE_SEL_SHIFT)         /* 0x0000C000 */
/* CLKSEL_CON50 */
#define CRU_CLKSEL_CON50_OFFSET                            (0x1C8U)
#define CRU_CLKSEL_CON50_ACLK_BUS_SEL_SHIFT                (0U)
#define CRU_CLKSEL_CON50_ACLK_BUS_SEL_MASK                 (0x3U << CRU_CLKSEL_CON50_ACLK_BUS_SEL_SHIFT)                /* 0x00000003 */
#define CRU_CLKSEL_CON50_PCLK_BUS_SEL_SHIFT                (4U)
#define CRU_CLKSEL_CON50_PCLK_BUS_SEL_MASK                 (0x3U << CRU_CLKSEL_CON50_PCLK_BUS_SEL_SHIFT)                /* 0x00000030 */
/* CLKSEL_CON51 */
#define CRU_CLKSEL_CON51_OFFSET                            (0x1CCU)
#define CRU_CLKSEL_CON51_CLK_TSADC_TSEN_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON51_CLK_TSADC_TSEN_DIV_MASK           (0x7U << CRU_CLKSEL_CON51_CLK_TSADC_TSEN_DIV_SHIFT)          /* 0x00000007 */
#define CRU_CLKSEL_CON51_CLK_TSADC_TSEN_SEL_SHIFT          (4U)
#define CRU_CLKSEL_CON51_CLK_TSADC_TSEN_SEL_MASK           (0x3U << CRU_CLKSEL_CON51_CLK_TSADC_TSEN_SEL_SHIFT)          /* 0x00000030 */
#define CRU_CLKSEL_CON51_CLK_TSADC_DIV_SHIFT               (8U)
#define CRU_CLKSEL_CON51_CLK_TSADC_DIV_MASK                (0x7FU << CRU_CLKSEL_CON51_CLK_TSADC_DIV_SHIFT)              /* 0x00007F00 */
/* CLKSEL_CON52 */
#define CRU_CLKSEL_CON52_OFFSET                            (0x1D0U)
#define CRU_CLKSEL_CON52_CLK_UART1_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON52_CLK_UART1_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON52_CLK_UART1_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON52_CLK_UART1_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON52_CLK_UART1_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON52_CLK_UART1_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON52_SCLK_UART1_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON52_SCLK_UART1_SEL_MASK               (0x3U << CRU_CLKSEL_CON52_SCLK_UART1_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON53 */
#define CRU_CLKSEL_CON53_OFFSET                            (0x1D4U)
#define CRU_CLKSEL_CON53_CLK_UART1_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON53_CLK_UART1_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON53_CLK_UART1_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON54 */
#define CRU_CLKSEL_CON54_OFFSET                            (0x1D8U)
#define CRU_CLKSEL_CON54_CLK_UART2_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON54_CLK_UART2_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON54_CLK_UART2_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON54_CLK_UART2_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON54_CLK_UART2_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON54_CLK_UART2_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON54_SCLK_UART2_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON54_SCLK_UART2_SEL_MASK               (0x3U << CRU_CLKSEL_CON54_SCLK_UART2_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON55 */
#define CRU_CLKSEL_CON55_OFFSET                            (0x1DCU)
#define CRU_CLKSEL_CON55_CLK_UART2_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON55_CLK_UART2_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON55_CLK_UART2_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON56 */
#define CRU_CLKSEL_CON56_OFFSET                            (0x1E0U)
#define CRU_CLKSEL_CON56_CLK_UART3_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON56_CLK_UART3_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON56_CLK_UART3_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON56_CLK_UART3_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON56_CLK_UART3_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON56_CLK_UART3_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON56_SCLK_UART3_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON56_SCLK_UART3_SEL_MASK               (0x3U << CRU_CLKSEL_CON56_SCLK_UART3_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON57 */
#define CRU_CLKSEL_CON57_OFFSET                            (0x1E4U)
#define CRU_CLKSEL_CON57_CLK_UART3_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON57_CLK_UART3_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON57_CLK_UART3_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON58 */
#define CRU_CLKSEL_CON58_OFFSET                            (0x1E8U)
#define CRU_CLKSEL_CON58_CLK_UART4_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON58_CLK_UART4_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON58_CLK_UART4_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON58_CLK_UART4_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON58_CLK_UART4_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON58_CLK_UART4_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON58_SCLK_UART4_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON58_SCLK_UART4_SEL_MASK               (0x3U << CRU_CLKSEL_CON58_SCLK_UART4_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON59 */
#define CRU_CLKSEL_CON59_OFFSET                            (0x1ECU)
#define CRU_CLKSEL_CON59_CLK_UART4_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON59_CLK_UART4_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON59_CLK_UART4_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON60 */
#define CRU_CLKSEL_CON60_OFFSET                            (0x1F0U)
#define CRU_CLKSEL_CON60_CLK_UART5_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON60_CLK_UART5_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON60_CLK_UART5_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON60_CLK_UART5_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON60_CLK_UART5_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON60_CLK_UART5_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON60_SCLK_UART5_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON60_SCLK_UART5_SEL_MASK               (0x3U << CRU_CLKSEL_CON60_SCLK_UART5_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON61 */
#define CRU_CLKSEL_CON61_OFFSET                            (0x1F4U)
#define CRU_CLKSEL_CON61_CLK_UART5_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON61_CLK_UART5_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON61_CLK_UART5_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON62 */
#define CRU_CLKSEL_CON62_OFFSET                            (0x1F8U)
#define CRU_CLKSEL_CON62_CLK_UART6_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON62_CLK_UART6_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON62_CLK_UART6_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON62_CLK_UART6_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON62_CLK_UART6_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON62_CLK_UART6_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON62_SCLK_UART6_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON62_SCLK_UART6_SEL_MASK               (0x3U << CRU_CLKSEL_CON62_SCLK_UART6_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON63 */
#define CRU_CLKSEL_CON63_OFFSET                            (0x1FCU)
#define CRU_CLKSEL_CON63_CLK_UART6_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON63_CLK_UART6_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON63_CLK_UART6_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON64 */
#define CRU_CLKSEL_CON64_OFFSET                            (0x200U)
#define CRU_CLKSEL_CON64_CLK_UART7_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON64_CLK_UART7_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON64_CLK_UART7_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON64_CLK_UART7_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON64_CLK_UART7_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON64_CLK_UART7_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON64_SCLK_UART7_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON64_SCLK_UART7_SEL_MASK               (0x3U << CRU_CLKSEL_CON64_SCLK_UART7_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON65 */
#define CRU_CLKSEL_CON65_OFFSET                            (0x204U)
#define CRU_CLKSEL_CON65_CLK_UART7_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON65_CLK_UART7_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON65_CLK_UART7_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON66 */
#define CRU_CLKSEL_CON66_OFFSET                            (0x208U)
#define CRU_CLKSEL_CON66_CLK_UART8_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON66_CLK_UART8_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON66_CLK_UART8_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON66_CLK_UART8_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON66_CLK_UART8_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON66_CLK_UART8_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON66_SCLK_UART8_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON66_SCLK_UART8_SEL_MASK               (0x3U << CRU_CLKSEL_CON66_SCLK_UART8_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON67 */
#define CRU_CLKSEL_CON67_OFFSET                            (0x20CU)
#define CRU_CLKSEL_CON67_CLK_UART8_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON67_CLK_UART8_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON67_CLK_UART8_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON68 */
#define CRU_CLKSEL_CON68_OFFSET                            (0x210U)
#define CRU_CLKSEL_CON68_CLK_UART9_SRC_DIV_SHIFT           (0U)
#define CRU_CLKSEL_CON68_CLK_UART9_SRC_DIV_MASK            (0x7FU << CRU_CLKSEL_CON68_CLK_UART9_SRC_DIV_SHIFT)          /* 0x0000007F */
#define CRU_CLKSEL_CON68_CLK_UART9_SRC_SEL_SHIFT           (8U)
#define CRU_CLKSEL_CON68_CLK_UART9_SRC_SEL_MASK            (0x3U << CRU_CLKSEL_CON68_CLK_UART9_SRC_SEL_SHIFT)           /* 0x00000300 */
#define CRU_CLKSEL_CON68_SCLK_UART9_SEL_SHIFT              (12U)
#define CRU_CLKSEL_CON68_SCLK_UART9_SEL_MASK               (0x3U << CRU_CLKSEL_CON68_SCLK_UART9_SEL_SHIFT)              /* 0x00003000 */
/* CLKSEL_CON69 */
#define CRU_CLKSEL_CON69_OFFSET                            (0x214U)
#define CRU_CLKSEL_CON69_CLK_UART9_FRAC_DIV_SHIFT          (0U)
#define CRU_CLKSEL_CON69_CLK_UART9_FRAC_DIV_MASK           (0xFFFFFFFFU << CRU_CLKSEL_CON69_CLK_UART9_FRAC_DIV_SHIFT)   /* 0xFFFFFFFF */
/* CLKSEL_CON70 */
#define CRU_CLKSEL_CON70_OFFSET                            (0x218U)
#define CRU_CLKSEL_CON70_CLK_CAN0_DIV_SHIFT                (0U)
#define CRU_CLKSEL_CON70_CLK_CAN0_DIV_MASK                 (0x1FU << CRU_CLKSEL_CON70_CLK_CAN0_DIV_SHIFT)               /* 0x0000001F */
#define CRU_CLKSEL_CON70_CLK_CAN0_SEL_SHIFT                (7U)
#define CRU_CLKSEL_CON70_CLK_CAN0_SEL_MASK                 (0x1U << CRU_CLKSEL_CON70_CLK_CAN0_SEL_SHIFT)                /* 0x00000080 */
#define CRU_CLKSEL_CON70_CLK_CAN1_DIV_SHIFT                (8U)
#define CRU_CLKSEL_CON70_CLK_CAN1_DIV_MASK                 (0x1FU << CRU_CLKSEL_CON70_CLK_CAN1_DIV_SHIFT)               /* 0x00001F00 */
#define CRU_CLKSEL_CON70_CLK_CAN1_SEL_SHIFT                (15U)
#define CRU_CLKSEL_CON70_CLK_CAN1_SEL_MASK                 (0x1U << CRU_CLKSEL_CON70_CLK_CAN1_SEL_SHIFT)                /* 0x00008000 */
/* CLKSEL_CON71 */
#define CRU_CLKSEL_CON71_OFFSET                            (0x21CU)
#define CRU_CLKSEL_CON71_CLK_CAN2_DIV_SHIFT                (0U)
#define CRU_CLKSEL_CON71_CLK_CAN2_DIV_MASK                 (0x1FU << CRU_CLKSEL_CON71_CLK_CAN2_DIV_SHIFT)               /* 0x0000001F */
#define CRU_CLKSEL_CON71_CLK_CAN2_SEL_SHIFT                (7U)
#define CRU_CLKSEL_CON71_CLK_CAN2_SEL_MASK                 (0x1U << CRU_CLKSEL_CON71_CLK_CAN2_SEL_SHIFT)                /* 0x00000080 */
#define CRU_CLKSEL_CON71_CLK_I2C_SEL_SHIFT                 (8U)
#define CRU_CLKSEL_CON71_CLK_I2C_SEL_MASK                  (0x3U << CRU_CLKSEL_CON71_CLK_I2C_SEL_SHIFT)                 /* 0x00000300 */
/* CLKSEL_CON72 */
#define CRU_CLKSEL_CON72_OFFSET                            (0x220U)
#define CRU_CLKSEL_CON72_CLK_SPI0_SEL_SHIFT                (0U)
#define CRU_CLKSEL_CON72_CLK_SPI0_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_SPI0_SEL_SHIFT)                /* 0x00000003 */
#define CRU_CLKSEL_CON72_CLK_SPI1_SEL_SHIFT                (2U)
#define CRU_CLKSEL_CON72_CLK_SPI1_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_SPI1_SEL_SHIFT)                /* 0x0000000C */
#define CRU_CLKSEL_CON72_CLK_SPI2_SEL_SHIFT                (4U)
#define CRU_CLKSEL_CON72_CLK_SPI2_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_SPI2_SEL_SHIFT)                /* 0x00000030 */
#define CRU_CLKSEL_CON72_CLK_SPI3_SEL_SHIFT                (6U)
#define CRU_CLKSEL_CON72_CLK_SPI3_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_SPI3_SEL_SHIFT)                /* 0x000000C0 */
#define CRU_CLKSEL_CON72_CLK_PWM1_SEL_SHIFT                (8U)
#define CRU_CLKSEL_CON72_CLK_PWM1_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_PWM1_SEL_SHIFT)                /* 0x00000300 */
#define CRU_CLKSEL_CON72_CLK_PWM2_SEL_SHIFT                (10U)
#define CRU_CLKSEL_CON72_CLK_PWM2_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_PWM2_SEL_SHIFT)                /* 0x00000C00 */
#define CRU_CLKSEL_CON72_CLK_PWM3_SEL_SHIFT                (12U)
#define CRU_CLKSEL_CON72_CLK_PWM3_SEL_MASK                 (0x3U << CRU_CLKSEL_CON72_CLK_PWM3_SEL_SHIFT)                /* 0x00003000 */
#define CRU_CLKSEL_CON72_DBCLK_GPIO_SEL_SHIFT              (14U)
#define CRU_CLKSEL_CON72_DBCLK_GPIO_SEL_MASK               (0x1U << CRU_CLKSEL_CON72_DBCLK_GPIO_SEL_SHIFT)              /* 0x00004000 */
/* CLKSEL_CON73 */
#define CRU_CLKSEL_CON73_OFFSET                            (0x224U)
#define CRU_CLKSEL_CON73_ACLK_TOP_HIGH_SEL_SHIFT           (0U)
#define CRU_CLKSEL_CON73_ACLK_TOP_HIGH_SEL_MASK            (0x3U << CRU_CLKSEL_CON73_ACLK_TOP_HIGH_SEL_SHIFT)           /* 0x00000003 */
#define CRU_CLKSEL_CON73_ACLK_TOP_LOW_SEL_SHIFT            (4U)
#define CRU_CLKSEL_CON73_ACLK_TOP_LOW_SEL_MASK             (0x3U << CRU_CLKSEL_CON73_ACLK_TOP_LOW_SEL_SHIFT)            /* 0x00000030 */
#define CRU_CLKSEL_CON73_HCLK_TOP_SEL_SHIFT                (8U)
#define CRU_CLKSEL_CON73_HCLK_TOP_SEL_MASK                 (0x3U << CRU_CLKSEL_CON73_HCLK_TOP_SEL_SHIFT)                /* 0x00000300 */
#define CRU_CLKSEL_CON73_PCLK_TOP_SEL_SHIFT                (12U)
#define CRU_CLKSEL_CON73_PCLK_TOP_SEL_MASK                 (0x3U << CRU_CLKSEL_CON73_PCLK_TOP_SEL_SHIFT)                /* 0x00003000 */
#define CRU_CLKSEL_CON73_CLK_OTPC_ARB_SEL_SHIFT            (15U)
#define CRU_CLKSEL_CON73_CLK_OTPC_ARB_SEL_MASK             (0x1U << CRU_CLKSEL_CON73_CLK_OTPC_ARB_SEL_SHIFT)            /* 0x00008000 */
/* CLKSEL_CON74 */
#define CRU_CLKSEL_CON74_OFFSET                            (0x228U)
#define CRU_CLKSEL_CON74_CLK_TESTOUT_DIV_SHIFT             (0U)
#define CRU_CLKSEL_CON74_CLK_TESTOUT_DIV_MASK              (0xFFU << CRU_CLKSEL_CON74_CLK_TESTOUT_DIV_SHIFT)            /* 0x000000FF */
#define CRU_CLKSEL_CON74_CLK_TESTOUT_SEL_SHIFT             (8U)
#define CRU_CLKSEL_CON74_CLK_TESTOUT_SEL_MASK              (0x1FU << CRU_CLKSEL_CON74_CLK_TESTOUT_SEL_SHIFT)            /* 0x00001F00 */
/* CLKSEL_CON75 */
#define CRU_CLKSEL_CON75_OFFSET                            (0x22CU)
#define CRU_CLKSEL_CON75_CLK_GPLL_DIV_400M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON75_CLK_GPLL_DIV_400M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON75_CLK_GPLL_DIV_400M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON75_CLK_GPLL_DIV_300M_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON75_CLK_GPLL_DIV_300M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON75_CLK_GPLL_DIV_300M_DIV_SHIFT)      /* 0x00001F00 */
/* CLKSEL_CON76 */
#define CRU_CLKSEL_CON76_OFFSET                            (0x230U)
#define CRU_CLKSEL_CON76_CLK_GPLL_DIV_200M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON76_CLK_GPLL_DIV_200M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON76_CLK_GPLL_DIV_200M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON76_CLK_GPLL_DIV_150M_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON76_CLK_GPLL_DIV_150M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON76_CLK_GPLL_DIV_150M_DIV_SHIFT)      /* 0x00001F00 */
/* CLKSEL_CON77 */
#define CRU_CLKSEL_CON77_OFFSET                            (0x234U)
#define CRU_CLKSEL_CON77_CLK_GPLL_DIV_100M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON77_CLK_GPLL_DIV_100M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON77_CLK_GPLL_DIV_100M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON77_CLK_GPLL_DIV_75M_DIV_SHIFT        (8U)
#define CRU_CLKSEL_CON77_CLK_GPLL_DIV_75M_DIV_MASK         (0x1FU << CRU_CLKSEL_CON77_CLK_GPLL_DIV_75M_DIV_SHIFT)       /* 0x00001F00 */
/* CLKSEL_CON78 */
#define CRU_CLKSEL_CON78_OFFSET                            (0x238U)
#define CRU_CLKSEL_CON78_CLK_GPLL_DIV_20M_DIV_SHIFT        (0U)
#define CRU_CLKSEL_CON78_CLK_GPLL_DIV_20M_DIV_MASK         (0x3FU << CRU_CLKSEL_CON78_CLK_GPLL_DIV_20M_DIV_SHIFT)       /* 0x0000003F */
#define CRU_CLKSEL_CON78_CLK_CPLL_DIV_500M_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON78_CLK_CPLL_DIV_500M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON78_CLK_CPLL_DIV_500M_DIV_SHIFT)      /* 0x00001F00 */
/* CLKSEL_CON79 */
#define CRU_CLKSEL_CON79_OFFSET                            (0x23CU)
#define CRU_CLKSEL_CON79_CLK_CPLL_DIV_333M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON79_CLK_CPLL_DIV_333M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON79_CLK_CPLL_DIV_333M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON79_CLK_CPLL_DIV_250M_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON79_CLK_CPLL_DIV_250M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON79_CLK_CPLL_DIV_250M_DIV_SHIFT)      /* 0x00001F00 */
/* CLKSEL_CON80 */
#define CRU_CLKSEL_CON80_OFFSET                            (0x240U)
#define CRU_CLKSEL_CON80_CLK_CPLL_DIV_125M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON80_CLK_CPLL_DIV_125M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON80_CLK_CPLL_DIV_125M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON80_CLK_CPLL_DIV_62P5_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON80_CLK_CPLL_DIV_62P5_DIV_MASK        (0x1FU << CRU_CLKSEL_CON80_CLK_CPLL_DIV_62P5_DIV_SHIFT)      /* 0x00001F00 */
/* CLKSEL_CON81 */
#define CRU_CLKSEL_CON81_OFFSET                            (0x244U)
#define CRU_CLKSEL_CON81_CLK_CPLL_DIV_50M_DIV_SHIFT        (0U)
#define CRU_CLKSEL_CON81_CLK_CPLL_DIV_50M_DIV_MASK         (0x1FU << CRU_CLKSEL_CON81_CLK_CPLL_DIV_50M_DIV_SHIFT)       /* 0x0000001F */
#define CRU_CLKSEL_CON81_CLK_CPLL_DIV_25M_DIV_SHIFT        (8U)
#define CRU_CLKSEL_CON81_CLK_CPLL_DIV_25M_DIV_MASK         (0x3FU << CRU_CLKSEL_CON81_CLK_CPLL_DIV_25M_DIV_SHIFT)       /* 0x00003F00 */
/* CLKSEL_CON82 */
#define CRU_CLKSEL_CON82_OFFSET                            (0x248U)
#define CRU_CLKSEL_CON82_CLK_CPLL_DIV_100M_DIV_SHIFT       (0U)
#define CRU_CLKSEL_CON82_CLK_CPLL_DIV_100M_DIV_MASK        (0x1FU << CRU_CLKSEL_CON82_CLK_CPLL_DIV_100M_DIV_SHIFT)      /* 0x0000001F */
#define CRU_CLKSEL_CON82_CLK_OSC0_DIV_750K_DIV_SHIFT       (8U)
#define CRU_CLKSEL_CON82_CLK_OSC0_DIV_750K_DIV_MASK        (0x3FU << CRU_CLKSEL_CON82_CLK_OSC0_DIV_750K_DIV_SHIFT)      /* 0x00003F00 */
/* CLKSEL_CON83 */
#define CRU_CLKSEL_CON83_OFFSET                            (0x24CU)
#define CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_DIV_SHIFT     (0U)
#define CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_DIV_MASK      (0x7FU << CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_DIV_SHIFT)    /* 0x0000007F */
#define CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_SEL_SHIFT     (8U)
#define CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_SEL_MASK      (0x3U << CRU_CLKSEL_CON83_CLK_I2S3_2CH_RX_SRC_SEL_SHIFT)     /* 0x00000300 */
#define CRU_CLKSEL_CON83_MCLK_I2S3_2CH_RX_SEL_SHIFT        (10U)
#define CRU_CLKSEL_CON83_MCLK_I2S3_2CH_RX_SEL_MASK         (0x3U << CRU_CLKSEL_CON83_MCLK_I2S3_2CH_RX_SEL_SHIFT)        /* 0x00000C00 */
#define CRU_CLKSEL_CON83_I2S3_MCLKOUT_RX_SEL_SHIFT         (15U)
#define CRU_CLKSEL_CON83_I2S3_MCLKOUT_RX_SEL_MASK          (0x1U << CRU_CLKSEL_CON83_I2S3_MCLKOUT_RX_SEL_SHIFT)         /* 0x00008000 */
/* CLKSEL_CON84 */
#define CRU_CLKSEL_CON84_OFFSET                            (0x250U)
#define CRU_CLKSEL_CON84_CLK_I2S3_2CH_RX_FRAC_DIV_SHIFT    (0U)
#define CRU_CLKSEL_CON84_CLK_I2S3_2CH_RX_FRAC_DIV_MASK     (0xFFFFFFFFU << CRU_CLKSEL_CON84_CLK_I2S3_2CH_RX_FRAC_DIV_SHIFT) /* 0xFFFFFFFF */
/* GATE_CON00 */
#define CRU_GATE_CON00_OFFSET                              (0x300U)
#define CRU_GATE_CON00_CLK_CORE_EN_SHIFT                   (0U)
#define CRU_GATE_CON00_CLK_CORE_EN_MASK                    (0x1U << CRU_GATE_CON00_CLK_CORE_EN_SHIFT)                   /* 0x00000001 */
#define CRU_GATE_CON00_CLK_CORE0_EN_SHIFT                  (1U)
#define CRU_GATE_CON00_CLK_CORE0_EN_MASK                   (0x1U << CRU_GATE_CON00_CLK_CORE0_EN_SHIFT)                  /* 0x00000002 */
#define CRU_GATE_CON00_CLK_CORE1_EN_SHIFT                  (2U)
#define CRU_GATE_CON00_CLK_CORE1_EN_MASK                   (0x1U << CRU_GATE_CON00_CLK_CORE1_EN_SHIFT)                  /* 0x00000004 */
#define CRU_GATE_CON00_CLK_CORE2_EN_SHIFT                  (3U)
#define CRU_GATE_CON00_CLK_CORE2_EN_MASK                   (0x1U << CRU_GATE_CON00_CLK_CORE2_EN_SHIFT)                  /* 0x00000008 */
#define CRU_GATE_CON00_CLK_CORE3_EN_SHIFT                  (4U)
#define CRU_GATE_CON00_CLK_CORE3_EN_MASK                   (0x1U << CRU_GATE_CON00_CLK_CORE3_EN_SHIFT)                  /* 0x00000010 */
#define CRU_GATE_CON00_SCLK_CORE_SRC_EN_SHIFT              (5U)
#define CRU_GATE_CON00_SCLK_CORE_SRC_EN_MASK               (0x1U << CRU_GATE_CON00_SCLK_CORE_SRC_EN_SHIFT)              /* 0x00000020 */
#define CRU_GATE_CON00_CLK_NPLL_CORE_EN_SHIFT              (6U)
#define CRU_GATE_CON00_CLK_NPLL_CORE_EN_MASK               (0x1U << CRU_GATE_CON00_CLK_NPLL_CORE_EN_SHIFT)              /* 0x00000040 */
#define CRU_GATE_CON00_SCLK_CORE_EN_SHIFT                  (7U)
#define CRU_GATE_CON00_SCLK_CORE_EN_MASK                   (0x1U << CRU_GATE_CON00_SCLK_CORE_EN_SHIFT)                  /* 0x00000080 */
#define CRU_GATE_CON00_ATCLK_CORE_EN_SHIFT                 (8U)
#define CRU_GATE_CON00_ATCLK_CORE_EN_MASK                  (0x1U << CRU_GATE_CON00_ATCLK_CORE_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON00_GICCLK_CORE_EN_SHIFT                (9U)
#define CRU_GATE_CON00_GICCLK_CORE_EN_MASK                 (0x1U << CRU_GATE_CON00_GICCLK_CORE_EN_SHIFT)                /* 0x00000200 */
#define CRU_GATE_CON00_PCLK_CORE_PRE_EN_SHIFT              (10U)
#define CRU_GATE_CON00_PCLK_CORE_PRE_EN_MASK               (0x1U << CRU_GATE_CON00_PCLK_CORE_PRE_EN_SHIFT)              /* 0x00000400 */
#define CRU_GATE_CON00_PERIPHCLK_CORE_PRE_EN_SHIFT         (11U)
#define CRU_GATE_CON00_PERIPHCLK_CORE_PRE_EN_MASK          (0x1U << CRU_GATE_CON00_PERIPHCLK_CORE_PRE_EN_SHIFT)         /* 0x00000800 */
#define CRU_GATE_CON00_PCLK_CORE_EN_SHIFT                  (12U)
#define CRU_GATE_CON00_PCLK_CORE_EN_MASK                   (0x1U << CRU_GATE_CON00_PCLK_CORE_EN_SHIFT)                  /* 0x00001000 */
#define CRU_GATE_CON00_PERIPHCLK_CORE_EN_SHIFT             (13U)
#define CRU_GATE_CON00_PERIPHCLK_CORE_EN_MASK              (0x1U << CRU_GATE_CON00_PERIPHCLK_CORE_EN_SHIFT)             /* 0x00002000 */
#define CRU_GATE_CON00_TSCLK_CORE_EN_SHIFT                 (14U)
#define CRU_GATE_CON00_TSCLK_CORE_EN_MASK                  (0x1U << CRU_GATE_CON00_TSCLK_CORE_EN_SHIFT)                 /* 0x00004000 */
#define CRU_GATE_CON00_CNTCLK_CORE_EN_SHIFT                (15U)
#define CRU_GATE_CON00_CNTCLK_CORE_EN_MASK                 (0x1U << CRU_GATE_CON00_CNTCLK_CORE_EN_SHIFT)                /* 0x00008000 */
/* GATE_CON01 */
#define CRU_GATE_CON01_OFFSET                              (0x304U)
#define CRU_GATE_CON01_ACLK_CORE_EN_SHIFT                  (0U)
#define CRU_GATE_CON01_ACLK_CORE_EN_MASK                   (0x1U << CRU_GATE_CON01_ACLK_CORE_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON01_ACLK_CORE_NIU2DDR_EN_SHIFT          (1U)
#define CRU_GATE_CON01_ACLK_CORE_NIU2DDR_EN_MASK           (0x1U << CRU_GATE_CON01_ACLK_CORE_NIU2DDR_EN_SHIFT)          /* 0x00000002 */
#define CRU_GATE_CON01_ACLK_CORE_NIU2BUS_EN_SHIFT          (2U)
#define CRU_GATE_CON01_ACLK_CORE_NIU2BUS_EN_MASK           (0x1U << CRU_GATE_CON01_ACLK_CORE_NIU2BUS_EN_SHIFT)          /* 0x00000004 */
#define CRU_GATE_CON01_PCLK_DBG_NIU_EN_SHIFT               (3U)
#define CRU_GATE_CON01_PCLK_DBG_NIU_EN_MASK                (0x1U << CRU_GATE_CON01_PCLK_DBG_NIU_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON01_PCLK_DBG_EN_SHIFT                   (4U)
#define CRU_GATE_CON01_PCLK_DBG_EN_MASK                    (0x1U << CRU_GATE_CON01_PCLK_DBG_EN_SHIFT)                   /* 0x00000010 */
#define CRU_GATE_CON01_PCLK_DBG_DAPLITE_EN_SHIFT           (5U)
#define CRU_GATE_CON01_PCLK_DBG_DAPLITE_EN_MASK            (0x1U << CRU_GATE_CON01_PCLK_DBG_DAPLITE_EN_SHIFT)           /* 0x00000020 */
#define CRU_GATE_CON01_ACLK_ADB400_CORE2GIC_EN_SHIFT       (6U)
#define CRU_GATE_CON01_ACLK_ADB400_CORE2GIC_EN_MASK        (0x1U << CRU_GATE_CON01_ACLK_ADB400_CORE2GIC_EN_SHIFT)       /* 0x00000040 */
#define CRU_GATE_CON01_ACLK_ADB400_GIC2CORE_EN_SHIFT       (7U)
#define CRU_GATE_CON01_ACLK_ADB400_GIC2CORE_EN_MASK        (0x1U << CRU_GATE_CON01_ACLK_ADB400_GIC2CORE_EN_SHIFT)       /* 0x00000080 */
#define CRU_GATE_CON01_PCLK_CORE_GRF_EN_SHIFT              (8U)
#define CRU_GATE_CON01_PCLK_CORE_GRF_EN_MASK               (0x1U << CRU_GATE_CON01_PCLK_CORE_GRF_EN_SHIFT)              /* 0x00000100 */
#define CRU_GATE_CON01_PCLK_CORE_PVTM_EN_SHIFT             (9U)
#define CRU_GATE_CON01_PCLK_CORE_PVTM_EN_MASK              (0x1U << CRU_GATE_CON01_PCLK_CORE_PVTM_EN_SHIFT)             /* 0x00000200 */
#define CRU_GATE_CON01_CLK_CORE_PVTM_EN_SHIFT              (10U)
#define CRU_GATE_CON01_CLK_CORE_PVTM_EN_MASK               (0x1U << CRU_GATE_CON01_CLK_CORE_PVTM_EN_SHIFT)              /* 0x00000400 */
#define CRU_GATE_CON01_CLK_CORE_PVTM_CORE_EN_SHIFT         (11U)
#define CRU_GATE_CON01_CLK_CORE_PVTM_CORE_EN_MASK          (0x1U << CRU_GATE_CON01_CLK_CORE_PVTM_CORE_EN_SHIFT)         /* 0x00000800 */
#define CRU_GATE_CON01_CLK_CORE_PVTPLL_EN_SHIFT            (12U)
#define CRU_GATE_CON01_CLK_CORE_PVTPLL_EN_MASK             (0x1U << CRU_GATE_CON01_CLK_CORE_PVTPLL_EN_SHIFT)            /* 0x00001000 */
#define CRU_GATE_CON01_CLK_CORE_DIV2_EN_SHIFT              (13U)
#define CRU_GATE_CON01_CLK_CORE_DIV2_EN_MASK               (0x1U << CRU_GATE_CON01_CLK_CORE_DIV2_EN_SHIFT)              /* 0x00002000 */
#define CRU_GATE_CON01_CLK_APLL_CORE_EN_SHIFT              (14U)
#define CRU_GATE_CON01_CLK_APLL_CORE_EN_MASK               (0x1U << CRU_GATE_CON01_CLK_APLL_CORE_EN_SHIFT)              /* 0x00004000 */
#define CRU_GATE_CON01_CLK_JTAG_EN_SHIFT                   (15U)
#define CRU_GATE_CON01_CLK_JTAG_EN_MASK                    (0x1U << CRU_GATE_CON01_CLK_JTAG_EN_SHIFT)                   /* 0x00008000 */
/* GATE_CON02 */
#define CRU_GATE_CON02_OFFSET                              (0x308U)
#define CRU_GATE_CON02_CLK_GPU_SRC_EN_SHIFT                (0U)
#define CRU_GATE_CON02_CLK_GPU_SRC_EN_MASK                 (0x1U << CRU_GATE_CON02_CLK_GPU_SRC_EN_SHIFT)                /* 0x00000001 */
#define CRU_GATE_CON02_PCLK_GPU_PRE_EN_SHIFT               (2U)
#define CRU_GATE_CON02_PCLK_GPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON02_PCLK_GPU_PRE_EN_SHIFT)               /* 0x00000004 */
#define CRU_GATE_CON02_ACLK_GPU_EN_SHIFT                   (3U)
#define CRU_GATE_CON02_ACLK_GPU_EN_MASK                    (0x1U << CRU_GATE_CON02_ACLK_GPU_EN_SHIFT)                   /* 0x00000008 */
#define CRU_GATE_CON02_ACLK_GPU_NIU_EN_SHIFT               (4U)
#define CRU_GATE_CON02_ACLK_GPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON02_ACLK_GPU_NIU_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON02_PCLK_GPU_NIU_EN_SHIFT               (5U)
#define CRU_GATE_CON02_PCLK_GPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON02_PCLK_GPU_NIU_EN_SHIFT)               /* 0x00000020 */
#define CRU_GATE_CON02_PCLK_GPU_PVTM_EN_SHIFT              (6U)
#define CRU_GATE_CON02_PCLK_GPU_PVTM_EN_MASK               (0x1U << CRU_GATE_CON02_PCLK_GPU_PVTM_EN_SHIFT)              /* 0x00000040 */
#define CRU_GATE_CON02_CLK_GPU_PVTM_EN_SHIFT               (7U)
#define CRU_GATE_CON02_CLK_GPU_PVTM_EN_MASK                (0x1U << CRU_GATE_CON02_CLK_GPU_PVTM_EN_SHIFT)               /* 0x00000080 */
#define CRU_GATE_CON02_CLK_GPU_PVTM_CORE_EN_SHIFT          (8U)
#define CRU_GATE_CON02_CLK_GPU_PVTM_CORE_EN_MASK           (0x1U << CRU_GATE_CON02_CLK_GPU_PVTM_CORE_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON02_CLK_GPU_PVTPLL_EN_SHIFT             (9U)
#define CRU_GATE_CON02_CLK_GPU_PVTPLL_EN_MASK              (0x1U << CRU_GATE_CON02_CLK_GPU_PVTPLL_EN_SHIFT)             /* 0x00000200 */
#define CRU_GATE_CON02_CLK_GPU_DIV2_EN_SHIFT               (10U)
#define CRU_GATE_CON02_CLK_GPU_DIV2_EN_MASK                (0x1U << CRU_GATE_CON02_CLK_GPU_DIV2_EN_SHIFT)               /* 0x00000400 */
#define CRU_GATE_CON02_ACLK_GPU_PRE_EN_SHIFT               (11U)
#define CRU_GATE_CON02_ACLK_GPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON02_ACLK_GPU_PRE_EN_SHIFT)               /* 0x00000800 */
/* GATE_CON03 */
#define CRU_GATE_CON03_OFFSET                              (0x30CU)
#define CRU_GATE_CON03_CLK_NPU_SRC_EN_SHIFT                (0U)
#define CRU_GATE_CON03_CLK_NPU_SRC_EN_MASK                 (0x1U << CRU_GATE_CON03_CLK_NPU_SRC_EN_SHIFT)                /* 0x00000001 */
#define CRU_GATE_CON03_CLK_NPU_NP5_EN_SHIFT                (1U)
#define CRU_GATE_CON03_CLK_NPU_NP5_EN_MASK                 (0x1U << CRU_GATE_CON03_CLK_NPU_NP5_EN_SHIFT)                /* 0x00000002 */
#define CRU_GATE_CON03_HCLK_NPU_PRE_EN_SHIFT               (2U)
#define CRU_GATE_CON03_HCLK_NPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON03_HCLK_NPU_PRE_EN_SHIFT)               /* 0x00000004 */
#define CRU_GATE_CON03_PCLK_NPU_PRE_EN_SHIFT               (3U)
#define CRU_GATE_CON03_PCLK_NPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON03_PCLK_NPU_PRE_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON03_ACLK_NPU_NIU_EN_SHIFT               (4U)
#define CRU_GATE_CON03_ACLK_NPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON03_ACLK_NPU_NIU_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON03_HCLK_NPU_NIU_EN_SHIFT               (5U)
#define CRU_GATE_CON03_HCLK_NPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON03_HCLK_NPU_NIU_EN_SHIFT)               /* 0x00000020 */
#define CRU_GATE_CON03_PCLK_NPU_NIU_EN_SHIFT               (6U)
#define CRU_GATE_CON03_PCLK_NPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON03_PCLK_NPU_NIU_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON03_ACLK_RKNN_EN_SHIFT                  (7U)
#define CRU_GATE_CON03_ACLK_RKNN_EN_MASK                   (0x1U << CRU_GATE_CON03_ACLK_RKNN_EN_SHIFT)                  /* 0x00000080 */
#define CRU_GATE_CON03_HCLK_RKNN_EN_SHIFT                  (8U)
#define CRU_GATE_CON03_HCLK_RKNN_EN_MASK                   (0x1U << CRU_GATE_CON03_HCLK_RKNN_EN_SHIFT)                  /* 0x00000100 */
#define CRU_GATE_CON03_PCLK_NPU_PVTM_EN_SHIFT              (9U)
#define CRU_GATE_CON03_PCLK_NPU_PVTM_EN_MASK               (0x1U << CRU_GATE_CON03_PCLK_NPU_PVTM_EN_SHIFT)              /* 0x00000200 */
#define CRU_GATE_CON03_CLK_NPU_PVTM_EN_SHIFT               (10U)
#define CRU_GATE_CON03_CLK_NPU_PVTM_EN_MASK                (0x1U << CRU_GATE_CON03_CLK_NPU_PVTM_EN_SHIFT)               /* 0x00000400 */
#define CRU_GATE_CON03_CLK_NPU_PVTM_CORE_EN_SHIFT          (11U)
#define CRU_GATE_CON03_CLK_NPU_PVTM_CORE_EN_MASK           (0x1U << CRU_GATE_CON03_CLK_NPU_PVTM_CORE_EN_SHIFT)          /* 0x00000800 */
#define CRU_GATE_CON03_CLK_NPU_PVTPLL_EN_SHIFT             (12U)
#define CRU_GATE_CON03_CLK_NPU_PVTPLL_EN_MASK              (0x1U << CRU_GATE_CON03_CLK_NPU_PVTPLL_EN_SHIFT)             /* 0x00001000 */
#define CRU_GATE_CON03_CLK_NPU_DIV2_EN_SHIFT               (13U)
#define CRU_GATE_CON03_CLK_NPU_DIV2_EN_MASK                (0x1U << CRU_GATE_CON03_CLK_NPU_DIV2_EN_SHIFT)               /* 0x00002000 */
/* GATE_CON04 */
#define CRU_GATE_CON04_OFFSET                              (0x310U)
#define CRU_GATE_CON04_CLK_DDRPHY1X_EN_SHIFT               (0U)
#define CRU_GATE_CON04_CLK_DDRPHY1X_EN_MASK                (0x1U << CRU_GATE_CON04_CLK_DDRPHY1X_EN_SHIFT)               /* 0x00000001 */
#define CRU_GATE_CON04_CLK_DPLL_DDR_EN_SHIFT               (1U)
#define CRU_GATE_CON04_CLK_DPLL_DDR_EN_MASK                (0x1U << CRU_GATE_CON04_CLK_DPLL_DDR_EN_SHIFT)               /* 0x00000002 */
#define CRU_GATE_CON04_ACLK_MSCH_DIV2_EN_SHIFT             (2U)
#define CRU_GATE_CON04_ACLK_MSCH_DIV2_EN_MASK              (0x1U << CRU_GATE_CON04_ACLK_MSCH_DIV2_EN_SHIFT)             /* 0x00000004 */
#define CRU_GATE_CON04_CLK_HWFFC_CTRL_EN_SHIFT             (3U)
#define CRU_GATE_CON04_CLK_HWFFC_CTRL_EN_MASK              (0x1U << CRU_GATE_CON04_CLK_HWFFC_CTRL_EN_SHIFT)             /* 0x00000008 */
#define CRU_GATE_CON04_ACLK_DDRSCRAMBLE_EN_SHIFT           (4U)
#define CRU_GATE_CON04_ACLK_DDRSCRAMBLE_EN_MASK            (0x1U << CRU_GATE_CON04_ACLK_DDRSCRAMBLE_EN_SHIFT)           /* 0x00000010 */
#define CRU_GATE_CON04_ACLK_MSCH_EN_SHIFT                  (5U)
#define CRU_GATE_CON04_ACLK_MSCH_EN_MASK                   (0x1U << CRU_GATE_CON04_ACLK_MSCH_EN_SHIFT)                  /* 0x00000020 */
#define CRU_GATE_CON04_CLK_DDR_ALWAYSON_EN_SHIFT           (6U)
#define CRU_GATE_CON04_CLK_DDR_ALWAYSON_EN_MASK            (0x1U << CRU_GATE_CON04_CLK_DDR_ALWAYSON_EN_SHIFT)           /* 0x00000040 */
#define CRU_GATE_CON04_ACLK_DDRSPLIT_EN_SHIFT              (8U)
#define CRU_GATE_CON04_ACLK_DDRSPLIT_EN_MASK               (0x1U << CRU_GATE_CON04_ACLK_DDRSPLIT_EN_SHIFT)              /* 0x00000100 */
#define CRU_GATE_CON04_CLK_DDRDFI_CTL_EN_SHIFT             (9U)
#define CRU_GATE_CON04_CLK_DDRDFI_CTL_EN_MASK              (0x1U << CRU_GATE_CON04_CLK_DDRDFI_CTL_EN_SHIFT)             /* 0x00000200 */
#define CRU_GATE_CON04_ACLK_DMA2DDR_EN_SHIFT               (11U)
#define CRU_GATE_CON04_ACLK_DMA2DDR_EN_MASK                (0x1U << CRU_GATE_CON04_ACLK_DMA2DDR_EN_SHIFT)               /* 0x00000800 */
#define CRU_GATE_CON04_CLK_DDRMON_EN_SHIFT                 (13U)
#define CRU_GATE_CON04_CLK_DDRMON_EN_MASK                  (0x1U << CRU_GATE_CON04_CLK_DDRMON_EN_SHIFT)                 /* 0x00002000 */
#define CRU_GATE_CON04_CLK24_DDRMON_EN_SHIFT               (15U)
#define CRU_GATE_CON04_CLK24_DDRMON_EN_MASK                (0x1U << CRU_GATE_CON04_CLK24_DDRMON_EN_SHIFT)               /* 0x00008000 */
/* GATE_CON05 */
#define CRU_GATE_CON05_OFFSET                              (0x314U)
#define CRU_GATE_CON05_ACLK_GIC_AUDIO_EN_SHIFT             (0U)
#define CRU_GATE_CON05_ACLK_GIC_AUDIO_EN_MASK              (0x1U << CRU_GATE_CON05_ACLK_GIC_AUDIO_EN_SHIFT)             /* 0x00000001 */
#define CRU_GATE_CON05_HCLK_GIC_AUDIO_EN_SHIFT             (1U)
#define CRU_GATE_CON05_HCLK_GIC_AUDIO_EN_MASK              (0x1U << CRU_GATE_CON05_HCLK_GIC_AUDIO_EN_SHIFT)             /* 0x00000002 */
#define CRU_GATE_CON05_ACLK_GIC_AUDIO_NIU_EN_SHIFT         (2U)
#define CRU_GATE_CON05_ACLK_GIC_AUDIO_NIU_EN_MASK          (0x1U << CRU_GATE_CON05_ACLK_GIC_AUDIO_NIU_EN_SHIFT)         /* 0x00000004 */
#define CRU_GATE_CON05_HCLK_GIC_AUDIO_NIU_EN_SHIFT         (3U)
#define CRU_GATE_CON05_HCLK_GIC_AUDIO_NIU_EN_MASK          (0x1U << CRU_GATE_CON05_HCLK_GIC_AUDIO_NIU_EN_SHIFT)         /* 0x00000008 */
#define CRU_GATE_CON05_ACLK_GIC600_EN_SHIFT                (4U)
#define CRU_GATE_CON05_ACLK_GIC600_EN_MASK                 (0x1U << CRU_GATE_CON05_ACLK_GIC600_EN_SHIFT)                /* 0x00000010 */
#define CRU_GATE_CON05_ACLK_GICADB_CORE2GIC_EN_SHIFT       (5U)
#define CRU_GATE_CON05_ACLK_GICADB_CORE2GIC_EN_MASK        (0x1U << CRU_GATE_CON05_ACLK_GICADB_CORE2GIC_EN_SHIFT)       /* 0x00000020 */
#define CRU_GATE_CON05_ACLK_GICADB_GIC2CORE_EN_SHIFT       (6U)
#define CRU_GATE_CON05_ACLK_GICADB_GIC2CORE_EN_MASK        (0x1U << CRU_GATE_CON05_ACLK_GICADB_GIC2CORE_EN_SHIFT)       /* 0x00000040 */
#define CRU_GATE_CON05_ACLK_SPINLOCK_EN_SHIFT              (7U)
#define CRU_GATE_CON05_ACLK_SPINLOCK_EN_MASK               (0x1U << CRU_GATE_CON05_ACLK_SPINLOCK_EN_SHIFT)              /* 0x00000080 */
#define CRU_GATE_CON05_HCLK_SDMMC_BUFFER_EN_SHIFT          (8U)
#define CRU_GATE_CON05_HCLK_SDMMC_BUFFER_EN_MASK           (0x1U << CRU_GATE_CON05_HCLK_SDMMC_BUFFER_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON05_DCLK_SDMMC_BUFFER_EN_SHIFT          (9U)
#define CRU_GATE_CON05_DCLK_SDMMC_BUFFER_EN_MASK           (0x1U << CRU_GATE_CON05_DCLK_SDMMC_BUFFER_EN_SHIFT)          /* 0x00000200 */
#define CRU_GATE_CON05_HCLK_I2S0_8CH_EN_SHIFT              (10U)
#define CRU_GATE_CON05_HCLK_I2S0_8CH_EN_MASK               (0x1U << CRU_GATE_CON05_HCLK_I2S0_8CH_EN_SHIFT)              /* 0x00000400 */
#define CRU_GATE_CON05_HCLK_I2S1_8CH_EN_SHIFT              (11U)
#define CRU_GATE_CON05_HCLK_I2S1_8CH_EN_MASK               (0x1U << CRU_GATE_CON05_HCLK_I2S1_8CH_EN_SHIFT)              /* 0x00000800 */
#define CRU_GATE_CON05_HCLK_I2S2_2CH_EN_SHIFT              (12U)
#define CRU_GATE_CON05_HCLK_I2S2_2CH_EN_MASK               (0x1U << CRU_GATE_CON05_HCLK_I2S2_2CH_EN_SHIFT)              /* 0x00001000 */
#define CRU_GATE_CON05_HCLK_I2S3_2CH_EN_SHIFT              (13U)
#define CRU_GATE_CON05_HCLK_I2S3_2CH_EN_MASK               (0x1U << CRU_GATE_CON05_HCLK_I2S3_2CH_EN_SHIFT)              /* 0x00002000 */
#define CRU_GATE_CON05_HCLK_PDM_EN_SHIFT                   (14U)
#define CRU_GATE_CON05_HCLK_PDM_EN_MASK                    (0x1U << CRU_GATE_CON05_HCLK_PDM_EN_SHIFT)                   /* 0x00004000 */
#define CRU_GATE_CON05_MCLK_PDM_EN_SHIFT                   (15U)
#define CRU_GATE_CON05_MCLK_PDM_EN_MASK                    (0x1U << CRU_GATE_CON05_MCLK_PDM_EN_SHIFT)                   /* 0x00008000 */
/* GATE_CON06 */
#define CRU_GATE_CON06_OFFSET                              (0x318U)
#define CRU_GATE_CON06_CLK_I2S0_8CH_TX_SRC_EN_SHIFT        (0U)
#define CRU_GATE_CON06_CLK_I2S0_8CH_TX_SRC_EN_MASK         (0x1U << CRU_GATE_CON06_CLK_I2S0_8CH_TX_SRC_EN_SHIFT)        /* 0x00000001 */
#define CRU_GATE_CON06_CLK_I2S0_8CH_TX_FRAC_EN_SHIFT       (1U)
#define CRU_GATE_CON06_CLK_I2S0_8CH_TX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON06_CLK_I2S0_8CH_TX_FRAC_EN_SHIFT)       /* 0x00000002 */
#define CRU_GATE_CON06_MCLK_I2S0_8CH_TX_EN_SHIFT           (2U)
#define CRU_GATE_CON06_MCLK_I2S0_8CH_TX_EN_MASK            (0x1U << CRU_GATE_CON06_MCLK_I2S0_8CH_TX_EN_SHIFT)           /* 0x00000004 */
#define CRU_GATE_CON06_I2S0_MCLKOUT_TX_EN_SHIFT            (3U)
#define CRU_GATE_CON06_I2S0_MCLKOUT_TX_EN_MASK             (0x1U << CRU_GATE_CON06_I2S0_MCLKOUT_TX_EN_SHIFT)            /* 0x00000008 */
#define CRU_GATE_CON06_CLK_I2S0_8CH_RX_SRC_EN_SHIFT        (4U)
#define CRU_GATE_CON06_CLK_I2S0_8CH_RX_SRC_EN_MASK         (0x1U << CRU_GATE_CON06_CLK_I2S0_8CH_RX_SRC_EN_SHIFT)        /* 0x00000010 */
#define CRU_GATE_CON06_CLK_I2S0_8CH_RX_FRAC_EN_SHIFT       (5U)
#define CRU_GATE_CON06_CLK_I2S0_8CH_RX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON06_CLK_I2S0_8CH_RX_FRAC_EN_SHIFT)       /* 0x00000020 */
#define CRU_GATE_CON06_MCLK_I2S0_8CH_RX_EN_SHIFT           (6U)
#define CRU_GATE_CON06_MCLK_I2S0_8CH_RX_EN_MASK            (0x1U << CRU_GATE_CON06_MCLK_I2S0_8CH_RX_EN_SHIFT)           /* 0x00000040 */
#define CRU_GATE_CON06_I2S0_MCLKOUT_RX_EN_SHIFT            (7U)
#define CRU_GATE_CON06_I2S0_MCLKOUT_RX_EN_MASK             (0x1U << CRU_GATE_CON06_I2S0_MCLKOUT_RX_EN_SHIFT)            /* 0x00000080 */
#define CRU_GATE_CON06_CLK_I2S1_8CH_TX_SRC_EN_SHIFT        (8U)
#define CRU_GATE_CON06_CLK_I2S1_8CH_TX_SRC_EN_MASK         (0x1U << CRU_GATE_CON06_CLK_I2S1_8CH_TX_SRC_EN_SHIFT)        /* 0x00000100 */
#define CRU_GATE_CON06_CLK_I2S1_8CH_TX_FRAC_EN_SHIFT       (9U)
#define CRU_GATE_CON06_CLK_I2S1_8CH_TX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON06_CLK_I2S1_8CH_TX_FRAC_EN_SHIFT)       /* 0x00000200 */
#define CRU_GATE_CON06_MCLK_I2S1_8CH_TX_EN_SHIFT           (10U)
#define CRU_GATE_CON06_MCLK_I2S1_8CH_TX_EN_MASK            (0x1U << CRU_GATE_CON06_MCLK_I2S1_8CH_TX_EN_SHIFT)           /* 0x00000400 */
#define CRU_GATE_CON06_I2S1_MCLKOUT_TX_EN_SHIFT            (11U)
#define CRU_GATE_CON06_I2S1_MCLKOUT_TX_EN_MASK             (0x1U << CRU_GATE_CON06_I2S1_MCLKOUT_TX_EN_SHIFT)            /* 0x00000800 */
#define CRU_GATE_CON06_CLK_I2S1_8CH_RX_SRC_EN_SHIFT        (12U)
#define CRU_GATE_CON06_CLK_I2S1_8CH_RX_SRC_EN_MASK         (0x1U << CRU_GATE_CON06_CLK_I2S1_8CH_RX_SRC_EN_SHIFT)        /* 0x00001000 */
#define CRU_GATE_CON06_CLK_I2S1_8CH_RX_FRAC_EN_SHIFT       (13U)
#define CRU_GATE_CON06_CLK_I2S1_8CH_RX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON06_CLK_I2S1_8CH_RX_FRAC_EN_SHIFT)       /* 0x00002000 */
#define CRU_GATE_CON06_MCLK_I2S1_8CH_RX_EN_SHIFT           (14U)
#define CRU_GATE_CON06_MCLK_I2S1_8CH_RX_EN_MASK            (0x1U << CRU_GATE_CON06_MCLK_I2S1_8CH_RX_EN_SHIFT)           /* 0x00004000 */
#define CRU_GATE_CON06_I2S1_MCLKOUT_RX_EN_SHIFT            (15U)
#define CRU_GATE_CON06_I2S1_MCLKOUT_RX_EN_MASK             (0x1U << CRU_GATE_CON06_I2S1_MCLKOUT_RX_EN_SHIFT)            /* 0x00008000 */
/* GATE_CON07 */
#define CRU_GATE_CON07_OFFSET                              (0x31CU)
#define CRU_GATE_CON07_CLK_I2S2_2CH_SRC_EN_SHIFT           (0U)
#define CRU_GATE_CON07_CLK_I2S2_2CH_SRC_EN_MASK            (0x1U << CRU_GATE_CON07_CLK_I2S2_2CH_SRC_EN_SHIFT)           /* 0x00000001 */
#define CRU_GATE_CON07_CLK_I2S2_2CH_FRAC_EN_SHIFT          (1U)
#define CRU_GATE_CON07_CLK_I2S2_2CH_FRAC_EN_MASK           (0x1U << CRU_GATE_CON07_CLK_I2S2_2CH_FRAC_EN_SHIFT)          /* 0x00000002 */
#define CRU_GATE_CON07_MCLK_I2S2_2CH_EN_SHIFT              (2U)
#define CRU_GATE_CON07_MCLK_I2S2_2CH_EN_MASK               (0x1U << CRU_GATE_CON07_MCLK_I2S2_2CH_EN_SHIFT)              /* 0x00000004 */
#define CRU_GATE_CON07_I2S2_MCLKOUT_EN_SHIFT               (3U)
#define CRU_GATE_CON07_I2S2_MCLKOUT_EN_MASK                (0x1U << CRU_GATE_CON07_I2S2_MCLKOUT_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON07_CLK_I2S3_2CH_TX_SRC_EN_SHIFT        (4U)
#define CRU_GATE_CON07_CLK_I2S3_2CH_TX_SRC_EN_MASK         (0x1U << CRU_GATE_CON07_CLK_I2S3_2CH_TX_SRC_EN_SHIFT)        /* 0x00000010 */
#define CRU_GATE_CON07_CLK_I2S3_2CH_TX_FRAC_EN_SHIFT       (5U)
#define CRU_GATE_CON07_CLK_I2S3_2CH_TX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON07_CLK_I2S3_2CH_TX_FRAC_EN_SHIFT)       /* 0x00000020 */
#define CRU_GATE_CON07_MCLK_I2S3_2CH_TX_EN_SHIFT           (6U)
#define CRU_GATE_CON07_MCLK_I2S3_2CH_TX_EN_MASK            (0x1U << CRU_GATE_CON07_MCLK_I2S3_2CH_TX_EN_SHIFT)           /* 0x00000040 */
#define CRU_GATE_CON07_I2S3_MCLKOUT_TX_EN_SHIFT            (7U)
#define CRU_GATE_CON07_I2S3_MCLKOUT_TX_EN_MASK             (0x1U << CRU_GATE_CON07_I2S3_MCLKOUT_TX_EN_SHIFT)            /* 0x00000080 */
#define CRU_GATE_CON07_CLK_I2S3_2CH_RX_SRC_EN_SHIFT        (8U)
#define CRU_GATE_CON07_CLK_I2S3_2CH_RX_SRC_EN_MASK         (0x1U << CRU_GATE_CON07_CLK_I2S3_2CH_RX_SRC_EN_SHIFT)        /* 0x00000100 */
#define CRU_GATE_CON07_CLK_I2S3_2CH_RX_FRAC_EN_SHIFT       (9U)
#define CRU_GATE_CON07_CLK_I2S3_2CH_RX_FRAC_EN_MASK        (0x1U << CRU_GATE_CON07_CLK_I2S3_2CH_RX_FRAC_EN_SHIFT)       /* 0x00000200 */
#define CRU_GATE_CON07_MCLK_I2S3_2CH_RX_EN_SHIFT           (10U)
#define CRU_GATE_CON07_MCLK_I2S3_2CH_RX_EN_MASK            (0x1U << CRU_GATE_CON07_MCLK_I2S3_2CH_RX_EN_SHIFT)           /* 0x00000400 */
#define CRU_GATE_CON07_I2S3_MCLKOUT_RX_EN_SHIFT            (11U)
#define CRU_GATE_CON07_I2S3_MCLKOUT_RX_EN_MASK             (0x1U << CRU_GATE_CON07_I2S3_MCLKOUT_RX_EN_SHIFT)            /* 0x00000800 */
#define CRU_GATE_CON07_HCLK_VAD_EN_SHIFT                   (12U)
#define CRU_GATE_CON07_HCLK_VAD_EN_MASK                    (0x1U << CRU_GATE_CON07_HCLK_VAD_EN_SHIFT)                   /* 0x00001000 */
#define CRU_GATE_CON07_HCLK_SPDIF_8CH_EN_SHIFT             (13U)
#define CRU_GATE_CON07_HCLK_SPDIF_8CH_EN_MASK              (0x1U << CRU_GATE_CON07_HCLK_SPDIF_8CH_EN_SHIFT)             /* 0x00002000 */
#define CRU_GATE_CON07_MCLK_SPDIF_8CH_SRC_EN_SHIFT         (14U)
#define CRU_GATE_CON07_MCLK_SPDIF_8CH_SRC_EN_MASK          (0x1U << CRU_GATE_CON07_MCLK_SPDIF_8CH_SRC_EN_SHIFT)         /* 0x00004000 */
#define CRU_GATE_CON07_MCLK_SPDIF_8CH_FRAC_EN_SHIFT        (15U)
#define CRU_GATE_CON07_MCLK_SPDIF_8CH_FRAC_EN_MASK         (0x1U << CRU_GATE_CON07_MCLK_SPDIF_8CH_FRAC_EN_SHIFT)        /* 0x00008000 */
/* GATE_CON08 */
#define CRU_GATE_CON08_OFFSET                              (0x320U)
#define CRU_GATE_CON08_HCLK_AUDPWM_EN_SHIFT                (0U)
#define CRU_GATE_CON08_HCLK_AUDPWM_EN_MASK                 (0x1U << CRU_GATE_CON08_HCLK_AUDPWM_EN_SHIFT)                /* 0x00000001 */
#define CRU_GATE_CON08_SCLK_AUDPWM_SRC_EN_SHIFT            (1U)
#define CRU_GATE_CON08_SCLK_AUDPWM_SRC_EN_MASK             (0x1U << CRU_GATE_CON08_SCLK_AUDPWM_SRC_EN_SHIFT)            /* 0x00000002 */
#define CRU_GATE_CON08_SCLK_AUDPWM_FRAC_EN_SHIFT           (2U)
#define CRU_GATE_CON08_SCLK_AUDPWM_FRAC_EN_MASK            (0x1U << CRU_GATE_CON08_SCLK_AUDPWM_FRAC_EN_SHIFT)           /* 0x00000004 */
#define CRU_GATE_CON08_HCLK_ACDCDIG_EN_SHIFT               (3U)
#define CRU_GATE_CON08_HCLK_ACDCDIG_EN_MASK                (0x1U << CRU_GATE_CON08_HCLK_ACDCDIG_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON08_CLK_ACDCDIG_I2C_EN_SHIFT            (4U)
#define CRU_GATE_CON08_CLK_ACDCDIG_I2C_EN_MASK             (0x1U << CRU_GATE_CON08_CLK_ACDCDIG_I2C_EN_SHIFT)            /* 0x00000010 */
#define CRU_GATE_CON08_CLK_ACDCDIG_DAC_EN_SHIFT            (5U)
#define CRU_GATE_CON08_CLK_ACDCDIG_DAC_EN_MASK             (0x1U << CRU_GATE_CON08_CLK_ACDCDIG_DAC_EN_SHIFT)            /* 0x00000020 */
#define CRU_GATE_CON08_CLK_ACDCDIG_ADC_EN_SHIFT            (6U)
#define CRU_GATE_CON08_CLK_ACDCDIG_ADC_EN_MASK             (0x1U << CRU_GATE_CON08_CLK_ACDCDIG_ADC_EN_SHIFT)            /* 0x00000040 */
#define CRU_GATE_CON08_ACLK_SECURE_FLASH_EN_SHIFT          (7U)
#define CRU_GATE_CON08_ACLK_SECURE_FLASH_EN_MASK           (0x1U << CRU_GATE_CON08_ACLK_SECURE_FLASH_EN_SHIFT)          /* 0x00000080 */
#define CRU_GATE_CON08_HCLK_SECURE_FLASH_EN_SHIFT          (8U)
#define CRU_GATE_CON08_HCLK_SECURE_FLASH_EN_MASK           (0x1U << CRU_GATE_CON08_HCLK_SECURE_FLASH_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON08_ACLK_SECURE_FLASH_NIU_EN_SHIFT      (9U)
#define CRU_GATE_CON08_ACLK_SECURE_FLASH_NIU_EN_MASK       (0x1U << CRU_GATE_CON08_ACLK_SECURE_FLASH_NIU_EN_SHIFT)      /* 0x00000200 */
#define CRU_GATE_CON08_HCLK_SECURE_FLASH_NIU_EN_SHIFT      (10U)
#define CRU_GATE_CON08_HCLK_SECURE_FLASH_NIU_EN_MASK       (0x1U << CRU_GATE_CON08_HCLK_SECURE_FLASH_NIU_EN_SHIFT)      /* 0x00000400 */
#define CRU_GATE_CON08_ACLK_CRYPTO_NS_EN_SHIFT             (11U)
#define CRU_GATE_CON08_ACLK_CRYPTO_NS_EN_MASK              (0x1U << CRU_GATE_CON08_ACLK_CRYPTO_NS_EN_SHIFT)             /* 0x00000800 */
#define CRU_GATE_CON08_HCLK_CRYPTO_NS_EN_SHIFT             (12U)
#define CRU_GATE_CON08_HCLK_CRYPTO_NS_EN_MASK              (0x1U << CRU_GATE_CON08_HCLK_CRYPTO_NS_EN_SHIFT)             /* 0x00001000 */
#define CRU_GATE_CON08_CLK_CRYPTO_NS_CORE_EN_SHIFT         (13U)
#define CRU_GATE_CON08_CLK_CRYPTO_NS_CORE_EN_MASK          (0x1U << CRU_GATE_CON08_CLK_CRYPTO_NS_CORE_EN_SHIFT)         /* 0x00002000 */
#define CRU_GATE_CON08_CLK_CRYPTO_NS_PKA_EN_SHIFT          (14U)
#define CRU_GATE_CON08_CLK_CRYPTO_NS_PKA_EN_MASK           (0x1U << CRU_GATE_CON08_CLK_CRYPTO_NS_PKA_EN_SHIFT)          /* 0x00004000 */
#define CRU_GATE_CON08_CLK_CRYPTO_NS_RNG_EN_SHIFT          (15U)
#define CRU_GATE_CON08_CLK_CRYPTO_NS_RNG_EN_MASK           (0x1U << CRU_GATE_CON08_CLK_CRYPTO_NS_RNG_EN_SHIFT)          /* 0x00008000 */
/* GATE_CON09 */
#define CRU_GATE_CON09_OFFSET                              (0x324U)
#define CRU_GATE_CON09_HCLK_NANDC_EN_SHIFT                 (0U)
#define CRU_GATE_CON09_HCLK_NANDC_EN_MASK                  (0x1U << CRU_GATE_CON09_HCLK_NANDC_EN_SHIFT)                 /* 0x00000001 */
#define CRU_GATE_CON09_NCLK_NANDC_EN_SHIFT                 (1U)
#define CRU_GATE_CON09_NCLK_NANDC_EN_MASK                  (0x1U << CRU_GATE_CON09_NCLK_NANDC_EN_SHIFT)                 /* 0x00000002 */
#define CRU_GATE_CON09_HCLK_SFC_EN_SHIFT                   (2U)
#define CRU_GATE_CON09_HCLK_SFC_EN_MASK                    (0x1U << CRU_GATE_CON09_HCLK_SFC_EN_SHIFT)                   /* 0x00000004 */
#define CRU_GATE_CON09_HCLK_SFC_XIP_EN_SHIFT               (3U)
#define CRU_GATE_CON09_HCLK_SFC_XIP_EN_MASK                (0x1U << CRU_GATE_CON09_HCLK_SFC_XIP_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON09_SCLK_SFC_EN_SHIFT                   (4U)
#define CRU_GATE_CON09_SCLK_SFC_EN_MASK                    (0x1U << CRU_GATE_CON09_SCLK_SFC_EN_SHIFT)                   /* 0x00000010 */
#define CRU_GATE_CON09_ACLK_EMMC_EN_SHIFT                  (5U)
#define CRU_GATE_CON09_ACLK_EMMC_EN_MASK                   (0x1U << CRU_GATE_CON09_ACLK_EMMC_EN_SHIFT)                  /* 0x00000020 */
#define CRU_GATE_CON09_HCLK_EMMC_EN_SHIFT                  (6U)
#define CRU_GATE_CON09_HCLK_EMMC_EN_MASK                   (0x1U << CRU_GATE_CON09_HCLK_EMMC_EN_SHIFT)                  /* 0x00000040 */
#define CRU_GATE_CON09_BCLK_EMMC_EN_SHIFT                  (7U)
#define CRU_GATE_CON09_BCLK_EMMC_EN_MASK                   (0x1U << CRU_GATE_CON09_BCLK_EMMC_EN_SHIFT)                  /* 0x00000080 */
#define CRU_GATE_CON09_CCLK_EMMC_EN_SHIFT                  (8U)
#define CRU_GATE_CON09_CCLK_EMMC_EN_MASK                   (0x1U << CRU_GATE_CON09_CCLK_EMMC_EN_SHIFT)                  /* 0x00000100 */
#define CRU_GATE_CON09_TCLK_EMMC_EN_SHIFT                  (9U)
#define CRU_GATE_CON09_TCLK_EMMC_EN_MASK                   (0x1U << CRU_GATE_CON09_TCLK_EMMC_EN_SHIFT)                  /* 0x00000200 */
#define CRU_GATE_CON09_HCLK_TRNG_NS_EN_SHIFT               (10U)
#define CRU_GATE_CON09_HCLK_TRNG_NS_EN_MASK                (0x1U << CRU_GATE_CON09_HCLK_TRNG_NS_EN_SHIFT)               /* 0x00000400 */
#define CRU_GATE_CON09_CLK_TRNG_NS_EN_SHIFT                (11U)
#define CRU_GATE_CON09_CLK_TRNG_NS_EN_MASK                 (0x1U << CRU_GATE_CON09_CLK_TRNG_NS_EN_SHIFT)                /* 0x00000800 */
/* GATE_CON10 */
#define CRU_GATE_CON10_OFFSET                              (0x328U)
#define CRU_GATE_CON10_ACLK_PIPE_EN_SHIFT                  (0U)
#define CRU_GATE_CON10_ACLK_PIPE_EN_MASK                   (0x1U << CRU_GATE_CON10_ACLK_PIPE_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON10_PCLK_PIPE_EN_SHIFT                  (1U)
#define CRU_GATE_CON10_PCLK_PIPE_EN_MASK                   (0x1U << CRU_GATE_CON10_PCLK_PIPE_EN_SHIFT)                  /* 0x00000002 */
#define CRU_GATE_CON10_ACLK_PIPE_NIU_EN_SHIFT              (2U)
#define CRU_GATE_CON10_ACLK_PIPE_NIU_EN_MASK               (0x1U << CRU_GATE_CON10_ACLK_PIPE_NIU_EN_SHIFT)              /* 0x00000004 */
#define CRU_GATE_CON10_PCLK_PIPE_NIU_EN_SHIFT              (3U)
#define CRU_GATE_CON10_PCLK_PIPE_NIU_EN_MASK               (0x1U << CRU_GATE_CON10_PCLK_PIPE_NIU_EN_SHIFT)              /* 0x00000008 */
#define CRU_GATE_CON10_CLK_XPCS_EEE_EN_SHIFT               (4U)
#define CRU_GATE_CON10_CLK_XPCS_EEE_EN_MASK                (0x1U << CRU_GATE_CON10_CLK_XPCS_EEE_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON10_CLK_XPCS_RX_DIV10_EN_SHIFT          (5U)
#define CRU_GATE_CON10_CLK_XPCS_RX_DIV10_EN_MASK           (0x1U << CRU_GATE_CON10_CLK_XPCS_RX_DIV10_EN_SHIFT)          /* 0x00000020 */
#define CRU_GATE_CON10_CLK_XPCS_TX_DIV10_EN_SHIFT          (6U)
#define CRU_GATE_CON10_CLK_XPCS_TX_DIV10_EN_MASK           (0x1U << CRU_GATE_CON10_CLK_XPCS_TX_DIV10_EN_SHIFT)          /* 0x00000040 */
#define CRU_GATE_CON10_PCLK_PIPE_GRF_EN_SHIFT              (7U)
#define CRU_GATE_CON10_PCLK_PIPE_GRF_EN_MASK               (0x1U << CRU_GATE_CON10_PCLK_PIPE_GRF_EN_SHIFT)              /* 0x00000080 */
#define CRU_GATE_CON10_ACLK_USB3OTG0_EN_SHIFT              (8U)
#define CRU_GATE_CON10_ACLK_USB3OTG0_EN_MASK               (0x1U << CRU_GATE_CON10_ACLK_USB3OTG0_EN_SHIFT)              /* 0x00000100 */
#define CRU_GATE_CON10_CLK_USB3OTG0_REF_EN_SHIFT           (9U)
#define CRU_GATE_CON10_CLK_USB3OTG0_REF_EN_MASK            (0x1U << CRU_GATE_CON10_CLK_USB3OTG0_REF_EN_SHIFT)           /* 0x00000200 */
#define CRU_GATE_CON10_CLK_USB3OTG0_SUSPEND_EN_SHIFT       (10U)
#define CRU_GATE_CON10_CLK_USB3OTG0_SUSPEND_EN_MASK        (0x1U << CRU_GATE_CON10_CLK_USB3OTG0_SUSPEND_EN_SHIFT)       /* 0x00000400 */
#define CRU_GATE_CON10_CLK_USB3OTG0_PIPE_EN_SHIFT          (11U)
#define CRU_GATE_CON10_CLK_USB3OTG0_PIPE_EN_MASK           (0x1U << CRU_GATE_CON10_CLK_USB3OTG0_PIPE_EN_SHIFT)          /* 0x00000800 */
#define CRU_GATE_CON10_ACLK_USB3OTG1_EN_SHIFT              (12U)
#define CRU_GATE_CON10_ACLK_USB3OTG1_EN_MASK               (0x1U << CRU_GATE_CON10_ACLK_USB3OTG1_EN_SHIFT)              /* 0x00001000 */
#define CRU_GATE_CON10_CLK_USB3OTG1_REF_EN_SHIFT           (13U)
#define CRU_GATE_CON10_CLK_USB3OTG1_REF_EN_MASK            (0x1U << CRU_GATE_CON10_CLK_USB3OTG1_REF_EN_SHIFT)           /* 0x00002000 */
#define CRU_GATE_CON10_CLK_USB3OTG1_SUSPEND_EN_SHIFT       (14U)
#define CRU_GATE_CON10_CLK_USB3OTG1_SUSPEND_EN_MASK        (0x1U << CRU_GATE_CON10_CLK_USB3OTG1_SUSPEND_EN_SHIFT)       /* 0x00004000 */
#define CRU_GATE_CON10_CLK_USB3OTG1_PIPE_EN_SHIFT          (15U)
#define CRU_GATE_CON10_CLK_USB3OTG1_PIPE_EN_MASK           (0x1U << CRU_GATE_CON10_CLK_USB3OTG1_PIPE_EN_SHIFT)          /* 0x00008000 */
/* GATE_CON11 */
#define CRU_GATE_CON11_OFFSET                              (0x32CU)
#define CRU_GATE_CON11_ACLK_SATA0_EN_SHIFT                 (0U)
#define CRU_GATE_CON11_ACLK_SATA0_EN_MASK                  (0x1U << CRU_GATE_CON11_ACLK_SATA0_EN_SHIFT)                 /* 0x00000001 */
#define CRU_GATE_CON11_CLK_SATA0_PMALIVE_EN_SHIFT          (1U)
#define CRU_GATE_CON11_CLK_SATA0_PMALIVE_EN_MASK           (0x1U << CRU_GATE_CON11_CLK_SATA0_PMALIVE_EN_SHIFT)          /* 0x00000002 */
#define CRU_GATE_CON11_CLK_SATA0_RXOOB_EN_SHIFT            (2U)
#define CRU_GATE_CON11_CLK_SATA0_RXOOB_EN_MASK             (0x1U << CRU_GATE_CON11_CLK_SATA0_RXOOB_EN_SHIFT)            /* 0x00000004 */
#define CRU_GATE_CON11_CLK_SATA0_PIPE_EN_SHIFT             (3U)
#define CRU_GATE_CON11_CLK_SATA0_PIPE_EN_MASK              (0x1U << CRU_GATE_CON11_CLK_SATA0_PIPE_EN_SHIFT)             /* 0x00000008 */
#define CRU_GATE_CON11_ACLK_SATA1_EN_SHIFT                 (4U)
#define CRU_GATE_CON11_ACLK_SATA1_EN_MASK                  (0x1U << CRU_GATE_CON11_ACLK_SATA1_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON11_CLK_SATA1_PMALIVE_EN_SHIFT          (5U)
#define CRU_GATE_CON11_CLK_SATA1_PMALIVE_EN_MASK           (0x1U << CRU_GATE_CON11_CLK_SATA1_PMALIVE_EN_SHIFT)          /* 0x00000020 */
#define CRU_GATE_CON11_CLK_SATA1_RXOOB_EN_SHIFT            (6U)
#define CRU_GATE_CON11_CLK_SATA1_RXOOB_EN_MASK             (0x1U << CRU_GATE_CON11_CLK_SATA1_RXOOB_EN_SHIFT)            /* 0x00000040 */
#define CRU_GATE_CON11_CLK_SATA1_PIPE_EN_SHIFT             (7U)
#define CRU_GATE_CON11_CLK_SATA1_PIPE_EN_MASK              (0x1U << CRU_GATE_CON11_CLK_SATA1_PIPE_EN_SHIFT)             /* 0x00000080 */
#define CRU_GATE_CON11_ACLK_SATA2_EN_SHIFT                 (8U)
#define CRU_GATE_CON11_ACLK_SATA2_EN_MASK                  (0x1U << CRU_GATE_CON11_ACLK_SATA2_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON11_CLK_SATA2_PMALIVE_EN_SHIFT          (9U)
#define CRU_GATE_CON11_CLK_SATA2_PMALIVE_EN_MASK           (0x1U << CRU_GATE_CON11_CLK_SATA2_PMALIVE_EN_SHIFT)          /* 0x00000200 */
#define CRU_GATE_CON11_CLK_SATA2_RXOOB_EN_SHIFT            (10U)
#define CRU_GATE_CON11_CLK_SATA2_RXOOB_EN_MASK             (0x1U << CRU_GATE_CON11_CLK_SATA2_RXOOB_EN_SHIFT)            /* 0x00000400 */
#define CRU_GATE_CON11_CLK_SATA2_PIPE_EN_SHIFT             (11U)
#define CRU_GATE_CON11_CLK_SATA2_PIPE_EN_MASK              (0x1U << CRU_GATE_CON11_CLK_SATA2_PIPE_EN_SHIFT)             /* 0x00000800 */
/* GATE_CON12 */
#define CRU_GATE_CON12_OFFSET                              (0x330U)
#define CRU_GATE_CON12_ACLK_PCIE20_MST_EN_SHIFT            (0U)
#define CRU_GATE_CON12_ACLK_PCIE20_MST_EN_MASK             (0x1U << CRU_GATE_CON12_ACLK_PCIE20_MST_EN_SHIFT)            /* 0x00000001 */
#define CRU_GATE_CON12_ACLK_PCIE20_SLV_EN_SHIFT            (1U)
#define CRU_GATE_CON12_ACLK_PCIE20_SLV_EN_MASK             (0x1U << CRU_GATE_CON12_ACLK_PCIE20_SLV_EN_SHIFT)            /* 0x00000002 */
#define CRU_GATE_CON12_ACLK_PCIE20_DBI_EN_SHIFT            (2U)
#define CRU_GATE_CON12_ACLK_PCIE20_DBI_EN_MASK             (0x1U << CRU_GATE_CON12_ACLK_PCIE20_DBI_EN_SHIFT)            /* 0x00000004 */
#define CRU_GATE_CON12_PCLK_PCIE20_EN_SHIFT                (3U)
#define CRU_GATE_CON12_PCLK_PCIE20_EN_MASK                 (0x1U << CRU_GATE_CON12_PCLK_PCIE20_EN_SHIFT)                /* 0x00000008 */
#define CRU_GATE_CON12_CLK_PCIE20_AUX_EN_SHIFT             (4U)
#define CRU_GATE_CON12_CLK_PCIE20_AUX_EN_MASK              (0x1U << CRU_GATE_CON12_CLK_PCIE20_AUX_EN_SHIFT)             /* 0x00000010 */
#define CRU_GATE_CON12_CLK_PCIE20_PIPE_EN_SHIFT            (5U)
#define CRU_GATE_CON12_CLK_PCIE20_PIPE_EN_MASK             (0x1U << CRU_GATE_CON12_CLK_PCIE20_PIPE_EN_SHIFT)            /* 0x00000020 */
#define CRU_GATE_CON12_ACLK_PCIE30X1_MST_EN_SHIFT          (8U)
#define CRU_GATE_CON12_ACLK_PCIE30X1_MST_EN_MASK           (0x1U << CRU_GATE_CON12_ACLK_PCIE30X1_MST_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON12_ACLK_PCIE30X1_SLV_EN_SHIFT          (9U)
#define CRU_GATE_CON12_ACLK_PCIE30X1_SLV_EN_MASK           (0x1U << CRU_GATE_CON12_ACLK_PCIE30X1_SLV_EN_SHIFT)          /* 0x00000200 */
#define CRU_GATE_CON12_ACLK_PCIE30X1_DBI_EN_SHIFT          (10U)
#define CRU_GATE_CON12_ACLK_PCIE30X1_DBI_EN_MASK           (0x1U << CRU_GATE_CON12_ACLK_PCIE30X1_DBI_EN_SHIFT)          /* 0x00000400 */
#define CRU_GATE_CON12_PCLK_PCIE30X1_EN_SHIFT              (11U)
#define CRU_GATE_CON12_PCLK_PCIE30X1_EN_MASK               (0x1U << CRU_GATE_CON12_PCLK_PCIE30X1_EN_SHIFT)              /* 0x00000800 */
#define CRU_GATE_CON12_CLK_PCIE30X1_AUX_EN_SHIFT           (12U)
#define CRU_GATE_CON12_CLK_PCIE30X1_AUX_EN_MASK            (0x1U << CRU_GATE_CON12_CLK_PCIE30X1_AUX_EN_SHIFT)           /* 0x00001000 */
#define CRU_GATE_CON12_CLK_PCIE30X1_PIPE_EN_SHIFT          (13U)
#define CRU_GATE_CON12_CLK_PCIE30X1_PIPE_EN_MASK           (0x1U << CRU_GATE_CON12_CLK_PCIE30X1_PIPE_EN_SHIFT)          /* 0x00002000 */
/* GATE_CON13 */
#define CRU_GATE_CON13_OFFSET                              (0x334U)
#define CRU_GATE_CON13_ACLK_PCIE30X2_MST_EN_SHIFT          (0U)
#define CRU_GATE_CON13_ACLK_PCIE30X2_MST_EN_MASK           (0x1U << CRU_GATE_CON13_ACLK_PCIE30X2_MST_EN_SHIFT)          /* 0x00000001 */
#define CRU_GATE_CON13_ACLK_PCIE30X2_SLV_EN_SHIFT          (1U)
#define CRU_GATE_CON13_ACLK_PCIE30X2_SLV_EN_MASK           (0x1U << CRU_GATE_CON13_ACLK_PCIE30X2_SLV_EN_SHIFT)          /* 0x00000002 */
#define CRU_GATE_CON13_ACLK_PCIE30X2_DBI_EN_SHIFT          (2U)
#define CRU_GATE_CON13_ACLK_PCIE30X2_DBI_EN_MASK           (0x1U << CRU_GATE_CON13_ACLK_PCIE30X2_DBI_EN_SHIFT)          /* 0x00000004 */
#define CRU_GATE_CON13_PCLK_PCIE30X2_EN_SHIFT              (3U)
#define CRU_GATE_CON13_PCLK_PCIE30X2_EN_MASK               (0x1U << CRU_GATE_CON13_PCLK_PCIE30X2_EN_SHIFT)              /* 0x00000008 */
#define CRU_GATE_CON13_CLK_PCIE30X2_AUX_EN_SHIFT           (4U)
#define CRU_GATE_CON13_CLK_PCIE30X2_AUX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_PCIE30X2_AUX_EN_SHIFT)           /* 0x00000010 */
#define CRU_GATE_CON13_CLK_PCIE30X2_PIPE_EN_SHIFT          (5U)
#define CRU_GATE_CON13_CLK_PCIE30X2_PIPE_EN_MASK           (0x1U << CRU_GATE_CON13_CLK_PCIE30X2_PIPE_EN_SHIFT)          /* 0x00000020 */
#define CRU_GATE_CON13_PCLK_XPCS_EN_SHIFT                  (6U)
#define CRU_GATE_CON13_PCLK_XPCS_EN_MASK                   (0x1U << CRU_GATE_CON13_PCLK_XPCS_EN_SHIFT)                  /* 0x00000040 */
#define CRU_GATE_CON13_CLK_XPCS_QSGMII_TX_EN_SHIFT         (7U)
#define CRU_GATE_CON13_CLK_XPCS_QSGMII_TX_EN_MASK          (0x1U << CRU_GATE_CON13_CLK_XPCS_QSGMII_TX_EN_SHIFT)         /* 0x00000080 */
#define CRU_GATE_CON13_CLK_XPCS_QSGMII_RX_EN_SHIFT         (8U)
#define CRU_GATE_CON13_CLK_XPCS_QSGMII_RX_EN_MASK          (0x1U << CRU_GATE_CON13_CLK_XPCS_QSGMII_RX_EN_SHIFT)         /* 0x00000100 */
#define CRU_GATE_CON13_CLK_XPCS_XGXS_TX_EN_SHIFT           (9U)
#define CRU_GATE_CON13_CLK_XPCS_XGXS_TX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_XGXS_TX_EN_SHIFT)           /* 0x00000200 */
#define CRU_GATE_CON13_CLK_XPCS_XGXS_RX_EN_SHIFT           (11U)
#define CRU_GATE_CON13_CLK_XPCS_XGXS_RX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_XGXS_RX_EN_SHIFT)           /* 0x00000800 */
#define CRU_GATE_CON13_CLK_XPCS_MII0_TX_EN_SHIFT           (12U)
#define CRU_GATE_CON13_CLK_XPCS_MII0_TX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_MII0_TX_EN_SHIFT)           /* 0x00001000 */
#define CRU_GATE_CON13_CLK_XPCS_MII0_RX_EN_SHIFT           (13U)
#define CRU_GATE_CON13_CLK_XPCS_MII0_RX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_MII0_RX_EN_SHIFT)           /* 0x00002000 */
#define CRU_GATE_CON13_CLK_XPCS_MII1_TX_EN_SHIFT           (14U)
#define CRU_GATE_CON13_CLK_XPCS_MII1_TX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_MII1_TX_EN_SHIFT)           /* 0x00004000 */
#define CRU_GATE_CON13_CLK_XPCS_MII1_RX_EN_SHIFT           (15U)
#define CRU_GATE_CON13_CLK_XPCS_MII1_RX_EN_MASK            (0x1U << CRU_GATE_CON13_CLK_XPCS_MII1_RX_EN_SHIFT)           /* 0x00008000 */
/* GATE_CON14 */
#define CRU_GATE_CON14_OFFSET                              (0x338U)
#define CRU_GATE_CON14_ACLK_PERIMID_EN_SHIFT               (0U)
#define CRU_GATE_CON14_ACLK_PERIMID_EN_MASK                (0x1U << CRU_GATE_CON14_ACLK_PERIMID_EN_SHIFT)               /* 0x00000001 */
#define CRU_GATE_CON14_HCLK_PERIMID_EN_SHIFT               (1U)
#define CRU_GATE_CON14_HCLK_PERIMID_EN_MASK                (0x1U << CRU_GATE_CON14_HCLK_PERIMID_EN_SHIFT)               /* 0x00000002 */
#define CRU_GATE_CON14_ACLK_PERIMID_NIU_EN_SHIFT           (2U)
#define CRU_GATE_CON14_ACLK_PERIMID_NIU_EN_MASK            (0x1U << CRU_GATE_CON14_ACLK_PERIMID_NIU_EN_SHIFT)           /* 0x00000004 */
#define CRU_GATE_CON14_HCLK_PERIMID_NIU_EN_SHIFT           (3U)
#define CRU_GATE_CON14_HCLK_PERIMID_NIU_EN_MASK            (0x1U << CRU_GATE_CON14_HCLK_PERIMID_NIU_EN_SHIFT)           /* 0x00000008 */
#define CRU_GATE_CON14_ACLK_PHP_EN_SHIFT                   (8U)
#define CRU_GATE_CON14_ACLK_PHP_EN_MASK                    (0x1U << CRU_GATE_CON14_ACLK_PHP_EN_SHIFT)                   /* 0x00000100 */
#define CRU_GATE_CON14_HCLK_PHP_EN_SHIFT                   (9U)
#define CRU_GATE_CON14_HCLK_PHP_EN_MASK                    (0x1U << CRU_GATE_CON14_HCLK_PHP_EN_SHIFT)                   /* 0x00000200 */
#define CRU_GATE_CON14_PCLK_PHP_EN_SHIFT                   (10U)
#define CRU_GATE_CON14_PCLK_PHP_EN_MASK                    (0x1U << CRU_GATE_CON14_PCLK_PHP_EN_SHIFT)                   /* 0x00000400 */
#define CRU_GATE_CON14_ACLK_PHP_NIU_EN_SHIFT               (11U)
#define CRU_GATE_CON14_ACLK_PHP_NIU_EN_MASK                (0x1U << CRU_GATE_CON14_ACLK_PHP_NIU_EN_SHIFT)               /* 0x00000800 */
#define CRU_GATE_CON14_HCLK_PHP_NIU_EN_SHIFT               (12U)
#define CRU_GATE_CON14_HCLK_PHP_NIU_EN_MASK                (0x1U << CRU_GATE_CON14_HCLK_PHP_NIU_EN_SHIFT)               /* 0x00001000 */
#define CRU_GATE_CON14_PCLK_PHP_NIU_EN_SHIFT               (13U)
#define CRU_GATE_CON14_PCLK_PHP_NIU_EN_MASK                (0x1U << CRU_GATE_CON14_PCLK_PHP_NIU_EN_SHIFT)               /* 0x00002000 */
/* GATE_CON15 */
#define CRU_GATE_CON15_OFFSET                              (0x33CU)
#define CRU_GATE_CON15_HCLK_SDMMC0_EN_SHIFT                (0U)
#define CRU_GATE_CON15_HCLK_SDMMC0_EN_MASK                 (0x1U << CRU_GATE_CON15_HCLK_SDMMC0_EN_SHIFT)                /* 0x00000001 */
#define CRU_GATE_CON15_CLK_SDMMC0_EN_SHIFT                 (1U)
#define CRU_GATE_CON15_CLK_SDMMC0_EN_MASK                  (0x1U << CRU_GATE_CON15_CLK_SDMMC0_EN_SHIFT)                 /* 0x00000002 */
#define CRU_GATE_CON15_HCLK_SDMMC1_EN_SHIFT                (2U)
#define CRU_GATE_CON15_HCLK_SDMMC1_EN_MASK                 (0x1U << CRU_GATE_CON15_HCLK_SDMMC1_EN_SHIFT)                /* 0x00000004 */
#define CRU_GATE_CON15_CLK_SDMMC1_EN_SHIFT                 (3U)
#define CRU_GATE_CON15_CLK_SDMMC1_EN_MASK                  (0x1U << CRU_GATE_CON15_CLK_SDMMC1_EN_SHIFT)                 /* 0x00000008 */
#define CRU_GATE_CON15_CLK_GMAC0_PTP_REF_EN_SHIFT          (4U)
#define CRU_GATE_CON15_CLK_GMAC0_PTP_REF_EN_MASK           (0x1U << CRU_GATE_CON15_CLK_GMAC0_PTP_REF_EN_SHIFT)          /* 0x00000010 */
#define CRU_GATE_CON15_ACLK_GMAC0_EN_SHIFT                 (5U)
#define CRU_GATE_CON15_ACLK_GMAC0_EN_MASK                  (0x1U << CRU_GATE_CON15_ACLK_GMAC0_EN_SHIFT)                 /* 0x00000020 */
#define CRU_GATE_CON15_PCLK_GMAC0_EN_SHIFT                 (6U)
#define CRU_GATE_CON15_PCLK_GMAC0_EN_MASK                  (0x1U << CRU_GATE_CON15_PCLK_GMAC0_EN_SHIFT)                 /* 0x00000040 */
#define CRU_GATE_CON15_CLK_MAC0_2TOP_EN_SHIFT              (7U)
#define CRU_GATE_CON15_CLK_MAC0_2TOP_EN_MASK               (0x1U << CRU_GATE_CON15_CLK_MAC0_2TOP_EN_SHIFT)              /* 0x00000080 */
#define CRU_GATE_CON15_CLK_MAC0_OUT_EN_SHIFT               (8U)
#define CRU_GATE_CON15_CLK_MAC0_OUT_EN_MASK                (0x1U << CRU_GATE_CON15_CLK_MAC0_OUT_EN_SHIFT)               /* 0x00000100 */
#define CRU_GATE_CON15_CLK_MAC0_REFOUT_EN_SHIFT            (12U)
#define CRU_GATE_CON15_CLK_MAC0_REFOUT_EN_MASK             (0x1U << CRU_GATE_CON15_CLK_MAC0_REFOUT_EN_SHIFT)            /* 0x00001000 */
/* GATE_CON16 */
#define CRU_GATE_CON16_OFFSET                              (0x340U)
#define CRU_GATE_CON16_ACLK_USB_EN_SHIFT                   (0U)
#define CRU_GATE_CON16_ACLK_USB_EN_MASK                    (0x1U << CRU_GATE_CON16_ACLK_USB_EN_SHIFT)                   /* 0x00000001 */
#define CRU_GATE_CON16_HCLK_USB_EN_SHIFT                   (1U)
#define CRU_GATE_CON16_HCLK_USB_EN_MASK                    (0x1U << CRU_GATE_CON16_HCLK_USB_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON16_PCLK_USB_EN_SHIFT                   (2U)
#define CRU_GATE_CON16_PCLK_USB_EN_MASK                    (0x1U << CRU_GATE_CON16_PCLK_USB_EN_SHIFT)                   /* 0x00000004 */
#define CRU_GATE_CON16_ACLK_USB_NIU_EN_SHIFT               (3U)
#define CRU_GATE_CON16_ACLK_USB_NIU_EN_MASK                (0x1U << CRU_GATE_CON16_ACLK_USB_NIU_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON16_HCLK_USB_NIU_EN_SHIFT               (4U)
#define CRU_GATE_CON16_HCLK_USB_NIU_EN_MASK                (0x1U << CRU_GATE_CON16_HCLK_USB_NIU_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON16_PCLK_USB_NIU_EN_SHIFT               (5U)
#define CRU_GATE_CON16_PCLK_USB_NIU_EN_MASK                (0x1U << CRU_GATE_CON16_PCLK_USB_NIU_EN_SHIFT)               /* 0x00000020 */
#define CRU_GATE_CON16_PCLK_USB_GRF_EN_SHIFT               (6U)
#define CRU_GATE_CON16_PCLK_USB_GRF_EN_MASK                (0x1U << CRU_GATE_CON16_PCLK_USB_GRF_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON16_HCLK_USB2HOST0_EN_SHIFT             (12U)
#define CRU_GATE_CON16_HCLK_USB2HOST0_EN_MASK              (0x1U << CRU_GATE_CON16_HCLK_USB2HOST0_EN_SHIFT)             /* 0x00001000 */
#define CRU_GATE_CON16_HCLK_USB2HOST0_ARB_EN_SHIFT         (13U)
#define CRU_GATE_CON16_HCLK_USB2HOST0_ARB_EN_MASK          (0x1U << CRU_GATE_CON16_HCLK_USB2HOST0_ARB_EN_SHIFT)         /* 0x00002000 */
#define CRU_GATE_CON16_HCLK_USB2HOST1_EN_SHIFT             (14U)
#define CRU_GATE_CON16_HCLK_USB2HOST1_EN_MASK              (0x1U << CRU_GATE_CON16_HCLK_USB2HOST1_EN_SHIFT)             /* 0x00004000 */
#define CRU_GATE_CON16_HCLK_USB2HOST1_ARB_EN_SHIFT         (15U)
#define CRU_GATE_CON16_HCLK_USB2HOST1_ARB_EN_MASK          (0x1U << CRU_GATE_CON16_HCLK_USB2HOST1_ARB_EN_SHIFT)         /* 0x00008000 */
/* GATE_CON17 */
#define CRU_GATE_CON17_OFFSET                              (0x344U)
#define CRU_GATE_CON17_HCLK_SDMMC2_EN_SHIFT                (0U)
#define CRU_GATE_CON17_HCLK_SDMMC2_EN_MASK                 (0x1U << CRU_GATE_CON17_HCLK_SDMMC2_EN_SHIFT)                /* 0x00000001 */
#define CRU_GATE_CON17_CLK_SDMMC2_EN_SHIFT                 (1U)
#define CRU_GATE_CON17_CLK_SDMMC2_EN_MASK                  (0x1U << CRU_GATE_CON17_CLK_SDMMC2_EN_SHIFT)                 /* 0x00000002 */
#define CRU_GATE_CON17_CLK_GMAC1_PTP_REF_EN_SHIFT          (2U)
#define CRU_GATE_CON17_CLK_GMAC1_PTP_REF_EN_MASK           (0x1U << CRU_GATE_CON17_CLK_GMAC1_PTP_REF_EN_SHIFT)          /* 0x00000004 */
#define CRU_GATE_CON17_ACLK_GMAC1_EN_SHIFT                 (3U)
#define CRU_GATE_CON17_ACLK_GMAC1_EN_MASK                  (0x1U << CRU_GATE_CON17_ACLK_GMAC1_EN_SHIFT)                 /* 0x00000008 */
#define CRU_GATE_CON17_PCLK_GMAC1_EN_SHIFT                 (4U)
#define CRU_GATE_CON17_PCLK_GMAC1_EN_MASK                  (0x1U << CRU_GATE_CON17_PCLK_GMAC1_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON17_CLK_MAC1_2TOP_EN_SHIFT              (5U)
#define CRU_GATE_CON17_CLK_MAC1_2TOP_EN_MASK               (0x1U << CRU_GATE_CON17_CLK_MAC1_2TOP_EN_SHIFT)              /* 0x00000020 */
#define CRU_GATE_CON17_CLK_MAC1_OUT_EN_SHIFT               (6U)
#define CRU_GATE_CON17_CLK_MAC1_OUT_EN_MASK                (0x1U << CRU_GATE_CON17_CLK_MAC1_OUT_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON17_CLK_MAC1_REFOUT_EN_SHIFT            (10U)
#define CRU_GATE_CON17_CLK_MAC1_REFOUT_EN_MASK             (0x1U << CRU_GATE_CON17_CLK_MAC1_REFOUT_EN_SHIFT)            /* 0x00000400 */
/* GATE_CON18 */
#define CRU_GATE_CON18_OFFSET                              (0x348U)
#define CRU_GATE_CON18_ACLK_VI_EN_SHIFT                    (0U)
#define CRU_GATE_CON18_ACLK_VI_EN_MASK                     (0x1U << CRU_GATE_CON18_ACLK_VI_EN_SHIFT)                    /* 0x00000001 */
#define CRU_GATE_CON18_HCLK_VI_EN_SHIFT                    (1U)
#define CRU_GATE_CON18_HCLK_VI_EN_MASK                     (0x1U << CRU_GATE_CON18_HCLK_VI_EN_SHIFT)                    /* 0x00000002 */
#define CRU_GATE_CON18_PCLK_VI_EN_SHIFT                    (2U)
#define CRU_GATE_CON18_PCLK_VI_EN_MASK                     (0x1U << CRU_GATE_CON18_PCLK_VI_EN_SHIFT)                    /* 0x00000004 */
#define CRU_GATE_CON18_ACLK_VI_NIU_EN_SHIFT                (3U)
#define CRU_GATE_CON18_ACLK_VI_NIU_EN_MASK                 (0x1U << CRU_GATE_CON18_ACLK_VI_NIU_EN_SHIFT)                /* 0x00000008 */
#define CRU_GATE_CON18_HCLK_VI_NIU_EN_SHIFT                (4U)
#define CRU_GATE_CON18_HCLK_VI_NIU_EN_MASK                 (0x1U << CRU_GATE_CON18_HCLK_VI_NIU_EN_SHIFT)                /* 0x00000010 */
#define CRU_GATE_CON18_PCLK_VI_NIU_EN_SHIFT                (5U)
#define CRU_GATE_CON18_PCLK_VI_NIU_EN_MASK                 (0x1U << CRU_GATE_CON18_PCLK_VI_NIU_EN_SHIFT)                /* 0x00000020 */
#define CRU_GATE_CON18_ACLK_VICAP1_EN_SHIFT                (9U)
#define CRU_GATE_CON18_ACLK_VICAP1_EN_MASK                 (0x1U << CRU_GATE_CON18_ACLK_VICAP1_EN_SHIFT)                /* 0x00000200 */
#define CRU_GATE_CON18_HCLK_VICAP1_EN_SHIFT                (10U)
#define CRU_GATE_CON18_HCLK_VICAP1_EN_MASK                 (0x1U << CRU_GATE_CON18_HCLK_VICAP1_EN_SHIFT)                /* 0x00000400 */
#define CRU_GATE_CON18_DCLK_VICAP1_EN_SHIFT                (11U)
#define CRU_GATE_CON18_DCLK_VICAP1_EN_MASK                 (0x1U << CRU_GATE_CON18_DCLK_VICAP1_EN_SHIFT)                /* 0x00000800 */
/* GATE_CON19 */
#define CRU_GATE_CON19_OFFSET                              (0x34CU)
#define CRU_GATE_CON19_ACLK_ISP_EN_SHIFT                   (0U)
#define CRU_GATE_CON19_ACLK_ISP_EN_MASK                    (0x1U << CRU_GATE_CON19_ACLK_ISP_EN_SHIFT)                   /* 0x00000001 */
#define CRU_GATE_CON19_HCLK_ISP_EN_SHIFT                   (1U)
#define CRU_GATE_CON19_HCLK_ISP_EN_MASK                    (0x1U << CRU_GATE_CON19_HCLK_ISP_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON19_CLK_ISP_EN_SHIFT                    (2U)
#define CRU_GATE_CON19_CLK_ISP_EN_MASK                     (0x1U << CRU_GATE_CON19_CLK_ISP_EN_SHIFT)                    /* 0x00000004 */
#define CRU_GATE_CON19_PCLK_CSI2HOST1_EN_SHIFT             (4U)
#define CRU_GATE_CON19_PCLK_CSI2HOST1_EN_MASK              (0x1U << CRU_GATE_CON19_PCLK_CSI2HOST1_EN_SHIFT)             /* 0x00000010 */
#define CRU_GATE_CON19_CLK_CIF_OUT_EN_SHIFT                (8U)
#define CRU_GATE_CON19_CLK_CIF_OUT_EN_MASK                 (0x1U << CRU_GATE_CON19_CLK_CIF_OUT_EN_SHIFT)                /* 0x00000100 */
#define CRU_GATE_CON19_CLK_CAM0_OUT_EN_SHIFT               (9U)
#define CRU_GATE_CON19_CLK_CAM0_OUT_EN_MASK                (0x1U << CRU_GATE_CON19_CLK_CAM0_OUT_EN_SHIFT)               /* 0x00000200 */
#define CRU_GATE_CON19_CLK_CAM1_OUT_EN_SHIFT               (10U)
#define CRU_GATE_CON19_CLK_CAM1_OUT_EN_MASK                (0x1U << CRU_GATE_CON19_CLK_CAM1_OUT_EN_SHIFT)               /* 0x00000400 */
/* GATE_CON20 */
#define CRU_GATE_CON20_OFFSET                              (0x350U)
#define CRU_GATE_CON20_HCLK_VO_EN_SHIFT                    (1U)
#define CRU_GATE_CON20_HCLK_VO_EN_MASK                     (0x1U << CRU_GATE_CON20_HCLK_VO_EN_SHIFT)                    /* 0x00000002 */
#define CRU_GATE_CON20_PCLK_VO_EN_SHIFT                    (2U)
#define CRU_GATE_CON20_PCLK_VO_EN_MASK                     (0x1U << CRU_GATE_CON20_PCLK_VO_EN_SHIFT)                    /* 0x00000004 */
#define CRU_GATE_CON20_ACLK_VO_NIU_EN_SHIFT                (3U)
#define CRU_GATE_CON20_ACLK_VO_NIU_EN_MASK                 (0x1U << CRU_GATE_CON20_ACLK_VO_NIU_EN_SHIFT)                /* 0x00000008 */
#define CRU_GATE_CON20_HCLK_VO_NIU_EN_SHIFT                (4U)
#define CRU_GATE_CON20_HCLK_VO_NIU_EN_MASK                 (0x1U << CRU_GATE_CON20_HCLK_VO_NIU_EN_SHIFT)                /* 0x00000010 */
#define CRU_GATE_CON20_PCLK_VO_NIU_EN_SHIFT                (5U)
#define CRU_GATE_CON20_PCLK_VO_NIU_EN_MASK                 (0x1U << CRU_GATE_CON20_PCLK_VO_NIU_EN_SHIFT)                /* 0x00000020 */
#define CRU_GATE_CON20_ACLK_VOP_PRE_EN_SHIFT               (6U)
#define CRU_GATE_CON20_ACLK_VOP_PRE_EN_MASK                (0x1U << CRU_GATE_CON20_ACLK_VOP_PRE_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON20_ACLK_VOP_NIU_EN_SHIFT               (7U)
#define CRU_GATE_CON20_ACLK_VOP_NIU_EN_MASK                (0x1U << CRU_GATE_CON20_ACLK_VOP_NIU_EN_SHIFT)               /* 0x00000080 */
#define CRU_GATE_CON20_ACLK_VOP_EN_SHIFT                   (8U)
#define CRU_GATE_CON20_ACLK_VOP_EN_MASK                    (0x1U << CRU_GATE_CON20_ACLK_VOP_EN_SHIFT)                   /* 0x00000100 */
#define CRU_GATE_CON20_HCLK_VOP_EN_SHIFT                   (9U)
#define CRU_GATE_CON20_HCLK_VOP_EN_MASK                    (0x1U << CRU_GATE_CON20_HCLK_VOP_EN_SHIFT)                   /* 0x00000200 */
#define CRU_GATE_CON20_DCLK0_VOP_EN_SHIFT                  (10U)
#define CRU_GATE_CON20_DCLK0_VOP_EN_MASK                   (0x1U << CRU_GATE_CON20_DCLK0_VOP_EN_SHIFT)                  /* 0x00000400 */
#define CRU_GATE_CON20_DCLK1_VOP_EN_SHIFT                  (11U)
#define CRU_GATE_CON20_DCLK1_VOP_EN_MASK                   (0x1U << CRU_GATE_CON20_DCLK1_VOP_EN_SHIFT)                  /* 0x00000800 */
#define CRU_GATE_CON20_DCLK2_VOP_EN_SHIFT                  (12U)
#define CRU_GATE_CON20_DCLK2_VOP_EN_MASK                   (0x1U << CRU_GATE_CON20_DCLK2_VOP_EN_SHIFT)                  /* 0x00001000 */
#define CRU_GATE_CON20_CLK_VOP_PWM_EN_SHIFT                (13U)
#define CRU_GATE_CON20_CLK_VOP_PWM_EN_MASK                 (0x1U << CRU_GATE_CON20_CLK_VOP_PWM_EN_SHIFT)                /* 0x00002000 */
/* GATE_CON21 */
#define CRU_GATE_CON21_OFFSET                              (0x354U)
#define CRU_GATE_CON21_ACLK_HDCP_EN_SHIFT                  (0U)
#define CRU_GATE_CON21_ACLK_HDCP_EN_MASK                   (0x1U << CRU_GATE_CON21_ACLK_HDCP_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON21_HCLK_HDCP_EN_SHIFT                  (1U)
#define CRU_GATE_CON21_HCLK_HDCP_EN_MASK                   (0x1U << CRU_GATE_CON21_HCLK_HDCP_EN_SHIFT)                  /* 0x00000002 */
#define CRU_GATE_CON21_PCLK_HDCP_EN_SHIFT                  (2U)
#define CRU_GATE_CON21_PCLK_HDCP_EN_MASK                   (0x1U << CRU_GATE_CON21_PCLK_HDCP_EN_SHIFT)                  /* 0x00000004 */
#define CRU_GATE_CON21_PCLK_HDMI_HOST_EN_SHIFT             (3U)
#define CRU_GATE_CON21_PCLK_HDMI_HOST_EN_MASK              (0x1U << CRU_GATE_CON21_PCLK_HDMI_HOST_EN_SHIFT)             /* 0x00000008 */
#define CRU_GATE_CON21_CLK_HDMI_SFR_EN_SHIFT               (4U)
#define CRU_GATE_CON21_CLK_HDMI_SFR_EN_MASK                (0x1U << CRU_GATE_CON21_CLK_HDMI_SFR_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON21_CLK_HDMI_CEC_EN_SHIFT               (5U)
#define CRU_GATE_CON21_CLK_HDMI_CEC_EN_MASK                (0x1U << CRU_GATE_CON21_CLK_HDMI_CEC_EN_SHIFT)               /* 0x00000020 */
#define CRU_GATE_CON21_PCLK_DSITX_0_EN_SHIFT               (6U)
#define CRU_GATE_CON21_PCLK_DSITX_0_EN_MASK                (0x1U << CRU_GATE_CON21_PCLK_DSITX_0_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON21_PCLK_DSITX_1_EN_SHIFT               (7U)
#define CRU_GATE_CON21_PCLK_DSITX_1_EN_MASK                (0x1U << CRU_GATE_CON21_PCLK_DSITX_1_EN_SHIFT)               /* 0x00000080 */
#define CRU_GATE_CON21_PCLK_EDP_CTRL_EN_SHIFT              (8U)
#define CRU_GATE_CON21_PCLK_EDP_CTRL_EN_MASK               (0x1U << CRU_GATE_CON21_PCLK_EDP_CTRL_EN_SHIFT)              /* 0x00000100 */
#define CRU_GATE_CON21_CLK_EDP_200M_EN_SHIFT               (9U)
#define CRU_GATE_CON21_CLK_EDP_200M_EN_MASK                (0x1U << CRU_GATE_CON21_CLK_EDP_200M_EN_SHIFT)               /* 0x00000200 */
/* GATE_CON22 */
#define CRU_GATE_CON22_OFFSET                              (0x358U)
#define CRU_GATE_CON22_ACLK_VPU_PRE_EN_SHIFT               (0U)
#define CRU_GATE_CON22_ACLK_VPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON22_ACLK_VPU_PRE_EN_SHIFT)               /* 0x00000001 */
#define CRU_GATE_CON22_HCLK_VPU_PRE_EN_SHIFT               (1U)
#define CRU_GATE_CON22_HCLK_VPU_PRE_EN_MASK                (0x1U << CRU_GATE_CON22_HCLK_VPU_PRE_EN_SHIFT)               /* 0x00000002 */
#define CRU_GATE_CON22_ACLK_VPU_NIU_EN_SHIFT               (2U)
#define CRU_GATE_CON22_ACLK_VPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON22_ACLK_VPU_NIU_EN_SHIFT)               /* 0x00000004 */
#define CRU_GATE_CON22_HCLK_VPU_NIU_EN_SHIFT               (3U)
#define CRU_GATE_CON22_HCLK_VPU_NIU_EN_MASK                (0x1U << CRU_GATE_CON22_HCLK_VPU_NIU_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON22_ACLK_VPU_EN_SHIFT                   (4U)
#define CRU_GATE_CON22_ACLK_VPU_EN_MASK                    (0x1U << CRU_GATE_CON22_ACLK_VPU_EN_SHIFT)                   /* 0x00000010 */
#define CRU_GATE_CON22_HCLK_VPU_EN_SHIFT                   (5U)
#define CRU_GATE_CON22_HCLK_VPU_EN_MASK                    (0x1U << CRU_GATE_CON22_HCLK_VPU_EN_SHIFT)                   /* 0x00000020 */
#define CRU_GATE_CON22_PCLK_RGA_PRE_EN_SHIFT               (12U)
#define CRU_GATE_CON22_PCLK_RGA_PRE_EN_MASK                (0x1U << CRU_GATE_CON22_PCLK_RGA_PRE_EN_SHIFT)               /* 0x00001000 */
#define CRU_GATE_CON22_PCLK_RGA_NIU_EN_SHIFT               (13U)
#define CRU_GATE_CON22_PCLK_RGA_NIU_EN_MASK                (0x1U << CRU_GATE_CON22_PCLK_RGA_NIU_EN_SHIFT)               /* 0x00002000 */
#define CRU_GATE_CON22_PCLK_EINK_EN_SHIFT                  (14U)
#define CRU_GATE_CON22_PCLK_EINK_EN_MASK                   (0x1U << CRU_GATE_CON22_PCLK_EINK_EN_SHIFT)                  /* 0x00004000 */
#define CRU_GATE_CON22_HCLK_EINK_EN_SHIFT                  (15U)
#define CRU_GATE_CON22_HCLK_EINK_EN_MASK                   (0x1U << CRU_GATE_CON22_HCLK_EINK_EN_SHIFT)                  /* 0x00008000 */
/* GATE_CON23 */
#define CRU_GATE_CON23_OFFSET                              (0x35CU)
#define CRU_GATE_CON23_ACLK_RGA_PRE_EN_SHIFT               (0U)
#define CRU_GATE_CON23_ACLK_RGA_PRE_EN_MASK                (0x1U << CRU_GATE_CON23_ACLK_RGA_PRE_EN_SHIFT)               /* 0x00000001 */
#define CRU_GATE_CON23_HCLK_RGA_PRE_EN_SHIFT               (1U)
#define CRU_GATE_CON23_HCLK_RGA_PRE_EN_MASK                (0x1U << CRU_GATE_CON23_HCLK_RGA_PRE_EN_SHIFT)               /* 0x00000002 */
#define CRU_GATE_CON23_ACLK_RGA_NIU_EN_SHIFT               (2U)
#define CRU_GATE_CON23_ACLK_RGA_NIU_EN_MASK                (0x1U << CRU_GATE_CON23_ACLK_RGA_NIU_EN_SHIFT)               /* 0x00000004 */
#define CRU_GATE_CON23_HCLK_RGA_NIU_EN_SHIFT               (3U)
#define CRU_GATE_CON23_HCLK_RGA_NIU_EN_MASK                (0x1U << CRU_GATE_CON23_HCLK_RGA_NIU_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON23_ACLK_RGA_EN_SHIFT                   (4U)
#define CRU_GATE_CON23_ACLK_RGA_EN_MASK                    (0x1U << CRU_GATE_CON23_ACLK_RGA_EN_SHIFT)                   /* 0x00000010 */
#define CRU_GATE_CON23_HCLK_RGA_EN_SHIFT                   (5U)
#define CRU_GATE_CON23_HCLK_RGA_EN_MASK                    (0x1U << CRU_GATE_CON23_HCLK_RGA_EN_SHIFT)                   /* 0x00000020 */
#define CRU_GATE_CON23_CLK_RGA_CORE_EN_SHIFT               (6U)
#define CRU_GATE_CON23_CLK_RGA_CORE_EN_MASK                (0x1U << CRU_GATE_CON23_CLK_RGA_CORE_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON23_ACLK_IEP_EN_SHIFT                   (7U)
#define CRU_GATE_CON23_ACLK_IEP_EN_MASK                    (0x1U << CRU_GATE_CON23_ACLK_IEP_EN_SHIFT)                   /* 0x00000080 */
#define CRU_GATE_CON23_HCLK_IEP_EN_SHIFT                   (8U)
#define CRU_GATE_CON23_HCLK_IEP_EN_MASK                    (0x1U << CRU_GATE_CON23_HCLK_IEP_EN_SHIFT)                   /* 0x00000100 */
#define CRU_GATE_CON23_CLK_IEP_CORE_EN_SHIFT               (9U)
#define CRU_GATE_CON23_CLK_IEP_CORE_EN_MASK                (0x1U << CRU_GATE_CON23_CLK_IEP_CORE_EN_SHIFT)               /* 0x00000200 */
#define CRU_GATE_CON23_HCLK_EBC_EN_SHIFT                   (10U)
#define CRU_GATE_CON23_HCLK_EBC_EN_MASK                    (0x1U << CRU_GATE_CON23_HCLK_EBC_EN_SHIFT)                   /* 0x00000400 */
#define CRU_GATE_CON23_DCLK_EBC_EN_SHIFT                   (11U)
#define CRU_GATE_CON23_DCLK_EBC_EN_MASK                    (0x1U << CRU_GATE_CON23_DCLK_EBC_EN_SHIFT)                   /* 0x00000800 */
#define CRU_GATE_CON23_ACLK_JDEC_EN_SHIFT                  (12U)
#define CRU_GATE_CON23_ACLK_JDEC_EN_MASK                   (0x1U << CRU_GATE_CON23_ACLK_JDEC_EN_SHIFT)                  /* 0x00001000 */
#define CRU_GATE_CON23_HCLK_JDEC_EN_SHIFT                  (13U)
#define CRU_GATE_CON23_HCLK_JDEC_EN_MASK                   (0x1U << CRU_GATE_CON23_HCLK_JDEC_EN_SHIFT)                  /* 0x00002000 */
#define CRU_GATE_CON23_ACLK_JENC_EN_SHIFT                  (14U)
#define CRU_GATE_CON23_ACLK_JENC_EN_MASK                   (0x1U << CRU_GATE_CON23_ACLK_JENC_EN_SHIFT)                  /* 0x00004000 */
#define CRU_GATE_CON23_HCLK_JENC_EN_SHIFT                  (15U)
#define CRU_GATE_CON23_HCLK_JENC_EN_MASK                   (0x1U << CRU_GATE_CON23_HCLK_JENC_EN_SHIFT)                  /* 0x00008000 */
/* GATE_CON24 */
#define CRU_GATE_CON24_OFFSET                              (0x360U)
#define CRU_GATE_CON24_ACLK_RKVENC_PRE_EN_SHIFT            (0U)
#define CRU_GATE_CON24_ACLK_RKVENC_PRE_EN_MASK             (0x1U << CRU_GATE_CON24_ACLK_RKVENC_PRE_EN_SHIFT)            /* 0x00000001 */
#define CRU_GATE_CON24_HCLK_RKVENC_PRE_EN_SHIFT            (1U)
#define CRU_GATE_CON24_HCLK_RKVENC_PRE_EN_MASK             (0x1U << CRU_GATE_CON24_HCLK_RKVENC_PRE_EN_SHIFT)            /* 0x00000002 */
#define CRU_GATE_CON24_ACLK_RKVENC_NIU_EN_SHIFT            (3U)
#define CRU_GATE_CON24_ACLK_RKVENC_NIU_EN_MASK             (0x1U << CRU_GATE_CON24_ACLK_RKVENC_NIU_EN_SHIFT)            /* 0x00000008 */
#define CRU_GATE_CON24_HCLK_RKVENC_NIU_EN_SHIFT            (4U)
#define CRU_GATE_CON24_HCLK_RKVENC_NIU_EN_MASK             (0x1U << CRU_GATE_CON24_HCLK_RKVENC_NIU_EN_SHIFT)            /* 0x00000010 */
#define CRU_GATE_CON24_ACLK_RKVENC_EN_SHIFT                (6U)
#define CRU_GATE_CON24_ACLK_RKVENC_EN_MASK                 (0x1U << CRU_GATE_CON24_ACLK_RKVENC_EN_SHIFT)                /* 0x00000040 */
#define CRU_GATE_CON24_HCLK_RKVENC_EN_SHIFT                (7U)
#define CRU_GATE_CON24_HCLK_RKVENC_EN_MASK                 (0x1U << CRU_GATE_CON24_HCLK_RKVENC_EN_SHIFT)                /* 0x00000080 */
#define CRU_GATE_CON24_CLK_RKVENC_CORE_EN_SHIFT            (8U)
#define CRU_GATE_CON24_CLK_RKVENC_CORE_EN_MASK             (0x1U << CRU_GATE_CON24_CLK_RKVENC_CORE_EN_SHIFT)            /* 0x00000100 */
/* GATE_CON25 */
#define CRU_GATE_CON25_OFFSET                              (0x364U)
#define CRU_GATE_CON25_ACLK_RKVDEC_PRE_EN_SHIFT            (0U)
#define CRU_GATE_CON25_ACLK_RKVDEC_PRE_EN_MASK             (0x1U << CRU_GATE_CON25_ACLK_RKVDEC_PRE_EN_SHIFT)            /* 0x00000001 */
#define CRU_GATE_CON25_HCLK_RKVDEC_PRE_EN_SHIFT            (1U)
#define CRU_GATE_CON25_HCLK_RKVDEC_PRE_EN_MASK             (0x1U << CRU_GATE_CON25_HCLK_RKVDEC_PRE_EN_SHIFT)            /* 0x00000002 */
#define CRU_GATE_CON25_ACLK_RKVDEC_NIU_EN_SHIFT            (2U)
#define CRU_GATE_CON25_ACLK_RKVDEC_NIU_EN_MASK             (0x1U << CRU_GATE_CON25_ACLK_RKVDEC_NIU_EN_SHIFT)            /* 0x00000004 */
#define CRU_GATE_CON25_HCLK_RKVDEC_NIU_EN_SHIFT            (3U)
#define CRU_GATE_CON25_HCLK_RKVDEC_NIU_EN_MASK             (0x1U << CRU_GATE_CON25_HCLK_RKVDEC_NIU_EN_SHIFT)            /* 0x00000008 */
#define CRU_GATE_CON25_ACLK_RKVDEC_EN_SHIFT                (4U)
#define CRU_GATE_CON25_ACLK_RKVDEC_EN_MASK                 (0x1U << CRU_GATE_CON25_ACLK_RKVDEC_EN_SHIFT)                /* 0x00000010 */
#define CRU_GATE_CON25_HCLK_RKVDEC_EN_SHIFT                (5U)
#define CRU_GATE_CON25_HCLK_RKVDEC_EN_MASK                 (0x1U << CRU_GATE_CON25_HCLK_RKVDEC_EN_SHIFT)                /* 0x00000020 */
#define CRU_GATE_CON25_CLK_RKVDEC_CA_EN_SHIFT              (6U)
#define CRU_GATE_CON25_CLK_RKVDEC_CA_EN_MASK               (0x1U << CRU_GATE_CON25_CLK_RKVDEC_CA_EN_SHIFT)              /* 0x00000040 */
#define CRU_GATE_CON25_CLK_RKVDEC_CORE_EN_SHIFT            (7U)
#define CRU_GATE_CON25_CLK_RKVDEC_CORE_EN_MASK             (0x1U << CRU_GATE_CON25_CLK_RKVDEC_CORE_EN_SHIFT)            /* 0x00000080 */
#define CRU_GATE_CON25_CLK_RKVDEC_HEVC_CA_EN_SHIFT         (8U)
#define CRU_GATE_CON25_CLK_RKVDEC_HEVC_CA_EN_MASK          (0x1U << CRU_GATE_CON25_CLK_RKVDEC_HEVC_CA_EN_SHIFT)         /* 0x00000100 */
/* GATE_CON26 */
#define CRU_GATE_CON26_OFFSET                              (0x368U)
#define CRU_GATE_CON26_ACLK_BUS_EN_SHIFT                   (0U)
#define CRU_GATE_CON26_ACLK_BUS_EN_MASK                    (0x1U << CRU_GATE_CON26_ACLK_BUS_EN_SHIFT)                   /* 0x00000001 */
#define CRU_GATE_CON26_PCLK_BUS_EN_SHIFT                   (1U)
#define CRU_GATE_CON26_PCLK_BUS_EN_MASK                    (0x1U << CRU_GATE_CON26_PCLK_BUS_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON26_ACLK_BUS_NIU_EN_SHIFT               (2U)
#define CRU_GATE_CON26_ACLK_BUS_NIU_EN_MASK                (0x1U << CRU_GATE_CON26_ACLK_BUS_NIU_EN_SHIFT)               /* 0x00000004 */
#define CRU_GATE_CON26_PCLK_BUS_NIU_EN_SHIFT               (3U)
#define CRU_GATE_CON26_PCLK_BUS_NIU_EN_MASK                (0x1U << CRU_GATE_CON26_PCLK_BUS_NIU_EN_SHIFT)               /* 0x00000008 */
#define CRU_GATE_CON26_PCLK_TSADC_EN_SHIFT                 (4U)
#define CRU_GATE_CON26_PCLK_TSADC_EN_MASK                  (0x1U << CRU_GATE_CON26_PCLK_TSADC_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON26_CLK_TSADC_TSEN_EN_SHIFT             (5U)
#define CRU_GATE_CON26_CLK_TSADC_TSEN_EN_MASK              (0x1U << CRU_GATE_CON26_CLK_TSADC_TSEN_EN_SHIFT)             /* 0x00000020 */
#define CRU_GATE_CON26_CLK_TSADC_EN_SHIFT                  (6U)
#define CRU_GATE_CON26_CLK_TSADC_EN_MASK                   (0x1U << CRU_GATE_CON26_CLK_TSADC_EN_SHIFT)                  /* 0x00000040 */
#define CRU_GATE_CON26_PCLK_SARADC_EN_SHIFT                (7U)
#define CRU_GATE_CON26_PCLK_SARADC_EN_MASK                 (0x1U << CRU_GATE_CON26_PCLK_SARADC_EN_SHIFT)                /* 0x00000080 */
#define CRU_GATE_CON26_CLK_SARADC_EN_SHIFT                 (8U)
#define CRU_GATE_CON26_CLK_SARADC_EN_MASK                  (0x1U << CRU_GATE_CON26_CLK_SARADC_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON26_PCLK_OTPC_NS_EN_SHIFT               (9U)
#define CRU_GATE_CON26_PCLK_OTPC_NS_EN_MASK                (0x1U << CRU_GATE_CON26_PCLK_OTPC_NS_EN_SHIFT)               /* 0x00000200 */
#define CRU_GATE_CON26_CLK_OTPC_NS_SBPI_EN_SHIFT           (10U)
#define CRU_GATE_CON26_CLK_OTPC_NS_SBPI_EN_MASK            (0x1U << CRU_GATE_CON26_CLK_OTPC_NS_SBPI_EN_SHIFT)           /* 0x00000400 */
#define CRU_GATE_CON26_CLK_OTPC_NS_USR_EN_SHIFT            (11U)
#define CRU_GATE_CON26_CLK_OTPC_NS_USR_EN_MASK             (0x1U << CRU_GATE_CON26_CLK_OTPC_NS_USR_EN_SHIFT)            /* 0x00000800 */
#define CRU_GATE_CON26_PCLK_SCR_EN_SHIFT                   (12U)
#define CRU_GATE_CON26_PCLK_SCR_EN_MASK                    (0x1U << CRU_GATE_CON26_PCLK_SCR_EN_SHIFT)                   /* 0x00001000 */
#define CRU_GATE_CON26_PCLK_WDT_NS_EN_SHIFT                (13U)
#define CRU_GATE_CON26_PCLK_WDT_NS_EN_MASK                 (0x1U << CRU_GATE_CON26_PCLK_WDT_NS_EN_SHIFT)                /* 0x00002000 */
#define CRU_GATE_CON26_TCLK_WDT_NS_EN_SHIFT                (14U)
#define CRU_GATE_CON26_TCLK_WDT_NS_EN_MASK                 (0x1U << CRU_GATE_CON26_TCLK_WDT_NS_EN_SHIFT)                /* 0x00004000 */
/* GATE_CON27 */
#define CRU_GATE_CON27_OFFSET                              (0x36CU)
#define CRU_GATE_CON27_PCLK_GRF_EN_SHIFT                   (0U)
#define CRU_GATE_CON27_PCLK_GRF_EN_MASK                    (0x1U << CRU_GATE_CON27_PCLK_GRF_EN_SHIFT)                   /* 0x00000001 */
#define CRU_GATE_CON27_PCLK_GRF_VCCIO12_EN_SHIFT           (1U)
#define CRU_GATE_CON27_PCLK_GRF_VCCIO12_EN_MASK            (0x1U << CRU_GATE_CON27_PCLK_GRF_VCCIO12_EN_SHIFT)           /* 0x00000002 */
#define CRU_GATE_CON27_PCLK_GRF_VCCIO34_EN_SHIFT           (2U)
#define CRU_GATE_CON27_PCLK_GRF_VCCIO34_EN_MASK            (0x1U << CRU_GATE_CON27_PCLK_GRF_VCCIO34_EN_SHIFT)           /* 0x00000004 */
#define CRU_GATE_CON27_PCLK_GRF_VCCIO567_EN_SHIFT          (3U)
#define CRU_GATE_CON27_PCLK_GRF_VCCIO567_EN_MASK           (0x1U << CRU_GATE_CON27_PCLK_GRF_VCCIO567_EN_SHIFT)          /* 0x00000008 */
#define CRU_GATE_CON27_PCLK_DFT2APB_EN_SHIFT               (4U)
#define CRU_GATE_CON27_PCLK_DFT2APB_EN_MASK                (0x1U << CRU_GATE_CON27_PCLK_DFT2APB_EN_SHIFT)               /* 0x00000010 */
#define CRU_GATE_CON27_PCLK_CAN0_EN_SHIFT                  (5U)
#define CRU_GATE_CON27_PCLK_CAN0_EN_MASK                   (0x1U << CRU_GATE_CON27_PCLK_CAN0_EN_SHIFT)                  /* 0x00000020 */
#define CRU_GATE_CON27_CLK_CAN0_EN_SHIFT                   (6U)
#define CRU_GATE_CON27_CLK_CAN0_EN_MASK                    (0x1U << CRU_GATE_CON27_CLK_CAN0_EN_SHIFT)                   /* 0x00000040 */
#define CRU_GATE_CON27_PCLK_CAN1_EN_SHIFT                  (7U)
#define CRU_GATE_CON27_PCLK_CAN1_EN_MASK                   (0x1U << CRU_GATE_CON27_PCLK_CAN1_EN_SHIFT)                  /* 0x00000080 */
#define CRU_GATE_CON27_CLK_CAN1_EN_SHIFT                   (8U)
#define CRU_GATE_CON27_CLK_CAN1_EN_MASK                    (0x1U << CRU_GATE_CON27_CLK_CAN1_EN_SHIFT)                   /* 0x00000100 */
#define CRU_GATE_CON27_PCLK_CAN2_EN_SHIFT                  (9U)
#define CRU_GATE_CON27_PCLK_CAN2_EN_MASK                   (0x1U << CRU_GATE_CON27_PCLK_CAN2_EN_SHIFT)                  /* 0x00000200 */
#define CRU_GATE_CON27_CLK_CAN2_EN_SHIFT                   (10U)
#define CRU_GATE_CON27_CLK_CAN2_EN_MASK                    (0x1U << CRU_GATE_CON27_CLK_CAN2_EN_SHIFT)                   /* 0x00000400 */
#define CRU_GATE_CON27_PCLK_UART1_EN_SHIFT                 (12U)
#define CRU_GATE_CON27_PCLK_UART1_EN_MASK                  (0x1U << CRU_GATE_CON27_PCLK_UART1_EN_SHIFT)                 /* 0x00001000 */
#define CRU_GATE_CON27_CLK_UART1_EN_SHIFT                  (13U)
#define CRU_GATE_CON27_CLK_UART1_EN_MASK                   (0x1U << CRU_GATE_CON27_CLK_UART1_EN_SHIFT)                  /* 0x00002000 */
#define CRU_GATE_CON27_CLK_UART1_FRAC_EN_SHIFT             (14U)
#define CRU_GATE_CON27_CLK_UART1_FRAC_EN_MASK              (0x1U << CRU_GATE_CON27_CLK_UART1_FRAC_EN_SHIFT)             /* 0x00004000 */
#define CRU_GATE_CON27_SCLK_UART1_EN_SHIFT                 (15U)
#define CRU_GATE_CON27_SCLK_UART1_EN_MASK                  (0x1U << CRU_GATE_CON27_SCLK_UART1_EN_SHIFT)                 /* 0x00008000 */
/* GATE_CON28 */
#define CRU_GATE_CON28_OFFSET                              (0x370U)
#define CRU_GATE_CON28_PCLK_UART2_EN_SHIFT                 (0U)
#define CRU_GATE_CON28_PCLK_UART2_EN_MASK                  (0x1U << CRU_GATE_CON28_PCLK_UART2_EN_SHIFT)                 /* 0x00000001 */
#define CRU_GATE_CON28_CLK_UART2_EN_SHIFT                  (1U)
#define CRU_GATE_CON28_CLK_UART2_EN_MASK                   (0x1U << CRU_GATE_CON28_CLK_UART2_EN_SHIFT)                  /* 0x00000002 */
#define CRU_GATE_CON28_CLK_UART2_FRAC_EN_SHIFT             (2U)
#define CRU_GATE_CON28_CLK_UART2_FRAC_EN_MASK              (0x1U << CRU_GATE_CON28_CLK_UART2_FRAC_EN_SHIFT)             /* 0x00000004 */
#define CRU_GATE_CON28_SCLK_UART2_EN_SHIFT                 (3U)
#define CRU_GATE_CON28_SCLK_UART2_EN_MASK                  (0x1U << CRU_GATE_CON28_SCLK_UART2_EN_SHIFT)                 /* 0x00000008 */
#define CRU_GATE_CON28_PCLK_UART3_EN_SHIFT                 (4U)
#define CRU_GATE_CON28_PCLK_UART3_EN_MASK                  (0x1U << CRU_GATE_CON28_PCLK_UART3_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON28_CLK_UART3_EN_SHIFT                  (5U)
#define CRU_GATE_CON28_CLK_UART3_EN_MASK                   (0x1U << CRU_GATE_CON28_CLK_UART3_EN_SHIFT)                  /* 0x00000020 */
#define CRU_GATE_CON28_CLK_UART3_FRAC_EN_SHIFT             (6U)
#define CRU_GATE_CON28_CLK_UART3_FRAC_EN_MASK              (0x1U << CRU_GATE_CON28_CLK_UART3_FRAC_EN_SHIFT)             /* 0x00000040 */
#define CRU_GATE_CON28_SCLK_UART3_EN_SHIFT                 (7U)
#define CRU_GATE_CON28_SCLK_UART3_EN_MASK                  (0x1U << CRU_GATE_CON28_SCLK_UART3_EN_SHIFT)                 /* 0x00000080 */
#define CRU_GATE_CON28_PCLK_UART4_EN_SHIFT                 (8U)
#define CRU_GATE_CON28_PCLK_UART4_EN_MASK                  (0x1U << CRU_GATE_CON28_PCLK_UART4_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON28_CLK_UART4_EN_SHIFT                  (9U)
#define CRU_GATE_CON28_CLK_UART4_EN_MASK                   (0x1U << CRU_GATE_CON28_CLK_UART4_EN_SHIFT)                  /* 0x00000200 */
#define CRU_GATE_CON28_CLK_UART4_FRAC_EN_SHIFT             (10U)
#define CRU_GATE_CON28_CLK_UART4_FRAC_EN_MASK              (0x1U << CRU_GATE_CON28_CLK_UART4_FRAC_EN_SHIFT)             /* 0x00000400 */
#define CRU_GATE_CON28_SCLK_UART4_EN_SHIFT                 (11U)
#define CRU_GATE_CON28_SCLK_UART4_EN_MASK                  (0x1U << CRU_GATE_CON28_SCLK_UART4_EN_SHIFT)                 /* 0x00000800 */
#define CRU_GATE_CON28_PCLK_UART5_EN_SHIFT                 (12U)
#define CRU_GATE_CON28_PCLK_UART5_EN_MASK                  (0x1U << CRU_GATE_CON28_PCLK_UART5_EN_SHIFT)                 /* 0x00001000 */
#define CRU_GATE_CON28_CLK_UART5_EN_SHIFT                  (13U)
#define CRU_GATE_CON28_CLK_UART5_EN_MASK                   (0x1U << CRU_GATE_CON28_CLK_UART5_EN_SHIFT)                  /* 0x00002000 */
#define CRU_GATE_CON28_CLK_UART5_FRAC_EN_SHIFT             (14U)
#define CRU_GATE_CON28_CLK_UART5_FRAC_EN_MASK              (0x1U << CRU_GATE_CON28_CLK_UART5_FRAC_EN_SHIFT)             /* 0x00004000 */
#define CRU_GATE_CON28_SCLK_UART5_EN_SHIFT                 (15U)
#define CRU_GATE_CON28_SCLK_UART5_EN_MASK                  (0x1U << CRU_GATE_CON28_SCLK_UART5_EN_SHIFT)                 /* 0x00008000 */
/* GATE_CON29 */
#define CRU_GATE_CON29_OFFSET                              (0x374U)
#define CRU_GATE_CON29_PCLK_UART6_EN_SHIFT                 (0U)
#define CRU_GATE_CON29_PCLK_UART6_EN_MASK                  (0x1U << CRU_GATE_CON29_PCLK_UART6_EN_SHIFT)                 /* 0x00000001 */
#define CRU_GATE_CON29_CLK_UART6_EN_SHIFT                  (1U)
#define CRU_GATE_CON29_CLK_UART6_EN_MASK                   (0x1U << CRU_GATE_CON29_CLK_UART6_EN_SHIFT)                  /* 0x00000002 */
#define CRU_GATE_CON29_CLK_UART6_FRAC_EN_SHIFT             (2U)
#define CRU_GATE_CON29_CLK_UART6_FRAC_EN_MASK              (0x1U << CRU_GATE_CON29_CLK_UART6_FRAC_EN_SHIFT)             /* 0x00000004 */
#define CRU_GATE_CON29_SCLK_UART6_EN_SHIFT                 (3U)
#define CRU_GATE_CON29_SCLK_UART6_EN_MASK                  (0x1U << CRU_GATE_CON29_SCLK_UART6_EN_SHIFT)                 /* 0x00000008 */
#define CRU_GATE_CON29_PCLK_UART7_EN_SHIFT                 (4U)
#define CRU_GATE_CON29_PCLK_UART7_EN_MASK                  (0x1U << CRU_GATE_CON29_PCLK_UART7_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON29_CLK_UART7_EN_SHIFT                  (5U)
#define CRU_GATE_CON29_CLK_UART7_EN_MASK                   (0x1U << CRU_GATE_CON29_CLK_UART7_EN_SHIFT)                  /* 0x00000020 */
#define CRU_GATE_CON29_CLK_UART7_FRAC_EN_SHIFT             (6U)
#define CRU_GATE_CON29_CLK_UART7_FRAC_EN_MASK              (0x1U << CRU_GATE_CON29_CLK_UART7_FRAC_EN_SHIFT)             /* 0x00000040 */
#define CRU_GATE_CON29_SCLK_UART7_EN_SHIFT                 (7U)
#define CRU_GATE_CON29_SCLK_UART7_EN_MASK                  (0x1U << CRU_GATE_CON29_SCLK_UART7_EN_SHIFT)                 /* 0x00000080 */
#define CRU_GATE_CON29_PCLK_UART8_EN_SHIFT                 (8U)
#define CRU_GATE_CON29_PCLK_UART8_EN_MASK                  (0x1U << CRU_GATE_CON29_PCLK_UART8_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON29_CLK_UART8_EN_SHIFT                  (9U)
#define CRU_GATE_CON29_CLK_UART8_EN_MASK                   (0x1U << CRU_GATE_CON29_CLK_UART8_EN_SHIFT)                  /* 0x00000200 */
#define CRU_GATE_CON29_CLK_UART8_FRAC_EN_SHIFT             (10U)
#define CRU_GATE_CON29_CLK_UART8_FRAC_EN_MASK              (0x1U << CRU_GATE_CON29_CLK_UART8_FRAC_EN_SHIFT)             /* 0x00000400 */
#define CRU_GATE_CON29_SCLK_UART8_EN_SHIFT                 (11U)
#define CRU_GATE_CON29_SCLK_UART8_EN_MASK                  (0x1U << CRU_GATE_CON29_SCLK_UART8_EN_SHIFT)                 /* 0x00000800 */
#define CRU_GATE_CON29_PCLK_UART9_EN_SHIFT                 (12U)
#define CRU_GATE_CON29_PCLK_UART9_EN_MASK                  (0x1U << CRU_GATE_CON29_PCLK_UART9_EN_SHIFT)                 /* 0x00001000 */
#define CRU_GATE_CON29_CLK_UART9_EN_SHIFT                  (13U)
#define CRU_GATE_CON29_CLK_UART9_EN_MASK                   (0x1U << CRU_GATE_CON29_CLK_UART9_EN_SHIFT)                  /* 0x00002000 */
#define CRU_GATE_CON29_CLK_UART9_FRAC_EN_SHIFT             (14U)
#define CRU_GATE_CON29_CLK_UART9_FRAC_EN_MASK              (0x1U << CRU_GATE_CON29_CLK_UART9_FRAC_EN_SHIFT)             /* 0x00004000 */
#define CRU_GATE_CON29_SCLK_UART9_EN_SHIFT                 (15U)
#define CRU_GATE_CON29_SCLK_UART9_EN_MASK                  (0x1U << CRU_GATE_CON29_SCLK_UART9_EN_SHIFT)                 /* 0x00008000 */
/* GATE_CON30 */
#define CRU_GATE_CON30_OFFSET                              (0x378U)
#define CRU_GATE_CON30_PCLK_I2C1_EN_SHIFT                  (0U)
#define CRU_GATE_CON30_PCLK_I2C1_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_I2C1_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON30_CLK_I2C1_EN_SHIFT                   (1U)
#define CRU_GATE_CON30_CLK_I2C1_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_I2C1_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON30_PCLK_I2C2_EN_SHIFT                  (2U)
#define CRU_GATE_CON30_PCLK_I2C2_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_I2C2_EN_SHIFT)                  /* 0x00000004 */
#define CRU_GATE_CON30_CLK_I2C2_EN_SHIFT                   (3U)
#define CRU_GATE_CON30_CLK_I2C2_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_I2C2_EN_SHIFT)                   /* 0x00000008 */
#define CRU_GATE_CON30_PCLK_I2C3_EN_SHIFT                  (4U)
#define CRU_GATE_CON30_PCLK_I2C3_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_I2C3_EN_SHIFT)                  /* 0x00000010 */
#define CRU_GATE_CON30_CLK_I2C3_EN_SHIFT                   (5U)
#define CRU_GATE_CON30_CLK_I2C3_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_I2C3_EN_SHIFT)                   /* 0x00000020 */
#define CRU_GATE_CON30_PCLK_I2C4_EN_SHIFT                  (6U)
#define CRU_GATE_CON30_PCLK_I2C4_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_I2C4_EN_SHIFT)                  /* 0x00000040 */
#define CRU_GATE_CON30_CLK_I2C4_EN_SHIFT                   (7U)
#define CRU_GATE_CON30_CLK_I2C4_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_I2C4_EN_SHIFT)                   /* 0x00000080 */
#define CRU_GATE_CON30_PCLK_I2C5_EN_SHIFT                  (8U)
#define CRU_GATE_CON30_PCLK_I2C5_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_I2C5_EN_SHIFT)                  /* 0x00000100 */
#define CRU_GATE_CON30_CLK_I2C5_EN_SHIFT                   (9U)
#define CRU_GATE_CON30_CLK_I2C5_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_I2C5_EN_SHIFT)                   /* 0x00000200 */
#define CRU_GATE_CON30_PCLK_SPI0_EN_SHIFT                  (10U)
#define CRU_GATE_CON30_PCLK_SPI0_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_SPI0_EN_SHIFT)                  /* 0x00000400 */
#define CRU_GATE_CON30_CLK_SPI0_EN_SHIFT                   (11U)
#define CRU_GATE_CON30_CLK_SPI0_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_SPI0_EN_SHIFT)                   /* 0x00000800 */
#define CRU_GATE_CON30_PCLK_SPI1_EN_SHIFT                  (12U)
#define CRU_GATE_CON30_PCLK_SPI1_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_SPI1_EN_SHIFT)                  /* 0x00001000 */
#define CRU_GATE_CON30_CLK_SPI1_EN_SHIFT                   (13U)
#define CRU_GATE_CON30_CLK_SPI1_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_SPI1_EN_SHIFT)                   /* 0x00002000 */
#define CRU_GATE_CON30_PCLK_SPI2_EN_SHIFT                  (14U)
#define CRU_GATE_CON30_PCLK_SPI2_EN_MASK                   (0x1U << CRU_GATE_CON30_PCLK_SPI2_EN_SHIFT)                  /* 0x00004000 */
#define CRU_GATE_CON30_CLK_SPI2_EN_SHIFT                   (15U)
#define CRU_GATE_CON30_CLK_SPI2_EN_MASK                    (0x1U << CRU_GATE_CON30_CLK_SPI2_EN_SHIFT)                   /* 0x00008000 */
/* GATE_CON31 */
#define CRU_GATE_CON31_OFFSET                              (0x37CU)
#define CRU_GATE_CON31_PCLK_SPI3_EN_SHIFT                  (0U)
#define CRU_GATE_CON31_PCLK_SPI3_EN_MASK                   (0x1U << CRU_GATE_CON31_PCLK_SPI3_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON31_CLK_SPI3_EN_SHIFT                   (1U)
#define CRU_GATE_CON31_CLK_SPI3_EN_MASK                    (0x1U << CRU_GATE_CON31_CLK_SPI3_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON31_PCLK_GPIO1_EN_SHIFT                 (2U)
#define CRU_GATE_CON31_PCLK_GPIO1_EN_MASK                  (0x1U << CRU_GATE_CON31_PCLK_GPIO1_EN_SHIFT)                 /* 0x00000004 */
#define CRU_GATE_CON31_DBCLK_GPIO1_EN_SHIFT                (3U)
#define CRU_GATE_CON31_DBCLK_GPIO1_EN_MASK                 (0x1U << CRU_GATE_CON31_DBCLK_GPIO1_EN_SHIFT)                /* 0x00000008 */
#define CRU_GATE_CON31_PCLK_GPIO2_EN_SHIFT                 (4U)
#define CRU_GATE_CON31_PCLK_GPIO2_EN_MASK                  (0x1U << CRU_GATE_CON31_PCLK_GPIO2_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON31_DBCLK_GPIO2_EN_SHIFT                (5U)
#define CRU_GATE_CON31_DBCLK_GPIO2_EN_MASK                 (0x1U << CRU_GATE_CON31_DBCLK_GPIO2_EN_SHIFT)                /* 0x00000020 */
#define CRU_GATE_CON31_PCLK_GPIO3_EN_SHIFT                 (6U)
#define CRU_GATE_CON31_PCLK_GPIO3_EN_MASK                  (0x1U << CRU_GATE_CON31_PCLK_GPIO3_EN_SHIFT)                 /* 0x00000040 */
#define CRU_GATE_CON31_DBCLK_GPIO3_EN_SHIFT                (7U)
#define CRU_GATE_CON31_DBCLK_GPIO3_EN_MASK                 (0x1U << CRU_GATE_CON31_DBCLK_GPIO3_EN_SHIFT)                /* 0x00000080 */
#define CRU_GATE_CON31_PCLK_GPIO4_EN_SHIFT                 (8U)
#define CRU_GATE_CON31_PCLK_GPIO4_EN_MASK                  (0x1U << CRU_GATE_CON31_PCLK_GPIO4_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON31_DBCLK_GPIO4_EN_SHIFT                (9U)
#define CRU_GATE_CON31_DBCLK_GPIO4_EN_MASK                 (0x1U << CRU_GATE_CON31_DBCLK_GPIO4_EN_SHIFT)                /* 0x00000200 */
#define CRU_GATE_CON31_PCLK_PWM1_EN_SHIFT                  (10U)
#define CRU_GATE_CON31_PCLK_PWM1_EN_MASK                   (0x1U << CRU_GATE_CON31_PCLK_PWM1_EN_SHIFT)                  /* 0x00000400 */
#define CRU_GATE_CON31_CLK_PWM1_EN_SHIFT                   (11U)
#define CRU_GATE_CON31_CLK_PWM1_EN_MASK                    (0x1U << CRU_GATE_CON31_CLK_PWM1_EN_SHIFT)                   /* 0x00000800 */
#define CRU_GATE_CON31_CLK_PWM1_CAPTURE_EN_SHIFT           (12U)
#define CRU_GATE_CON31_CLK_PWM1_CAPTURE_EN_MASK            (0x1U << CRU_GATE_CON31_CLK_PWM1_CAPTURE_EN_SHIFT)           /* 0x00001000 */
#define CRU_GATE_CON31_PCLK_PWM2_EN_SHIFT                  (13U)
#define CRU_GATE_CON31_PCLK_PWM2_EN_MASK                   (0x1U << CRU_GATE_CON31_PCLK_PWM2_EN_SHIFT)                  /* 0x00002000 */
#define CRU_GATE_CON31_CLK_PWM2_EN_SHIFT                   (14U)
#define CRU_GATE_CON31_CLK_PWM2_EN_MASK                    (0x1U << CRU_GATE_CON31_CLK_PWM2_EN_SHIFT)                   /* 0x00004000 */
#define CRU_GATE_CON31_CLK_PWM2_CAPTURE_EN_SHIFT           (15U)
#define CRU_GATE_CON31_CLK_PWM2_CAPTURE_EN_MASK            (0x1U << CRU_GATE_CON31_CLK_PWM2_CAPTURE_EN_SHIFT)           /* 0x00008000 */
/* GATE_CON32 */
#define CRU_GATE_CON32_OFFSET                              (0x380U)
#define CRU_GATE_CON32_PCLK_PWM3_EN_SHIFT                  (0U)
#define CRU_GATE_CON32_PCLK_PWM3_EN_MASK                   (0x1U << CRU_GATE_CON32_PCLK_PWM3_EN_SHIFT)                  /* 0x00000001 */
#define CRU_GATE_CON32_CLK_PWM3_EN_SHIFT                   (1U)
#define CRU_GATE_CON32_CLK_PWM3_EN_MASK                    (0x1U << CRU_GATE_CON32_CLK_PWM3_EN_SHIFT)                   /* 0x00000002 */
#define CRU_GATE_CON32_CLK_PWM3_CAPTURE_EN_SHIFT           (2U)
#define CRU_GATE_CON32_CLK_PWM3_CAPTURE_EN_MASK            (0x1U << CRU_GATE_CON32_CLK_PWM3_CAPTURE_EN_SHIFT)           /* 0x00000004 */
#define CRU_GATE_CON32_PCLK_TIMER_EN_SHIFT                 (3U)
#define CRU_GATE_CON32_PCLK_TIMER_EN_MASK                  (0x1U << CRU_GATE_CON32_PCLK_TIMER_EN_SHIFT)                 /* 0x00000008 */
#define CRU_GATE_CON32_CLK_TIMER0_EN_SHIFT                 (4U)
#define CRU_GATE_CON32_CLK_TIMER0_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER0_EN_SHIFT)                 /* 0x00000010 */
#define CRU_GATE_CON32_CLK_TIMER1_EN_SHIFT                 (5U)
#define CRU_GATE_CON32_CLK_TIMER1_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER1_EN_SHIFT)                 /* 0x00000020 */
#define CRU_GATE_CON32_CLK_TIMER2_EN_SHIFT                 (6U)
#define CRU_GATE_CON32_CLK_TIMER2_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER2_EN_SHIFT)                 /* 0x00000040 */
#define CRU_GATE_CON32_CLK_TIMER3_EN_SHIFT                 (7U)
#define CRU_GATE_CON32_CLK_TIMER3_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER3_EN_SHIFT)                 /* 0x00000080 */
#define CRU_GATE_CON32_CLK_TIMER4_EN_SHIFT                 (8U)
#define CRU_GATE_CON32_CLK_TIMER4_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER4_EN_SHIFT)                 /* 0x00000100 */
#define CRU_GATE_CON32_CLK_TIMER5_EN_SHIFT                 (9U)
#define CRU_GATE_CON32_CLK_TIMER5_EN_MASK                  (0x1U << CRU_GATE_CON32_CLK_TIMER5_EN_SHIFT)                 /* 0x00000200 */
#define CRU_GATE_CON32_CLK_I2C_EN_SHIFT                    (10U)
#define CRU_GATE_CON32_CLK_I2C_EN_MASK                     (0x1U << CRU_GATE_CON32_CLK_I2C_EN_SHIFT)                    /* 0x00000400 */
#define CRU_GATE_CON32_DBCLK_GPIO_EN_SHIFT                 (11U)
#define CRU_GATE_CON32_DBCLK_GPIO_EN_MASK                  (0x1U << CRU_GATE_CON32_DBCLK_GPIO_EN_SHIFT)                 /* 0x00000800 */
#define CRU_GATE_CON32_CLK_TIMER_EN_SHIFT                  (12U)
#define CRU_GATE_CON32_CLK_TIMER_EN_MASK                   (0x1U << CRU_GATE_CON32_CLK_TIMER_EN_SHIFT)                  /* 0x00001000 */
#define CRU_GATE_CON32_ACLK_MCU_EN_SHIFT                   (13U)
#define CRU_GATE_CON32_ACLK_MCU_EN_MASK                    (0x1U << CRU_GATE_CON32_ACLK_MCU_EN_SHIFT)                   /* 0x00002000 */
#define CRU_GATE_CON32_PCLK_INTMUX_EN_SHIFT                (14U)
#define CRU_GATE_CON32_PCLK_INTMUX_EN_MASK                 (0x1U << CRU_GATE_CON32_PCLK_INTMUX_EN_SHIFT)                /* 0x00004000 */
#define CRU_GATE_CON32_PCLK_MAILBOX_EN_SHIFT               (15U)
#define CRU_GATE_CON32_PCLK_MAILBOX_EN_MASK                (0x1U << CRU_GATE_CON32_PCLK_MAILBOX_EN_SHIFT)               /* 0x00008000 */
/* GATE_CON33 */
#define CRU_GATE_CON33_OFFSET                              (0x384U)
#define CRU_GATE_CON33_ACLK_TOP_HIGH_EN_SHIFT              (0U)
#define CRU_GATE_CON33_ACLK_TOP_HIGH_EN_MASK               (0x1U << CRU_GATE_CON33_ACLK_TOP_HIGH_EN_SHIFT)              /* 0x00000001 */
#define CRU_GATE_CON33_ACLK_TOP_LOW_EN_SHIFT               (1U)
#define CRU_GATE_CON33_ACLK_TOP_LOW_EN_MASK                (0x1U << CRU_GATE_CON33_ACLK_TOP_LOW_EN_SHIFT)               /* 0x00000002 */
#define CRU_GATE_CON33_HCLK_TOP_EN_SHIFT                   (2U)
#define CRU_GATE_CON33_HCLK_TOP_EN_MASK                    (0x1U << CRU_GATE_CON33_HCLK_TOP_EN_SHIFT)                   /* 0x00000004 */
#define CRU_GATE_CON33_PCLK_TOP_EN_SHIFT                   (3U)
#define CRU_GATE_CON33_PCLK_TOP_EN_MASK                    (0x1U << CRU_GATE_CON33_PCLK_TOP_EN_SHIFT)                   /* 0x00000008 */
#define CRU_GATE_CON33_ACLK_TOP_HIGH_NIU_EN_SHIFT          (4U)
#define CRU_GATE_CON33_ACLK_TOP_HIGH_NIU_EN_MASK           (0x1U << CRU_GATE_CON33_ACLK_TOP_HIGH_NIU_EN_SHIFT)          /* 0x00000010 */
#define CRU_GATE_CON33_ACLK_TOP_LOW_NIU_EN_SHIFT           (5U)
#define CRU_GATE_CON33_ACLK_TOP_LOW_NIU_EN_MASK            (0x1U << CRU_GATE_CON33_ACLK_TOP_LOW_NIU_EN_SHIFT)           /* 0x00000020 */
#define CRU_GATE_CON33_HCLK_TOP_NIU_EN_SHIFT               (6U)
#define CRU_GATE_CON33_HCLK_TOP_NIU_EN_MASK                (0x1U << CRU_GATE_CON33_HCLK_TOP_NIU_EN_SHIFT)               /* 0x00000040 */
#define CRU_GATE_CON33_PCLK_TOP_NIU_EN_SHIFT               (7U)
#define CRU_GATE_CON33_PCLK_TOP_NIU_EN_MASK                (0x1U << CRU_GATE_CON33_PCLK_TOP_NIU_EN_SHIFT)               /* 0x00000080 */
#define CRU_GATE_CON33_PCLK_PCIE30PHY_EN_SHIFT             (8U)
#define CRU_GATE_CON33_PCLK_PCIE30PHY_EN_MASK              (0x1U << CRU_GATE_CON33_PCLK_PCIE30PHY_EN_SHIFT)             /* 0x00000100 */
#define CRU_GATE_CON33_CLK_OTPC_ARB_EN_SHIFT               (9U)
#define CRU_GATE_CON33_CLK_OTPC_ARB_EN_MASK                (0x1U << CRU_GATE_CON33_CLK_OTPC_ARB_EN_SHIFT)               /* 0x00000200 */
#define CRU_GATE_CON33_PCLK_TOP_CRU_EN_SHIFT               (12U)
#define CRU_GATE_CON33_PCLK_TOP_CRU_EN_MASK                (0x1U << CRU_GATE_CON33_PCLK_TOP_CRU_EN_SHIFT)               /* 0x00001000 */
#define CRU_GATE_CON33_PCLK_MIPICSIPHY_EN_SHIFT            (13U)
#define CRU_GATE_CON33_PCLK_MIPICSIPHY_EN_MASK             (0x1U << CRU_GATE_CON33_PCLK_MIPICSIPHY_EN_SHIFT)            /* 0x00002000 */
#define CRU_GATE_CON33_PCLK_MIPIDSIPHY0_EN_SHIFT           (14U)
#define CRU_GATE_CON33_PCLK_MIPIDSIPHY0_EN_MASK            (0x1U << CRU_GATE_CON33_PCLK_MIPIDSIPHY0_EN_SHIFT)           /* 0x00004000 */
#define CRU_GATE_CON33_PCLK_MIPIDSIPHY1_EN_SHIFT           (15U)
#define CRU_GATE_CON33_PCLK_MIPIDSIPHY1_EN_MASK            (0x1U << CRU_GATE_CON33_PCLK_MIPIDSIPHY1_EN_SHIFT)           /* 0x00008000 */
/* GATE_CON34 */
#define CRU_GATE_CON34_OFFSET                              (0x388U)
#define CRU_GATE_CON34_PCLK_APB2ASB_CHIP_LEFT_EN_SHIFT     (0U)
#define CRU_GATE_CON34_PCLK_APB2ASB_CHIP_LEFT_EN_MASK      (0x1U << CRU_GATE_CON34_PCLK_APB2ASB_CHIP_LEFT_EN_SHIFT)     /* 0x00000001 */
#define CRU_GATE_CON34_PCLK_APB2ASB_CHIP_BOTTOM_EN_SHIFT   (1U)
#define CRU_GATE_CON34_PCLK_APB2ASB_CHIP_BOTTOM_EN_MASK    (0x1U << CRU_GATE_CON34_PCLK_APB2ASB_CHIP_BOTTOM_EN_SHIFT)   /* 0x00000002 */
#define CRU_GATE_CON34_PCLK_ASB2APB_CHIP_LEFT_EN_SHIFT     (2U)
#define CRU_GATE_CON34_PCLK_ASB2APB_CHIP_LEFT_EN_MASK      (0x1U << CRU_GATE_CON34_PCLK_ASB2APB_CHIP_LEFT_EN_SHIFT)     /* 0x00000004 */
#define CRU_GATE_CON34_PCLK_ASB2APB_CHIP_BOTTOM_EN_SHIFT   (3U)
#define CRU_GATE_CON34_PCLK_ASB2APB_CHIP_BOTTOM_EN_MASK    (0x1U << CRU_GATE_CON34_PCLK_ASB2APB_CHIP_BOTTOM_EN_SHIFT)   /* 0x00000008 */
#define CRU_GATE_CON34_PCLK_PIPEPHY0_EN_SHIFT              (4U)
#define CRU_GATE_CON34_PCLK_PIPEPHY0_EN_MASK               (0x1U << CRU_GATE_CON34_PCLK_PIPEPHY0_EN_SHIFT)              /* 0x00000010 */
#define CRU_GATE_CON34_PCLK_PIPEPHY1_EN_SHIFT              (5U)
#define CRU_GATE_CON34_PCLK_PIPEPHY1_EN_MASK               (0x1U << CRU_GATE_CON34_PCLK_PIPEPHY1_EN_SHIFT)              /* 0x00000020 */
#define CRU_GATE_CON34_PCLK_PIPEPHY2_EN_SHIFT              (6U)
#define CRU_GATE_CON34_PCLK_PIPEPHY2_EN_MASK               (0x1U << CRU_GATE_CON34_PCLK_PIPEPHY2_EN_SHIFT)              /* 0x00000040 */
#define CRU_GATE_CON34_PCLK_USB2PHY0_GRF_EN_SHIFT          (7U)
#define CRU_GATE_CON34_PCLK_USB2PHY0_GRF_EN_MASK           (0x1U << CRU_GATE_CON34_PCLK_USB2PHY0_GRF_EN_SHIFT)          /* 0x00000080 */
#define CRU_GATE_CON34_PCLK_USB2PHY1_GRF_EN_SHIFT          (8U)
#define CRU_GATE_CON34_PCLK_USB2PHY1_GRF_EN_MASK           (0x1U << CRU_GATE_CON34_PCLK_USB2PHY1_GRF_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON34_PCLK_DDRPHY_EN_SHIFT                (9U)
#define CRU_GATE_CON34_PCLK_DDRPHY_EN_MASK                 (0x1U << CRU_GATE_CON34_PCLK_DDRPHY_EN_SHIFT)                /* 0x00000200 */
#define CRU_GATE_CON34_CLK_DDRPHY_EN_SHIFT                 (10U)
#define CRU_GATE_CON34_CLK_DDRPHY_EN_MASK                  (0x1U << CRU_GATE_CON34_CLK_DDRPHY_EN_SHIFT)                 /* 0x00000400 */
#define CRU_GATE_CON34_PCLK_CPU_BOOST_EN_SHIFT             (11U)
#define CRU_GATE_CON34_PCLK_CPU_BOOST_EN_MASK              (0x1U << CRU_GATE_CON34_PCLK_CPU_BOOST_EN_SHIFT)             /* 0x00000800 */
#define CRU_GATE_CON34_CLK_CPU_BOOST_EN_SHIFT              (12U)
#define CRU_GATE_CON34_CLK_CPU_BOOST_EN_MASK               (0x1U << CRU_GATE_CON34_CLK_CPU_BOOST_EN_SHIFT)              /* 0x00001000 */
#define CRU_GATE_CON34_PCLK_OTPPHY_EN_SHIFT                (13U)
#define CRU_GATE_CON34_PCLK_OTPPHY_EN_MASK                 (0x1U << CRU_GATE_CON34_PCLK_OTPPHY_EN_SHIFT)                /* 0x00002000 */
#define CRU_GATE_CON34_PCLK_EDPPHY_GRF_EN_SHIFT            (14U)
#define CRU_GATE_CON34_PCLK_EDPPHY_GRF_EN_MASK             (0x1U << CRU_GATE_CON34_PCLK_EDPPHY_GRF_EN_SHIFT)            /* 0x00004000 */
#define CRU_GATE_CON34_CLK_TESTOUT_EN_SHIFT                (15U)
#define CRU_GATE_CON34_CLK_TESTOUT_EN_MASK                 (0x1U << CRU_GATE_CON34_CLK_TESTOUT_EN_SHIFT)                /* 0x00008000 */
/* GATE_CON35 */
#define CRU_GATE_CON35_OFFSET                              (0x38CU)
#define CRU_GATE_CON35_CLK_GPLL_DIV_400M_EN_SHIFT          (0U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_400M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_400M_EN_SHIFT)          /* 0x00000001 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_300M_EN_SHIFT          (1U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_300M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_300M_EN_SHIFT)          /* 0x00000002 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_200M_EN_SHIFT          (2U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_200M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_200M_EN_SHIFT)          /* 0x00000004 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_150M_EN_SHIFT          (3U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_150M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_150M_EN_SHIFT)          /* 0x00000008 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_100M_EN_SHIFT          (4U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_100M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_100M_EN_SHIFT)          /* 0x00000010 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_75M_EN_SHIFT           (5U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_75M_EN_MASK            (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_75M_EN_SHIFT)           /* 0x00000020 */
#define CRU_GATE_CON35_CLK_GPLL_DIV_20M_EN_SHIFT           (6U)
#define CRU_GATE_CON35_CLK_GPLL_DIV_20M_EN_MASK            (0x1U << CRU_GATE_CON35_CLK_GPLL_DIV_20M_EN_SHIFT)           /* 0x00000040 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_500M_EN_SHIFT          (7U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_500M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_500M_EN_SHIFT)          /* 0x00000080 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_333M_EN_SHIFT          (8U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_333M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_333M_EN_SHIFT)          /* 0x00000100 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_250M_EN_SHIFT          (9U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_250M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_250M_EN_SHIFT)          /* 0x00000200 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_125M_EN_SHIFT          (10U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_125M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_125M_EN_SHIFT)          /* 0x00000400 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_100M_EN_SHIFT          (11U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_100M_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_100M_EN_SHIFT)          /* 0x00000800 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_62P5_EN_SHIFT          (12U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_62P5_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_62P5_EN_SHIFT)          /* 0x00001000 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_50M_EN_SHIFT           (13U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_50M_EN_MASK            (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_50M_EN_SHIFT)           /* 0x00002000 */
#define CRU_GATE_CON35_CLK_CPLL_DIV_25M_EN_SHIFT           (14U)
#define CRU_GATE_CON35_CLK_CPLL_DIV_25M_EN_MASK            (0x1U << CRU_GATE_CON35_CLK_CPLL_DIV_25M_EN_SHIFT)           /* 0x00004000 */
#define CRU_GATE_CON35_CLK_OSC0_DIV_750K_EN_SHIFT          (15U)
#define CRU_GATE_CON35_CLK_OSC0_DIV_750K_EN_MASK           (0x1U << CRU_GATE_CON35_CLK_OSC0_DIV_750K_EN_SHIFT)          /* 0x00008000 */
/* SOFTRST_CON00 */
#define CRU_SOFTRST_CON00_OFFSET                           (0x400U)
#define CRU_SOFTRST_CON00_NCORERESET0_SHIFT                (0U)
#define CRU_SOFTRST_CON00_NCORERESET0_MASK                 (0x1U << CRU_SOFTRST_CON00_NCORERESET0_SHIFT)                /* 0x00000001 */
#define CRU_SOFTRST_CON00_NCORERESET1_SHIFT                (1U)
#define CRU_SOFTRST_CON00_NCORERESET1_MASK                 (0x1U << CRU_SOFTRST_CON00_NCORERESET1_SHIFT)                /* 0x00000002 */
#define CRU_SOFTRST_CON00_NCORERESET2_SHIFT                (2U)
#define CRU_SOFTRST_CON00_NCORERESET2_MASK                 (0x1U << CRU_SOFTRST_CON00_NCORERESET2_SHIFT)                /* 0x00000004 */
#define CRU_SOFTRST_CON00_NCORERESET3_SHIFT                (3U)
#define CRU_SOFTRST_CON00_NCORERESET3_MASK                 (0x1U << CRU_SOFTRST_CON00_NCORERESET3_SHIFT)                /* 0x00000008 */
#define CRU_SOFTRST_CON00_NCPUPORESET0_SHIFT               (4U)
#define CRU_SOFTRST_CON00_NCPUPORESET0_MASK                (0x1U << CRU_SOFTRST_CON00_NCPUPORESET0_SHIFT)               /* 0x00000010 */
#define CRU_SOFTRST_CON00_NCPUPORESET1_SHIFT               (5U)
#define CRU_SOFTRST_CON00_NCPUPORESET1_MASK                (0x1U << CRU_SOFTRST_CON00_NCPUPORESET1_SHIFT)               /* 0x00000020 */
#define CRU_SOFTRST_CON00_NCPUPORESET2_SHIFT               (6U)
#define CRU_SOFTRST_CON00_NCPUPORESET2_MASK                (0x1U << CRU_SOFTRST_CON00_NCPUPORESET2_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON00_NCPUPORESET3_SHIFT               (7U)
#define CRU_SOFTRST_CON00_NCPUPORESET3_MASK                (0x1U << CRU_SOFTRST_CON00_NCPUPORESET3_SHIFT)               /* 0x00000080 */
#define CRU_SOFTRST_CON00_NSRESET_SHIFT                    (8U)
#define CRU_SOFTRST_CON00_NSRESET_MASK                     (0x1U << CRU_SOFTRST_CON00_NSRESET_SHIFT)                    /* 0x00000100 */
#define CRU_SOFTRST_CON00_NSPORESET_SHIFT                  (9U)
#define CRU_SOFTRST_CON00_NSPORESET_MASK                   (0x1U << CRU_SOFTRST_CON00_NSPORESET_SHIFT)                  /* 0x00000200 */
#define CRU_SOFTRST_CON00_NATRESET_SHIFT                   (10U)
#define CRU_SOFTRST_CON00_NATRESET_MASK                    (0x1U << CRU_SOFTRST_CON00_NATRESET_SHIFT)                   /* 0x00000400 */
#define CRU_SOFTRST_CON00_NGICRESET_SHIFT                  (11U)
#define CRU_SOFTRST_CON00_NGICRESET_MASK                   (0x1U << CRU_SOFTRST_CON00_NGICRESET_SHIFT)                  /* 0x00000800 */
#define CRU_SOFTRST_CON00_NPRESET_SHIFT                    (12U)
#define CRU_SOFTRST_CON00_NPRESET_MASK                     (0x1U << CRU_SOFTRST_CON00_NPRESET_SHIFT)                    /* 0x00001000 */
#define CRU_SOFTRST_CON00_NPERIPHRESET_SHIFT               (13U)
#define CRU_SOFTRST_CON00_NPERIPHRESET_MASK                (0x1U << CRU_SOFTRST_CON00_NPERIPHRESET_SHIFT)               /* 0x00002000 */
/* SOFTRST_CON01 */
#define CRU_SOFTRST_CON01_OFFSET                           (0x404U)
#define CRU_SOFTRST_CON01_ARESETN_CORE_NIU2DDR_SHIFT       (0U)
#define CRU_SOFTRST_CON01_ARESETN_CORE_NIU2DDR_MASK        (0x1U << CRU_SOFTRST_CON01_ARESETN_CORE_NIU2DDR_SHIFT)       /* 0x00000001 */
#define CRU_SOFTRST_CON01_ARESETN_CORE_NIU2BUS_SHIFT       (1U)
#define CRU_SOFTRST_CON01_ARESETN_CORE_NIU2BUS_MASK        (0x1U << CRU_SOFTRST_CON01_ARESETN_CORE_NIU2BUS_SHIFT)       /* 0x00000002 */
#define CRU_SOFTRST_CON01_PRESETN_DBG_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON01_PRESETN_DBG_NIU_MASK             (0x1U << CRU_SOFTRST_CON01_PRESETN_DBG_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON01_PRESETN_DBG_SHIFT                (3U)
#define CRU_SOFTRST_CON01_PRESETN_DBG_MASK                 (0x1U << CRU_SOFTRST_CON01_PRESETN_DBG_SHIFT)                /* 0x00000008 */
#define CRU_SOFTRST_CON01_PRESETN_DBG_DAPLITE_SHIFT        (4U)
#define CRU_SOFTRST_CON01_PRESETN_DBG_DAPLITE_MASK         (0x1U << CRU_SOFTRST_CON01_PRESETN_DBG_DAPLITE_SHIFT)        /* 0x00000010 */
#define CRU_SOFTRST_CON01_RESETN_DAP_SHIFT                 (5U)
#define CRU_SOFTRST_CON01_RESETN_DAP_MASK                  (0x1U << CRU_SOFTRST_CON01_RESETN_DAP_SHIFT)                 /* 0x00000020 */
#define CRU_SOFTRST_CON01_ARESETN_ADB400_CORE2GIC_SHIFT    (6U)
#define CRU_SOFTRST_CON01_ARESETN_ADB400_CORE2GIC_MASK     (0x1U << CRU_SOFTRST_CON01_ARESETN_ADB400_CORE2GIC_SHIFT)    /* 0x00000040 */
#define CRU_SOFTRST_CON01_ARESETN_ADB400_GIC2CORE_SHIFT    (7U)
#define CRU_SOFTRST_CON01_ARESETN_ADB400_GIC2CORE_MASK     (0x1U << CRU_SOFTRST_CON01_ARESETN_ADB400_GIC2CORE_SHIFT)    /* 0x00000080 */
#define CRU_SOFTRST_CON01_PRESETN_CORE_GRF_SHIFT           (8U)
#define CRU_SOFTRST_CON01_PRESETN_CORE_GRF_MASK            (0x1U << CRU_SOFTRST_CON01_PRESETN_CORE_GRF_SHIFT)           /* 0x00000100 */
#define CRU_SOFTRST_CON01_PRESETN_CORE_PVTM_SHIFT          (9U)
#define CRU_SOFTRST_CON01_PRESETN_CORE_PVTM_MASK           (0x1U << CRU_SOFTRST_CON01_PRESETN_CORE_PVTM_SHIFT)          /* 0x00000200 */
#define CRU_SOFTRST_CON01_RESETN_CORE_PVTM_SHIFT           (10U)
#define CRU_SOFTRST_CON01_RESETN_CORE_PVTM_MASK            (0x1U << CRU_SOFTRST_CON01_RESETN_CORE_PVTM_SHIFT)           /* 0x00000400 */
#define CRU_SOFTRST_CON01_RESETN_CORE_PVTPLL_SHIFT         (11U)
#define CRU_SOFTRST_CON01_RESETN_CORE_PVTPLL_MASK          (0x1U << CRU_SOFTRST_CON01_RESETN_CORE_PVTPLL_SHIFT)         /* 0x00000800 */
/* SOFTRST_CON02 */
#define CRU_SOFTRST_CON02_OFFSET                           (0x408U)
#define CRU_SOFTRST_CON02_RESETN_GPU_SHIFT                 (0U)
#define CRU_SOFTRST_CON02_RESETN_GPU_MASK                  (0x1U << CRU_SOFTRST_CON02_RESETN_GPU_SHIFT)                 /* 0x00000001 */
#define CRU_SOFTRST_CON02_ARESETN_GPU_NIU_SHIFT            (1U)
#define CRU_SOFTRST_CON02_ARESETN_GPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON02_ARESETN_GPU_NIU_SHIFT)            /* 0x00000002 */
#define CRU_SOFTRST_CON02_PRESETN_GPU_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON02_PRESETN_GPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON02_PRESETN_GPU_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON02_PRESETN_GPU_PVTM_SHIFT           (3U)
#define CRU_SOFTRST_CON02_PRESETN_GPU_PVTM_MASK            (0x1U << CRU_SOFTRST_CON02_PRESETN_GPU_PVTM_SHIFT)           /* 0x00000008 */
#define CRU_SOFTRST_CON02_RESETN_GPU_PVTM_SHIFT            (4U)
#define CRU_SOFTRST_CON02_RESETN_GPU_PVTM_MASK             (0x1U << CRU_SOFTRST_CON02_RESETN_GPU_PVTM_SHIFT)            /* 0x00000010 */
#define CRU_SOFTRST_CON02_RESETN_GPU_PVTPLL_SHIFT          (5U)
#define CRU_SOFTRST_CON02_RESETN_GPU_PVTPLL_MASK           (0x1U << CRU_SOFTRST_CON02_RESETN_GPU_PVTPLL_SHIFT)          /* 0x00000020 */
#define CRU_SOFTRST_CON02_ARESETN_NPU_NIU_SHIFT            (8U)
#define CRU_SOFTRST_CON02_ARESETN_NPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON02_ARESETN_NPU_NIU_SHIFT)            /* 0x00000100 */
#define CRU_SOFTRST_CON02_HRESETN_NPU_NIU_SHIFT            (9U)
#define CRU_SOFTRST_CON02_HRESETN_NPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON02_HRESETN_NPU_NIU_SHIFT)            /* 0x00000200 */
#define CRU_SOFTRST_CON02_PRESETN_NPU_NIU_SHIFT            (10U)
#define CRU_SOFTRST_CON02_PRESETN_NPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON02_PRESETN_NPU_NIU_SHIFT)            /* 0x00000400 */
#define CRU_SOFTRST_CON02_ARESETN_RKNN_SHIFT               (11U)
#define CRU_SOFTRST_CON02_ARESETN_RKNN_MASK                (0x1U << CRU_SOFTRST_CON02_ARESETN_RKNN_SHIFT)               /* 0x00000800 */
#define CRU_SOFTRST_CON02_HRESETN_RKNN_SHIFT               (12U)
#define CRU_SOFTRST_CON02_HRESETN_RKNN_MASK                (0x1U << CRU_SOFTRST_CON02_HRESETN_RKNN_SHIFT)               /* 0x00001000 */
#define CRU_SOFTRST_CON02_PRESETN_NPU_PVTM_SHIFT           (13U)
#define CRU_SOFTRST_CON02_PRESETN_NPU_PVTM_MASK            (0x1U << CRU_SOFTRST_CON02_PRESETN_NPU_PVTM_SHIFT)           /* 0x00002000 */
#define CRU_SOFTRST_CON02_RESETN_NPU_PVTM_SHIFT            (14U)
#define CRU_SOFTRST_CON02_RESETN_NPU_PVTM_MASK             (0x1U << CRU_SOFTRST_CON02_RESETN_NPU_PVTM_SHIFT)            /* 0x00004000 */
#define CRU_SOFTRST_CON02_RESETN_NPU_PVTPLL_SHIFT          (15U)
#define CRU_SOFTRST_CON02_RESETN_NPU_PVTPLL_MASK           (0x1U << CRU_SOFTRST_CON02_RESETN_NPU_PVTPLL_SHIFT)          /* 0x00008000 */
/* SOFTRST_CON03 */
#define CRU_SOFTRST_CON03_OFFSET                           (0x40CU)
#define CRU_SOFTRST_CON03_ARESETN_MSCH_SHIFT               (3U)
#define CRU_SOFTRST_CON03_ARESETN_MSCH_MASK                (0x1U << CRU_SOFTRST_CON03_ARESETN_MSCH_SHIFT)               /* 0x00000008 */
#define CRU_SOFTRST_CON03_RESETN_HWFFC_CTRL_SHIFT          (4U)
#define CRU_SOFTRST_CON03_RESETN_HWFFC_CTRL_MASK           (0x1U << CRU_SOFTRST_CON03_RESETN_HWFFC_CTRL_SHIFT)          /* 0x00000010 */
#define CRU_SOFTRST_CON03_RESETN_DDR_ALWAYSON_SHIFT        (5U)
#define CRU_SOFTRST_CON03_RESETN_DDR_ALWAYSON_MASK         (0x1U << CRU_SOFTRST_CON03_RESETN_DDR_ALWAYSON_SHIFT)        /* 0x00000020 */
#define CRU_SOFTRST_CON03_ARESETN_DDRSPLIT_SHIFT           (6U)
#define CRU_SOFTRST_CON03_ARESETN_DDRSPLIT_MASK            (0x1U << CRU_SOFTRST_CON03_ARESETN_DDRSPLIT_SHIFT)           /* 0x00000040 */
#define CRU_SOFTRST_CON03_RESETN_DDRDFI_CTL_SHIFT          (7U)
#define CRU_SOFTRST_CON03_RESETN_DDRDFI_CTL_MASK           (0x1U << CRU_SOFTRST_CON03_RESETN_DDRDFI_CTL_SHIFT)          /* 0x00000080 */
#define CRU_SOFTRST_CON03_ARESETN_DMA2DDR_SHIFT            (9U)
#define CRU_SOFTRST_CON03_ARESETN_DMA2DDR_MASK             (0x1U << CRU_SOFTRST_CON03_ARESETN_DMA2DDR_SHIFT)            /* 0x00000200 */
/* SOFTRST_CON04 */
#define CRU_SOFTRST_CON04_OFFSET                           (0x410U)
#define CRU_SOFTRST_CON04_ARESETN_PERIMID_NIU_SHIFT        (0U)
#define CRU_SOFTRST_CON04_ARESETN_PERIMID_NIU_MASK         (0x1U << CRU_SOFTRST_CON04_ARESETN_PERIMID_NIU_SHIFT)        /* 0x00000001 */
#define CRU_SOFTRST_CON04_HRESETN_PERIMID_NIU_SHIFT        (1U)
#define CRU_SOFTRST_CON04_HRESETN_PERIMID_NIU_MASK         (0x1U << CRU_SOFTRST_CON04_HRESETN_PERIMID_NIU_SHIFT)        /* 0x00000002 */
#define CRU_SOFTRST_CON04_ARESETN_GIC_AUDIO_NIU_SHIFT      (2U)
#define CRU_SOFTRST_CON04_ARESETN_GIC_AUDIO_NIU_MASK       (0x1U << CRU_SOFTRST_CON04_ARESETN_GIC_AUDIO_NIU_SHIFT)      /* 0x00000004 */
#define CRU_SOFTRST_CON04_HRESETN_GIC_AUDIO_NIU_SHIFT      (3U)
#define CRU_SOFTRST_CON04_HRESETN_GIC_AUDIO_NIU_MASK       (0x1U << CRU_SOFTRST_CON04_HRESETN_GIC_AUDIO_NIU_SHIFT)      /* 0x00000008 */
#define CRU_SOFTRST_CON04_ARESETN_GIC600_SHIFT             (4U)
#define CRU_SOFTRST_CON04_ARESETN_GIC600_MASK              (0x1U << CRU_SOFTRST_CON04_ARESETN_GIC600_SHIFT)             /* 0x00000010 */
#define CRU_SOFTRST_CON04_ARESETN_GIC600_DEBUG_SHIFT       (5U)
#define CRU_SOFTRST_CON04_ARESETN_GIC600_DEBUG_MASK        (0x1U << CRU_SOFTRST_CON04_ARESETN_GIC600_DEBUG_SHIFT)       /* 0x00000020 */
#define CRU_SOFTRST_CON04_ARESETN_GICADB_CORE2GIC_SHIFT    (6U)
#define CRU_SOFTRST_CON04_ARESETN_GICADB_CORE2GIC_MASK     (0x1U << CRU_SOFTRST_CON04_ARESETN_GICADB_CORE2GIC_SHIFT)    /* 0x00000040 */
#define CRU_SOFTRST_CON04_ARESETN_GICADB_GIC2CORE_SHIFT    (7U)
#define CRU_SOFTRST_CON04_ARESETN_GICADB_GIC2CORE_MASK     (0x1U << CRU_SOFTRST_CON04_ARESETN_GICADB_GIC2CORE_SHIFT)    /* 0x00000080 */
#define CRU_SOFTRST_CON04_ARESETN_SPINLOCK_SHIFT           (8U)
#define CRU_SOFTRST_CON04_ARESETN_SPINLOCK_MASK            (0x1U << CRU_SOFTRST_CON04_ARESETN_SPINLOCK_SHIFT)           /* 0x00000100 */
#define CRU_SOFTRST_CON04_HRESETN_SDMMC_BUFFER_SHIFT       (9U)
#define CRU_SOFTRST_CON04_HRESETN_SDMMC_BUFFER_MASK        (0x1U << CRU_SOFTRST_CON04_HRESETN_SDMMC_BUFFER_SHIFT)       /* 0x00000200 */
#define CRU_SOFTRST_CON04_DRESETN_SDMMC_BUFFER_SHIFT       (10U)
#define CRU_SOFTRST_CON04_DRESETN_SDMMC_BUFFER_MASK        (0x1U << CRU_SOFTRST_CON04_DRESETN_SDMMC_BUFFER_SHIFT)       /* 0x00000400 */
#define CRU_SOFTRST_CON04_HRESETN_I2S0_8CH_SHIFT           (11U)
#define CRU_SOFTRST_CON04_HRESETN_I2S0_8CH_MASK            (0x1U << CRU_SOFTRST_CON04_HRESETN_I2S0_8CH_SHIFT)           /* 0x00000800 */
#define CRU_SOFTRST_CON04_HRESETN_I2S1_8CH_SHIFT           (12U)
#define CRU_SOFTRST_CON04_HRESETN_I2S1_8CH_MASK            (0x1U << CRU_SOFTRST_CON04_HRESETN_I2S1_8CH_SHIFT)           /* 0x00001000 */
#define CRU_SOFTRST_CON04_HRESETN_I2S2_2CH_SHIFT           (13U)
#define CRU_SOFTRST_CON04_HRESETN_I2S2_2CH_MASK            (0x1U << CRU_SOFTRST_CON04_HRESETN_I2S2_2CH_SHIFT)           /* 0x00002000 */
#define CRU_SOFTRST_CON04_HRESETN_I2S3_2CH_SHIFT           (14U)
#define CRU_SOFTRST_CON04_HRESETN_I2S3_2CH_MASK            (0x1U << CRU_SOFTRST_CON04_HRESETN_I2S3_2CH_SHIFT)           /* 0x00004000 */
/* SOFTRST_CON05 */
#define CRU_SOFTRST_CON05_OFFSET                           (0x414U)
#define CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_TX_SHIFT        (0U)
#define CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_TX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_TX_SHIFT)        /* 0x00000001 */
#define CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_RX_SHIFT        (1U)
#define CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_RX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S0_8CH_RX_SHIFT)        /* 0x00000002 */
#define CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_TX_SHIFT        (2U)
#define CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_TX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_TX_SHIFT)        /* 0x00000004 */
#define CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_RX_SHIFT        (3U)
#define CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_RX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S1_8CH_RX_SHIFT)        /* 0x00000008 */
#define CRU_SOFTRST_CON05_MRESETN_I2S2_2CH_SHIFT           (4U)
#define CRU_SOFTRST_CON05_MRESETN_I2S2_2CH_MASK            (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S2_2CH_SHIFT)           /* 0x00000010 */
#define CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_TX_SHIFT        (5U)
#define CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_TX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_TX_SHIFT)        /* 0x00000020 */
#define CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_RX_SHIFT        (6U)
#define CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_RX_MASK         (0x1U << CRU_SOFTRST_CON05_MRESETN_I2S3_2CH_RX_SHIFT)        /* 0x00000040 */
#define CRU_SOFTRST_CON05_HRESETN_PDM_SHIFT                (7U)
#define CRU_SOFTRST_CON05_HRESETN_PDM_MASK                 (0x1U << CRU_SOFTRST_CON05_HRESETN_PDM_SHIFT)                /* 0x00000080 */
#define CRU_SOFTRST_CON05_MRESETN_PDM_SHIFT                (8U)
#define CRU_SOFTRST_CON05_MRESETN_PDM_MASK                 (0x1U << CRU_SOFTRST_CON05_MRESETN_PDM_SHIFT)                /* 0x00000100 */
#define CRU_SOFTRST_CON05_HRESETN_VAD_SHIFT                (9U)
#define CRU_SOFTRST_CON05_HRESETN_VAD_MASK                 (0x1U << CRU_SOFTRST_CON05_HRESETN_VAD_SHIFT)                /* 0x00000200 */
#define CRU_SOFTRST_CON05_HRESETN_SPDIF_8CH_SHIFT          (10U)
#define CRU_SOFTRST_CON05_HRESETN_SPDIF_8CH_MASK           (0x1U << CRU_SOFTRST_CON05_HRESETN_SPDIF_8CH_SHIFT)          /* 0x00000400 */
#define CRU_SOFTRST_CON05_MRESETN_SPDIF_8CH_SHIFT          (11U)
#define CRU_SOFTRST_CON05_MRESETN_SPDIF_8CH_MASK           (0x1U << CRU_SOFTRST_CON05_MRESETN_SPDIF_8CH_SHIFT)          /* 0x00000800 */
#define CRU_SOFTRST_CON05_HRESETN_AUDPWM_SHIFT             (12U)
#define CRU_SOFTRST_CON05_HRESETN_AUDPWM_MASK              (0x1U << CRU_SOFTRST_CON05_HRESETN_AUDPWM_SHIFT)             /* 0x00001000 */
#define CRU_SOFTRST_CON05_SRESETN_AUDPWM_SHIFT             (13U)
#define CRU_SOFTRST_CON05_SRESETN_AUDPWM_MASK              (0x1U << CRU_SOFTRST_CON05_SRESETN_AUDPWM_SHIFT)             /* 0x00002000 */
#define CRU_SOFTRST_CON05_HRESETN_ACDCDIG_SHIFT            (14U)
#define CRU_SOFTRST_CON05_HRESETN_ACDCDIG_MASK             (0x1U << CRU_SOFTRST_CON05_HRESETN_ACDCDIG_SHIFT)            /* 0x00004000 */
#define CRU_SOFTRST_CON05_RESETN_ACDCDIG_SHIFT             (15U)
#define CRU_SOFTRST_CON05_RESETN_ACDCDIG_MASK              (0x1U << CRU_SOFTRST_CON05_RESETN_ACDCDIG_SHIFT)             /* 0x00008000 */
/* SOFTRST_CON06 */
#define CRU_SOFTRST_CON06_OFFSET                           (0x418U)
#define CRU_SOFTRST_CON06_ARESETN_SECURE_FLASH_NIU_SHIFT   (0U)
#define CRU_SOFTRST_CON06_ARESETN_SECURE_FLASH_NIU_MASK    (0x1U << CRU_SOFTRST_CON06_ARESETN_SECURE_FLASH_NIU_SHIFT)   /* 0x00000001 */
#define CRU_SOFTRST_CON06_HRESETN_SECURE_FLASH_NIU_SHIFT   (1U)
#define CRU_SOFTRST_CON06_HRESETN_SECURE_FLASH_NIU_MASK    (0x1U << CRU_SOFTRST_CON06_HRESETN_SECURE_FLASH_NIU_SHIFT)   /* 0x00000002 */
#define CRU_SOFTRST_CON06_ARESETN_CRYPTO_NS_SHIFT          (7U)
#define CRU_SOFTRST_CON06_ARESETN_CRYPTO_NS_MASK           (0x1U << CRU_SOFTRST_CON06_ARESETN_CRYPTO_NS_SHIFT)          /* 0x00000080 */
#define CRU_SOFTRST_CON06_HRESETN_CRYPTO_NS_SHIFT          (8U)
#define CRU_SOFTRST_CON06_HRESETN_CRYPTO_NS_MASK           (0x1U << CRU_SOFTRST_CON06_HRESETN_CRYPTO_NS_SHIFT)          /* 0x00000100 */
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_CORE_SHIFT      (9U)
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_CORE_MASK       (0x1U << CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_CORE_SHIFT)      /* 0x00000200 */
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_PKA_SHIFT       (10U)
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_PKA_MASK        (0x1U << CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_PKA_SHIFT)       /* 0x00000400 */
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_RNG_SHIFT       (11U)
#define CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_RNG_MASK        (0x1U << CRU_SOFTRST_CON06_RESETN_CRYPTO_NS_RNG_SHIFT)       /* 0x00000800 */
#define CRU_SOFTRST_CON06_HRESETN_TRNG_NS_SHIFT            (12U)
#define CRU_SOFTRST_CON06_HRESETN_TRNG_NS_MASK             (0x1U << CRU_SOFTRST_CON06_HRESETN_TRNG_NS_SHIFT)            /* 0x00001000 */
#define CRU_SOFTRST_CON06_RESETN_TRNG_NS_SHIFT             (13U)
#define CRU_SOFTRST_CON06_RESETN_TRNG_NS_MASK              (0x1U << CRU_SOFTRST_CON06_RESETN_TRNG_NS_SHIFT)             /* 0x00002000 */
/* SOFTRST_CON07 */
#define CRU_SOFTRST_CON07_OFFSET                           (0x41CU)
#define CRU_SOFTRST_CON07_HRESETN_NANDC_SHIFT              (0U)
#define CRU_SOFTRST_CON07_HRESETN_NANDC_MASK               (0x1U << CRU_SOFTRST_CON07_HRESETN_NANDC_SHIFT)              /* 0x00000001 */
#define CRU_SOFTRST_CON07_NRESETN_NANDC_SHIFT              (1U)
#define CRU_SOFTRST_CON07_NRESETN_NANDC_MASK               (0x1U << CRU_SOFTRST_CON07_NRESETN_NANDC_SHIFT)              /* 0x00000002 */
#define CRU_SOFTRST_CON07_HRESETN_SFC_SHIFT                (2U)
#define CRU_SOFTRST_CON07_HRESETN_SFC_MASK                 (0x1U << CRU_SOFTRST_CON07_HRESETN_SFC_SHIFT)                /* 0x00000004 */
#define CRU_SOFTRST_CON07_HRESETN_SFC_XIP_SHIFT            (3U)
#define CRU_SOFTRST_CON07_HRESETN_SFC_XIP_MASK             (0x1U << CRU_SOFTRST_CON07_HRESETN_SFC_XIP_SHIFT)            /* 0x00000008 */
#define CRU_SOFTRST_CON07_SRESETN_SFC_SHIFT                (4U)
#define CRU_SOFTRST_CON07_SRESETN_SFC_MASK                 (0x1U << CRU_SOFTRST_CON07_SRESETN_SFC_SHIFT)                /* 0x00000010 */
#define CRU_SOFTRST_CON07_ARESETN_EMMC_SHIFT               (5U)
#define CRU_SOFTRST_CON07_ARESETN_EMMC_MASK                (0x1U << CRU_SOFTRST_CON07_ARESETN_EMMC_SHIFT)               /* 0x00000020 */
#define CRU_SOFTRST_CON07_HRESETN_EMMC_SHIFT               (6U)
#define CRU_SOFTRST_CON07_HRESETN_EMMC_MASK                (0x1U << CRU_SOFTRST_CON07_HRESETN_EMMC_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON07_BRESETN_EMMC_SHIFT               (7U)
#define CRU_SOFTRST_CON07_BRESETN_EMMC_MASK                (0x1U << CRU_SOFTRST_CON07_BRESETN_EMMC_SHIFT)               /* 0x00000080 */
#define CRU_SOFTRST_CON07_CRESETN_EMMC_SHIFT               (8U)
#define CRU_SOFTRST_CON07_CRESETN_EMMC_MASK                (0x1U << CRU_SOFTRST_CON07_CRESETN_EMMC_SHIFT)               /* 0x00000100 */
#define CRU_SOFTRST_CON07_TRESETN_EMMC_SHIFT               (9U)
#define CRU_SOFTRST_CON07_TRESETN_EMMC_MASK                (0x1U << CRU_SOFTRST_CON07_TRESETN_EMMC_SHIFT)               /* 0x00000200 */
/* SOFTRST_CON08 */
#define CRU_SOFTRST_CON08_OFFSET                           (0x420U)
#define CRU_SOFTRST_CON08_ARESETN_PIPE_NIU_SHIFT           (0U)
#define CRU_SOFTRST_CON08_ARESETN_PIPE_NIU_MASK            (0x1U << CRU_SOFTRST_CON08_ARESETN_PIPE_NIU_SHIFT)           /* 0x00000001 */
#define CRU_SOFTRST_CON08_PRESETN_PIPE_NIU_SHIFT           (2U)
#define CRU_SOFTRST_CON08_PRESETN_PIPE_NIU_MASK            (0x1U << CRU_SOFTRST_CON08_PRESETN_PIPE_NIU_SHIFT)           /* 0x00000004 */
#define CRU_SOFTRST_CON08_PRESETN_PIPE_GRF_SHIFT           (5U)
#define CRU_SOFTRST_CON08_PRESETN_PIPE_GRF_MASK            (0x1U << CRU_SOFTRST_CON08_PRESETN_PIPE_GRF_SHIFT)           /* 0x00000020 */
#define CRU_SOFTRST_CON08_ARESETN_SATA0_SHIFT              (6U)
#define CRU_SOFTRST_CON08_ARESETN_SATA0_MASK               (0x1U << CRU_SOFTRST_CON08_ARESETN_SATA0_SHIFT)              /* 0x00000040 */
#define CRU_SOFTRST_CON08_RESETN_SATA0_PIPE_SHIFT          (7U)
#define CRU_SOFTRST_CON08_RESETN_SATA0_PIPE_MASK           (0x1U << CRU_SOFTRST_CON08_RESETN_SATA0_PIPE_SHIFT)          /* 0x00000080 */
#define CRU_SOFTRST_CON08_RESETN_SATA0_PMALIVE_SHIFT       (8U)
#define CRU_SOFTRST_CON08_RESETN_SATA0_PMALIVE_MASK        (0x1U << CRU_SOFTRST_CON08_RESETN_SATA0_PMALIVE_SHIFT)       /* 0x00000100 */
#define CRU_SOFTRST_CON08_RESETN_SATA0_RXOOB_SHIFT         (9U)
#define CRU_SOFTRST_CON08_RESETN_SATA0_RXOOB_MASK          (0x1U << CRU_SOFTRST_CON08_RESETN_SATA0_RXOOB_SHIFT)         /* 0x00000200 */
#define CRU_SOFTRST_CON08_ARESETN_SATA1_SHIFT              (10U)
#define CRU_SOFTRST_CON08_ARESETN_SATA1_MASK               (0x1U << CRU_SOFTRST_CON08_ARESETN_SATA1_SHIFT)              /* 0x00000400 */
#define CRU_SOFTRST_CON08_RESETN_SATA1_PIPE_SHIFT          (11U)
#define CRU_SOFTRST_CON08_RESETN_SATA1_PIPE_MASK           (0x1U << CRU_SOFTRST_CON08_RESETN_SATA1_PIPE_SHIFT)          /* 0x00000800 */
#define CRU_SOFTRST_CON08_RESETN_SATA1_PMALIVE_SHIFT       (12U)
#define CRU_SOFTRST_CON08_RESETN_SATA1_PMALIVE_MASK        (0x1U << CRU_SOFTRST_CON08_RESETN_SATA1_PMALIVE_SHIFT)       /* 0x00001000 */
#define CRU_SOFTRST_CON08_RESETN_SATA1_RXOOB_SHIFT         (13U)
#define CRU_SOFTRST_CON08_RESETN_SATA1_RXOOB_MASK          (0x1U << CRU_SOFTRST_CON08_RESETN_SATA1_RXOOB_SHIFT)         /* 0x00002000 */
/* SOFTRST_CON09 */
#define CRU_SOFTRST_CON09_OFFSET                           (0x424U)
#define CRU_SOFTRST_CON09_ARESETN_SATA2_SHIFT              (0U)
#define CRU_SOFTRST_CON09_ARESETN_SATA2_MASK               (0x1U << CRU_SOFTRST_CON09_ARESETN_SATA2_SHIFT)              /* 0x00000001 */
#define CRU_SOFTRST_CON09_RESETN_SATA2_PIPE_SHIFT          (1U)
#define CRU_SOFTRST_CON09_RESETN_SATA2_PIPE_MASK           (0x1U << CRU_SOFTRST_CON09_RESETN_SATA2_PIPE_SHIFT)          /* 0x00000002 */
#define CRU_SOFTRST_CON09_RESETN_SATA2_PMALIVE_SHIFT       (2U)
#define CRU_SOFTRST_CON09_RESETN_SATA2_PMALIVE_MASK        (0x1U << CRU_SOFTRST_CON09_RESETN_SATA2_PMALIVE_SHIFT)       /* 0x00000004 */
#define CRU_SOFTRST_CON09_RESETN_SATA2_RXOOB_SHIFT         (3U)
#define CRU_SOFTRST_CON09_RESETN_SATA2_RXOOB_MASK          (0x1U << CRU_SOFTRST_CON09_RESETN_SATA2_RXOOB_SHIFT)         /* 0x00000008 */
#define CRU_SOFTRST_CON09_RESETN_USB3OTG0_SHIFT            (4U)
#define CRU_SOFTRST_CON09_RESETN_USB3OTG0_MASK             (0x1U << CRU_SOFTRST_CON09_RESETN_USB3OTG0_SHIFT)            /* 0x00000010 */
#define CRU_SOFTRST_CON09_RESETN_USB3OTG1_SHIFT            (5U)
#define CRU_SOFTRST_CON09_RESETN_USB3OTG1_MASK             (0x1U << CRU_SOFTRST_CON09_RESETN_USB3OTG1_SHIFT)            /* 0x00000020 */
#define CRU_SOFTRST_CON09_RESETN_XPCS_SHIFT                (6U)
#define CRU_SOFTRST_CON09_RESETN_XPCS_MASK                 (0x1U << CRU_SOFTRST_CON09_RESETN_XPCS_SHIFT)                /* 0x00000040 */
#define CRU_SOFTRST_CON09_RESETN_XPCS_TX_DIV10_SHIFT       (7U)
#define CRU_SOFTRST_CON09_RESETN_XPCS_TX_DIV10_MASK        (0x1U << CRU_SOFTRST_CON09_RESETN_XPCS_TX_DIV10_SHIFT)       /* 0x00000080 */
#define CRU_SOFTRST_CON09_RESETN_XPCS_RX_DIV10_SHIFT       (8U)
#define CRU_SOFTRST_CON09_RESETN_XPCS_RX_DIV10_MASK        (0x1U << CRU_SOFTRST_CON09_RESETN_XPCS_RX_DIV10_SHIFT)       /* 0x00000100 */
#define CRU_SOFTRST_CON09_RESETN_XPCS_XGXS_RX_SHIFT        (9U)
#define CRU_SOFTRST_CON09_RESETN_XPCS_XGXS_RX_MASK         (0x1U << CRU_SOFTRST_CON09_RESETN_XPCS_XGXS_RX_SHIFT)        /* 0x00000200 */
/* SOFTRST_CON10 */
#define CRU_SOFTRST_CON10_OFFSET                           (0x428U)
#define CRU_SOFTRST_CON10_PRESETN_PCIE20_SHIFT             (0U)
#define CRU_SOFTRST_CON10_PRESETN_PCIE20_MASK              (0x1U << CRU_SOFTRST_CON10_PRESETN_PCIE20_SHIFT)             /* 0x00000001 */
#define CRU_SOFTRST_CON10_RESETN_PCIE20_POWERUP_REQ_SHIFT  (1U)
#define CRU_SOFTRST_CON10_RESETN_PCIE20_POWERUP_REQ_MASK   (0x1U << CRU_SOFTRST_CON10_RESETN_PCIE20_POWERUP_REQ_SHIFT)  /* 0x00000002 */
#define CRU_SOFTRST_CON10_MSTR_ARESET_PCIE20_REQ_SHIFT     (2U)
#define CRU_SOFTRST_CON10_MSTR_ARESET_PCIE20_REQ_MASK      (0x1U << CRU_SOFTRST_CON10_MSTR_ARESET_PCIE20_REQ_SHIFT)     /* 0x00000004 */
#define CRU_SOFTRST_CON10_SLV_ARESET_PCIE20_REQ_SHIFT      (3U)
#define CRU_SOFTRST_CON10_SLV_ARESET_PCIE20_REQ_MASK       (0x1U << CRU_SOFTRST_CON10_SLV_ARESET_PCIE20_REQ_SHIFT)      /* 0x00000008 */
#define CRU_SOFTRST_CON10_DBI_ARESET_PCIE20_REQ_SHIFT      (4U)
#define CRU_SOFTRST_CON10_DBI_ARESET_PCIE20_REQ_MASK       (0x1U << CRU_SOFTRST_CON10_DBI_ARESET_PCIE20_REQ_SHIFT)      /* 0x00000010 */
#define CRU_SOFTRST_CON10_BRESET_PCIE20_REQ_SHIFT          (5U)
#define CRU_SOFTRST_CON10_BRESET_PCIE20_REQ_MASK           (0x1U << CRU_SOFTRST_CON10_BRESET_PCIE20_REQ_SHIFT)          /* 0x00000020 */
#define CRU_SOFTRST_CON10_PERST_PCIE20_REQ_SHIFT           (6U)
#define CRU_SOFTRST_CON10_PERST_PCIE20_REQ_MASK            (0x1U << CRU_SOFTRST_CON10_PERST_PCIE20_REQ_SHIFT)           /* 0x00000040 */
#define CRU_SOFTRST_CON10_CORE_RST_PCIE20_REQ_SHIFT        (7U)
#define CRU_SOFTRST_CON10_CORE_RST_PCIE20_REQ_MASK         (0x1U << CRU_SOFTRST_CON10_CORE_RST_PCIE20_REQ_SHIFT)        /* 0x00000080 */
#define CRU_SOFTRST_CON10_NSTICKY_RST_PCIE20_REQ_SHIFT     (8U)
#define CRU_SOFTRST_CON10_NSTICKY_RST_PCIE20_REQ_MASK      (0x1U << CRU_SOFTRST_CON10_NSTICKY_RST_PCIE20_REQ_SHIFT)     /* 0x00000100 */
#define CRU_SOFTRST_CON10_STICKY_RST_PCIE20_REQ_SHIFT      (9U)
#define CRU_SOFTRST_CON10_STICKY_RST_PCIE20_REQ_MASK       (0x1U << CRU_SOFTRST_CON10_STICKY_RST_PCIE20_REQ_SHIFT)      /* 0x00000200 */
#define CRU_SOFTRST_CON10_PWR_RST_PCIE20_REQ_SHIFT         (10U)
#define CRU_SOFTRST_CON10_PWR_RST_PCIE20_REQ_MASK          (0x1U << CRU_SOFTRST_CON10_PWR_RST_PCIE20_REQ_SHIFT)         /* 0x00000400 */
/* SOFTRST_CON12 */
#define CRU_SOFTRST_CON12_OFFSET                           (0x430U)
#define CRU_SOFTRST_CON12_PRESETN_PCIE30X2_SHIFT           (0U)
#define CRU_SOFTRST_CON12_PRESETN_PCIE30X2_MASK            (0x1U << CRU_SOFTRST_CON12_PRESETN_PCIE30X2_SHIFT)           /* 0x00000001 */
#define CRU_SOFTRST_CON12_RESETN_PCIE30X2_POWERUP_REQ_SHIFT (1U)
#define CRU_SOFTRST_CON12_RESETN_PCIE30X2_POWERUP_REQ_MASK (0x1U << CRU_SOFTRST_CON12_RESETN_PCIE30X2_POWERUP_REQ_SHIFT) /* 0x00000002 */
#define CRU_SOFTRST_CON12_MSTR_ARESET_PCIE30X2_REQ_SHIFT   (2U)
#define CRU_SOFTRST_CON12_MSTR_ARESET_PCIE30X2_REQ_MASK    (0x1U << CRU_SOFTRST_CON12_MSTR_ARESET_PCIE30X2_REQ_SHIFT)   /* 0x00000004 */
#define CRU_SOFTRST_CON12_SLV_ARESET_PCIE30X2_REQ_SHIFT    (3U)
#define CRU_SOFTRST_CON12_SLV_ARESET_PCIE30X2_REQ_MASK     (0x1U << CRU_SOFTRST_CON12_SLV_ARESET_PCIE30X2_REQ_SHIFT)    /* 0x00000008 */
#define CRU_SOFTRST_CON12_DBI_ARESET_PCIE30X2_REQ_SHIFT    (4U)
#define CRU_SOFTRST_CON12_DBI_ARESET_PCIE30X2_REQ_MASK     (0x1U << CRU_SOFTRST_CON12_DBI_ARESET_PCIE30X2_REQ_SHIFT)    /* 0x00000010 */
#define CRU_SOFTRST_CON12_BRESET_PCIE30X2_REQ_SHIFT        (5U)
#define CRU_SOFTRST_CON12_BRESET_PCIE30X2_REQ_MASK         (0x1U << CRU_SOFTRST_CON12_BRESET_PCIE30X2_REQ_SHIFT)        /* 0x00000020 */
#define CRU_SOFTRST_CON12_PERST_PCIE30X2_REQ_SHIFT         (6U)
#define CRU_SOFTRST_CON12_PERST_PCIE30X2_REQ_MASK          (0x1U << CRU_SOFTRST_CON12_PERST_PCIE30X2_REQ_SHIFT)         /* 0x00000040 */
#define CRU_SOFTRST_CON12_CORE_RST_PCIE30X2_REQ_SHIFT      (7U)
#define CRU_SOFTRST_CON12_CORE_RST_PCIE30X2_REQ_MASK       (0x1U << CRU_SOFTRST_CON12_CORE_RST_PCIE30X2_REQ_SHIFT)      /* 0x00000080 */
#define CRU_SOFTRST_CON12_NSTICKY_RST_PCIE30X2_REQ_SHIFT   (8U)
#define CRU_SOFTRST_CON12_NSTICKY_RST_PCIE30X2_REQ_MASK    (0x1U << CRU_SOFTRST_CON12_NSTICKY_RST_PCIE30X2_REQ_SHIFT)   /* 0x00000100 */
#define CRU_SOFTRST_CON12_STICKY_RST_PCIE30X2_REQ_SHIFT    (9U)
#define CRU_SOFTRST_CON12_STICKY_RST_PCIE30X2_REQ_MASK     (0x1U << CRU_SOFTRST_CON12_STICKY_RST_PCIE30X2_REQ_SHIFT)    /* 0x00000200 */
#define CRU_SOFTRST_CON12_PWR_RST_PCIE30X2_REQ_SHIFT       (10U)
#define CRU_SOFTRST_CON12_PWR_RST_PCIE30X2_REQ_MASK        (0x1U << CRU_SOFTRST_CON12_PWR_RST_PCIE30X2_REQ_SHIFT)       /* 0x00000400 */
/* SOFTRST_CON13 */
#define CRU_SOFTRST_CON13_OFFSET                           (0x434U)
#define CRU_SOFTRST_CON13_ARESETN_PHP_NIU_SHIFT            (0U)
#define CRU_SOFTRST_CON13_ARESETN_PHP_NIU_MASK             (0x1U << CRU_SOFTRST_CON13_ARESETN_PHP_NIU_SHIFT)            /* 0x00000001 */
#define CRU_SOFTRST_CON13_HRESETN_PHP_NIU_SHIFT            (1U)
#define CRU_SOFTRST_CON13_HRESETN_PHP_NIU_MASK             (0x1U << CRU_SOFTRST_CON13_HRESETN_PHP_NIU_SHIFT)            /* 0x00000002 */
#define CRU_SOFTRST_CON13_PRESETN_PHP_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON13_PRESETN_PHP_NIU_MASK             (0x1U << CRU_SOFTRST_CON13_PRESETN_PHP_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON13_HRESETN_SDMMC0_SHIFT             (3U)
#define CRU_SOFTRST_CON13_HRESETN_SDMMC0_MASK              (0x1U << CRU_SOFTRST_CON13_HRESETN_SDMMC0_SHIFT)             /* 0x00000008 */
#define CRU_SOFTRST_CON13_RESETN_SDMMC0_SHIFT              (4U)
#define CRU_SOFTRST_CON13_RESETN_SDMMC0_MASK               (0x1U << CRU_SOFTRST_CON13_RESETN_SDMMC0_SHIFT)              /* 0x00000010 */
#define CRU_SOFTRST_CON13_HRESETN_SDMMC1_SHIFT             (5U)
#define CRU_SOFTRST_CON13_HRESETN_SDMMC1_MASK              (0x1U << CRU_SOFTRST_CON13_HRESETN_SDMMC1_SHIFT)             /* 0x00000020 */
#define CRU_SOFTRST_CON13_RESETN_SDMMC1_SHIFT              (6U)
#define CRU_SOFTRST_CON13_RESETN_SDMMC1_MASK               (0x1U << CRU_SOFTRST_CON13_RESETN_SDMMC1_SHIFT)              /* 0x00000040 */
#define CRU_SOFTRST_CON13_ARESETN_GMAC0_SHIFT              (7U)
#define CRU_SOFTRST_CON13_ARESETN_GMAC0_MASK               (0x1U << CRU_SOFTRST_CON13_ARESETN_GMAC0_SHIFT)              /* 0x00000080 */
#define CRU_SOFTRST_CON13_RESETN_GMAC0_TIMESTAMP_SHIFT     (8U)
#define CRU_SOFTRST_CON13_RESETN_GMAC0_TIMESTAMP_MASK      (0x1U << CRU_SOFTRST_CON13_RESETN_GMAC0_TIMESTAMP_SHIFT)     /* 0x00000100 */
/* SOFTRST_CON14 */
#define CRU_SOFTRST_CON14_OFFSET                           (0x438U)
#define CRU_SOFTRST_CON14_ARESETN_USB_NIU_SHIFT            (0U)
#define CRU_SOFTRST_CON14_ARESETN_USB_NIU_MASK             (0x1U << CRU_SOFTRST_CON14_ARESETN_USB_NIU_SHIFT)            /* 0x00000001 */
#define CRU_SOFTRST_CON14_HRESETN_USB_NIU_SHIFT            (1U)
#define CRU_SOFTRST_CON14_HRESETN_USB_NIU_MASK             (0x1U << CRU_SOFTRST_CON14_HRESETN_USB_NIU_SHIFT)            /* 0x00000002 */
#define CRU_SOFTRST_CON14_PRESETN_USB_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON14_PRESETN_USB_NIU_MASK             (0x1U << CRU_SOFTRST_CON14_PRESETN_USB_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON14_PRESETN_USB_GRF_SHIFT            (3U)
#define CRU_SOFTRST_CON14_PRESETN_USB_GRF_MASK             (0x1U << CRU_SOFTRST_CON14_PRESETN_USB_GRF_SHIFT)            /* 0x00000008 */
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST0_SHIFT          (4U)
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST0_MASK           (0x1U << CRU_SOFTRST_CON14_HRESETN_USB2HOST0_SHIFT)          /* 0x00000010 */
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST0_ARB_SHIFT      (5U)
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST0_ARB_MASK       (0x1U << CRU_SOFTRST_CON14_HRESETN_USB2HOST0_ARB_SHIFT)      /* 0x00000020 */
#define CRU_SOFTRST_CON14_RESETN_USB2HOST0_UTMI_SHIFT      (6U)
#define CRU_SOFTRST_CON14_RESETN_USB2HOST0_UTMI_MASK       (0x1U << CRU_SOFTRST_CON14_RESETN_USB2HOST0_UTMI_SHIFT)      /* 0x00000040 */
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST1_SHIFT          (7U)
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST1_MASK           (0x1U << CRU_SOFTRST_CON14_HRESETN_USB2HOST1_SHIFT)          /* 0x00000080 */
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST1_ARB_SHIFT      (8U)
#define CRU_SOFTRST_CON14_HRESETN_USB2HOST1_ARB_MASK       (0x1U << CRU_SOFTRST_CON14_HRESETN_USB2HOST1_ARB_SHIFT)      /* 0x00000100 */
#define CRU_SOFTRST_CON14_RESETN_USB2HOST1_UTMI_SHIFT      (9U)
#define CRU_SOFTRST_CON14_RESETN_USB2HOST1_UTMI_MASK       (0x1U << CRU_SOFTRST_CON14_RESETN_USB2HOST1_UTMI_SHIFT)      /* 0x00000200 */
#define CRU_SOFTRST_CON14_HRESETN_SDMMC2_SHIFT             (10U)
#define CRU_SOFTRST_CON14_HRESETN_SDMMC2_MASK              (0x1U << CRU_SOFTRST_CON14_HRESETN_SDMMC2_SHIFT)             /* 0x00000400 */
#define CRU_SOFTRST_CON14_RESETN_SDMMC2_SHIFT              (11U)
#define CRU_SOFTRST_CON14_RESETN_SDMMC2_MASK               (0x1U << CRU_SOFTRST_CON14_RESETN_SDMMC2_SHIFT)              /* 0x00000800 */
#define CRU_SOFTRST_CON14_ARESETN_GMAC1_SHIFT              (12U)
#define CRU_SOFTRST_CON14_ARESETN_GMAC1_MASK               (0x1U << CRU_SOFTRST_CON14_ARESETN_GMAC1_SHIFT)              /* 0x00001000 */
#define CRU_SOFTRST_CON14_RESETN_GMAC1_TIMESTAMP_SHIFT     (13U)
#define CRU_SOFTRST_CON14_RESETN_GMAC1_TIMESTAMP_MASK      (0x1U << CRU_SOFTRST_CON14_RESETN_GMAC1_TIMESTAMP_SHIFT)     /* 0x00002000 */
/* SOFTRST_CON15 */
#define CRU_SOFTRST_CON15_OFFSET                           (0x43CU)
#define CRU_SOFTRST_CON15_ARESETN_VI_NIU_SHIFT             (0U)
#define CRU_SOFTRST_CON15_ARESETN_VI_NIU_MASK              (0x1U << CRU_SOFTRST_CON15_ARESETN_VI_NIU_SHIFT)             /* 0x00000001 */
#define CRU_SOFTRST_CON15_HRESETN_VI_NIU_SHIFT             (1U)
#define CRU_SOFTRST_CON15_HRESETN_VI_NIU_MASK              (0x1U << CRU_SOFTRST_CON15_HRESETN_VI_NIU_SHIFT)             /* 0x00000002 */
#define CRU_SOFTRST_CON15_PRESETN_VI_NIU_SHIFT             (2U)
#define CRU_SOFTRST_CON15_PRESETN_VI_NIU_MASK              (0x1U << CRU_SOFTRST_CON15_PRESETN_VI_NIU_SHIFT)             /* 0x00000004 */
#define CRU_SOFTRST_CON15_ARESETN_VICAP1_SHIFT             (7U)
#define CRU_SOFTRST_CON15_ARESETN_VICAP1_MASK              (0x1U << CRU_SOFTRST_CON15_ARESETN_VICAP1_SHIFT)             /* 0x00000080 */
#define CRU_SOFTRST_CON15_HRESETN_VICAP1_SHIFT             (8U)
#define CRU_SOFTRST_CON15_HRESETN_VICAP1_MASK              (0x1U << CRU_SOFTRST_CON15_HRESETN_VICAP1_SHIFT)             /* 0x00000100 */
#define CRU_SOFTRST_CON15_DRESETN_VICAP1_SHIFT             (9U)
#define CRU_SOFTRST_CON15_DRESETN_VICAP1_MASK              (0x1U << CRU_SOFTRST_CON15_DRESETN_VICAP1_SHIFT)             /* 0x00000200 */
#define CRU_SOFTRST_CON15_IRESETN_VICAP1_SHIFT             (10U)
#define CRU_SOFTRST_CON15_IRESETN_VICAP1_MASK              (0x1U << CRU_SOFTRST_CON15_IRESETN_VICAP1_SHIFT)             /* 0x00000400 */
#define CRU_SOFTRST_CON15_PRESETN_VICAP1_SHIFT             (11U)
#define CRU_SOFTRST_CON15_PRESETN_VICAP1_MASK              (0x1U << CRU_SOFTRST_CON15_PRESETN_VICAP1_SHIFT)             /* 0x00000800 */
#define CRU_SOFTRST_CON15_HRESETN_ISP_SHIFT                (12U)
#define CRU_SOFTRST_CON15_HRESETN_ISP_MASK                 (0x1U << CRU_SOFTRST_CON15_HRESETN_ISP_SHIFT)                /* 0x00001000 */
#define CRU_SOFTRST_CON15_RESETN_ISP_SHIFT                 (13U)
#define CRU_SOFTRST_CON15_RESETN_ISP_MASK                  (0x1U << CRU_SOFTRST_CON15_RESETN_ISP_SHIFT)                 /* 0x00002000 */
#define CRU_SOFTRST_CON15_PRESETN_CSI2HOST1_SHIFT          (15U)
#define CRU_SOFTRST_CON15_PRESETN_CSI2HOST1_MASK           (0x1U << CRU_SOFTRST_CON15_PRESETN_CSI2HOST1_SHIFT)          /* 0x00008000 */
/* SOFTRST_CON16 */
#define CRU_SOFTRST_CON16_OFFSET                           (0x440U)
#define CRU_SOFTRST_CON16_ARESETN_VO_NIU_SHIFT             (0U)
#define CRU_SOFTRST_CON16_ARESETN_VO_NIU_MASK              (0x1U << CRU_SOFTRST_CON16_ARESETN_VO_NIU_SHIFT)             /* 0x00000001 */
#define CRU_SOFTRST_CON16_HRESETN_VO_NIU_SHIFT             (1U)
#define CRU_SOFTRST_CON16_HRESETN_VO_NIU_MASK              (0x1U << CRU_SOFTRST_CON16_HRESETN_VO_NIU_SHIFT)             /* 0x00000002 */
#define CRU_SOFTRST_CON16_PRESETN_VO_NIU_SHIFT             (2U)
#define CRU_SOFTRST_CON16_PRESETN_VO_NIU_MASK              (0x1U << CRU_SOFTRST_CON16_PRESETN_VO_NIU_SHIFT)             /* 0x00000004 */
#define CRU_SOFTRST_CON16_ARESETN_VOP_NIU_SHIFT            (3U)
#define CRU_SOFTRST_CON16_ARESETN_VOP_NIU_MASK             (0x1U << CRU_SOFTRST_CON16_ARESETN_VOP_NIU_SHIFT)            /* 0x00000008 */
#define CRU_SOFTRST_CON16_ARESETN_VOP_SHIFT                (4U)
#define CRU_SOFTRST_CON16_ARESETN_VOP_MASK                 (0x1U << CRU_SOFTRST_CON16_ARESETN_VOP_SHIFT)                /* 0x00000010 */
#define CRU_SOFTRST_CON16_HRESETN_VOP_SHIFT                (5U)
#define CRU_SOFTRST_CON16_HRESETN_VOP_MASK                 (0x1U << CRU_SOFTRST_CON16_HRESETN_VOP_SHIFT)                /* 0x00000020 */
#define CRU_SOFTRST_CON16_DRESETN0_VOP_SHIFT               (6U)
#define CRU_SOFTRST_CON16_DRESETN0_VOP_MASK                (0x1U << CRU_SOFTRST_CON16_DRESETN0_VOP_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON16_DRESETN1_VOP_SHIFT               (7U)
#define CRU_SOFTRST_CON16_DRESETN1_VOP_MASK                (0x1U << CRU_SOFTRST_CON16_DRESETN1_VOP_SHIFT)               /* 0x00000080 */
#define CRU_SOFTRST_CON16_DRESETN2_VOP_SHIFT               (8U)
#define CRU_SOFTRST_CON16_DRESETN2_VOP_MASK                (0x1U << CRU_SOFTRST_CON16_DRESETN2_VOP_SHIFT)               /* 0x00000100 */
#define CRU_SOFTRST_CON16_RESETN_VOP_PWM_SHIFT             (9U)
#define CRU_SOFTRST_CON16_RESETN_VOP_PWM_MASK              (0x1U << CRU_SOFTRST_CON16_RESETN_VOP_PWM_SHIFT)             /* 0x00000200 */
#define CRU_SOFTRST_CON16_ARESETN_HDCP_SHIFT               (10U)
#define CRU_SOFTRST_CON16_ARESETN_HDCP_MASK                (0x1U << CRU_SOFTRST_CON16_ARESETN_HDCP_SHIFT)               /* 0x00000400 */
#define CRU_SOFTRST_CON16_HRESETN_HDCP_SHIFT               (11U)
#define CRU_SOFTRST_CON16_HRESETN_HDCP_MASK                (0x1U << CRU_SOFTRST_CON16_HRESETN_HDCP_SHIFT)               /* 0x00000800 */
#define CRU_SOFTRST_CON16_PRESETN_HDCP_SHIFT               (12U)
#define CRU_SOFTRST_CON16_PRESETN_HDCP_MASK                (0x1U << CRU_SOFTRST_CON16_PRESETN_HDCP_SHIFT)               /* 0x00001000 */
#define CRU_SOFTRST_CON16_PRESETN_HDMI_HOST_SHIFT          (14U)
#define CRU_SOFTRST_CON16_PRESETN_HDMI_HOST_MASK           (0x1U << CRU_SOFTRST_CON16_PRESETN_HDMI_HOST_SHIFT)          /* 0x00004000 */
#define CRU_SOFTRST_CON16_RESETN_HDMI_HOST_SHIFT           (15U)
#define CRU_SOFTRST_CON16_RESETN_HDMI_HOST_MASK            (0x1U << CRU_SOFTRST_CON16_RESETN_HDMI_HOST_SHIFT)           /* 0x00008000 */
/* SOFTRST_CON17 */
#define CRU_SOFTRST_CON17_OFFSET                           (0x444U)
#define CRU_SOFTRST_CON17_PRESETN_DSITX_0_SHIFT            (0U)
#define CRU_SOFTRST_CON17_PRESETN_DSITX_0_MASK             (0x1U << CRU_SOFTRST_CON17_PRESETN_DSITX_0_SHIFT)            /* 0x00000001 */
#define CRU_SOFTRST_CON17_PRESETN_DSITX_1_SHIFT            (1U)
#define CRU_SOFTRST_CON17_PRESETN_DSITX_1_MASK             (0x1U << CRU_SOFTRST_CON17_PRESETN_DSITX_1_SHIFT)            /* 0x00000002 */
#define CRU_SOFTRST_CON17_PRESETN_EDP_CTRL_SHIFT           (2U)
#define CRU_SOFTRST_CON17_PRESETN_EDP_CTRL_MASK            (0x1U << CRU_SOFTRST_CON17_PRESETN_EDP_CTRL_SHIFT)           /* 0x00000004 */
#define CRU_SOFTRST_CON17_RESETN_EDP_24M_SHIFT             (3U)
#define CRU_SOFTRST_CON17_RESETN_EDP_24M_MASK              (0x1U << CRU_SOFTRST_CON17_RESETN_EDP_24M_SHIFT)             /* 0x00000008 */
#define CRU_SOFTRST_CON17_ARESETN_VPU_NIU_SHIFT            (8U)
#define CRU_SOFTRST_CON17_ARESETN_VPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON17_ARESETN_VPU_NIU_SHIFT)            /* 0x00000100 */
#define CRU_SOFTRST_CON17_HRESETN_VPU_NIU_SHIFT            (9U)
#define CRU_SOFTRST_CON17_HRESETN_VPU_NIU_MASK             (0x1U << CRU_SOFTRST_CON17_HRESETN_VPU_NIU_SHIFT)            /* 0x00000200 */
#define CRU_SOFTRST_CON17_ARESETN_VPU_SHIFT                (10U)
#define CRU_SOFTRST_CON17_ARESETN_VPU_MASK                 (0x1U << CRU_SOFTRST_CON17_ARESETN_VPU_SHIFT)                /* 0x00000400 */
#define CRU_SOFTRST_CON17_HRESETN_VPU_SHIFT                (11U)
#define CRU_SOFTRST_CON17_HRESETN_VPU_MASK                 (0x1U << CRU_SOFTRST_CON17_HRESETN_VPU_SHIFT)                /* 0x00000800 */
#define CRU_SOFTRST_CON17_HRESETN_EINK_SHIFT               (14U)
#define CRU_SOFTRST_CON17_HRESETN_EINK_MASK                (0x1U << CRU_SOFTRST_CON17_HRESETN_EINK_SHIFT)               /* 0x00004000 */
#define CRU_SOFTRST_CON17_PRESETN_EINK_SHIFT               (15U)
#define CRU_SOFTRST_CON17_PRESETN_EINK_MASK                (0x1U << CRU_SOFTRST_CON17_PRESETN_EINK_SHIFT)               /* 0x00008000 */
/* SOFTRST_CON18 */
#define CRU_SOFTRST_CON18_OFFSET                           (0x448U)
#define CRU_SOFTRST_CON18_ARESETN_RGA_NIU_SHIFT            (0U)
#define CRU_SOFTRST_CON18_ARESETN_RGA_NIU_MASK             (0x1U << CRU_SOFTRST_CON18_ARESETN_RGA_NIU_SHIFT)            /* 0x00000001 */
#define CRU_SOFTRST_CON18_HRESETN_RGA_NIU_SHIFT            (1U)
#define CRU_SOFTRST_CON18_HRESETN_RGA_NIU_MASK             (0x1U << CRU_SOFTRST_CON18_HRESETN_RGA_NIU_SHIFT)            /* 0x00000002 */
#define CRU_SOFTRST_CON18_PRESETN_RGA_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON18_PRESETN_RGA_NIU_MASK             (0x1U << CRU_SOFTRST_CON18_PRESETN_RGA_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON18_ARESETN_RGA_SHIFT                (4U)
#define CRU_SOFTRST_CON18_ARESETN_RGA_MASK                 (0x1U << CRU_SOFTRST_CON18_ARESETN_RGA_SHIFT)                /* 0x00000010 */
#define CRU_SOFTRST_CON18_HRESETN_RGA_SHIFT                (5U)
#define CRU_SOFTRST_CON18_HRESETN_RGA_MASK                 (0x1U << CRU_SOFTRST_CON18_HRESETN_RGA_SHIFT)                /* 0x00000020 */
#define CRU_SOFTRST_CON18_RESETN_RGA_CORE_SHIFT            (6U)
#define CRU_SOFTRST_CON18_RESETN_RGA_CORE_MASK             (0x1U << CRU_SOFTRST_CON18_RESETN_RGA_CORE_SHIFT)            /* 0x00000040 */
#define CRU_SOFTRST_CON18_ARESETN_IEP_SHIFT                (7U)
#define CRU_SOFTRST_CON18_ARESETN_IEP_MASK                 (0x1U << CRU_SOFTRST_CON18_ARESETN_IEP_SHIFT)                /* 0x00000080 */
#define CRU_SOFTRST_CON18_HRESETN_IEP_SHIFT                (8U)
#define CRU_SOFTRST_CON18_HRESETN_IEP_MASK                 (0x1U << CRU_SOFTRST_CON18_HRESETN_IEP_SHIFT)                /* 0x00000100 */
#define CRU_SOFTRST_CON18_RESETN_IEP_CORE_SHIFT            (9U)
#define CRU_SOFTRST_CON18_RESETN_IEP_CORE_MASK             (0x1U << CRU_SOFTRST_CON18_RESETN_IEP_CORE_SHIFT)            /* 0x00000200 */
#define CRU_SOFTRST_CON18_HRESETN_EBC_SHIFT                (10U)
#define CRU_SOFTRST_CON18_HRESETN_EBC_MASK                 (0x1U << CRU_SOFTRST_CON18_HRESETN_EBC_SHIFT)                /* 0x00000400 */
#define CRU_SOFTRST_CON18_DRESETN_EBC_SHIFT                (11U)
#define CRU_SOFTRST_CON18_DRESETN_EBC_MASK                 (0x1U << CRU_SOFTRST_CON18_DRESETN_EBC_SHIFT)                /* 0x00000800 */
#define CRU_SOFTRST_CON18_ARESETN_JDEC_SHIFT               (12U)
#define CRU_SOFTRST_CON18_ARESETN_JDEC_MASK                (0x1U << CRU_SOFTRST_CON18_ARESETN_JDEC_SHIFT)               /* 0x00001000 */
#define CRU_SOFTRST_CON18_HRESETN_JDEC_SHIFT               (13U)
#define CRU_SOFTRST_CON18_HRESETN_JDEC_MASK                (0x1U << CRU_SOFTRST_CON18_HRESETN_JDEC_SHIFT)               /* 0x00002000 */
#define CRU_SOFTRST_CON18_ARESETN_JENC_SHIFT               (14U)
#define CRU_SOFTRST_CON18_ARESETN_JENC_MASK                (0x1U << CRU_SOFTRST_CON18_ARESETN_JENC_SHIFT)               /* 0x00004000 */
#define CRU_SOFTRST_CON18_HRESETN_JENC_SHIFT               (15U)
#define CRU_SOFTRST_CON18_HRESETN_JENC_MASK                (0x1U << CRU_SOFTRST_CON18_HRESETN_JENC_SHIFT)               /* 0x00008000 */
/* SOFTRST_CON19 */
#define CRU_SOFTRST_CON19_OFFSET                           (0x44CU)
#define CRU_SOFTRST_CON19_ARESETN_VENC_NIU_SHIFT           (0U)
#define CRU_SOFTRST_CON19_ARESETN_VENC_NIU_MASK            (0x1U << CRU_SOFTRST_CON19_ARESETN_VENC_NIU_SHIFT)           /* 0x00000001 */
#define CRU_SOFTRST_CON19_HRESETN_VENC_NIU_SHIFT           (1U)
#define CRU_SOFTRST_CON19_HRESETN_VENC_NIU_MASK            (0x1U << CRU_SOFTRST_CON19_HRESETN_VENC_NIU_SHIFT)           /* 0x00000002 */
#define CRU_SOFTRST_CON19_ARESETN_RKVENC_SHIFT             (3U)
#define CRU_SOFTRST_CON19_ARESETN_RKVENC_MASK              (0x1U << CRU_SOFTRST_CON19_ARESETN_RKVENC_SHIFT)             /* 0x00000008 */
#define CRU_SOFTRST_CON19_HRESETN_RKVENC_SHIFT             (4U)
#define CRU_SOFTRST_CON19_HRESETN_RKVENC_MASK              (0x1U << CRU_SOFTRST_CON19_HRESETN_RKVENC_SHIFT)             /* 0x00000010 */
#define CRU_SOFTRST_CON19_RESETN_RKVENC_CORE_SHIFT         (5U)
#define CRU_SOFTRST_CON19_RESETN_RKVENC_CORE_MASK          (0x1U << CRU_SOFTRST_CON19_RESETN_RKVENC_CORE_SHIFT)         /* 0x00000020 */
/* SOFTRST_CON20 */
#define CRU_SOFTRST_CON20_OFFSET                           (0x450U)
#define CRU_SOFTRST_CON20_ARESETN_RKVDEC_NIU_SHIFT         (0U)
#define CRU_SOFTRST_CON20_ARESETN_RKVDEC_NIU_MASK          (0x1U << CRU_SOFTRST_CON20_ARESETN_RKVDEC_NIU_SHIFT)         /* 0x00000001 */
#define CRU_SOFTRST_CON20_HRESETN_RKVDEC_NIU_SHIFT         (1U)
#define CRU_SOFTRST_CON20_HRESETN_RKVDEC_NIU_MASK          (0x1U << CRU_SOFTRST_CON20_HRESETN_RKVDEC_NIU_SHIFT)         /* 0x00000002 */
#define CRU_SOFTRST_CON20_ARESETN_RKVDEC_SHIFT             (2U)
#define CRU_SOFTRST_CON20_ARESETN_RKVDEC_MASK              (0x1U << CRU_SOFTRST_CON20_ARESETN_RKVDEC_SHIFT)             /* 0x00000004 */
#define CRU_SOFTRST_CON20_HRESETN_RKVDEC_SHIFT             (3U)
#define CRU_SOFTRST_CON20_HRESETN_RKVDEC_MASK              (0x1U << CRU_SOFTRST_CON20_HRESETN_RKVDEC_SHIFT)             /* 0x00000008 */
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_CA_SHIFT           (4U)
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_CA_MASK            (0x1U << CRU_SOFTRST_CON20_RESETN_RKVDEC_CA_SHIFT)           /* 0x00000010 */
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_CORE_SHIFT         (5U)
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_CORE_MASK          (0x1U << CRU_SOFTRST_CON20_RESETN_RKVDEC_CORE_SHIFT)         /* 0x00000020 */
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_HEVC_CA_SHIFT      (6U)
#define CRU_SOFTRST_CON20_RESETN_RKVDEC_HEVC_CA_MASK       (0x1U << CRU_SOFTRST_CON20_RESETN_RKVDEC_HEVC_CA_SHIFT)      /* 0x00000040 */
/* SOFTRST_CON21 */
#define CRU_SOFTRST_CON21_OFFSET                           (0x454U)
#define CRU_SOFTRST_CON21_ARESETN_BUS_NIU_SHIFT            (0U)
#define CRU_SOFTRST_CON21_ARESETN_BUS_NIU_MASK             (0x1U << CRU_SOFTRST_CON21_ARESETN_BUS_NIU_SHIFT)            /* 0x00000001 */
#define CRU_SOFTRST_CON21_PRESETN_BUS_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON21_PRESETN_BUS_NIU_MASK             (0x1U << CRU_SOFTRST_CON21_PRESETN_BUS_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON21_PRESETN_CAN0_SHIFT               (4U)
#define CRU_SOFTRST_CON21_PRESETN_CAN0_MASK                (0x1U << CRU_SOFTRST_CON21_PRESETN_CAN0_SHIFT)               /* 0x00000010 */
#define CRU_SOFTRST_CON21_RESETN_CAN0_SHIFT                (5U)
#define CRU_SOFTRST_CON21_RESETN_CAN0_MASK                 (0x1U << CRU_SOFTRST_CON21_RESETN_CAN0_SHIFT)                /* 0x00000020 */
#define CRU_SOFTRST_CON21_PRESETN_CAN1_SHIFT               (6U)
#define CRU_SOFTRST_CON21_PRESETN_CAN1_MASK                (0x1U << CRU_SOFTRST_CON21_PRESETN_CAN1_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON21_RESETN_CAN1_SHIFT                (7U)
#define CRU_SOFTRST_CON21_RESETN_CAN1_MASK                 (0x1U << CRU_SOFTRST_CON21_RESETN_CAN1_SHIFT)                /* 0x00000080 */
#define CRU_SOFTRST_CON21_PRESETN_CAN2_SHIFT               (8U)
#define CRU_SOFTRST_CON21_PRESETN_CAN2_MASK                (0x1U << CRU_SOFTRST_CON21_PRESETN_CAN2_SHIFT)               /* 0x00000100 */
#define CRU_SOFTRST_CON21_RESETN_CAN2_SHIFT                (9U)
#define CRU_SOFTRST_CON21_RESETN_CAN2_MASK                 (0x1U << CRU_SOFTRST_CON21_RESETN_CAN2_SHIFT)                /* 0x00000200 */
#define CRU_SOFTRST_CON21_PRESETN_GPIO1_SHIFT              (10U)
#define CRU_SOFTRST_CON21_PRESETN_GPIO1_MASK               (0x1U << CRU_SOFTRST_CON21_PRESETN_GPIO1_SHIFT)              /* 0x00000400 */
#define CRU_SOFTRST_CON21_DBRESETN_GPIO1_SHIFT             (11U)
#define CRU_SOFTRST_CON21_DBRESETN_GPIO1_MASK              (0x1U << CRU_SOFTRST_CON21_DBRESETN_GPIO1_SHIFT)             /* 0x00000800 */
#define CRU_SOFTRST_CON21_PRESETN_GPIO2_SHIFT              (12U)
#define CRU_SOFTRST_CON21_PRESETN_GPIO2_MASK               (0x1U << CRU_SOFTRST_CON21_PRESETN_GPIO2_SHIFT)              /* 0x00001000 */
#define CRU_SOFTRST_CON21_DBRESETN_GPIO2_SHIFT             (13U)
#define CRU_SOFTRST_CON21_DBRESETN_GPIO2_MASK              (0x1U << CRU_SOFTRST_CON21_DBRESETN_GPIO2_SHIFT)             /* 0x00002000 */
#define CRU_SOFTRST_CON21_PRESETN_GPIO3_SHIFT              (14U)
#define CRU_SOFTRST_CON21_PRESETN_GPIO3_MASK               (0x1U << CRU_SOFTRST_CON21_PRESETN_GPIO3_SHIFT)              /* 0x00004000 */
#define CRU_SOFTRST_CON21_DBRESETN_GPIO3_SHIFT             (15U)
#define CRU_SOFTRST_CON21_DBRESETN_GPIO3_MASK              (0x1U << CRU_SOFTRST_CON21_DBRESETN_GPIO3_SHIFT)             /* 0x00008000 */
/* SOFTRST_CON22 */
#define CRU_SOFTRST_CON22_OFFSET                           (0x458U)
#define CRU_SOFTRST_CON22_PRESETN_GPIO4_SHIFT              (0U)
#define CRU_SOFTRST_CON22_PRESETN_GPIO4_MASK               (0x1U << CRU_SOFTRST_CON22_PRESETN_GPIO4_SHIFT)              /* 0x00000001 */
#define CRU_SOFTRST_CON22_DBRESETN_GPIO4_SHIFT             (1U)
#define CRU_SOFTRST_CON22_DBRESETN_GPIO4_MASK              (0x1U << CRU_SOFTRST_CON22_DBRESETN_GPIO4_SHIFT)             /* 0x00000002 */
#define CRU_SOFTRST_CON22_PRESETN_I2C1_SHIFT               (2U)
#define CRU_SOFTRST_CON22_PRESETN_I2C1_MASK                (0x1U << CRU_SOFTRST_CON22_PRESETN_I2C1_SHIFT)               /* 0x00000004 */
#define CRU_SOFTRST_CON22_RESETN_I2C1_SHIFT                (3U)
#define CRU_SOFTRST_CON22_RESETN_I2C1_MASK                 (0x1U << CRU_SOFTRST_CON22_RESETN_I2C1_SHIFT)                /* 0x00000008 */
#define CRU_SOFTRST_CON22_PRESETN_I2C2_SHIFT               (4U)
#define CRU_SOFTRST_CON22_PRESETN_I2C2_MASK                (0x1U << CRU_SOFTRST_CON22_PRESETN_I2C2_SHIFT)               /* 0x00000010 */
#define CRU_SOFTRST_CON22_RESETN_I2C2_SHIFT                (5U)
#define CRU_SOFTRST_CON22_RESETN_I2C2_MASK                 (0x1U << CRU_SOFTRST_CON22_RESETN_I2C2_SHIFT)                /* 0x00000020 */
#define CRU_SOFTRST_CON22_PRESETN_I2C3_SHIFT               (6U)
#define CRU_SOFTRST_CON22_PRESETN_I2C3_MASK                (0x1U << CRU_SOFTRST_CON22_PRESETN_I2C3_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON22_RESETN_I2C3_SHIFT                (7U)
#define CRU_SOFTRST_CON22_RESETN_I2C3_MASK                 (0x1U << CRU_SOFTRST_CON22_RESETN_I2C3_SHIFT)                /* 0x00000080 */
#define CRU_SOFTRST_CON22_PRESETN_I2C4_SHIFT               (8U)
#define CRU_SOFTRST_CON22_PRESETN_I2C4_MASK                (0x1U << CRU_SOFTRST_CON22_PRESETN_I2C4_SHIFT)               /* 0x00000100 */
#define CRU_SOFTRST_CON22_RESETN_I2C4_SHIFT                (9U)
#define CRU_SOFTRST_CON22_RESETN_I2C4_MASK                 (0x1U << CRU_SOFTRST_CON22_RESETN_I2C4_SHIFT)                /* 0x00000200 */
#define CRU_SOFTRST_CON22_PRESETN_I2C5_SHIFT               (10U)
#define CRU_SOFTRST_CON22_PRESETN_I2C5_MASK                (0x1U << CRU_SOFTRST_CON22_PRESETN_I2C5_SHIFT)               /* 0x00000400 */
#define CRU_SOFTRST_CON22_RESETN_I2C5_SHIFT                (11U)
#define CRU_SOFTRST_CON22_RESETN_I2C5_MASK                 (0x1U << CRU_SOFTRST_CON22_RESETN_I2C5_SHIFT)                /* 0x00000800 */
#define CRU_SOFTRST_CON22_PRESETN_OTPC_NS_SHIFT            (12U)
#define CRU_SOFTRST_CON22_PRESETN_OTPC_NS_MASK             (0x1U << CRU_SOFTRST_CON22_PRESETN_OTPC_NS_SHIFT)            /* 0x00001000 */
#define CRU_SOFTRST_CON22_RESETN_OTPC_NS_SBPI_SHIFT        (13U)
#define CRU_SOFTRST_CON22_RESETN_OTPC_NS_SBPI_MASK         (0x1U << CRU_SOFTRST_CON22_RESETN_OTPC_NS_SBPI_SHIFT)        /* 0x00002000 */
#define CRU_SOFTRST_CON22_RESETN_OTPC_NS_USR_SHIFT         (14U)
#define CRU_SOFTRST_CON22_RESETN_OTPC_NS_USR_MASK          (0x1U << CRU_SOFTRST_CON22_RESETN_OTPC_NS_USR_SHIFT)         /* 0x00004000 */
/* SOFTRST_CON23 */
#define CRU_SOFTRST_CON23_OFFSET                           (0x45CU)
#define CRU_SOFTRST_CON23_PRESETN_PWM1_SHIFT               (0U)
#define CRU_SOFTRST_CON23_PRESETN_PWM1_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_PWM1_SHIFT)               /* 0x00000001 */
#define CRU_SOFTRST_CON23_RESETN_PWM1_SHIFT                (1U)
#define CRU_SOFTRST_CON23_RESETN_PWM1_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_PWM1_SHIFT)                /* 0x00000002 */
#define CRU_SOFTRST_CON23_PRESETN_PWM2_SHIFT               (2U)
#define CRU_SOFTRST_CON23_PRESETN_PWM2_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_PWM2_SHIFT)               /* 0x00000004 */
#define CRU_SOFTRST_CON23_RESETN_PWM2_SHIFT                (3U)
#define CRU_SOFTRST_CON23_RESETN_PWM2_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_PWM2_SHIFT)                /* 0x00000008 */
#define CRU_SOFTRST_CON23_PRESETN_PWM3_SHIFT               (4U)
#define CRU_SOFTRST_CON23_PRESETN_PWM3_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_PWM3_SHIFT)               /* 0x00000010 */
#define CRU_SOFTRST_CON23_RESETN_PWM3_SHIFT                (5U)
#define CRU_SOFTRST_CON23_RESETN_PWM3_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_PWM3_SHIFT)                /* 0x00000020 */
#define CRU_SOFTRST_CON23_PRESETN_SPI0_SHIFT               (6U)
#define CRU_SOFTRST_CON23_PRESETN_SPI0_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_SPI0_SHIFT)               /* 0x00000040 */
#define CRU_SOFTRST_CON23_RESETN_SPI0_SHIFT                (7U)
#define CRU_SOFTRST_CON23_RESETN_SPI0_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_SPI0_SHIFT)                /* 0x00000080 */
#define CRU_SOFTRST_CON23_PRESETN_SPI1_SHIFT               (8U)
#define CRU_SOFTRST_CON23_PRESETN_SPI1_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_SPI1_SHIFT)               /* 0x00000100 */
#define CRU_SOFTRST_CON23_RESETN_SPI1_SHIFT                (9U)
#define CRU_SOFTRST_CON23_RESETN_SPI1_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_SPI1_SHIFT)                /* 0x00000200 */
#define CRU_SOFTRST_CON23_PRESETN_SPI2_SHIFT               (10U)
#define CRU_SOFTRST_CON23_PRESETN_SPI2_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_SPI2_SHIFT)               /* 0x00000400 */
#define CRU_SOFTRST_CON23_RESETN_SPI2_SHIFT                (11U)
#define CRU_SOFTRST_CON23_RESETN_SPI2_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_SPI2_SHIFT)                /* 0x00000800 */
#define CRU_SOFTRST_CON23_PRESETN_SPI3_SHIFT               (12U)
#define CRU_SOFTRST_CON23_PRESETN_SPI3_MASK                (0x1U << CRU_SOFTRST_CON23_PRESETN_SPI3_SHIFT)               /* 0x00001000 */
#define CRU_SOFTRST_CON23_RESETN_SPI3_SHIFT                (13U)
#define CRU_SOFTRST_CON23_RESETN_SPI3_MASK                 (0x1U << CRU_SOFTRST_CON23_RESETN_SPI3_SHIFT)                /* 0x00002000 */
/* SOFTRST_CON24 */
#define CRU_SOFTRST_CON24_OFFSET                           (0x460U)
#define CRU_SOFTRST_CON24_PRESETN_SARADC_SHIFT             (0U)
#define CRU_SOFTRST_CON24_PRESETN_SARADC_MASK              (0x1U << CRU_SOFTRST_CON24_PRESETN_SARADC_SHIFT)             /* 0x00000001 */
#define CRU_SOFTRST_CON24_PRESETN_TSADC_SHIFT              (1U)
#define CRU_SOFTRST_CON24_PRESETN_TSADC_MASK               (0x1U << CRU_SOFTRST_CON24_PRESETN_TSADC_SHIFT)              /* 0x00000002 */
#define CRU_SOFTRST_CON24_RESETN_TSADC_SHIFT               (2U)
#define CRU_SOFTRST_CON24_RESETN_TSADC_MASK                (0x1U << CRU_SOFTRST_CON24_RESETN_TSADC_SHIFT)               /* 0x00000004 */
#define CRU_SOFTRST_CON24_PRESETN_TIMER_SHIFT              (3U)
#define CRU_SOFTRST_CON24_PRESETN_TIMER_MASK               (0x1U << CRU_SOFTRST_CON24_PRESETN_TIMER_SHIFT)              /* 0x00000008 */
#define CRU_SOFTRST_CON24_RESETN_TIMER0_SHIFT              (4U)
#define CRU_SOFTRST_CON24_RESETN_TIMER0_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER0_SHIFT)              /* 0x00000010 */
#define CRU_SOFTRST_CON24_RESETN_TIMER1_SHIFT              (5U)
#define CRU_SOFTRST_CON24_RESETN_TIMER1_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER1_SHIFT)              /* 0x00000020 */
#define CRU_SOFTRST_CON24_RESETN_TIMER2_SHIFT              (6U)
#define CRU_SOFTRST_CON24_RESETN_TIMER2_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER2_SHIFT)              /* 0x00000040 */
#define CRU_SOFTRST_CON24_RESETN_TIMER3_SHIFT              (7U)
#define CRU_SOFTRST_CON24_RESETN_TIMER3_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER3_SHIFT)              /* 0x00000080 */
#define CRU_SOFTRST_CON24_RESETN_TIMER4_SHIFT              (8U)
#define CRU_SOFTRST_CON24_RESETN_TIMER4_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER4_SHIFT)              /* 0x00000100 */
#define CRU_SOFTRST_CON24_RESETN_TIMER5_SHIFT              (9U)
#define CRU_SOFTRST_CON24_RESETN_TIMER5_MASK               (0x1U << CRU_SOFTRST_CON24_RESETN_TIMER5_SHIFT)              /* 0x00000200 */
#define CRU_SOFTRST_CON24_PRESETN_UART1_SHIFT              (10U)
#define CRU_SOFTRST_CON24_PRESETN_UART1_MASK               (0x1U << CRU_SOFTRST_CON24_PRESETN_UART1_SHIFT)              /* 0x00000400 */
#define CRU_SOFTRST_CON24_SRESETN_UART1_SHIFT              (11U)
#define CRU_SOFTRST_CON24_SRESETN_UART1_MASK               (0x1U << CRU_SOFTRST_CON24_SRESETN_UART1_SHIFT)              /* 0x00000800 */
/* SOFTRST_CON25 */
#define CRU_SOFTRST_CON25_OFFSET                           (0x464U)
#define CRU_SOFTRST_CON25_PRESETN_UART2_SHIFT              (0U)
#define CRU_SOFTRST_CON25_PRESETN_UART2_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART2_SHIFT)              /* 0x00000001 */
#define CRU_SOFTRST_CON25_SRESETN_UART2_SHIFT              (1U)
#define CRU_SOFTRST_CON25_SRESETN_UART2_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART2_SHIFT)              /* 0x00000002 */
#define CRU_SOFTRST_CON25_PRESETN_UART3_SHIFT              (2U)
#define CRU_SOFTRST_CON25_PRESETN_UART3_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART3_SHIFT)              /* 0x00000004 */
#define CRU_SOFTRST_CON25_SRESETN_UART3_SHIFT              (3U)
#define CRU_SOFTRST_CON25_SRESETN_UART3_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART3_SHIFT)              /* 0x00000008 */
#define CRU_SOFTRST_CON25_PRESETN_UART4_SHIFT              (4U)
#define CRU_SOFTRST_CON25_PRESETN_UART4_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART4_SHIFT)              /* 0x00000010 */
#define CRU_SOFTRST_CON25_SRESETN_UART4_SHIFT              (5U)
#define CRU_SOFTRST_CON25_SRESETN_UART4_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART4_SHIFT)              /* 0x00000020 */
#define CRU_SOFTRST_CON25_PRESETN_UART5_SHIFT              (6U)
#define CRU_SOFTRST_CON25_PRESETN_UART5_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART5_SHIFT)              /* 0x00000040 */
#define CRU_SOFTRST_CON25_SRESETN_UART5_SHIFT              (7U)
#define CRU_SOFTRST_CON25_SRESETN_UART5_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART5_SHIFT)              /* 0x00000080 */
#define CRU_SOFTRST_CON25_PRESETN_UART6_SHIFT              (8U)
#define CRU_SOFTRST_CON25_PRESETN_UART6_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART6_SHIFT)              /* 0x00000100 */
#define CRU_SOFTRST_CON25_SRESETN_UART6_SHIFT              (9U)
#define CRU_SOFTRST_CON25_SRESETN_UART6_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART6_SHIFT)              /* 0x00000200 */
#define CRU_SOFTRST_CON25_PRESETN_UART7_SHIFT              (10U)
#define CRU_SOFTRST_CON25_PRESETN_UART7_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART7_SHIFT)              /* 0x00000400 */
#define CRU_SOFTRST_CON25_SRESETN_UART7_SHIFT              (11U)
#define CRU_SOFTRST_CON25_SRESETN_UART7_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART7_SHIFT)              /* 0x00000800 */
#define CRU_SOFTRST_CON25_PRESETN_UART8_SHIFT              (12U)
#define CRU_SOFTRST_CON25_PRESETN_UART8_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART8_SHIFT)              /* 0x00001000 */
#define CRU_SOFTRST_CON25_SRESETN_UART8_SHIFT              (13U)
#define CRU_SOFTRST_CON25_SRESETN_UART8_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART8_SHIFT)              /* 0x00002000 */
#define CRU_SOFTRST_CON25_PRESETN_UART9_SHIFT              (14U)
#define CRU_SOFTRST_CON25_PRESETN_UART9_MASK               (0x1U << CRU_SOFTRST_CON25_PRESETN_UART9_SHIFT)              /* 0x00004000 */
#define CRU_SOFTRST_CON25_SRESETN_UART9_SHIFT              (15U)
#define CRU_SOFTRST_CON25_SRESETN_UART9_MASK               (0x1U << CRU_SOFTRST_CON25_SRESETN_UART9_SHIFT)              /* 0x00008000 */
/* SOFTRST_CON26 */
#define CRU_SOFTRST_CON26_OFFSET                           (0x468U)
#define CRU_SOFTRST_CON26_PRESETN_GRF_SHIFT                (0U)
#define CRU_SOFTRST_CON26_PRESETN_GRF_MASK                 (0x1U << CRU_SOFTRST_CON26_PRESETN_GRF_SHIFT)                /* 0x00000001 */
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO12_SHIFT        (1U)
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO12_MASK         (0x1U << CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO12_SHIFT)        /* 0x00000002 */
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO34_SHIFT        (2U)
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO34_MASK         (0x1U << CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO34_SHIFT)        /* 0x00000004 */
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO567_SHIFT       (3U)
#define CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO567_MASK        (0x1U << CRU_SOFTRST_CON26_PRESETN_GRF_VCCIO567_SHIFT)       /* 0x00000008 */
#define CRU_SOFTRST_CON26_PRESETN_SCR_SHIFT                (4U)
#define CRU_SOFTRST_CON26_PRESETN_SCR_MASK                 (0x1U << CRU_SOFTRST_CON26_PRESETN_SCR_SHIFT)                /* 0x00000010 */
#define CRU_SOFTRST_CON26_PRESETN_WDT_NS_SHIFT             (5U)
#define CRU_SOFTRST_CON26_PRESETN_WDT_NS_MASK              (0x1U << CRU_SOFTRST_CON26_PRESETN_WDT_NS_SHIFT)             /* 0x00000020 */
#define CRU_SOFTRST_CON26_TRESETN_WDT_NS_SHIFT             (6U)
#define CRU_SOFTRST_CON26_TRESETN_WDT_NS_MASK              (0x1U << CRU_SOFTRST_CON26_TRESETN_WDT_NS_SHIFT)             /* 0x00000040 */
#define CRU_SOFTRST_CON26_PRESETN_DFT2APB_SHIFT            (7U)
#define CRU_SOFTRST_CON26_PRESETN_DFT2APB_MASK             (0x1U << CRU_SOFTRST_CON26_PRESETN_DFT2APB_SHIFT)            /* 0x00000080 */
#define CRU_SOFTRST_CON26_ARESETN_MCU_SHIFT                (10U)
#define CRU_SOFTRST_CON26_ARESETN_MCU_MASK                 (0x1U << CRU_SOFTRST_CON26_ARESETN_MCU_SHIFT)                /* 0x00000400 */
#define CRU_SOFTRST_CON26_PRESETN_INTMUX_SHIFT             (11U)
#define CRU_SOFTRST_CON26_PRESETN_INTMUX_MASK              (0x1U << CRU_SOFTRST_CON26_PRESETN_INTMUX_SHIFT)             /* 0x00000800 */
#define CRU_SOFTRST_CON26_PRESETN_MAILBOX_SHIFT            (12U)
#define CRU_SOFTRST_CON26_PRESETN_MAILBOX_MASK             (0x1U << CRU_SOFTRST_CON26_PRESETN_MAILBOX_SHIFT)            /* 0x00001000 */
/* SOFTRST_CON27 */
#define CRU_SOFTRST_CON27_OFFSET                           (0x46CU)
#define CRU_SOFTRST_CON27_ARESETN_TOP_HIGH_NIU_SHIFT       (0U)
#define CRU_SOFTRST_CON27_ARESETN_TOP_HIGH_NIU_MASK        (0x1U << CRU_SOFTRST_CON27_ARESETN_TOP_HIGH_NIU_SHIFT)       /* 0x00000001 */
#define CRU_SOFTRST_CON27_ARESETN_TOP_LOW_NIU_SHIFT        (1U)
#define CRU_SOFTRST_CON27_ARESETN_TOP_LOW_NIU_MASK         (0x1U << CRU_SOFTRST_CON27_ARESETN_TOP_LOW_NIU_SHIFT)        /* 0x00000002 */
#define CRU_SOFTRST_CON27_HRESETN_TOP_NIU_SHIFT            (2U)
#define CRU_SOFTRST_CON27_HRESETN_TOP_NIU_MASK             (0x1U << CRU_SOFTRST_CON27_HRESETN_TOP_NIU_SHIFT)            /* 0x00000004 */
#define CRU_SOFTRST_CON27_PRESETN_TOP_NIU_SHIFT            (3U)
#define CRU_SOFTRST_CON27_PRESETN_TOP_NIU_MASK             (0x1U << CRU_SOFTRST_CON27_PRESETN_TOP_NIU_SHIFT)            /* 0x00000008 */
#define CRU_SOFTRST_CON27_PRESETN_TOP_CRU_SHIFT            (6U)
#define CRU_SOFTRST_CON27_PRESETN_TOP_CRU_MASK             (0x1U << CRU_SOFTRST_CON27_PRESETN_TOP_CRU_SHIFT)            /* 0x00000040 */
#define CRU_SOFTRST_CON27_PRESETN_DDRPHY_SHIFT             (7U)
#define CRU_SOFTRST_CON27_PRESETN_DDRPHY_MASK              (0x1U << CRU_SOFTRST_CON27_PRESETN_DDRPHY_SHIFT)             /* 0x00000080 */
#define CRU_SOFTRST_CON27_RESETN_DDRPHY_SHIFT              (8U)
#define CRU_SOFTRST_CON27_RESETN_DDRPHY_MASK               (0x1U << CRU_SOFTRST_CON27_RESETN_DDRPHY_SHIFT)              /* 0x00000100 */
#define CRU_SOFTRST_CON27_PRESETN_MIPICSIPHY_SHIFT         (10U)
#define CRU_SOFTRST_CON27_PRESETN_MIPICSIPHY_MASK          (0x1U << CRU_SOFTRST_CON27_PRESETN_MIPICSIPHY_SHIFT)         /* 0x00000400 */
#define CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY0_SHIFT        (11U)
#define CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY0_MASK         (0x1U << CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY0_SHIFT)        /* 0x00000800 */
#define CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY1_SHIFT        (12U)
#define CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY1_MASK         (0x1U << CRU_SOFTRST_CON27_PRESETN_MIPIDSIPHY1_SHIFT)        /* 0x00001000 */
#define CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_SHIFT          (13U)
#define CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_MASK           (0x1U << CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_SHIFT)          /* 0x00002000 */
#define CRU_SOFTRST_CON27_RESETN_PCIE30PHY_SHIFT           (14U)
#define CRU_SOFTRST_CON27_RESETN_PCIE30PHY_MASK            (0x1U << CRU_SOFTRST_CON27_RESETN_PCIE30PHY_SHIFT)           /* 0x00004000 */
#define CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_GRF_SHIFT      (15U)
#define CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_GRF_MASK       (0x1U << CRU_SOFTRST_CON27_PRESETN_PCIE30PHY_GRF_SHIFT)      /* 0x00008000 */
/* SOFTRST_CON28 */
#define CRU_SOFTRST_CON28_OFFSET                           (0x470U)
#define CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_LEFT_SHIFT  (0U)
#define CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_LEFT_MASK   (0x1U << CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_LEFT_SHIFT)  /* 0x00000001 */
#define CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_BOTTOM_SHIFT (1U)
#define CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_BOTTOM_MASK (0x1U << CRU_SOFTRST_CON28_PRESETN_APB2ASB_CHIP_BOTTOM_SHIFT) /* 0x00000002 */
#define CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_LEFT_SHIFT  (2U)
#define CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_LEFT_MASK   (0x1U << CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_LEFT_SHIFT)  /* 0x00000004 */
#define CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_BOTTOM_SHIFT (3U)
#define CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_BOTTOM_MASK (0x1U << CRU_SOFTRST_CON28_PRESETN_ASB2APB_CHIP_BOTTOM_SHIFT) /* 0x00000008 */
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY0_SHIFT           (4U)
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY0_MASK            (0x1U << CRU_SOFTRST_CON28_PRESETN_PIPEPHY0_SHIFT)           /* 0x00000010 */
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY0_SHIFT            (5U)
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY0_MASK             (0x1U << CRU_SOFTRST_CON28_RESETN_PIPEPHY0_SHIFT)            /* 0x00000020 */
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY1_SHIFT           (6U)
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY1_MASK            (0x1U << CRU_SOFTRST_CON28_PRESETN_PIPEPHY1_SHIFT)           /* 0x00000040 */
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY1_SHIFT            (7U)
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY1_MASK             (0x1U << CRU_SOFTRST_CON28_RESETN_PIPEPHY1_SHIFT)            /* 0x00000080 */
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY2_SHIFT           (8U)
#define CRU_SOFTRST_CON28_PRESETN_PIPEPHY2_MASK            (0x1U << CRU_SOFTRST_CON28_PRESETN_PIPEPHY2_SHIFT)           /* 0x00000100 */
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY2_SHIFT            (9U)
#define CRU_SOFTRST_CON28_RESETN_PIPEPHY2_MASK             (0x1U << CRU_SOFTRST_CON28_RESETN_PIPEPHY2_SHIFT)            /* 0x00000200 */
#define CRU_SOFTRST_CON28_PRESETN_USB2PHY0_GRF_SHIFT       (10U)
#define CRU_SOFTRST_CON28_PRESETN_USB2PHY0_GRF_MASK        (0x1U << CRU_SOFTRST_CON28_PRESETN_USB2PHY0_GRF_SHIFT)       /* 0x00000400 */
#define CRU_SOFTRST_CON28_PRESETN_USB2PHY1_GRF_SHIFT       (11U)
#define CRU_SOFTRST_CON28_PRESETN_USB2PHY1_GRF_MASK        (0x1U << CRU_SOFTRST_CON28_PRESETN_USB2PHY1_GRF_SHIFT)       /* 0x00000800 */
#define CRU_SOFTRST_CON28_PRESETN_CPU_BOOST_SHIFT          (12U)
#define CRU_SOFTRST_CON28_PRESETN_CPU_BOOST_MASK           (0x1U << CRU_SOFTRST_CON28_PRESETN_CPU_BOOST_SHIFT)          /* 0x00001000 */
#define CRU_SOFTRST_CON28_RESETN_CPU_BOOST_SHIFT           (13U)
#define CRU_SOFTRST_CON28_RESETN_CPU_BOOST_MASK            (0x1U << CRU_SOFTRST_CON28_RESETN_CPU_BOOST_SHIFT)           /* 0x00002000 */
#define CRU_SOFTRST_CON28_PRESETN_OTPPHY_SHIFT             (14U)
#define CRU_SOFTRST_CON28_PRESETN_OTPPHY_MASK              (0x1U << CRU_SOFTRST_CON28_PRESETN_OTPPHY_SHIFT)             /* 0x00004000 */
#define CRU_SOFTRST_CON28_RESETN_OTPPHY_SHIFT              (15U)
#define CRU_SOFTRST_CON28_RESETN_OTPPHY_MASK               (0x1U << CRU_SOFTRST_CON28_RESETN_OTPPHY_SHIFT)              /* 0x00008000 */
/* SOFTRST_CON29 */
#define CRU_SOFTRST_CON29_OFFSET                           (0x474U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_POR_SHIFT        (0U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_POR_MASK         (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY0_POR_SHIFT)        /* 0x00000001 */
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG0_SHIFT   (1U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG0_MASK    (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG0_SHIFT)   /* 0x00000002 */
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG1_SHIFT   (2U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG1_MASK    (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY0_USB3OTG1_SHIFT)   /* 0x00000004 */
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_POR_SHIFT        (3U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_POR_MASK         (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY1_POR_SHIFT)        /* 0x00000008 */
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST0_SHIFT  (4U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST0_MASK   (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST0_SHIFT)  /* 0x00000010 */
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST1_SHIFT  (5U)
#define CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST1_MASK   (0x1U << CRU_SOFTRST_CON29_RESETN_USB2PHY1_USB2HOST1_SHIFT)  /* 0x00000020 */
#define CRU_SOFTRST_CON29_PRESETN_EDPPHY_GRF_SHIFT         (6U)
#define CRU_SOFTRST_CON29_PRESETN_EDPPHY_GRF_MASK          (0x1U << CRU_SOFTRST_CON29_PRESETN_EDPPHY_GRF_SHIFT)         /* 0x00000040 */
#define CRU_SOFTRST_CON29_RESETN_TSADCPHY_SHIFT            (7U)
#define CRU_SOFTRST_CON29_RESETN_TSADCPHY_MASK             (0x1U << CRU_SOFTRST_CON29_RESETN_TSADCPHY_SHIFT)            /* 0x00000080 */
#define CRU_SOFTRST_CON29_RESETN_GMAC0_DELAYLINE_SHIFT     (8U)
#define CRU_SOFTRST_CON29_RESETN_GMAC0_DELAYLINE_MASK      (0x1U << CRU_SOFTRST_CON29_RESETN_GMAC0_DELAYLINE_SHIFT)     /* 0x00000100 */
#define CRU_SOFTRST_CON29_RESETN_GMAC1_DELAYLINE_SHIFT     (9U)
#define CRU_SOFTRST_CON29_RESETN_GMAC1_DELAYLINE_MASK      (0x1U << CRU_SOFTRST_CON29_RESETN_GMAC1_DELAYLINE_SHIFT)     /* 0x00000200 */
#define CRU_SOFTRST_CON29_RESETN_OTPC_ARB_SHIFT            (10U)
#define CRU_SOFTRST_CON29_RESETN_OTPC_ARB_MASK             (0x1U << CRU_SOFTRST_CON29_RESETN_OTPC_ARB_SHIFT)            /* 0x00000400 */
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY0_GRF_SHIFT       (11U)
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY0_GRF_MASK        (0x1U << CRU_SOFTRST_CON29_PRESETN_PIPEPHY0_GRF_SHIFT)       /* 0x00000800 */
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY1_GRF_SHIFT       (12U)
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY1_GRF_MASK        (0x1U << CRU_SOFTRST_CON29_PRESETN_PIPEPHY1_GRF_SHIFT)       /* 0x00001000 */
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY2_GRF_SHIFT       (13U)
#define CRU_SOFTRST_CON29_PRESETN_PIPEPHY2_GRF_MASK        (0x1U << CRU_SOFTRST_CON29_PRESETN_PIPEPHY2_GRF_SHIFT)       /* 0x00002000 */
/* SSGTBL0_3 */
#define CRU_SSGTBL0_3_OFFSET                               (0x480U)
#define CRU_SSGTBL0_3_SSGTBL0_3_SHIFT                      (0U)
#define CRU_SSGTBL0_3_SSGTBL0_3_MASK                       (0xFFFFFFFFU << CRU_SSGTBL0_3_SSGTBL0_3_SHIFT)               /* 0xFFFFFFFF */
/* SSGTBL4_7 */
#define CRU_SSGTBL4_7_OFFSET                               (0x484U)
#define CRU_SSGTBL4_7_SSGTBL4_7_SHIFT                      (0U)
#define CRU_SSGTBL4_7_SSGTBL4_7_MASK                       (0xFFFFFFFFU << CRU_SSGTBL4_7_SSGTBL4_7_SHIFT)               /* 0xFFFFFFFF */
/* SSGTBL8_11 */
#define CRU_SSGTBL8_11_OFFSET                              (0x488U)
#define CRU_SSGTBL8_11_SSGTBL8_11_SHIFT                    (0U)
#define CRU_SSGTBL8_11_SSGTBL8_11_MASK                     (0xFFFFFFFFU << CRU_SSGTBL8_11_SSGTBL8_11_SHIFT)             /* 0xFFFFFFFF */
/* SSGTBL12_15 */
#define CRU_SSGTBL12_15_OFFSET                             (0x48CU)
#define CRU_SSGTBL12_15_SSGTBL12_15_SHIFT                  (0U)
#define CRU_SSGTBL12_15_SSGTBL12_15_MASK                   (0xFFFFFFFFU << CRU_SSGTBL12_15_SSGTBL12_15_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL16_19 */
#define CRU_SSGTBL16_19_OFFSET                             (0x490U)
#define CRU_SSGTBL16_19_SSGTBL16_19_SHIFT                  (0U)
#define CRU_SSGTBL16_19_SSGTBL16_19_MASK                   (0xFFFFFFFFU << CRU_SSGTBL16_19_SSGTBL16_19_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL20_23 */
#define CRU_SSGTBL20_23_OFFSET                             (0x494U)
#define CRU_SSGTBL20_23_SSGTBL20_23_SHIFT                  (0U)
#define CRU_SSGTBL20_23_SSGTBL20_23_MASK                   (0xFFFFFFFFU << CRU_SSGTBL20_23_SSGTBL20_23_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL24_27 */
#define CRU_SSGTBL24_27_OFFSET                             (0x498U)
#define CRU_SSGTBL24_27_SSGTBL24_27_SHIFT                  (0U)
#define CRU_SSGTBL24_27_SSGTBL24_27_MASK                   (0xFFFFFFFFU << CRU_SSGTBL24_27_SSGTBL24_27_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL28_31 */
#define CRU_SSGTBL28_31_OFFSET                             (0x49CU)
#define CRU_SSGTBL28_31_SSGTBL28_31_SHIFT                  (0U)
#define CRU_SSGTBL28_31_SSGTBL28_31_MASK                   (0xFFFFFFFFU << CRU_SSGTBL28_31_SSGTBL28_31_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL32_35 */
#define CRU_SSGTBL32_35_OFFSET                             (0x4A0U)
#define CRU_SSGTBL32_35_SSGTBL32_35_SHIFT                  (0U)
#define CRU_SSGTBL32_35_SSGTBL32_35_MASK                   (0xFFFFFFFFU << CRU_SSGTBL32_35_SSGTBL32_35_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL36_39 */
#define CRU_SSGTBL36_39_OFFSET                             (0x4A4U)
#define CRU_SSGTBL36_39_SSGTBL36_39_SHIFT                  (0U)
#define CRU_SSGTBL36_39_SSGTBL36_39_MASK                   (0xFFFFFFFFU << CRU_SSGTBL36_39_SSGTBL36_39_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL40_43 */
#define CRU_SSGTBL40_43_OFFSET                             (0x4A8U)
#define CRU_SSGTBL40_43_SSGTBL40_43_SHIFT                  (0U)
#define CRU_SSGTBL40_43_SSGTBL40_43_MASK                   (0xFFFFFFFFU << CRU_SSGTBL40_43_SSGTBL40_43_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL44_47 */
#define CRU_SSGTBL44_47_OFFSET                             (0x4ACU)
#define CRU_SSGTBL44_47_SSGTBL44_47_SHIFT                  (0U)
#define CRU_SSGTBL44_47_SSGTBL44_47_MASK                   (0xFFFFFFFFU << CRU_SSGTBL44_47_SSGTBL44_47_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL48_51 */
#define CRU_SSGTBL48_51_OFFSET                             (0x4B0U)
#define CRU_SSGTBL48_51_SSGTBL48_51_SHIFT                  (0U)
#define CRU_SSGTBL48_51_SSGTBL48_51_MASK                   (0xFFFFFFFFU << CRU_SSGTBL48_51_SSGTBL48_51_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL52_55 */
#define CRU_SSGTBL52_55_OFFSET                             (0x4B4U)
#define CRU_SSGTBL52_55_SSGTBL52_55_SHIFT                  (0U)
#define CRU_SSGTBL52_55_SSGTBL52_55_MASK                   (0xFFFFFFFFU << CRU_SSGTBL52_55_SSGTBL52_55_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL56_59 */
#define CRU_SSGTBL56_59_OFFSET                             (0x4B8U)
#define CRU_SSGTBL56_59_SSGTBL56_59_SHIFT                  (0U)
#define CRU_SSGTBL56_59_SSGTBL56_59_MASK                   (0xFFFFFFFFU << CRU_SSGTBL56_59_SSGTBL56_59_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL60_63 */
#define CRU_SSGTBL60_63_OFFSET                             (0x4BCU)
#define CRU_SSGTBL60_63_SSGTBL60_63_SHIFT                  (0U)
#define CRU_SSGTBL60_63_SSGTBL60_63_MASK                   (0xFFFFFFFFU << CRU_SSGTBL60_63_SSGTBL60_63_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL64_67 */
#define CRU_SSGTBL64_67_OFFSET                             (0x4C0U)
#define CRU_SSGTBL64_67_SSGTBL64_67_SHIFT                  (0U)
#define CRU_SSGTBL64_67_SSGTBL64_67_MASK                   (0xFFFFFFFFU << CRU_SSGTBL64_67_SSGTBL64_67_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL68_71 */
#define CRU_SSGTBL68_71_OFFSET                             (0x4C4U)
#define CRU_SSGTBL68_71_SSGTBL68_71_SHIFT                  (0U)
#define CRU_SSGTBL68_71_SSGTBL68_71_MASK                   (0xFFFFFFFFU << CRU_SSGTBL68_71_SSGTBL68_71_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL72_75 */
#define CRU_SSGTBL72_75_OFFSET                             (0x4C8U)
#define CRU_SSGTBL72_75_SSGTBL72_75_SHIFT                  (0U)
#define CRU_SSGTBL72_75_SSGTBL72_75_MASK                   (0xFFFFFFFFU << CRU_SSGTBL72_75_SSGTBL72_75_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL76_79 */
#define CRU_SSGTBL76_79_OFFSET                             (0x4CCU)
#define CRU_SSGTBL76_79_SSGTBL76_79_SHIFT                  (0U)
#define CRU_SSGTBL76_79_SSGTBL76_79_MASK                   (0xFFFFFFFFU << CRU_SSGTBL76_79_SSGTBL76_79_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL80_83 */
#define CRU_SSGTBL80_83_OFFSET                             (0x4D0U)
#define CRU_SSGTBL80_83_SSGTBL80_83_SHIFT                  (0U)
#define CRU_SSGTBL80_83_SSGTBL80_83_MASK                   (0xFFFFFFFFU << CRU_SSGTBL80_83_SSGTBL80_83_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL84_87 */
#define CRU_SSGTBL84_87_OFFSET                             (0x4D4U)
#define CRU_SSGTBL84_87_SSGTBL84_87_SHIFT                  (0U)
#define CRU_SSGTBL84_87_SSGTBL84_87_MASK                   (0xFFFFFFFFU << CRU_SSGTBL84_87_SSGTBL84_87_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL88_91 */
#define CRU_SSGTBL88_91_OFFSET                             (0x4D8U)
#define CRU_SSGTBL88_91_SSGTBL88_91_SHIFT                  (0U)
#define CRU_SSGTBL88_91_SSGTBL88_91_MASK                   (0xFFFFFFFFU << CRU_SSGTBL88_91_SSGTBL88_91_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL92_95 */
#define CRU_SSGTBL92_95_OFFSET                             (0x4DCU)
#define CRU_SSGTBL92_95_SSGTBL92_95_SHIFT                  (0U)
#define CRU_SSGTBL92_95_SSGTBL92_95_MASK                   (0xFFFFFFFFU << CRU_SSGTBL92_95_SSGTBL92_95_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL96_99 */
#define CRU_SSGTBL96_99_OFFSET                             (0x4E0U)
#define CRU_SSGTBL96_99_SSGTBL96_99_SHIFT                  (0U)
#define CRU_SSGTBL96_99_SSGTBL96_99_MASK                   (0xFFFFFFFFU << CRU_SSGTBL96_99_SSGTBL96_99_SHIFT)           /* 0xFFFFFFFF */
/* SSGTBL100_103 */
#define CRU_SSGTBL100_103_OFFSET                           (0x4E4U)
#define CRU_SSGTBL100_103_SSGTBL100_103_SHIFT              (0U)
#define CRU_SSGTBL100_103_SSGTBL100_103_MASK               (0xFFFFFFFFU << CRU_SSGTBL100_103_SSGTBL100_103_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL104_107 */
#define CRU_SSGTBL104_107_OFFSET                           (0x4E8U)
#define CRU_SSGTBL104_107_SSGTBL104_107_SHIFT              (0U)
#define CRU_SSGTBL104_107_SSGTBL104_107_MASK               (0xFFFFFFFFU << CRU_SSGTBL104_107_SSGTBL104_107_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL108_111 */
#define CRU_SSGTBL108_111_OFFSET                           (0x4ECU)
#define CRU_SSGTBL108_111_SSGTBL108_111_SHIFT              (0U)
#define CRU_SSGTBL108_111_SSGTBL108_111_MASK               (0xFFFFFFFFU << CRU_SSGTBL108_111_SSGTBL108_111_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL112_115 */
#define CRU_SSGTBL112_115_OFFSET                           (0x4F0U)
#define CRU_SSGTBL112_115_SSGTBL112_115_SHIFT              (0U)
#define CRU_SSGTBL112_115_SSGTBL112_115_MASK               (0xFFFFFFFFU << CRU_SSGTBL112_115_SSGTBL112_115_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL116_119 */
#define CRU_SSGTBL116_119_OFFSET                           (0x4F4U)
#define CRU_SSGTBL116_119_SSGTBL116_119_SHIFT              (0U)
#define CRU_SSGTBL116_119_SSGTBL116_119_MASK               (0xFFFFFFFFU << CRU_SSGTBL116_119_SSGTBL116_119_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL120_123 */
#define CRU_SSGTBL120_123_OFFSET                           (0x4F8U)
#define CRU_SSGTBL120_123_SSGTBL120_123_SHIFT              (0U)
#define CRU_SSGTBL120_123_SSGTBL120_123_MASK               (0xFFFFFFFFU << CRU_SSGTBL120_123_SSGTBL120_123_SHIFT)       /* 0xFFFFFFFF */
/* SSGTBL124_127 */
#define CRU_SSGTBL124_127_OFFSET                           (0x4FCU)
#define CRU_SSGTBL124_127_SSGTBL124_127_SHIFT              (0U)
#define CRU_SSGTBL124_127_SSGTBL124_127_MASK               (0xFFFFFFFFU << CRU_SSGTBL124_127_SSGTBL124_127_SHIFT)       /* 0xFFFFFFFF */
/* AUTOCS_CORE_CON0 */
#define CRU_AUTOCS_CORE_CON0_OFFSET                        (0x500U)
#define CRU_AUTOCS_CORE_CON0_PDCORE_IDLE_TH_SHIFT          (0U)
#define CRU_AUTOCS_CORE_CON0_PDCORE_IDLE_TH_MASK           (0xFFFFU << CRU_AUTOCS_CORE_CON0_PDCORE_IDLE_TH_SHIFT)       /* 0x0000FFFF */
#define CRU_AUTOCS_CORE_CON0_PDCORE_WAIT_TH_SHIFT          (16U)
#define CRU_AUTOCS_CORE_CON0_PDCORE_WAIT_TH_MASK           (0xFFFFU << CRU_AUTOCS_CORE_CON0_PDCORE_WAIT_TH_SHIFT)       /* 0xFFFF0000 */
/* AUTOCS_CORE_CON1 */
#define CRU_AUTOCS_CORE_CON1_OFFSET                        (0x504U)
#define CRU_AUTOCS_CORE_CON1_CPU_SWITCH_EN_SHIFT           (0U)
#define CRU_AUTOCS_CORE_CON1_CPU_SWITCH_EN_MASK            (0x1U << CRU_AUTOCS_CORE_CON1_CPU_SWITCH_EN_SHIFT)           /* 0x00000001 */
#define CRU_AUTOCS_CORE_CON1_DSU_SWITCH_EN_SHIFT           (1U)
#define CRU_AUTOCS_CORE_CON1_DSU_SWITCH_EN_MASK            (0x1U << CRU_AUTOCS_CORE_CON1_DSU_SWITCH_EN_SHIFT)           /* 0x00000002 */
#define CRU_AUTOCS_CORE_CON1_WFI_EN_SHIFT                  (2U)
#define CRU_AUTOCS_CORE_CON1_WFI_EN_MASK                   (0x1U << CRU_AUTOCS_CORE_CON1_WFI_EN_SHIFT)                  /* 0x00000004 */
#define CRU_AUTOCS_CORE_CON1_WFIL3_EN_SHIFT                (3U)
#define CRU_AUTOCS_CORE_CON1_WFIL3_EN_MASK                 (0x1U << CRU_AUTOCS_CORE_CON1_WFIL3_EN_SHIFT)                /* 0x00000008 */
#define CRU_AUTOCS_CORE_CON1_FIQIRQ_EN_SHIFT               (4U)
#define CRU_AUTOCS_CORE_CON1_FIQIRQ_EN_MASK                (0x1U << CRU_AUTOCS_CORE_CON1_FIQIRQ_EN_SHIFT)               /* 0x00000010 */
#define CRU_AUTOCS_CORE_CON1_VFIQIRQ_EN_SHIFT              (5U)
#define CRU_AUTOCS_CORE_CON1_VFIQIRQ_EN_MASK               (0x1U << CRU_AUTOCS_CORE_CON1_VFIQIRQ_EN_SHIFT)              /* 0x00000020 */
#define CRU_AUTOCS_CORE_CON1_NIU_ACTIVE_EN_SHIFT           (6U)
#define CRU_AUTOCS_CORE_CON1_NIU_ACTIVE_EN_MASK            (0x1U << CRU_AUTOCS_CORE_CON1_NIU_ACTIVE_EN_SHIFT)           /* 0x00000040 */
#define CRU_AUTOCS_CORE_CON1_STEP_SHIFT                    (8U)
#define CRU_AUTOCS_CORE_CON1_STEP_MASK                     (0x7U << CRU_AUTOCS_CORE_CON1_STEP_SHIFT)                    /* 0x00000700 */
#define CRU_AUTOCS_CORE_CON1_CLKSEL_CFG_SHIFT              (14U)
#define CRU_AUTOCS_CORE_CON1_CLKSEL_CFG_MASK               (0x3U << CRU_AUTOCS_CORE_CON1_CLKSEL_CFG_SHIFT)              /* 0x0000C000 */
/* AUTOCS_GPU_CON0 */
#define CRU_AUTOCS_GPU_CON0_OFFSET                         (0x508U)
#define CRU_AUTOCS_GPU_CON0_IDLE_TH_SHIFT                  (0U)
#define CRU_AUTOCS_GPU_CON0_IDLE_TH_MASK                   (0xFFFFU << CRU_AUTOCS_GPU_CON0_IDLE_TH_SHIFT)               /* 0x0000FFFF */
#define CRU_AUTOCS_GPU_CON0_WAIT_TH_SHIFT                  (16U)
#define CRU_AUTOCS_GPU_CON0_WAIT_TH_MASK                   (0xFFFFU << CRU_AUTOCS_GPU_CON0_WAIT_TH_SHIFT)               /* 0xFFFF0000 */
/* AUTOCS_GPU_CON1 */
#define CRU_AUTOCS_GPU_CON1_OFFSET                         (0x50CU)
#define CRU_AUTOCS_GPU_CON1_SWITCH_EN_SHIFT                (0U)
#define CRU_AUTOCS_GPU_CON1_SWITCH_EN_MASK                 (0x1U << CRU_AUTOCS_GPU_CON1_SWITCH_EN_SHIFT)                /* 0x00000001 */
#define CRU_AUTOCS_GPU_CON1_CLK_EN_SHIFT                   (1U)
#define CRU_AUTOCS_GPU_CON1_CLK_EN_MASK                    (0x1U << CRU_AUTOCS_GPU_CON1_CLK_EN_SHIFT)                   /* 0x00000002 */
#define CRU_AUTOCS_GPU_CON1_CLKSEL_CFG_SHIFT               (14U)
#define CRU_AUTOCS_GPU_CON1_CLKSEL_CFG_MASK                (0x3U << CRU_AUTOCS_GPU_CON1_CLKSEL_CFG_SHIFT)               /* 0x0000C000 */
/* AUTOCS_BUS_CON0 */
#define CRU_AUTOCS_BUS_CON0_OFFSET                         (0x510U)
#define CRU_AUTOCS_BUS_CON0_IDLE_TH_SHIFT                  (0U)
#define CRU_AUTOCS_BUS_CON0_IDLE_TH_MASK                   (0xFFFFU << CRU_AUTOCS_BUS_CON0_IDLE_TH_SHIFT)               /* 0x0000FFFF */
#define CRU_AUTOCS_BUS_CON0_WAIT_TH_SHIFT                  (16U)
#define CRU_AUTOCS_BUS_CON0_WAIT_TH_MASK                   (0xFFFFU << CRU_AUTOCS_BUS_CON0_WAIT_TH_SHIFT)               /* 0xFFFF0000 */
/* AUTOCS_BUS_CON1 */
#define CRU_AUTOCS_BUS_CON1_OFFSET                         (0x514U)
#define CRU_AUTOCS_BUS_CON1_SWITCH_EN_SHIFT                (0U)
#define CRU_AUTOCS_BUS_CON1_SWITCH_EN_MASK                 (0x1U << CRU_AUTOCS_BUS_CON1_SWITCH_EN_SHIFT)                /* 0x00000001 */
#define CRU_AUTOCS_BUS_CON1_ACLK_EN_SHIFT                  (1U)
#define CRU_AUTOCS_BUS_CON1_ACLK_EN_MASK                   (0x1U << CRU_AUTOCS_BUS_CON1_ACLK_EN_SHIFT)                  /* 0x00000002 */
#define CRU_AUTOCS_BUS_CON1_PCLK_EN_SHIFT                  (3U)
#define CRU_AUTOCS_BUS_CON1_PCLK_EN_MASK                   (0x1U << CRU_AUTOCS_BUS_CON1_PCLK_EN_SHIFT)                  /* 0x00000008 */
#define CRU_AUTOCS_BUS_CON1_MASTER_EN_SHIFT                (4U)
#define CRU_AUTOCS_BUS_CON1_MASTER_EN_MASK                 (0x1U << CRU_AUTOCS_BUS_CON1_MASTER_EN_SHIFT)                /* 0x00000010 */
#define CRU_AUTOCS_BUS_CON1_SLAVE_EN_SHIFT                 (5U)
#define CRU_AUTOCS_BUS_CON1_SLAVE_EN_MASK                  (0x1U << CRU_AUTOCS_BUS_CON1_SLAVE_EN_SHIFT)                 /* 0x00000020 */
#define CRU_AUTOCS_BUS_CON1_DMAC_M_EN_SHIFT                (7U)
#define CRU_AUTOCS_BUS_CON1_DMAC_M_EN_MASK                 (0x1U << CRU_AUTOCS_BUS_CON1_DMAC_M_EN_SHIFT)                /* 0x00000080 */
#define CRU_AUTOCS_BUS_CON1_CLKSEL_CFG_SHIFT               (14U)
#define CRU_AUTOCS_BUS_CON1_CLKSEL_CFG_MASK                (0x3U << CRU_AUTOCS_BUS_CON1_CLKSEL_CFG_SHIFT)               /* 0x0000C000 */
/* AUTOCS_TOP_CON0 */
#define CRU_AUTOCS_TOP_CON0_OFFSET                         (0x518U)
#define CRU_AUTOCS_TOP_CON0_IDLE_TH_SHIFT                  (0U)
#define CRU_AUTOCS_TOP_CON0_IDLE_TH_MASK                   (0xFFFFU << CRU_AUTOCS_TOP_CON0_IDLE_TH_SHIFT)               /* 0x0000FFFF */
#define CRU_AUTOCS_TOP_CON0_WAIT_TH_SHIFT                  (16U)
#define CRU_AUTOCS_TOP_CON0_WAIT_TH_MASK                   (0xFFFFU << CRU_AUTOCS_TOP_CON0_WAIT_TH_SHIFT)               /* 0xFFFF0000 */
/* AUTOCS_TOP_CON1 */
#define CRU_AUTOCS_TOP_CON1_OFFSET                         (0x51CU)
#define CRU_AUTOCS_TOP_CON1_SWITCH_EN_SHIFT                (0U)
#define CRU_AUTOCS_TOP_CON1_SWITCH_EN_MASK                 (0x1U << CRU_AUTOCS_TOP_CON1_SWITCH_EN_SHIFT)                /* 0x00000001 */
#define CRU_AUTOCS_TOP_CON1_ACLK_EN_SHIFT                  (1U)
#define CRU_AUTOCS_TOP_CON1_ACLK_EN_MASK                   (0x1U << CRU_AUTOCS_TOP_CON1_ACLK_EN_SHIFT)                  /* 0x00000002 */
#define CRU_AUTOCS_TOP_CON1_HCLK_EN_SHIFT                  (2U)
#define CRU_AUTOCS_TOP_CON1_HCLK_EN_MASK                   (0x1U << CRU_AUTOCS_TOP_CON1_HCLK_EN_SHIFT)                  /* 0x00000004 */
#define CRU_AUTOCS_TOP_CON1_PCLK_EN_SHIFT                  (3U)
#define CRU_AUTOCS_TOP_CON1_PCLK_EN_MASK                   (0x1U << CRU_AUTOCS_TOP_CON1_PCLK_EN_SHIFT)                  /* 0x00000008 */
#define CRU_AUTOCS_TOP_CON1_MASTER_EN_SHIFT                (4U)
#define CRU_AUTOCS_TOP_CON1_MASTER_EN_MASK                 (0x1U << CRU_AUTOCS_TOP_CON1_MASTER_EN_SHIFT)                /* 0x00000010 */
#define CRU_AUTOCS_TOP_CON1_SLAVE_EN_SHIFT                 (5U)
#define CRU_AUTOCS_TOP_CON1_SLAVE_EN_MASK                  (0x1U << CRU_AUTOCS_TOP_CON1_SLAVE_EN_SHIFT)                 /* 0x00000020 */
#define CRU_AUTOCS_TOP_CON1_DMAC_M_EN_SHIFT                (7U)
#define CRU_AUTOCS_TOP_CON1_DMAC_M_EN_MASK                 (0x1U << CRU_AUTOCS_TOP_CON1_DMAC_M_EN_SHIFT)                /* 0x00000080 */
#define CRU_AUTOCS_TOP_CON1_CLKSEL_CFG_SHIFT               (14U)
#define CRU_AUTOCS_TOP_CON1_CLKSEL_CFG_MASK                (0x3U << CRU_AUTOCS_TOP_CON1_CLKSEL_CFG_SHIFT)               /* 0x0000C000 */
/* AUTOCS_RKVDEC_CON0 */
#define CRU_AUTOCS_RKVDEC_CON0_OFFSET                      (0x520U)
#define CRU_AUTOCS_RKVDEC_CON0_IDLE_TH_SHIFT               (0U)
#define CRU_AUTOCS_RKVDEC_CON0_IDLE_TH_MASK                (0xFFFFU << CRU_AUTOCS_RKVDEC_CON0_IDLE_TH_SHIFT)            /* 0x0000FFFF */
#define CRU_AUTOCS_RKVDEC_CON0_WAIT_TH_SHIFT               (16U)
#define CRU_AUTOCS_RKVDEC_CON0_WAIT_TH_MASK                (0xFFFFU << CRU_AUTOCS_RKVDEC_CON0_WAIT_TH_SHIFT)            /* 0xFFFF0000 */
/* AUTOCS_RKVDEC_CON1 */
#define CRU_AUTOCS_RKVDEC_CON1_OFFSET                      (0x524U)
#define CRU_AUTOCS_RKVDEC_CON1_SWITCH_EN_SHIFT             (0U)
#define CRU_AUTOCS_RKVDEC_CON1_SWITCH_EN_MASK              (0x1U << CRU_AUTOCS_RKVDEC_CON1_SWITCH_EN_SHIFT)             /* 0x00000001 */
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_ACLK_EN_SHIFT        (1U)
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_ACLK_EN_MASK         (0x1U << CRU_AUTOCS_RKVDEC_CON1_RKVDEC_ACLK_EN_SHIFT)        /* 0x00000002 */
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CA_EN_SHIFT      (2U)
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CA_EN_MASK       (0x1U << CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CA_EN_SHIFT)      /* 0x00000004 */
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CORE_EN_SHIFT    (3U)
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CORE_EN_MASK     (0x1U << CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_CORE_EN_SHIFT)    /* 0x00000008 */
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_HEVC_EN_SHIFT    (4U)
#define CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_HEVC_EN_MASK     (0x1U << CRU_AUTOCS_RKVDEC_CON1_RKVDEC_CLK_HEVC_EN_SHIFT)    /* 0x00000010 */
#define CRU_AUTOCS_RKVDEC_CON1_CLK_CA_SEL_CFG_SHIFT        (8U)
#define CRU_AUTOCS_RKVDEC_CON1_CLK_CA_SEL_CFG_MASK         (0x3U << CRU_AUTOCS_RKVDEC_CON1_CLK_CA_SEL_CFG_SHIFT)        /* 0x00000300 */
#define CRU_AUTOCS_RKVDEC_CON1_CLK_CORE_SEL_CFG_SHIFT      (10U)
#define CRU_AUTOCS_RKVDEC_CON1_CLK_CORE_SEL_CFG_MASK       (0x3U << CRU_AUTOCS_RKVDEC_CON1_CLK_CORE_SEL_CFG_SHIFT)      /* 0x00000C00 */
#define CRU_AUTOCS_RKVDEC_CON1_CLK_HEVC_SEL_CFG_SHIFT      (12U)
#define CRU_AUTOCS_RKVDEC_CON1_CLK_HEVC_SEL_CFG_MASK       (0x3U << CRU_AUTOCS_RKVDEC_CON1_CLK_HEVC_SEL_CFG_SHIFT)      /* 0x00003000 */
#define CRU_AUTOCS_RKVDEC_CON1_ACLKSEL_CFG_SHIFT           (14U)
#define CRU_AUTOCS_RKVDEC_CON1_ACLKSEL_CFG_MASK            (0x3U << CRU_AUTOCS_RKVDEC_CON1_ACLKSEL_CFG_SHIFT)           /* 0x0000C000 */
/* AUTOCS_RKVENC_CON0 */
#define CRU_AUTOCS_RKVENC_CON0_OFFSET                      (0x528U)
#define CRU_AUTOCS_RKVENC_CON0_IDLE_TH_SHIFT               (0U)
#define CRU_AUTOCS_RKVENC_CON0_IDLE_TH_MASK                (0xFFFFU << CRU_AUTOCS_RKVENC_CON0_IDLE_TH_SHIFT)            /* 0x0000FFFF */
#define CRU_AUTOCS_RKVENC_CON0_WAIT_TH_SHIFT               (16U)
#define CRU_AUTOCS_RKVENC_CON0_WAIT_TH_MASK                (0xFFFFU << CRU_AUTOCS_RKVENC_CON0_WAIT_TH_SHIFT)            /* 0xFFFF0000 */
/* AUTOCS_RKVENC_CON1 */
#define CRU_AUTOCS_RKVENC_CON1_OFFSET                      (0x52CU)
#define CRU_AUTOCS_RKVENC_CON1_SWITCH_EN_SHIFT             (0U)
#define CRU_AUTOCS_RKVENC_CON1_SWITCH_EN_MASK              (0x1U << CRU_AUTOCS_RKVENC_CON1_SWITCH_EN_SHIFT)             /* 0x00000001 */
#define CRU_AUTOCS_RKVENC_CON1_CLK_EN_SHIFT                (1U)
#define CRU_AUTOCS_RKVENC_CON1_CLK_EN_MASK                 (0x1U << CRU_AUTOCS_RKVENC_CON1_CLK_EN_SHIFT)                /* 0x00000002 */
#define CRU_AUTOCS_RKVENC_CON1_CLKSEL_CFG_SHIFT            (14U)
#define CRU_AUTOCS_RKVENC_CON1_CLKSEL_CFG_MASK             (0x3U << CRU_AUTOCS_RKVENC_CON1_CLKSEL_CFG_SHIFT)            /* 0x0000C000 */
/* AUTOCS_VPU_CON0 */
#define CRU_AUTOCS_VPU_CON0_OFFSET                         (0x530U)
#define CRU_AUTOCS_VPU_CON0_IDLE_TH_SHIFT                  (0U)
#define CRU_AUTOCS_VPU_CON0_IDLE_TH_MASK                   (0xFFFFU << CRU_AUTOCS_VPU_CON0_IDLE_TH_SHIFT)               /* 0x0000FFFF */
#define CRU_AUTOCS_VPU_CON0_WAIT_TH_SHIFT                  (16U)
#define CRU_AUTOCS_VPU_CON0_WAIT_TH_MASK                   (0xFFFFU << CRU_AUTOCS_VPU_CON0_WAIT_TH_SHIFT)               /* 0xFFFF0000 */
/* AUTOCS_VPU_CON1 */
#define CRU_AUTOCS_VPU_CON1_OFFSET                         (0x534U)
#define CRU_AUTOCS_VPU_CON1_SWITCH_EN_SHIFT                (0U)
#define CRU_AUTOCS_VPU_CON1_SWITCH_EN_MASK                 (0x1U << CRU_AUTOCS_VPU_CON1_SWITCH_EN_SHIFT)                /* 0x00000001 */
#define CRU_AUTOCS_VPU_CON1_CLK_EN_SHIFT                   (1U)
#define CRU_AUTOCS_VPU_CON1_CLK_EN_MASK                    (0x1U << CRU_AUTOCS_VPU_CON1_CLK_EN_SHIFT)                   /* 0x00000002 */
#define CRU_AUTOCS_VPU_CON1_CLKSEL_CFG_SHIFT               (14U)
#define CRU_AUTOCS_VPU_CON1_CLKSEL_CFG_MASK                (0x3U << CRU_AUTOCS_VPU_CON1_CLKSEL_CFG_SHIFT)               /* 0x0000C000 */
/* AUTOCS_PERI_CON0 */
#define CRU_AUTOCS_PERI_CON0_OFFSET                        (0x538U)
#define CRU_AUTOCS_PERI_CON0_IDLE_TH_SHIFT                 (0U)
#define CRU_AUTOCS_PERI_CON0_IDLE_TH_MASK                  (0xFFFFU << CRU_AUTOCS_PERI_CON0_IDLE_TH_SHIFT)              /* 0x0000FFFF */
#define CRU_AUTOCS_PERI_CON0_WAIT_TH_SHIFT                 (16U)
#define CRU_AUTOCS_PERI_CON0_WAIT_TH_MASK                  (0xFFFFU << CRU_AUTOCS_PERI_CON0_WAIT_TH_SHIFT)              /* 0xFFFF0000 */
/* AUTOCS_PERI_CON1 */
#define CRU_AUTOCS_PERI_CON1_OFFSET                        (0x53CU)
#define CRU_AUTOCS_PERI_CON1_PERI_SWITCH_EN_SHIFT          (0U)
#define CRU_AUTOCS_PERI_CON1_PERI_SWITCH_EN_MASK           (0x1U << CRU_AUTOCS_PERI_CON1_PERI_SWITCH_EN_SHIFT)          /* 0x00000001 */
#define CRU_AUTOCS_PERI_CON1_PERI_ACLK_EN_SHIFT            (1U)
#define CRU_AUTOCS_PERI_CON1_PERI_ACLK_EN_MASK             (0x1U << CRU_AUTOCS_PERI_CON1_PERI_ACLK_EN_SHIFT)            /* 0x00000002 */
#define CRU_AUTOCS_PERI_CON1_PERI_HCLK_EN_SHIFT            (2U)
#define CRU_AUTOCS_PERI_CON1_PERI_HCLK_EN_MASK             (0x1U << CRU_AUTOCS_PERI_CON1_PERI_HCLK_EN_SHIFT)            /* 0x00000004 */
#define CRU_AUTOCS_PERI_CON1_PHP_SWITCH_EN_SHIFT           (3U)
#define CRU_AUTOCS_PERI_CON1_PHP_SWITCH_EN_MASK            (0x1U << CRU_AUTOCS_PERI_CON1_PHP_SWITCH_EN_SHIFT)           /* 0x00000008 */
#define CRU_AUTOCS_PERI_CON1_PHP_ACLK_EN_SHIFT             (4U)
#define CRU_AUTOCS_PERI_CON1_PHP_ACLK_EN_MASK              (0x1U << CRU_AUTOCS_PERI_CON1_PHP_ACLK_EN_SHIFT)             /* 0x00000010 */
#define CRU_AUTOCS_PERI_CON1_PHP_HCLK_EN_SHIFT             (5U)
#define CRU_AUTOCS_PERI_CON1_PHP_HCLK_EN_MASK              (0x1U << CRU_AUTOCS_PERI_CON1_PHP_HCLK_EN_SHIFT)             /* 0x00000020 */
#define CRU_AUTOCS_PERI_CON1_GA_SWITCH_EN_SHIFT            (6U)
#define CRU_AUTOCS_PERI_CON1_GA_SWITCH_EN_MASK             (0x1U << CRU_AUTOCS_PERI_CON1_GA_SWITCH_EN_SHIFT)            /* 0x00000040 */
#define CRU_AUTOCS_PERI_CON1_GA_ACLK_EN_SHIFT              (7U)
#define CRU_AUTOCS_PERI_CON1_GA_ACLK_EN_MASK               (0x1U << CRU_AUTOCS_PERI_CON1_GA_ACLK_EN_SHIFT)              /* 0x00000080 */
#define CRU_AUTOCS_PERI_CON1_GA_HCLK_EN_SHIFT              (8U)
#define CRU_AUTOCS_PERI_CON1_GA_HCLK_EN_MASK               (0x1U << CRU_AUTOCS_PERI_CON1_GA_HCLK_EN_SHIFT)              /* 0x00000100 */
#define CRU_AUTOCS_PERI_CON1_SF_SWITCH_EN_SHIFT            (9U)
#define CRU_AUTOCS_PERI_CON1_SF_SWITCH_EN_MASK             (0x1U << CRU_AUTOCS_PERI_CON1_SF_SWITCH_EN_SHIFT)            /* 0x00000200 */
#define CRU_AUTOCS_PERI_CON1_SF_ACLK_EN_SHIFT              (10U)
#define CRU_AUTOCS_PERI_CON1_SF_ACLK_EN_MASK               (0x1U << CRU_AUTOCS_PERI_CON1_SF_ACLK_EN_SHIFT)              /* 0x00000400 */
#define CRU_AUTOCS_PERI_CON1_SF_HCLK_EN_SHIFT              (11U)
#define CRU_AUTOCS_PERI_CON1_SF_HCLK_EN_MASK               (0x1U << CRU_AUTOCS_PERI_CON1_SF_HCLK_EN_SHIFT)              /* 0x00000800 */
#define CRU_AUTOCS_PERI_CON1_DCF_M_EN_SHIFT                (12U)
#define CRU_AUTOCS_PERI_CON1_DCF_M_EN_MASK                 (0x1U << CRU_AUTOCS_PERI_CON1_DCF_M_EN_SHIFT)                /* 0x00001000 */
#define CRU_AUTOCS_PERI_CON1_CLKSEL_CFG_SHIFT              (14U)
#define CRU_AUTOCS_PERI_CON1_CLKSEL_CFG_MASK               (0x3U << CRU_AUTOCS_PERI_CON1_CLKSEL_CFG_SHIFT)              /* 0x0000C000 */
/* AUTOCS_GPLL_CON0 */
#define CRU_AUTOCS_GPLL_CON0_OFFSET                        (0x540U)
#define CRU_AUTOCS_GPLL_CON0_IDLE_TH_SHIFT                 (0U)
#define CRU_AUTOCS_GPLL_CON0_IDLE_TH_MASK                  (0xFFFFU << CRU_AUTOCS_GPLL_CON0_IDLE_TH_SHIFT)              /* 0x0000FFFF */
#define CRU_AUTOCS_GPLL_CON0_WAIT_TH_SHIFT                 (16U)
#define CRU_AUTOCS_GPLL_CON0_WAIT_TH_MASK                  (0xFFFFU << CRU_AUTOCS_GPLL_CON0_WAIT_TH_SHIFT)              /* 0xFFFF0000 */
/* AUTOCS_GPLL_CON1 */
#define CRU_AUTOCS_GPLL_CON1_OFFSET                        (0x544U)
#define CRU_AUTOCS_GPLL_CON1_SWITCH_EN_SHIFT               (0U)
#define CRU_AUTOCS_GPLL_CON1_SWITCH_EN_MASK                (0x1U << CRU_AUTOCS_GPLL_CON1_SWITCH_EN_SHIFT)               /* 0x00000001 */
#define CRU_AUTOCS_GPLL_CON1_WFI_EN_SHIFT                  (2U)
#define CRU_AUTOCS_GPLL_CON1_WFI_EN_MASK                   (0x1U << CRU_AUTOCS_GPLL_CON1_WFI_EN_SHIFT)                  /* 0x00000004 */
#define CRU_AUTOCS_GPLL_CON1_WFIL3_EN_SHIFT                (3U)
#define CRU_AUTOCS_GPLL_CON1_WFIL3_EN_MASK                 (0x1U << CRU_AUTOCS_GPLL_CON1_WFIL3_EN_SHIFT)                /* 0x00000008 */
#define CRU_AUTOCS_GPLL_CON1_FIQIRQ_EN_SHIFT               (4U)
#define CRU_AUTOCS_GPLL_CON1_FIQIRQ_EN_MASK                (0x1U << CRU_AUTOCS_GPLL_CON1_FIQIRQ_EN_SHIFT)               /* 0x00000010 */
#define CRU_AUTOCS_GPLL_CON1_VFIQIRQ_EN_SHIFT              (5U)
#define CRU_AUTOCS_GPLL_CON1_VFIQIRQ_EN_MASK               (0x1U << CRU_AUTOCS_GPLL_CON1_VFIQIRQ_EN_SHIFT)              /* 0x00000020 */
/* AUTOCS_CPLL_CON0 */
#define CRU_AUTOCS_CPLL_CON0_OFFSET                        (0x548U)
#define CRU_AUTOCS_CPLL_CON0_IDLE_TH_SHIFT                 (0U)
#define CRU_AUTOCS_CPLL_CON0_IDLE_TH_MASK                  (0xFFFFU << CRU_AUTOCS_CPLL_CON0_IDLE_TH_SHIFT)              /* 0x0000FFFF */
#define CRU_AUTOCS_CPLL_CON0_WAIT_TH_SHIFT                 (16U)
#define CRU_AUTOCS_CPLL_CON0_WAIT_TH_MASK                  (0xFFFFU << CRU_AUTOCS_CPLL_CON0_WAIT_TH_SHIFT)              /* 0xFFFF0000 */
/* AUTOCS_CPLL_CON1 */
#define CRU_AUTOCS_CPLL_CON1_OFFSET                        (0x54CU)
#define CRU_AUTOCS_CPLL_CON1_SWITCH_EN_SHIFT               (0U)
#define CRU_AUTOCS_CPLL_CON1_SWITCH_EN_MASK                (0x1U << CRU_AUTOCS_CPLL_CON1_SWITCH_EN_SHIFT)               /* 0x00000001 */
#define CRU_AUTOCS_CPLL_CON1_WFI_EN_SHIFT                  (2U)
#define CRU_AUTOCS_CPLL_CON1_WFI_EN_MASK                   (0x1U << CRU_AUTOCS_CPLL_CON1_WFI_EN_SHIFT)                  /* 0x00000004 */
#define CRU_AUTOCS_CPLL_CON1_WFIL3_EN_SHIFT                (3U)
#define CRU_AUTOCS_CPLL_CON1_WFIL3_EN_MASK                 (0x1U << CRU_AUTOCS_CPLL_CON1_WFIL3_EN_SHIFT)                /* 0x00000008 */
#define CRU_AUTOCS_CPLL_CON1_FIQIRQ_EN_SHIFT               (4U)
#define CRU_AUTOCS_CPLL_CON1_FIQIRQ_EN_MASK                (0x1U << CRU_AUTOCS_CPLL_CON1_FIQIRQ_EN_SHIFT)               /* 0x00000010 */
#define CRU_AUTOCS_CPLL_CON1_VFIQIRQ_EN_SHIFT              (5U)
#define CRU_AUTOCS_CPLL_CON1_VFIQIRQ_EN_MASK               (0x1U << CRU_AUTOCS_CPLL_CON1_VFIQIRQ_EN_SHIFT)              /* 0x00000020 */
/* SDMMC0_CON0 */
#define CRU_SDMMC0_CON0_OFFSET                             (0x580U)
#define CRU_SDMMC0_CON0_INIT_STATE_SHIFT                   (0U)
#define CRU_SDMMC0_CON0_INIT_STATE_MASK                    (0x1U << CRU_SDMMC0_CON0_INIT_STATE_SHIFT)                   /* 0x00000001 */
#define CRU_SDMMC0_CON0_DRV_DEGREE_SHIFT                   (1U)
#define CRU_SDMMC0_CON0_DRV_DEGREE_MASK                    (0x3U << CRU_SDMMC0_CON0_DRV_DEGREE_SHIFT)                   /* 0x00000006 */
#define CRU_SDMMC0_CON0_DRV_DELAYNUM_SHIFT                 (3U)
#define CRU_SDMMC0_CON0_DRV_DELAYNUM_MASK                  (0xFFU << CRU_SDMMC0_CON0_DRV_DELAYNUM_SHIFT)                /* 0x000007F8 */
#define CRU_SDMMC0_CON0_DRV_SEL_SHIFT                      (11U)
#define CRU_SDMMC0_CON0_DRV_SEL_MASK                       (0x1U << CRU_SDMMC0_CON0_DRV_SEL_SHIFT)                      /* 0x00000800 */
/* SDMMC0_CON1 */
#define CRU_SDMMC0_CON1_OFFSET                             (0x584U)
#define CRU_SDMMC0_CON1_SAMPLE_DEGREE_SHIFT                (0U)
#define CRU_SDMMC0_CON1_SAMPLE_DEGREE_MASK                 (0x3U << CRU_SDMMC0_CON1_SAMPLE_DEGREE_SHIFT)                /* 0x00000003 */
#define CRU_SDMMC0_CON1_SAMPLE_DELAYNUM_SHIFT              (2U)
#define CRU_SDMMC0_CON1_SAMPLE_DELAYNUM_MASK               (0xFFU << CRU_SDMMC0_CON1_SAMPLE_DELAYNUM_SHIFT)             /* 0x000003FC */
#define CRU_SDMMC0_CON1_SAMPLE_SEL_SHIFT                   (10U)
#define CRU_SDMMC0_CON1_SAMPLE_SEL_MASK                    (0x1U << CRU_SDMMC0_CON1_SAMPLE_SEL_SHIFT)                   /* 0x00000400 */
/* SDMMC1_CON0 */
#define CRU_SDMMC1_CON0_OFFSET                             (0x588U)
#define CRU_SDMMC1_CON0_INIT_STATE_SHIFT                   (0U)
#define CRU_SDMMC1_CON0_INIT_STATE_MASK                    (0x1U << CRU_SDMMC1_CON0_INIT_STATE_SHIFT)                   /* 0x00000001 */
#define CRU_SDMMC1_CON0_DRV_DEGREE_SHIFT                   (1U)
#define CRU_SDMMC1_CON0_DRV_DEGREE_MASK                    (0x3U << CRU_SDMMC1_CON0_DRV_DEGREE_SHIFT)                   /* 0x00000006 */
#define CRU_SDMMC1_CON0_DRV_DELAYNUM_SHIFT                 (3U)
#define CRU_SDMMC1_CON0_DRV_DELAYNUM_MASK                  (0xFFU << CRU_SDMMC1_CON0_DRV_DELAYNUM_SHIFT)                /* 0x000007F8 */
#define CRU_SDMMC1_CON0_DRV_SEL_SHIFT                      (11U)
#define CRU_SDMMC1_CON0_DRV_SEL_MASK                       (0x1U << CRU_SDMMC1_CON0_DRV_SEL_SHIFT)                      /* 0x00000800 */
/* SDMMC1_CON1 */
#define CRU_SDMMC1_CON1_OFFSET                             (0x58CU)
#define CRU_SDMMC1_CON1_SAMPLE_DEGREE_SHIFT                (0U)
#define CRU_SDMMC1_CON1_SAMPLE_DEGREE_MASK                 (0x3U << CRU_SDMMC1_CON1_SAMPLE_DEGREE_SHIFT)                /* 0x00000003 */
#define CRU_SDMMC1_CON1_SAMPLE_DELAYNUM_SHIFT              (2U)
#define CRU_SDMMC1_CON1_SAMPLE_DELAYNUM_MASK               (0xFFU << CRU_SDMMC1_CON1_SAMPLE_DELAYNUM_SHIFT)             /* 0x000003FC */
#define CRU_SDMMC1_CON1_SAMPLE_SEL_SHIFT                   (10U)
#define CRU_SDMMC1_CON1_SAMPLE_SEL_MASK                    (0x1U << CRU_SDMMC1_CON1_SAMPLE_SEL_SHIFT)                   /* 0x00000400 */
/* SDMMC2_CON0 */
#define CRU_SDMMC2_CON0_OFFSET                             (0x590U)
#define CRU_SDMMC2_CON0_INIT_STATE_SHIFT                   (0U)
#define CRU_SDMMC2_CON0_INIT_STATE_MASK                    (0x1U << CRU_SDMMC2_CON0_INIT_STATE_SHIFT)                   /* 0x00000001 */
#define CRU_SDMMC2_CON0_DRV_DEGREE_SHIFT                   (1U)
#define CRU_SDMMC2_CON0_DRV_DEGREE_MASK                    (0x3U << CRU_SDMMC2_CON0_DRV_DEGREE_SHIFT)                   /* 0x00000006 */
#define CRU_SDMMC2_CON0_DRV_DELAYNUM_SHIFT                 (3U)
#define CRU_SDMMC2_CON0_DRV_DELAYNUM_MASK                  (0xFFU << CRU_SDMMC2_CON0_DRV_DELAYNUM_SHIFT)                /* 0x000007F8 */
#define CRU_SDMMC2_CON0_DRV_SEL_SHIFT                      (11U)
#define CRU_SDMMC2_CON0_DRV_SEL_MASK                       (0x1U << CRU_SDMMC2_CON0_DRV_SEL_SHIFT)                      /* 0x00000800 */
/* SDMMC2_CON1 */
#define CRU_SDMMC2_CON1_OFFSET                             (0x594U)
#define CRU_SDMMC2_CON1_SAMPLE_DEGREE_SHIFT                (0U)
#define CRU_SDMMC2_CON1_SAMPLE_DEGREE_MASK                 (0x3U << CRU_SDMMC2_CON1_SAMPLE_DEGREE_SHIFT)                /* 0x00000003 */
#define CRU_SDMMC2_CON1_SAMPLE_DELAYNUM_SHIFT              (2U)
#define CRU_SDMMC2_CON1_SAMPLE_DELAYNUM_MASK               (0xFFU << CRU_SDMMC2_CON1_SAMPLE_DELAYNUM_SHIFT)             /* 0x000003FC */
#define CRU_SDMMC2_CON1_SAMPLE_SEL_SHIFT                   (10U)
#define CRU_SDMMC2_CON1_SAMPLE_SEL_MASK                    (0x1U << CRU_SDMMC2_CON1_SAMPLE_SEL_SHIFT)                   /* 0x00000400 */
/* EMMC_CON0 */
#define CRU_EMMC_CON0_OFFSET                               (0x598U)
#define CRU_EMMC_CON0_INIT_STATE_SHIFT                     (0U)
#define CRU_EMMC_CON0_INIT_STATE_MASK                      (0x1U << CRU_EMMC_CON0_INIT_STATE_SHIFT)                     /* 0x00000001 */
#define CRU_EMMC_CON0_DRV_DEGREE_SHIFT                     (1U)
#define CRU_EMMC_CON0_DRV_DEGREE_MASK                      (0x3U << CRU_EMMC_CON0_DRV_DEGREE_SHIFT)                     /* 0x00000006 */
#define CRU_EMMC_CON0_DRV_DELAYNUM_SHIFT                   (3U)
#define CRU_EMMC_CON0_DRV_DELAYNUM_MASK                    (0xFFU << CRU_EMMC_CON0_DRV_DELAYNUM_SHIFT)                  /* 0x000007F8 */
#define CRU_EMMC_CON0_DRV_SEL_SHIFT                        (11U)
#define CRU_EMMC_CON0_DRV_SEL_MASK                         (0x1U << CRU_EMMC_CON0_DRV_SEL_SHIFT)                        /* 0x00000800 */
/* EMMC_CON1 */
#define CRU_EMMC_CON1_OFFSET                               (0x59CU)
#define CRU_EMMC_CON1_SAMPLE_DEGREE_SHIFT                  (0U)
#define CRU_EMMC_CON1_SAMPLE_DEGREE_MASK                   (0x3U << CRU_EMMC_CON1_SAMPLE_DEGREE_SHIFT)                  /* 0x00000003 */
#define CRU_EMMC_CON1_SAMPLE_DELAYNUM_SHIFT                (2U)
#define CRU_EMMC_CON1_SAMPLE_DELAYNUM_MASK                 (0xFFU << CRU_EMMC_CON1_SAMPLE_DELAYNUM_SHIFT)               /* 0x000003FC */
#define CRU_EMMC_CON1_SAMPLE_SEL_SHIFT                     (10U)
#define CRU_EMMC_CON1_SAMPLE_SEL_MASK                      (0x1U << CRU_EMMC_CON1_SAMPLE_SEL_SHIFT)                     /* 0x00000400 */
/******************************************PMU*******************************************/
/* VERSION */
#define PMU_VERSION_OFFSET                                 (0x0U)
#define PMU_VERSION                                        (0x3003566U)
#define PMU_VERSION_VERSION_SHIFT                          (0U)
#define PMU_VERSION_VERSION_MASK                           (0xFFFFFFFFU << PMU_VERSION_VERSION_SHIFT)                   /* 0xFFFFFFFF */
/* PWR_CON */
#define PMU_PWR_CON_OFFSET                                 (0x4U)
#define PMU_PWR_CON_POWERMODE_EN_SHIFT                     (0U)
#define PMU_PWR_CON_POWERMODE_EN_MASK                      (0x1U << PMU_PWR_CON_POWERMODE_EN_SHIFT)                     /* 0x00000001 */
#define PMU_PWR_CON_DSU_BYPASS_SHIFT                       (1U)
#define PMU_PWR_CON_DSU_BYPASS_MASK                        (0x1U << PMU_PWR_CON_DSU_BYPASS_SHIFT)                       /* 0x00000002 */
#define PMU_PWR_CON_RESERVED_SHIFT                         (2U)
#define PMU_PWR_CON_RESERVED_MASK                          (0x3U << PMU_PWR_CON_RESERVED_SHIFT)                         /* 0x0000000C */
#define PMU_PWR_CON_BUS_BYPASS_SHIFT                       (4U)
#define PMU_PWR_CON_BUS_BYPASS_MASK                        (0x1U << PMU_PWR_CON_BUS_BYPASS_SHIFT)                       /* 0x00000010 */
#define PMU_PWR_CON_DDR_BYPASS_SHIFT                       (5U)
#define PMU_PWR_CON_DDR_BYPASS_MASK                        (0x1U << PMU_PWR_CON_DDR_BYPASS_SHIFT)                       /* 0x00000020 */
#define PMU_PWR_CON_PWRDN_BYPASS_SHIFT                     (6U)
#define PMU_PWR_CON_PWRDN_BYPASS_MASK                      (0x1U << PMU_PWR_CON_PWRDN_BYPASS_SHIFT)                     /* 0x00000040 */
#define PMU_PWR_CON_CRU_BYPASS_SHIFT                       (7U)
#define PMU_PWR_CON_CRU_BYPASS_MASK                        (0x1U << PMU_PWR_CON_CRU_BYPASS_SHIFT)                       /* 0x00000080 */
#define PMU_PWR_CON_CPU_BYPASS_SHIFT                       (8U)
#define PMU_PWR_CON_CPU_BYPASS_MASK                        (0xFU << PMU_PWR_CON_CPU_BYPASS_SHIFT)                       /* 0x00000F00 */
#define PMU_PWR_CON_PMU_SLEEP_POL_SHIFT                    (15U)
#define PMU_PWR_CON_PMU_SLEEP_POL_MASK                     (0x1U << PMU_PWR_CON_PMU_SLEEP_POL_SHIFT)                    /* 0x00008000 */
/* MAIN_PWR_STATE */
#define PMU_MAIN_PWR_STATE_OFFSET                          (0x8U)
#define PMU_MAIN_PWR_STATE                                 (0x0U)
#define PMU_MAIN_PWR_STATE_PMU_POWER_STATE_SHIFT           (0U)
#define PMU_MAIN_PWR_STATE_PMU_POWER_STATE_MASK            (0xFU << PMU_MAIN_PWR_STATE_PMU_POWER_STATE_SHIFT)           /* 0x0000000F */
/* INT_MASK_CON */
#define PMU_INT_MASK_CON_OFFSET                            (0xCU)
#define PMU_INT_MASK_CON_GLB_INT_DISABLE_SHIFT             (0U)
#define PMU_INT_MASK_CON_GLB_INT_DISABLE_MASK              (0x1U << PMU_INT_MASK_CON_GLB_INT_DISABLE_SHIFT)             /* 0x00000001 */
#define PMU_INT_MASK_CON_WAKEUP_MCU_SFT_SHIFT              (15U)
#define PMU_INT_MASK_CON_WAKEUP_MCU_SFT_MASK               (0x1U << PMU_INT_MASK_CON_WAKEUP_MCU_SFT_SHIFT)              /* 0x00008000 */
/* WAKEUP_INT_CON */
#define PMU_WAKEUP_INT_CON_OFFSET                          (0x10U)
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU0_INT_EN_SHIFT        (0U)
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU0_INT_EN_MASK         (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_CPU0_INT_EN_SHIFT)        /* 0x00000001 */
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU1_INT_EN_SHIFT        (1U)
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU1_INT_EN_MASK         (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_CPU1_INT_EN_SHIFT)        /* 0x00000002 */
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU2_INT_EN_SHIFT        (2U)
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU2_INT_EN_MASK         (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_CPU2_INT_EN_SHIFT)        /* 0x00000004 */
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU3_INT_EN_SHIFT        (3U)
#define PMU_WAKEUP_INT_CON_WAKEUP_CPU3_INT_EN_MASK         (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_CPU3_INT_EN_SHIFT)        /* 0x00000008 */
#define PMU_WAKEUP_INT_CON_WAKEUP_GPIO0_INT_EN_SHIFT       (4U)
#define PMU_WAKEUP_INT_CON_WAKEUP_GPIO0_INT_EN_MASK        (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_GPIO0_INT_EN_SHIFT)       /* 0x00000010 */
#define PMU_WAKEUP_INT_CON_WAKEUP_UART0_EN_SHIFT           (5U)
#define PMU_WAKEUP_INT_CON_WAKEUP_UART0_EN_MASK            (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_UART0_EN_SHIFT)           /* 0x00000020 */
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC0_EN_SHIFT          (6U)
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC0_EN_MASK           (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_SDMMC0_EN_SHIFT)          /* 0x00000040 */
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC1_EN_SHIFT          (7U)
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC1_EN_MASK           (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_SDMMC1_EN_SHIFT)          /* 0x00000080 */
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC2_EN_SHIFT          (8U)
#define PMU_WAKEUP_INT_CON_WAKEUP_SDMMC2_EN_MASK           (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_SDMMC2_EN_SHIFT)          /* 0x00000100 */
#define PMU_WAKEUP_INT_CON_WAKEUP_USB_EN_SHIFT             (9U)
#define PMU_WAKEUP_INT_CON_WAKEUP_USB_EN_MASK              (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_USB_EN_SHIFT)             /* 0x00000200 */
#define PMU_WAKEUP_INT_CON_WAKEUP_PCIE_EN_SHIFT            (10U)
#define PMU_WAKEUP_INT_CON_WAKEUP_PCIE_EN_MASK             (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_PCIE_EN_SHIFT)            /* 0x00000400 */
#define PMU_WAKEUP_INT_CON_WAKEUP_VAD_EN_SHIFT             (11U)
#define PMU_WAKEUP_INT_CON_WAKEUP_VAD_EN_MASK              (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_VAD_EN_SHIFT)             /* 0x00000800 */
#define PMU_WAKEUP_INT_CON_WAKEUP_TIMER_EN_SHIFT           (12U)
#define PMU_WAKEUP_INT_CON_WAKEUP_TIMER_EN_MASK            (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_TIMER_EN_SHIFT)           /* 0x00001000 */
#define PMU_WAKEUP_INT_CON_WAKEUP_PWM0_EN_SHIFT            (13U)
#define PMU_WAKEUP_INT_CON_WAKEUP_PWM0_EN_MASK             (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_PWM0_EN_SHIFT)            /* 0x00002000 */
#define PMU_WAKEUP_INT_CON_WAKEUP_TIMEOUT_EN_SHIFT         (14U)
#define PMU_WAKEUP_INT_CON_WAKEUP_TIMEOUT_EN_MASK          (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_TIMEOUT_EN_SHIFT)         /* 0x00004000 */
#define PMU_WAKEUP_INT_CON_WAKEUP_MCU_SFT_EN_SHIFT         (15U)
#define PMU_WAKEUP_INT_CON_WAKEUP_MCU_SFT_EN_MASK          (0x1U << PMU_WAKEUP_INT_CON_WAKEUP_MCU_SFT_EN_SHIFT)         /* 0x00008000 */
/* WAKEUP_INT_ST */
#define PMU_WAKEUP_INT_ST_OFFSET                           (0x14U)
#define PMU_WAKEUP_INT_ST                                  (0x0U)
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU0_INT_ST_SHIFT         (0U)
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU0_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_CPU0_INT_ST_SHIFT)         /* 0x00000001 */
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU1_INT_ST_SHIFT         (1U)
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU1_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_CPU1_INT_ST_SHIFT)         /* 0x00000002 */
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU2_INT_ST_SHIFT         (2U)
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU2_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_CPU2_INT_ST_SHIFT)         /* 0x00000004 */
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU3_INT_ST_SHIFT         (3U)
#define PMU_WAKEUP_INT_ST_WAKEUP_CPU3_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_CPU3_INT_ST_SHIFT)         /* 0x00000008 */
#define PMU_WAKEUP_INT_ST_WAKEUP_GPIO0_INT_ST_SHIFT        (4U)
#define PMU_WAKEUP_INT_ST_WAKEUP_GPIO0_INT_ST_MASK         (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_GPIO0_INT_ST_SHIFT)        /* 0x00000010 */
#define PMU_WAKEUP_INT_ST_WAKEUP_UART0_INT_ST_SHIFT        (5U)
#define PMU_WAKEUP_INT_ST_WAKEUP_UART0_INT_ST_MASK         (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_UART0_INT_ST_SHIFT)        /* 0x00000020 */
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC0_INT_ST_SHIFT       (6U)
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC0_INT_ST_MASK        (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_SDMMC0_INT_ST_SHIFT)       /* 0x00000040 */
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC1_INT_ST_SHIFT       (7U)
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC1_INT_ST_MASK        (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_SDMMC1_INT_ST_SHIFT)       /* 0x00000080 */
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC2_INT_ST_SHIFT       (8U)
#define PMU_WAKEUP_INT_ST_WAKEUP_SDMMC2_INT_ST_MASK        (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_SDMMC2_INT_ST_SHIFT)       /* 0x00000100 */
#define PMU_WAKEUP_INT_ST_WAKEUP_USB_INT_ST_SHIFT          (9U)
#define PMU_WAKEUP_INT_ST_WAKEUP_USB_INT_ST_MASK           (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_USB_INT_ST_SHIFT)          /* 0x00000200 */
#define PMU_WAKEUP_INT_ST_WAKEUP_PCIE_INT_ST_SHIFT         (10U)
#define PMU_WAKEUP_INT_ST_WAKEUP_PCIE_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_PCIE_INT_ST_SHIFT)         /* 0x00000400 */
#define PMU_WAKEUP_INT_ST_WAKEUP_VAD_INT_ST_SHIFT          (11U)
#define PMU_WAKEUP_INT_ST_WAKEUP_VAD_INT_ST_MASK           (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_VAD_INT_ST_SHIFT)          /* 0x00000800 */
#define PMU_WAKEUP_INT_ST_WAKEUP_TIMER_INT_ST_SHIFT        (12U)
#define PMU_WAKEUP_INT_ST_WAKEUP_TIMER_INT_ST_MASK         (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_TIMER_INT_ST_SHIFT)        /* 0x00001000 */
#define PMU_WAKEUP_INT_ST_WAKEUP_PWM0_INT_ST_SHIFT         (13U)
#define PMU_WAKEUP_INT_ST_WAKEUP_PWM0_INT_ST_MASK          (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_PWM0_INT_ST_SHIFT)         /* 0x00002000 */
#define PMU_WAKEUP_INT_ST_WAKEUP_TIMEOUT_INT_ST_SHIFT      (14U)
#define PMU_WAKEUP_INT_ST_WAKEUP_TIMEOUT_INT_ST_MASK       (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_TIMEOUT_INT_ST_SHIFT)      /* 0x00004000 */
#define PMU_WAKEUP_INT_ST_WAKEUP_SYS_INT_ST_SHIFT          (15U)
#define PMU_WAKEUP_INT_ST_WAKEUP_SYS_INT_ST_MASK           (0x1U << PMU_WAKEUP_INT_ST_WAKEUP_SYS_INT_ST_SHIFT)          /* 0x00008000 */
/* WAKEUP_EDGE_CON */
#define PMU_WAKEUP_EDGE_CON_OFFSET                         (0x18U)
#define PMU_WAKEUP_EDGE_CON_EDGE_WAKEUP_EN_SHIFT           (0U)
#define PMU_WAKEUP_EDGE_CON_EDGE_WAKEUP_EN_MASK            (0xFFFFFFFFU << PMU_WAKEUP_EDGE_CON_EDGE_WAKEUP_EN_SHIFT)    /* 0xFFFFFFFF */
/* WAKEUP_EDGE_ST */
#define PMU_WAKEUP_EDGE_ST_OFFSET                          (0x1CU)
#define PMU_WAKEUP_EDGE_ST_EDGE_STATUS_SHIFT               (0U)
#define PMU_WAKEUP_EDGE_ST_EDGE_STATUS_MASK                (0xFFFFFFFFU << PMU_WAKEUP_EDGE_ST_EDGE_STATUS_SHIFT)        /* 0xFFFFFFFF */
/* BUS_IDLE_CON0 */
#define PMU_BUS_IDLE_CON0_OFFSET                           (0x40U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_MSCH_SHIFT              (0U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_MSCH_MASK               (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_MSCH_SHIFT)              /* 0x00000001 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_GPU_SHIFT               (1U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_GPU_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_GPU_SHIFT)               /* 0x00000002 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_NPU_SHIFT               (2U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_NPU_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_NPU_SHIFT)               /* 0x00000004 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VI_SHIFT                (3U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VI_MASK                 (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_VI_SHIFT)                /* 0x00000008 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VO_SHIFT                (4U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VO_MASK                 (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_VO_SHIFT)                /* 0x00000010 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RGA_SHIFT               (5U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RGA_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_RGA_SHIFT)               /* 0x00000020 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VPU_SHIFT               (6U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_VPU_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_VPU_SHIFT)               /* 0x00000040 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RKVENC_SHIFT            (7U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RKVENC_MASK             (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_RKVENC_SHIFT)            /* 0x00000080 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RKVDEC_SHIFT            (8U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_RKVDEC_MASK             (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_RKVDEC_SHIFT)            /* 0x00000100 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_GIC_AUDIO_SHIFT         (9U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_GIC_AUDIO_MASK          (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_GIC_AUDIO_SHIFT)         /* 0x00000200 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PHP_SHIFT               (10U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PHP_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_PHP_SHIFT)               /* 0x00000400 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PIPE_SHIFT              (11U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PIPE_MASK               (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_PIPE_SHIFT)              /* 0x00000800 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_SECURE_FLASH_SHIFT      (12U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_SECURE_FLASH_MASK       (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_SECURE_FLASH_SHIFT)      /* 0x00001000 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PERIMID_SHIFT           (13U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_PERIMID_MASK            (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_PERIMID_SHIFT)           /* 0x00002000 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_USB_SHIFT               (14U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_USB_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_USB_SHIFT)               /* 0x00004000 */
#define PMU_BUS_IDLE_CON0_IDLE_REQ_BUS_SHIFT               (15U)
#define PMU_BUS_IDLE_CON0_IDLE_REQ_BUS_MASK                (0x1U << PMU_BUS_IDLE_CON0_IDLE_REQ_BUS_SHIFT)               /* 0x00008000 */
/* BUS_IDLE_CON1 */
#define PMU_BUS_IDLE_CON1_OFFSET                           (0x44U)
#define PMU_BUS_IDLE_CON1_IDLE_REQ_TOP1_SHIFT              (0U)
#define PMU_BUS_IDLE_CON1_IDLE_REQ_TOP1_MASK               (0x1U << PMU_BUS_IDLE_CON1_IDLE_REQ_TOP1_SHIFT)              /* 0x00000001 */
#define PMU_BUS_IDLE_CON1_IDLE_REQ_TOP2_SHIFT              (1U)
#define PMU_BUS_IDLE_CON1_IDLE_REQ_TOP2_MASK               (0x1U << PMU_BUS_IDLE_CON1_IDLE_REQ_TOP2_SHIFT)              /* 0x00000002 */
#define PMU_BUS_IDLE_CON1_IDLE_REQ_PMU_SHIFT               (2U)
#define PMU_BUS_IDLE_CON1_IDLE_REQ_PMU_MASK                (0x1U << PMU_BUS_IDLE_CON1_IDLE_REQ_PMU_SHIFT)               /* 0x00000004 */
/* BUS_IDLE_SFTCON0 */
#define PMU_BUS_IDLE_SFTCON0_OFFSET                        (0x50U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_MSCH_SHIFT           (0U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_MSCH_MASK            (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_MSCH_SHIFT)           /* 0x00000001 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GPU_SHIFT            (1U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GPU_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GPU_SHIFT)            /* 0x00000002 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_NPU_SHIFT            (2U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_NPU_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_NPU_SHIFT)            /* 0x00000004 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VI_SHIFT             (3U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VI_MASK              (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VI_SHIFT)             /* 0x00000008 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VO_SHIFT             (4U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VO_MASK              (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VO_SHIFT)             /* 0x00000010 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RGA_SHIFT            (5U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RGA_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RGA_SHIFT)            /* 0x00000020 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VPU_SHIFT            (6U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VPU_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_VPU_SHIFT)            /* 0x00000040 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVENC_SHIFT         (7U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVENC_MASK          (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVENC_SHIFT)         /* 0x00000080 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVDEC_SHIFT         (8U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVDEC_MASK          (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_RKVDEC_SHIFT)         /* 0x00000100 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GIC_AUDIO_SHIFT      (9U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GIC_AUDIO_MASK       (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_GIC_AUDIO_SHIFT)      /* 0x00000200 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PHP_SHIFT            (10U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PHP_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PHP_SHIFT)            /* 0x00000400 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PIPE_SHIFT           (11U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PIPE_MASK            (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PIPE_SHIFT)           /* 0x00000800 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_SECURE_FLASH_SHIFT   (12U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_SECURE_FLASH_MASK    (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_SECURE_FLASH_SHIFT)   /* 0x00001000 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PERIMID_SHIFT        (13U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PERIMID_MASK         (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_PERIMID_SHIFT)        /* 0x00002000 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_USB_SHIFT            (14U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_USB_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_USB_SHIFT)            /* 0x00004000 */
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_BUS_SHIFT            (15U)
#define PMU_BUS_IDLE_SFTCON0_IDLE_REQ_BUS_MASK             (0x1U << PMU_BUS_IDLE_SFTCON0_IDLE_REQ_BUS_SHIFT)            /* 0x00008000 */
/* BUS_IDLE_SFTCON1 */
#define PMU_BUS_IDLE_SFTCON1_OFFSET                        (0x54U)
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP1_SHIFT           (0U)
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP1_MASK            (0x1U << PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP1_SHIFT)           /* 0x00000001 */
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP2_SHIFT           (1U)
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP2_MASK            (0x1U << PMU_BUS_IDLE_SFTCON1_IDLE_REQ_TOP2_SHIFT)           /* 0x00000002 */
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_PMU_SHIFT            (2U)
#define PMU_BUS_IDLE_SFTCON1_IDLE_REQ_PMU_MASK             (0x1U << PMU_BUS_IDLE_SFTCON1_IDLE_REQ_PMU_SHIFT)            /* 0x00000004 */
/* BUS_IDLE_ACK */
#define PMU_BUS_IDLE_ACK_OFFSET                            (0x60U)
#define PMU_BUS_IDLE_ACK                                   (0x0U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_MSCH_SHIFT               (0U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_MSCH_MASK                (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_MSCH_SHIFT)               /* 0x00000001 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_GPU_SHIFT                (1U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_GPU_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_GPU_SHIFT)                /* 0x00000002 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_NPU_SHIFT                (2U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_NPU_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_NPU_SHIFT)                /* 0x00000004 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VI_SHIFT                 (3U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VI_MASK                  (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_VI_SHIFT)                 /* 0x00000008 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VO_SHIFT                 (4U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VO_MASK                  (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_VO_SHIFT)                 /* 0x00000010 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RGA_SHIFT                (5U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RGA_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_RGA_SHIFT)                /* 0x00000020 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VPU_SHIFT                (6U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_VPU_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_VPU_SHIFT)                /* 0x00000040 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RKVENC_SHIFT             (7U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RKVENC_MASK              (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_RKVENC_SHIFT)             /* 0x00000080 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RKVDEC_SHIFT             (8U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_RKVDEC_MASK              (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_RKVDEC_SHIFT)             /* 0x00000100 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_GIC_AUDIO_SHIFT          (9U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_GIC_AUDIO_MASK           (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_GIC_AUDIO_SHIFT)          /* 0x00000200 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PHP_SHIFT                (10U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PHP_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_PHP_SHIFT)                /* 0x00000400 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PIPE_SHIFT               (11U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PIPE_MASK                (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_PIPE_SHIFT)               /* 0x00000800 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_SECURE_FLASH_SHIFT       (12U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_SECURE_FLASH_MASK        (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_SECURE_FLASH_SHIFT)       /* 0x00001000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PERIMID_SHIFT            (13U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PERIMID_MASK             (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_PERIMID_SHIFT)            /* 0x00002000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_USB_SHIFT                (14U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_USB_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_USB_SHIFT)                /* 0x00004000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_BUS_SHIFT                (15U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_BUS_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_BUS_SHIFT)                /* 0x00008000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_TOP1_SHIFT               (16U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_TOP1_MASK                (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_TOP1_SHIFT)               /* 0x00010000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_TOP2_SHIFT               (17U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_TOP2_MASK                (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_TOP2_SHIFT)               /* 0x00020000 */
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PMU_SHIFT                (18U)
#define PMU_BUS_IDLE_ACK_IDLE_ACK_PMU_MASK                 (0x1U << PMU_BUS_IDLE_ACK_IDLE_ACK_PMU_SHIFT)                /* 0x00040000 */
/* BUS_IDLE_ST */
#define PMU_BUS_IDLE_ST_OFFSET                             (0x68U)
#define PMU_BUS_IDLE_ST                                    (0x0U)
#define PMU_BUS_IDLE_ST_IDLE_MSCH_SHIFT                    (0U)
#define PMU_BUS_IDLE_ST_IDLE_MSCH_MASK                     (0x1U << PMU_BUS_IDLE_ST_IDLE_MSCH_SHIFT)                    /* 0x00000001 */
#define PMU_BUS_IDLE_ST_IDLE_GPU_SHIFT                     (1U)
#define PMU_BUS_IDLE_ST_IDLE_GPU_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_GPU_SHIFT)                     /* 0x00000002 */
#define PMU_BUS_IDLE_ST_IDLE_NPU_SHIFT                     (2U)
#define PMU_BUS_IDLE_ST_IDLE_NPU_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_NPU_SHIFT)                     /* 0x00000004 */
#define PMU_BUS_IDLE_ST_IDLE_VI_SHIFT                      (3U)
#define PMU_BUS_IDLE_ST_IDLE_VI_MASK                       (0x1U << PMU_BUS_IDLE_ST_IDLE_VI_SHIFT)                      /* 0x00000008 */
#define PMU_BUS_IDLE_ST_IDLE_VO_SHIFT                      (4U)
#define PMU_BUS_IDLE_ST_IDLE_VO_MASK                       (0x1U << PMU_BUS_IDLE_ST_IDLE_VO_SHIFT)                      /* 0x00000010 */
#define PMU_BUS_IDLE_ST_IDLE_RGA_SHIFT                     (5U)
#define PMU_BUS_IDLE_ST_IDLE_RGA_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_RGA_SHIFT)                     /* 0x00000020 */
#define PMU_BUS_IDLE_ST_IDLE_VPU_SHIFT                     (6U)
#define PMU_BUS_IDLE_ST_IDLE_VPU_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_VPU_SHIFT)                     /* 0x00000040 */
#define PMU_BUS_IDLE_ST_IDLE_RKVENC_SHIFT                  (7U)
#define PMU_BUS_IDLE_ST_IDLE_RKVENC_MASK                   (0x1U << PMU_BUS_IDLE_ST_IDLE_RKVENC_SHIFT)                  /* 0x00000080 */
#define PMU_BUS_IDLE_ST_IDLE_RKVDEC_SHIFT                  (8U)
#define PMU_BUS_IDLE_ST_IDLE_RKVDEC_MASK                   (0x1U << PMU_BUS_IDLE_ST_IDLE_RKVDEC_SHIFT)                  /* 0x00000100 */
#define PMU_BUS_IDLE_ST_IDLE_GIC_AUDIO_SHIFT               (9U)
#define PMU_BUS_IDLE_ST_IDLE_GIC_AUDIO_MASK                (0x1U << PMU_BUS_IDLE_ST_IDLE_GIC_AUDIO_SHIFT)               /* 0x00000200 */
#define PMU_BUS_IDLE_ST_IDLE_PHP_SHIFT                     (10U)
#define PMU_BUS_IDLE_ST_IDLE_PHP_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_PHP_SHIFT)                     /* 0x00000400 */
#define PMU_BUS_IDLE_ST_IDLE_PIPE_SHIFT                    (11U)
#define PMU_BUS_IDLE_ST_IDLE_PIPE_MASK                     (0x1U << PMU_BUS_IDLE_ST_IDLE_PIPE_SHIFT)                    /* 0x00000800 */
#define PMU_BUS_IDLE_ST_IDLE_SECURE_FLASH_SHIFT            (12U)
#define PMU_BUS_IDLE_ST_IDLE_SECURE_FLASH_MASK             (0x1U << PMU_BUS_IDLE_ST_IDLE_SECURE_FLASH_SHIFT)            /* 0x00001000 */
#define PMU_BUS_IDLE_ST_IDLE_PERIMID_SHIFT                 (13U)
#define PMU_BUS_IDLE_ST_IDLE_PERIMID_MASK                  (0x1U << PMU_BUS_IDLE_ST_IDLE_PERIMID_SHIFT)                 /* 0x00002000 */
#define PMU_BUS_IDLE_ST_IDLE_USB_SHIFT                     (14U)
#define PMU_BUS_IDLE_ST_IDLE_USB_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_USB_SHIFT)                     /* 0x00004000 */
#define PMU_BUS_IDLE_ST_IDLE_BUS_SHIFT                     (15U)
#define PMU_BUS_IDLE_ST_IDLE_BUS_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_BUS_SHIFT)                     /* 0x00008000 */
#define PMU_BUS_IDLE_ST_IDLE_TOP1_SHIFT                    (16U)
#define PMU_BUS_IDLE_ST_IDLE_TOP1_MASK                     (0x1U << PMU_BUS_IDLE_ST_IDLE_TOP1_SHIFT)                    /* 0x00010000 */
#define PMU_BUS_IDLE_ST_IDLE_TOP2_SHIFT                    (17U)
#define PMU_BUS_IDLE_ST_IDLE_TOP2_MASK                     (0x1U << PMU_BUS_IDLE_ST_IDLE_TOP2_SHIFT)                    /* 0x00020000 */
#define PMU_BUS_IDLE_ST_IDLE_PMU_SHIFT                     (18U)
#define PMU_BUS_IDLE_ST_IDLE_PMU_MASK                      (0x1U << PMU_BUS_IDLE_ST_IDLE_PMU_SHIFT)                     /* 0x00040000 */
/* NOC_AUTO_CON0 */
#define PMU_NOC_AUTO_CON0_OFFSET                           (0x70U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_MSCH_SHIFT             (0U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_MSCH_MASK              (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_MSCH_SHIFT)             /* 0x00000001 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_GPU_SHIFT              (1U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_GPU_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_GPU_SHIFT)              /* 0x00000002 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_NPU_SHIFT              (2U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_NPU_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_NPU_SHIFT)              /* 0x00000004 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VI_SHIFT               (3U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VI_MASK                (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_VI_SHIFT)               /* 0x00000008 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VO_SHIFT               (4U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VO_MASK                (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_VO_SHIFT)               /* 0x00000010 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RGA_SHIFT              (5U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RGA_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_RGA_SHIFT)              /* 0x00000020 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VPU_SHIFT              (6U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_VPU_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_VPU_SHIFT)              /* 0x00000040 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVENC_SHIFT           (7U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVENC_MASK            (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVENC_SHIFT)           /* 0x00000080 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVDEC_SHIFT           (8U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVDEC_MASK            (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_RKVDEC_SHIFT)           /* 0x00000100 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_GIC_AUDIO_SHIFT        (9U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_GIC_AUDIO_MASK         (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_GIC_AUDIO_SHIFT)        /* 0x00000200 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PHP_SHIFT              (10U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PHP_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_PHP_SHIFT)              /* 0x00000400 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PIPE_SHIFT             (11U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PIPE_MASK              (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_PIPE_SHIFT)             /* 0x00000800 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_SECURE_FLASH_SHIFT     (12U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_SECURE_FLASH_MASK      (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_SECURE_FLASH_SHIFT)     /* 0x00001000 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PERIMID_SHIFT          (13U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_PERIMID_MASK           (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_PERIMID_SHIFT)          /* 0x00002000 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_USB_SHIFT              (14U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_USB_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_USB_SHIFT)              /* 0x00004000 */
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_BUS_SHIFT              (15U)
#define PMU_NOC_AUTO_CON0_AUTO_IDLE_BUS_MASK               (0x1U << PMU_NOC_AUTO_CON0_AUTO_IDLE_BUS_SHIFT)              /* 0x00008000 */
/* NOC_AUTO_CON1 */
#define PMU_NOC_AUTO_CON1_OFFSET                           (0x74U)
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP1_SHIFT             (0U)
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP1_MASK              (0x1U << PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP1_SHIFT)             /* 0x00000001 */
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP2_SHIFT             (1U)
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP2_MASK              (0x1U << PMU_NOC_AUTO_CON1_AUTO_IDLE_TOP2_SHIFT)             /* 0x00000002 */
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_PMU_SHIFT              (2U)
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_PMU_MASK               (0x1U << PMU_NOC_AUTO_CON1_AUTO_IDLE_PMU_SHIFT)              /* 0x00000004 */
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_CPU_SHIFT              (3U)
#define PMU_NOC_AUTO_CON1_AUTO_IDLE_CPU_MASK               (0x1U << PMU_NOC_AUTO_CON1_AUTO_IDLE_CPU_SHIFT)              /* 0x00000008 */
/* DDR_PWR_CON */
#define PMU_DDR_PWR_CON_OFFSET                             (0x80U)
#define PMU_DDR_PWR_CON_DDR_SREF_ENA_SHIFT                 (0U)
#define PMU_DDR_PWR_CON_DDR_SREF_ENA_MASK                  (0x1U << PMU_DDR_PWR_CON_DDR_SREF_ENA_SHIFT)                 /* 0x00000001 */
#define PMU_DDR_PWR_CON_DDRIO_RET_EXIT_ENA_SHIFT           (2U)
#define PMU_DDR_PWR_CON_DDRIO_RET_EXIT_ENA_MASK            (0x1U << PMU_DDR_PWR_CON_DDRIO_RET_EXIT_ENA_SHIFT)           /* 0x00000004 */
#define PMU_DDR_PWR_CON_DDRPHY_AUTO_GATING_ENA_SHIFT       (4U)
#define PMU_DDR_PWR_CON_DDRPHY_AUTO_GATING_ENA_MASK        (0x1U << PMU_DDR_PWR_CON_DDRPHY_AUTO_GATING_ENA_SHIFT)       /* 0x00000010 */
/* DDR_PWR_SFTCON */
#define PMU_DDR_PWR_SFTCON_OFFSET                          (0x84U)
#define PMU_DDR_PWR_SFTCON_SW_DDR_SREF_REQ_SHIFT           (0U)
#define PMU_DDR_PWR_SFTCON_SW_DDR_SREF_REQ_MASK            (0x1U << PMU_DDR_PWR_SFTCON_SW_DDR_SREF_REQ_SHIFT)           /* 0x00000001 */
#define PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_REQ_SHIFT          (1U)
#define PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_REQ_MASK           (0x1U << PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_REQ_SHIFT)          /* 0x00000002 */
#define PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_EXIT_SHIFT         (2U)
#define PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_EXIT_MASK          (0x1U << PMU_DDR_PWR_SFTCON_SW_DDRIO_RET_EXIT_SHIFT)         /* 0x00000004 */
#define PMU_DDR_PWR_SFTCON_DDRCTL_ACTIVE_WAIT_SHIFT        (3U)
#define PMU_DDR_PWR_SFTCON_DDRCTL_ACTIVE_WAIT_MASK         (0x1U << PMU_DDR_PWR_SFTCON_DDRCTL_ACTIVE_WAIT_SHIFT)        /* 0x00000008 */
/* DDR_PWR_STATE */
#define PMU_DDR_PWR_STATE_OFFSET                           (0x88U)
#define PMU_DDR_PWR_STATE                                  (0x0U)
#define PMU_DDR_PWR_STATE_DDR_POWER_STATE_SHIFT            (0U)
#define PMU_DDR_PWR_STATE_DDR_POWER_STATE_MASK             (0x7U << PMU_DDR_PWR_STATE_DDR_POWER_STATE_SHIFT)            /* 0x00000007 */
/* DDR_PWR_ST */
#define PMU_DDR_PWR_ST_OFFSET                              (0x8CU)
#define PMU_DDR_PWR_ST                                     (0x2U)
#define PMU_DDR_PWR_ST_DDRCTL_C_SYSACK_SHIFT               (0U)
#define PMU_DDR_PWR_ST_DDRCTL_C_SYSACK_MASK                (0x1U << PMU_DDR_PWR_ST_DDRCTL_C_SYSACK_SHIFT)               /* 0x00000001 */
#define PMU_DDR_PWR_ST_DDRCTL_C_ACTIVE_SHIFT               (1U)
#define PMU_DDR_PWR_ST_DDRCTL_C_ACTIVE_MASK                (0x1U << PMU_DDR_PWR_ST_DDRCTL_C_ACTIVE_SHIFT)               /* 0x00000002 */
#define PMU_DDR_PWR_ST_DDRIO_RET_SHIFT                     (2U)
#define PMU_DDR_PWR_ST_DDRIO_RET_MASK                      (0x1U << PMU_DDR_PWR_ST_DDRIO_RET_SHIFT)                     /* 0x00000004 */
/* PWR_GATE_CON */
#define PMU_PWR_GATE_CON_OFFSET                            (0x90U)
#define PMU_PWR_GATE_CON_PD_GPU_DWN_ENA_SHIFT              (0U)
#define PMU_PWR_GATE_CON_PD_GPU_DWN_ENA_MASK               (0x1U << PMU_PWR_GATE_CON_PD_GPU_DWN_ENA_SHIFT)              /* 0x00000001 */
#define PMU_PWR_GATE_CON_PD_NPU_DWN_ENA_SHIFT              (1U)
#define PMU_PWR_GATE_CON_PD_NPU_DWN_ENA_MASK               (0x1U << PMU_PWR_GATE_CON_PD_NPU_DWN_ENA_SHIFT)              /* 0x00000002 */
#define PMU_PWR_GATE_CON_PD_VPU_DWN_ENA_SHIFT              (2U)
#define PMU_PWR_GATE_CON_PD_VPU_DWN_ENA_MASK               (0x1U << PMU_PWR_GATE_CON_PD_VPU_DWN_ENA_SHIFT)              /* 0x00000004 */
#define PMU_PWR_GATE_CON_PD_RKVENC_DWN_ENA_SHIFT           (3U)
#define PMU_PWR_GATE_CON_PD_RKVENC_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_CON_PD_RKVENC_DWN_ENA_SHIFT)           /* 0x00000008 */
#define PMU_PWR_GATE_CON_PD_RKVDEC_DWN_ENA_SHIFT           (4U)
#define PMU_PWR_GATE_CON_PD_RKVDEC_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_CON_PD_RKVDEC_DWN_ENA_SHIFT)           /* 0x00000010 */
#define PMU_PWR_GATE_CON_PD_RGA_DWN_ENA_SHIFT              (5U)
#define PMU_PWR_GATE_CON_PD_RGA_DWN_ENA_MASK               (0x1U << PMU_PWR_GATE_CON_PD_RGA_DWN_ENA_SHIFT)              /* 0x00000020 */
#define PMU_PWR_GATE_CON_PD_VI_DWN_ENA_SHIFT               (6U)
#define PMU_PWR_GATE_CON_PD_VI_DWN_ENA_MASK                (0x1U << PMU_PWR_GATE_CON_PD_VI_DWN_ENA_SHIFT)               /* 0x00000040 */
#define PMU_PWR_GATE_CON_PD_VO_DWN_ENA_SHIFT               (7U)
#define PMU_PWR_GATE_CON_PD_VO_DWN_ENA_MASK                (0x1U << PMU_PWR_GATE_CON_PD_VO_DWN_ENA_SHIFT)               /* 0x00000080 */
#define PMU_PWR_GATE_CON_PD_PIPE_DWN_ENA_SHIFT             (8U)
#define PMU_PWR_GATE_CON_PD_PIPE_DWN_ENA_MASK              (0x1U << PMU_PWR_GATE_CON_PD_PIPE_DWN_ENA_SHIFT)             /* 0x00000100 */
#define PMU_PWR_GATE_CON_PD_DDR_DWN_ENA_SHIFT              (9U)
#define PMU_PWR_GATE_CON_PD_DDR_DWN_ENA_MASK               (0x1U << PMU_PWR_GATE_CON_PD_DDR_DWN_ENA_SHIFT)              /* 0x00000200 */
/* PWR_GATE_STATE */
#define PMU_PWR_GATE_STATE_OFFSET                          (0x94U)
#define PMU_PWR_GATE_STATE                                 (0x0U)
#define PMU_PWR_GATE_STATE_POWER_GATE_STATE_SHIFT          (0U)
#define PMU_PWR_GATE_STATE_POWER_GATE_STATE_MASK           (0x7U << PMU_PWR_GATE_STATE_POWER_GATE_STATE_SHIFT)          /* 0x00000007 */
/* PWR_DWN_ST */
#define PMU_PWR_DWN_ST_OFFSET                              (0x98U)
#define PMU_PWR_DWN_ST                                     (0x0U)
#define PMU_PWR_DWN_ST_PD_GPU_DWN_STAT_SHIFT               (0U)
#define PMU_PWR_DWN_ST_PD_GPU_DWN_STAT_MASK                (0x1U << PMU_PWR_DWN_ST_PD_GPU_DWN_STAT_SHIFT)               /* 0x00000001 */
#define PMU_PWR_DWN_ST_PD_NPU_DWN_STAT_SHIFT               (1U)
#define PMU_PWR_DWN_ST_PD_NPU_DWN_STAT_MASK                (0x1U << PMU_PWR_DWN_ST_PD_NPU_DWN_STAT_SHIFT)               /* 0x00000002 */
#define PMU_PWR_DWN_ST_PD_VPU_DWN_STAT_SHIFT               (2U)
#define PMU_PWR_DWN_ST_PD_VPU_DWN_STAT_MASK                (0x1U << PMU_PWR_DWN_ST_PD_VPU_DWN_STAT_SHIFT)               /* 0x00000004 */
#define PMU_PWR_DWN_ST_PD_RKVENC_DWN_STAT_SHIFT            (3U)
#define PMU_PWR_DWN_ST_PD_RKVENC_DWN_STAT_MASK             (0x1U << PMU_PWR_DWN_ST_PD_RKVENC_DWN_STAT_SHIFT)            /* 0x00000008 */
#define PMU_PWR_DWN_ST_PD_RKVDEC_DWN_STAT_SHIFT            (4U)
#define PMU_PWR_DWN_ST_PD_RKVDEC_DWN_STAT_MASK             (0x1U << PMU_PWR_DWN_ST_PD_RKVDEC_DWN_STAT_SHIFT)            /* 0x00000010 */
#define PMU_PWR_DWN_ST_PD_RGA_DWN_STAT_SHIFT               (5U)
#define PMU_PWR_DWN_ST_PD_RGA_DWN_STAT_MASK                (0x1U << PMU_PWR_DWN_ST_PD_RGA_DWN_STAT_SHIFT)               /* 0x00000020 */
#define PMU_PWR_DWN_ST_PD_VI_DWN_STAT_SHIFT                (6U)
#define PMU_PWR_DWN_ST_PD_VI_DWN_STAT_MASK                 (0x1U << PMU_PWR_DWN_ST_PD_VI_DWN_STAT_SHIFT)                /* 0x00000040 */
#define PMU_PWR_DWN_ST_PD_VO_DWN_STAT_SHIFT                (7U)
#define PMU_PWR_DWN_ST_PD_VO_DWN_STAT_MASK                 (0x1U << PMU_PWR_DWN_ST_PD_VO_DWN_STAT_SHIFT)                /* 0x00000080 */
#define PMU_PWR_DWN_ST_PD_PIPE_DWN_STAT_SHIFT              (8U)
#define PMU_PWR_DWN_ST_PD_PIPE_DWN_STAT_MASK               (0x1U << PMU_PWR_DWN_ST_PD_PIPE_DWN_STAT_SHIFT)              /* 0x00000100 */
#define PMU_PWR_DWN_ST_PD_DDR_DWN_STAT_SHIFT               (9U)
#define PMU_PWR_DWN_ST_PD_DDR_DWN_STAT_MASK                (0x1U << PMU_PWR_DWN_ST_PD_DDR_DWN_STAT_SHIFT)               /* 0x00000200 */
/* PWR_GATE_SFTCON */
#define PMU_PWR_GATE_SFTCON_OFFSET                         (0xA0U)
#define PMU_PWR_GATE_SFTCON_PD_GPU_DWN_ENA_SHIFT           (0U)
#define PMU_PWR_GATE_SFTCON_PD_GPU_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_SFTCON_PD_GPU_DWN_ENA_SHIFT)           /* 0x00000001 */
#define PMU_PWR_GATE_SFTCON_PD_NPU_DWN_ENA_SHIFT           (1U)
#define PMU_PWR_GATE_SFTCON_PD_NPU_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_SFTCON_PD_NPU_DWN_ENA_SHIFT)           /* 0x00000002 */
#define PMU_PWR_GATE_SFTCON_PD_VPU_DWN_ENA_SHIFT           (2U)
#define PMU_PWR_GATE_SFTCON_PD_VPU_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_SFTCON_PD_VPU_DWN_ENA_SHIFT)           /* 0x00000004 */
#define PMU_PWR_GATE_SFTCON_PD_RKVENC_DWN_ENA_SHIFT        (3U)
#define PMU_PWR_GATE_SFTCON_PD_RKVENC_DWN_ENA_MASK         (0x1U << PMU_PWR_GATE_SFTCON_PD_RKVENC_DWN_ENA_SHIFT)        /* 0x00000008 */
#define PMU_PWR_GATE_SFTCON_PD_RKVDEC_DWN_ENA_SHIFT        (4U)
#define PMU_PWR_GATE_SFTCON_PD_RKVDEC_DWN_ENA_MASK         (0x1U << PMU_PWR_GATE_SFTCON_PD_RKVDEC_DWN_ENA_SHIFT)        /* 0x00000010 */
#define PMU_PWR_GATE_SFTCON_PD_RGA_DWN_ENA_SHIFT           (5U)
#define PMU_PWR_GATE_SFTCON_PD_RGA_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_SFTCON_PD_RGA_DWN_ENA_SHIFT)           /* 0x00000020 */
#define PMU_PWR_GATE_SFTCON_PD_VI_DWN_ENA_SHIFT            (6U)
#define PMU_PWR_GATE_SFTCON_PD_VI_DWN_ENA_MASK             (0x1U << PMU_PWR_GATE_SFTCON_PD_VI_DWN_ENA_SHIFT)            /* 0x00000040 */
#define PMU_PWR_GATE_SFTCON_PD_VO_DWN_ENA_SHIFT            (7U)
#define PMU_PWR_GATE_SFTCON_PD_VO_DWN_ENA_MASK             (0x1U << PMU_PWR_GATE_SFTCON_PD_VO_DWN_ENA_SHIFT)            /* 0x00000080 */
#define PMU_PWR_GATE_SFTCON_PD_PIPE_DWN_ENA_SHIFT          (8U)
#define PMU_PWR_GATE_SFTCON_PD_PIPE_DWN_ENA_MASK           (0x1U << PMU_PWR_GATE_SFTCON_PD_PIPE_DWN_ENA_SHIFT)          /* 0x00000100 */
#define PMU_PWR_GATE_SFTCON_PD_DDR_DWN_ENA_SHIFT           (9U)
#define PMU_PWR_GATE_SFTCON_PD_DDR_DWN_ENA_MASK            (0x1U << PMU_PWR_GATE_SFTCON_PD_DDR_DWN_ENA_SHIFT)           /* 0x00000200 */
/* VOL_GATE_SFTCON */
#define PMU_VOL_GATE_SFTCON_OFFSET                         (0xA8U)
#define PMU_VOL_GATE_SFTCON_VD_GPU_ENA_SHIFT               (0U)
#define PMU_VOL_GATE_SFTCON_VD_GPU_ENA_MASK                (0x1U << PMU_VOL_GATE_SFTCON_VD_GPU_ENA_SHIFT)               /* 0x00000001 */
#define PMU_VOL_GATE_SFTCON_VD_NPU_ENA_SHIFT               (1U)
#define PMU_VOL_GATE_SFTCON_VD_NPU_ENA_MASK                (0x1U << PMU_VOL_GATE_SFTCON_VD_NPU_ENA_SHIFT)               /* 0x00000002 */
/* CRU_PWR_CON */
#define PMU_CRU_PWR_CON_OFFSET                             (0xB0U)
#define PMU_CRU_PWR_CON_ALIVE_32K_ENA_SHIFT                (0U)
#define PMU_CRU_PWR_CON_ALIVE_32K_ENA_MASK                 (0x1U << PMU_CRU_PWR_CON_ALIVE_32K_ENA_SHIFT)                /* 0x00000001 */
#define PMU_CRU_PWR_CON_OSC_DIS_ENA_SHIFT                  (1U)
#define PMU_CRU_PWR_CON_OSC_DIS_ENA_MASK                   (0x1U << PMU_CRU_PWR_CON_OSC_DIS_ENA_SHIFT)                  /* 0x00000002 */
#define PMU_CRU_PWR_CON_WAKEUP_RST_ENA_SHIFT               (2U)
#define PMU_CRU_PWR_CON_WAKEUP_RST_ENA_MASK                (0x1U << PMU_CRU_PWR_CON_WAKEUP_RST_ENA_SHIFT)               /* 0x00000004 */
#define PMU_CRU_PWR_CON_INPUT_CLAMP_ENA_SHIFT              (3U)
#define PMU_CRU_PWR_CON_INPUT_CLAMP_ENA_MASK               (0x1U << PMU_CRU_PWR_CON_INPUT_CLAMP_ENA_SHIFT)              /* 0x00000008 */
#define PMU_CRU_PWR_CON_ALIVE_OSC_ENA_SHIFT                (4U)
#define PMU_CRU_PWR_CON_ALIVE_OSC_ENA_MASK                 (0x1U << PMU_CRU_PWR_CON_ALIVE_OSC_ENA_SHIFT)                /* 0x00000010 */
#define PMU_CRU_PWR_CON_POWER_OFF_ENA_SHIFT                (5U)
#define PMU_CRU_PWR_CON_POWER_OFF_ENA_MASK                 (0x1U << PMU_CRU_PWR_CON_POWER_OFF_ENA_SHIFT)                /* 0x00000020 */
#define PMU_CRU_PWR_CON_PWM_SWITCH_ENA_SHIFT               (6U)
#define PMU_CRU_PWR_CON_PWM_SWITCH_ENA_MASK                (0x1U << PMU_CRU_PWR_CON_PWM_SWITCH_ENA_SHIFT)               /* 0x00000040 */
#define PMU_CRU_PWR_CON_PWM_GPIO_IOE_ENA_SHIFT             (7U)
#define PMU_CRU_PWR_CON_PWM_GPIO_IOE_ENA_MASK              (0x1U << PMU_CRU_PWR_CON_PWM_GPIO_IOE_ENA_SHIFT)             /* 0x00000080 */
#define PMU_CRU_PWR_CON_PWM_SWITCH_IOUT_SHIFT              (8U)
#define PMU_CRU_PWR_CON_PWM_SWITCH_IOUT_MASK               (0x1U << PMU_CRU_PWR_CON_PWM_SWITCH_IOUT_SHIFT)              /* 0x00000100 */
#define PMU_CRU_PWR_CON_PD_BUS_CLK_SRC_GATE_ENA_SHIFT      (9U)
#define PMU_CRU_PWR_CON_PD_BUS_CLK_SRC_GATE_ENA_MASK       (0x1U << PMU_CRU_PWR_CON_PD_BUS_CLK_SRC_GATE_ENA_SHIFT)      /* 0x00000200 */
#define PMU_CRU_PWR_CON_PD_PERI_CLK_SRC_GATE_ENA_SHIFT     (10U)
#define PMU_CRU_PWR_CON_PD_PERI_CLK_SRC_GATE_ENA_MASK      (0x1U << PMU_CRU_PWR_CON_PD_PERI_CLK_SRC_GATE_ENA_SHIFT)     /* 0x00000400 */
#define PMU_CRU_PWR_CON_PD_PMU_CLK_SRC_GATE_ENA_SHIFT      (11U)
#define PMU_CRU_PWR_CON_PD_PMU_CLK_SRC_GATE_ENA_MASK       (0x1U << PMU_CRU_PWR_CON_PD_PMU_CLK_SRC_GATE_ENA_SHIFT)      /* 0x00000800 */
#define PMU_CRU_PWR_CON_PMUMEM_CLK_SRC_GATE_ENA_SHIFT      (12U)
#define PMU_CRU_PWR_CON_PMUMEM_CLK_SRC_GATE_ENA_MASK       (0x1U << PMU_CRU_PWR_CON_PMUMEM_CLK_SRC_GATE_ENA_SHIFT)      /* 0x00001000 */
/* CRU_PWR_SFTCON */
#define PMU_CRU_PWR_SFTCON_OFFSET                          (0xB4U)
#define PMU_CRU_PWR_SFTCON_ALIVE_32K_ENA_SHIFT             (0U)
#define PMU_CRU_PWR_SFTCON_ALIVE_32K_ENA_MASK              (0x1U << PMU_CRU_PWR_SFTCON_ALIVE_32K_ENA_SHIFT)             /* 0x00000001 */
#define PMU_CRU_PWR_SFTCON_OSC_DIS_ENA_SHIFT               (1U)
#define PMU_CRU_PWR_SFTCON_OSC_DIS_ENA_MASK                (0x1U << PMU_CRU_PWR_SFTCON_OSC_DIS_ENA_SHIFT)               /* 0x00000002 */
#define PMU_CRU_PWR_SFTCON_WAKEUP_RST_ENA_SHIFT            (2U)
#define PMU_CRU_PWR_SFTCON_WAKEUP_RST_ENA_MASK             (0x1U << PMU_CRU_PWR_SFTCON_WAKEUP_RST_ENA_SHIFT)            /* 0x00000004 */
#define PMU_CRU_PWR_SFTCON_INPUT_CLAMP_ENA_SHIFT           (3U)
#define PMU_CRU_PWR_SFTCON_INPUT_CLAMP_ENA_MASK            (0x1U << PMU_CRU_PWR_SFTCON_INPUT_CLAMP_ENA_SHIFT)           /* 0x00000008 */
#define PMU_CRU_PWR_SFTCON_ALIVE_OSC_ENA_SHIFT             (4U)
#define PMU_CRU_PWR_SFTCON_ALIVE_OSC_ENA_MASK              (0x1U << PMU_CRU_PWR_SFTCON_ALIVE_OSC_ENA_SHIFT)             /* 0x00000010 */
#define PMU_CRU_PWR_SFTCON_POWER_OFF_ENA_SHIFT             (5U)
#define PMU_CRU_PWR_SFTCON_POWER_OFF_ENA_MASK              (0x1U << PMU_CRU_PWR_SFTCON_POWER_OFF_ENA_SHIFT)             /* 0x00000020 */
/* CRU_PWR_STATE */
#define PMU_CRU_PWR_STATE_OFFSET                           (0xB8U)
#define PMU_CRU_PWR_STATE                                  (0x0U)
#define PMU_CRU_PWR_STATE_CRU_POWER_STATE_SHIFT            (0U)
#define PMU_CRU_PWR_STATE_CRU_POWER_STATE_MASK             (0xFU << PMU_CRU_PWR_STATE_CRU_POWER_STATE_SHIFT)            /* 0x0000000F */
/* PLLPD_CON */
#define PMU_PLLPD_CON_OFFSET                               (0xC0U)
#define PMU_PLLPD_CON_APLL_PD_ENA_SHIFT                    (0U)
#define PMU_PLLPD_CON_APLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_APLL_PD_ENA_SHIFT)                    /* 0x00000001 */
#define PMU_PLLPD_CON_DPLL_PD_ENA_SHIFT                    (1U)
#define PMU_PLLPD_CON_DPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_DPLL_PD_ENA_SHIFT)                    /* 0x00000002 */
#define PMU_PLLPD_CON_CPLL_PD_ENA_SHIFT                    (2U)
#define PMU_PLLPD_CON_CPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_CPLL_PD_ENA_SHIFT)                    /* 0x00000004 */
#define PMU_PLLPD_CON_GPLL_PD_ENA_SHIFT                    (3U)
#define PMU_PLLPD_CON_GPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_GPLL_PD_ENA_SHIFT)                    /* 0x00000008 */
#define PMU_PLLPD_CON_MPLL_PD_ENA_SHIFT                    (4U)
#define PMU_PLLPD_CON_MPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_MPLL_PD_ENA_SHIFT)                    /* 0x00000010 */
#define PMU_PLLPD_CON_NPLL_PD_ENA_SHIFT                    (5U)
#define PMU_PLLPD_CON_NPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_NPLL_PD_ENA_SHIFT)                    /* 0x00000020 */
#define PMU_PLLPD_CON_HPLL_PD_ENA_SHIFT                    (6U)
#define PMU_PLLPD_CON_HPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_HPLL_PD_ENA_SHIFT)                    /* 0x00000040 */
#define PMU_PLLPD_CON_PPLL_PD_ENA_SHIFT                    (7U)
#define PMU_PLLPD_CON_PPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_PPLL_PD_ENA_SHIFT)                    /* 0x00000080 */
#define PMU_PLLPD_CON_VPLL_PD_ENA_SHIFT                    (8U)
#define PMU_PLLPD_CON_VPLL_PD_ENA_MASK                     (0x1U << PMU_PLLPD_CON_VPLL_PD_ENA_SHIFT)                    /* 0x00000100 */
/* PLLPD_SFTCON */
#define PMU_PLLPD_SFTCON_OFFSET                            (0xC4U)
#define PMU_PLLPD_SFTCON_APLL_PD_ENA_SHIFT                 (0U)
#define PMU_PLLPD_SFTCON_APLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_APLL_PD_ENA_SHIFT)                 /* 0x00000001 */
#define PMU_PLLPD_SFTCON_DPLL_PD_ENA_SHIFT                 (1U)
#define PMU_PLLPD_SFTCON_DPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_DPLL_PD_ENA_SHIFT)                 /* 0x00000002 */
#define PMU_PLLPD_SFTCON_CPLL_PD_ENA_SHIFT                 (2U)
#define PMU_PLLPD_SFTCON_CPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_CPLL_PD_ENA_SHIFT)                 /* 0x00000004 */
#define PMU_PLLPD_SFTCON_GPLL_PD_ENA_SHIFT                 (3U)
#define PMU_PLLPD_SFTCON_GPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_GPLL_PD_ENA_SHIFT)                 /* 0x00000008 */
#define PMU_PLLPD_SFTCON_MPLL_PD_ENA_SHIFT                 (4U)
#define PMU_PLLPD_SFTCON_MPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_MPLL_PD_ENA_SHIFT)                 /* 0x00000010 */
#define PMU_PLLPD_SFTCON_NPLL_PD_ENA_SHIFT                 (5U)
#define PMU_PLLPD_SFTCON_NPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_NPLL_PD_ENA_SHIFT)                 /* 0x00000020 */
#define PMU_PLLPD_SFTCON_HPLL_PD_ENA_SHIFT                 (6U)
#define PMU_PLLPD_SFTCON_HPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_HPLL_PD_ENA_SHIFT)                 /* 0x00000040 */
#define PMU_PLLPD_SFTCON_PPLL_PD_ENA_SHIFT                 (7U)
#define PMU_PLLPD_SFTCON_PPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_PPLL_PD_ENA_SHIFT)                 /* 0x00000080 */
#define PMU_PLLPD_SFTCON_VPLL_PD_ENA_SHIFT                 (8U)
#define PMU_PLLPD_SFTCON_VPLL_PD_ENA_MASK                  (0x1U << PMU_PLLPD_SFTCON_VPLL_PD_ENA_SHIFT)                 /* 0x00000100 */
/* INFO_TX_CON */
#define PMU_INFO_TX_CON_OFFSET                             (0xD0U)
#define PMU_INFO_TX_CON_INFO_TX_EN_SHIFT                   (0U)
#define PMU_INFO_TX_CON_INFO_TX_EN_MASK                    (0x1U << PMU_INFO_TX_CON_INFO_TX_EN_SHIFT)                   /* 0x00000001 */
#define PMU_INFO_TX_CON_INFO_TX_CON_SHIFT                  (4U)
#define PMU_INFO_TX_CON_INFO_TX_CON_MASK                   (0xFU << PMU_INFO_TX_CON_INFO_TX_CON_SHIFT)                  /* 0x000000F0 */
#define PMU_INFO_TX_CON_INFO_TX_INTV_TIME_SHIFT            (8U)
#define PMU_INFO_TX_CON_INFO_TX_INTV_TIME_MASK             (0xFFU << PMU_INFO_TX_CON_INFO_TX_INTV_TIME_SHIFT)           /* 0x0000FF00 */
/* DSU_STABLE_CNT */
#define PMU_DSU_STABLE_CNT_OFFSET                          (0x100U)
#define PMU_DSU_STABLE_CNT_STABLE_CNT_SHIFT                (0U)
#define PMU_DSU_STABLE_CNT_STABLE_CNT_MASK                 (0xFFFFFU << PMU_DSU_STABLE_CNT_STABLE_CNT_SHIFT)            /* 0x000FFFFF */
/* PMIC_STABLE_CNT */
#define PMU_PMIC_STABLE_CNT_OFFSET                         (0x104U)
#define PMU_PMIC_STABLE_CNT_STABLE_CNT_SHIFT               (0U)
#define PMU_PMIC_STABLE_CNT_STABLE_CNT_MASK                (0xFFFFFU << PMU_PMIC_STABLE_CNT_STABLE_CNT_SHIFT)           /* 0x000FFFFF */
/* OSC_STABLE_CNT */
#define PMU_OSC_STABLE_CNT_OFFSET                          (0x108U)
#define PMU_OSC_STABLE_CNT_STABLE_CNT_SHIFT                (0U)
#define PMU_OSC_STABLE_CNT_STABLE_CNT_MASK                 (0xFFFFFU << PMU_OSC_STABLE_CNT_STABLE_CNT_SHIFT)            /* 0x000FFFFF */
/* WAKEUP_RSTCLR_CNT */
#define PMU_WAKEUP_RSTCLR_CNT_OFFSET                       (0x10CU)
#define PMU_WAKEUP_RSTCLR_CNT_WAKEUP_RSTCLR_CNT_SHIFT      (0U)
#define PMU_WAKEUP_RSTCLR_CNT_WAKEUP_RSTCLR_CNT_MASK       (0xFFFFFU << PMU_WAKEUP_RSTCLR_CNT_WAKEUP_RSTCLR_CNT_SHIFT)  /* 0x000FFFFF */
/* PLL_LOCK_CNT */
#define PMU_PLL_LOCK_CNT_OFFSET                            (0x110U)
#define PMU_PLL_LOCK_CNT_PLL_LOCK_CNT_SHIFT                (0U)
#define PMU_PLL_LOCK_CNT_PLL_LOCK_CNT_MASK                 (0xFFFFFU << PMU_PLL_LOCK_CNT_PLL_LOCK_CNT_SHIFT)            /* 0x000FFFFF */
/* DSU_PWRUP_CNT */
#define PMU_DSU_PWRUP_CNT_OFFSET                           (0x118U)
#define PMU_DSU_PWRUP_CNT_STABLE_CNT_SHIFT                 (0U)
#define PMU_DSU_PWRUP_CNT_STABLE_CNT_MASK                  (0xFFFFFU << PMU_DSU_PWRUP_CNT_STABLE_CNT_SHIFT)             /* 0x000FFFFF */
/* DSU_PWRDN_CNT */
#define PMU_DSU_PWRDN_CNT_OFFSET                           (0x11CU)
#define PMU_DSU_PWRDN_CNT_STABLE_CNT_SHIFT                 (0U)
#define PMU_DSU_PWRDN_CNT_STABLE_CNT_MASK                  (0xFFFFFU << PMU_DSU_PWRDN_CNT_STABLE_CNT_SHIFT)             /* 0x000FFFFF */
/* GPU_VOLUP_CNT */
#define PMU_GPU_VOLUP_CNT_OFFSET                           (0x120U)
#define PMU_GPU_VOLUP_CNT_STABLE_CNT_SHIFT                 (0U)
#define PMU_GPU_VOLUP_CNT_STABLE_CNT_MASK                  (0xFFFFFU << PMU_GPU_VOLUP_CNT_STABLE_CNT_SHIFT)             /* 0x000FFFFF */
/* GPU_VOLDN_CNT */
#define PMU_GPU_VOLDN_CNT_OFFSET                           (0x124U)
#define PMU_GPU_VOLDN_CNT_STABLE_CNT_SHIFT                 (0U)
#define PMU_GPU_VOLDN_CNT_STABLE_CNT_MASK                  (0xFFFFFU << PMU_GPU_VOLDN_CNT_STABLE_CNT_SHIFT)             /* 0x000FFFFF */
/* WAKEUP_TIMEOUT_CNT */
#define PMU_WAKEUP_TIMEOUT_CNT_OFFSET                      (0x128U)
#define PMU_WAKEUP_TIMEOUT_CNT_WAKEUP_TIMEOUT_CNT_SHIFT    (0U)
#define PMU_WAKEUP_TIMEOUT_CNT_WAKEUP_TIMEOUT_CNT_MASK     (0xFFFFFFFFU << PMU_WAKEUP_TIMEOUT_CNT_WAKEUP_TIMEOUT_CNT_SHIFT) /* 0xFFFFFFFF */
/* PWM_SWITCH_CNT */
#define PMU_PWM_SWITCH_CNT_OFFSET                          (0x12CU)
#define PMU_PWM_SWITCH_CNT_STABLE_CNT_SHIFT                (0U)
#define PMU_PWM_SWITCH_CNT_STABLE_CNT_MASK                 (0xFFFFFFFFU << PMU_PWM_SWITCH_CNT_STABLE_CNT_SHIFT)         /* 0xFFFFFFFF */
/* DBG_RST_CNT */
#define PMU_DBG_RST_CNT_OFFSET                             (0x130U)
#define PMU_DBG_RST_CNT_DBG_RST_CNT_SHIFT                  (0U)
#define PMU_DBG_RST_CNT_DBG_RST_CNT_MASK                   (0xFFFFFFFFU << PMU_DBG_RST_CNT_DBG_RST_CNT_SHIFT)           /* 0xFFFFFFFF */
/* SYS_REG0 */
#define PMU_SYS_REG0_OFFSET                                (0x180U)
#define PMU_SYS_REG0_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG0_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG0_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG1 */
#define PMU_SYS_REG1_OFFSET                                (0x184U)
#define PMU_SYS_REG1_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG1_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG1_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG2 */
#define PMU_SYS_REG2_OFFSET                                (0x188U)
#define PMU_SYS_REG2_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG2_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG2_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG3 */
#define PMU_SYS_REG3_OFFSET                                (0x18CU)
#define PMU_SYS_REG3_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG3_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG3_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG4 */
#define PMU_SYS_REG4_OFFSET                                (0x190U)
#define PMU_SYS_REG4_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG4_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG4_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG5 */
#define PMU_SYS_REG5_OFFSET                                (0x194U)
#define PMU_SYS_REG5_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG5_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG5_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG6 */
#define PMU_SYS_REG6_OFFSET                                (0x198U)
#define PMU_SYS_REG6_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG6_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG6_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* SYS_REG7 */
#define PMU_SYS_REG7_OFFSET                                (0x19CU)
#define PMU_SYS_REG7_PMU_SYS_REG_SHIFT                     (0U)
#define PMU_SYS_REG7_PMU_SYS_REG_MASK                      (0xFFFFFFFFU << PMU_SYS_REG7_PMU_SYS_REG_SHIFT)              /* 0xFFFFFFFF */
/* DSU_PWR_CON */
#define PMU_DSU_PWR_CON_OFFSET                             (0x300U)
#define PMU_DSU_PWR_CON_DSU_PWRDN_ENA_SHIFT                (2U)
#define PMU_DSU_PWR_CON_DSU_PWRDN_ENA_MASK                 (0x1U << PMU_DSU_PWR_CON_DSU_PWRDN_ENA_SHIFT)                /* 0x00000004 */
#define PMU_DSU_PWR_CON_DSU_PWROFF_ENA_SHIFT               (3U)
#define PMU_DSU_PWR_CON_DSU_PWROFF_ENA_MASK                (0x1U << PMU_DSU_PWR_CON_DSU_PWROFF_ENA_SHIFT)               /* 0x00000008 */
#define PMU_DSU_PWR_CON_DSU_RET_ENA_SHIFT                  (6U)
#define PMU_DSU_PWR_CON_DSU_RET_ENA_MASK                   (0x1U << PMU_DSU_PWR_CON_DSU_RET_ENA_SHIFT)                  /* 0x00000040 */
#define PMU_DSU_PWR_CON_CLUSTER_CLK_SRC_GATE_ENA_SHIFT     (7U)
#define PMU_DSU_PWR_CON_CLUSTER_CLK_SRC_GATE_ENA_MASK      (0x1U << PMU_DSU_PWR_CON_CLUSTER_CLK_SRC_GATE_ENA_SHIFT)     /* 0x00000080 */
/* DSU_PWR_SFTCON */
#define PMU_DSU_PWR_SFTCON_OFFSET                          (0x304U)
#define PMU_DSU_PWR_SFTCON_DSU_PWRDN_ENA_SHIFT             (0U)
#define PMU_DSU_PWR_SFTCON_DSU_PWRDN_ENA_MASK              (0x1U << PMU_DSU_PWR_SFTCON_DSU_PWRDN_ENA_SHIFT)             /* 0x00000001 */
#define PMU_DSU_PWR_SFTCON_CLUSTER_CLK_SRC_GATE_CFG_SHIFT  (7U)
#define PMU_DSU_PWR_SFTCON_CLUSTER_CLK_SRC_GATE_CFG_MASK   (0x1U << PMU_DSU_PWR_SFTCON_CLUSTER_CLK_SRC_GATE_CFG_SHIFT)  /* 0x00000080 */
/* DSU_AUTO_CON */
#define PMU_DSU_AUTO_CON_OFFSET                            (0x308U)
#define PMU_DSU_AUTO_CON_DSU_LP_ENA_SHIFT                  (0U)
#define PMU_DSU_AUTO_CON_DSU_LP_ENA_MASK                   (0x1U << PMU_DSU_AUTO_CON_DSU_LP_ENA_SHIFT)                  /* 0x00000001 */
#define PMU_DSU_AUTO_CON_DSU_INT_WAKEUP_CLUSTER_ENA_SHIFT  (1U)
#define PMU_DSU_AUTO_CON_DSU_INT_WAKEUP_CLUSTER_ENA_MASK   (0x1U << PMU_DSU_AUTO_CON_DSU_INT_WAKEUP_CLUSTER_ENA_SHIFT)  /* 0x00000002 */
#define PMU_DSU_AUTO_CON_DSU_INT_MASK_ENA_SHIFT            (2U)
#define PMU_DSU_AUTO_CON_DSU_INT_MASK_ENA_MASK             (0x1U << PMU_DSU_AUTO_CON_DSU_INT_MASK_ENA_SHIFT)            /* 0x00000004 */
#define PMU_DSU_AUTO_CON_DSU_SFT_WAKEUP_CLUSTER_ENA_SHIFT  (3U)
#define PMU_DSU_AUTO_CON_DSU_SFT_WAKEUP_CLUSTER_ENA_MASK   (0x1U << PMU_DSU_AUTO_CON_DSU_SFT_WAKEUP_CLUSTER_ENA_SHIFT)  /* 0x00000008 */
#define PMU_DSU_AUTO_CON_DSU_AUTO_RET_ENA_SHIFT            (4U)
#define PMU_DSU_AUTO_CON_DSU_AUTO_RET_ENA_MASK             (0x1U << PMU_DSU_AUTO_CON_DSU_AUTO_RET_ENA_SHIFT)            /* 0x00000010 */
/* DSU_PWR_STATE */
#define PMU_DSU_PWR_STATE_OFFSET                           (0x30CU)
#define PMU_DSU_PWR_STATE                                  (0x0U)
#define PMU_DSU_PWR_STATE_CPU0_POWER_STATE_SHIFT           (0U)
#define PMU_DSU_PWR_STATE_CPU0_POWER_STATE_MASK            (0x7U << PMU_DSU_PWR_STATE_CPU0_POWER_STATE_SHIFT)           /* 0x00000007 */
#define PMU_DSU_PWR_STATE_CPU1_POWER_STATE_SHIFT           (4U)
#define PMU_DSU_PWR_STATE_CPU1_POWER_STATE_MASK            (0x7U << PMU_DSU_PWR_STATE_CPU1_POWER_STATE_SHIFT)           /* 0x00000070 */
#define PMU_DSU_PWR_STATE_CPU2_POWER_STATE_SHIFT           (8U)
#define PMU_DSU_PWR_STATE_CPU2_POWER_STATE_MASK            (0x7U << PMU_DSU_PWR_STATE_CPU2_POWER_STATE_SHIFT)           /* 0x00000700 */
#define PMU_DSU_PWR_STATE_CPU3_POWER_STATE_SHIFT           (12U)
#define PMU_DSU_PWR_STATE_CPU3_POWER_STATE_MASK            (0x7U << PMU_DSU_PWR_STATE_CPU3_POWER_STATE_SHIFT)           /* 0x00007000 */
#define PMU_DSU_PWR_STATE_DSU_POWER_STATE_SHIFT            (16U)
#define PMU_DSU_PWR_STATE_DSU_POWER_STATE_MASK             (0x7U << PMU_DSU_PWR_STATE_DSU_POWER_STATE_SHIFT)            /* 0x00070000 */
/* CPU_AUTO_PWR_CON0 */
#define PMU_CPU_AUTO_PWR_CON0_OFFSET                       (0x310U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_PWRDN_ENA_SHIFT    (0U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_PWRDN_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_PWRDN_ENA_SHIFT)    /* 0x00000001 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_INT_WAKEUP_ENA_SHIFT    (1U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_INT_WAKEUP_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_INT_WAKEUP_ENA_SHIFT)    /* 0x00000002 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_INT_MASK_ENA_SHIFT      (2U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_INT_MASK_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_INT_MASK_ENA_SHIFT)      /* 0x00000004 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_PWRDN_ENA_SHIFT (3U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_PWRDN_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_PWRDN_ENA_SHIFT) /* 0x00000008 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_RET_ENA_SHIFT      (4U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_RET_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_AUTO_RET_ENA_SHIFT)      /* 0x00000010 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_RET_ENA_SHIFT (5U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_RET_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_SFT_WAKEUP_RET_ENA_SHIFT) /* 0x00000020 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_ENA_SHIFT     (6U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_ENA_MASK      (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_ENA_SHIFT)     /* 0x00000040 */
#define PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_RSTSRC_SHIFT  (7U)
#define PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_RSTSRC_MASK   (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU0_DBG_RECOV_RSTSRC_SHIFT)  /* 0x00000080 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_PWRDN_ENA_SHIFT    (8U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_PWRDN_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_PWRDN_ENA_SHIFT)    /* 0x00000100 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_INT_WAKEUP_ENA_SHIFT    (9U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_INT_WAKEUP_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_INT_WAKEUP_ENA_SHIFT)    /* 0x00000200 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_INT_MASK_ENA_SHIFT      (10U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_INT_MASK_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_INT_MASK_ENA_SHIFT)      /* 0x00000400 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_PWRDN_ENA_SHIFT (11U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_PWRDN_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_PWRDN_ENA_SHIFT) /* 0x00000800 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_RET_ENA_SHIFT      (12U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_RET_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_AUTO_RET_ENA_SHIFT)      /* 0x00001000 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_RET_ENA_SHIFT (13U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_RET_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_SFT_WAKEUP_RET_ENA_SHIFT) /* 0x00002000 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_ENA_SHIFT     (14U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_ENA_MASK      (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_ENA_SHIFT)     /* 0x00004000 */
#define PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_RSTSRC_SHIFT  (15U)
#define PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_RSTSRC_MASK   (0x1U << PMU_CPU_AUTO_PWR_CON0_CPU1_DBG_RECOV_RSTSRC_SHIFT)  /* 0x00008000 */
/* CPU_AUTO_PWR_CON1 */
#define PMU_CPU_AUTO_PWR_CON1_OFFSET                       (0x314U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_PWRDN_ENA_SHIFT    (0U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_PWRDN_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_PWRDN_ENA_SHIFT)    /* 0x00000001 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_INT_WAKEUP_ENA_SHIFT    (1U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_INT_WAKEUP_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_INT_WAKEUP_ENA_SHIFT)    /* 0x00000002 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_INT_MASK_ENA_SHIFT      (2U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_INT_MASK_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_INT_MASK_ENA_SHIFT)      /* 0x00000004 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_PWRDN_ENA_SHIFT (3U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_PWRDN_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_PWRDN_ENA_SHIFT) /* 0x00000008 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_RET_ENA_SHIFT      (4U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_RET_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_AUTO_RET_ENA_SHIFT)      /* 0x00000010 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_RET_ENA_SHIFT (5U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_RET_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_SFT_WAKEUP_RET_ENA_SHIFT) /* 0x00000020 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_ENA_SHIFT     (6U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_ENA_MASK      (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_ENA_SHIFT)     /* 0x00000040 */
#define PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_RSTSRC_SHIFT  (7U)
#define PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_RSTSRC_MASK   (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU2_DBG_RECOV_RSTSRC_SHIFT)  /* 0x00000080 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_PWRDN_ENA_SHIFT    (8U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_PWRDN_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_PWRDN_ENA_SHIFT)    /* 0x00000100 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_INT_WAKEUP_ENA_SHIFT    (9U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_INT_WAKEUP_ENA_MASK     (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_INT_WAKEUP_ENA_SHIFT)    /* 0x00000200 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_INT_MASK_ENA_SHIFT      (10U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_INT_MASK_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_INT_MASK_ENA_SHIFT)      /* 0x00000400 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_PWRDN_ENA_SHIFT (11U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_PWRDN_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_PWRDN_ENA_SHIFT) /* 0x00000800 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_RET_ENA_SHIFT      (12U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_RET_ENA_MASK       (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_AUTO_RET_ENA_SHIFT)      /* 0x00001000 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_RET_ENA_SHIFT (13U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_RET_ENA_MASK (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_SFT_WAKEUP_RET_ENA_SHIFT) /* 0x00002000 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_ENA_SHIFT     (14U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_ENA_MASK      (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_ENA_SHIFT)     /* 0x00004000 */
#define PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_RSTSRC_SHIFT  (15U)
#define PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_RSTSRC_MASK   (0x1U << PMU_CPU_AUTO_PWR_CON1_CPU3_DBG_RECOV_RSTSRC_SHIFT)  /* 0x00008000 */
/* CPU_PWR_SFTCON */
#define PMU_CPU_PWR_SFTCON_OFFSET                          (0x318U)
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PWRDN_ENA_SHIFT        (0U)
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PWRDN_ENA_MASK         (0x1U << PMU_CPU_PWR_SFTCON_CPU0_SFT_PWRDN_ENA_SHIFT)        /* 0x00000001 */
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_OFF_SHIFT         (1U)
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_OFF_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_OFF_SHIFT)         /* 0x00000002 */
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_ON_SHIFT          (2U)
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_ON_MASK           (0x1U << PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_ON_SHIFT)          /* 0x00000004 */
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_RET_SHIFT         (3U)
#define PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_RET_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU0_SFT_PREQ_RET_SHIFT)         /* 0x00000008 */
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PWRDN_ENA_SHIFT        (4U)
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PWRDN_ENA_MASK         (0x1U << PMU_CPU_PWR_SFTCON_CPU1_SFT_PWRDN_ENA_SHIFT)        /* 0x00000010 */
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_OFF_SHIFT         (5U)
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_OFF_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_OFF_SHIFT)         /* 0x00000020 */
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_ON_SHIFT          (6U)
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_ON_MASK           (0x1U << PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_ON_SHIFT)          /* 0x00000040 */
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_RET_SHIFT         (7U)
#define PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_RET_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU1_SFT_PREQ_RET_SHIFT)         /* 0x00000080 */
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PWRDN_ENA_SHIFT        (8U)
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PWRDN_ENA_MASK         (0x1U << PMU_CPU_PWR_SFTCON_CPU2_SFT_PWRDN_ENA_SHIFT)        /* 0x00000100 */
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_OFF_SHIFT         (9U)
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_OFF_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_OFF_SHIFT)         /* 0x00000200 */
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_ON_SHIFT          (10U)
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_ON_MASK           (0x1U << PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_ON_SHIFT)          /* 0x00000400 */
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_RET_SHIFT         (11U)
#define PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_RET_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU2_SFT_PREQ_RET_SHIFT)         /* 0x00000800 */
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PWRDN_ENA_SHIFT        (12U)
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PWRDN_ENA_MASK         (0x1U << PMU_CPU_PWR_SFTCON_CPU3_SFT_PWRDN_ENA_SHIFT)        /* 0x00001000 */
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_OFF_SHIFT         (13U)
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_OFF_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_OFF_SHIFT)         /* 0x00002000 */
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_ON_SHIFT          (14U)
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_ON_MASK           (0x1U << PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_ON_SHIFT)          /* 0x00004000 */
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_RET_SHIFT         (15U)
#define PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_RET_MASK          (0x1U << PMU_CPU_PWR_SFTCON_CPU3_SFT_PREQ_RET_SHIFT)         /* 0x00008000 */
/* CLUSTER_PWR_ST */
#define PMU_CLUSTER_PWR_ST_OFFSET                          (0x31CU)
#define PMU_CLUSTER_PWR_ST                                 (0x0U)
#define PMU_CLUSTER_PWR_ST_CPU0_DWN_STATE_SHIFT            (0U)
#define PMU_CLUSTER_PWR_ST_CPU0_DWN_STATE_MASK             (0x1U << PMU_CLUSTER_PWR_ST_CPU0_DWN_STATE_SHIFT)            /* 0x00000001 */
#define PMU_CLUSTER_PWR_ST_CPU1_DWN_STATE_SHIFT            (1U)
#define PMU_CLUSTER_PWR_ST_CPU1_DWN_STATE_MASK             (0x1U << PMU_CLUSTER_PWR_ST_CPU1_DWN_STATE_SHIFT)            /* 0x00000002 */
#define PMU_CLUSTER_PWR_ST_CPU2_DWN_STATE_SHIFT            (2U)
#define PMU_CLUSTER_PWR_ST_CPU2_DWN_STATE_MASK             (0x1U << PMU_CLUSTER_PWR_ST_CPU2_DWN_STATE_SHIFT)            /* 0x00000004 */
#define PMU_CLUSTER_PWR_ST_CPU3_DWN_STATE_SHIFT            (3U)
#define PMU_CLUSTER_PWR_ST_CPU3_DWN_STATE_MASK             (0x1U << PMU_CLUSTER_PWR_ST_CPU3_DWN_STATE_SHIFT)            /* 0x00000008 */
#define PMU_CLUSTER_PWR_ST_DSU_DWN_STATE_SHIFT             (4U)
#define PMU_CLUSTER_PWR_ST_DSU_DWN_STATE_MASK              (0x1U << PMU_CLUSTER_PWR_ST_DSU_DWN_STATE_SHIFT)             /* 0x00000010 */
#define PMU_CLUSTER_PWR_ST_CLUSTER_PREQ_ACCEPED_SHIFT      (7U)
#define PMU_CLUSTER_PWR_ST_CLUSTER_PREQ_ACCEPED_MASK       (0x1U << PMU_CLUSTER_PWR_ST_CLUSTER_PREQ_ACCEPED_SHIFT)      /* 0x00000080 */
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_MEMRET_SHIFT (8U)
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_MEMRET_MASK  (0x1U << PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_MEMRET_SHIFT) /* 0x00000100 */
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FUNCRET_SHIFT (9U)
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FUNCRET_MASK (0x1U << PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FUNCRET_SHIFT) /* 0x00000200 */
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_ON_SHIFT     (10U)
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_ON_MASK      (0x1U << PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_ON_SHIFT)     /* 0x00000400 */
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FULL_SHIFT   (11U)
#define PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FULL_MASK    (0x1U << PMU_CLUSTER_PWR_ST_CLUSTERPACTIVE_BIT_FULL_SHIFT)   /* 0x00000800 */
#define PMU_CLUSTER_PWR_ST_CPU0_PREQ_ACCEPED_SHIFT         (12U)
#define PMU_CLUSTER_PWR_ST_CPU0_PREQ_ACCEPED_MASK          (0x1U << PMU_CLUSTER_PWR_ST_CPU0_PREQ_ACCEPED_SHIFT)         /* 0x00001000 */
#define PMU_CLUSTER_PWR_ST_CPU1_PREQ_ACCEPED_SHIFT         (13U)
#define PMU_CLUSTER_PWR_ST_CPU1_PREQ_ACCEPED_MASK          (0x1U << PMU_CLUSTER_PWR_ST_CPU1_PREQ_ACCEPED_SHIFT)         /* 0x00002000 */
#define PMU_CLUSTER_PWR_ST_CPU2_PREQ_ACCEPED_SHIFT         (14U)
#define PMU_CLUSTER_PWR_ST_CPU2_PREQ_ACCEPED_MASK          (0x1U << PMU_CLUSTER_PWR_ST_CPU2_PREQ_ACCEPED_SHIFT)         /* 0x00004000 */
#define PMU_CLUSTER_PWR_ST_CPU3_PREQ_ACCEPED_SHIFT         (15U)
#define PMU_CLUSTER_PWR_ST_CPU3_PREQ_ACCEPED_MASK          (0x1U << PMU_CLUSTER_PWR_ST_CPU3_PREQ_ACCEPED_SHIFT)         /* 0x00008000 */
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_EMUOFF_SHIFT           (16U)
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_EMUOFF_MASK            (0x1U << PMU_CLUSTER_PWR_ST_CPU0_BIT_EMUOFF_SHIFT)           /* 0x00010000 */
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_FULLRET_SHIFT          (17U)
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_FULLRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU0_BIT_FULLRET_SHIFT)          /* 0x00020000 */
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_FUNCRET_SHIFT          (18U)
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_FUNCRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU0_BIT_FUNCRET_SHIFT)          /* 0x00040000 */
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_ON_SHIFT               (19U)
#define PMU_CLUSTER_PWR_ST_CPU0_BIT_ON_MASK                (0x1U << PMU_CLUSTER_PWR_ST_CPU0_BIT_ON_SHIFT)               /* 0x00080000 */
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_EMUOFF_SHIFT           (20U)
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_EMUOFF_MASK            (0x1U << PMU_CLUSTER_PWR_ST_CPU1_BIT_EMUOFF_SHIFT)           /* 0x00100000 */
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_FULLRET_SHIFT          (21U)
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_FULLRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU1_BIT_FULLRET_SHIFT)          /* 0x00200000 */
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_FUNCRET_SHIFT          (22U)
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_FUNCRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU1_BIT_FUNCRET_SHIFT)          /* 0x00400000 */
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_ON_SHIFT               (23U)
#define PMU_CLUSTER_PWR_ST_CPU1_BIT_ON_MASK                (0x1U << PMU_CLUSTER_PWR_ST_CPU1_BIT_ON_SHIFT)               /* 0x00800000 */
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_EMUOFF_SHIFT           (24U)
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_EMUOFF_MASK            (0x1U << PMU_CLUSTER_PWR_ST_CPU2_BIT_EMUOFF_SHIFT)           /* 0x01000000 */
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_FULLRET_SHIFT          (25U)
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_FULLRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU2_BIT_FULLRET_SHIFT)          /* 0x02000000 */
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_FUNCRET_SHIFT          (26U)
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_FUNCRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU2_BIT_FUNCRET_SHIFT)          /* 0x04000000 */
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_ON_SHIFT               (27U)
#define PMU_CLUSTER_PWR_ST_CPU2_BIT_ON_MASK                (0x1U << PMU_CLUSTER_PWR_ST_CPU2_BIT_ON_SHIFT)               /* 0x08000000 */
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_EMUOFF_SHIFT           (28U)
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_EMUOFF_MASK            (0x1U << PMU_CLUSTER_PWR_ST_CPU3_BIT_EMUOFF_SHIFT)           /* 0x10000000 */
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_FULLRET_SHIFT          (29U)
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_FULLRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU3_BIT_FULLRET_SHIFT)          /* 0x20000000 */
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_FUNCRET_SHIFT          (30U)
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_FUNCRET_MASK           (0x1U << PMU_CLUSTER_PWR_ST_CPU3_BIT_FUNCRET_SHIFT)          /* 0x40000000 */
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_ON_SHIFT               (31U)
#define PMU_CLUSTER_PWR_ST_CPU3_BIT_ON_MASK                (0x1U << PMU_CLUSTER_PWR_ST_CPU3_BIT_ON_SHIFT)               /* 0x80000000 */
/* CLUSTER_IDLE_CON */
#define PMU_CLUSTER_IDLE_CON_OFFSET                        (0x320U)
#define PMU_CLUSTER_IDLE_CON_IDLE_REQ_CPU_SHIFT            (0U)
#define PMU_CLUSTER_IDLE_CON_IDLE_REQ_CPU_MASK             (0x1U << PMU_CLUSTER_IDLE_CON_IDLE_REQ_CPU_SHIFT)            /* 0x00000001 */
#define PMU_CLUSTER_IDLE_CON_DBG_PWRQ_REQ_SHIFT            (1U)
#define PMU_CLUSTER_IDLE_CON_DBG_PWRQ_REQ_MASK             (0x1U << PMU_CLUSTER_IDLE_CON_DBG_PWRQ_REQ_SHIFT)            /* 0x00000002 */
#define PMU_CLUSTER_IDLE_CON_CORE2GIC_PWRQ_REQ_SHIFT       (2U)
#define PMU_CLUSTER_IDLE_CON_CORE2GIC_PWRQ_REQ_MASK        (0x1U << PMU_CLUSTER_IDLE_CON_CORE2GIC_PWRQ_REQ_SHIFT)       /* 0x00000004 */
#define PMU_CLUSTER_IDLE_CON_GIC2CORE_PWRQ_REQ_SHIFT       (3U)
#define PMU_CLUSTER_IDLE_CON_GIC2CORE_PWRQ_REQ_MASK        (0x1U << PMU_CLUSTER_IDLE_CON_GIC2CORE_PWRQ_REQ_SHIFT)       /* 0x00000008 */
/* CLUSTER_IDLE_SFTCON */
#define PMU_CLUSTER_IDLE_SFTCON_OFFSET                     (0x324U)
#define PMU_CLUSTER_IDLE_SFTCON_IDLE_REQ_CPU_SHIFT         (0U)
#define PMU_CLUSTER_IDLE_SFTCON_IDLE_REQ_CPU_MASK          (0x1U << PMU_CLUSTER_IDLE_SFTCON_IDLE_REQ_CPU_SHIFT)         /* 0x00000001 */
#define PMU_CLUSTER_IDLE_SFTCON_DBG_PWRQ_REQ_SHIFT         (1U)
#define PMU_CLUSTER_IDLE_SFTCON_DBG_PWRQ_REQ_MASK          (0x1U << PMU_CLUSTER_IDLE_SFTCON_DBG_PWRQ_REQ_SHIFT)         /* 0x00000002 */
#define PMU_CLUSTER_IDLE_SFTCON_CORE2GIC_PWRQ_REQ_SHIFT    (2U)
#define PMU_CLUSTER_IDLE_SFTCON_CORE2GIC_PWRQ_REQ_MASK     (0x1U << PMU_CLUSTER_IDLE_SFTCON_CORE2GIC_PWRQ_REQ_SHIFT)    /* 0x00000004 */
#define PMU_CLUSTER_IDLE_SFTCON_GIC2CORE_PWRQ_REQ_SHIFT    (3U)
#define PMU_CLUSTER_IDLE_SFTCON_GIC2CORE_PWRQ_REQ_MASK     (0x1U << PMU_CLUSTER_IDLE_SFTCON_GIC2CORE_PWRQ_REQ_SHIFT)    /* 0x00000008 */
/* CLUSTER_IDLE_ACK */
#define PMU_CLUSTER_IDLE_ACK_OFFSET                        (0x328U)
#define PMU_CLUSTER_IDLE_ACK                               (0x0U)
#define PMU_CLUSTER_IDLE_ACK_IDLE_ACK_CPU_SHIFT            (0U)
#define PMU_CLUSTER_IDLE_ACK_IDLE_ACK_CPU_MASK             (0x1U << PMU_CLUSTER_IDLE_ACK_IDLE_ACK_CPU_SHIFT)            /* 0x00000001 */
#define PMU_CLUSTER_IDLE_ACK_DBG_PWRQ_ACCEPT_SHIFT         (1U)
#define PMU_CLUSTER_IDLE_ACK_DBG_PWRQ_ACCEPT_MASK          (0x1U << PMU_CLUSTER_IDLE_ACK_DBG_PWRQ_ACCEPT_SHIFT)         /* 0x00000002 */
#define PMU_CLUSTER_IDLE_ACK_CORE2GIC_PWRQ_ACCEPT_SHIFT    (2U)
#define PMU_CLUSTER_IDLE_ACK_CORE2GIC_PWRQ_ACCEPT_MASK     (0x1U << PMU_CLUSTER_IDLE_ACK_CORE2GIC_PWRQ_ACCEPT_SHIFT)    /* 0x00000004 */
#define PMU_CLUSTER_IDLE_ACK_GIC2CORE_PWRQ_ACCEPT_SHIFT    (3U)
#define PMU_CLUSTER_IDLE_ACK_GIC2CORE_PWRQ_ACCEPT_MASK     (0x1U << PMU_CLUSTER_IDLE_ACK_GIC2CORE_PWRQ_ACCEPT_SHIFT)    /* 0x00000008 */
/* CLUSTER_IDLE_ST */
#define PMU_CLUSTER_IDLE_ST_OFFSET                         (0x32CU)
#define PMU_CLUSTER_IDLE_ST                                (0x0U)
#define PMU_CLUSTER_IDLE_ST_IDLE_CPU_SHIFT                 (0U)
#define PMU_CLUSTER_IDLE_ST_IDLE_CPU_MASK                  (0x1U << PMU_CLUSTER_IDLE_ST_IDLE_CPU_SHIFT)                 /* 0x00000001 */
#define PMU_CLUSTER_IDLE_ST_DBG_PWRQ_ACTIVE_SHIFT          (1U)
#define PMU_CLUSTER_IDLE_ST_DBG_PWRQ_ACTIVE_MASK           (0x1U << PMU_CLUSTER_IDLE_ST_DBG_PWRQ_ACTIVE_SHIFT)          /* 0x00000002 */
#define PMU_CLUSTER_IDLE_ST_CORE2GIC_PWRQ_ACTIVE_SHIFT     (2U)
#define PMU_CLUSTER_IDLE_ST_CORE2GIC_PWRQ_ACTIVE_MASK      (0x1U << PMU_CLUSTER_IDLE_ST_CORE2GIC_PWRQ_ACTIVE_SHIFT)     /* 0x00000004 */
#define PMU_CLUSTER_IDLE_ST_GIC2CORE_PWRQ_ACTIVE_SHIFT     (3U)
#define PMU_CLUSTER_IDLE_ST_GIC2CORE_PWRQ_ACTIVE_MASK      (0x1U << PMU_CLUSTER_IDLE_ST_GIC2CORE_PWRQ_ACTIVE_SHIFT)     /* 0x00000008 */
/* DBG_PWR_CON */
#define PMU_DBG_PWR_CON_OFFSET                             (0x330U)
#define PMU_DBG_PWR_CON_CPU0_DBG_PWRUP_REQ_ENA_SHIFT       (0U)
#define PMU_DBG_PWR_CON_CPU0_DBG_PWRUP_REQ_ENA_MASK        (0x1U << PMU_DBG_PWR_CON_CPU0_DBG_PWRUP_REQ_ENA_SHIFT)       /* 0x00000001 */
#define PMU_DBG_PWR_CON_CPU1_DBG_PWRUP_REQ_ENA_SHIFT       (1U)
#define PMU_DBG_PWR_CON_CPU1_DBG_PWRUP_REQ_ENA_MASK        (0x1U << PMU_DBG_PWR_CON_CPU1_DBG_PWRUP_REQ_ENA_SHIFT)       /* 0x00000002 */
#define PMU_DBG_PWR_CON_CPU2_DBG_PWRUP_REQ_ENA_SHIFT       (2U)
#define PMU_DBG_PWR_CON_CPU2_DBG_PWRUP_REQ_ENA_MASK        (0x1U << PMU_DBG_PWR_CON_CPU2_DBG_PWRUP_REQ_ENA_SHIFT)       /* 0x00000004 */
#define PMU_DBG_PWR_CON_CPU3_DBG_PWRUP_REQ_ENA_SHIFT       (3U)
#define PMU_DBG_PWR_CON_CPU3_DBG_PWRUP_REQ_ENA_MASK        (0x1U << PMU_DBG_PWR_CON_CPU3_DBG_PWRUP_REQ_ENA_SHIFT)       /* 0x00000008 */
#define PMU_DBG_PWR_CON_CLUSTER_DBG_PWRUP_REQ_ENA_SHIFT    (4U)
#define PMU_DBG_PWR_CON_CLUSTER_DBG_PWRUP_REQ_ENA_MASK     (0x1U << PMU_DBG_PWR_CON_CLUSTER_DBG_PWRUP_REQ_ENA_SHIFT)    /* 0x00000010 */
/*****************************************TIMER******************************************/
/* LOAD_COUNT0 */
#define TIMER_LOAD_COUNT0_OFFSET                           (0x0U)
#define TIMER_LOAD_COUNT0_COUNT0_SHIFT                     (0U)
#define TIMER_LOAD_COUNT0_COUNT0_MASK                      (0xFFFFFFFFU << TIMER_LOAD_COUNT0_COUNT0_SHIFT)              /* 0xFFFFFFFF */
/* LOAD_COUNT1 */
#define TIMER_LOAD_COUNT1_OFFSET                           (0x4U)
#define TIMER_LOAD_COUNT1_COUNT1_SHIFT                     (0U)
#define TIMER_LOAD_COUNT1_COUNT1_MASK                      (0xFFFFFFFFU << TIMER_LOAD_COUNT1_COUNT1_SHIFT)              /* 0xFFFFFFFF */
/* CURRENT_VALUE0 */
#define TIMER_CURRENT_VALUE0_OFFSET                        (0x8U)
#define TIMER_CURRENT_VALUE0                               (0x0U)
#define TIMER_CURRENT_VALUE0_CURRENT_VALUE0_SHIFT          (0U)
#define TIMER_CURRENT_VALUE0_CURRENT_VALUE0_MASK           (0xFFFFFFFFU << TIMER_CURRENT_VALUE0_CURRENT_VALUE0_SHIFT)   /* 0xFFFFFFFF */
/* CURRENT_VALUE1 */
#define TIMER_CURRENT_VALUE1_OFFSET                        (0xCU)
#define TIMER_CURRENT_VALUE1                               (0x0U)
#define TIMER_CURRENT_VALUE1_CURRENT_VALUE1_SHIFT          (0U)
#define TIMER_CURRENT_VALUE1_CURRENT_VALUE1_MASK           (0xFFFFFFFFU << TIMER_CURRENT_VALUE1_CURRENT_VALUE1_SHIFT)   /* 0xFFFFFFFF */
/* CONTROLREG */
#define TIMER_CONTROLREG_OFFSET                            (0x10U)
#define TIMER_CONTROLREG_TIMER_ENABLE_SHIFT                (0U)
#define TIMER_CONTROLREG_TIMER_ENABLE_MASK                 (0x1U << TIMER_CONTROLREG_TIMER_ENABLE_SHIFT)                /* 0x00000001 */
#define TIMER_CONTROLREG_TIMER_MODE_SHIFT                  (1U)
#define TIMER_CONTROLREG_TIMER_MODE_MASK                   (0x1U << TIMER_CONTROLREG_TIMER_MODE_SHIFT)                  /* 0x00000002 */
#define TIMER_CONTROLREG_TIMER_INT_MASK_SHIFT              (2U)
#define TIMER_CONTROLREG_TIMER_INT_MASK_MASK               (0x1U << TIMER_CONTROLREG_TIMER_INT_MASK_SHIFT)              /* 0x00000004 */
/* INTSTATUS */
#define TIMER_INTSTATUS_OFFSET                             (0x18U)
#define TIMER_INTSTATUS_INT_PD_SHIFT                       (0U)
#define TIMER_INTSTATUS_INT_PD_MASK                        (0x1U << TIMER_INTSTATUS_INT_PD_SHIFT)                       /* 0x00000001 */
/******************************************UART******************************************/
/* RBR */
#define UART_RBR_OFFSET                                    (0x0U)
#define UART_RBR                                           (0x0U)
#define UART_RBR_DATA_INPUT_SHIFT                          (0U)
#define UART_RBR_DATA_INPUT_MASK                           (0xFFU << UART_RBR_DATA_INPUT_SHIFT)                         /* 0x000000FF */
/* DLL */
#define UART_DLL_OFFSET                                    (0x0U)
#define UART_DLL_BAUD_RATE_DIVISOR_L_SHIFT                 (0U)
#define UART_DLL_BAUD_RATE_DIVISOR_L_MASK                  (0xFFU << UART_DLL_BAUD_RATE_DIVISOR_L_SHIFT)                /* 0x000000FF */
/* THR */
#define UART_THR_OFFSET                                    (0x0U)
#define UART_THR_DATA_OUTPUT_SHIFT                         (0U)
#define UART_THR_DATA_OUTPUT_MASK                          (0xFFU << UART_THR_DATA_OUTPUT_SHIFT)                        /* 0x000000FF */
/* DLH */
#define UART_DLH_OFFSET                                    (0x4U)
#define UART_DLH_BAUD_RATE_DIVISOR_H_SHIFT                 (0U)
#define UART_DLH_BAUD_RATE_DIVISOR_H_MASK                  (0xFFU << UART_DLH_BAUD_RATE_DIVISOR_H_SHIFT)                /* 0x000000FF */
/* IER */
#define UART_IER_OFFSET                                    (0x4U)
#define UART_IER_RECEIVE_DATA_AVAILABLE_INT_EN_SHIFT       (0U)
#define UART_IER_RECEIVE_DATA_AVAILABLE_INT_EN_MASK        (0x1U << UART_IER_RECEIVE_DATA_AVAILABLE_INT_EN_SHIFT)       /* 0x00000001 */
#define UART_IER_TRANS_HOLD_EMPTY_INT_EN_SHIFT             (1U)
#define UART_IER_TRANS_HOLD_EMPTY_INT_EN_MASK              (0x1U << UART_IER_TRANS_HOLD_EMPTY_INT_EN_SHIFT)             /* 0x00000002 */
#define UART_IER_RECEIVE_LINE_STATUS_INT_EN_SHIFT          (2U)
#define UART_IER_RECEIVE_LINE_STATUS_INT_EN_MASK           (0x1U << UART_IER_RECEIVE_LINE_STATUS_INT_EN_SHIFT)          /* 0x00000004 */
#define UART_IER_MODEM_STATUS_INT_EN_SHIFT                 (3U)
#define UART_IER_MODEM_STATUS_INT_EN_MASK                  (0x1U << UART_IER_MODEM_STATUS_INT_EN_SHIFT)                 /* 0x00000008 */
#define UART_IER_PROG_THRE_INT_EN_SHIFT                    (7U)
#define UART_IER_PROG_THRE_INT_EN_MASK                     (0x1U << UART_IER_PROG_THRE_INT_EN_SHIFT)                    /* 0x00000080 */
/* FCR */
#define UART_FCR_OFFSET                                    (0x8U)
#define UART_FCR_FIFO_EN_SHIFT                             (0U)
#define UART_FCR_FIFO_EN_MASK                              (0x1U << UART_FCR_FIFO_EN_SHIFT)                             /* 0x00000001 */
#define UART_FCR_RCVR_FIFO_RESET_SHIFT                     (1U)
#define UART_FCR_RCVR_FIFO_RESET_MASK                      (0x1U << UART_FCR_RCVR_FIFO_RESET_SHIFT)                     /* 0x00000002 */
#define UART_FCR_XMIT_FIFO_RESET_SHIFT                     (2U)
#define UART_FCR_XMIT_FIFO_RESET_MASK                      (0x1U << UART_FCR_XMIT_FIFO_RESET_SHIFT)                     /* 0x00000004 */
#define UART_FCR_DMA_MODE_SHIFT                            (3U)
#define UART_FCR_DMA_MODE_MASK                             (0x1U << UART_FCR_DMA_MODE_SHIFT)                            /* 0x00000008 */
#define UART_FCR_TX_EMPTY_TRIGGER_SHIFT                    (4U)
#define UART_FCR_TX_EMPTY_TRIGGER_MASK                     (0x3U << UART_FCR_TX_EMPTY_TRIGGER_SHIFT)                    /* 0x00000030 */
#define UART_FCR_RCVR_TRIGGER_SHIFT                        (6U)
#define UART_FCR_RCVR_TRIGGER_MASK                         (0x3U << UART_FCR_RCVR_TRIGGER_SHIFT)                        /* 0x000000C0 */
/* IIR */
#define UART_IIR_OFFSET                                    (0x8U)
#define UART_IIR                                           (0x1U)
#define UART_IIR_INT_ID_SHIFT                              (0U)
#define UART_IIR_INT_ID_MASK                               (0xFU << UART_IIR_INT_ID_SHIFT)                              /* 0x0000000F */
#define UART_IIR_FIFOS_EN_SHIFT                            (6U)
#define UART_IIR_FIFOS_EN_MASK                             (0x3U << UART_IIR_FIFOS_EN_SHIFT)                            /* 0x000000C0 */
/* LCR */
#define UART_LCR_OFFSET                                    (0xCU)
#define UART_LCR_DATA_LENGTH_SEL_SHIFT                     (0U)
#define UART_LCR_DATA_LENGTH_SEL_MASK                      (0x3U << UART_LCR_DATA_LENGTH_SEL_SHIFT)                     /* 0x00000003 */
#define UART_LCR_STOP_BITS_NUM_SHIFT                       (2U)
#define UART_LCR_STOP_BITS_NUM_MASK                        (0x1U << UART_LCR_STOP_BITS_NUM_SHIFT)                       /* 0x00000004 */
#define UART_LCR_PARITY_EN_SHIFT                           (3U)
#define UART_LCR_PARITY_EN_MASK                            (0x1U << UART_LCR_PARITY_EN_SHIFT)                           /* 0x00000008 */
#define UART_LCR_EVEN_PARITY_SEL_SHIFT                     (4U)
#define UART_LCR_EVEN_PARITY_SEL_MASK                      (0x1U << UART_LCR_EVEN_PARITY_SEL_SHIFT)                     /* 0x00000010 */
#define UART_LCR_BREAK_CTRL_SHIFT                          (6U)
#define UART_LCR_BREAK_CTRL_MASK                           (0x1U << UART_LCR_BREAK_CTRL_SHIFT)                          /* 0x00000040 */
#define UART_LCR_DIV_LAT_ACCESS_SHIFT                      (7U)
#define UART_LCR_DIV_LAT_ACCESS_MASK                       (0x1U << UART_LCR_DIV_LAT_ACCESS_SHIFT)                      /* 0x00000080 */
/* MCR */
#define UART_MCR_OFFSET                                    (0x10U)
#define UART_MCR_DATA_TERMINAL_READY_SHIFT                 (0U)
#define UART_MCR_DATA_TERMINAL_READY_MASK                  (0x1U << UART_MCR_DATA_TERMINAL_READY_SHIFT)                 /* 0x00000001 */
#define UART_MCR_REQ_TO_SEND_SHIFT                         (1U)
#define UART_MCR_REQ_TO_SEND_MASK                          (0x1U << UART_MCR_REQ_TO_SEND_SHIFT)                         /* 0x00000002 */
#define UART_MCR_OUT1_SHIFT                                (2U)
#define UART_MCR_OUT1_MASK                                 (0x1U << UART_MCR_OUT1_SHIFT)                                /* 0x00000004 */
#define UART_MCR_OUT2_SHIFT                                (3U)
#define UART_MCR_OUT2_MASK                                 (0x1U << UART_MCR_OUT2_SHIFT)                                /* 0x00000008 */
#define UART_MCR_LOOPBACK_SHIFT                            (4U)
#define UART_MCR_LOOPBACK_MASK                             (0x1U << UART_MCR_LOOPBACK_SHIFT)                            /* 0x00000010 */
#define UART_MCR_AUTO_FLOW_CTRL_EN_SHIFT                   (5U)
#define UART_MCR_AUTO_FLOW_CTRL_EN_MASK                    (0x1U << UART_MCR_AUTO_FLOW_CTRL_EN_SHIFT)                   /* 0x00000020 */
#define UART_MCR_SIR_MODE_EN_SHIFT                         (6U)
#define UART_MCR_SIR_MODE_EN_MASK                          (0x1U << UART_MCR_SIR_MODE_EN_SHIFT)                         /* 0x00000040 */
/* LSR */
#define UART_LSR_OFFSET                                    (0x14U)
#define UART_LSR                                           (0x60U)
#define UART_LSR_DATA_READY_SHIFT                          (0U)
#define UART_LSR_DATA_READY_MASK                           (0x1U << UART_LSR_DATA_READY_SHIFT)                          /* 0x00000001 */
#define UART_LSR_OVERRUN_ERROR_SHIFT                       (1U)
#define UART_LSR_OVERRUN_ERROR_MASK                        (0x1U << UART_LSR_OVERRUN_ERROR_SHIFT)                       /* 0x00000002 */
#define UART_LSR_PARITY_EROR_SHIFT                         (2U)
#define UART_LSR_PARITY_EROR_MASK                          (0x1U << UART_LSR_PARITY_EROR_SHIFT)                         /* 0x00000004 */
#define UART_LSR_FRAMING_ERROR_SHIFT                       (3U)
#define UART_LSR_FRAMING_ERROR_MASK                        (0x1U << UART_LSR_FRAMING_ERROR_SHIFT)                       /* 0x00000008 */
#define UART_LSR_BREAK_INT_SHIFT                           (4U)
#define UART_LSR_BREAK_INT_MASK                            (0x1U << UART_LSR_BREAK_INT_SHIFT)                           /* 0x00000010 */
#define UART_LSR_TRANS_HOLD_REG_EMPTY_SHIFT                (5U)
#define UART_LSR_TRANS_HOLD_REG_EMPTY_MASK                 (0x1U << UART_LSR_TRANS_HOLD_REG_EMPTY_SHIFT)                /* 0x00000020 */
#define UART_LSR_TRANS_EMPTY_SHIFT                         (6U)
#define UART_LSR_TRANS_EMPTY_MASK                          (0x1U << UART_LSR_TRANS_EMPTY_SHIFT)                         /* 0x00000040 */
#define UART_LSR_RECEIVER_FIFO_ERROR_SHIFT                 (7U)
#define UART_LSR_RECEIVER_FIFO_ERROR_MASK                  (0x1U << UART_LSR_RECEIVER_FIFO_ERROR_SHIFT)                 /* 0x00000080 */
/* MSR */
#define UART_MSR_OFFSET                                    (0x18U)
#define UART_MSR                                           (0x0U)
#define UART_MSR_DELTA_CLEAR_TO_SEND_SHIFT                 (0U)
#define UART_MSR_DELTA_CLEAR_TO_SEND_MASK                  (0x1U << UART_MSR_DELTA_CLEAR_TO_SEND_SHIFT)                 /* 0x00000001 */
#define UART_MSR_DELTA_DATA_SET_READY_SHIFT                (1U)
#define UART_MSR_DELTA_DATA_SET_READY_MASK                 (0x1U << UART_MSR_DELTA_DATA_SET_READY_SHIFT)                /* 0x00000002 */
#define UART_MSR_TRAILING_EDGE_RING_INDICATOR_SHIFT        (2U)
#define UART_MSR_TRAILING_EDGE_RING_INDICATOR_MASK         (0x1U << UART_MSR_TRAILING_EDGE_RING_INDICATOR_SHIFT)        /* 0x00000004 */
#define UART_MSR_DELTA_DATA_CARRIER_DETECT_SHIFT           (3U)
#define UART_MSR_DELTA_DATA_CARRIER_DETECT_MASK            (0x1U << UART_MSR_DELTA_DATA_CARRIER_DETECT_SHIFT)           /* 0x00000008 */
#define UART_MSR_CLEAR_TO_SEND_SHIFT                       (4U)
#define UART_MSR_CLEAR_TO_SEND_MASK                        (0x1U << UART_MSR_CLEAR_TO_SEND_SHIFT)                       /* 0x00000010 */
#define UART_MSR_DATA_SET_READY_SHIFT                      (5U)
#define UART_MSR_DATA_SET_READY_MASK                       (0x1U << UART_MSR_DATA_SET_READY_SHIFT)                      /* 0x00000020 */
#define UART_MSR_RING_INDICATOR_SHIFT                      (6U)
#define UART_MSR_RING_INDICATOR_MASK                       (0x1U << UART_MSR_RING_INDICATOR_SHIFT)                      /* 0x00000040 */
#define UART_MSR_DATA_CARRIOR_DETECT_SHIFT                 (7U)
#define UART_MSR_DATA_CARRIOR_DETECT_MASK                  (0x1U << UART_MSR_DATA_CARRIOR_DETECT_SHIFT)                 /* 0x00000080 */
/* SCR */
#define UART_SCR_OFFSET                                    (0x1CU)
#define UART_SCR_TEMP_STORE_SPACE_SHIFT                    (0U)
#define UART_SCR_TEMP_STORE_SPACE_MASK                     (0xFFU << UART_SCR_TEMP_STORE_SPACE_SHIFT)                   /* 0x000000FF */
/* SRBR */
#define UART_SRBR_OFFSET                                   (0x30U)
#define UART_SRBR                                          (0x0U)
#define UART_SRBR_SHADOW_RBR_SHIFT                         (0U)
#define UART_SRBR_SHADOW_RBR_MASK                          (0xFFU << UART_SRBR_SHADOW_RBR_SHIFT)                        /* 0x000000FF */
/* STHR */
#define UART_STHR_OFFSET                                   (0x30U)
#define UART_STHR_SHADOW_THR_SHIFT                         (0U)
#define UART_STHR_SHADOW_THR_MASK                          (0xFFU << UART_STHR_SHADOW_THR_SHIFT)                        /* 0x000000FF */
/* FAR */
#define UART_FAR_OFFSET                                    (0x70U)
#define UART_FAR_FIFO_ACCESS_TEST_EN_SHIFT                 (0U)
#define UART_FAR_FIFO_ACCESS_TEST_EN_MASK                  (0x1U << UART_FAR_FIFO_ACCESS_TEST_EN_SHIFT)                 /* 0x00000001 */
/* TFR */
#define UART_TFR_OFFSET                                    (0x74U)
#define UART_TFR                                           (0x0U)
#define UART_TFR_TRANS_FIFO_READ_SHIFT                     (0U)
#define UART_TFR_TRANS_FIFO_READ_MASK                      (0xFFU << UART_TFR_TRANS_FIFO_READ_SHIFT)                    /* 0x000000FF */
/* RFW */
#define UART_RFW_OFFSET                                    (0x78U)
#define UART_RFW_RECEIVE_FIFO_WRITE_SHIFT                  (0U)
#define UART_RFW_RECEIVE_FIFO_WRITE_MASK                   (0xFFU << UART_RFW_RECEIVE_FIFO_WRITE_SHIFT)                 /* 0x000000FF */
#define UART_RFW_RECEIVE_FIFO_PARITY_ERROR_SHIFT           (8U)
#define UART_RFW_RECEIVE_FIFO_PARITY_ERROR_MASK            (0x1U << UART_RFW_RECEIVE_FIFO_PARITY_ERROR_SHIFT)           /* 0x00000100 */
#define UART_RFW_RECEIVE_FIFO_FRAMING_ERROR_SHIFT          (9U)
#define UART_RFW_RECEIVE_FIFO_FRAMING_ERROR_MASK           (0x1U << UART_RFW_RECEIVE_FIFO_FRAMING_ERROR_SHIFT)          /* 0x00000200 */
/* USR */
#define UART_USR_OFFSET                                    (0x7CU)
#define UART_USR                                           (0x6U)
#define UART_USR_UART_BUSY_SHIFT                           (0U)
#define UART_USR_UART_BUSY_MASK                            (0x1U << UART_USR_UART_BUSY_SHIFT)                           /* 0x00000001 */
#define UART_USR_TRANS_FIFO_NOT_FULL_SHIFT                 (1U)
#define UART_USR_TRANS_FIFO_NOT_FULL_MASK                  (0x1U << UART_USR_TRANS_FIFO_NOT_FULL_SHIFT)                 /* 0x00000002 */
#define UART_USR_TRASN_FIFO_EMPTY_SHIFT                    (2U)
#define UART_USR_TRASN_FIFO_EMPTY_MASK                     (0x1U << UART_USR_TRASN_FIFO_EMPTY_SHIFT)                    /* 0x00000004 */
#define UART_USR_RECEIVE_FIFO_NOT_EMPTY_SHIFT              (3U)
#define UART_USR_RECEIVE_FIFO_NOT_EMPTY_MASK               (0x1U << UART_USR_RECEIVE_FIFO_NOT_EMPTY_SHIFT)              /* 0x00000008 */
#define UART_USR_RECEIVE_FIFO_FULL_SHIFT                   (4U)
#define UART_USR_RECEIVE_FIFO_FULL_MASK                    (0x1U << UART_USR_RECEIVE_FIFO_FULL_SHIFT)                   /* 0x00000010 */
/* TFL */
#define UART_TFL_OFFSET                                    (0x80U)
#define UART_TFL                                           (0x0U)
#define UART_TFL_TRANS_FIFO_LEVEL_SHIFT                    (0U)
#define UART_TFL_TRANS_FIFO_LEVEL_MASK                     (0x3FU << UART_TFL_TRANS_FIFO_LEVEL_SHIFT)                   /* 0x0000003F */
/* RFL */
#define UART_RFL_OFFSET                                    (0x84U)
#define UART_RFL                                           (0x0U)
#define UART_RFL_RECEIVE_FIFO_LEVEL_SHIFT                  (0U)
#define UART_RFL_RECEIVE_FIFO_LEVEL_MASK                   (0x3FU << UART_RFL_RECEIVE_FIFO_LEVEL_SHIFT)                 /* 0x0000003F */
/* SRR */
#define UART_SRR_OFFSET                                    (0x88U)
#define UART_SRR_UART_RESET_SHIFT                          (0U)
#define UART_SRR_UART_RESET_MASK                           (0x1U << UART_SRR_UART_RESET_SHIFT)                          /* 0x00000001 */
#define UART_SRR_RCVR_FIFO_RESET_SHIFT                     (1U)
#define UART_SRR_RCVR_FIFO_RESET_MASK                      (0x1U << UART_SRR_RCVR_FIFO_RESET_SHIFT)                     /* 0x00000002 */
#define UART_SRR_XMIT_FIFO_RESET_SHIFT                     (2U)
#define UART_SRR_XMIT_FIFO_RESET_MASK                      (0x1U << UART_SRR_XMIT_FIFO_RESET_SHIFT)                     /* 0x00000004 */
/* SRTS */
#define UART_SRTS_OFFSET                                   (0x8CU)
#define UART_SRTS_SHADOW_REQ_TO_SEND_SHIFT                 (0U)
#define UART_SRTS_SHADOW_REQ_TO_SEND_MASK                  (0x1U << UART_SRTS_SHADOW_REQ_TO_SEND_SHIFT)                 /* 0x00000001 */
/* SBCR */
#define UART_SBCR_OFFSET                                   (0x90U)
#define UART_SBCR_SHADOW_BREAK_CTRL_SHIFT                  (0U)
#define UART_SBCR_SHADOW_BREAK_CTRL_MASK                   (0x1U << UART_SBCR_SHADOW_BREAK_CTRL_SHIFT)                  /* 0x00000001 */
/* SDMAM */
#define UART_SDMAM_OFFSET                                  (0x94U)
#define UART_SDMAM_SHADOW_DMA_MODE_SHIFT                   (0U)
#define UART_SDMAM_SHADOW_DMA_MODE_MASK                    (0x1U << UART_SDMAM_SHADOW_DMA_MODE_SHIFT)                   /* 0x00000001 */
/* SFE */
#define UART_SFE_OFFSET                                    (0x98U)
#define UART_SFE_SHADOW_FIFO_EN_SHIFT                      (0U)
#define UART_SFE_SHADOW_FIFO_EN_MASK                       (0x1U << UART_SFE_SHADOW_FIFO_EN_SHIFT)                      /* 0x00000001 */
/* SRT */
#define UART_SRT_OFFSET                                    (0x9CU)
#define UART_SRT_SHADOW_RCVR_TRIGGER_SHIFT                 (0U)
#define UART_SRT_SHADOW_RCVR_TRIGGER_MASK                  (0x3U << UART_SRT_SHADOW_RCVR_TRIGGER_SHIFT)                 /* 0x00000003 */
/* STET */
#define UART_STET_OFFSET                                   (0xA0U)
#define UART_STET_SHADOW_TX_EMPTY_TRIGGER_SHIFT            (0U)
#define UART_STET_SHADOW_TX_EMPTY_TRIGGER_MASK             (0x3U << UART_STET_SHADOW_TX_EMPTY_TRIGGER_SHIFT)            /* 0x00000003 */
/* HTX */
#define UART_HTX_OFFSET                                    (0xA4U)
#define UART_HTX_HALT_TX_EN_SHIFT                          (0U)
#define UART_HTX_HALT_TX_EN_MASK                           (0x1U << UART_HTX_HALT_TX_EN_SHIFT)                          /* 0x00000001 */
/* DMASA */
#define UART_DMASA_OFFSET                                  (0xA8U)
#define UART_DMASA_DMA_SOFTWARE_ACK_SHIFT                  (0U)
#define UART_DMASA_DMA_SOFTWARE_ACK_MASK                   (0x1U << UART_DMASA_DMA_SOFTWARE_ACK_SHIFT)                  /* 0x00000001 */
/* CPR */
#define UART_CPR_OFFSET                                    (0xF4U)
#define UART_CPR                                           (0x0U)
#define UART_CPR_APB_DATA_WIDTH_SHIFT                      (0U)
#define UART_CPR_APB_DATA_WIDTH_MASK                       (0x3U << UART_CPR_APB_DATA_WIDTH_SHIFT)                      /* 0x00000003 */
#define UART_CPR_AFCE_MODE_SHIFT                           (4U)
#define UART_CPR_AFCE_MODE_MASK                            (0x1U << UART_CPR_AFCE_MODE_SHIFT)                           /* 0x00000010 */
#define UART_CPR_THRE_MODE_SHIFT                           (5U)
#define UART_CPR_THRE_MODE_MASK                            (0x1U << UART_CPR_THRE_MODE_SHIFT)                           /* 0x00000020 */
#define UART_CPR_SIR_MODE_SHIFT                            (6U)
#define UART_CPR_SIR_MODE_MASK                             (0x1U << UART_CPR_SIR_MODE_SHIFT)                            /* 0x00000040 */
#define UART_CPR_SIR_LP_MODE_SHIFT                         (7U)
#define UART_CPR_SIR_LP_MODE_MASK                          (0x1U << UART_CPR_SIR_LP_MODE_SHIFT)                         /* 0x00000080 */
#define UART_CPR_NEW_FEAT_SHIFT                            (8U)
#define UART_CPR_NEW_FEAT_MASK                             (0x1U << UART_CPR_NEW_FEAT_SHIFT)                            /* 0x00000100 */
#define UART_CPR_FIFO_ACCESS_SHIFT                         (9U)
#define UART_CPR_FIFO_ACCESS_MASK                          (0x1U << UART_CPR_FIFO_ACCESS_SHIFT)                         /* 0x00000200 */
#define UART_CPR_FIFO_STAT_SHIFT                           (10U)
#define UART_CPR_FIFO_STAT_MASK                            (0x1U << UART_CPR_FIFO_STAT_SHIFT)                           /* 0x00000400 */
#define UART_CPR_SHADOW_SHIFT                              (11U)
#define UART_CPR_SHADOW_MASK                               (0x1U << UART_CPR_SHADOW_SHIFT)                              /* 0x00000800 */
#define UART_CPR_UART_ADD_ENCODED_PARAMS_SHIFT             (12U)
#define UART_CPR_UART_ADD_ENCODED_PARAMS_MASK              (0x1U << UART_CPR_UART_ADD_ENCODED_PARAMS_SHIFT)             /* 0x00001000 */
#define UART_CPR_DMA_EXTRA_SHIFT                           (13U)
#define UART_CPR_DMA_EXTRA_MASK                            (0x1U << UART_CPR_DMA_EXTRA_SHIFT)                           /* 0x00002000 */
#define UART_CPR_FIFO_MODE_SHIFT                           (16U)
#define UART_CPR_FIFO_MODE_MASK                            (0xFFU << UART_CPR_FIFO_MODE_SHIFT)                          /* 0x00FF0000 */
/* UCV */
#define UART_UCV_OFFSET                                    (0xF8U)
#define UART_UCV                                           (0x330372AU)
#define UART_UCV_VER_SHIFT                                 (0U)
#define UART_UCV_VER_MASK                                  (0xFFFFFFFFU << UART_UCV_VER_SHIFT)                          /* 0xFFFFFFFF */
/* CTR */
#define UART_CTR_OFFSET                                    (0xFCU)
#define UART_CTR                                           (0x44570110U)
#define UART_CTR_PERIPHERAL_ID_SHIFT                       (0U)
#define UART_CTR_PERIPHERAL_ID_MASK                        (0xFFFFFFFFU << UART_CTR_PERIPHERAL_ID_SHIFT)                /* 0xFFFFFFFF */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __RK3568_H */
