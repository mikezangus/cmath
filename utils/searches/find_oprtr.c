#include <stdio.h>
#include <string.h>
#include "../utils.h"

char* find_oprtr(char* start, char* end)
{
    start = *start == '-' ? start + 1 : start;
    end = end ? end : start + strlen(start);
    for (char* p = start; *p && p <= end; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}
