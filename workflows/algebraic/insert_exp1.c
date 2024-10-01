#include "algebraic.h"
#include "../../utils/utils.h"


void insert_exp1(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p) && *(p + 1) != '^') {
            insert_str(s, "^1", p + 1);
            p+=2;
        }
    }
}
