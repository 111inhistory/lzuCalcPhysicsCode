#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;
void swap(int *a, int *b);
void matrix_mul_matrix(Matrix *matrix1, Matrix *matrix2, Matrix *res_matrix);
int get_index(Matrix *mat, int x, int y);
void trans_matrix(Matrix *mat, Matrix *res);
void init_matrix(Matrix *mat, int T, int row, int col, int *matrix);
int *fuzz(int length);

typedef struct Matrix {
    int T;
    int row;
    int col;
    int *matrix;
} Matrix;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void init_matrix(Matrix *mat, int T, int row, int col, int *matrix) {
    mat->T = T;
    mat->row = row;
    mat->col = col;
    if (matrix == NULL) {
        mat->matrix = malloc(row * col * sizeof(int));
    } else {
        mat->matrix = matrix;
    }
}

int get_index(Matrix *mat, int x, int y) {
    int col = mat->T ? mat->row : mat->col;
    return col * x + y;
}

int *fuzz(int length) {
    int *res = malloc(length * sizeof(int));
    for (int i  =  0;i < length; ++i) {
        res[i] = rand() % 100;
    }
    return res;
}

/*
Free-after-use result array should always be defined in caller and pass the
pointer to the func

row1 * col1 matrix * col1 * col2 matrix = row1 * col2 matrix.
res_vec length is row1 * col2 * sizeof(double)

algorithm complexity is O(n^3)
*/
void matrix_mul_matrix(Matrix *matrix1, Matrix *matrix2, Matrix *res_matrix) {
    // process the condition when T
    int m1_row = matrix1->T ? matrix1->col : matrix1->row;
    int m1_col = matrix1->T ? matrix1->row : matrix1->col;
    int m2_row = matrix2->T ? matrix2->col : matrix2->row;
    int m2_col = matrix2->T ? matrix2->row : matrix2->col;
    // reduce the time to look up matrix pointer
    int *m1_data = matrix1->matrix, *m2_data = matrix2->matrix;
    // init the res_matrix
    res_matrix->T = 0, res_matrix->row = m1_row, res_matrix->col = m2_col;
    int *res_data;
    if (res_matrix->matrix == NULL) {
        res_data = (int *)malloc(m1_row * m2_col * sizeof(int));
        res_matrix->matrix = res_data;
    } else {
        res_data = res_matrix->matrix;
    }
    // init res_matrix array
    for (int i = 0; i < m1_row * m2_col; i++) {
        res_data[i] = 0;
    }
    if (m1_row == m2_row) {
        for (int i = 0; i < m1_row; i++) {
            for (int j = 0; j < m2_col; j++) {
                for (int k = 0; k < m2_row; k++) {
                    // calc process should be res_vec[1(i)][1(j)] =
                    // m1[1(i)][1(k)]*m2[1(k)][1(j)]+...+m1[1][n(col1)]*m2[n(row2)][1]
                    res_data[i * m2_col + j] +=
                        m1_data[i * m1_col + k] *
                        m2_data[k * m2_col + j];
                }
            }
        }
    }
}

void trans_matrix(Matrix *mat, Matrix *res) {
    if (mat->T) {
        *res = *mat;
        res->T = 0;
    } else {
        res->T = 0;
        int row = mat->row;
        int col = mat->col;
        res->col = row;
        res->row = col;
        for (int i = 0; i < mat->row; i++) {
            for (int j = 0; j < mat->col; j++) {
                res->matrix[i + j * col] =
                    mat->matrix[i * col + j];
            }
        }
    }
}

int main(void) {
    Matrix a, b, aT, bT, res_ab, res_ab_T, res_bTaT;
    init_matrix(&a, 0, 12, 24, fuzz(12*24));
    init_matrix(&b, 0, 24, 7, fuzz(24*7));
    init_matrix(&aT, 0, 24, 12, NULL);
    init_matrix(&bT, 0, 7, 24, NULL);
    init_matrix(&res_ab, 0, 24, 7, NULL);
    init_matrix(&res_ab_T, 0, 7, 24, NULL);
    init_matrix(&res_bTaT, 0, 7, 24, NULL);
    
    trans_matrix(&a, &aT);
    trans_matrix(&b, &bT);

    matrix_mul_matrix(&a, &b, &res_ab);
    trans_matrix(&res_ab, &res_ab_T);
    matrix_mul_matrix(&bT, &aT, &res_bTaT);

    for (int i = 0; i < 12 * 7; i++) {
        if (res_ab_T.matrix[i] != res_bTaT.matrix[i]) {
            printf("error at i, %d != %d", res_ab_T.matrix[i],
                   res_bTaT.matrix[i]);
        }
    }
}