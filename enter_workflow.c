#include <stdbool.h>
#include "general/general.h"
#include "workflows/arithmetic/arithmetic.h"
#include "workflows/algebraic/algebraic.h"

bool is_arithmetic(char* s)
{
    for (char* p = s; *p; p++) {
        if (char_is_var(*p)) {
            return false;
        }
    }
    return true;
}

bool is_algebraic(char* s)
{
    for (char* p = s; *p; p++) {
        if (char_is_var(*p)) {
            return true;
        }
    }
    return false;
}

void enter_workflow(char* s)
{
    if (is_arithmetic(s)) {
        process_arithmetic(s);
    } else if (is_algebraic(s)) {
        process_algebraic(s);
    }
}
