#include "algebraic.h"
#include <stdio.h>
#include "../../utils/utils.h"
#include "../../main.h"


void collapse_string(char *s, int start, int end)
{
    printf("Before: %s\n", s);
    for (int i = start; s[i] != '\0'; i++) {
        s[i] = s[i + end - start + 1];
    }
    printf("After: %s\n\n", s);
}


void strip_parens(void)
{
    int i;
    for (i = 0; input[i] != '='; i++) {
        ;;
    }
    if (input[0] == '(' && input[i - 1] == ')') {
        collapse_string(input, 0, 0);
        collapse_string(input, i - 2, i - 2);
    }
}