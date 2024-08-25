#include "../main.h"
#include <stdio.h>

int check_parens_balanced(void)
{
    int scale = 0;
    for (char *p = input; *p != '\0'; p++) {
        if (*p == '(') {
            scale++;
        } else if (*p == ')') {
            if (--scale < 0) {
                printf("\nImbalanced parentheses, exiting\n");
                return 0;
            }
        }
    }
    return scale == 0;
}
