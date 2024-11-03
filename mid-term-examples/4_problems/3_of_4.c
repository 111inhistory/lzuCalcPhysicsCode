#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// All pos start at 0.

void convert_index_to_pos(int index, int row_num, int *pos) {
    pos[0] = index / row_num;
    pos[1] = ((index - 1) % row_num);
}

int convert_pos_to_index(int *pos, int row_num) {
    return pos[0] * row_num + pos[1];
}

int det(int *matrix, int length) {
    if (length == 9) {
        //well, calculate it yourself.
        return (matrix[0] * matrix[4] * matrix[8] +
                matrix[1] * matrix[5] * matrix[6] +
                matrix[2] * matrix[3] * matrix[7] -
                matrix[2] * matrix[4] * matrix[6] -
                matrix[1] * matrix[3] * matrix[8] -
                matrix[0] * matrix[5] * matrix[7]);
    } else if (length == 4) {
        return (matrix[0] * matrix[3] - matrix[1] * matrix[2]);
    } else {
        //the det of up-triangle matrix can be calculated by multiplying
        //all the numbers on the diagonal(对角线)
        int row = (int)sqrt(length);
        int res = 1;
        for (int i = 0; i < (int)sqrt(length); i++) {
            int pos[2] = {i,i};
            int p = matrix[convert_pos_to_index(pos, row)];
            if (p != 0) {
                res *= p; 
            } else {
                return 0;
            }
        }
        return res;
    }
}

/*
    will return a new array, DO NOT FORFET TO FREE IT!
*/
int *new_matrix(int *n, int *m) {
    scanf("%d %d", n, m);
    int *matrix = malloc(*n * *m * sizeof(int));
    for (int j = 0; j < *m; ++j) {
        for (int i = 0; i < *n; ++i) {
            scanf("%d", &matrix[j * *n + i]);
        }
    }
    // for (int j = 0; j < m; ++j) {
    //     for (int i = 0; i < n; ++i) {
    //         // equals to:
    //         // printf("%-*d ", 5, *(matrix + j * n + i));
    //         // but operate the raw pointer is dangerous
    //         printf("%-*d ", 5, matrix[j * n + i]);
    //     }
    //     printf("\n");
    // }
    return matrix;
}

int main(void) {
    int n, m;
    int *matrix = new_matrix(&n, &m);
    int length = n * m;
    int res = det(matrix, length);
    printf("The det(matrix) is %d\n", res);
    // int pos[2];
    // convert_index_to_pos(13, n, pos);
    // printf("The row and col of index 13 is %d and %d\n", pos[0], pos[1]);
    // // clean up the memory
    free(matrix);
}