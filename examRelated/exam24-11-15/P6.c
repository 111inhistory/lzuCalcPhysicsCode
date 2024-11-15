#include <stdio.h>

int times(int a, int b) {
    // a is depth of the hell, b is jump height.
    int time = a / b;
    if (a % b == 0) {
        return time;
    } else {
        return time + 1;
    }
}

int main() {
    printf("10米井每次跳1米需要%d次\n", times(10, 1));
    printf("21米井每次跳2米需要%d次\n", times(21, 2));
}