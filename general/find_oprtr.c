#include <stdio.h>
#include <string.h>
#include "../utils/utils.h"

char* find_oprtr(char* start, char* end)
{
    end = end ? end : start + strlen(start);
    for (char* p = start; *p && p <= end; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}
