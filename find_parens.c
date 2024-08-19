#include <stdbool.h>
#include <stdio.h>

extern char input[];
extern bool parens_exist;

void find_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            parens_exist = true;
            return;
        }
    }
    parens_exist = false;
}
