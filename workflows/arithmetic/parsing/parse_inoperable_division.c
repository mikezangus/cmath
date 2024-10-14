#include <ctype.h>
#include <stdio.h>
#include "parsing.h"
#include "../arithmetic.h"
#include "../../../general/general.h"
#include "../../../utils/utils.h"

static DivStatus extract_oprtn(char* min, char* oprtr, char* prev_oprtr,
                               EqAr* eq, Bounds* b)
{
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    char* l_bound = extract_num_bwd(op1, oprtr - 1, min);
    char* r_bound = extract_num_fwd(op2, oprtr + 1);
    if (is_operable(convert_str_to_int(op1), *oprtr, convert_str_to_int(op2))) {
        parse_oprtn(eq->op1_num_s, &eq->oprtr, eq->op2_num_s, op1, *oprtr, op2);
        b->l = l_bound;
        b->r = r_bound;
        return PARSED_TO_NEW;
    }
    if (*oprtr != '/') {
        return FAIL;
    }
    parse_oprtn(eq->op2_num_s, NULL, eq->op2_den_s, op1, '\0', op2);
    eq->oprtr = *prev_oprtr;
    b->l = l_bound < b->l ? l_bound : b->l;
    b->r = b->r < r_bound ? r_bound : b->r;
    return PARSED_TO_PREV;  
}

static DivStatus extract_oprtn_l(char* s, char* start, char* prev_oprtr,
                                 EqAr* eq, Bounds* b)
{
    char* oprtr = find_nearest_oprtr(s, b->l, NULL);
    if (!oprtr || !is_paren_depth_same(oprtr, start)) {
        return FAIL;
    }
    return extract_oprtn(s, oprtr, prev_oprtr, eq, b);
}

static DivStatus extract_oprtn_r(char* start, char* prev_oprtr,
                                 EqAr* eq, Bounds* b)
{
    char* oprtr = find_nearest_oprtr(NULL, NULL, start);
    if (!oprtr || !is_paren_depth_same(start, oprtr)) {
        return FAIL;
    }
    return extract_oprtn(start, oprtr, prev_oprtr, eq, b);
}

static DivStatus extract_l(char* s, char* oprtr, EqAr* eq, Bounds* b)
{
    if (isdigit(*(oprtr - 1))) {
        b->l = extract_num_bwd(eq->op2_num_s, oprtr - 1, s);
        b->r++;
        eq->oprtr = *oprtr;
        return PARSED_TO_PREV;
    }
    return extract_oprtn_l(s, oprtr - 2, oprtr, eq, b);
}

static DivStatus extract_r(char* oprtr, EqAr* eq, Bounds* b)
{
    if (isdigit(*(oprtr + 1))) {
        b->r = extract_num_fwd(eq->op2_num_s, oprtr + 1);
        b->l--;
        eq->oprtr = *oprtr;
        return PARSED_TO_PREV;
    }
    return extract_oprtn_r(oprtr + 2, oprtr, eq, b);
}

static DivStatus extract(char* s, EqAr* eq, Bounds* b)
{
    char* oprtr = find_nearest_oprtr(s, b->l - 2, b->r + 2);
    if (!oprtr) {
        return FAIL;
    } else if (oprtr < b->l) {
        return extract_l(s, oprtr, eq, b);
    } else if (b->r < oprtr) {
        return extract_r(oprtr, eq, b);
    } else {
        return FAIL;
    }
}

bool parse_inoperable_division(char* s, char* op1, char* op2,
                               EqAr* eq, Bounds* b)
{
    switch (extract(s, eq, b)) {
        case FAIL:
            parse_arithmetic(s, b->r, eq, b);
            return true;
        case PARSED_TO_PREV:
            parse_oprtn(eq->op1_num_s, NULL, eq->op1_den_s, op1, '\0', op2);
            return true;
        case PARSED_TO_NEW:
            return true;
    }
    return false;
}