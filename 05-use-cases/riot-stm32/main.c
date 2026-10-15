#include <stdio.h>

#include "board.h"
#include "ztimer.h"

volatile int button_pressed = 0;

// From the monitor: sysbus.gpioPortA.UserButton PressAndRelease
static void button_callback(void *arg) {
    (void)arg;
    button_pressed = 1;
}

int main(void) {
    gpio_init_int(BTN0_PIN, BTN0_MODE, GPIO_RISING, button_callback, NULL);

    printf("Application started.\n");
    
    while (1) {
        printf("Waiting for button...");
        if(button_pressed) {
            button_pressed = 0;
            printf(" Button pressed!\n");

        } else printf("\n");

        ztimer_sleep(ZTIMER_MSEC, 50);
    }

    return 0;
}