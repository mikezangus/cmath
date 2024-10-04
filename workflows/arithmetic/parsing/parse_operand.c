#include <ctype.h>

void parse_operand(const char* l_bound, const char* r_bound, char* dst)
{
    for (const char* p = l_bound; p <= r_bound; p++) {
        if (isdigit(*p) || *p == '-') {
            *dst++ = *p;
        }
    }
}
