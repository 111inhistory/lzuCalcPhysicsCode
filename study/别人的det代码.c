#include <math.h>

double det(double A[10][10][2], int n) {
    double sum = 0;
    double B[10][10][2] = {0};
    if (n == 1)
        sum = A[0][0][0];
    else {
        for (int i = 0; i < n; i++) {
            for (int ii = 0; ii < n - 1; ii++) {
                for (int iii = 0; iii < n - 1; iii++) {
                    if (iii < i)
                        B[ii][iii][0] = A[ii + 1][iii][0];
                    if (iii >= i)
                        B[ii][iii][0] = A[ii + 1][iii + 1][0];
                }
            }
            sum += pow(-1, i) * A[0][i][0] * det(B, n - 1);
        }
    }
    return sum;
}
