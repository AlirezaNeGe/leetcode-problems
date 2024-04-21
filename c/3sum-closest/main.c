#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

int threeSumClosest(int *nums, int numsSize, int target) {
    if (numsSize < 3)
        return 0;
    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }
    qsort(nums, numsSize, sizeof(int), compare);

    int i = 0;
    int next = 0;
    int last = 0;
    int sumResult = nums[0] + nums[1] + nums[2];
    int diff = abs((nums[0] + nums[1] + nums[2]) - target);

    while (i < numsSize - 2) {
        int num = nums[i];
        next = i + 1;
        last = numsSize - 1;
        while (next < last) {
            int sum = num + nums[next] + nums[last];
            if (sum == target)
                return sum;
            if (abs(target - sum) < abs(diff)) {
                diff = sum - target;
                sumResult = sum;
            }
            if (sum > target) {
                last--;
            } else {
                next++;
            }
        }
        i++;
    }
    return sumResult;
}

int main() {
    int nums[4] = {1, 1, 1, 1};
    int result = threeSumClosest(nums, 4, 0);

    printf("result: %d\n", result);

    return 0;
}
