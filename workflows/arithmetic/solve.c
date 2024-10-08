#include <math.h>
#include <stdio.h>
#include "arithmetic.h"
#include "parsing/parsing.h"
#include "../../main.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

static void convert_strs_to_doubles(EqAr* eq)
{
    eq->op1_num_d = convert_str_to_d(eq->op1_num_s);
    eq->op1_den_d = convert_str_to_d(eq->op1_den_s);
    eq->op2_num_d = convert_str_to_d(eq->op2_num_s);
    eq->op2_den_d = convert_str_to_d(eq->op2_den_s);
}

static void convert_doubles_to_strs(EqAr* eq)
{
    convert_d_to_str(eq->result_num_d, eq->result_num_s);
    if (eq->result_den_d == 1.0) {
        *eq->result_den_s = '\0';
        return;
    }
    convert_d_to_str(eq->result_den_d, eq->result_den_s);
}

static void adjust_bounds(char** l_bound, char** r_bound)
{
    if (*(*l_bound - 1) == '(' && *(*r_bound + 1) != ')') {
        (*l_bound)--;
    } else if (*(*l_bound - 1) != '(' && *(*r_bound + 1) == ')') {
        (*r_bound)++;
    }
}

bool solve_arithmetic(char* s, EqAr* eq)
{
    printf(
        "\n-------------------------\n"
        "Solving for:\n%s\n", s
    );
    char* l_bound = NULL;
    char* r_bound = NULL;
    parse_arithmetic(s, eq, &l_bound, &r_bound);
    convert_strs_to_doubles(eq);
    if (is_prec3_oprtr(eq->oprtr)) {
        equate_denoms(&eq->op1_num_d, &eq->op1_den_d, &eq->op2_num_d, &eq->op2_den_d);
        eq->result_den_d = eq->op1_den_d;
    } else {
        eq->result_den_d = calculate_result(eq->op1_den_d, eq->oprtr, eq->op2_den_d);
    }
    eq->result_num_d = calculate_result(eq->op1_num_d, eq->oprtr, eq->op2_num_d);
    if (isnan(eq->result_num_d) || isnan(eq->result_den_d)) {
        fprintf(stderr, "\n%s | Failed to calculate. Exiting\n", __FILE__);
        return false;
    }
    reduce_fraction(&eq->result_num_d, &eq->result_den_d);
    convert_doubles_to_strs(eq);
    create_result_str(eq->result_num_s, eq->result_den_s, eq->result_s);
    adjust_bounds(&l_bound, &r_bound);
    collapse_str(l_bound, r_bound);
    insert_str(s, eq->result_s, l_bound);
    remove_unnecessary_parens(s);
    return true;
}
