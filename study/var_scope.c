#include <stdio.h>

// define global and static variables.
int c = 114514;
const int d = 1919810;
static int e = 114;

int get_e() { return e; }

int *get_e_pointer() {
    int *pe;
    {
        int e = 1;
        printf("%p\n", &e);
        pe = &e;
    }
    printf("%p\n", pe);
    printf("%d\n", *pe);
    printf("%d\n\n", e);
    return pe;
}

void doing_nothing() {
    // char string[] = "%p %p %p %p %p %p %p %p %p %p %p %p\n";
    int a, b, c, d, e, f, g, h, i, j, k, m;
    // , l;
    a = b = c = d = e = f = g = h = i = j = k = m = 1;
    // for (int _i = 0; _i < 2147483647; _i++) {
    //     _i += 2;
    //     i = _i;
    // }
    // do {
    //     int _i = 0;
    //     ++_i;
    //     i = _i * 2 - 1;
    // } while (_i < 2147483647);
    // printf("%d\n\n", _i);
    a = 1;
    b = 2;
    c = 1919810;
    d = 4;
    k = 114514;
    // l = 1234567890;
    // printf(string, &a, &b, &c, &d, &e, &f, &g,
    //        &h, &i, &j, &k, &m);
}

int main() {
    // printf("%p\n", get_e_pointer());
    // printf("%d\n", get_e());
    // int a =  2;
    // {
    //     int b = 1;
    // }
    // // b = 3; // `b` undefined
    // c = 9;
    // // d = 8; // In theory, `d` shouldn't be modified
    // // for (const int i = 0; i < 99; i++) {
    //     // ; // C is not like rust, it won't modify `i`
    // // }
    // int e = 1;
    // printf("%p\n", get_e_pointer()); // the `e` defined in the function
    // shadowed static var e. printf("%d\n", get_e()); printf("%p\n", &e);
    // printf("%d\n", e);
    // // static var can be modified.

    int *pe;
    {
        int e = 1;
        printf("%p\n", &e);
        pe = &e;
    }
    printf("%p\n", pe);
    printf("%d\n", *pe);
    printf("%d\n\n", e);
    int *pe1 = get_e_pointer();
    doing_nothing();
    printf("%p\n", pe1);
    printf("%d\n", *pe1);
}