#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "../../general/general.h"
#include "../../utils/utils.h"


static void parse_exp(char *p_var, double *out_exp)
{
    int i;
    char buff[100] = {0};
    for (char *p = p_var + 2; isdigit(*p); p++) {
        buff[i++] = *p;
        *p = '\0';
    }
    buff[i] = '\0';
    convert_str_to_d(buff, out_exp);
}


void parse_var(char *in, char *out_var, double *out_exp)
{
    char *p_var = strchr(in, 'x');
    if (p_var == NULL) {
        return;
    }
    *out_var = *p_var;
    if (*(p_var + 1) == '^') {
        parse_exp(p_var, out_exp);
    } else {
        *out_exp = 1.0;
    }
}
