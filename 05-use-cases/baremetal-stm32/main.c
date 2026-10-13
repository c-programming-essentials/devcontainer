/* USART2 */
#define USART2_BASE     0x40004400UL
#define USART2_SR       (*(volatile unsigned int *)(USART2_BASE + 0x00))
#define USART2_DR       (*(volatile unsigned int *)(USART2_BASE + 0x04))
#define USART2_CR1      (*(volatile unsigned int *)(USART2_BASE + 0x0C))

#define USART_SR_TXE    (1U << 7)
#define USART_CR1_UE    (1U << 13)
#define USART_CR1_TE    (1U << 3)

/* SysTick */
#define SYSTICK_BASE    0xE000E010UL
#define SYSTICK_CTRL    (*(volatile unsigned int *)(SYSTICK_BASE + 0x00))
#define SYSTICK_LOAD    (*(volatile unsigned int *)(SYSTICK_BASE + 0x04))
#define SYSTICK_VAL     (*(volatile unsigned int *)(SYSTICK_BASE + 0x08))

#define SYSTICK_ENABLE      (1U << 0)
#define SYSTICK_TICKINT     (1U << 1)
#define SYSTICK_CLKSOURCE   (1U << 2)

#define SYSTICK_HZ      1000U
#define CPU_CLOCK_HZ    72000000UL

/* EXTI */
#define EXTI_BASE       0x40013C00UL
#define EXTI_IMR        (*(volatile unsigned int *)(EXTI_BASE + 0x00))
#define EXTI_FTSR       (*(volatile unsigned int *)(EXTI_BASE + 0x08))
#define EXTI_PR         (*(volatile unsigned int *)(EXTI_BASE + 0x14))

/* NVIC */
#define NVIC_BASE       0xE000E100UL
#define NVIC_ISER0      (*(volatile unsigned int *)(NVIC_BASE + 0x00))

volatile unsigned int milliseconds = 0;
volatile int button_pressed = 0;

void SysTick_Handler(void) {
    milliseconds++;
}

// Button interrupt handler
void EXTI0_IRQHandler(void) {
    // Clear the interrupt flag
    EXTI_PR = (1U << 0);
    button_pressed = 1;
}

// Initialize serial console
void usart_init(void) {
    USART2_CR1 = USART_CR1_TE | USART_CR1_UE;
}

// Initialize the button's interrupt
void exti_init(void) {
    EXTI_PR = (1U << 0);  // clear any pending interrupts
    EXTI_IMR |= (1U << 0); // Enable interrupts for line 0 (EXTI0)
    EXTI_FTSR |= (1U << 0); // Configure interrupt trigger (falling edge)
    NVIC_ISER0 |= (1U << 6); // Enable EXTI0 interrupt in NVIC, EXTI0_IRQn = 6
}

// Print a character on the serial output
void putc(char c) {
    while (!(USART2_SR & USART_SR_TXE));
    USART2_DR = (unsigned int)c;
}

// Print a string on the serial output
void puts(const char *s) {
    while (*s)
        putc(*s++);
}

void systick_init(void) {
    // 72 MHz / 1000 Hz = 72000 cycles/ms
    SYSTICK_LOAD = (CPU_CLOCK_HZ / SYSTICK_HZ) - 1;
    SYSTICK_VAL = 0;

    SYSTICK_CTRL =
        SYSTICK_CLKSOURCE |
        SYSTICK_TICKINT |
        SYSTICK_ENABLE;
}

void delay_ms(unsigned int ms) {
    unsigned int start = milliseconds;
    while ((milliseconds - start) < ms);
}

int main(void) {
    usart_init();
    exti_init();
    systick_init();

    puts("Application started.\n");

    while (1) {
        puts("Waiting for button...");
        if(button_pressed) {
            button_pressed = 0;
            puts(" Button pressed!\n");

        } else puts("\n");

        delay_ms(500);
    }
}
