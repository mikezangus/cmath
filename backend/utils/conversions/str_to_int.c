#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

long long str_to_int(const char* src)
{
    long long result = 0;
    bool neg = false;
    if (*src == '-') {
        neg = true;
        src++;
    }
    for (const char* p = src; *p; p++) {
        if (!isdigit(*p)) {
            if (*p == '.') {
                return LLONG_MIN;
            }
            fprintf(stderr,
                    "\n%s\nError: non-digit in input string:\n" 
                    "  Char: %c\n"
                    "  Str:  %s\n",
                    __FILE__, *p, src);
            return LLONG_MIN;
        }
        result = result * 10 + (*p - '0');
    }
    return neg ? -result : result;
}
