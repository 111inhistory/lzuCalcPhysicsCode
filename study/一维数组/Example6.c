#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10

void setrand(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }
}

void del(int *a, int n, int k) {
    for (int j = k; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        n--;
}

void print_array(int *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int w[M];
    setrand(w, M);
    print_array(w, M);
    int k = rand() % M;
    printf("Del index = %d elem\n", k);
    del(w, M, k);
    print_array(w, M - 1);
}