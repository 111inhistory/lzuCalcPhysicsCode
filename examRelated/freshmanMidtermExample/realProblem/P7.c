#include <stdio.h>
#include <stdlib.h>

int m = 20, n = 100;

void swap(int *a, int *b);
void row_exchange(int *array, int rowN, int colN, int row_idx1, int row_idx2);


void row_exchange(int *array, int rowN, int colN, int row_idx1, int row_idx2) {
    int *row1 = &array[colN * row_idx1];
    int *row2 = &array[colN * row_idx2];
    for (int j = 0; j < colN; j++) {
        swap(&row1[j], &row2[j]);
    }
}


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_matrix(int *matrix, int rowN, int colN) {
    for (int i = 0; i < rowN; i++) {
        int *row = &matrix[colN * i];
        for (int j = 0; j < colN; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
        }
}

int main(void) {
    int *array = (int *)malloc(m * n * sizeof(int));
    int swap1 = 1, swap2 = 5;
    for (int i = 0; i < m * n; i++) {
        array[i] = rand() % 10;
    }
    print_matrix(array, m, n);
    printf("\n");
    row_exchange(array, m, n, swap1, swap2);
    print_matrix(array, m, n);
    free(array);
    return 0;
}