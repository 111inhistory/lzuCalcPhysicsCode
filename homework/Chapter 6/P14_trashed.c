#include <stdio.h>
#include <stdlib.h>

// int count = 0;

// lazy to makeup a name
void func114514(int *a, int *idx, int cnt, int idx_idx);

void print_array(int *a, int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

/* `a` need `cnt+1` array space, and `idx` only need `cnt` array space */
void func114514(int *a, int *idx, int cnt, int idx_idx) {
    if (idx_idx == cnt) {
        // count += 1;
        print_array(idx, cnt);
        return;
    }
    // enumerate all possible combination of this position(check if it is used
    // before), then use itself to enumerate the next position.
    for (int i = 1; i <= cnt; i++) {
        if (a[i] == 0) { // not using 1 because it's hard
            a[i] = 1;
            idx[idx_idx] = i;
            func114514(a, idx, cnt, idx_idx + 1);
            a[i] = 0;
            // idx[idx_idx] does not need to be reset cuz it will be overwrite.
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    // `malloc()`只是返回一片内存，但是不管里面有没有数据。`calloc()`会返回一段干净的，值为0的内存。
    // int *a = (int *)calloc((2 * n + 1) * sizeof(int));
    int *a = (int *)malloc((2 * n + 1) * sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) {
        a[i] = 0;
    }
    int *idx = a + n + 1;
    func114514(a, idx, n, 0);
    // printf("%d\n", count);
    free(a);
    // `a` and `idx` shouldn't be used any more.
}