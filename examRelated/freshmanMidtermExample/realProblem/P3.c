// #include <float.h>
#include <stdio.h>

int fcmp(double a, double b);

double magic_number = 100.19;

int solution(double a1, double a2, double a3) {
    int res = 0;
    if (a1 > magic_number) {
        res++;
    }
    if (a1 > magic_number) {
        res++;
    }
    if (a1 > magic_number) {
        res++;
    }
    return res;
}

// the code below is the standard method used when processing double
// Why not use it is that there is no double operations, so we don't need it.
/***
int fcmp(double a, double b) {
    double accuracy = 1e-6;
    double sub = a - b;
    if (sub > accuracy) {
        return 1; // a is bigger than b
    } else if (sub < accuracy) {
        return -1; // a is smaller than b
    } else {
        return 0; // a and b are equal. If this case is the first or second, it
                  // will bring unnecessary preformance cost.
    }
}
***/


int main(void) {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%d\n", solution(a, b, c));
}