#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
    int newSize = nums1Size + nums2Size;
    int newNums[newSize];

    int i, j, newIndex = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            newNums[newIndex++] = nums1[i++];
        } else {
            newNums[newIndex++] = nums2[j++];
        }
    }

    while (i < nums1Size)
        newNums[newIndex++] = nums1[i++];
    while (j < nums2Size)
        newNums[newIndex++] = nums2[j++];

    double median;
    if ((newSize % 2) != 0) {
        median = newNums[newSize / 2];
    } else {
        median =
            ((double)newNums[newSize / 2] + (double)newNums[newSize / 2 - 1]) /
            2;
    }

    return median;
}

int main() {
    int nums1[2] = {1, 3};
    int nums2[2] = {2, 4};

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    double median = findMedianSortedArrays(nums1, 2, nums2, 2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("median=%f, time used: %f ms\n", median, cpu_time_used * 1000);
}
