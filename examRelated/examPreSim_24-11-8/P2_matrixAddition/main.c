#include <stdio.h>
#include <stdlib.h>
#define ll long long

void scanMatrix(double *tar, ll m, ll n) {
    for (ll i = 0; i < m * n; i++) {
        // printf("scanMatrix() i = %lld", i);
        scanf("%lf", &tar[i]);
    }
}

void matrixAddition(double *matrix1, double *matrix2, double *tar, ll m, ll n) {
    for (ll i = 0; i < m * n; i++) {
        tar[i] = matrix1[i] + matrix2[i];
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    double *matrix1 = (double *)malloc(m * n * sizeof(double));
    double *matrix2 = (double *)malloc(m * n * sizeof(double));
    double *res = (double *)malloc(m * n * sizeof(double));
    scanMatrix(matrix1, m, n);
    scanMatrix(matrix2, m, n);
    matrixAddition(matrix1, matrix2, res, m, n);
    free(matrix1);free(matrix2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", res[i * n + j]);
        }
        printf("\n");
    }
    free(res);
    return 0;
}
