#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const double DOUBLE_DIFF = 1e-6;

/**Matrix function**/
int row_reduce(double *mat, double *res, int m, int n);
int rec_ref_matrix(double *mat, double *res, int m, int n);
int _rec_ref_matrix(double *res, int i, int j, int m, int n, double *temp,
                    int a);
void vec_add(double *vec1, double *vec2, double *res, int l);
void vec_scalar(double *vec, int l, double scalar, double *res);
void swap_two_row(double *matrix, int row1, int row2, int m, int n);
/*utility function*/
int fcmp(double a, double b);
void swap(double *a, double *b);
void print_matrix(double *a, int m, int n);
void print_array(double *a, int l);

void print_array(double *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

/*swap two element*/
void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

/*compare double*/
int fcmp(double a, double b) {
    if (a - b > DOUBLE_DIFF) {
        return 1;
    } else if (a - b < -DOUBLE_DIFF) {
        return -1;
    } else {
        return 0;
    }
}

/*swap two row in the matrix*/
void swap_two_row(double *matrix, int row1, int row2, int m, int n) {
    for (int i = 0; i < n; i++) {
        swap(&matrix[row1 * n + i], &matrix[row2 * n + i]);
    }
}

/*as the name*/
void vec_add(double *vec1, double *vec2, double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
    }
}

/*as the name*/
void vec_scalar(double *vec, int l, double scalar, double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

/*as the name*/
void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", a[i * n + j]);
        }
        printf("\n");
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
            // print_array(&res[k * n], n);
            vec_scalar(&res[j * n], n, -res[k * n + i] / res[j * n + i], temp);
            // print_array(temp, n);
            vec_add(&res[k * n], temp, &res[k * n], n);
            // print_array(&res[k * n], n);
        }
        i++;
        j++;
    }
    return a;
}

int _rec_ref_matrix(double *res, int i, int j, int m, int n, double *temp,
                    int a) {
    // set stop condition
    // `i` is the column idx current processing, `j` is the row idx current
    // processing
    if (i >= n || j >= m) {
        return a;
    }
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
            _rec_ref_matrix(res, i + 1, j, m, n, temp, a);
            return a;
        }
    }
    // set the first elem of column 0 of submatrix mat_{i, j} to 0 using
    // line multi scalar and line plus
    for (int k = j + 1; k < m; k++) {
        // print_array(&res[k * n], n);
        vec_scalar(&res[j * n], n, -res[k * n + i] / res[j * n + i], temp);
        // print_array(temp, n);
        vec_add(&res[k * n], temp, &res[k * n], n);
        // print_array(&res[k * n], n);
    }
    return _rec_ref_matrix(res, i + 1, j + 1, m, n, temp,
                           a); // 似乎可以做尾调用优化
}

/*entrance function for recursion version of ref_matrix()*/
int rec_ref_matrix(double *mat, double *res, int m, int n) {
    double *temp = (double *)malloc(m * n * sizeof(double));
    for (int i = 0; i < m * n; i++) {
        res[i] = mat[i];
    }
    return _rec_ref_matrix(res, 0, 0, m, n, temp, 1);
}

int main() {
    // add some variable so that the random matrix is not fixed on one machine
    // long timer;
    // time(&timer); // current UNIX timestamp
    // srand(timer);
    // double B[16], REFB[16];
    // for (int i = 0; i < 16; i++) {
    //     B[i] = rand() % 4;
    // }
    double B[16] = {1, 1, 1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1};
    double REFB[16];
    print_matrix(B, 4, 4);
    printf("\n");
    // two types of function for you to choose
    // ref_matrix(B, REFB, 4, 4);
    printf("%d\n", rec_ref_matrix(B, REFB, 4, 4));
    print_matrix(REFB, 4, 4);
}