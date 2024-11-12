#include <math.h>
#include <stdio.h>

int solution(int a) {
    // In theory, we need to solve the inaccuracy when operate double.
    // But with test, it won't.
    // if (a == 2) {
    //     return 3;
    // } else if (a == 3) {
    //     return 4;
    // }
    int sum = 0, stop = (int)(sqrt(a));
    if (a == stop * stop) {
        sum = stop;
        for (int i = 1; i < stop; i++) {
            if (a % i == 0) {
                sum += i + a / i;
            }
        }
    } else {
        for (int i = 1; i < stop + 1; i++) {
            if (a % i == 0) {
                sum += i + a / i;
            }
        }
    }
    return sum;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", solution(a));
}