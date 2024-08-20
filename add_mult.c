#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

extern char input[];
extern int i_var;

void add_mult(void)
{
    int start = strlen(input) + 1;
    if (isdigit(input[i_var - 1])) {
        for (int i = start; i >= i_var; i--) {
            input[i] = input[i - 1];
        }
        input[i_var] = '*';
    }
    i_var++;
    printf("Via add mult: %s\n", input);
}
