#include <math.h>
#include <stdio.h>

int main() {
    // If change the type from `double` to `float`, it won't have any warning at all.
    double res1 = 3 * (2L + 4.5f) - 012 + 44;
    double res2 = 3 * (int)sqrt(34) - sin(6) * 5 + 0x2AF;
    long double res3 = cos(2.5f + 4) - 6 * 27L + 1526 -2.4L;
    printf("(1) 3 * (2L + 4.5f) - 012 + 44 = %lf\n", res1);
    // Some findings
    // printf("(1) 3 * (2L + 4.5f) - 012 + 44 = %f\n", res1);// Why? Does float enough to represent the value?
    printf("(2) 3 * (int)sqrt(34) - sin(6) * 5 + 0x2AF = %lf\n", res2);
    printf("(3) cos(2.5f + 4) - 6 * 27L + 1526 -2.4L = %Lf\n", res3);
    // Someone said that if the expression is directly give it as a function parameter, it will cause incorrect result.
    // However, it won't.
    // printf("(3) cos(2.5f + 4) - 6 * 27L + 1526 -2.4L = %Lf\n", cos(2.5f + 4) - 6 * 27L + 1526 -2.4L);
}