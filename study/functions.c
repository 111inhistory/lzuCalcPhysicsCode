#include <stdio.h>

int foo(int n) {
    printf("%p", &n);
    n *= 2;
    n++;
    printf("%p", &n);
    return n;
}

int main(void) {
    int n = 10086;
    printf("%p", &n);
    printf("%d\n", foo(n));
}