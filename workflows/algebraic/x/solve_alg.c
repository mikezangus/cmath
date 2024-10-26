#include <stdbool.h>
#include <stdio.h>
#include "algebraic.h"
#include "parsing/parsing.h"
#include "../../main.h"
#include "../../bounding/bounding.h"

bool solve_alg(char* s, EqAlg* eq, Bounds* b)
{
    if (!find_bounds(s, &b->l, &b->r)) {
        return false;
    }
    return true;

}
