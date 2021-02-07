/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2018-2020 Rockchip Electronics Co., Ltd.
 */

#ifndef __SOC_H
#define __SOC_H
#ifdef __cplusplus
  extern "C" {
#endif

#ifndef __ASSEMBLY__
/* ================================================================================ */
/* ================                    DMA REQ                      =============== */
/* ================================================================================ */
typedef enum {
    DMA_REQ_I2S0_TX = 0,
    DMA_REQ_I2S0_RX = 1,
    DMA_REQ_I2S1_TX = 2,
    DMA_REQ_I2S1_RX = 3,
    DMA_REQ_SPI0_TX = 4,
    DMA_REQ_SPI0_RX = 5,
    DMA_REQ_SPI1_TX = 6,
    DMA_REQ_SPI1_RX = 7,
    DMA_REQ_UART0_TX = 8,
    DMA_REQ_UART0_RX = 9,
    DMA_REQ_UART2_TX = 8,
    DMA_REQ_UART2_RX = 9,
    DMA_REQ_UART1_TX = 10,
    DMA_REQ_UART1_RX = 11,
    DMA_REQ_SDMMC = 12,
    DMA_REQ_EMMC = 13,
    DMA_REQ_VOP = 14,
    DMA_REQ_HIFI_RX = 0,
    DMA_REQ_HIFI_TX = 1,
} DMA_REQ_Type;

/* ================================================================================ */
/* ================                       IRQ                      ================ */
/* ================================================================================ */
typedef enum
{
    /* -------------------  Processor Exceptions Numbers  ----------------------------- */
    NonMaskableInt_IRQn = -14, /*  2 Non Maskable Interrupt */
    HardFault_IRQn = -13, /*  3 HardFault Interrupt */
    MemoryManagement_IRQn = -12, /*  4 Memory Management Interrupt */
    BusFault_IRQn = -11, /*  5 Bus Fault Interrupt */
    UsageFault_IRQn = -10, /*  6 Usage Fault Interrupt */
    SVCall_IRQn = -5, /* 11 SV Call Interrupt */
    DebugMonitor_IRQn = -4, /* 12 Debug Monitor Interrupt */
    PendSV_IRQn = -2, /* 14 Pend SV Interrupt */
    SysTick_IRQn = -1, /* 15 System Tick Interrupt */

    /* -------------------  Processor Interrupt Numbers  ------------------------------ */
    SFC_IRQn = 0,
    SYNTH_IRQn,
    EBC_IRQn,
    EMMC_IRQn,
    SDMMC_IRQn,
    USBC_IRQn,
    DMA_IRQn,
    IMDCT_IRQn,
    WDT_IRQn,
    MAILBOX0_IRQn,
    MAILBOX1_IRQn,
    MAILBOX2_IRQn,
    MAILBOX3_IRQn,
    REV0_IRQn,
    REV1_IRQn,
    REV2_IRQn,
    PWM1_IRQn,
    PWM0_IRQn,
    TIMER1_IRQn,
    TIMER0_IRQn,
    SRADC_IRQn,
    UART5_IRQn,
    UART4_IRQn,
    UART3_IRQn,
    UART2_IRQn,
    UART1_IRQn,
    UART0_IRQn,
    SPI1_IRQn,
    SPI0_IRQn,
    I2C2_IRQn,
    I2C1_IRQn,
    I2C0_IRQn,
    I2S1_IRQn,
    I2S0_IRQn,
    HIFI_IRQn,
    PMU_IRQn,
    GPIO2_IRQn,
    GPIO1_IRQn,
    GPIO0_IRQn,
    VOP_IRQn,
    DMA2_IRQn,

    NUM_INTERRUPTS //Interrupts Total Nums

    /* Interrupts 10 .. 224 are left out */
} IRQn_Type;
#endif /* __ASSEMBLY__ */

#define NVIC_PERIPH_IRQ_NUM MAX_IRQn
#define NVIC_PERIPH_IRQ_OFFSET 16

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if defined(__CC_ARM)
#pragma push
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language = extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning 586
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM3_REV 0x0201U /* Core revision r2p1 */
#define __MPU_PRESENT 1U /* MPU present */
#define __VTOR_PRESENT 1U /* VTOR present */
#define __NVIC_PRIO_BITS 3U /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig \
    0U /* Set to 1 if different SysTick Config is used */

#ifndef __ASSEMBLY__
#include "core_cm3.h" /* Processor and core peripherals */
#include "system_rk2106.h" /* System Header */
#include <stdint.h>
#endif /* __ASSEMBLY__ */

/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if defined(__CC_ARM)
#pragma pop
#elif defined(__ICCARM__)
/* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
#pragma clang diagnostic pop
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning restore
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

#ifndef __ASSEMBLY__
/* ================================================================================ */
/* ================            Extend  Peripheral Resource         ================ */
/* ================================================================================ */
/****************************************************************************************/
/*                                                                                      */
/*                               Module Structure Section                               */
/*                                                                                      */
/****************************************************************************************/
/* GPIO Register Structure Define */
struct GPIO_REG {
    __IO uint32_t SWPORTA_DR;                         /* Address Offset: 0x0000 */
    __IO uint32_t SWPORTA_DDR;                        /* Address Offset: 0x0004 */
         uint32_t RESERVED1[(0x30 - 0x04) / 4 - 1];
    __IO uint32_t INTEN;                              /* Address Offset: 0x0030 */
    __IO uint32_t INTMASK;                            /* Address Offset: 0x0034 */
    __IO uint32_t INTTYPE_LEVEL;                      /* Address Offset: 0x0038 */
    __IO uint32_t INT_POLARITY;                       /* Address Offset: 0x003c */
    __I  uint32_t INT_STATUS;                         /* Address Offset: 0x0040 */
    __I  uint32_t INT_RAWSTATUS;                      /* Address Offset: 0x0044 */
    __IO uint32_t DEBOUNCE;                           /* Address Offset: 0x0048 */
    __O  uint32_t PORTA_EOI;                          /* Address Offset: 0x004c */
    __I  uint32_t EXT_PORTA;                          /* Address Offset: 0x0050 */
         uint32_t RESERVED2[(0x60 - 0x50) / 4 - 1];
    __IO uint32_t LS_SYNC;                            /* Address Offset: 0x0060 */
};
/* CRU Register Structure Define */
struct CRU_REG
{
    __IO uint32_t CRU_APLL_CON0;
    __IO uint32_t CRU_APLL_CON1;
    __IO uint32_t CRU_APLL_CON2;
    __IO uint32_t RESERVED1[1];
    __IO uint32_t CRU_MODE_CON;
    __IO uint32_t CRU_CLKSEL_CON[13];
    __IO uint32_t RESERVED2[2];
    __IO uint32_t CRU_CLK_FRACDIV_CON0;
    __IO uint32_t CRU_CLK_FRACDIV_CON1;
    __IO uint32_t RESERVED3[10];
    __IO uint32_t CRU_CLKGATE_CON[10];
    __IO uint32_t RESERVED4[6];
    __IO uint32_t CRU_SOFTRST[4];
    __IO uint32_t RESERVED5[4];
    __IO uint32_t CRU_STCLK_CON0;
    __IO uint32_t CRU_STCLK_CON1;
    __IO uint32_t RESERVED6[3];
    __IO uint32_t CRU_GLB_SRST_FST_VALUE;
    __IO uint32_t CRU_GLB_CNT_TH;
};

/* SDMMC Register Structure Define */
struct MMC_REG {
    __IO uint32_t CTRL;                               /* Address Offset: 0x0000 */
    __IO uint32_t PWREN;                              /* Address Offset: 0x0004 */
    __IO uint32_t CLKDIV;                             /* Address Offset: 0x0008 */
    __IO uint32_t CLKSRC;                             /* Address Offset: 0x000C */
    __IO uint32_t CLKENA;                             /* Address Offset: 0x0010 */
    __IO uint32_t TMOUT;                              /* Address Offset: 0x0014 */
    __IO uint32_t CTYPE;                              /* Address Offset: 0x0018 */
    __IO uint32_t BLKSIZ;                             /* Address Offset: 0x001C */
    __IO uint32_t BYTCNT;                             /* Address Offset: 0x0020 */
    __IO uint32_t INTMASK;                            /* Address Offset: 0x0024 */
    __IO uint32_t CMDARG;                             /* Address Offset: 0x0028 */
    __IO uint32_t CMD;                                /* Address Offset: 0x002C */
    __I  uint32_t RESP0;                              /* Address Offset: 0x0030 */
    __I  uint32_t RESP1;                              /* Address Offset: 0x0034 */
    __I  uint32_t RESP2;                              /* Address Offset: 0x0038 */
    __I  uint32_t RESP3;                              /* Address Offset: 0x003C */
    __IO uint32_t MINTSTS;                            /* Address Offset: 0x0040 */
    __IO uint32_t RINTSTS;                            /* Address Offset: 0x0044 */
    __I  uint32_t STATUS;                             /* Address Offset: 0x0048 */
    __IO uint32_t FIFOTH;                             /* Address Offset: 0x004C */
    __I  uint32_t CDETECT;                            /* Address Offset: 0x0050 */
    __IO uint32_t WRTPRT;                             /* Address Offset: 0x0054 */
    __IO uint32_t RESERVED0;                          /* Address Offset: 0x0058 */
    __I  uint32_t TCBCNT;                             /* Address Offset: 0x005C */
    __I  uint32_t TBBCNT;                             /* Address Offset: 0x0060 */
    __IO uint32_t DEBNCE;                             /* Address Offset: 0x0064 */
    __IO uint32_t USRID;                              /* Address Offset: 0x0068 */
    __I  uint32_t VERID;                              /* Address Offset: 0x006C */
    __I  uint32_t HCON;                               /* Address Offset: 0x0070 */
    __IO uint32_t UHSREG;                             /* Address Offset: 0x0074 */
    __IO uint32_t RSTN;                               /* Address Offset: 0x0078 */
    __IO uint32_t RESERVED1;                          /* Address Offset: 0x007C */
    __IO uint32_t BMOD;                               /* Address Offset: 0x0080 */
    __O  uint32_t PLDMND;                             /* Address Offset: 0x0084 */
    __IO uint32_t DBADDR;                             /* Address Offset: 0x0088 */
    __IO uint32_t IDSTS;                              /* Address Offset: 0x008C */
    __IO uint32_t IDINTEN;                            /* Address Offset: 0x0090 */
    __IO uint32_t DSCADDR;                            /* Address Offset: 0x0094 */
    __IO uint32_t BUFADDR;                            /* Address Offset: 0x0098 */
    __IO uint32_t RESERVED2[25];                      /* Address Offset: 0x009C */
    __IO uint32_t CARDTHRCTL;                         /* Address Offset: 0x0100 */
    __IO uint32_t BACKEND_POWER;                      /* Address Offset: 0x0104 */
    __IO uint32_t RESERVED3;                          /* Address Offset: 0x0108 */
    __IO uint32_t EMMCDDR_REG;                        /* Address Offset: 0x010C */
    __IO uint32_t RESERVED4[4];                       /* Address Offset: 0x0110 */
    __IO uint32_t RDYINT_GEN;                         /* Address Offset: 0x0120 */
    __IO uint32_t RESERVED5[55];                      /* Address Offset: 0x0124 */
    __IO uint32_t FIFO_BASE;                          /* Address Offset: 0x0200 */
};

/* UART Register Structure Define */
struct UART_REG {
    union {
        __I uint32_t RBR;                             /* Address Offset: 0x0000 */
        __O uint32_t THR;                             /* Address Offset: 0x0000 */
        __IO uint32_t DLL;                            /* Address Offset: 0x0000 */
    };

    union {
        __IO uint32_t DLH;                            /* Address Offset: 0x0004 */
        __IO uint32_t IER;                            /* Address Offset: 0x0004 */
    };

    union {
        __I  uint32_t IIR;                            /* Address Offset: 0x0008 */
        __O  uint32_t FCR;                            /* Address Offset: 0x0008 */
    };

    __IO uint32_t LCR;                                /* Address Offset: 0x000C */
    __IO uint32_t MCR;                                /* Address Offset: 0x0010 */
    __I  uint32_t LSR;                                /* Address Offset: 0x0014 */
    __I  uint32_t MSR;                                /* Address Offset: 0x0018 */
    __IO uint32_t SCR;                                /* Address Offset: 0x001C */
         uint32_t RESERVED0020[4];                    /* Address Offset: 0x0020 */

    union {
        __I  uint32_t SRBR;                           /* Address Offset: 0x0030 */
        __I  uint32_t STHR;                           /* Address Offset: 0x0030 */
    };
         uint32_t RESERVED0034[15];                   /* Address Offset: 0x0034 */

    __IO uint32_t FAR;                                /* Address Offset: 0x0070 */
    __I  uint32_t TFR;                                /* Address Offset: 0x0074 */
    __O  uint32_t RFW;                                /* Address Offset: 0x0078 */
    __I  uint32_t USR;                                /* Address Offset: 0x007C */
    __IO uint32_t TFL;                                /* Address Offset: 0x0080 */
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

/* GRF Register Structure Define */
struct GRF_REG
{
    __IO uint32_t GPIO_IO0MUX[4];
    __IO uint32_t GPIO_IO0PULL[4]; /* 0x10 */

    __IO uint32_t GPIO_IO1MUX[4]; /* 0x20 */
    __IO uint32_t GPIO_IO1PULL[4];

    __IO uint32_t GPIO_IO2MUX[4]; /* 0x40 */
    __IO uint32_t GPIO_IO2PULL[4];

    __IO uint32_t GRF_PVTM_CON0; /* GRF_DLL_CON0 0x60 */
    __IO uint32_t GRF_PVTM_CON1;
    __IO uint32_t GRF_PVTM_CON2;

    __IO uint32_t GRF_PVTM_STATUS0; /* GRF_DLL_STATUS0 */
    __IO uint32_t GRF_PVTM_STATUS1; /* 0x70 */

    __IO uint32_t PAD0[3];

    __IO uint32_t GRF_USBPHY_CON0; /* 0x80 */
    __IO uint32_t GRF_USBPHY_CON1;
    __IO uint32_t GRF_USBPHY_CON2;
    __IO uint32_t GRF_USBPHY_CON3;
    __IO uint32_t GRF_USBPHY_CON4; /* 0x90 */
    __IO uint32_t GRF_USBPHY_CON5;
    __IO uint32_t GRF_USBPHY_CON6;
    __IO uint32_t GRF_USBPHY_CON7;
    __IO uint32_t GRF_USBPHY_CON8; /* 0xa0 */
    __IO uint32_t GRF_USBPHY_CON9;
    __IO uint32_t GRF_USBPHY_CON10;
    __IO uint32_t GRF_USBPHY_CON11;

    __IO uint32_t GRF_UOC_CON0; /* 0xb0 */
    __IO uint32_t GRF_UOC_CON1;
    __IO uint32_t GRF_UOC_CON2;

    __IO uint32_t GRF_IOMUX_CON;
    __IO uint32_t PAD1; /* 0xc0 */
    __IO uint32_t GRF_INTER_CON0;
    __IO uint32_t PAD2;
    __IO uint32_t GRF_VREF_TRIM_CON; /* 0xcc */
    __IO uint32_t PAD3[4]; /* 0xd0 - 0xdc */
    __IO uint32_t GRF_SOC_STATUS0; /* 0xe0 */
    __IO uint32_t GRF_SOC_STATUS1;
    __IO uint32_t GRF_SOC_USB_STATUS; /* 0xe8 */
    __IO uint32_t PAD4[3]; /* 0xec - 0xf4 */
    __IO uint32_t GRF_PRJ_ID; /* f8 */
    __IO uint32_t GRF_CPU_ID;
};
/* TIMER Register Structure Define */
#define TIMER_CHAN_CNT   2
struct TIMER_REG {
    __IO uint32_t LOAD_COUNT[2];                      /* Address Offset: 0x0000 */
    __I  uint32_t CURRENT_VALUE[2];                   /* Address Offset: 0x0008 */
    __IO uint32_t CONTROLREG;                         /* Address Offset: 0x0010 */
         uint32_t RESERVED0014;                       /* Address Offset: 0x0014 */
    __O  uint32_t INTSTATUS;                          /* Address Offset: 0x0018 */
};
/* WDT Register Structure Define */
struct WDT_REG
{
    __IO uint32_t CR;
    __IO uint32_t TORR;
    __I  uint32_t CCVR;
    __IO uint32_t CRR;
    __I  uint32_t STAT;
    __I  uint32_t EOI;
};

/* MBOX Register struct define */
#define MBOX_CNT             1
#define MBOX_CHAN_CNT        4

struct MBOX_CMD_DAT {
    __IO uint32_t CMD;
    __IO uint32_t DATA;
};

struct MBOX_REG {
    __IO uint32_t          A2B_INTEN;
    __IO uint32_t          A2B_STATUS;
    struct MBOX_CMD_DAT A2B[MBOX_CHAN_CNT];
    __IO uint32_t          B2A_INTEN;
    __IO uint32_t          B2A_STATUS;
    struct MBOX_CMD_DAT B2A[MBOX_CHAN_CNT];
};

/* PMU Register Structure Define */
struct PMU_REG {
    __IO uint32_t WAKEUP_CFG[3];                      /* Address Offset: 0x0000 */
    __IO uint32_t PWRDN_CON;                          /* Address Offset: 0x000c */
    __I  uint32_t PWRDN_ST;                           /* Address Offset: 0x0010 */
    __IO uint32_t PWRMODE_CON;                        /* Address Offset: 0x0014 */
         uint32_t RESERVED0[1];                       /* Address Offset: 0x0018 */
    __IO uint32_t OSC_CNT;                            /* Address Offset: 0x001c */
    __I  uint32_t PWRDN_CNT;                          /* Address Offset: 0x0020 */
    __I  uint32_t PWRUP_CNT;                          /* Address Offset: 0x0024 */
    __IO uint32_t SFT_CON;                            /* Address Offset: 0x0028 */
    __IO uint32_t PLLLOCK_CNT;                        /* Address Offset: 0x002c */
    __IO uint32_t INT_CON;                            /* Address Offset: 0x0030 */
    __O  uint32_t INT_ST;                             /* Address Offset: 0x0034 */
    __O  uint32_t GPIO_POS_INT_ST;                    /* Address Offset: 0x0038 */
    __O  uint32_t GPIO_NEG_INT_ST;                    /* Address Offset: 0x003C */
    __IO uint32_t SYS_REG[4];                         /* Address Offset: 0x0040 */
         uint32_t RESERVED1[4];                       /* Address Offset: 0x0050 */
    __IO uint32_t GPIO_POS_INT_CON;                   /* Address Offset: 0x0060 */
    __IO uint32_t GPIO_NEG_INT_CON;                   /* Address Offset: 0x0064 */
         uint32_t RESERVED2[6];                       /* Address Offset: 0x0068 */
    __IO uint32_t SOFTRST_CON;                        /* Address Offset: 0x0080 */
};

/* SFC Register Structure Define */
struct SFC_REG {
    __IO uint32_t CTRL;                               /* Address Offset: 0x0000 */
    __IO uint32_t IMR;                                /* Address Offset: 0x0004 */
    __O  uint32_t ICLR;                               /* Address Offset: 0x0008 */
    __IO uint32_t FTLR;                               /* Address Offset: 0x000C */
    __IO uint32_t RCVR;                               /* Address Offset: 0x0010 */
    __IO uint32_t AX;                                 /* Address Offset: 0x0014 */
    __IO uint32_t ABIT;                               /* Address Offset: 0x0018 */
    __IO uint32_t ISR;                                /* Address Offset: 0x001C */
    __IO uint32_t FSR;                                /* Address Offset: 0x0020 */
    __IO uint32_t SR;                                 /* Address Offset: 0x0024 */
    __I  uint32_t RISR;                               /* Address Offset: 0x0028 */
    __IO uint32_t VER;                                /* Address Offset: 0x002C */
    __IO uint32_t QOP;                                /* Address Offset: 0x0030 */
    __IO uint32_t EXT_CTRL;                           /* Address Offset: 0x0034 */
         uint32_t RESERVED0;                          /* Address Offset: 0x0038 */
    __IO uint32_t DLL_CTRL;                           /* Address Offset: 0x003C */
         uint32_t RESERVED1[4];                       /* Address Offset: 0x0040 */
    __IO uint32_t POLL_CTRL;                          /* Address Offset: 0x0050 */
    __O  uint32_t FETCH_CMD;                          /* Address Offset: 0x0054 */
    __IO uint32_t FETCH_CTRL;                         /* Address Offset: 0x0058 */
    __IO uint32_t XIP_MODE;                           /* Address Offset: 0x005C */
    __I  uint32_t POLL_DATA;                          /* Address Offset: 0x0060 */
         uint32_t RESERVED2[7];                       /* Address Offset: 0x0064 */
    __O  uint32_t DMATR;                              /* Address Offset: 0x0080 */
    __IO uint32_t DMAADDR;                            /* Address Offset: 0x0084 */
         uint32_t RESERVED3[30];                      /* Address Offset: 0x0088 */
    __O  uint32_t CMD;                                /* Address Offset: 0x0100 */
    __O  uint32_t ADDR;                               /* Address Offset: 0x0104 */
    __IO uint32_t DATA;                               /* Address Offset: 0x0108 */
};
#endif /* __ASSEMBLY__ */
/****************************************************************************************/
/*                                                                                      */
/*                                Module Address Section                                */
/*                                                                                      */
/****************************************************************************************/
#define SRAM_BASE ((uint32_t)0x03000000)

#define ADC_BASE ((uint32_t)0x400d0000)
#define EFUSE_BASE ((uint32_t)0x40090000)
#define RTC_BASE ((uint32_t)0x400b0000)
#define NANDC_BASE ((uint32_t)0x60080000)
#define HIFIACC_BASE ((uint32_t)0x01060000)

#define I2S0_BASE ((uint32_t)0x40020000)
#define I2S1_BASE ((uint32_t)0x40030000)
#define I2C0_BASE ((uint32_t)0x40040000)
#define I2C1_BASE ((uint32_t)0x40050000)
#define I2C2_BASE ((uint32_t)0x40060000)
#define SPI0_BASE ((uint32_t)0x40070000)
#define SPI1_BASE ((uint32_t)0x40080000)
#define ACODEC_BASE ((uint32_t)0x40090000)
#define UART0_BASE ((uint32_t)0x400a0000)
#define UART1_BASE ((uint32_t)0x400b0000)
#define UART2_BASE ((uint32_t)0x400c0000)
#define SARADC_BASE ((uint32_t)0x400d0000)
#define TIMER_BASE ((uint32_t)0x400e0000)
#define PWM0_BASE ((uint32_t)0x400f0000)
#define PWM1_BASE ((uint32_t)0x40100000)
#define MBOX_BASE ((uint32_t)0x40110000)
#define WDT_BASE ((uint32_t)0x40120000)
#define UART3_BASE ((uint32_t)0x40130000)
#define UART4_BASE ((uint32_t)0x40140000)
#define UART5_BASE ((uint32_t)0x40150000)

#define GPIO0_BASE ((uint32_t)0x40160000)
#define GPIO1_BASE ((uint32_t)0x40170000)
#define CRU_BASE ((uint32_t)0x40180000)

#define GRF_BASE ((uint32_t)0x50010000)
#define PMU_BASE ((uint32_t)0x50020000)
#define GPIO2_BASE ((uint32_t)0x50030000)
#define DMA_BASE ((uint32_t)0x60000000)
#define DMA_BASE2 ((uint32_t)0x01070000)
#define IMDCT_BASE ((uint32_t)0x60010000)
#define SDMMC_BASE ((uint32_t)0x60020000)
#define EMMC_BASE ((uint32_t)0x60030000)
#define EBC_BASE ((uint32_t)0x60040000)
#define SYNTH_BASE ((uint32_t)0x60050000)
#define SFC_BASE ((uint32_t)0x60060000)
#define VOP_BASE ((uint32_t)0x60070000)
#define USB_BASE ((uint32_t)0x60080000)

#define SDC0_ADDR ((uint32_t)0x60020000)
#define SDC0_FIFO_ADDR (SDC0_ADDR + 0x200)
#define EMMC_ADDR ((uint32_t)0x60030000)
#define EMMC_FIFO_ADDR (EMMC_ADDR + 0x200)

#define MBOX0_BASE MBOX_BASE
/****************************************************************************************/
/*                                                                                      */
/*                               Module Variable Section                                */
/*                                                                                      */
/****************************************************************************************/
/* Module Variable Define */
#define MBOX0               ((struct MBOX_REG *) MBOX0_BASE)
#define PMU                 ((struct PMU_REG *) PMU_BASE)
#define GRF                 ((struct GRF_REG *) GRF_BASE)
#define TIMER0              ((struct TIMER_REG *) TIMER_BASE)
#define TIMER1              ((struct TIMER_REG *) (TIMER_BASE + 0x20))
#define SFC                 ((struct SFC_REG *) SFC_BASE)
#define UART0               ((struct UART_REG *) UART0_BASE)
#define UART1               ((struct UART_REG *) UART1_BASE)
#define UART2               ((struct UART_REG *) UART2_BASE)
#define UART3               ((struct UART_REG *) UART3_BASE)
#define UART4               ((struct UART_REG *) UART4_BASE)
#define UART5               ((struct UART_REG *) UART5_BASE)
#define GPIO0               ((struct GPIO_REG *) GPIO0_BASE)
#define GPIO1               ((struct GPIO_REG *) GPIO1_BASE)
#define GPIO2               ((struct GPIO_REG *) GPIO2_BASE)

#define IS_TIMER_INSTANCE(instance) (((instance) == TIMER0) || ((instance) == TIMER1))
#define IS_MBOX_INSTANCE(instance) ((instance) == MBOX0)
#define IS_GPIO_INSTANCE(instance) (((instance) == GPIO0) || ((instance) == GPIO1) || ((instance) == GPIO2))
#define IS_SFC_INSTANCE(instance) ((instance) == SFC)
#define IS_UART_INSTANCE(instance) (((instance) == UART0) || ((instance) == UART1) || ((instance) == UART2) || ((instance) == UART3) || ((instance) == UART4) || ((instance) == UART5))

/******************************************GRF*******************************************/
#define IOMUX_GPIO2A6_IO ((uint32_t)(0))

/*****************************************CRU*******************************************/
#define PLL_INPUT_OSC_RATE       (24 * 1000 * 1000)

/*****************************************UART*******************************************/
#define UART0_TX_WORK BIT(0)
#define UART0_RX_WORK BIT(1)
#define UART1_TX_WORK BIT(2)
#define UART1_RX_WORK BIT(3)
#define UART2_TX_WORK BIT(5)
#define UART2_RX_WORK BIT(6)
#define UART3_TX_WORK BIT(7)
#define UART3_RX_WORK BIT(8)
#define UART_ERR_RX BIT(14)

#define UART_IE_TX BIT(1)
#define UART_IE_RX BIT(0)

#define UART_IF_MASK (0xFU)
#define UART_IF_THR_EMPTY (0x2U)
#define UART_IF_REC_DATA (0x4U)
#define UART_IF_C_TIMEOUT (0xCU)

/* UART_IER */
#define THRE_INT_ENABLE ((uint32_t)(1) << 7)
#define THRE_INT_DISABLE ((uint32_t)(0))
#define ENABLE_MODEM_STATUS_INT ((uint32_t)(1) << 3)
#define DISABLE_MODEM_STATUS_INT ((uint32_t)(0))
#define ENABLE_RECEIVER_LINE_STATUS_INT ((uint32_t)(1) << 2)
#define DISABLE_RECEIVER_LINE_STATUS_INT ((uint32_t)(0))
#define ENABLE_TRANSMIT_HOLDING_EM_INT ((uint32_t)(1) << 1)
#define DISABLE_TRANSMIT_HOLDING_EM_INT ((uint32_t)(0))
#define ENABLE_RECEIVER_DATA_INT ((uint32_t)(1))
#define DISABLE_RECEIVER_DATA_INT ((uint32_t)(0))

/* UART_IIR */
#define IR_MODEM_STATUS ((uint32_t)(0))
#define NO_INT_PENDING ((uint32_t)(1))
#define THR_EMPTY ((uint32_t)(2))
#define RECEIVER_DATA_AVAILABLE ((uint32_t)(0x04))
#define RECEIVER_LINE_AVAILABLE ((uint32_t)(0x06))
#define BUSY_DETECT ((uint32_t)(0x07))
#define CHARACTER_TIMEOUT ((uint32_t)(0x0c))

/* UART_LCR */
#define LCR_DLA_EN ((uint32_t)(1) << 7)
#define BREAK_CONTROL_BIT ((uint32_t)(1) << 6)
#define PARITY_DISABLED ((uint32_t)(0))
#define PARITY_ENABLED ((uint32_t)(1) << 3)
#define ONE_STOP_BIT ((uint32_t)(0))
#define ONE_HALF_OR_TWO_BIT ((uint32_t)(1) << 2)
#define LCR_WLS_5 ((uint32_t)(0x00))
#define LCR_WLS_6 ((uint32_t)(0x01))
#define LCR_WLS_7 ((uint32_t)(0x02))
#define LCR_WLS_8 ((uint32_t)(0x03))
#define UART_DATABIT_MASK ((uint32_t)(0x03))

/* UART_MCR */
#define IRDA_SIR_DISABLED ((uint32_t)(0))
#define IRDA_SIR_ENSABLED ((uint32_t)(1) << 6)
#define AUTO_FLOW_DISABLED ((uint32_t)(0))
#define AUTO_FLOW_ENSABLED ((uint32_t)(1) << 5)

/* UART_LSR */
#define THRE_BIT_EN ((uint32_t)(1) << 5)

/* UART_USR */
#define UART_RECEIVE_FIFO_EMPTY ((uint32_t)(0))
#define UART_RECEIVE_FIFO_NOT_EMPTY ((uint32_t)(1) << 3)
#define UART_TRANSMIT_FIFO_FULL ((uint32_t)(0))
#define UART_TRANSMIT_FIFO_NOT_FULL ((uint32_t)(1) << 1)

/* UART_SFE */
#define SHADOW_SHIFT ((uint32_t)(0))
#define SHADOW_FIFI_ENABLED ((uint32_t)(1))
#define SHADOW_FIFI_DISABLED ((uint32_t)(0))

/* UART_SRT */
#define RCVR_TRIGGER_SHIF ((uint32_t)(1))
#define RCVR_TRIGGER_ONE ((uint32_t)(0) << RCVR_TRIGGER_SHIF)
#define RCVR_TRIGGER_QUARTER_FIFO ((uint32_t)(1) << RCVR_TRIGGER_SHIF)
#define RCVR_TRIGGER_HALF_FIFO ((uint32_t)(2) << RCVR_TRIGGER_SHIF)
#define RCVR_TRIGGER_TWO_LESS_FIFO ((uint32_t)(3) << RCVR_TRIGGER_SHIF)

/* UART_STET */
#define TX_TRIGGER_PARA_SHIFT ((uint32_t)(3))
#define TX_TRIGGER_EMPTY ((uint32_t)(0) << TX_TRIGGER_PARA_SHIFT)
#define TX_TRIGGER_TWO_IN_FIFO ((uint32_t)(1) << TX_TRIGGER_PARA_SHIFT)
#define TX_TRIGGER_ONE_FOUR_FIFO ((uint32_t)(2) << TX_TRIGGER_PARA_SHIFT)
#define TX_TRIGGER_HALF_FIFO ((uint32_t)(3) << TX_TRIGGER_PARA_SHIFT)

/* UART_SRR */
#define UART_RESET ((uint32_t)(1))
#define RCVR_FIFO_REST ((uint32_t)(1) << 1)
#define XMIT_FIFO_RESET ((uint32_t)(1) << 2)

/* UART_FCR */
#define TX_TRIGGER_TWO ((uint32_t)(0x1) << 4) // 2 characters in the TX FIFO
#define RX_TRIGGER_HALF_FIFO ((uint32_t)(0x1) << 7) // 1/2 in the rx FIFO
#define TX_LEN_PER_INT ((uint32_t)(64)) //(16)
#define RX_LEN_PER_INT ((uint32_t)(8))

#define MODE_X_DIV 16
/*****************************************TIMER******************************************/
/* LOAD_COUNT0 */
#define TIMER_LOAD_COUNT0_TIMER_LOAD_COUNT0_SHIFT          (0U)
#define TIMER_LOAD_COUNT0_TIMER_LOAD_COUNT0_MASK           (0xFFFFFFFFU << TIMER_LOAD_COUNT0_TIMER_LOAD_COUNT0_SHIFT)   /* 0xFFFFFFFF */
/* LOAD_COUNT1 */
#define TIMER_LOAD_COUNT1_TIMER_LOAD_COUNT1_SHIFT          (0U)
#define TIMER_LOAD_COUNT1_TIMER_LOAD_COUNT1_MASK           (0xFFFFFFFFU << TIMER_LOAD_COUNT1_TIMER_LOAD_COUNT1_SHIFT)   /* 0xFFFFFFFF */
/* CURRENT_VALUE0 */
#define TIMER_CURRENT_VALUE0_TIMER_CURRENT_VALUE0_SHIFT    (0U)
#define TIMER_CURRENT_VALUE0_TIMER_CURRENT_VALUE0_MASK     (0xFFFFFFFFU << TIMER_CURRENT_VALUE0_TIMER_CURRENT_VALUE0_SHIFT) /* 0xFFFFFFFF */
/* CURRENT_VALUE1 */
#define TIMER_CURRENT_VALUE1_TIMER_CURRENT_VALUE_SHIFT     (0U)
#define TIMER_CURRENT_VALUE1_TIMER_CURRENT_VALUE_MASK      (0xFFFFFFFFU << TIMER_CURRENT_VALUE1_TIMER_CURRENT_VALUE_SHIFT) /* 0xFFFFFFFF */
/* CONTROLREG */
#define TIMER_CONTROLREG_TIMER_ENABLE_SHIFT                (0U)
#define TIMER_CONTROLREG_TIMER_ENABLE_MASK                 (0x1U << TIMER_CONTROLREG_TIMER_ENABLE_SHIFT)                /* 0x00000001 */
#define TIMER_CONTROLREG_TIMER_MODE_SHIFT                  (1U)
#define TIMER_CONTROLREG_TIMER_MODE_MASK                   (0x1U << TIMER_CONTROLREG_TIMER_MODE_SHIFT)                  /* 0x00000002 */
#define TIMER_CONTROLREG_TIMER_INT_MASK_SHIFT              (2U)
#define TIMER_CONTROLREG_TIMER_INT_MASK_MASK               (0x1U << TIMER_CONTROLREG_TIMER_INT_MASK_SHIFT)              /* 0x00000004 */
/* INTSTATUS */
#define TIMER_INTSTATUS_INTSTATUS_SHIFT                    (0U)
#define TIMER_INTSTATUS_INTSTATUS_MASK                     (0x1U << TIMER_INTSTATUS_INTSTATUS_SHIFT)                    /* 0x00000001 */
/*****************************************MMC******************************************/
/* SDMMC/EMMC/SDIO Macro Define */
#define MMC_STATUS_DATA_STATE_MC_BUSY_SHIFT (10U)
#define MMC_STATUS_DATA_STATE_MC_BUSY_MASK (0x1U)
#define MMC_STATUS_FIFO_COUNT_SHIFT (17U)
#define MMC_STATUS_FIFO_COUNT_MASK (0x1fffU)
#define MMC_STATUS_FIFO_EMPTY_SHIFT (2U)
#define MMC_STATUS_FIFO_EMPTY_MASK (0x1U)

#define MMC_FIFOTH_TX_WMARK_SHIFT (0U)
#define MMC_FIFOTH_RX_WMARK_SHIFT (16U)
#define MMC_FIFOTH_RX_WMARK_MASK (0x7ffU)
#define MMC_FIFOTH_DMA_MUTIPLE_TRANSACTION_SIZE_SHIFT (28U)
#define MMC_FIFOTH_DMA_MUTIPLE_TRANSACTION_SIZE_8 (0x2U)

/******************************************SFC*******************************************/
/* CTRL */
#define SFC_CTRL_SPIM_SHIFT                                (0U)
#define SFC_CTRL_SPIM_MASK                                 (0x1U << SFC_CTRL_SPIM_SHIFT)                                /* 0x00000001 */
#define SFC_CTRL_SHIFTPHASE_SHIFT                          (1U)
#define SFC_CTRL_SHIFTPHASE_MASK                           (0x1U << SFC_CTRL_SHIFTPHASE_SHIFT)                          /* 0x00000002 */
#define SFC_CTRL_IDLE_CYCLE_SHIFT                          (4U)
#define SFC_CTRL_IDLE_CYCLE_MASK                           (0xFU << SFC_CTRL_IDLE_CYCLE_SHIFT)                          /* 0x000000F0 */
#define SFC_CTRL_CMDB_SHIFT                                (8U)
#define SFC_CTRL_CMDB_MASK                                 (0x3U << SFC_CTRL_CMDB_SHIFT)                                /* 0x00000300 */
#define SFC_CTRL_ADRB_SHIFT                                (10U)
#define SFC_CTRL_ADRB_MASK                                 (0x3U << SFC_CTRL_ADRB_SHIFT)                                /* 0x00000C00 */
#define SFC_CTRL_DATB_SHIFT                                (12U)
#define SFC_CTRL_DATB_MASK                                 (0x3U << SFC_CTRL_DATB_SHIFT)                                /* 0x00003000 */
/* IMR */
#define SFC_IMR_RXFM_SHIFT                                 (0U)
#define SFC_IMR_RXFM_MASK                                  (0x1U << SFC_IMR_RXFM_SHIFT)                                 /* 0x00000001 */
#define SFC_IMR_RXUM_SHIFT                                 (1U)
#define SFC_IMR_RXUM_MASK                                  (0x1U << SFC_IMR_RXUM_SHIFT)                                 /* 0x00000002 */
#define SFC_IMR_TXOM_SHIFT                                 (2U)
#define SFC_IMR_TXOM_MASK                                  (0x1U << SFC_IMR_TXOM_SHIFT)                                 /* 0x00000004 */
#define SFC_IMR_TXEM_SHIFT                                 (3U)
#define SFC_IMR_TXEM_MASK                                  (0x1U << SFC_IMR_TXEM_SHIFT)                                 /* 0x00000008 */
#define SFC_IMR_TRANSM_SHIFT                               (4U)
#define SFC_IMR_TRANSM_MASK                                (0x1U << SFC_IMR_TRANSM_SHIFT)                               /* 0x00000010 */
#define SFC_IMR_AHBM_SHIFT                                 (5U)
#define SFC_IMR_AHBM_MASK                                  (0x1U << SFC_IMR_AHBM_SHIFT)                                 /* 0x00000020 */
#define SFC_IMR_NSPIM_SHIFT                                (6U)
#define SFC_IMR_NSPIM_MASK                                 (0x1U << SFC_IMR_NSPIM_SHIFT)                                /* 0x00000040 */
#define SFC_IMR_DMAM_SHIFT                                 (7U)
#define SFC_IMR_DMAM_MASK                                  (0x1U << SFC_IMR_DMAM_SHIFT)                                 /* 0x00000080 */
#define SFC_IMR_STPOLLM_SHIFT                              (8U)
#define SFC_IMR_STPOLLM_MASK                               (0x1U << SFC_IMR_STPOLLM_SHIFT)                              /* 0x00000100 */
/* ICLR */
#define SFC_ICLR_RXFC_SHIFT                                (0U)
#define SFC_ICLR_RXFC_MASK                                 (0x1U << SFC_ICLR_RXFC_SHIFT)                                /* 0x00000001 */
#define SFC_ICLR_RXUC_SHIFT                                (1U)
#define SFC_ICLR_RXUC_MASK                                 (0x1U << SFC_ICLR_RXUC_SHIFT)                                /* 0x00000002 */
#define SFC_ICLR_TXOC_SHIFT                                (2U)
#define SFC_ICLR_TXOC_MASK                                 (0x1U << SFC_ICLR_TXOC_SHIFT)                                /* 0x00000004 */
#define SFC_ICLR_TXEC_SHIFT                                (3U)
#define SFC_ICLR_TXEC_MASK                                 (0x1U << SFC_ICLR_TXEC_SHIFT)                                /* 0x00000008 */
#define SFC_ICLR_TRANSC_SHIFT                              (4U)
#define SFC_ICLR_TRANSC_MASK                               (0x1U << SFC_ICLR_TRANSC_SHIFT)                              /* 0x00000010 */
#define SFC_ICLR_AHBC_SHIFT                                (5U)
#define SFC_ICLR_AHBC_MASK                                 (0x1U << SFC_ICLR_AHBC_SHIFT)                                /* 0x00000020 */
#define SFC_ICLR_NSPIC_SHIFT                               (6U)
#define SFC_ICLR_NSPIC_MASK                                (0x1U << SFC_ICLR_NSPIC_SHIFT)                               /* 0x00000040 */
#define SFC_ICLR_DMAC_SHIFT                                (7U)
#define SFC_ICLR_DMAC_MASK                                 (0x1U << SFC_ICLR_DMAC_SHIFT)                                /* 0x00000080 */
#define SFC_ICLR_STPOLLC_SHIFT                             (8U)
#define SFC_ICLR_STPOLLC_MASK                              (0x1U << SFC_ICLR_STPOLLC_SHIFT)                             /* 0x00000100 */
/* FTLR */
#define SFC_FTLR_TXFTLR_SHIFT                              (0U)
#define SFC_FTLR_TXFTLR_MASK                               (0xFFU << SFC_FTLR_TXFTLR_SHIFT)                             /* 0x000000FF */
#define SFC_FTLR_RXFTLR_SHIFT                              (8U)
#define SFC_FTLR_RXFTLR_MASK                               (0xFFU << SFC_FTLR_RXFTLR_SHIFT)                             /* 0x0000FF00 */
/* RCVR */
#define SFC_RCVR_RCVR_SHIFT                                (0U)
#define SFC_RCVR_RCVR_MASK                                 (0x1U << SFC_RCVR_RCVR_SHIFT)                                /* 0x00000001 */
/* AX */
#define SFC_AX_AX_SHIFT                                    (0U)
#define SFC_AX_AX_MASK                                     (0xFFU << SFC_AX_AX_SHIFT)                                   /* 0x000000FF */
/* ABIT */
#define SFC_ABIT_ABIT_SHIFT                                (0U)
#define SFC_ABIT_ABIT_MASK                                 (0x1FU << SFC_ABIT_ABIT_SHIFT)                               /* 0x0000001F */
/* ISR */
#define SFC_ISR_RXFS_SHIFT                                 (0U)
#define SFC_ISR_RXFS_MASK                                  (0x1U << SFC_ISR_RXFS_SHIFT)                                 /* 0x00000001 */
#define SFC_ISR_RXUS_SHIFT                                 (1U)
#define SFC_ISR_RXUS_MASK                                  (0x1U << SFC_ISR_RXUS_SHIFT)                                 /* 0x00000002 */
#define SFC_ISR_TXOS_SHIFT                                 (2U)
#define SFC_ISR_TXOS_MASK                                  (0x1U << SFC_ISR_TXOS_SHIFT)                                 /* 0x00000004 */
#define SFC_ISR_TXES_SHIFT                                 (3U)
#define SFC_ISR_TXES_MASK                                  (0x1U << SFC_ISR_TXES_SHIFT)                                 /* 0x00000008 */
#define SFC_ISR_TRANSS_SHIFT                               (4U)
#define SFC_ISR_TRANSS_MASK                                (0x1U << SFC_ISR_TRANSS_SHIFT)                               /* 0x00000010 */
#define SFC_ISR_AHBS_SHIFT                                 (5U)
#define SFC_ISR_AHBS_MASK                                  (0x1U << SFC_ISR_AHBS_SHIFT)                                 /* 0x00000020 */
#define SFC_ISR_NSPIS_SHIFT                                (6U)
#define SFC_ISR_NSPIS_MASK                                 (0x1U << SFC_ISR_NSPIS_SHIFT)                                /* 0x00000040 */
#define SFC_ISR_DMAS_SHIFT                                 (7U)
#define SFC_ISR_DMAS_MASK                                  (0x1U << SFC_ISR_DMAS_SHIFT)                                 /* 0x00000080 */
#define SFC_ISR_STPOLLS_SHIFT                              (8U)
#define SFC_ISR_STPOLLS_MASK                               (0x1U << SFC_ISR_STPOLLS_SHIFT)                              /* 0x00000100 */
/* FSR */
#define SFC_FSR_TXFS_SHIFT                                 (0U)
#define SFC_FSR_TXFS_MASK                                  (0x1U << SFC_FSR_TXFS_SHIFT)                                 /* 0x00000001 */
#define SFC_FSR_TXES_SHIFT                                 (1U)
#define SFC_FSR_TXES_MASK                                  (0x1U << SFC_FSR_TXES_SHIFT)                                 /* 0x00000002 */
#define SFC_FSR_RXES_SHIFT                                 (2U)
#define SFC_FSR_RXES_MASK                                  (0x1U << SFC_FSR_RXES_SHIFT)                                 /* 0x00000004 */
#define SFC_FSR_RXFS_SHIFT                                 (3U)
#define SFC_FSR_RXFS_MASK                                  (0x1U << SFC_FSR_RXFS_SHIFT)                                 /* 0x00000008 */
#define SFC_FSR_TXWLVL_SHIFT                               (8U)
#define SFC_FSR_TXWLVL_MASK                                (0x1FU << SFC_FSR_TXWLVL_SHIFT)                              /* 0x00001F00 */
#define SFC_FSR_RXWLVL_SHIFT                               (16U)
#define SFC_FSR_RXWLVL_MASK                                (0x1FU << SFC_FSR_RXWLVL_SHIFT)                              /* 0x001F0000 */
/* SR */
#define SFC_SR_SR_SHIFT                                    (0U)
#define SFC_SR_SR_MASK                                     (0x1U << SFC_SR_SR_SHIFT)                                    /* 0x00000001 */
/* RISR */
#define SFC_RISR_RXFS_SHIFT                                (0U)
#define SFC_RISR_RXFS_MASK                                 (0x1U << SFC_RISR_RXFS_SHIFT)                                /* 0x00000001 */
#define SFC_RISR_RXUS_SHIFT                                (1U)
#define SFC_RISR_RXUS_MASK                                 (0x1U << SFC_RISR_RXUS_SHIFT)                                /* 0x00000002 */
#define SFC_RISR_TXOS_SHIFT                                (2U)
#define SFC_RISR_TXOS_MASK                                 (0x1U << SFC_RISR_TXOS_SHIFT)                                /* 0x00000004 */
#define SFC_RISR_TXES_SHIFT                                (3U)
#define SFC_RISR_TXES_MASK                                 (0x1U << SFC_RISR_TXES_SHIFT)                                /* 0x00000008 */
#define SFC_RISR_TRANSS_SHIFT                              (4U)
#define SFC_RISR_TRANSS_MASK                               (0x1U << SFC_RISR_TRANSS_SHIFT)                              /* 0x00000010 */
#define SFC_RISR_AHBS_SHIFT                                (5U)
#define SFC_RISR_AHBS_MASK                                 (0x1U << SFC_RISR_AHBS_SHIFT)                                /* 0x00000020 */
#define SFC_RISR_NSPIS_SHIFT                               (6U)
#define SFC_RISR_NSPIS_MASK                                (0x1U << SFC_RISR_NSPIS_SHIFT)                               /* 0x00000040 */
#define SFC_RISR_DMAS_SHIFT                                (7U)
#define SFC_RISR_DMAS_MASK                                 (0x1U << SFC_RISR_DMAS_SHIFT)                                /* 0x00000080 */
#define SFC_RISR_STPOLLS_SHIFT                             (8U)
#define SFC_RISR_STPOLLS_MASK                              (0x1U << SFC_RISR_STPOLLS_SHIFT)                             /* 0x00000100 */
/* VER */
#define SFC_VER_VER_SHIFT                                  (0U)
#define SFC_VER_VER_MASK                                   (0xFFFFU << SFC_VER_VER_SHIFT)                               /* 0x0000FFFF */
/* DMATR */
#define SFC_DMATR_DMATR_SHIFT                              (0U)
#define SFC_DMATR_DMATR_MASK                               (0x1U << SFC_DMATR_DMATR_SHIFT)                              /* 0x00000001 */
/* DMAADDR */
#define SFC_DMAADDR_DMAADDR_SHIFT                          (0U)
#define SFC_DMAADDR_DMAADDR_MASK                           (0xFFFFFFFFU << SFC_DMAADDR_DMAADDR_SHIFT)                   /* 0xFFFFFFFF */
/* CMD */
#define SFC_CMD_CMD_SHIFT                                  (0U)
#define SFC_CMD_CMD_MASK                                   (0xFFU << SFC_CMD_CMD_SHIFT)                                 /* 0x000000FF */
#define SFC_CMD_DUMM_SHIFT                                 (8U)
#define SFC_CMD_DUMM_MASK                                  (0xFU << SFC_CMD_DUMM_SHIFT)                                 /* 0x00000F00 */
#define SFC_CMD_WR_SHIFT                                   (12U)
#define SFC_CMD_WR_MASK                                    (0x1U << SFC_CMD_WR_SHIFT)                                   /* 0x00001000 */
#define SFC_CMD_CONT_SHIFT                                 (13U)
#define SFC_CMD_CONT_MASK                                  (0x1U << SFC_CMD_CONT_SHIFT)                                 /* 0x00002000 */
#define SFC_CMD_ADDRB_SHIFT                                (14U)
#define SFC_CMD_ADDRB_MASK                                 (0x3U << SFC_CMD_ADDRB_SHIFT)                                /* 0x0000C000 */
#define SFC_CMD_TRB_SHIFT                                  (16U)
#define SFC_CMD_TRB_MASK                                   (0x3FFFU << SFC_CMD_TRB_SHIFT)                               /* 0x3FFF0000 */
#define SFC_CMD_CS_SHIFT                                   (30U)
#define SFC_CMD_CS_MASK                                    (0x3U << SFC_CMD_CS_SHIFT)                                   /* 0xC0000000 */
/* ADDR */
#define SFC_ADDR_ADDR_SHIFT                                (0U)
#define SFC_ADDR_ADDR_MASK                                 (0xFFFFFFFFU << SFC_ADDR_ADDR_SHIFT)                         /* 0xFFFFFFFF */
/* DATA */
#define SFC_DATA_DATA_SHIFT                                (0U)
#define SFC_DATA_DATA_MASK                                 (0xFFFFFFFFU << SFC_DATA_DATA_SHIFT)                         /* 0xFFFFFFFF */

#define SFC_CHIP_CNT                                       (1U)

#ifndef __ASSEMBLY__
typedef uint32_t eCLOCK_Name;
#endif /* __ASSEMBLY__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __SOC_H */
