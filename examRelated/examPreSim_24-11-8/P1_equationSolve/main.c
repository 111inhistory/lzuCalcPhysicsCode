#include <math.h> // In fact I miss this line in the "exam" ……
#include <stdio.h>


void solveEquation(double a, double b, double c) {
    double delta = b * b - 4.0 * a * c;
    if (delta - 0 < -0.00001) {
        printf("Equation %lfx^2 + %lfx + %lf has no result. \n", a, b, c);
    } else if (fabs(delta - 0.0) < 0.00001) {
        double res = -b / 2 / a; // if delta == 0, then we don't need to add it.
        printf("The solution of %lfx^2 + %lfx + %lf has two same solution %lf",
               a, b, c, res);
    } else {
        // I forget to sqrt the delta…… Sad……
        double res1 = (-b + sqrt(delta)) / 2 / a;
        double res2 = (-b - sqrt(delta)) / 2 / a;
        printf("The solution of %lfx^2 + %lfx + %lf has two same solution %lf "
               "and %lf",
               a, b, c, res1, res2);
    }
}

int main() {
    double a, b, c;
    printf("Enter the 系数 of the equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (fabs(a - 0) < 0.00001) {
        printf("非二元一次方程\n");
        return 1;
    } else {
        solveEquation(a, b, c);
    }
}