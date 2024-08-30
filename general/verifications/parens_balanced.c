#include <stdio.h>

int parens_balanced(char *s)
{
    int scale = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '(') {
            scale++;
        } else if (*p == ')' && --scale < 0) {
            printf("\nImbalanced parentheses, exiting\n");
            return 0;
        }
    }
    if (scale != 0) {
        printf("\nImbalanced parentheses, exiting\n");
    }
    return scale == 0 ? 1 : 0;
}
