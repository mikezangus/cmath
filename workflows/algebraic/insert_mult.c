#include "../../utils/utils.h"
#include <ctype.h>

void insert_mult(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'x' && isdigit(s[i - 1])) {
            insert_str(s, "*", i);
            i++;
        }
    }
}