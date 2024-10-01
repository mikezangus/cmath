#include <ctype.h>

void parse_operand(char* start, char* end, char* dst)
{
    for (char* p = start; p <= end; p++) {
        if (isdigit(*p)) {
            *dst++ = *p;
        }
    }
}
