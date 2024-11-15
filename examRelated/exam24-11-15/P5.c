#include <stdio.h>

int sum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    printf("%d\n", sum(2147483647));
    printf("%d\n", sum(1));
    printf("%d\n", sum(0));
    printf("%d\n", sum(233));
    printf("%d\n", sum(114514));
}