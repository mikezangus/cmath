#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "parsing.h"
#include "../arithmetic.h"
#include "../../../main.h"
#include "../../../general/general.h"
#include "../../../general/bounding/bounding.h"
#include "../../../utils/utils.h"

static bool is_paren_depth_same(char* p1, char* p2)
{
    short scale = 0;
    for (char* p = p1; p <= p2; p++) {
        balance_chars(*p, &scale, '(', ')');
    }
    return scale == 0;
}

static bool parse_next_digit(char* op1, char* oprtr, char* op2, char** end, EqAr* eq)
{
    if (!isdigit(*(oprtr + 1))) {
        return false;
    }
    strcpy(eq->op1_num_s, op1);
    strcpy(eq->op1_den_s, op2);
    eq->oprtr = *oprtr;
    memset(eq->op2_num_s, '\0', STR_MAXLEN);
    char* p;
    char* dst = eq->op2_num_s;
    for (p = oprtr + 1; *p && isdigit(*p); p++) {
        *dst++ = *p;
    }
    *dst = '\0';
    *end = p -1;
    return true;
}

static bool parse_next_operation(char** start, char** end, char* p_op1, char* p_oprtr, char* p_op2, EqAr* eq)
{
    char* l_bound = NULL;
    char* r_bound = NULL;
    if (!find_bounds(*end, &l_bound, &r_bound)) {
        return false;
    }
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    char* oprtr = find_oprtr(l_bound, r_bound);
    parse_operand(l_bound, oprtr - 1, op1);
    parse_operand(oprtr + 1, r_bound, op2);
    if (!is_paren_depth_same(*end, l_bound) &&
        is_operable(convert_str_to_int(op1), *oprtr, convert_str_to_int(op2))) {
        *start = l_bound;
        *end = r_bound;
        strcpy(eq->op1_num_s, op1);
        eq->oprtr = *oprtr;
        strcpy(eq->op2_num_s, op2);
        return true;
    }
    if (is_paren_depth_same(*end, l_bound) &&
        !is_operable(convert_str_to_int(op1), *oprtr, convert_str_to_int(op2))) {
        *end = r_bound;
        strcpy(eq->op1_num_s, p_op1);
        strcpy(eq->op1_den_s, p_op2);
        eq->oprtr = *p_oprtr;
        strcpy(eq->op2_num_s, op1);
        strcpy(eq->op2_den_s, op2);
        return true;
    }
    return false;
}

// static bool go_right(char* l_bound, char** r_bound, struct Eq)

bool parse_division(char** start, char* div_op, char** end, EqAr* eq)
{
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    parse_operand(*start, div_op - 1, op1);
    parse_operand(div_op + 1, *end, op2);
    if (is_operable(convert_str_to_int(op1), *div_op, convert_str_to_int(op2))) {
        strcpy(eq->op1_num_s, op1);
        eq->oprtr = *div_op;
        strcpy(eq->op2_num_s, op2);
        return true;
    }
    char* oprtr = find_oprtr(*end, NULL);
    if (parse_next_digit(op1, oprtr, op2, end, eq) ||
        parse_next_operation(start, end, op1, oprtr, op2, eq)) {
        return true;
    }
    return false;
}
