#include <stdio.h>
#include <string.h>
#include "../../main.h"

void d_to_str(char* s, double d)
{
    memset(s, '\0', NUM_MAXLEN);
    snprintf(s, NUM_MAXLEN, "%.17g", d);
}
