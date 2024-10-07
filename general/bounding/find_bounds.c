#include <stdbool.h>
#include <stdio.h>
#include "bounding.h"
#include "../../main.h"

bool find_bounds(char* s, Bounds* b)
{
    init_bounds(b);
    if (!find_bounds_by_parens(s, b) &&
        !find_bounds_by_highest_op(s, b)
    ) {
        return false;
    }
    printf(
        "\nBounds: %c%c ... %c%c\n",
        *b->l, *(b->l + 1), *(b->r - 1), *(b->r)
    );
    return true;
}
