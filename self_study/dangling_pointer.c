#include <stdio.h>

int *dangling_pointer() {
    int a = 24;
    int *p = &a;
    return p;
    // return &a; // It will return nullptr
}

int main() {
    int *p = dangling_pointer();
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
}