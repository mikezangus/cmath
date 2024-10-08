#include <ctype.h>

void parse_operand(char* dst, const char* start, const char* end)
{
    for (const char* p = start; p <= end; p++) {
        if (isdigit(*p) || *p == '-') {
            *dst++ = *p;
        }
    }
}
