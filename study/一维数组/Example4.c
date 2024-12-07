#include <stdio.h>
#include <stdlib.h>
#define M 8

// swap has many ways to achieve, but this one is the most simple one
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&a[i], &a[n-1-i]);
    }
}

int main() {
    int a[M];
    for (int i = 0; i < M; i++) {
        a[i] = 10 * (i + 1);
    }
    for (int i = 0; i < M; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    reverse(a, M);
    for (int i = 0; i < M; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}