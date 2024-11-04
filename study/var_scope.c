#include <stdio.h>

int c = 114514;
const int d = 1919810;
static int e = 114;

int get_e() {
    return e;
}

int *get_e_pointer() {
    return &e;
}

int main() {
    printf("%p\n", get_e_pointer());
    printf("%d\n", get_e());
    int a =  2;
    {
        int b = 1;
    }
    // b = 3; // `b` undefined
    c = 9;
    // d = 8; // In theory, `d` shouldn't be modified
    // for (const int i = 0; i < 99; i++) {
        // ; // C is not like rust, it won't modify `i`
    // }
    int e = 1;
    printf("%p\n", get_e_pointer()); // the `e` defined in the function shadowed static var e.
    printf("%d\n", get_e());
    printf("%p\n", &e);
    printf("%d\n", e);
    // static var can be modified. 
}