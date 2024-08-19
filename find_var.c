#include <stdio.h>

extern char input[];
extern int var;

void find_var(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'x') {
            var = i;
        }
    }
}