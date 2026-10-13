#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

typedef struct {
    char c[60];
    int i;
    double d;
} my_struct;

my_struct array[N];

int main(int argc, char **argv) {
    struct timespec start, stop;
    my_struct s;
    unsigned int random_val = 42;

    // initialize the array
    for(int i=0; i<N; i++) {
        array[i].i = i;
        array[i].d = i;
        memset(array[i].c, 'a', sizeof(array[i].c));
    }

    clock_gettime(CLOCK_MONOTONIC, &start);

    // the loop we want to speed up
    for(int i=0; i<N*10; i++) {
        random_val = random_val * 1103515245 + 12345;
        memcpy(&s, &array[random_val%N], sizeof(my_struct));
    }

    clock_gettime(CLOCK_MONOTONIC, &stop);

    long ns = (stop.tv_sec - start.tv_sec) * 1000000000L + (stop.tv_nsec - start.tv_nsec);

    printf("%ld.%09ld\n", ns / 1000000000L, ns % 1000000000L);

    return 0;
}
