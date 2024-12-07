#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100

void setrand(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }
}

void bucket(int *a, int n, int *b) {
    for (int i = 0; i < n; i++) {
        b[a[i]] += 1;
    }
}

void analyse(int *bucket, int n) {
    for (int i = 0; i < n; i++) {
        printf("Number %d occured %d times.\n", i, bucket[i]);
    }
}

void print_array(int *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[M];
    srand(time(NULL));
    setrand(a,  M);
    print_array(a, M);
    int b[10] = {0};
    bucket(a, M, b);
    analyse(b, 10);
}