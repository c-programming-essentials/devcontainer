baremetal.elf: main.c startup.s stm32f4.ld
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -ffreestanding -nostdlib -Wall \
	-Wextra -T stm32f4.ld startup.s main.c -o baremetal.elf

print-size: baremetal.elf
	arm-none-eabi-size baremetal.elf

run: baremetal.elf
	renode -P 1234 --disable-xwt run.resc

clean:
	rm -rf baremetal.elf