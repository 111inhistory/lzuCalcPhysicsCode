// TODO!!!!
#include <stdio.h>
#include <stdlib.h>

/*Ensure `idx < n1 + n2` By yourself*/
void getPointerUnsafe(int *nums1, int n1, int *nums2, int n2, int **p, int idx) {
    if (n1 == 0) {
        *p = nums2 + idx;
    } else if (n2 == 0) {
        *p = nums1 + idx;
    } else if (idx > n1) {
        *p = nums2 + idx - n1;
    } else {
        *p = nums1 + idx;
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
    if (nums1 == 0 && nums2 == 0) {
        return 0;
    }
    int total = nums1Size + nums2Size;
    // Imagine there is a int array of length nums1Size + nums2Size, than find the mid
    // Assume that left indicates the result
    int left = 0, right = total - 1;
    int *resp, *remainp;
    getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &resp, left);
    getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &remainp, right);
    while (left < right) {
        int mid = (left + right) - 1;
        if (*resp > *remainp) {
            right = mid - 1;
            getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &resp, right);
            getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &remainp, total - 1 - right);
            printf("left++:%d, right:%d, *resp=%d, *remainp=%d\n", left, right, *resp, *remainp);
        } else if (*resp < *remainp) {
            left = mid;
            getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &resp, left);
            getPointerUnsafe(nums1, nums1Size, nums2, nums2Size, &remainp, total - 1 - left);
            printf("left:%d, right--:%d, *resp=%d, *remainp=%d\n", left, right, *resp, *remainp);
        } else {
            return *resp;
        }
    }
    return *resp;
}

int main() {
    int nums1[] = {1, 5, 9};
    int nums2[] = {2,4,6};
    printf("%lf\n",
           findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int)));
}