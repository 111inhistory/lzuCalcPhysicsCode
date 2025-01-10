#include <stdio.h>
#include <float.h>

#define ll long long

double big_int_method(int digits) {
    ll a = 1;
    ll res = 0;
    for (int i = 0; i < digits + 2; i++) {
        a *= 10;
    }
    ll num = 1;
    ll sign = 1;
    ll sub = a / num;
    while (sub >= 1) {
        res += sign * sub;
        sign *= -1;
        num += 2;
        sub = a / num;
    }
    printf("0.%.13lld\n", res);
    return (double)res / (double)a;
}

int main() {
    big_int_method(13);
}