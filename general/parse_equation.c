#include <ctype.h>
#include "../utils/utils.h"
#include "../main.h"
#include <stdio.h>

static int find_i_oprtr(char *s, int l_bound, int r_bound, int (*func)(char))
{
    for (int i = l_bound; i <= r_bound; i++) {
        if (func(s[i])) {
            return i;
        }
    }
    return -1; 
}

static int parse_oprtr(char *in, char *out, int l_bound, int r_bound)
{
    int i_op;
    if (l_bound == 0 && *in == '-') {
        l_bound++;
    }
    if (sw.sw_var_exp) {
            if ((i_op = find_i_oprtr(in, l_bound, r_bound, is_prec2_oprtr)) > -1 ||
                (i_op = find_i_oprtr(in, l_bound, r_bound, is_prec3_oprtr)) > -1
            ) {
                *out = in[i_op];
                return i_op;
            }
        return -1;
    }
    if ((i_op = find_i_oprtr(in, l_bound, r_bound, is_prec1_oprtr)) > -1 ||
        (i_op = find_i_oprtr(in, l_bound, r_bound, is_prec2_oprtr)) > -1 ||
        (i_op = find_i_oprtr(in, l_bound, r_bound, is_prec3_oprtr)) > -1
    ) {
        *out = in[i_op];
        return i_op;
    }
    return -1;
}

static void parse_oprnd(char *in, char *out_n, char *out_d, int start, int end)
{
    int j = 0;
    int sw_div = 0;
    for (int i = start; i <= end; i++) {
        if (in[i] == '/') {
            sw_div = 1;
            j = 0;
        } else if (!sw_div) {
            out_n[j++] = in[i];
        } else if (sw_div) {
            out_d[j++] = in[i];
        }
    }
}

void parse_equation(char *in, int l_bound, int r_bound, char *op1_n, char *op1_d, char *oprtr, char *op2_n, char *op2_d)
{
    int i_oprtr = parse_oprtr(in, oprtr, l_bound, r_bound);
    parse_oprnd(in, op1_n, op1_d, l_bound, i_oprtr - 1);
    parse_oprnd(in, op2_n, op2_d, i_oprtr + 1, r_bound);
    printf("\nParsed:\n  Op1:   %s/%s\n  Oprtr: %c\n  Op2:   %s/%s\n", op1_n, op1_d, *oprtr, op2_n, op2_d);
}
