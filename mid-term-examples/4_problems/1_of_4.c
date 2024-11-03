#include <stdio.h>
#include <math.h>

long long sqr_input() {
    long long a, res;
    scanf("%lld", &a);
    res = a * a;
    printf("%lld\n", res);
    return res;
}

void largest_factor(long long n) {
    long long res = 1;
    if (!(n & 1)) {
        res = n/2;
    } else {
        for (int i = 3; i <= (int)sqrt(n); i += 2){
            if (n % i == 0) {
                res = n / i;
                break;
            }
        }
    }
    printf("The largest factor of squared number %lld is %lld\n", n, n/2);
}

int main(void) {
    printf("Task 1: Square the input int\n");
    long long sqr = sqr_input();
    printf("Task 2: Return the largest factor except it self\n");
    largest_factor(sqr);
}
