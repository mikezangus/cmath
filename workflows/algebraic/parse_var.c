#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "../../general/general.h"
#include "../../utils/utils.h"

static void parse_exp(char *p_var, double *out_exp)
{
    printf("Parsing exponent:\n  p_var: %s\n  out_exp: %.1f\n", p_var, *out_exp);
    int i = 0;
    char buff[100] = {0};
    for (char *p = p_var; isdigit(*p); p++) {
        printf("buff[%d] <- %c\n", i, *p);
        buff[i++] = *p;
    }
    buff[i] = '\0';
    printf("End buff: %s\n", buff);
    convert_str_to_d(buff, out_exp);
}

void parse_var(char *in, char *out_var, double *out_exp)
{
    printf("Parsing var:\n  in: %s\n  out_var: %s\n  out_exp: %.1f\n", in, out_var, *out_exp);
    char *p_var = strchr(in, 'x');
    if (p_var == NULL) {
        return;
    }
    *out_var = *p_var;
    if (*(p_var + 1) == '^') {
        parse_exp(p_var + 2, out_exp);
    }
}
