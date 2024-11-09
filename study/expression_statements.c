#include <stdio.h>
#include <math.h>

long funca(long a, long b);
int isprime(long x);

double func1(double x) {
    // x*x*3+2 will be treated as expression
    return x*x*3+2;
}

unsigned long long fac(unsigned long long x) {
    unsigned long long MAX_LLU = 1;
    MAX_LLU = MAX_LLU << 1 | MAX_LLU;
    MAX_LLU = MAX_LLU << 2 | MAX_LLU;
    MAX_LLU = MAX_LLU << 4 | MAX_LLU;
    MAX_LLU = MAX_LLU << 8 | MAX_LLU;
    MAX_LLU = MAX_LLU << 16 | MAX_LLU;
    MAX_LLU = MAX_LLU << 32 | MAX_LLU;
    // debug
    printf("%llu\n", MAX_LLU);
    unsigned long long res = 1;
    for (unsigned long long i = 2; i <= x; i++) {
        res *= i;
        if (MAX_LLU / res < i+1) {
            printf("max fac num: %llu", i);
        } 
    }
}

long double sim_sinx(long double x, long times) {
    long double res = 0;
    for (int i = 0; i < times; i++) {
        res += powl(-1, i) * powl(x, 2*i+1) / (1);
    }
}

int main() {
    int flag;
    scanf("%d", &flag);
    // Syntax 1:
    // 三元表达式，?表示对前面进行if判断，:后是else语句。
    // 不要堆叠！很难看！
    int a = flag ? 1: 0;
    printf("%d\n", a);
    printf("%lf\n", func1(6));
    printf("%ld\n",funca(114514, 1919810));
    long prime;
    scanf("%ld", &prime);
    printf("isprime(%ld) returns %d", prime, isprime(prime));
}

long funca(long a, long b) {
    long min = a<b?a:b;
    int flag = 0;
    long i;
    for (i = min+1; i>2; i--) {
        if (a % i == 0 && b % i == 0){
            flag = 1;
            break;
        }
    }
    return flag ? i : -1;
}

int isprime(long x){
    long i = 2;
    while (x % i != 0 && i <= x-1) {
        i++;
    }
    return i == x ? 1 : 0;
}