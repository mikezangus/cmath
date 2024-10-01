#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../arithmetic.h"
#include "../bounding/bounding.h"
#include "../../../utils/utils.h"
#include "../../../general/general.h"
#include "parsing.h"


static void parse_operation(char** start, char** end, struct EqAr* eq)
{
    char* oprtr = find_oprtr(*start, *end);
    if (*oprtr == '/') {
        parse_division(start, oprtr, end, eq);
    } else {
        eq->oprtr = *oprtr;
        parse_operand(*start, oprtr - 1, eq->op1_num_s);
        parse_operand(oprtr + 1, *end, eq->op2_num_s);
    }
}

void parse_arithmetic(char* s, struct EqAr* eq, char** l_bound, char** r_bound)
{
    if (!find_bounds_ar(s, l_bound, r_bound)) {
        return;
    }
    parse_operation(l_bound, r_bound, eq);

    printf("\nPARSED:\n");
    printf("  Op1 num: %s\n", eq->op1_num_s);
    printf("  Op1 den: %s\n", eq->op1_den_s);
    printf("  Oprtr:   %c\n", eq->oprtr);
    printf("  Op2 num: %s\n", eq->op2_num_s);
    printf("  Op2 den: %s\n\n", eq->op2_den_s);
}
