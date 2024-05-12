/*
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 */

#include <stdbool.h>
#include <stdio.h>

void nextPermutation(int array[], int length) {
    // Find non-increasing suffix
    if (length == 0)
        return;
    size_t i = length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    if (i == 0)
        return;

    // Find successor to pivot
    int j = length - 1;
    while (array[j] <= array[i - 1])
        j--;
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    // Reverse suffix
    j = length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int nums[3] = {1, 2, 3};
    int numsSize = 3;
    nextPermutation(nums, numsSize);
    for (int i; i < numsSize; i++) {
        printf("%d", nums[i]);
    }
}
