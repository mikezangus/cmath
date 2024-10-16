#include <stdio.h>

char* find_char(char c, char* start, char* end)
{
    if (start > end) {
        return NULL;
    }
    for (char* p = start; *p && p <= end; p++) {
        if (*p == c) {
            return p;
        }
    }
    return NULL;
}
