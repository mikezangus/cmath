#include <math.h>
#include <stdio.h>
#include <string.h>
#include "arithmetic.h"
#include "../../main.h"
#include "../../bounding/bounding.h"
#include "../../formatting/formatting.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

OprtnAr o;

static void init_oprtn(OprtnAr* o)
{
    memset(o->n1s, '\0', STR_MAXLEN);
    memset(o->d1s, '\0', STR_MAXLEN);
    o->oprtr = '\0';
    memset(o->n2s, '\0', STR_MAXLEN);
    memset(o->d2s, '\0', STR_MAXLEN);
    o->n1d = o->d1d = o->n2d = o->d2d = o->rnd = o->rdd = 0.0;
    memset(o->rns, '\0', STR_MAXLEN);
    memset(o->rds, '\0', STR_MAXLEN); 
    memset(o->r, '\0', STR_MAXLEN); 
}

bool solve_arithmetic(char* start, char* src, char** l_bound, char** r_bound)
{
    if (!start || !src || !l_bound || !r_bound) {
        return false;
    }
    printf("\n\n\nSolving arithmetic:\n%s\n", src);
    init_oprtn(&o);

    /* 1. Find bounds */
    if ((!*l_bound || !*r_bound) && !find_bounds(start, l_bound, r_bound)) {
        printf("\nFailed to find bounds\n");
        return false;
    }
    printf("\nBounds:\n%.2s ... %.2s\n", *l_bound, *r_bound - 1);

    /* 2. Parse operation */
    if (!parse_arithmetic(start, src, l_bound, r_bound, &o)) {
        if (strcmp(o.d1s, "0") || strcmp(o.d2s, "0")) {
            return false;
        }
        start = *r_bound + 1;
        *l_bound = *r_bound = NULL;
        return solve_arithmetic(start, src, l_bound, r_bound);
    }
    printf("\nParsed:\n%s/%s %c %s/%s\n", o.n1s, o.d1s, o.oprtr, o.n2s, o.d2s);

    /* 3. Verify and format parsed operation */
    if (*o.d1s == '0' || *o.d2s == '0') {
        fprintf(stderr, "\n%s\nError | Parsed 0 in denominator\n", __FILE__);
        return false;
    }
    if (o.oprtr == '/' && *o.d2s) {
        flip_frctn_divisor(&o.oprtr, o.n2s, o.d2s);
    }

    /* 4. Convert parsed operand strings to doubles */
    o.n1d = str_to_d(o.n1s);
    o.d1d = str_to_d(o.d1s);
    o.n2d = str_to_d(o.n2s);
    o.d2d = str_to_d(o.d2s);
    printf("\nDoubles:\n%.2f/%.2f %c %.2f/%.2f\n",
           o.n1d, o.d1d, o.oprtr, o.n2d, o.d2d);
    
    /* 5. Verify operation is operable */
    if (!is_oprtn_operable(o.n1d, o.d1d, o.oprtr, o.n2d, o.d2d)) {
        printf("\nNot operable. Searching for new bounds\n");
        start = *r_bound + 1;
        *l_bound = *r_bound = NULL;
        return solve_arithmetic(start, src, l_bound, r_bound);
    }

    /* 6. Calculate operation */
    if (isnan(o.rdd = calculate_den(&o.n1d, &o.d1d, o.oprtr, &o.n2d, &o.d2d))
        || isnan(o.rnd = calculate_oprtn(o.n1d, o.oprtr, o.n2d, o.d2d))) {
        return false;
    }
    if (o.rdd != 1) {
        reduce_frctn(&o.rnd, &o.rdd);
    }
    printf("\nCalculation:\n%f/%f\n", o.rnd, o.rdd);

    /* 7. Create result string */
    d_to_str(o.rns, o.rnd);
    if (o.rdd == 1.0) {
        *o.rds = '\0';
    } else {
        d_to_str(o.rds, o.rdd);
    }
    create_result_str(o.r, o.rns, o.rds);

    /* 8. Insert result into base string */
    collapse_str(*l_bound, *r_bound);
    insert_str(src, *l_bound, o.r);
    printf("\nResult:\n%s\n", src);
    return true;
}
