#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../arithmetic.h"
#include "../../../main.h"
#include "../../../bounding/bounding.h"
#include "../../../utils/utils.h"

bool parse_arithmetic(const char* s, const char* start, bool bounds_found,
                      OprtnAr* o, Bounds* b)
{
    if (!bounds_found && !find_bounds(start, &b->l, &b->r)) {
        return false;
    }
    const char* oprtr = find_oprtr(b->l, b->r);
    if (!oprtr) {
        return false;
    }
    char op1[STR_MAXLEN] = {0};
    char op2[STR_MAXLEN] = {0};
    extract_num_bwd(op1, oprtr - 1, s);
    extract_num_fwd(op2, oprtr + 1);
    if (!*op1 || !*op2) {
        fprintf(stderr,
                "\n%s\nError: Failed to extract operands. Exiting\n",
                __FILE__);
        return false;
    }
    if (oprtn_is_operable(str_to_d(op1), *oprtr, str_to_d(op2))) {
        parse_oprtn(o->n1s, &o->oprtr, o->n2s, op1, *oprtr, op2);
        return true;
    }
    if (*oprtr != '/'
        || !parse_inoperable_division(s, op1, op2, o, b)
        || !*o->n1s
        || !o->oprtr
        || !*o->n2s) {
        return false;
    }
    printf("\nParsed fraction operation:\n"
           "  Op1 num: %s\n"
           "  Op1 den: %s\n"
           "  Oprtr:   %c\n"
           "  Op2 num: %s\n"
           "  Op2 den: %s\n\n",
           o->n1s, o->d1s, o->oprtr, o->n2s, o->d2s);
    return true;
}
