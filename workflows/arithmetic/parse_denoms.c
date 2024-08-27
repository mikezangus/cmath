
#include "../../main.h"
#include "../../general/general.h"
#include "../../utils/utils.h"
#include <ctype.h>
#include "stdio.h"
#include <string.h>

struct Equation2 {
    char op1sn[MAXLEN];
    char op1sd[MAXLEN];
    char oprtr;
    char op2sn[MAXLEN];
    char op2sd[MAXLEN];
    double op1dn;
    double op1dd;
    double op2dn;
    double op2dd;
    
} eq2;

static int find_i_oprtr(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_oprtr(input[i]) && input[i] != '/') {
            return i;
        }
    }
    return -1;
}

int parse_op1s(int i_oprtr)
{
    int i_start = -1;
    /* find divide */
    int i_div = -1;
    for (int i = i_oprtr; i >= 0; i--) {
        if (input[i] == '/') {
            i_div =i;
        }
    }

    int j;
    /* populate numerator */
    j = 0;
    for (int i = 0; i < i_div && isdigit(input[i]); i++) {
        if (i_start < 0) {
            i_start = i;
        }
        eq2.op1sn[j++] = input[i];
    }

    /* populate denominator */
    j = 0;
    for (int i = i_div + 1; i <= i_oprtr && isdigit(input[i]); i++) {
        eq2.op1sd[j++] = input[i];
    }
    return i_start;
}

int parse_op2s(int i_oprtr)
{
    /* find divide */
    int i;
    int i_div = -1;
    int j;
    
    for (int i = i_oprtr + 1; input[i] != '\0'; i++) {
        if (input[i] == '/') {
            i_div = i;
            break;
        }
    }
    /* populate numerator */
    j = 0;
    for (i = i_oprtr + 1; isdigit(input[i]) && i < i_div && input[i] != '\0'; i++) {
        eq2.op2sn[j++] = input[i];
    }

    /* populate denominator */
    j = 0;
    for (i = i_div + 1; isdigit(input[i]) && input[i] != '\0'; i++) {
        eq2.op2sd[j++] = input[i];
    }
    return i - 1;
}

static double convert(char *s)
{
    int fractional = 0;
    int digit = 0;
    double result = 0.0;
    double divisor = 10.0;

    for (char *p = s; *p != '\0'; p++) {
        if (*p == '.') {
            fractional = 1;
            continue;
        }
        digit = *p - '0';
        if  (!fractional) {
            result = result * 10 + digit;
        } else {
            result += digit / divisor;
            divisor *= 10;
        }
    }
    return result;
}


void parse_denoms(void)
{
    print_str("\nParsing denoms", input);
    memset(eq2.op1sn, '\0', MAXLEN);
    memset(eq2.op1sd, '\0', MAXLEN);
    memset(eq2.op2sn, '\0', MAXLEN);
    memset(eq2.op2sd, '\0', MAXLEN);
    int i_oprtr = find_i_oprtr();
    printf("Operator found at input[%d]='%c'\n", i_oprtr, input[i_oprtr]);
    eq2.oprtr = input[i_oprtr];
    int l_bound = parse_op1s(i_oprtr);
    int r_bound = parse_op2s(i_oprtr);
    printf("Bounds:\nL: %d | R: %d\n", l_bound, r_bound);
    eq2.op1dn = convert(eq2.op1sn);
    eq2.op1dd = convert(eq2.op1sd);
    eq2.op2dn = convert(eq2.op2sn);
    eq2.op2dd = convert(eq2.op2sd);
    printf("Op 1: %s/%s\n", eq2.op1sn, eq2.op1sd);
    printf("Op 2: %s/%s\n", eq2.op2sn, eq2.op2sd);

}