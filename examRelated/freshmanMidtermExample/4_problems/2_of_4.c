#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);
    //narrow the condition gradually
    if (x >= 90) {
        printf("A\n");
    } else if (x >= 80){
        printf("B\n");
    } else if (x >= 60) {
        printf("C\n");
    } else {
        printf("D\n");
    }
}