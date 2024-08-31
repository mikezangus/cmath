void convert_str_to_d(char *s, double *d)
{
    int sw_neg = 0;
    int sw_frac = 0;

    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;

    if (*s == '-') {
        sw_neg = 1;
        s++;
    }
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '.') {
            sw_frac = 1;
            continue;
        }
        digit = *p - '0';
        if  (!sw_frac) {
            result = result * 10 + digit;
        } else {
            result += digit / divisor;
            divisor *= 10;
        }
    }
    *d = sw_neg ? -result : result;
}
