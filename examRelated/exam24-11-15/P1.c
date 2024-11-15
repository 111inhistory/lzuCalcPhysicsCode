#include <stdio.h>

double total(double t, double x, int n) {
    double add_num = t, res = 0; // init every month production
    for (int i = 0; i < n; i++) {
        res += add_num;
        // printf("%lf ", add_num);
        add_num *= 1.0 + x / 100;
    }
    return res;
}

int main() {
    double t = 3, x = 10;
    int n = 6;
    printf("%lf\n", total(t, x, n));
}
