#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    int j = 0;
    int i = 0;
    int tmp;
    for (i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num != val) {
            nums[j] = num;
            j++;
        }
    }
    return j;
}

int main() {
    int nums[4] = {3, 2, 2, 3};
    int result = removeElement(nums, 4, 3);
    printf("result: %d\n", result);

    return 0;
}
