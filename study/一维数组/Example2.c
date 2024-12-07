#include <stdio.h>
#include <stdlib.h>

void setstar(char *a, int n) {
    for (int i = 4; i < n; i++) {
        a[i] = '*';
    }
}

int main() {
    char a[10] = "lzu.edu.cn";
    printf("%s\n", a);
    setstar(a, 10);
    printf("%s\n", a);
}