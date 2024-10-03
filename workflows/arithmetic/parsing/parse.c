#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "parsing.h"
#include "../arithmetic.h"
#include "../../../general/general.h"
#include "../../../general/bounding/bounding.h"
#include "../../../utils/utils.h"


static void parse_operation(char** start, char** end, struct EqAr* eq)
{
    char* oprtr = find_oprtr((*start) + 1, *end);
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
    if (!find_bounds(s, l_bound, r_bound)) {
        return;
    }
    parse_operation(l_bound, r_bound, eq);
    printf(
        "\nParsed:\n"
        "  Op1 num: %s\n"
        "  Op1 den: %s\n"
        "  Oprtr:   %c\n"
        "  Op2 num: %s\n"
        "  Op2 den: %s\n\n",
        eq->op1_num_s, eq->op1_den_s, eq->oprtr, eq->op2_num_s, eq->op2_den_s
    );
}
