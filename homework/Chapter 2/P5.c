// #define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

// M_PI and M_E is defined in math.h.
// Some system may define _USE_MATH_DEFINES before including math.h to use M_PI
// and M_E. 

#ifdef M_PI
#undef M_PI
#endif
#ifdef M_E
#undef M_E
#endif
// #define M_PI 3.14159265358979323846
// #define M_E  2.71828182845904523536

// After seeing many post, use define may not be a good idea.
const double M_PI = 3.14159265358979323846;
const double M_E  = 2.71828182845904523536;
// 听说大家都是手动写，所以我干脆不用库里的定义了

int main(void) {
    double res[10];
    res[0] = (double)2.34 / (double)(1 + 257);
    res[1] = (double)1065.0 / (double)(24 * 13);
    res[2] = (double)23.582 / (double)(7.96 / 3.67);
    // res[3] = sqrt(M_PI_2 + 1);
    res[3] = sqrt(M_PI + 1);
    res[4] = log(sqrt(2 * M_PI - 1)) / log(5); // log_{5}x = lnx / ln5
    res[5] = exp(sqrt(M_PI + 1));              // exp() return e^x
    res[6] = atan(log(M_E + M_PI) / log(3));
    res[7] = sqrt((13 - (2.24 - 0.24 * 0.24) * (2.24 - 0.24 * 0.24)) / 3.68);
    res[8] = 1 + 2.0 / (3 + 4.0 / 5.0);
    res[9] = log(2 * M_PI * sqrt(13 + M_E));
    int i = 0;
    while (i < 10) {
        printf("(%d) Answer: %lf\n", i + 1, res[i]);
        i++;
    }
}