#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "../arithmetic.h"
#include "../../../general/general.h"
#include "../../../utils/utils.h"

static DivStatus extract_oprtn(const char* src,
                               const char* oprtr, const char* prev_oprtr,
                               char** l_bound, char** r_bound,
                               OprtnAr* o)
{
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    char* l = extract_num(op1, oprtr - 1, src, -1);
    char* r = extract_num(op2, oprtr + 1, src, 1);
    if (!*op1 || !*op2) {
        return FAIL;
    }
    if (is_oprtn_operable(str_to_d(op1), NAN, *oprtr, str_to_d(op2), NAN)) {
        parse_oprtn(o->n1s, &o->oprtr, o->n2s, op1, *oprtr, op2);
        *l_bound = l;
        *r_bound = r;
        return PARSED_TO_NEW;
    }
    if (*oprtr != '/') {
        return FAIL;
    }
    parse_oprtn(o->n2s, NULL, o->d2s, op1, '\0', op2);
    o->oprtr = *prev_oprtr;
    *l_bound = (l < *l_bound) ? l : *l_bound;
    *r_bound = (*r_bound < r) ? r : *r_bound;
    return (oprtr < prev_oprtr) ? PARSED_L_TO_PREV : PARSED_R_TO_PREV;  
}

static DivStatus extract_oprtn_l(const char* start, const char* src,
                                 const char* prev_oprtr,
                                 char** l_bound, char** r_bound,
                                 OprtnAr* o)
{
    const char* oprtr = find_adj_oprtr(src, *l_bound, NULL);
    if (!oprtr) {
        return FAIL;
    }
    return extract_oprtn(src, oprtr, prev_oprtr, l_bound, r_bound, o);
}

static DivStatus extract_oprtn_r(const char* start, const char* prev_oprtr,
                                 char** l_bound, char** r_bound,
                                 OprtnAr* o)
{
    const char* oprtr = walk_num_fwd(start) + 1;
    if (!oprtr) {
        return FAIL;
    }
    return extract_oprtn(start, oprtr, prev_oprtr, l_bound, r_bound, o);
}

static DivStatus extract_l(const char* src, const char* oprtr,
                           char** l_bound, char** r_bound,
                           OprtnAr* o)
{
    if (isdigit(*(oprtr - 1))
        || ((*(oprtr - 1) == '-') && (oprtr - 2) && isdigit(*oprtr - 2))) {
        *l_bound = extract_num(o->n1s, oprtr - 1, src, -1);
        (*r_bound)++;
        o->oprtr = *oprtr;
        return PARSED_L_TO_PREV;
    }
    return extract_oprtn_l((is_paren(*(oprtr - 1)) && oprtr - 2 > src)
                               ? oprtr - 2
                               : oprtr - 1,
                           src, oprtr, l_bound, r_bound, o);
}

static DivStatus extract_r(const char* src, const char* oprtr,
                           char** l_bound, char** r_bound,
                           OprtnAr* o)
{
    if (*(o->d1s) && *oprtr == '^') {
        return FAIL;
    }
    if (isdigit(*(oprtr + 1)) || *(oprtr + 1) == '-' && isdigit(*(oprtr + 2))) {
        *r_bound = extract_num(o->n2s, oprtr + 1, src, 1);
        (*l_bound > src) ? (*l_bound)-- : *l_bound;
        o->oprtr = *oprtr;
        return PARSED_R_TO_PREV;
    }
    return extract_oprtn_r(oprtr + 2, oprtr, l_bound, r_bound, o);
}

static DivStatus extract(const char* src,
                         char** l_bound, char** r_bound,
                         OprtnAr* o)
{
    const char* oprtr = find_adj_oprtr(src, *l_bound, *r_bound);
    if (!oprtr) {
        return FAIL;
    }
    if (oprtr < *l_bound) {
        return extract_l(src, oprtr, l_bound, r_bound, o);
    } else if (*r_bound < oprtr) {
        return extract_r(src, oprtr, l_bound, r_bound, o);
    }
    return FAIL;
}

bool parse_inoperable_division(const char* src,
                               const char* op1, const char* op2,
                               char** l_bound, char** r_bound,
                               OprtnAr* o)
{
    printf("\nParsing inoperable division:\n"
           "  Str: %s\n"
           "  Bounds: %.4s ... %.4s\n"
           "  Parsed: %s / %s\n",
           src, *l_bound, *r_bound - 3, op1, op2);
    switch (extract(src, l_bound, r_bound, o)) {
        case PARSED_L_TO_PREV:
            parse_oprtn(o->n2s, NULL, o->d2s, op1, '\0', op2);
            return true;
        case PARSED_R_TO_PREV:
            parse_oprtn(o->n1s, NULL, o->d1s, op1, '\0', op2);
            return true;
        case PARSED_TO_NEW:
            return true;
        case FAIL:
            break;
    }
    return false;
}
