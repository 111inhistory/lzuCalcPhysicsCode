#include <stdio.h>
// #include <stdlib.h>
#define ll long long 

ll fac(ll a) {
    if (a == 1) {return 1;}
    return a * fac(a-1);
}

int main() {
    ll a;
    scanf("%lld", &a);
    printf("%lld\n", fac(a));
    return 0;
}