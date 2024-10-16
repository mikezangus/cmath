#include <stdbool.h>
#include <stdio.h>

bool parens_balanced(char* s)
{
    short scale = 0;
    for (char* p = s; *p; p++) {
        if (*p == '(') {
            scale++;
        } else if (*p == ')' && --scale < 0) {
            printf("\nImbalanced parentheses, exiting\n");
            return false;
        }
    }
    if (scale != 0) {
        printf("\nImbalanced parentheses, exiting\n");
    }
    return scale == 0;
}
