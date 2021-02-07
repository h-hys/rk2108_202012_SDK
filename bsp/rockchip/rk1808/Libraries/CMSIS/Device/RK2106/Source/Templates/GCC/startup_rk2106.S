/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2020 Rockchip Electronics Co., Ltd.
 */

.syntax	unified
.cpu	cortex-m3
.fpu	softvfp
.thumb

.global    __Vectors

.extern    Image$$AP_MAIN_STACK$$RW$$Limit
.extern    __bss_start__
.extern    __bss_end__
.extern    SystemInit
.extern    Main

.equ    SYSTICK_CONTROL,    0xE000E010
.equ    RESET_CONTROL,      0xE000ED0C
.equ    HANDLER_CONTROL,    0xE000ED24
.equ    IRQ_DISABLE0,       0xE000E180

/**
 * Vector table
 */
	.section .isr_vector,"a",%progbits
	.type __Vectors, %object
	.size __Vectors, .-__Vectors
__Vectors:
        .long    Image$$AP_MAIN_STACK$$RW$$Limit    /*     Top of Stack */
        .long    Reset_Handler                      /*     Reset Handler */
        .long    Default_Handler                    /* -14 NMI Handler */
        .long    Default_Handler                    /* -13 Hard Fault Handler */
        .long    Default_Handler                    /* -12 MPU Fault Handler */
        .long    Default_Handler                    /* -11 Bus Fault Handler */
        .long    Default_Handler                    /* -10 Usage Fault Handler */
        .long    0                                  /*     Reserved */
        .long    0                                  /*     Reserved */
        .long    0                                  /*     Reserved */
        .long    0                                  /*     Reserved */
        .long    SVC_Handler                        /*  -5 SVCall Handler */
        .long    Default_Handler                    /*  -4 Debug Monitor Handler */
        .long    0                                  /*     Reserved */
        .long    PendSV_Handler                     /*  -2 PendSV Handler */
        .long    SysTick_Handler                    /*  -1 SysTick Handler */

        /* Interrupts */
        .long    Default_Handler                    /*   0 Interrupt 0 */
        .long    Default_Handler                    /*   1 Interrupt 1 */
        .long    Default_Handler                    /*   2 Interrupt 2 */
        .long    Default_Handler                    /*   3 Interrupt 3 */
        .long    Default_Handler                    /*   4 Interrupt 4 */
        .long    Default_Handler                    /*   5 Interrupt 5 */
        .long    Default_Handler                    /*   6 Interrupt 6 */
        .long    Default_Handler                    /*   7 Interrupt 7 */
        .long    Default_Handler                    /*   8 Interrupt 8 */
        .long    Default_Handler                    /*   9 Interrupt 9 */

       .space   (31 * 4)            /* Interrupts 10 .. 224 are left out */
__Vectors_End:
        .equ     __Vectors_Size, __Vectors_End - __Vectors
        .size    __Vectors, . - __Vectors

/**
 * Reset_Handler
 */
        .section .text.Reset_Handler
        .type    Reset_Handler, %function
        .globl   Reset_Handler
Reset_Handler:
        ldr     r0, =0x00000000
        ldr     r1, =0x00000000
        ldr     r2, =0x00000000
        ldr     r3, =0x00000000
        ldr     r4, =0x00000000
        ldr     r5, =0x00000000
        ldr     r6, =0x00000000
        ldr     r7, =0x00000000
        mov     r8,  r0
        mov     r9,  r0
        mov     r10, r0
        mov     r11, r0
        mov     r12, r0

        /* Disable the system handlers */
        ldr     r2, =0x00000000
        ldr     r1, =HANDLER_CONTROL
        str     r2, [r1, #0x00]

        /* Systick disable */
        ldr     r2, =0x00000000
        ldr     r1, =SYSTICK_CONTROL
        str     r2, [r1, #0x00]

        /* General interrupt disable */
        ldr     r2, =0xFFFFFFFF
        ldr     r1, =IRQ_DISABLE0
        str     r2, [r1, #0x00]
        str     r2, [r1, #0x04]
        str     r2, [r1, #0x08]
        str     r2, [r1, #0x0c]
        str     r2, [r1, #0x10]
        str     r2, [r1, #0x14]
        str     r2, [r1, #0x18]
        str     r2, [r1, #0x1c]

        /* Clear all state information for active NMI, fault, and interrupts */
        ldr     r0, =0x05FA0002
        ldr     r1, =RESET_CONTROL
        str     r0, [r1, #0x00]

        /* Zero fill the bss segment */
        ldr 	r0, =__bss_start__
        ldr     r1, =__bss_end__
        mov     r2, #0
zero_loop:
        cmp     r0, r1
        it      lt
        strlt   r2, [r0], #4
        blt     zero_loop

        /* System init */
        bl      SystemInit

        /* Ready for going to main */
        ldr     r2, =__Vectors
        ldr     r0, [r2, #0x00]
        mov     sp, r0
        mov     lr, #0
        b       Main
.size Reset_Handler, .-Reset_Handler

/**
 * Default_Handler
 */
        .section .text.Default_Handler,"ax",%progbits
Default_Handler:
        B       Default_Handler
.size Default_Handler, .-Default_Handler

/**
 * Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
        .macro   Set_Default_Handler  Handler_Name
        .weak    \Handler_Name
        .set     \Handler_Name, Default_Handler
        .endm

/* Default exception/interrupt handler */
Set_Default_Handler  SVC_Handler
Set_Default_Handler  PendSV_Handler
Set_Default_Handler  SysTick_Handler
