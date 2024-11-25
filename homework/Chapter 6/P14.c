#include <stdlib.h>
#include <stdio.h>

void permute(int);
void print_array(int *, int);
void swap(int *, int *);
int next(int *, int);
int predicate_ascd_r2l(int *, int);


// 理论上来讲，数字一共就10个，还从1开始，实际可用其实就是9……
#define MAX 10

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

// pack the logic of iterator
void permute(int n) {
    int *a = (int *)malloc((2 * n + 1) * sizeof(int));
    do {
        print_array(a, n);
    } while (next(a, n));
    free(a);
}

// 如果不借助任何外部变量的话，这个有一个很好的方式定位上一次最后一个处理的位置。
// 从后往前看，升序序列往前一个，就是当前处理的位置。
// `n` 变量不得不加，毕竟总不能用全局变量吧（虽然不是不行）
int next(int *a, int n) {
    int last = predicate_ascd_r2l(a, n);
    if (last == -1) {
        return 0;
    }
    // TODO: Complete it
    return 1;
}

int predicate_ascd_r2l(int * a, int n) {
    for (int i = n-1; i > 0; i--) {
        if (a[i] > a[i-1]) {
            return i - 1;
        }
    }
    return -1;
}