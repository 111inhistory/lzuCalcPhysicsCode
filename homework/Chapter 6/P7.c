#include <stdio.h>

int linear_search(int *a, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int linear_searchf(double *a, int n, double target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[3] = {2,3,4};
    // expect -1
    printf("%d\n", linear_search(a, 3, 5));
    // expect 2
    printf("%d\n", linear_search(a, 3, 4));
    // expect 1
    printf("%d\n", linear_search(a, 3, 3));
    // expect 0
    printf("%d\n", linear_search(a, 3, 2));

    double b[3] = {2,3,4};
    // expect -1
    printf("%d\n", linear_searchf(b, 3, 5));
    // expect 2
    printf("%d\n", linear_searchf(b, 3, 4));
    // expect 1
    printf("%d\n", linear_searchf(b, 3, 3));
    // expect 0
    printf("%d\n", linear_searchf(b, 3, 2));
}