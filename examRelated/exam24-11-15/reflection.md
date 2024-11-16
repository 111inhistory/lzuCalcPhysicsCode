# 反思

# P1

> 1\. a) 某工厂一月份产值为 t 万元，以后的每一个月都比上一个月增产 x %，编写函数计算前 n 个月的总产值。b) 调用该函数计算当 t = 3, x = 10, n = 6 情况下的总产值。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

很好，很快，兼顾了代码正确性。

# P2

> 2\. 已知面包价格 x 元/个，牛奶是 y 元/袋。小明的妈妈给了小明 m 元钱，编写函数计算并输出小明能买到的牛奶和面包的数量的所有可能的组合。这里假设x, y, m都是正整数。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

这道题说实话，对于写算法题的人来说有点吃亏，总是默认为要最大程度利用`m`，但是却不考虑所有的方案，包括啥也不买。这个的算法复杂度为`O(n^x)`，`x`为有几样商品。

(还好我反应快)

# P3

> 3\. 编写函数计算两正整数的所有公因数的乘积并返回该值。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

采用了最笨的办法，没有什么最大公倍数然后分解质因数啥的。理论上还是可以提升速度的，但是就先这样吧。

# P4

> 4\. 已知$\mathbb{R}^4$中两向量 u，v 和标量 x, y， 计算  W = xu + yv 并输出到屏幕，自行设定标量以及向量中元素的值。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

这道题并不难，但是代码量大，写起来挺顺畅的。

# P5

> 5\. 编写函数返回组成某一正整数的所有数字之和，如：组成1056的数字和为12。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

水题。只是我在思考能不能把它提点速？(基本没戏)

很好。TODO List + 1。

# P6

> 6\. 一口水井深 a 米，一只青蛙在井底，一次向上跳 b 米，编写函数计算青蛙至少需要跳多少次才能跳出水井。这里假设 a , b 都是正整数。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

水题，注意临界情况。

# P7

> 7\. 从键盘读入四个0-9之间的数字，输出这四个数字能组成的最大十进制数，比如：读入0, 3, 1, 9， 输出9310。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

用时：30min

1. **谁\*\*不会用就写快排啊，还不用标准库里的算法！**

    So，记住算法！
2. **虽然应该会AK，但是确实写错了**：手写的`qsort`就是只考虑了`ascd`的情况而没有考虑`non-dscd`的情况。
3. **其它**：都挺好的。

# P8

> 8. 已知矩阵 B 是 $4\times4$ 的矩阵，写程序利用初等行变换将矩阵 B 化为阶梯型矩阵，矩阵 B 中元素的值用 `rand()%4` 产生，并检查你的计算结果是否正确。\
如果没有特别说明，计算机语言为C语言，将程序源代码（注意源代码上传，不是截图上传）及运行结果截图请粘贴在答案区。

1. **自己作死**：第七题写了自己没背下来的快排，反复改BUG，直接导致第七题用时30min
2. **时间太紧就不先去研究算法**：最后第八题没时间写，却还是不研究如何计算。直接导致自己忽略了行交换这个步骤
3. **代码复用不足**：如名。可以考虑一下。

## P8算法

### 如何阶梯化

有两种思路，一种用迭代，一种用递归。实际上是递归的思路思考起来更清晰一点，只是代码有些细节会很难处理。迭代的思路更符合平时做阶梯化的思路。

算法复杂度应该是O((m+n)×n)

#### 思路

手写阶梯化过程，就是从左到右从上往下一一把每一行化作0

这里考试后写的代码里我使用了单层循环，考试时使用了双层循环，还用了for，显然不对。差评。

变量i,j表示目前处理到的列以及处理到的行。

**如果：**

1. **第i列j行及下面都是0**：跳过这一列，处理下一列
2. **第i列j行是0**：找不为0的，行交换，继续处理
3. **把i行j列下面的变成0**：行倍加嘛，略。

### 一些实现细节

1. `#include <time.h>`是为了**给随机数函数设置种子**，避免某些机器上会始终随机出同样的矩阵。
2. 

### Solution

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const double DOUBLE_DIFF = 1e-6;

/**Matrix function**/
void ref_matrix(double *mat, double *res, int m, int n);
void vec_add(double *vec1, double *vec2, double *res, int l);
void vec_scalar(double *vec, int l, double scalar, double *res);
void swap_two_row(double *matrix, int row1, int row2, int m, int n);
/*utility function*/
int fcmp(double a, double b);
void swap(double *a, double *b);
void print_matrix(double *a, int m, int n);
void print_array(double *a, int l);

void print_array(double *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

/*swap two element*/
void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

/*compare double*/
int fcmp(double a, double b) {
    if (a - b > DOUBLE_DIFF) {
        return 1;
    } else if (a - b < -DOUBLE_DIFF) {
        return -1;
    } else {
        return 0;
    }
}

/*swap two row in the matrix*/
void swap_two_row(double *matrix, int row1, int row2, int m, int n) {
    for (int i = 0; i < n; i++) {
        swap(&matrix[row1 * n + i], &matrix[row2 * n + i]);
    }
}

/*as the name*/
void vec_add(double *vec1, double *vec2, double *res, int l) {
    for (int i = 0; i < l; i++) {
        res[i] = vec1[i] + vec2[i];
    }
}

/*as the name*/
void vec_scalar(double *vec, int l, double scalar, double *res) {
    for (int i = 0; i < l; i++) {
        res[i] = vec[i] * scalar;
    }
}

/*as the name*/
void print_matrix(double *a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", a[i * n + j]);
        }
        printf("\n");
    }
}

/*convert m*n matrix `mat` to its Row Echelon Form(REF) and write to matrix
 * `res`*/
void ref_matrix(double *mat, double *res, int m, int n) {
    // a variable to save mid result
    double *temp = (double *)malloc(n * sizeof(double));
    // copy it from `mat` to `res`. not modify original matrix. though in fact,
    // can be accepted.
    for (int i = 0; i < m * n; i++) {
        res[i] = mat[i];
    }
    int i = 0, j = 0;
    // well, think after finishing it, using recursion to ref a sub matrix is
    // straightforward than using iteration loop. though it would be a bit
    // complex to write the map from 2D pos to 1D index.
    while (i < n && j < m) {
        // this `if` statement process the condition when the first elem [0,0]
        // in submatrix mat_{i~m, j~n} is 0. if each elem in the first column of
        // submatrix is 0, then skip this column to process submatrix mat_{i +
        // 1~m, j~n}.
        if (fcmp(res[j * n + i], 0) == 0) {
            int flag = 1;
            for (int k = j; k < m; k++) {
                if (fcmp(res[k * n + i], 0) != 0) {
                    swap_two_row(res, j, k, m, n);
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                i++;
                continue;
            }
        }
        // set the first elem of column 0 of submatrix mat_{i~m, j~n} to 0 using
        // line multi scalar and line plus
        for (int k = j + 1; k < m; k++) {
            // print_array(&res[k * n], n);
            vec_scalar(&res[j * n], n, -res[k * n + i] / res[j * n + i], temp);
            // print_array(temp, n);
            vec_add(&res[k * n], temp, &res[k * n], n);
            // print_array(&res[k * n], n);
        }
        i++;
        j++;
    }
}

void _rec_ref_matrix(double *res, int i, int j, int m, int n,
                     double *temp) {
    // set stop condition
    // `i` is the column idx current processing, `j` is the row idx current
    // processing
    if (i >= n || j >= m) {
        return;
    }
    if (fcmp(res[j * n + i], 0) == 0) {
        int flag = 1;
        for (int k = j; k < m; k++) {
            if (fcmp(res[k * n + i], 0) != 0) {
                swap_two_row(res, j, k, m, n);
                flag = 0;
                break;
            }
        }
        if (flag) {
            _rec_ref_matrix(res, i + 1, j, m, n, temp);
            return;
        }
    }
    // set the first elem of column 0 of submatrix mat_{i, j} to 0 using
    // line multi scalar and line plus
    for (int k = j + 1; k < m; k++) {
        // print_array(&res[k * n], n);
        vec_scalar(&res[j * n], n, -res[k * n + i] / res[j * n + i], temp);
        // print_array(temp, n);
        vec_add(&res[k * n], temp, &res[k * n], n);
        // print_array(&res[k * n], n);
    }
    _rec_ref_matrix(res, i + 1, j + 1, m, n, temp); // 似乎可以做尾调用优化
}

/*entrance function for recursion version of ref_matrix()*/
void rec_ref_matrix(double *mat, double *res, int m, int n) {
    double *temp = (double *)malloc(m * n * sizeof(double));
    for (int i = 0; i < m * n; i++) {
        res[i] = mat[i];
    }
    _rec_ref_matrix(res, 0, 0, m, n, temp);
}

int main() {
    // add some variable so that the random matrix is not fixed on one machine
    long timer;
    time(&timer); // current UNIX timestamp
    srand(timer);
    double B[16], REFB[16];
    for (int i = 0; i < 16; i++) {
        B[i] = rand() % 4;
    }
    // double B[16] = {3, 3, 2, 0, 1, 1, 1, 1, 1, 0, 1, 0, 3, 3, 2, 3};
    // double REFB[16];
    print_matrix(B, 4, 4);
    printf("\n");
    // two types of function for you to choose
    // ref_matrix(B, REFB, 4, 4);
    rec_ref_matrix(B, REFB, 4, 4);
    print_matrix(REFB, 4, 4);
}
```
