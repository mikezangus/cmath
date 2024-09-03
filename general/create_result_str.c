#include <stdio.h>

void create_result_str(char *n, char *x_n, char *d, char *r)
{
    int j = 0;
    printf("Numerator string: %s\n", n);
    printf("Denominator string: %s\n", d);
    printf("1. Result: %s\n", r);
    for (int i = 0; n[i] != '\0'; i++) {
        r[j++] = n[i];
    }
    printf("2. Result: %s\n", r);
    for (int i = 0; x_n[i] != '\0'; i++) {
        if (i == 0) {
            r[j++] = 'x';
            r[j++] = '^';
        }
        r[j++] = x_n[i];
    }
    printf("3. Result: %s\n", r);
    if (*d != '\0') {
        r[j++] = '/';
    }
    printf("4. Result: %s\n", r);
    for (int i = 0; d[i] != '\0'; i++) {
        r[j++] = d[i];
    }
    printf("5. Result: %s\n", r);
}
