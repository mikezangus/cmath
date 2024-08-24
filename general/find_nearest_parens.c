#include "../main.h"

void find_nearest_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            parens.l = i;
        } else if (input[i] == ')') {
            parens.r = i;
            return;
        }
    }
}
