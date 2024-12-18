#include <stdio.h>
#include <string.h>

char* find_char(char c, const char* start, const char* end)
{
    if (!end) {
        end = start + strlen(start);
    }
    if (start > end) {
        return NULL;
    }
    for (const char* p = start; p <= end; p++) {
        if (*p == c) {
            return (char*)p;
        }
    }
    return NULL;
}
