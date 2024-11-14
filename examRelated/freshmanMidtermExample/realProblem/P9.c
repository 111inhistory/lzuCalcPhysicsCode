#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;
// void swap(int *a, int *b);
// int get_index(Matrix *mat, int x, int y);
// util functions
void init_matrix(Matrix *mat, int m, int n, double *array2D);
double *fuzz(int length);
void print_matrix(Matrix *mat);
int check_equal(Matrix *mat1, Matrix *mat2);

void matrix_mul_matrix(Matrix *mat1, Matrix *mat2, Matrix *res);
void trans_matrix(Matrix *mat, Matrix *res);


// TODO: should add checks. 
typedef struct Matrix {
    // int T, // deleted cuz it leads to complexity of the program.
    int row;
    int col;
    double *matrix;
} Matrix;

int main(void) {
    // define and init all the matrix used below
    Matrix a, b, aT, bT, res_ab, res_ab_T, res_bTaT;
    init_matrix(&a, 12, 24, fuzz(12 * 24));
    init_matrix(&b, 24, 7, fuzz(24 * 7));
    init_matrix(&aT, 24, 12, NULL);
    init_matrix(&bT, 7, 24, NULL);
    init_matrix(&res_ab, 12, 7, NULL);
    init_matrix(&res_ab_T, 7, 12, NULL);
    init_matrix(&res_bTaT, 7, 12, NULL);

    // output the initial matrix a and b
    printf("matrix A is: \n");
    print_matrix(&a);
    printf("\n");
    printf("matrix B is: \n");
    print_matrix(&b);
    printf("\n");

    // get the transpose matrix of A and B for the calc of A^T * B^T
    trans_matrix(&a, &aT);
    trans_matrix(&b, &bT);

    // output the matrix A^T and B^T
    printf("matrix A^T is: \n");
    print_matrix(&aT);
    printf("\n");
    printf("matrix B^T is: \n");
    print_matrix(&bT);
    printf("\n");

    // calc A * B
    matrix_mul_matrix(&a, &b, &res_ab);
    // get (AB)^T
    trans_matrix(&res_ab, &res_ab_T);
    // calc B^T * A^T
    matrix_mul_matrix(&bT, &aT, &res_bTaT);

    printf("matrix AB is: \n");
    print_matrix(&res_ab);
    printf("\n");
    printf("matrix B^TA^T is: \n");
    print_matrix(&res_bTaT);
    printf("\n");

    // output the result matrix (AB)^T & B^TA^T
    printf("matrix (AB)^T is: \n");
    print_matrix(&res_ab_T);
    printf("\n");
    printf("matrix B^TA^T is: \n");
    print_matrix(&res_bTaT);
    printf("\n");

    // check every elem in res_ab_T is equal to res_bTaT, which means res_ab_T =
    // res_bTaT
    assert(check_equal(&res_ab_T, &res_bTaT));
}

/*init Matrix with specific params*/
void init_matrix(Matrix *mat, int m, int n, double *array2D) {
    mat->row = m;
    mat->col = n;
    if (array2D == NULL) {
        mat->matrix = malloc(m * n * sizeof(double));
        for (int i = 0; i < n * m; i++) {
            mat->matrix[i] = 0;
        }
    } else {
        mat->matrix = array2D;
    }
}

/*generate `length` double array with random data*/
double *fuzz(int l) {
    double *res = malloc(l * sizeof(double));
    for (int i = 0; i < l; ++i) {
        // generate random number from [0, 100)
        res[i] = (double)(rand() % 100);
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
void matrix_mul_matrix(Matrix *mat1, Matrix *mat2, Matrix *res) {
    int m1_row = mat1->row;
    int m1_col = mat1->col;
    int m2_row = mat2->row;
    int m2_col = mat2->col;
    if (m1_col == m2_row) { // MD You shouldn't believe what you write!!!
        // init the res_matrix
        double *res_data;
        if (res->matrix == NULL) {
            init_matrix(res, m1_row, m2_col, NULL);
        }
        if (res->row != m1_row || res->col != m2_col) {
            printf("You wrong! Reinit the matrix.");
            init_matrix(res, m1_row, m2_col, NULL);
        }
        // reduce the time to look up matrix pointer
        res_data = res->matrix;
        // init res_matrix array
        for (int i = 0; i < m1_row * m2_col; i++) {
            res_data[i] = 0;
        }
        double *m1_data = mat1->matrix, *m2_data = mat2->matrix;
        for (int x = 0; x < m1_row; x++) {
            for (int y = 0; y < m2_col; y++) {
                // Solve the result of res_matrix[x][y]
                for (int k = 0; k < m1_col; k++) { // m2_row == m1_col
                    res_data[x * m2_col + y] +=
                        m1_data[x * m1_col + k] * m2_data[k * m2_col + y];
                }
            }
        }
    } else {
        printf("Invalid column and row num, matrix 1 row is %d, col is %d, "
               "matrix 2 row %d, col is %d\n",
               m1_row, m1_col, m2_row, m2_col);
    }
}

/*transpose the matrix, save it to res*/
void trans_matrix(Matrix *mat, Matrix *res) {
    int row = mat->row;
    int col = mat->col;
    // defensive programming. you never know what mistake you would make.
    if (res->matrix == NULL) {
        // res col and row are opposite
        init_matrix(res, col, row, NULL);
    } else {
        // 你要相信，你传进来的matrix各项都是配置正确的的。你，要自信！
        res->col = row;
        res->row = col;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // row i, col j of `mat` is row j, col i of `res`
            res->matrix[j * row + i] = mat->matrix[i * col + j];
        }
    }
}

void print_matrix(Matrix *mat) {
    int m = mat->row, n = mat->col;
    double *matrix = mat->matrix;
    for (int i = 0; i < mat->row; i++) {
        for (int j = 0; j < mat->col; j++) {
            printf("%.0lf ", matrix[i * n + j]);
        }
        printf("\n");
    }
}

/*check if the 2 matrix has the same row, col, and every elem in it are equal.*/
int check_equal(Matrix *mat1, Matrix *mat2) {
    if (mat1->row != mat2->row) {
        printf("Matrix 1 and Matrix 2 has different row count. Matrix 1 is %d, "
               "Matrix 2 is %d\n",
               mat1->row, mat2->row);
        return 0;
    }
    if (mat1->col != mat2->col) {
        printf("Matrix 1 and Matrix 2 has different col count. Matrix 1 is %d, "
               "Matrix 2 is %d\n",
               mat1->row, mat2->row);
        return 0;
    }
    double *array1 = mat1->matrix;
    double *array2 = mat2->matrix;
    int row = mat1->row, col = mat1->col, flag = 1;
    for (int i = 0; i < mat1->row; i++) {
        for (int j = 0; j < mat1->col; j++) {
            if (array1[i * col + j] != array2[i * col + j]) {
                printf("Matrix 1 and Matrix 2 not equal at row %d, column %d\n",
                       i, j);
                flag = 0;
            }
        }
    }
    return flag;
}

// Dead Code
// /*Just swap two elem*/
// void swap(int *a, int *b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// Dead Code
// /*well, right but useless*/
// int get_index(Matrix *mat, int x, int y) {
//     int col = mat->T ? mat->row : mat->col;
//     return col * x + y;
// }