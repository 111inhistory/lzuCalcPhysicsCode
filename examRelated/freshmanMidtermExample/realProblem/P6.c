#include <stdio.h>

int iter_limit = 20;


double arctan(double x, int limit) {
    double res = x, not_add_num = x;
    for (int n = 1; n < limit; n++) {
        double sgn = 1 - ((n & 1) << 1);
        not_add_num *= x * x;
        res += sgn * not_add_num / (2 * n + 1);
    }
    return res;
}

int main(void) {
    double a;
    scanf("%lf", &a);
    printf("%lf\n", arctan(a, iter_limit));
    return 0;
}