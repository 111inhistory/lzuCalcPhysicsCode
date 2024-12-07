#include <stdio.h>
#include <stdlib.h>

void new_link_list(int n, int *a, int *idx) {
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        idx[i] = i + 1;
    }
    idx[n - 1] = 0;
}

int circulate(int n, int m, int k) {
    if (m > n) {
        printf("You! ****ing Human! You wrong! You Enter again! \n");
        return -1;
    }
    int step = k % n + 1; // 或许算优化吧，确保每次循环都最多只遍历一遍
    int *a = (int *)malloc(2 * n * sizeof(int));
    int *idx = &a[n];
    new_link_list(n, a, idx);
    int head = m - 1, cnt = 1, last = n - 1; // 编号从1开始，但是索引从0开始
    while (n > 1) {
        if (cnt == k) {
            idx[last] = idx[head];
            idx[head] = -1;
            head = idx[last];
            cnt = 1;
            n--;
            step = k % n + 1;
        }
        last = head;
        head = idx[head];
        cnt++;
    }
    int res = a[head];
    free(a);
    return res;
}

int joseph(int n, int m, int k) {
    k = k - 1;
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int idx = m - 1;
    while (n > 1) {
        idx = (idx + k) % n;
        for (int j = idx; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        n--;
    }
    int res = a[0];
    free(a);
    return res;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", circulate(n, m, k));
}