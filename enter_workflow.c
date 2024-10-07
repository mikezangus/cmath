#include <stdbool.h>
#include "main.h"
#include "utils/utils.h"
#include "workflows/algebraic/algebraic.h"
#include "workflows/arithmetic/arithmetic.h"

Bounds b;

void enter_workflow(char* s)
{
    if (!find_var(s)) {
        process_arithmetic(s, &b);
    } else {
        process_algebraic(s);
    }
}
