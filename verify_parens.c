#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern char input[];

bool verify_parens(void)
{
    int scale = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            scale++;
        } else if (input[i] == ')') {
            scale--;
        }
    }
    return scale == 0;
}
