#include <stdio.h>
#include <string.h>
#include "../main.h"

void convert_d_to_str(double d, char *s)
{
    memset(s, '\0', MAXLEN);
    snprintf(s, sizeof(s), "%.17g", d);
}
