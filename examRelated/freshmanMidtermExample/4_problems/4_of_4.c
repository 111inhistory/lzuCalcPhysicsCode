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

/*
return the length of the vec
*/
double vec_mod(double *vec, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += vec[i] * vec[i];
    }
    res = sqrt(res);
    return res;
}

/*
return the dot multi of two vecs
*/
double dot_multi(double *vec1, double *vec2, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

/*
write back the vec with each elem * scalar
*/
void vec_multi_scalar(double *vec, double scalar, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] *= scalar;
    }
}

/*
n is the length of the vector array.
*/
void vec_add(double *vec1, double *vec2, int n) {
    for (int i = 0; i < n; i++) {
        // You never know what mistake you will make.
        // You never know what mistake you will make.
        // You never know what mistake you will make.
        // You never know what mistake you will make
        // I wrote `vec1[i] = vec1[i] + vec2[2];`
        // OMG!
        vec1[i] = vec1[i] + vec2[i];
    }
}

/*
n is the length of the vector array.
*/
void vec_minus(double *vec1, double *vec2, int n) {
    for (int i = 0; i < n; i++) {
        vec1[i] = vec1[i] - vec2[i];
    }
}

/*
    make `length` vecs orthogonalization(正交化)

    o15n is the common basis to avoid a word too long.

    `n` is the dimension(阶数) of the vecs
*/
void gram_schmidt_o15n(double *vec_arr, int length, int n, double *res) {
    double *temp = (double *)malloc(n * sizeof(double));
    // copy the vec to the res
    memcpy(res, vec_arr, length * n * sizeof(double));
    for (int i = 0; i < length; i++) {
        // two array pointer represent the array current processing
        double *cur_in_vec = &vec_arr[i * n];
        double *cur_res_vec = &res[i * n];
        for (int j = 0; j < i; j++) {
            // (dot_multi / pow(vecmod of the base_vec, 2)) * base vector
            double base_vec_mod = vec_mod(&res[j * n], n);
            memcpy(temp, &res[j * n], n * sizeof(double));
            vec_multi_scalar(temp,
                             dot_multi(cur_in_vec, &res[j * n], n) /
                                 base_vec_mod / base_vec_mod,
                             n);
            vec_minus(cur_res_vec, temp, n);
        }
    }
    free(temp);
}

int main() {
    double test_vec1[3][3] = {
        {1.0, 1.0, 1.0}, {3.0, 4.0, 5.0}, {6.0, 7.0, 9.0}};
    double res[3][3];
    memset(res, 0, 3 * 3 * sizeof(double));
    // Test vec_mod
    gram_schmidt_o15n((double *)test_vec1, 3, 3, (double *)res);
    for (int i = 0; i < 3; i++) {
        printf("{");
        for (int j = 0; j < 3; j++) {
            printf("%lf, ", res[i][j]);
        }
        printf("}\n");
    }
}