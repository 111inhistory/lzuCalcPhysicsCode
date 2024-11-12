#include <stdio.h>
#include <math.h>
#define llu unsigned long long
#define ll long long
#define ld long double

llu sum_cubic(llu k) {
    llu res = 0;
    for (llu i = 1; i <= k; i++) {
        res += i * i * i;
    }
    return res;
}

// llu sum_cubic(llu k) {
//     llu res = 0;
//     llu i = 1;
//     while (i <= k) {
//         res += i * i * i;
//         i++;
//     }
//     return res;
// }

ld sinx(ld x, ll max_times) {
    // x -= (llu)(x / M_PI + 1) * M_PI;
    ld sum = x;
    ld add = x;
    for (ll i = 1; i <= max_times; i++) {
        // use the last and output the present. 
        // Perfect!
        add *= -1.0 * x * x;
        add /= (2.0*i) * (2.0*i + 1);
        sum += add;
    }
    return sum;
}

int main() {
    llu k;
    scanf("%llu", &k);
    printf("%llu\n", sum_cubic(k));
    printf("%llu\n", (llu)powl(2,64)-1);
    ld x;
    scanf("%Lf", &x);
    printf("%.40Lf\n", sinx(x,10));
    return 0;
}