/*
Understand the algorithm.

1. let the first vec as one of the base vector;
2. for the other vec, calculate the cos of the angle between the vec and the
other base vector.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double vec_mod(double *vec, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += vec[i] * vec[i];
    }
    res = sqrt(res);
    return res;
}

double dot_multi(double *vec1, double *vec2, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

void vec_multi_scalar(double *vec, double scalar, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] *= scalar;
    }
}

/*
DO NOT FORGET FREE IT!

n is the length of the vector array.
*/
void vec_add(double *vec1, double *vec2, int n) {
    for (int i = 0; i < n; i++) {
        vec1[i] = vec1[i] + vec2[2];
    }
}

/*
DO NOT FORGET FREE IT!

n is the length of the vector array.
*/
void vec_minus(double *vec1, double *vec2, int n) {
    double *res = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        res[i] = vec1[i] - vec2[2];
    }
}

/*
    make `length` vecs orthogonalization(正交化)

    o15n is the common basis to avoid a word too long.

    `n` is the dimension(阶数) of the vecs
*/
double **gram_schmidt_o15n(double **vec_arr, int length, int n) {
    double **res = (double **)malloc(n * length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double *cur_in_vec = vec_arr[i];
        double *cur_res_vec = res[i];
        for (int k = 0; k < n; k++) {
            cur_res_vec[k] = cur_in_vec[k];
        }
        memcpy(cur_res_vec, cur_in_vec, n * sizeof(double));
        for (int j = 0; j < i; j++) {
            // (dot_multi / pow(vecmod of the base_vec, 2)) * base vector
            double base_vec_mod = vec_mod(res[j], n);
            double *temp = (double *)malloc(n * sizeof(double));
            memcpy(temp, res[j], n * sizeof(double));
            vec_multi_scalar(temp,
                             dot_multi(cur_in_vec, res[j], n) / base_vec_mod /
                                 base_vec_mod,
                             n);
            vec_minus(cur_res_vec, temp, n);
            free(temp);
        }
    }
    return res;
}

int main() {
    double test_vec1[3][3] = {{1.0, 1.0, 1.0}, {3.0, 4.0, 5.0}, {6.0, 7.0, 8.0}};
    // Test vec_mod
} 