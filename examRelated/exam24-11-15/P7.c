#include <stdio.h>

void swap(int *a, int *b);

void print_array(int *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sort(int *num, int l) {
    // print_array(num, l);
    if (l < 2) {
        return;
    }
    int base = num[0];
    int left = 1, right = l - 1;
    while (left < right) {
        // printf("%d ", left);
        while (num[left] <= base && left < right) {
            left++;
        }
        // printf("%d ", left);
        // printf("%d ", right);
        while (num[right] >= base && left < right) {
            right--;
        }
        // printf("%d ", right);
        // printf("\n");
        swap(&num[left], &num[right]);
    }
    // printf("swap idx %d %d and idx %d %d\n", 0, num[0], right, num[right]);
    swap(&num[0], &num[right]);
    sort(num, right);
    sort(&num[right+1], l - right - 1);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_max_num(int *a, int l) {
    // assume that a is ascending
    if (a[l-1] != 0) {
        for (int i = l-1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    } else {
        printf("the input num can't combine into a valid number\n");
    }
}

int main() {
    // int a[10] = {3,4,2,5,1,5,8,9,0,4};
    // qsort(a, 10);
    // print_array(a, 10);
    int a[4];
    for (int i = 0; i < 4; i++){
        scanf("%d", &a[i]);
    }
    sort(a, 4);
    // print_array(a, 4);
    print_max_num(a, 4);
}