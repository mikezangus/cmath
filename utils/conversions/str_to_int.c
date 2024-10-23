#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

long long str_to_int(const char* s)
{
    long long result = 0;
    bool negative = false;
    if (*s == '-') {
        negative = true;
        s++;
    }
    for (const char* p = s; *p; p++) {
        if (!isdigit(*p)) {
            if (*p == '.') {
                return 0;
            }
            fprintf(stderr,
                    "%s | Error: non-digit in input string:\n" 
                    "Char: %c\n"
                    "Str: %s\n",
                    __FILE__, *p, s);
            return 0;
        }
        result = result * 10 + (*p - '0');
    }
    return negative ? -result : result;
}
