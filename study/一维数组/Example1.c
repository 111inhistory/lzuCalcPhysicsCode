#include <stdio.h>
#include <stdlib.h>

#define M 30

int main() {
    int a[M];
    for (int i = 1, k = 0; k < 30; i+=2, k++) {
        a[k] = i;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", a[i * 10 + j]);
        }
        printf("\n");
    }
    for (int i = 2; i >= 0; i--) {
        for (int j = 9; j >= 0; j--) {
            printf("%d ", a[i * 10 + j]);
        }
        printf("\n");
    }
}