#include <stdio.h>
#include <string.h>
#include "main.h"

void convert_d_to_str(void)
{
    memset(eq.results, '\0', MAXLEN);
    snprintf(eq.results, sizeof(eq.results), "%.17g", eq.resultd);
}
