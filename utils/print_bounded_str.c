#include <stdio.h>

void print_bounded_str(char* start, char* end)
{
    printf("\nBounded string:\n");
    for (char* p = start; *p && p <= end; p++) {
        printf("%p - %c\n", p, *p);
    }
}