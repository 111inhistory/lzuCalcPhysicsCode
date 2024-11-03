#include <math.h>
#include <stdio.h>

long long a = 1;

long double cal_ball_V(long double r) {
    return 4.0/3.0 * M_PI * r * r * r;
}

int main() {
    long double r;
    scanf("%Lf", &r);
    printf("V:%.12Lf\n", cal_ball_V(r));
    // printf("%d, %f, %Lf, %lf, %ld, %lld\n", 2.4L, 2.4L, 2.4L, 2.4L, 2.4L, 2.4L);
    //这里怀疑是因为读取了不同的寄存器导致输出了0。到时候看看标准库代码就知道了。
}

