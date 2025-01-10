# 文件操作Usage

## 函数

- `FILE *fopen(const char *filename, const char *mode)`: `filename`本质上是路径而非文件名。`mode`和Python等基本通用，比如"r","w","rb","wb","a","ab","r+","rb+"

- `int fclose(FILE *fp)`: 关闭文件，成功关闭返回`0`

- `size_t fwrite(const void *ptr, size_t size, size_t n, FILE *fp)`: 第一个参数\*\*是个指针，指向要写入的数据，`size`指的是单个元素大小，`n`表示元素数量，最后一个才是文件指针。

- `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`: 从`stream`读取`size * nmemb`字节保存到数组ptr中。
    - **注意**: 如果`size`>1，那么依旧会按字节一点一点给存进去。所以事实上，只要`size*nmemb`正确，随便填啥都行（虽然不建议）

- `int fseek(FILE *stream, long offset, int whence)`: 当前文件指针偏移（add）`offset`个字节（**可以为负**），返回`0`表示成功，返回非零值表示失败，`whence`有三个枚举值:
    - `SEEK_SET`: 以开头为基准
    - `SEEK_CUR`: 以当前文件指针为基准（直接在FILE->_offset上操作）
    - `SEEK_END`: 以文件末尾为基准（应该需要负数`offset`）

- `int fprintf(FILE *fp, format, ...)`: 比`printf()`多了一个`fp`参数，表示写入的流，其余无区别。返回值非负表示写入的字符数，负值表示出错。

- `int fscanf(FILE *fp, format, ...)`: 比`scanf()`多了一个`fp`参数，表示读取的流，其余无区别。返回值表示成功赋值的数量，或者`EOF`表示发生错误。

- `char getc(FILE *fp)`和`char fgetc(FILE *fp)`: `getc()`可以是个宏，也可以是个函数。而`fgetc()`是个函数。保险一点用`fgetc`，慢就慢吧（我甚至都觉得算误差）。

- `int fputchar(int c, FILE *fp)`和`int fputc(int c, FILE *fp)`和`putc(int c, FILE *fp)`：都是向"文件"写入字符。基本没区别，除去`putc()`可能为宏。返回`char`本身。（离谱）
    - 以上还有没有f开头的函数版本，都是向`stdout`写入。`int putchar(int c)`才是`fputc()`的写入stdout版本

- `char *fgets(char *str, int n, FILE *fp)`: 从`fp`中读取`n-1`个字符（或遇到换行符、EOF）存入`str`，末尾自动加`\0`。返回`str`，失败或EOF返回`NULL`。
    - **注意**: `fgets()`会把换行符`\n`也读进去

- `int fputs(const char *str, FILE *fp)`: 将字符串`str`写入`fp`，成功返回非负值，失败返回`EOF`。
    - 与`puts()`的区别：`puts()`会自动加换行，`fputs()`不会

- `int feof(FILE *fp)`: 返回是否EOF。本质是个bool。