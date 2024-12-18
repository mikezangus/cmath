#include <stdio.h>
#include <string.h>
#include "../utils.h"

char* find_var(const char* start, const char* end)
{
    const char* e = end ? end : start + strlen(start);
    for (const char* p = start; *p && p <= e; p++) {
        if (is_var(*p)) {
            return (char*)p;
        }
    }
    return NULL;
}
