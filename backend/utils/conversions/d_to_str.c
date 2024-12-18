#include <stdio.h>
#include <string.h>
#include "../../main.h"

void d_to_str(char* dst, double src)
{
    memset(dst, '\0', NUM_MAXLEN);
    snprintf(dst, NUM_MAXLEN, "%.17g", src);
}
