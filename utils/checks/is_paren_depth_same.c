#include <stdbool.h>
#include "../utils.h"

bool is_paren_depth_same(char* p1, char* p2)
{
    int scale = 0;
    for (char* p = p1; p <= p2; p++) {
        balance_chars(*p, &scale, '(', ')');
    }
    return scale == 0;
}
