# C Programming Essentials: Bare Metal Application Use Case

To build and run this example, bring up a container environment as described [here](https://github.com/c-programming-essentials/devcontainer/).
Build the application as follows:

```console
$ arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -ffreestanding -nostdlib -Wall \
    -Wextra -T stm32f4.ld startup.s main.c -o baremetal.elf
```

Launch it:

```console
$ renode -P 1234 --disable-xwt run.resc
```

While the application runs, in a separate terminal you can connect to Renode's management interface and simulate a button press:

```console
$ telnet localhost 1234
(machine-0) sysbus.gpioPortA.UserButton PressAndRelease
```