#include <stdio.h>


void vec_scalar(double *vec, int l, double scalar, double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

void vec_add(double *vec1, double * vec2, double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
    }
}

void print_array(double *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

int main() {
    double x = 10, y = 20;
    double u[10], v[10], xu[10], yv[10], res[10];
    for (int i = 0; i < 10; i++) {
        u[i] = i; // fill vec u with value from 0 to 9
        v[i] = i+1; // fill vec v with value from 1 to 10
    }
    printf("vector u is :\n");
    print_array(u, 10);
    printf("vector v is :\n");
    print_array(v, 10);
    vec_scalar(u, 10, x, xu);
    vec_scalar(v, 10, y, yv);
    printf("vector xu is :\n");
    print_array(xu, 10);
    printf("vector yv is :\n");
    print_array(yv, 10);
    vec_add(xu, yv, res, 10);
    printf("vector xu + yv is :\n");
    print_array(res, 10);
}