#include <stdio.h>
#include <stdlib.h>

void swapi(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

long long computeidx(int n, int *dimMax, int *pos) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res *= dimMax[i];
        res += pos[i];
    }
    return res;
}

// It doesn't need calloc cuz it overwrite everything
void permute(int rank, int *dim, double *src, double *dst, int j, int k) {
    int *swapedDim = (int *)malloc(rank * sizeof(int));
    for (int i = 0; i < rank; i++) {
        swapedDim[i] = dim[i];
    }
    swapi(&swapedDim[j], &swapedDim[k]);
    int *pos = (int *)malloc(2 * rank * sizeof(int));
    int *swapedPos = pos + rank;
    for (int i = 0; i < rank; i++) {
        pos[i] = -1;
        swapedPos[i] = -1;
    }
    int idx = 0; // point to the pos index
    // a loop to iterate all the dimensions without any rank restriction
    while (idx >= 0) {
        if (idx == rank) { // operation condition (loop to the base)
            swapi(&swapedPos[j], &swapedPos[k]);
            long long srcIdx = computeidx(rank, dim, pos);
            long long dstIdx = computeidx(rank, swapedDim, swapedPos);
            // printf("%lld %lld\n", srcIdx, dstIdx);
            dst[dstIdx] = src[srcIdx];
            swapi(&swapedPos[j], &swapedPos[k]);
            idx--;
        } else { // check idx bounds and check whether should reverse or advance
            if (pos[idx] == dim[idx] - 1) {
                pos[idx] = -1;
                swapedPos[idx] = -1;
                idx--;
            } else {
                pos[idx]++;
                swapedPos[idx]++;
                idx++;
            }
        }
    }
    free(swapedDim);
    free(pos);
}

void arrout(long long n, double *a) {
    for (long long i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\n");
}

int main() {
    double a[2][2][2][2] = {{{{2, 2}, {6, 2}}, {{4, 3}, {9, 6}}},
                            {{{10, 10}, {6, 1}}, {{6, 10}, {2, 4}}}};
    double *pa = (double *)a;
    double c[2][2][2][2] = {0};
    double *pc = (double *)c;
    int dim[4] = {2, 2, 2, 2};
    permute(4, dim, pa, pc, 1, 2);
    arrout(16, pa);
    arrout(16, pc);
    return 0;
}