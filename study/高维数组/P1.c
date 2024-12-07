#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double a[2][2] = {{1, 2}, {3, 4}};
    printf("a[0] is double* pointer: %p\n", a[0]); // double *
    printf("a[2] is double* pointer: %p\n", a[2]); // has meaning but undefined
    // int *p[3];
    // sizeof(p); // p type (int *[3]) (length 8 * 3) (int pointer array with length of 3)
    // sizeof(p[0]); // p[0] type (int *) (unsigned long on 64bit machine)
    // int (*ptr)[2];
    // sizeof(ptr); // ptr type (int (*)[2]) (unsigned long) (pointer to int[2])
    // sizeof(ptr[0]); // ptr[0] type (int[2]) (unsigned long ) (array of length 2)
    // sizeof(ptr[0][0]); // ptr[0][0] type (int) (The data of the 2D array)
}
