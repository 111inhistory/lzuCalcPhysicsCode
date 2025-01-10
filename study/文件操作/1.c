#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VEC_SIZE 100

/*Caller Free!*/
char *customFileRead(FILE *file, long size, long *str_len) {
    if (size == -1) {
        long l = VEC_SIZE;
        char *a = malloc(100 * sizeof(char));
        long i = 0;
        a[i] = fgetc(file);
        while (a[i] != EOF) {
            i++;
            if (i == l) {
                char *b = realloc(a, l + VEC_SIZE);
                if (b != a) {
                    if (b == NULL) {
                        fprintf(stderr,
                                "Cannot reallocate enough memory. Original "
                                "Size %ld, Targeted Size %ld\n",
                                l, l + VEC_SIZE);
                        exit(2);
                    }
                }
                a = b;
                l = l + VEC_SIZE;
            }
            a[i] = fgetc(file);
        }
        a[i] = '\0';
        *str_len = i;
        int test_fread[1000] = {0};
        fseek(file,-1000*sizeof(int),SEEK_CUR);
        fread(test_fread, sizeof(int), 1000, file);
        printf("[DBG] test_fread[0] is %d\n", test_fread[0]);
        printf("[DBG] (char)test_fread[999] is %c\n", ((char *)test_fread)[3]);
        printf("[DBG] str_len is %ld\n", *str_len);
        printf("[DBG] a[str_len] is %c\n", a[*str_len]);
        return a;
    } else {
        char *a = malloc((size + 1) * sizeof(char));
        if (a == NULL) {
            fprintf(stderr, "Cannot allocate enough memory. Size %ld\n",
                    size + 1);
            exit(2);
        }
        *str_len = fread(a, sizeof(char), size, file);
        printf("[DBG] str_len is %ld\n", *str_len);
        printf("[DBG] a[str_len] is %c\n", a[*str_len]);
        return a;
    }
}

void doSthWithFile() {
    /*创建文件*/
    FILE *new_file = fopen("sdkllew.txt", "w");
    if (new_file == NULL) {
        fprintf(stderr, "Cannot open file sdkllew.txt\n");
        exit(1);
    } // Thanks Copilot副驾驶
    /*写入文件*/
    // char string[] = "111";
    // fwrite(string, sizeof(char), sizeof(string) - 1,
    //        new_file); // length - 1 to ensure '\0' is not written into the file
    // fclose(new_file);
    char string[11] = "9999999999";
    long len = 0;
    for (int i = 0; i < 1024 * 1024; i++) {
        fwrite(string, sizeof(char), 10, new_file);
        len += 10;
    }
    printf("[DBG] Written len %ld\n", len);
    /*读取文件*/
    new_file = fopen("sdkllew.txt", "r");
    long stringl;
    char *a = customFileRead(new_file, -1, &stringl);
    printf("[DBG] Received str_len %ld\n", stringl);
    // printf("%s\n", a);
    free(a);
    fclose(new_file);
}

int main() { doSthWithFile(); }