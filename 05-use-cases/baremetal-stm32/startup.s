.syntax unified
.cpu cortex-m3
.thumb

.global Reset_Handler

.section .vectors, "a", %progbits

// minimal vector table with support for handling reset, timer, and button
// press interrupts
.word _estack            @ 0x0000 0000: initial stack pointer
.word Reset_Handler      @ 0x0000 0004: reset
.org 15 * 4
.word SysTick_Handler    @ 0x0000 003c: systick
.org (16 + 6) * 4
.word EXTI0_IRQHandler   @ 0x0000 0058: EXTI Line 0

.section .text.Reset_Handler
.thumb_func

// Code entry point
Reset_Handler:
    // Zero .bss
    ldr r0, =_sbss
    ldr r1, =_ebss
    movs r2, #0
2:
    cmp r0, r1
    bhs 3f
    str r2, [r0], #4
    b 2b
3:

    // Call C main()
    bl main

1:
    b 1b
