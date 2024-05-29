#include <stdbool.h>
#include <stdio.h>

bool isMatch(char *s, char *p);
bool matchhere(char *s, char *p);
bool matchstar(int c, char *s, char *p);

bool isMatch(char *s, char *p) {
    do {
        if (!matchhere(s, p)) {
            printf("1. s=%s, p=%s\n", s, p);
            return false;
        }
    } while (*s++ != '\0');
    return true;
}

bool matchhere(char *s, char *p) {
    if (p[0] == '\0')
        return true;
    if (p[1] == '*') {
        // printf("2. s=%s, p=%s, p[0]=%c\n", s, p + 2, p[0]);
        return matchstar(p[0], s, p + 2);
    }
    if (*s != '\0' && (p[0] == '.' || p[0] == *s)) {
        return matchhere(s + 1, p + 1);
    }
    return false;
}

bool matchstar(int c, char *s, char *p) {
    do {
        if (!matchhere(s, p)) {
            printf("false, s=%s, p=%s\n", s, p);
            return false;
        }
    } while (*s != '\0' && (*s++ == c || c == '.'));
    return true;
}

int main() {
    char *s = "aab";
    char *p = "c*a*b";
    printf("matched: %d\n", isMatch(s, p));
}
