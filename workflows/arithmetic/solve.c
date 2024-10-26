#include <math.h>
#include <stdio.h>
#include <string.h>
#include "arithmetic.h"
#include "../../main.h"
#include "../../formatting/formatting.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

OprtnAr o;

static void init_oprtn(void)
{
    memset(o.n1s, '\0', STR_MAXLEN);
    memset(o.d1s, '\0', STR_MAXLEN);
    o.oprtr = '\0';
    memset(o.n2s, '\0', STR_MAXLEN);
    memset(o.d2s, '\0', STR_MAXLEN);
    o.n1d = o.d1d = o.n2d = o.d2d = o.rnd = o.rdd = 0.0;
    memset(o.rns, '\0', STR_MAXLEN);
    memset(o.rds, '\0', STR_MAXLEN); 
    memset(o.r, '\0', STR_MAXLEN); 
}

static void oprtn_str_to_double(double* n1d, double* d1d,
                                double* n2d, double* d2d,
                                char* n1s, char* d1s, char* n2s, char* d2s)
{
    *n1d = str_to_double(n1s);
    *d1d = str_to_double(d1s);
    *n2d = str_to_double(n2s);
    *d2d = str_to_double(d2s);
}

static void result_double_to_str(char* ns, char* ds, double nd, double dd)
{
    double_to_str(ns, nd);
    if (dd == 1.0) {
        *ds = '\0';
        return;
    }
    double_to_str(ds, dd);
}

bool solve_arithmetic(char* s, Bounds* b)
{
    init_oprtn();
    format_frctn_neg_signs(s, b);
    if (!parse_arithmetic(s, s, true, &o, b)) {
        return false;
    }
    if (*o.d1s == '0' || *o.d2s == '0') {
        fprintf(stderr, "\n%s\nError: 0 in denominator. Exiting\n", __FILE__);
        return false;
    }
    flip_frctn_divisor(&o.oprtr, o.n2s, o.d2s);
    oprtn_str_to_double(&o.n1d, &o.d1d, &o.n2d, &o.d2d,
                        o.n1s, o.d1s, o.n2s, o.d2s);
    if (isnan(o.rdd = calculate_den(&o.n1d, &o.d1d, o.oprtr, &o.n2d, &o.d2d))) {
        return false;
    }
    if (isnan(o.rnd = calculate_oprtn(o.n1d, o.oprtr, o.n2d))) {
        return false;
    }
    reduce_frctn(&o.rnd, &o.rdd);
    result_double_to_str(o.rns, o.rds, o.rnd, o.rdd);
    create_result_str(o.r, o.rns, o.rds);
    collapse_str(b->l, b->r);
    insert_str(s, o.r, b->l);
    printf("\nEnding: %s\n\n%s\n", s, DASHES);
    return true;
}
