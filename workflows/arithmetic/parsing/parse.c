#include <stdbool.h>
#include <stdio.h>
#include "parsing.h"
#include "../arithmetic.h"
#include "../../../main.h"
#include "../../../general/general.h"
#include "../../../bounding/bounding.h"

bool parse_arithmetic(char* s, char* start, EqAr* eq, Bounds* b)
{
    if (!find_bounds(start, &b->l, &b->r)) {
        return false;
    }
    char* oprtr = find_oprtr(b->l, b->r);
    if (!oprtr) {
        return false;
    }
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    extract_num_bwd(op1, oprtr - 1, s);
    extract_num_fwd(op2, oprtr + 1);
    if (is_operable(convert_str_to_int(op1), *oprtr, convert_str_to_int(op2))) {
        parse_oprtn(eq->op1_num_s, &eq->oprtr, eq->op2_num_s, op1, *oprtr, op2);
        return true;
    }
    if (*oprtr != '/') {
        return false;
    }
    if (!parse_inoperable_division(s, op1, op2, eq, b)) {
        return false;
    }
    printf(
        "\nParsed:\n"
        "  Op1 num: %s\n"
        "  Op1 den: %s\n"
        "  Oprtr:   %c\n"
        "  Op2 num: %s\n"
        "  Op2 den: %s\n\n",
        eq->op1_num_s, eq->op1_den_s, eq->oprtr, eq->op2_num_s, eq->op2_den_s
    );
    return true;
}
