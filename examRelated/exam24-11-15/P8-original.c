#include <stdio.h>
#include <stdlib.h>

int fcmp(double a, double b) {
    if (a - b > 1e-6) {
        return 1;
    } else if (a - b < -1e-6) {
        return -1;
    } else {
        return 0;
    }
}

void vec_add(double *vec1, double * vec2, double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
    }
}

void vec_scalar(double *vec, int l, double scalar, double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", a[i * n + j]);
        }
        printf("\n");
    }
}

void ref_matrix(double *B, double *REFB, int m, int n) {
    double *temp = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < m * n; i++) {
        REFB[i] = B[i];
    }
    int last = 0;
    for (int j = 0; j < n - 1; j++) {
        print_matrix(REFB, 4, 4);
        if (fcmp(REFB[last * n + j], 0) == 0) {
            j++;
            goto end;
        }
        last++;
        for (int i = last; i < m; i++) {
            if (fcmp(REFB[i * n + j], 0) != 0) {
                vec_scalar(&REFB[i * n], n, - REFB[i * n + j] / REFB[(i-1) * n + j], temp);
                vec_add(&REFB[i * n], temp, &REFB[i * n], n);
            }
        }
        end:
            ;
    }
}

int main() {
    double B[16], REFB[16];
    for (int i = 0; i < 16; i++) {
        B[i] = rand() % 4;
    }
    print_matrix(B, 4, 4);
    printf("\n");
    ref_matrix(B, REFB, 4, 4);
    print_matrix(REFB, 4, 4);
}