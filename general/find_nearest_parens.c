#include "../main.h"

void find_nearest_parens(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            parens.l = i;
        } else if (s[i] == ')') {
            parens.r = i;
            return;
        }
    }
}
