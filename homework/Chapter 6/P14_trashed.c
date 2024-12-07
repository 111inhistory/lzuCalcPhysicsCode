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
void func114514(int *a, int *idx, int n, int idx_idx) {
    if (idx_idx == n) {
        // count += 1;
        print_array(idx, n);
        return;
    }
    // enumerate all possible combination of this position(check if it is used
    // before), then use itself to enumerate the next position.
    // if `i` loops from `n` -> 0, it will output in reverse dict order.
    for (int i = n; i > 0; i--) {
        if (a[i] == 0) { // not using 1 because it's hard
            // Mark used
            a[i] = 1;
            idx[idx_idx] = i;
            func114514(a, idx, n, idx_idx + 1);
            // Mark Unused
            a[i] = 0;
            // idx[idx_idx] does not need to be reset cuz it will be overwrite.
        }
    }
}

void permute(int n) {
    int *a = malloc((2 * n + 1) * sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) {
        a[i] = 0;
    }
    int *idx = a + n + 1;
    func114514(a, idx, n, 0);
    free(a);
}

int main() {
    int n;
    scanf("%d", &n);
    permute(n);
}