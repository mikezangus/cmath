#include <stdio.h>
#include <string.h>
#include "../../main.h"

void double_to_str(double d, char* s)
{
    memset(s, '\0', NUM_MAXLEN);
    snprintf(s, NUM_MAXLEN, "%.17g", d);
}
