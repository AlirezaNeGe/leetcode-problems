#include <stdio.h>
#include <time.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
    // Check if either nums1 or nums2 has size zero
    if (nums1Size == 0 && nums2Size == 0) {
        return 0.0;
    } else if (nums1Size == 0) {
        if (nums2Size % 2 != 0) {
            return nums2[nums2Size / 2];
        } else {
            return (double)(nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) /
                   2;
        }
    } else if (nums2Size == 0) {
        if (nums1Size % 2 != 0) {
            return nums1[nums1Size / 2];
        } else {
            return (double)(nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) /
                   2;
        }
    }

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
    int nums2[1] = {2};

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    double median = findMedianSortedArrays(nums1, 0, nums2, 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("median=%f, time used: %f ms\n", median, cpu_time_used * 1000);
}
