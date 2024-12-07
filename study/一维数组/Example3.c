#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 15

void setrand(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
}

void calc3sum(int *a, int n, int *res) {
    // start at 2 and each loop add 3 to avoid extra boundary check
    for (int i = 2, k = 0; i < n; i += 3, k++) {
        res[k] = a[i-2] + a[i-1] + a[i];
    }
}

int main() {
    srand(time(NULL));
    int a[M];
    setrand(a, M);
    // int res[M/3]; // 这算变长数组吗？
    for (int i = 0; i < M; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int res[M];
    calc3sum(a, M, res);
    for (int i = 0; i < M / 3; i++) {
        printf("%d ", res[i]);
    }
}