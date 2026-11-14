# C Programming Essentials: HPC Application Use Case

To build and run the unoptimized and optimized versions of the application and see a speed up, disable compiler optimizations with the `-O0` GCC flag:

```console
$ gcc hpc-original.c -O0 -o hpc-original
$ gcc hpc-optimized.c -O0 -o hpc-optimized
$ ./hpc-original
1.225121777
$ ./hpc-optimized
1.043915857
```