#include <stdio.h>
#include <stdlib.h>
// 理论上来讲，数字一共就10个，还从1开始，实际可用其实就是9……
#define MAX 9

void permute(int n);
void print_array(int *a, int n);
void swap(int *a, int *b);
int next(int *a, int n);
int predicate_desc_r2l(int *a, int n);

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
    if (n > MAX) {
        return;
    }
    int *a = (int *)malloc((2 * n + 1) * sizeof(int));
    // 用于验证是否正确，至少数量上
    // int cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    do {
        print_array(a, n);
        // cnt++;
    } while (next(a, n));
    // printf("%d\n", cnt);
    free(a);
}

// 这里采用dfs的输出的模式，只用swap()
// `n` 变量不得不加，毕竟总不能用全局变量吧（虽然不是不行）
// 有点故意给自己加难度之嫌，说实话规律都是盯出来的
// 至少保证了线性复杂度
int next(int *a, int n) {
    // 判断位置，从后往前第一个不符合降序排列的前一个是目前正在处理的位置
    int last = predicate_desc_r2l(a, n);
    if (last == -1) {
        return 0;
    }
    // 寻找最小的大于当前处理的位置保存的数的数
    int k = n - 1;
    while (a[k] < a[last]) {
        k--;
    }
    // 交换位置
    swap(&a[k], &a[last]);
    // 使(last, n)升序（本来已降序）
    int i = last + 1, j = n - 1;
    // [last+1, n) is dscending
    while (i < j) {
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    return 1;
}

int predicate_desc_r2l(int *a, int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            return i - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    permute(n);
    return 0;
}