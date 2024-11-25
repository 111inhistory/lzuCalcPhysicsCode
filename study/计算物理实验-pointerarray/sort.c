#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void arr_sort(int *arr, int cnt) {
    if (cnt< 2) {
        return;
    }
    int base = arr[0];
    int left = 0, right = cnt - 1;
    while (left <= right) {
        while (arr[left] <= base && left <= right) {
            left++;
        }
        while (arr[right] >= base && left <= right) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[0], &arr[right]);
    arr_sort(arr, right);
    arr_sort(&arr[right + 1], cnt - right - 1);
}

void print_array(int *arr, int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[13] = {6, 134, 67,124, 3, 536,123,3,56,1,2,7,1,5,};
    print_array(arr, 13);
    arr_sort(arr, 13);
    print_array(arr, 13);
}