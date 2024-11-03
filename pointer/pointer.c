#include <stdio.h>

void test_pointer() {
    printf( "test_pointer\n" );
    int *pa = NULL;
    int a = 1;
    pa = &a;
    printf("a = %d\n", *pa);
    printf("%p = %p\n", &a, pa);
}

void test_pointer_param(int p, int layer) {
    //if a var is give to another func, it will be copyed.
    //it will show different addresses.
    printf( "test_pointer_param\n" );
    printf("layer %d param p address is %p\n", layer, &p);
    if (layer > 0) {
        test_pointer_param(p, --layer);
    } else {
        return;
    }
}

int main(void) {
    printf("%d\n", 18/-4);
    test_pointer();
    test_pointer_param(1, 3);
}