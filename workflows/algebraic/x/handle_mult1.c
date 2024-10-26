#include <ctype.h>
#include <string.h>
#include "algebraic.h"
#include "../../utils/utils.h"

void insert_mult1(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p) && !isdigit(*(p - 1))) {
            insert_str(s, "1", p);
            p++;
        }
    }
}

void remove_mult1(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p)
            && *(p - 1) == '1'
            && !isdigit(*(p - 2))
        ) {
            collapse_str(p - 1, p);
        }
    }
}
