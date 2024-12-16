#include <stdio.h>
#include <stdlib.h>

// 3d tensor and 2d tensor contraction
void contract(int *rankA, int *rankB, int *rankC, double *A, double *B,
              double *C) {
    if (rankA[1] != rankB[0] && rankA[0] != rankC[0] && rankB[1] != rankC[2] &&
        rankA[2] != rankC[1]) {
        printf("[ERROR] Dimension Not Meet the Requirement\n");
        return;
    }
    for (int i = 0; i < rankC[0]; i++) {
        for (int k = 0; k < rankC[1]; k++) {
            for (int l = 0; l < rankC[2]; l++) {
                double sum = 0;
                for (int j = 0; j < rankA[1]; j++) {
                    sum += A[(i * rankA[1] + j) * rankA[2] + k] *
                           B[(j * rankB[1]) + l];
                }
                C[(i * rankC[1] + k) * rankC[2] + l] = sum;
            }
        }
    }
}

int main() {
    double A[2][3][4] = {
        {{
             1,
             2,
             3,
             4,
         },
         {
             5,
             6,
             7,
             8,
         },
         {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}};
    double B[3][2] = {{1,2},{1,2},{1,2}};
    double C[2][4][2] = {0};
    int rankA[3] = {2,3,4};
    int rankB[2] = {3,2};
    int rankC[3] = {2,4,2};
    contract(rankA, rankB, rankC, (double *)A, (double *)B, (double *)C);
    for (int i = 0; i < 16; i++) {
        printf("%lf ", ((double *)C)[i]);
    }
    printf("\n");
}