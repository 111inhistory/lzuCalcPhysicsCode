#include <stdio.h>
#include <stdlib.h>

/*returned array length is 3*/
int *gedebahe(int n) {
    // init linear filter array
    int *res = (int *)malloc(3 * sizeof(int));
    res[0] = 0, res[1] = 0, res[2] = 0;
    int *filter = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        filter[i] = 1;
    }
    filter[1] = 0;
    // mark all primes
    // bit flag 0b01 means this is a prime number
    for (int i = 2; i < n + 1; i++) {
        if (filter[i] == 1) {
            for (int j = i * 2; j < n + 1; j += i) {
                filter[j] = 0;
            }
        }
    }
    // mark all n-prime
    // bit flag 0b10 means this is the remain of prime n-i
    for (int i = 2; i < n + 1; i++) {
        if (filter[i] == 1) {
            filter[n - i] |= 0b10;
        }
    }
    // if i is a n-prime, then search every prime < i that i - prime is a prime
    for (int i = n; i > 1; i--) {
        if (filter[i] & 2) {
            for (int j = 2; j <= i / 2; j++) {
                if ((filter[j] & 1) && (filter[i - j] & 1)) {
                    res[0] = n - i;
                    res[1] = j;
                    res[2] = i - j;
                }
            }
        }
    }
    free(filter);
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *res = gedebahe(n);
    printf("%d %d %d\n", res[0], res[1], res[2]);
    free(res);
    return 0;
}