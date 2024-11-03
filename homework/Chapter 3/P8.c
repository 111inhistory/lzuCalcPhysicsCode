#include <stdio.h>

double tmax(double b1, double b2, double b3) {
    double max1 = b1;
    if (b2 > b2) {
        max1 = b2;
    }
    return max1 > b3 ? max1 : b3;
}

void test_tmax() {
    printf("%d\n", tmax(4, 2, 1) - 4 <= 0.000001);
    // if use `==`, it will return 0. I don't really know why.
    printf("%d\n", tmax(2, 4, 1) - 4 <= 0.000001);
    printf("%d\n", tmax(1, 2, 4) - 4 <= 0.000001);
}

int main() {
    test_tmax();
    return 0;
}