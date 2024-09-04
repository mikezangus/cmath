#include <ctype.h>
#include <string.h>
#include "../../utils/utils.h"

void insert_1(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'x' && !isdigit(s[i - 1])) {
            insert_str(s, "1", i);
            i++;
        }
    }
}

void remove_1(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'x' && (s[i - 1] == '1')) {
            collapse_str(s, i - 1, i - 1);
        }
    }  
}
