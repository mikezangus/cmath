#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../arithmetic.h"
#include "../../../main.h"
#include "../../../bounding/bounding.h"
#include "../../../utils/utils.h"

bool parse_arithmetic(const char* start, const char* src, 
                      char** l_bound, char** r_bound,
                      OprtnAr* o)
{
    /* 1. Find bounds if not provided */
    if ((!*l_bound || !*r_bound) && !find_bounds(start, l_bound, r_bound)) {
        return false;
    }
    /* 2. Extract operator */
    const char* oprtr = find_oprtr(*l_bound, *r_bound);
    if (!oprtr) {
        return false;
    }

    /* 3. Extract operands */
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    extract_num(op1, *l_bound, src, 1);
    extract_num(op2, oprtr + 1, src, 1);
    if (!*op1 || !*op2) {
        fprintf(stderr, "\n%s\nError | Failed to extract operands\n", __FILE__);
        return false;
    }

    /* 4. Check if operation is operable - if operable, then parse and return */
    if (is_oprtn_operable(str_to_d(op1), NAN, *oprtr, str_to_d(op2), NAN)) {
        parse_oprtn(o->n1s, &o->oprtr, o->n2s, op1, *oprtr, op2);
        return true;
    }

    /* 5. Operation is not operable - attempt to parse inoperable division */
    if (*oprtr != '/'
        || strcmp(o->d1s, "0")
        || strcmp(o->d2s, "0")
        || !parse_inoperable_division(src, op1, op2, l_bound, r_bound, o)
        || !*o->n1s
        || !o->oprtr
        || !*o->n2s) {
        return false;
    }

    printf("\nParsed fractional operation:\n"
           "  Op1 num: %s\n"
           "  Op1 den: %s\n"
           "  Oprtr:   %c\n"
           "  Op2 num: %s\n"
           "  Op2 den: %s\n\n",
           o->n1s, o->d1s, o->oprtr, o->n2s, o->d2s);
    return true;
}
