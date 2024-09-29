#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

long long int convert_str_to_int(char* s)
{
    long long result = 0;
    bool negative = false;
    if (*s == '-') {
        negative = true;
        s++;
    }
    for (char* p = s; *p; p++) {
        if (!isdigit(*p)) {
            fprintf(
                stderr,
                "%s | Error: non-digit in input string:\n  %s\n",
                __FILE__, s
            );
            return 0;
        }
        result = result * 10 + (*p - '0');
    }
    return negative ? -result : result;
}
