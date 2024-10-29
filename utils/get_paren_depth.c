#include "utils.h"

int get_paren_depth(const char* p1, const char* p2)
{
    int scale = 0;
    for (const char* p = p1; p <= p2; p++) {
        balance_chars(*p, &scale, '(', ')');
    }
    return scale;
}
