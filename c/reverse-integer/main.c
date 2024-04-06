#include <limits.h>
#include <stdio.h>

int reverse(int x) {
    int tempx = x;
    int i = 0;
    while (x != 0) {
        int rightDigit = x % 10;
        x = x / 10;
        i++;
    }
    long int reverseInt = 0;
    long int extracedInt = 0;
    while (tempx != 0) {
        int rightDigit = tempx % 10;
        tempx = tempx / 10;
        long int ten = 1;
        for (int k = 0; k < i - 1; k++) {
            ten *= 10;
        }
        extracedInt = rightDigit * ten;
        reverseInt = reverseInt + extracedInt;
        i--;
    }
    if (reverseInt <= INT_MIN || reverseInt >= INT_MAX) {
        return 0;
    }

    return (int)reverseInt;
}

int main() {
    int result = reverse(1534236469);
    printf("resutl = %d\n", result);

    return 0;
}
