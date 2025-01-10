#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define FILE_SIZE (1024*1024*10) // 10MB测试文件

void create_test_file() {
    FILE *fp = fopen("test.bin", "r");
    // 避免重复生成文件
    if (fp) {
        return;
    }
    fp = fopen("test.bin", "wb");
    for(int i = 0; i < FILE_SIZE; i++) {
        fputc('w', fp);
    }
    fclose(fp);
}

double test_fgetc() {
    struct timeval start, end;
    FILE *fp = fopen("test.bin", "rb");
    gettimeofday(&start, NULL);
    
    int c;
    while((c = fgetc(fp)) != EOF);
    
    gettimeofday(&end, NULL);
    fclose(fp);
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
}

double test_getc() {
    struct timeval start, end;
    FILE *fp = fopen("test.bin", "rb");
    gettimeofday(&start, NULL);
    
    int c;
    while((c = getc(fp)) != EOF);
    
    gettimeofday(&end, NULL);
    fclose(fp);
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
}

int main() {
    create_test_file();
    
    double fgetc_time = test_fgetc();
    double getc_time = test_getc();
    
    printf("fgetc耗时: %.6f秒\n", fgetc_time);
    printf("getc耗时:  %.6f秒\n", getc_time);
    printf("差异百分比: %.2f%%\n", (fgetc_time - getc_time) * 100 / fgetc_time);
    
    return 0;
}