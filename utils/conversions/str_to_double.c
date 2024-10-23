#include <stdbool.h>

double str_to_double(const char* s)
{
    if (*s == '\0') {
        return 1.0;
    }
    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;
    bool negative = false;
    bool fractional = false;
    if (*s == '-') {
        negative = true;
        s++;
    }
    for (const char* p = s; *p; p++) {
        if (*p == '.') {
            fractional = true;
            continue;
        }
        digit = *p - '0';
        if  (!fractional) {
            result = result * 10 + digit;
        } else {
            result += digit / divisor;
            divisor *= 10;
        }
    }
    return negative ? -result : result;
}
