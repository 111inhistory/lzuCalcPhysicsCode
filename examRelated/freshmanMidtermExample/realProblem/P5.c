#include <stdio.h>
#include <stdlib.h>

void del(int *array, int idx, int length) {
    for (int i = idx; i < length - 1; i++) {
        array[i] = array[i + 1];
    }
}

void print_array(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = rand() % 100;
    }
    print_array(array, 100);
    for (int i = 0; i < 100; i++) {
        int idx = rand() % (100 - i);
        printf("length=%d, del index=%d\n", 100 - i, idx);
        del(array, idx, (100 - i));
        print_array(array, 99 - i);
    }
    return 0;
}