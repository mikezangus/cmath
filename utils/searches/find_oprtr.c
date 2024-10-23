#include <stdio.h>
#include <string.h>
#include "../utils.h"

char* find_oprtr(const char* start, const char* end)
{
    const char* s = (*start == '-') ? start + 1 : start;
    const char* e = end ? end : s + strlen(s);
    for (const char* p = s; *p && p <= e; p++) {
        if (is_oprtr(*p)) {
            return (char*)p;
        }
    }
    return NULL;
}
