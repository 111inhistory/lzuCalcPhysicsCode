#include <stdio.h>
#include <stdlib.h>
#define DBL_ERR 1e-6

void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i * n + j]);
        }
        printf("\n");
    }
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void scalar_times_matrix(double scalar, double *matrix, double *res, int m,
                         int n) {
    for (int i = 0; i < m * n; i++) {
        res[i] = matrix[i] * scalar;
    }
}

/* res can be `a` or `b` itself */
void matrix_add(double *a, double *b, double *res, int m, int n) {
    for (int i = 0; i < m * n; i++) {
        res[i] = a[i] + b[i];
    }
}

int fcmp(double a, double b) {
    int sub = a - b;
    if (sub < -DBL_ERR) {
        return -1;
    } else if (sub > DBL_ERR) {
        return 1;
    } else {
        return 0;
    }
}

void row_swap(double *matrix, int src, int dst, int col) {
    double *src_row = &matrix[src * col];
    double *dst_row = &matrix[src * col];
    for (int i = 0; i < col; i++) {
        swap(&src_row[i], &dst_row[i]);
    }
}

int row_reduce(double *matrix, int m, int n) {
    double *temp = (double *)malloc(n * sizeof(double));
    int i = 0, j = 0;
    int res = 1;
    while (i < m && j < n) {
        if (fcmp(matrix[i * n + j], 0) == 0) {
            int flag = 0;
            for (int k = i + 1; k < m; k++) {
                if (fcmp(matrix[k * n + j], 0) != 0) {
                    row_swap(matrix, i, k, n);
                    res *= -1;
                }
            }
            if (flag) {
                j++;
                continue;
            }
        }
        double *src_row = &matrix[i * n];
        for (int k = i + 1; k < m; k++) {
            double scalar = -matrix[k * n + j] / matrix[i * n + j];
            scalar_times_matrix(scalar, src_row, temp, 1, n);
            matrix_add(&matrix[k * n], temp, &matrix[k * n], 1, n);
        }
        i++;
        j++;
    }
    return res;
}

double determinate(double *matrix, int m) {
    double *copy = (double *)malloc(m * m * sizeof(double));
    for (int i = 0; i < m * m; i++) {
        copy[i] = matrix[i];
    }
    double res = row_reduce(copy, m, m);
    for (int i = 0; i < m; i++) {
        res *= copy[i * m + i];
    }
    print_matrix(copy, m, m);
    return res;
}

int main() {
    // test matrix_add
    int m1 = 3, n1 = 2;
    double a[3][2] = {1, 2, 3, 4, 5, 6};
    double b[3][2] = {1, 2, 3, 4, 5, 6};
    double c[3][2];
    matrix_add((double *)a, (double *)b, (double *)c, m1, n1);
    print_matrix((double *)a, m1, n1);
    print_matrix((double *)b, m1, n1);
    print_matrix((double *)c, m1, n1);

    // test scalar_times_matrix
    int m2 = 3, n2 = 3;
    double d[3][3] = { 2, 4, 6, 8, 10, 12, 14, 16, 18};
    double e[3][3];
    scalar_times_matrix(0.5, (double *)d, (double *)e, m2,  n2);
    print_matrix((double *)d, m2, n2);
    print_matrix((double *)e, m2, n2);

    //test determinate
    double det = determinate((double *)d, m2);
    printf("%.2lf\n", det);
}