#include <stdio.h>

int solution(int n) {
    int res = 0;
    while (n > 0) {
        // both solutions below are ok without obvious difference in
        // performance. But if use `%` then it is much slower.
        res += (n + 1) & 1;

        // if (n ^ 1) {res++;}
        n /= 10;
    }
    return res;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d", solution(a));
    return 0;
}