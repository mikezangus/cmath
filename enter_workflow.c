#include <stdbool.h>
#include "utils/utils.h"
#include "workflows/arithmetic/arithmetic.h"
#include "workflows/algebraic/algebraic.h"

#include <stdio.h>

bool is_arithmetic(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p)) {
            return false;
        }
    }
    return true;
}

bool is_algebraic(char* s)
{
    for (char* p = s; *p; p++) {
        if (is_var(*p)) {
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
        printf("alg\n");
        process_algebraic(s);
    }
}
