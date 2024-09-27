#include <ctype.h>
#include <string.h>
#include "../../utils/utils.h"
#include "algebraic.h"

void insert_1(char* s)
{
    for (char* p = s; *p; p++) {
        if (*p == 'x' && !isdigit(*(p - 1))) {
            insert_str(s, "1", p);
            p++;
        }
    }
}

void remove_mult_1(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p) && *(p - 1) == '1') {
            collapse_str(p - 1, p);
        }
    }
}