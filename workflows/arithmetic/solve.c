#include <math.h>
#include <stdio.h>
#include <string.h>
#include "arithmetic.h"
#include "parsing/parsing.h"
#include "../../main.h"
#include "../../formatting/formatting.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

EqAr eq;

void init_eq(void)
{
    memset(eq.op1_num_s, '\0', STR_MAXLEN);
    memset(eq.op1_den_s, '\0', STR_MAXLEN);
    eq.oprtr = '\0';
    memset(eq.op2_num_s, '\0', STR_MAXLEN);
    memset(eq.op2_den_s, '\0', STR_MAXLEN);
}

static void convert_strs_to_doubles(void)
{
    eq.op1_num_d = convert_str_to_d(eq.op1_num_s);
    eq.op1_den_d = convert_str_to_d(eq.op1_den_s);
    eq.op2_num_d = convert_str_to_d(eq.op2_num_s);
    eq.op2_den_d = convert_str_to_d(eq.op2_den_s);
}

static void convert_doubles_to_strs(void)
{
    convert_d_to_str(eq.result_num_d, eq.result_num_s);
    if (eq.result_den_d == 1.0) {
        *eq.result_den_s = '\0';
        return;
    }
    convert_d_to_str(eq.result_den_d, eq.result_den_s);
}

bool solve_arithmetic(char* s, Bounds* b)
{
    init_eq();
    if (!parse_arithmetic(s, s, true, &eq, b)) {
        fprintf(stderr,
                "\n%s | Failed to parse. Exiting\n",
                __FILE__);
        return false;
    }
    convert_strs_to_doubles();
    if (is_prec3_oprtr(eq.oprtr)) {
        equate_denoms(&eq.op1_num_d, &eq.op1_den_d,
                      &eq.op2_num_d, &eq.op2_den_d);
        eq.result_den_d = eq.op1_den_d;
    } else {
        eq.result_den_d = calculate_result(eq.op1_den_d,
                                           eq.oprtr,
                                           eq.op2_den_d);
    }
    eq.result_num_d = calculate_result(eq.op1_num_d,
                                       eq.oprtr,
                                       eq.op2_num_d);
    if (isnan(eq.result_num_d) || isnan(eq.result_den_d)) {
        fprintf(stderr,
                "\n%s | Failed to calculate. Exiting\n",
                __FILE__);
        return false;
    }
    reduce_fraction(&eq.result_num_d, &eq.result_den_d);
    convert_doubles_to_strs();
    create_result_str(eq.result_num_s, eq.result_den_s, eq.result_s);
    printf("Before moving: %s\n", eq.result_s);
    move_fract_neg_sign(eq.result_s);
    printf("After moving:  %s\n", eq.result_s);
    collapse_str(b->l, b->r);
    insert_str(s, eq.result_s, b->l);
    printf("\nEnding: %s\n%s\n", s, DASHES);
    return true;
}
