#include <stdio.h>
#include <stdlib.h>
#define DBL_ERR 1e-6

void print_matrix(double *a, int m, int n);
void swap_two_row(double *matrix, int row1, int row2, int m, int n);
void swap(double *a, double *b);

void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i * n + j]);
        }
        printf("\n");
    }
}

/*swap two row in the matrix*/
void swap_two_row(double *matrix, int row1, int row2, int m, int n) {
    for (int i = 0; i < n; i++) {
        swap(&matrix[row1 * n + i], &matrix[row2 * n + i]);
    }
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

/*as the name*/
void vec_scalar(double *vec, int l, double scalar, double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

void scalar_times_matrix(double scalar, double *matrix, double *res, int m,
                         int n) {
    for (int i = 0; i < m * n; i++) {
        res[i] = matrix[i] * scalar;
    }
}

void matrix_add(double *a, double *b, double *res, int m, int n) {
    for (int i = 0; i < m * n; i++) {
        res[i] = a[i] = b[i];
    }
}

/* res can be `a` or `b` itself */
void vec_add(double *vec1, double *vec2, double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
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

/*convert m*n matrix `mat` to its Row Echelon Form(REF) and write to matrix
 * `res`*/
int row_reduce(double *mat, double *res, int m, int n) {
    int a = 1;
    // a variable to save mid result
    double *temp = (double *)malloc(n * sizeof(double));
    // copy it from `mat` to `res`. not modify original matrix. though in fact,
    // can be accepted.
    for (int i = 0; i < m * n; i++) {
        res[i] = mat[i];
    }
    int i = 0, j = 0;
    // well, think after finishing it, using recursion to ref a sub matrix is
    // straightforward than using iteration loop. though it would be a bit
    // complex to write the map from 2D pos to 1D index.
    while (i < n && j < m) {
        // this `if` statement process the condition when the first elem [0,0]
        // in submatrix mat_{i~m, j~n} is 0. if each elem in the first column of
        // submatrix is 0, then skip this column to process submatrix mat_{i +
        // 1~m, j~n}.
        if (fcmp(res[j * n + i], 0) == 0) {
            int flag = 1;
            for (int k = j; k < m; k++) {
                if (fcmp(res[k * n + i], 0) != 0) {
                    swap_two_row(res, j, k, m, n);
                    a *= -1;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                i++;
                continue;
            }
        }
        // set the first elem of column 0 of submatrix mat_{i~m, j~n} to 0 using
        // line multi scalar and line plus
        for (int k = j + 1; k < m; k++) {
            vec_scalar(&res[j * n], n, -res[k * n + i] / res[j * n + i], temp);
            vec_add(&res[k * n], temp, &res[k * n], n);
        }
        i++;
        j++;
    }
    return a;
}

double determinate(double *matrix, int m) {
    double *copy = (double *)calloc(m * m, sizeof(double));
    double res = row_reduce(matrix, copy, m, m);
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
    double d[3][3] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    double e[3][3];
    scalar_times_matrix(0.5, (double *)d, (double *)e, m2, n2);
    print_matrix((double *)d, m2, n2);
    print_matrix((double *)e, m2, n2);

    // test determinate
    double det = determinate((double *)d, m2);
    printf("%.2lf\n", det);
}