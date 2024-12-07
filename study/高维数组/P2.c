#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10

void swap(double *a, double *b);
void swap_two_row(double *matrix, int row1, int row2, int m, int n);
void setrand(double *a, int n);
void print_matrix(double *a, int m, int n);

void swap_two_row(double *matrix, int row1, int row2, int m, int n) {
    for (int i = 0; i < n; i++) {
        swap(&matrix[row1 * n + i], &matrix[row2 * n + i]);
    }
}

void swap_two_col(double *matrix, int col1, int col2, int m, int n) {
    for (int i = 0; i < m; i++) {
        swap(&matrix[i * n + col2], &matrix[i * n + col2]);
    }
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void setrand(double *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
}

void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", a[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    double a[M][M];
    setrand((double *)a, M * M);
    print_matrix((double *)a, M, M);
    printf("\n");
    swap_two_row((double *)a, 1, 2, M, M);
    print_matrix((double *)a, M, M);
    printf("\n");
    swap_two_col((double *)a, 1, 2, M, M);
    print_matrix((double *)a, M, M);
    printf("\n");
}