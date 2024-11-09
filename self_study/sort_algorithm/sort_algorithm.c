#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int predicate_ascd(int *array, int length);
void insertion_sort(int *array, int length);
int test_insertion_sort();
void selection_sort(int *array, int length);
int test_selection_sort();
void swap(int *a, int *b);
int test_swap();
int binary_search(int *array, int length, int key);
int test_binary_search();
void merge(int *array1, int length1, int *array2, int length2, int *res);
int test_merge();
void merge_sort(int *array, int length);
int test_merge_sort();

static const int test_array[101] = {
    100, 91, 8,  2,  7,  80, 40, 36, 67, 24, 63, 9,  20, 38, 21, 95, 93,
    79,  71, 32, 11, 89, 99, 46, 85, 98, 22, 75, 49, 72, 37, 53, 12, 19,
    13,  82, 81, 78, 58, 50, 61, 43, 70, 1,  57, 97, 77, 51, 68, 25, 31,
    3,   47, 74, 18, 23, 45, 66, 83, 4,  27, 6,  55, 59, 88, 62, 73, 30,
    16,  84, 26, 33, 39, 76, 52, 87, 5,  90, 44, 34, 48, 65, 56, 69, 35,
    15,  60, 14, 41, 28, 10, 96, 54, 94, 92, 0,  86, 29, 64, 42, 17};

/*Check if the length of array is ascending.*/
int predicate_ascd(int *array, int length) {
    for (int i = 0; i < length - 1; ++i) {
        if (array[i] > array[i + 1])
            return 0;
    }
    return 1;
}

/*A function to swap to data. Maybe std func better.*/
void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int test_swap() {
    int a[2] = {1, 2};
    swap(&a[0], &a[1]);
    return (a[0] == 2 && a[1] == 1);
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
    for (int i = 0; i < length - 1; i++) { // length 1 array is always ordered.
        int j = i + 1;
        int key = array[j];
        for (; j > 0 && array[j - 1] > key; j--) { // the second statement
            // in for loop statement is a expression, you can add conditions
            // whatever you want.
            int a = array[j-1];
            array[j] = array[j - 1];
        }
        array[j] = key;
    }
}

int test_insertion_sort() {
    int *array = (int *)malloc(sizeof(int) * test_array[0]);
    memcpy(array, test_array + 1, sizeof(int) * test_array[0]);
    insertion_sort(array, test_array[0]);
    return predicate_ascd(array, test_array[0]);
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

int test_selection_sort() {
    int *array = (int *)malloc(sizeof(int) * test_array[0]);
    memcpy(array, test_array + 1, sizeof(int) * test_array[0]);
    selection_sort(array, test_array[0]);
    return predicate_ascd(array, test_array[0]);
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
            right = mid;
        } else if (array[mid] < key) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

int test_binary_search() {
    int *array = (int *)malloc(sizeof(int) * test_array[0]);
    for (int i = 0; i < test_array[0]; i++) {
        array[i] = i + 1;
    }
    for (int i = 0; i < test_array[0]; ++i) {
        if (binary_search(array, test_array[0], array[i]) != i) {
            return 0;
        }
    }
    return 1;
}

/*
A function helps merge_sort.

It receives two ordered array and merge them into one ordered array(res).

Algorithm complexity is O(n).
*/
void merge(int *array1, int length1, int *array2, int length2, int *res) {
    int i = 0, j = 0;
    int cnt = 0;
    while (i < length1 && j < length2) {
        if (array1[i] < array2[j]) {
            res[cnt++] = array1[i++];
        } else {
            res[cnt++] = array2[j++];
        }
    }
    if (i < length1) {
        do {
            res[cnt++] = array1[i++];
        } while (i < length1);
    }
    if (j < length2) {
        do {
            res[cnt++] = array2[j++];
        } while (j < length2);
    }
}

int test_merge() {
    int *array1 = (int *)malloc(50 * sizeof(int));
    int *array2 = (int *)malloc(50 * sizeof(int));
    int *res = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < 50; i++) {
        array1[i] = i;
    }
    for (int i = 0; i < 50; i++) {
        array2[i] = i + 50;
    }
    merge(array1, 50, array2, 50, res);
    if (!predicate_ascd(res, 100)) {
        return 0;
    } else {
        for (int i = 0; i < 100; i++) {
            if (res[i] != i) {
                return 0;
            }
        }
        return 1;
    }
}

/*
Merge Sort:

Split the array and sort it recursively.

The implement below will make the array ascending.

Algorithm complexity is O(logn*n), and it's very fixed in real life sorting.
*/
void merge_sort(int *array, int length) {
    int mid = length / 2;
    switch (length) {
    case 1:
        return;
    case 2:
        if (array[0] > array[1]) {
            swap(&array[0], &array[1]);
        }
        return;
    default:
        merge_sort(array, mid);
        merge_sort(array + mid, length - mid);
    }
    int *res = (int *)malloc(length * sizeof(int));
    // DO NOT USE merge() TO WRITE BACK TO ARRAY! IT WILL LEAD TO LOGIC ERROR!
    merge(array, mid, array + mid, length - mid, res);
    for (int i = 0; i < length; i++) {
        array[i] = res[i];
        // printf( "%d ", array[i]);
    }
    // printf( "\n");
    free(res);
}

int test_merge_sort() {
    int *array = (int *)malloc(sizeof(int) * test_array[0]);
    memcpy(array, test_array + 1, sizeof(int) * test_array[0]);
    merge_sort(array, test_array[0]);
    return predicate_ascd(array, test_array[0]);
}

int main() {
    char s[64];
    scanf("%s", s);
    if (strcmp(s, "test_insertion_sort") == 0) {
        assert(test_insertion_sort());
    } else if (strcmp(s, "test_selection_sort") == 0) {
        assert(test_selection_sort());
    } else if (strcmp(s, "test_swap") == 0) {
        assert(test_swap());
    } else if (strcmp(s, "test_binary_search") == 0) {
        assert(test_binary_search());
    } else if (strcmp(s, "test_merge") == 0) {
        assert(test_merge());
    } else if (strcmp(s, "test_merge_sort") == 0) {
        assert(test_merge_sort());
    } else {
        printf("No test found\n");
    }
}