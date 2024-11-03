#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
// #include <math.h>
#define ll long long

void test_matrix_mul_vec();
void test_matrix_mul_matrix();

/*
Free-after-use result array should always be defined in caller and pass the pointer to the func

Note: In fact the 2D array is 1D array internal, so if use a 2D array identifier, the second or higher dimension length should be specified.
*/
void matrix_mul_vec(double *matrix, double *vec, double *res_vec, int row, int col) {
    for (int i = 0; i < row; i++) {
        // calc process should be: a11(idx is 1 * col + 1)*v1 + ... + a1n*vn
        for (int j = 0; j < col; j++) {
            res_vec[i] += matrix[col * i + j] * vec[j];
        }
    }
}

/*
Free-after-use result array should always be defined in caller and pass the pointer to the func

row1 * col1 matrix * col1 * col2 matrix = row1 * col2 matrix.
res_vec length is row1 * col2 * sizeof(double)
so for each col in matrix2 
*/
void matrix_mul_matrix(double *matrix1, double *matrix2, double *res_matrix, int row1, int col1, int col2) {
    int row2 = col1;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < row2; k++) {
                // calc process should be res_vec[1(i)][1(j)] = m1[1(i)][1(k)]*m2[1(k)][1(j)]+...+m1[1][n(col1)]*m2[n(row2)][1]
                res_matrix[col2 * i + j] += matrix1[col1 * i + k] * matrix2[col2 * k + j];
            }
        } 
    }
}

int main() {
    char s[64];
    scanf("%s", s);
    if (strcmp(s, "test_matrix_mul_vec") == 0) {
        test_matrix_mul_vec();
    } else if (strcmp(s, "test_matrix_mul_matrix") == 0) {
        test_matrix_mul_matrix();
    } else {
        printf("No test found");
    }
    return 0;
}


void test_matrix_mul_vec() {
    // init row*col(m*n)
    int m, n;
    printf("Enter row*col \n");
    scanf("%d*%d", &m, &n);

    // init matrix
    double *matrix = (double*)malloc((ll)n*m*sizeof(double));
    printf("Enter matrix element, from row to row: \n");
    for (long i = 0; i < (ll)n * (ll)m; i++) {
        scanf("%lf", &matrix[i]);
    }

    // init vec
    double *vec = (double*)malloc(n * sizeof(double));
    printf("Enter vec element, from row to row: \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i]);
    }

    // create result vec
    double *res_vec = (double*)malloc(m*sizeof(double));

    // calc
    matrix_mul_vec(matrix, vec, res_vec, m, n);

    // output
    for (int i = 0; i < m; i++) {
        printf("%lf\n", res_vec[i]);
    }

    // free after use
    free(vec);
    free(matrix);
    free(res_vec);

}

void test_matrix_mul_matrix() {
    // init row1*col1(m*n), row2*col2(n*l)
    int m, n, l;
    printf("Enter row*col \n");
    scanf("%d*%d", &m, &n);
    printf("Enter matrix2 col \n");
    scanf("%d", &l);

    // init matrix1
    double *matrix1 = (double*)malloc((ll)n*m*sizeof(double));
    printf("Enter matrix1 element, from row to row: \n");
    for (long i = 0; i < (ll)n * (ll)m; i++) {
        scanf("%lf", &matrix1[i]);
    }

    // init matrix1
    double *matrix2 = (double*)malloc((ll)n*l*sizeof(double));
    printf("Enter matrix2 element, from row to row: \n");
    for (long i = 0; i < (ll)n * (ll)l; i++) {
        scanf("%lf", &matrix2[i]);
    }

    // create result matrix
    double *res_matrix = (double*)malloc(m*l*sizeof(double));

    // calc
    matrix_mul_matrix(matrix1, matrix2, res_matrix, m, n, l);

    // output
    for (int i = 0; i < m; i++){
        for (int j = 0; j < l; j++){
            printf("%lf ", res_matrix[i*l+j]);
        }
        printf("\n");
    }
}