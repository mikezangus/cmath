#include <stdio.h>

char* find_char(char c, const char* start, const char* end)
{
    if (start > end) {
        return NULL;
    }
    for (const char* p = start; *p && p <= end; p++) {
        if (*p == c) {
            return (char*)p;
        }
    }
    return NULL;
}
