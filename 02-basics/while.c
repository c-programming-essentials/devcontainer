#include <stdio.h>

int main() {
    int x = 10;
    printf("------ while loop:\n");
    while (x > 0) {              // loops 10 times
        printf("x is %d\n", x);
        x = x - 1;
    }

    int y = 0;
    printf("------ do ... while loop:\n");
    do {
        printf("y is %d\n", y);
        y = y - 1;
    } while (y > 0); // although this condition is always false, body is executed once

    return 0;
}
