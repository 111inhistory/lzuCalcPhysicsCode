// TODO!!!!
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
    int total = nums1Size + nums2Size;
    int mid = total / 2;
    int avg_flag = (~total) & 1;
    int min, *a;
    if (nums1Size > nums2Size) {
        min = nums2Size;
        a = nums2;
    } else {
        min = nums1Size;
        a = nums1;
    }
    int p = min / 2;
    while (1) {
        int remain = mid - p;
    }
}

int main() {
    int nums1[] = {1, 5, 9};
    int nums2[] = {2, 4, 5};
    printf("%lf\n",
           findMedianSortedArrays(nums1, sizeof(nums1), nums2, sizeof(nums2)));
}