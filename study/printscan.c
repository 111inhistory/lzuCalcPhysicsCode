#include <stdio.h>

void test_scanf() {
    // //Phase 1
    // printf("Phase 1\n");
    // int a;
    // printf("Enter an integer: ");
    // //User input "\n" will not be processed by scanf. It wouldn't left in the buffer.
    // scanf("%d", &a);
    // printf("You entered %d\n", a);
    // //Does printf will clean the stdio?
    // //Just when scanf has \n will need to enter twice, then some bugs occurs.
    // scanf("%d", &a);
    // printf("You entered %d\n", a);
    // //Phase 2
    // int b, c;
    // scanf("%d", &b);
    // scanf("%d", &c);
    // printf("You entered %d and %d\n", b, c);
    //Phase 3: test if scanf first params has \n at the end of string.
    printf("Phase 3\n");
    int d,e,f;
    scanf("%d\n", &d);
    scanf("%d\n", &e);
    scanf("%d\n", &f); 
    //This will force you to enter twice.
    printf("d=%d, e=%d, f=%d\n", d, e, f);
}

int main() {
    test_scanf();
}