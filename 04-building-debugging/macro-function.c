#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(int argc, char **argv) {
    int x = 5, y = 10;
    float a = 1.5, b = 12.42;
    int max_val = MAX(x, y);

    printf("The maximum of %d and %d is %d\n", x, y, max_val);
    printf("The maximum of %f and %f is %f\n", a, b, MAX(a, b));
    return 0;
}
