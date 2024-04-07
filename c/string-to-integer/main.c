#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int myAtoi(char *s) {
    int positive = 1;
    int signDetected = 0;
    int digitSeen = 0;
    int leadingSpace = 0;
    int i = 0;
    long int result = 0;
    long int newResult = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' && i == 0) {
            leadingSpace = 1;
            continue;
        } else if (s[i] == ' ' && leadingSpace) {
            continue;
        } else if (s[i] == ' ' && !leadingSpace) {
            break;
        } else if (s[i] == '-') {
            if (digitSeen) {
                break;
            }
            if (!signDetected) {
                positive = 0;
                signDetected = 1;
                leadingSpace = 0;
                continue;
            } else {
                break;
            }
        } else if (s[i] == '+') {
            if (digitSeen) {
                break;
            }
            if (!signDetected) {
                positive = 1;
                signDetected = 1;
                leadingSpace = 0;
                continue;
            } else {
                break;
            }
        } else if (!isdigit(s[i])) {
            break;
        }
        digitSeen = 1;
        leadingSpace = 0;
        int digit = s[i] - '0';
        newResult = result * 10 + (long int)digit;

        // check for overflow
        if (newResult > INT_MAX || newResult < INT_MIN) {
            if (positive) {
                return INT_MAX;
            }
            return INT_MIN;
        }

        result = newResult;
    }

    if (!positive) {
        result = -result;
    }
    return result;
}

int main() {
    char *s = "      -42";
    printf("result: %d\n", myAtoi(s));

    return 0;
}
