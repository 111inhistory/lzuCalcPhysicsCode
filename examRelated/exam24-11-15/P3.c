#include <stdio.h>

int multi(int a, int b) {
    int res = 1;
    int min = a > b ? b : a;
    for (int i = 1; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            // printf("%d ", i);
            res *= i;
        }
    }
    return res;
}

int main() {
    printf("3和6所有公因数的乘积为%d\n", multi(3, 6));
    printf("144和24所有公因数的乘积为%d\n", multi(144, 24));
}