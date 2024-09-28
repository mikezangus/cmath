#include <stdbool.h>
#include "utils/utils.h"
#include "workflows/arithmetic/arithmetic.h"
#include "workflows/algebraic/algebraic.h"

#include <stdio.h>

void enter_workflow(char* s)
{
    if (!find_var(s)) {
        process_arithmetic(s);
    } else {
        printf("alg\n");
        process_algebraic(s);
    }
}
