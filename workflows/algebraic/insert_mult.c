#include "algebraic.h"
#include "../../utils/utils.h"

void insert_mult(char* s)
{
    for (char* p = s; *p && *(p + 1); p++) {
        if (is_var(*p) && is_var(*(p + 1))) {
            insert_str(s, "*", p + 1);
            p++;
        }
    }
}
