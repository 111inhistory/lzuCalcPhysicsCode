#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int length);
void selection_sort(int *array, int length);
void swap(int *a, int *b);
int binary_search(int *array, int length, int key);
void *merge_sort(int *array, int length);
void merge(int *array1, int length1, int *array2, int length2, int *res);

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

/*
Insertion Sort:

It will make a part of the array ordered. For each element outside the ordered
part, it will compare and add the element to the ordered part. Thus, the part
expanded and still be ordered.

The implement below will maintain the part of the array on the left ordered and
make the array ascending.

Algorithm complexity is O(n^2), but will take less time due to the dist of data.
*/
void insertion_sort(int *array, int length) {
    for (int i = 1; i < length; i++) { // length 1 array is always ordered.
        for (int j = i + 1; j > 0 && array[j - 1] > array[j];
             j--) { // the second statement in for loop statement is a
                    // expression, you can add conditions whatever you want.
            swap(&array[j], &array[j - 1]);
        }
    }
}

/*
Selection Sort:

Very easy. Some thoughts are the same as insertion sort, so don't be confused.
Maintain part of the array ordered(and is the final version), and loop the
rest find min or max, then swap the two.

The implement below will maintain the part of the array on the left ordered and
make the array ascending.

Algorithm complexity is O(n^2)
*/
void selection_sort(int *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int key = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[key]) {
                key = j;
            }
        }
        swap(&array[i], &array[key]);
    }
}

/*
Binary Search:

The array must be ordered. If not, it will return meaningless result.

The implement receives a ascending array and return the index that array[index]
<= key.

Algorithm complexity is O(logn).
*/
int binary_search(int *array, int length, int key) {
    int left = 0;
    int right = length - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (array[mid] > key) {
            left = mid;
        } else if (array[mid] < key) {
            right = mid;
        } else {
            return mid;
        }
    }
    return left;
}

/*
A function helps merge_sort.

It receives two ordered array and merge them into one ordered array(res).

Algorithm complexity is O(n).
*/
void merge(int *array1, int length1, int *array2, int length2, int *res) {
    int i=0,j=0;
    int cnt = 0;
    while (i < length1 || j < length2) {
        if (array1[i] < array2[j]) {
            res[cnt] = array1[i];
            cnt++;
            i++;
        } else {
            res[cnt] = array2[j];
            cnt++;
            j++;
        }
    }
    if (i < length1) {
        for (; i < length1; i++) {
            res[cnt++] = array1[i];
        }
    }
    if (j < length2) {
        for (; j < length2; i++) {
            res[cnt++] = array2[j];
        }
    }
}

/*
Merge Sort:

Split the array and sort it recursively.

The implement below will make the array ascending.

Algorithm complexity is O(logn*n), and it's very fixed in real life sorting.

Due to the process, it will 
*/
void *merge_sort(int *array, int length) {
    int mid = length / 2;
    int *arr1 = merge_sort(array, mid);
    int *arr2 = merge_sort(&array[mid], length - mid);
    int *res = (int *)malloc(length * sizeof(int));
    // DO NOT USE merge() TO WRITE BACK TO ARRAY! IT WILL LEAD TO LOGIC ERROR!
    merge(arr1, mid, arr2, length-mid, res);
    free(arr1);
    free(arr2);
    for (int i = 0; i < length; i++) {
        array[i] = res[i];
    }
    free(res);
}