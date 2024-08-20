#include <stdio.h>
#include <stdbool.h>

extern char input[];
extern bool var_exists;
extern int i_var;

void find_var(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'x') {
            var_exists = true;
            i_var = i;
        }
    }
}