#include <ctype.h>
#include <stdio.h>
#include "../arithmetic.h"
#include "../../../general/general.h"
#include "../../../utils/utils.h"

static DivStatus extract_oprtn(const char* min,
                               const char* oprtr, const char* prev_oprtr,
                               OprtnAr* o, Bounds* b)
{
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    char* l_bound = extract_num_bwd(op1, oprtr - 1, min);
    char* r_bound = extract_num_fwd(op2, oprtr + 1);
    if (!*op1 || !*op2) {
        return FAIL;
    }
    if (oprtn_is_operable(str_to_d(op1), *oprtr, str_to_d(op2))) {
        parse_oprtn(o->n1s, &o->oprtr, o->n2s, op1, *oprtr, op2);
        b->l = l_bound;
        b->r = r_bound;
        return PARSED_TO_NEW;
    }
    if (*oprtr != '/') {
        return FAIL;
    }
    parse_oprtn(o->n2s, NULL, o->d2s, op1, '\0', op2);
    o->oprtr = *prev_oprtr;
    b->l = (l_bound < b->l) ? l_bound : b->l;
    b->r = (b->r < r_bound) ? r_bound : b->r;
    return (oprtr < prev_oprtr) ? PARSED_L_TO_PREV : PARSED_R_TO_PREV;  
}

static DivStatus extract_oprtn_l(const char* start, const char* s,
                                 const char* prev_oprtr,
                                 OprtnAr* o, Bounds* b)
{
    const char* oprtr = find_adj_oprtr(s, b->l, NULL);
    if (!oprtr) {
        return FAIL;
    }
    return extract_oprtn(s, oprtr, prev_oprtr, o, b);
}

static DivStatus extract_oprtn_r(const char* start,
                                 const char* prev_oprtr,
                                 OprtnAr* o, Bounds* b)
{
    const char* oprtr = find_adj_oprtr(NULL, NULL, start + 1);
    if (!oprtr) {
        return FAIL;
    }
    return extract_oprtn(start, oprtr, prev_oprtr, o, b);
}

static DivStatus extract_l(const char* s, const char* oprtr,
                           OprtnAr* o, Bounds* b)
{
    if (isdigit(*(oprtr - 1))
        || ((*(oprtr - 1) == '-') && (oprtr - 2) && isdigit(*oprtr - 2))) {
        b->l = extract_num_bwd(o->n1s, oprtr - 1, s);
        b->r++;
        o->oprtr = *oprtr;
        return PARSED_L_TO_PREV;
    }
    return extract_oprtn_l((is_paren(*(oprtr - 1)) && oprtr - 2 > s)
                               ? oprtr - 2
                               : oprtr - 1,
                           s, oprtr, o, b);
}

static DivStatus extract_r(const char* s, const char* oprtr,
                           OprtnAr* o, Bounds* b)
{
    if (isdigit(*(oprtr + 1))
        || (*(oprtr + 1) == '-' && isdigit(*(oprtr + 2)))) {
        b->r = extract_num_fwd(o->n2s, oprtr + 1);
        (b->l > s) ? b->l-- : b->l;
        o->oprtr = *oprtr;
        return PARSED_R_TO_PREV;
    }
    return extract_oprtn_r(is_paren(*(oprtr + 1)) ? oprtr + 2 : oprtr + 1,
                           oprtr, o, b);
}

static DivStatus extract(const char* s, OprtnAr* o, Bounds* b)
{
    const char* oprtr = find_adj_oprtr(s, b->l - 1, b->r + 1);
    if (!oprtr) {
        return FAIL;
    } else if (oprtr < b->l) {
        return extract_l(s, oprtr, o, b);
    } else if (b->r < oprtr) {
        return extract_r(s, oprtr, o, b);
    } else {
        return FAIL;
    }
}

bool parse_inoperable_division(const char* s, const char* op1, const char* op2,
                               OprtnAr* o, Bounds* b)
{
    switch (extract(s, o, b)) {
        case FAIL:
            return parse_arithmetic(s, b->r + 1, false, o, b);
        case PARSED_L_TO_PREV:
            parse_oprtn(o->n2s, NULL, o->d2s, op1, '\0', op2);
            return true;
        case PARSED_R_TO_PREV:
            parse_oprtn(o->n1s, NULL, o->d1s, op1, '\0', op2);
            return true;
        case PARSED_TO_NEW:
            return true;
    }
    return false;
}
