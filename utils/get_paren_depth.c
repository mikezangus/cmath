#include <string.h>
#include "utils.h"

int get_paren_depth(const char* p1, const char* p2)
{
    int scale = 0;
    const char* end = p2 ? p2 : p1 + strlen(p1);
    for (const char* p = p1; p <= end; p++) {
        balance_chars(*p, &scale, '(', ')');
    }
    return scale;
}
