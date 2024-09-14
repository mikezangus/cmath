#include <stdio.h>

void print_bounded_str(char* start, char* end)
{
    for (char* p = start; *p && p <= end; p++) {
        printf("%p - %c\n", p, *p);
    }
}
