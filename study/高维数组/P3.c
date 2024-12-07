#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10

void setrand(double *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
}