#include <stdbool.h>
#include <stdio.h>

extern char input[];
extern bool parens;

void parens_exist(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            parens = true;
            return;
        }
    }
    parens = false;
}
