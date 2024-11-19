#include <stdio.h>
#include <stdlib.h>

int test_array[200];

void swap(int *a, int *b);

void print_array(int *a, int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
Quick Sort:

It's like the reverse version of merge. Split, and recursive the parts, assume
after each opration it will be well sorted. In fact, it's a improved version of
bubble sorting.

Average algorithm complexity is O(nlogn)
*/
void sort(int *array, int length) {
    // end condition check
    if (length < 2) {
        return;
    }
    // does worth the condition check?
    // if (length == 2) {
    //     if (array[0] > array[1]) {
    //         swap(&array[0], &array[1]);
    //     }
    // }
    int base = array[0];
    // init two pointers
    int left = 1;
    int right = length - 1;
    while (left <= right) {
        // find two elem, one small in the right part, one big in the left part,
        // then swap them. if left is the start of the right part, it still
        // work. The same when right is the end of the left part.
        while (array[right] >= base && left <= right) {
            right--;
        }
        while (array[left] <= base && left <= right) {
            left++;
        }
        if (left < right) {
            swap(&array[left], &array[right]);
        }
    }
    swap(&array[0], &array[right]);
    // the base is at array[right] now
    // sort the left part and right part except the base, cause it will make
    // infinite recursion.
    sort(&array[0], right);
    sort(&array[right + 1], length - right - 1);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_max_num(int *a, int l) {
    // assume that a is ascending
    if (a[l - 1] != 0) {
        for (int i = l - 1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    } else {
        printf("the input num can't combine into a valid number\n");
    }
}

int main() {
    // // int a[10] = {3,4,2,5,1,5,8,9,0,4};
    // // qsort(a, 10);
    // // print_array(a, 10);
    int a[4];
    for (int i = 0; i < 4; i++){
        scanf("%d", &a[i]);
    }
    sort(a, 4);
    // print_array(a, 4);
    print_max_num(a, 4);
    // for (int i = 0; i < 200; i++) {
    //     test_array[i] = rand() % 100;
    // }
    // sort(test_array, 200);
    // print_array(test_array, 200);
}