#include <stdio.h>

int maxArea(int *height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int area = 0;
    int maxArea = 0;
    int iHeight, jHeight = 0;

    while (i < heightSize - 1 && j > i) {
        iHeight = height[i];
        jHeight = height[j];
        if (iHeight >= jHeight) {
            area = (j - i) * jHeight;
            if (area < maxArea) {
                j--;
                continue;
            }
            maxArea = area;
            j--;
        } else {
            area = (j - i) * iHeight;
            if (area < maxArea) {
                i++;
                continue;
            }
            maxArea = area;
            i++;
        }
    }

    return maxArea;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    printf("maxArea: %d\n", maxArea(height, 9));

    return 0;
}
