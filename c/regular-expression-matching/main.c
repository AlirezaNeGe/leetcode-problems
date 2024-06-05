#include <stdbool.h>
#include <stdio.h>

bool isMatch(char *s, char *p);
bool matchhere(char *s, char *p);

bool isMatch(char *s, char *p) { return matchhere(s, p); }

bool matchhere(char *s, char *p) {
    if (p[0] == '\0') {
        return *s == '\0';
    }

    if (p[1] == '*') {
        if (matchhere(s, p + 2))
            return 1;
        while (*s != '\0' && (*s++ == p[0] || p[0] == '.'))
            if (matchhere(s, p + 2))
                return 1;
    } else if (*s != '\0' && (p[0] == '.' || p[0] == *s) &&
               matchhere(s + 1, p + 1)) {
        return 1;
    }
    return 0;
}

int main() {
    char *s = "aab";
    char *p = "c*a*b";
    printf("matched: %d\n", isMatch(s, p));
}
