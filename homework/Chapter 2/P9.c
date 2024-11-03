#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double *solution(double x1, double x2, double x3);

/*The params are the coefficents of the 一元二次 equation*/
double *solution(double x1, double x2, double x3) {
    double delta = x2 * x2 - 4 * x1 * x3;
    double *result = (double *)malloc(sizeof(double) * 2);
    if (delta < 0) {
        result[0] = NAN;
        result[1] = NAN;
    } else {
        result[0] = (-x2 + sqrt(delta)) / (2 * x1);
        result[1] = (-x2 - sqrt(delta)) / (2 * x1);
    }
    return result;
}

int main() {
    double coefficents[3] = {5, 2, 6};
    double *result = solution(coefficents[0], coefficents[1], coefficents[2]);
    printf("Solving equation %lfx^2+%lfx+%lf\n", coefficents[0], coefficents[1],
           coefficents[2]);
    if (isnan(result[0]) || isnan(result[1])) { // NAN is not equal to anything, including itself. So, use isnan()
        printf("The equation has no solutions.\n");
    } else {
        printf("The solutions of the equation are %lf and %lf\n", result[0],
               result[1]);
    }
    free(result);
}