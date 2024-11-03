#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Note: this function will output an array including `end` if (end-start)%step=0*/
void make_triangle_list(int start, int end, int step, double *result) {
    int cnt = (end - start) / step + 1;
    for (int i = 0; i < cnt; i++) {
        result[i * 5] = start + i * step;
        result[i * 5 + 1] = sin(result[i * 5] / 180 * M_PI);
        result[i * 5 + 2] = cos(result[i * 5] / 180 * M_PI);
        result[i * 5 + 3] = tan(result[i * 5] / 180 * M_PI);
        result[i * 5 + 4] = 1 / result[i * 5 + 3];
    }
}

void print_triangle_list(double *result, int length) {
    printf("Here is the triangle list:\n");
    printf("Angle\t\tsin()\t\tcos()\t\ttan()\t\tcot()\n");
    for (int i = 0; i < length; i++) {
        printf("%lf\t%lf\t%lf\t%lf\t%lf\n", result[i * 5], result[i * 5 + 1],
               result[i * 5 + 2], result[i * 5 + 3], result[i * 5 + 4]);
    }
}

int main() {
    int start, end, step;
    // scanf("%d %d %d", &start, &end, &step);
    start = 0;
    end = 90;
    step = 5;
    double *result =
        (double *)malloc(((end - start) / step + 1) * 5 * sizeof(double));
    make_triangle_list(start, end, step, result);
    print_triangle_list(result, (end - start) / step + 1);
    // where you malloc, where you free.
    free(result);
    return 0;
}