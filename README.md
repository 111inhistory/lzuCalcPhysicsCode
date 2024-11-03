# lzuCalcPhysicsCode

记录了我写的代码。就这。

# 文件说明

编程环境：VSCode + WSL2 Ubuntu-22.04 + clang 14.0.0 + gcc 11.4.0 + python 

1. 每个程序由3部分组成，源代码.c，可执行文件，输出结果.out，输入范例.in。
2. 不能存在未定义行为。
3. 按照章节分类。
4. (目前Optional)做的每个题目实现函数后编写`test`做io测试（虽然这个可能并不好），考虑以后做一个通用实现。差不多是：
    ```c
    int main() {
        char s[64];
        scanf("%s", s);
        if (strcmp(s, "函数1") == 0) {
            test_matrix_mul_vec();
        } else if (strcmp(s, "函数2") == 0) {
            test_matrix_mul_matrix();
        } else {
            printf("No test found");
        }
        return 0;
    }
    ```
然后的话就是通过文件导入stdin（终端上进行测试），写好.in和.out
5. `test_<filename>_<function_name>.in`是对某个文件的某个函数的输入，第一行为test函数名。同理，`test_<filename>_<function_name>.out`是对某个文件的某个函数的输出。