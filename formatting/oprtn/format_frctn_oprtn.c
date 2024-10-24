#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../formatting.h"

bool format_frctn_oprtn(char* n1, char* d1, char* oprtr, char* n2, char* d2)
{
    if (*oprtr != '/') {
        return true;
    }
    if (strcmp(d1, "0") == 0 || strcmp(d2, "0") == 0) {
        fprintf(stderr,
                "\n%s\nError: Zero in denominator. Exiting\n",
                __FILE__);
        return false;
    }
    if (n2 && d2) {
        flip_frctn_divisor(oprtr, n2, d2);
        format_neg_frctn(n2, d2);
    }
    format_neg_frctn(n1, d1);
    return true;
}
