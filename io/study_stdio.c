#include <stdio.h>

void test_getchar(void) {
    //study the getchar()
    //usually used to empty the buffer
    printf( "Enter anything that don't meet the requirement of scanf() below:");
    int a;
    if (scanf("%d", &a) < 1) {
        while ((a = getchar()) != EOF && a != '\n') {
            printf("%c\n", (char)a);
        }
    }
}

int main(void) {
    test_getchar();
    test_getchar();
}