#include <stdio.h>

void print_bounded_str(const char* start, const char* end)
{
    for (const char* p = start; *p && p <= end; p++) {
        printf("%p - %c\n", p, *p);
    }
}
