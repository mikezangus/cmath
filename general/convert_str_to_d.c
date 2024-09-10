#include <stdbool.h>

void convert_str_to_d(char* s, double* d)
{
    bool negative_sign = false;
    bool fractional = false;

    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;

    if (*s == '-') {
        negative_sign = true;
        s++;
    }
    for (char* p = s; *p; p++) {
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
    *d = negative_sign ? -result : result;
}
