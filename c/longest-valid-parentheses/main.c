#include <stdio.h>
#include <string.h>

int longestValidParentheses(char *s) {
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    if (sLen == 0 || sLen == 1)
        return 0;
    char p[sLen];
    int maxLen = 0;
    while (i < sLen) {
        if (s[i] == '(') {
            p[j] = s[i];
            printf("1. p[%d]=%c\n", j, p[j]);
            j++;
        } else if (s[i] == ')' && j > 0 && p[j - 1] == '(') {
            maxLen++;
            printf("2. p[%d]=%c\n", j, p[j]);
        } else if (s[i] == ')' && j > 0 && p[j - 1] != '(')
            maxLen--;
        i++;
    }

    // printf("maxLen=%d\n", maxLen * 2);
    // printf("sLen=%d\n", sLen);
    return maxLen * 2;
}

int main() {
    char *s = ")()())";
    // char *s = "";
    int result = longestValidParentheses(s);
    printf("result: %d\n", result);
    return 0;
}
