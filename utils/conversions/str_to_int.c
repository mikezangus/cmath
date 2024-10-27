#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

long long str_to_int(const char* s)
{
    long long result = 0;
    bool neg = false;
    if (*s == '-') {
        neg = true;
        s++;
    }
    for (const char* p = s; *p; p++) {
        if (!isdigit(*p)) {
            if (*p == '.') {
                return LLONG_MIN;
            }
            fprintf(stderr,
                    "\n%s\nError: non-digit in input string:\n" 
                    "  Char: %c\n"
                    "  Str:  %s\n",
                    __FILE__, *p, s);
            return LLONG_MIN;
        }
        result = result * 10 + (*p - '0');
    }
    return neg ? -result : result;
}
