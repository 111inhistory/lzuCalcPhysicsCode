#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_filter1(int *filter, int *prime, int max);
int linear_filter2(int *filter, int *prime, int max);

/*returned array length is 3. */
int *gedebach(int n) {
    // init linear filter array
    int *res = (int *)malloc(3 * sizeof(int));
    res[0] = 0, res[1] = 0, res[2] = 0;
    int *filter = (int *)malloc((n + 1) * sizeof(int));
    // int prime[10000000];
    int *prime = (int *)malloc(n * sizeof(int));
    int cnt = linear_filter2(filter, prime, n);
    int last = cnt - 1;
    for (int i = 0; i < cnt; i++) {
        int p1 = prime[i];
        int remain = n-p1;
        int j = last;
        int p2 = prime[j];
        while (p2 > remain) {
            p2 = prime[--j];
        }
        last = j;
        while (j > 0) {
            if (filter[remain - p2]) {
                res[0] = p1;
                res[1] = p2;
                res[2] = n - p1 - p2;
                break;
            }
            p2 = prime[--j];
        }
        if (res[0] != 0) break;
    }
    free(filter);
    return res;
}

/*PLEASE ENSURE THAT PRIME IS BIG ENOUGH*/
int linear_filter1(int *filter, int *prime, int max) {
    int cnt = 0;
    for (int i = 0; i < max; i++) {
        filter[i] = 1;
    }
    filter[0] = filter[1] = 0;
    for (int i = 2; i < max + 1; i++) {
        if (filter[i] == 1) {
            prime[cnt++] = i;
            for (int j = i * 2; j < max + 1; j += i) {
                filter[j] = 0;
            }
        }
    }
    return cnt;
}

/*PLEASE ENSURE THAT ARRAY PRIME IS BIG ENOUGH*/
int linear_filter2(int *filter, int *prime, int max) {
    int cnt = 0;
    for (int i = 0; i < max; i++) {
        filter[i] = 1;
    }
    filter[0] = filter[1] = 0;
    for (int i = 2; i <= max; i++) {
        if (filter[i] == 1) {
            prime[cnt++] = i;
        }
        for (int j = 0,idx; j < cnt && (idx = (i * prime[j])) <= max; j++) {
            filter[idx] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}

int main(void) {
    int n;
    struct timespec start, end;
    scanf("%d", &n);
    clock_gettime(CLOCK_REALTIME, &start);
    int *res = gedebach(n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("%ld\n", start.tv_sec - start.tv_sec);
    printf("%d %d %d\n", res[0], res[1], res[2]);
    free(res);
    return 0;
}