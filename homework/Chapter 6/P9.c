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
        printf("You! Go Again!\n");
        return -1;
    }
    int *a = (int *)malloc(2 * n * sizeof(int));
    int *idx = &a[n];
    new_link_list(n, a, idx);
    int head = m - 1, cnt = 1, last = n - 1;
    while (n > 1) {
        if (cnt == k) {
            idx[last] = idx[head];
            idx[head] = -1;
            head = idx[last];
            cnt = 1;
            n--;
        }
        last = head;
        head = idx[head];
        cnt += 1;
    }
    return a[head];
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", circulate(n, m, k));
}