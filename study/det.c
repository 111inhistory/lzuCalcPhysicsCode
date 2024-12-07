/* 我还是那么喜欢用标记数组表示是否被使用过。这样的好处就是只需要一个矩阵，不需要任何复制。
 * 但是吧，就是说，这个最好优化成链表，这样对于很大很大的矩阵而言会少一个的`C*n^2`的计算量
 * (当然，这有差别吗……本身复杂度已经足够大了(n!)，没意义的……)
 * det1&_det1没有用到链表。另外一个版本det2&_det2是链表版本，det3是使用行化简的版本。
 * 行化简会损失精度，但是是真的快……det1和det2在12*12矩阵时需要10s和5s（还是O3编译），
 * 但是det3依旧不需要1ms（也是O3，可能inline了）*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DBL_ERR 1e-6
#define ll long long

long double _det1(long double *mat, int m, int *pos_x, int cnt);
long double det1(long double *mat, int m);
long double _det2(long double *mat, int m, int *idx_x, int *idx_y, int head_x,
                  int head_y, int cnt);
long double det2(long double *mat, int m);
long double det3(long double *mat, int m);
int row_reduce(long double *mat, long double *res, int m, int n);
void swap(long double *a, long double *b);
void swap_two_row(long double *matrix, int row1, int row2, int m, int n);
void vec_add(long double *vec1, long double *vec2, long double *res, int l);
void vec_scalar(long double *vec, int l, long double scalar, long double *res);
int fcmp(long double a, long double b);
void print_array(long double *a, int l);
void print_matrix(long double *a, int m, int n);
long double test_det1(long double *mat, int m);
long double test_det2(long double *mat, int m);
long double test_det3(long double *mat, int m);

int main() {
    // det3() used row reduce to calc det, so it will have error in result.
    // So, to reduce the error, I used long double
    srand(time(NULL));
    // for (int i = 1; i < 13; i++) {
    //     printf("\ncalc det %dx%d matrix\n", i, i);
    //     long double total_time1 = 0, total_time2 = 0, total_time3 = 0;
    //     long double *mat = (long double *)malloc(i * i * sizeof(long
    //     double)); for (int j = 0; j < i * i; j++) {
    //         mat[j] = rand() % 50;
    //     }
    //     print_matrix(mat, i, i);
    //     printf("\nTest det1():\n");
    //     for (int j = 0; j < 10; j++) {
    //         total_time1 += test_det1(mat, i);
    //     }
    //     printf("\nTest det2():\n");
    //     for (int j = 0; j < 10; j++) {
    //         total_time2 += test_det2(mat, i);
    //     }
    //     printf("\nTest det3():\n");
    //     for (int j = 0; j < 10; j++) {
    //         total_time3 += test_det3(mat, i);
    //     }
    //     printf("Avg exe time of det1() is %Lfms\n", total_time1 / 10);
    //     printf("Avg exe time of det2() is %Lfms\n", total_time2 / 10);
    //     printf("Avg exe time of det3() is %Lfms\n", total_time3 / 10);
    //     free(mat);
    // }
    long double d[4][4] = {
        {1, -1, -3, 0}, {00, 1, 5, 4}, {-1, 0, 5, 3}, {3, -1, -2, 3}};
    long double res[5][5];
    memset(res, 0, 25 * sizeof(long double));
    printf("%Lf\n", det3((long double *)d, 5));
}

long double test_det1(long double *mat, int m) {
    // printf("\ndet of the matrix is: %lf\n", determin1((long double *)mat,
    // m));
    clock_t start = clock();
    long double res = det1(mat, m);
    clock_t end = clock();
    printf("det of the matrix is: %Lf\n", res);
    return (long double)(end - start) / CLOCKS_PER_SEC * 1000;
}

long double test_det2(long double *mat, int m) {
    // print_matrix(mat, m, m);
    // printf("\ndet of the matrix is: %lf\n", determin1((long double *)mat,
    // m));
    clock_t start = clock();
    long double res = det2(mat, m);
    clock_t end = clock();
    printf("det of the matrix is: %Lf\n", res);
    return (long double)(end - start) / CLOCKS_PER_SEC * 1000;
}

long double test_det3(long double *mat, int m) {
    // printf("\ndet of the matrix is: %lf\n", determin1((long double *)mat,
    // m));
    clock_t start = clock();
    long double res = det3(mat, m);
    clock_t end = clock();
    printf("det of the matrix is: %Lf\n", res);
    return (long double)(end - start) / CLOCKS_PER_SEC * 1000;
}

long double det1(long double *mat, int m) {
    int *pos_x = malloc(2 * m * sizeof(int));
    for (int i = 0; i < 2 * m; i++) {
        pos_x[i] = 1;
    }
    long double res = _det1(mat, m, pos_x, m);
    free(pos_x);
    return res;
}

// `pos_array` record which row & col need to be processed. it length is `2 *
// m`, and `pos_array + m` records rows.
long double _det1(long double *mat, int m, int *pos_x, int cnt) {
    int *pos_y = pos_x + m;
    long double res = 0;
    int sign = 1;
    if (cnt == 1) {
        int i = 0, j = 0;
        while (pos_x[i] == 0) {
            i++;
        }
        while (pos_y[j] == 0) {
            j++;
        }
        // printf("%lf\n", mat[m * i + j]);
        // printf("cnt = %d, res = %lf\n", cnt, mat[m * i + j]);
        return mat[i * m + j];
    }
    // 按首行展开
    int i1 = 0;
    for (; i1 < m && pos_x[i1] == 0; i1++) {
        ;
    }
    pos_x[i1] = 0;
    for (int j1 = 0; j1 < m; j1++) {
        if (pos_y[j1] == 1) {
            pos_y[j1] = 0;
            res += _det1(mat, m, pos_x, cnt - 1) * mat[i1 * m + j1] * sign;
            sign *= -1;
            pos_y[j1] = 1;
        }
    }
    pos_x[i1] = 1;
    // printf("cnt = %d, res = %lf\n", cnt, res);
    return res;
}

long double det2(long double *mat, int m) {
    int *idx_x = malloc(2 * m * sizeof(int));
    int *idx_y = idx_x + m;
    for (int i = 0; i < m; i++) {
        idx_x[i] = i + 1;
        idx_y[i] = i + 1;
    }
    idx_x[m - 1] = idx_y[m - 1] = -1;
    long double res = _det2(mat, m, idx_x, idx_y, 0, 0, m);
    free(idx_x);
    return res;
}

long double _det2(long double *mat, int m, int *idx_x, int *idx_y, int head_x,
                  int head_y, int cnt) {
    if (cnt == 1) {
        // 取链表第一项
        return mat[head_x * m + head_y];
    }
    long double res = 0;
    // 按首行展开
    int qx = head_x, qy = head_y;
    int px = -1, py = -1;
    res += mat[qx * m + head_y] *
           _det2(mat, m, idx_x, idx_y, idx_x[head_x], idx_y[head_y], cnt - 1);
    long double sign = -1;
    py = qy;
    qy = idx_y[qy];
    while (qy != -1) {
        idx_y[py] = idx_y[qy];
        res += sign * mat[qx * m + qy] *
               _det2(mat, m, idx_x, idx_y, idx_x[head_x], head_y, cnt - 1);
        sign *= -1;
        idx_y[py] = qy;
        py = qy;
        qy = idx_y[qy];
    }
    // printf("cnt = %d, res = %lf\n", cnt, res);
    return res;
}

long double det3(long double *mat, int m) {
    long double *res = (long double *)malloc(m * m * sizeof(long double));
    long double sign = row_reduce(mat, res, m, m);
    for (int i = 0; i < m; i++) {
        sign *= res[i * m + i];
    }
    free(res);
    return sign;
}

/*convert m*n matrix `mat` to its Row Echelon Form(REF) and write to matrix
 * `res`*/
int row_reduce(long double *mat, long double *res, int m, int n) {
    int a = 1;
    // a variable to save mid result
    long double *temp = (long double *)malloc(n * sizeof(long double));
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

/*swap two element*/
void swap(long double *a, long double *b) {
    long double tmp = *a;
    *a = *b;
    *b = tmp;
}

/*compare long double*/
int fcmp(long double a, long double b) {
    if (a - b > DBL_ERR) {
        return 1;
    } else if (a - b < -DBL_ERR) {
        return -1;
    } else {
        return 0;
    }
}

/*swap two row in the matrix*/
void swap_two_row(long double *matrix, int row1, int row2, int m, int n) {
    for (int i = 0; i < n; i++) {
        swap(&matrix[row1 * n + i], &matrix[row2 * n + i]);
    }
}

void vec_add(long double *vec1, long double *vec2, long double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
    }
}

/*as the name*/
void vec_scalar(long double *vec, int l, long double scalar, long double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

void print_array(long double *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%Lf ", a[i]);
    }
    printf("\n");
}

void scanMatrix(long double *tar, ll m, ll n) {
    for (ll i = 0; i < m * n; i++) {
        // printf("scanMatrix() i = %lld", i);
        scanf("%Lf", &tar[i]);
    }
}

void print_matrix(long double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2Lf ", a[i * n + j]);
        }
        printf("\n");
    }
}
