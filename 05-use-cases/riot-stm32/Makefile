APPLICATION = riot-button
BOARD ?= stm32f4discovery
RIOTBASE ?= /root/RIOT

USEMODULE += stdio_uart
USEMODULE += periph_gpio_irq
USEMODULE += ztimer
USEMODULE += ztimer_msec

include $(RIOTBASE)/Makefile.include

run: all
	renode -P 1234 --disable-xwt run.resc

print-size: all
	arm-none-eabi-size bin/stm32f4discovery/riot-button.elf