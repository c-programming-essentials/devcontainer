# C Programming Essentials: Embedded OS Use Case

To build and run this example, bring up a container environment as described [here](https://github.com/c-programming-essentials/devcontainer/).
Build the application as follows:

```console
$ make
...
arm-none-eabi-size bin/stm32f4discovery/riot-button.elf
   text	   data	    bss	    dec	    hex	filename
   9056	     52	   2516	  11624	   2d68	bin/stm32f4discovery/riot-button.elf
```

Run it under Renote:

```console
$ renode -P 1234 --disable-xwt run.resc
```

While the application runs, in a separate terminal you can connect to Renode's management interface and simulate a button press:

```console
$ telnet localhost 1234
(machine-0) sysbus.gpioPortA.UserButton PressAndRelease
```