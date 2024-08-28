#include "../main.h"

void convert_str_to_d(char *s, double *d)
{
    int sw_fractional = 0;
    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '.') {
            sw_fractional = 1;
            continue;
        }
        digit = *p - '0';
        if  (!sw_fractional) {
            result = result * 10 + digit;
        } else {
            result += digit / divisor;
            divisor *= 10;
        }
    }
    *d = result;
}
