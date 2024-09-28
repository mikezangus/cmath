#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "algebraic.h"
#include "../../general/parsing/parsing.h"
#include "../../general/general.h"
#include "../../utils/utils.h"

struct EquationAlg eq_alg;


static void parse_base(char* src, char* dst)
{
    char* var = find_var(src);
    size_t len = var - src;
    memcpy(dst, src, len);
    printf("Base: %s\n", dst);
}

static void parse_varx(char* src, char* dst)
{
    char* var = find_var(src);
    *dst = *var;
}

static void parse_exp(char* src, char* dst)
{
    char* exp_oprtr = strchr(src, '^');
    size_t len = src + strlen(src) - exp_oprtr;
    memcpy(dst, exp_oprtr + 1, len);
    printf("Exponent: %s\n", dst);
}


static void parse_alg(struct EquationAlg* eq, char* op1, char* op2, char oprtr)
{
    printf("Parse Algebra takes these args:\n");
    printf("  Op1:   %s\n", op1);
    printf("  Oprtr: %c\n", oprtr);
    printf("  Op2:   %s\n", op2);
    eq->oprtr = oprtr;
    parse_base(op1, eq->op1_num_base_s);
    parse_varx(op1, &eq->op1_num_var);
    parse_exp(op1, eq->op1_num_exp_s);
    parse_base(op2, eq->op2_num_base_s);
    parse_varx(op2, &eq->op2_num_var);
    parse_exp(op2, eq->op2_num_exp_s);
}

static bool are_vars_same(char var1, char var2)
{
    return var1 == var2;
}

static bool are_exps_same(char* exp1, char* exp2)
{
    return strcmp(exp1, exp2) == 0;
}

static bool handle_prec2(struct EquationAlg* eq)
{
    return are_vars_same(eq->op1_num_var, eq->op2_num_var);
}

static bool handle_prec3(struct EquationAlg* eq)
{
    return (
        are_vars_same(eq->op1_num_var, eq->op2_num_var) &&
        are_exps_same(eq->op1_num_exp_s, eq->op2_num_exp_s)
    );
}

static bool czech(struct EquationAlg* eq)
{
    switch (eq->oprtr) {
    case '*':
        return handle_prec2(eq);
    case '/':
        return handle_prec2(eq);
    case '+':
        return handle_prec3(eq);
    case '-':
        return handle_prec3(eq);
    default:
        return false;
    }
}

void solve_alg(char* s)
{
    printf("\n\nStart of solve loop: %s\n", s);
    parse_equation(s, &bounds.l, &bounds.r, eq.op1ns, eq.op1ds, &eq.oprtr, eq.op2ns, eq.op2ds);
    printf("Parsed main: %s %c %s\n", eq.op1ns, eq.oprtr, eq.op2ns);
    parse_alg(&eq_alg, eq.op1ns, eq.op2ns, eq.oprtr);
    printf("Parsed alg:\n");
    printf("  op1 base: %s\n", eq_alg.op1_num_base_s);
    printf("  op1 var:  %c\n", eq_alg.op1_num_var);
    printf("  op1 exp:  %s\n", eq_alg.op1_num_exp_s);
    printf("  oprtr:    %c\n", eq_alg.oprtr);
    printf("  op2 base: %s\n", eq_alg.op2_num_base_s);
    printf("  op2 var:  %c\n", eq_alg.op2_num_var);
    printf("  op2 exp:  %s\n", eq_alg.op2_num_exp_s);
    if (!czech(&eq_alg)) {
        printf("baaaad\n");
        return;
    }
    convert_str_to_d(eq_alg.op1_num_base_s, &eq_alg.op1_num_base_d);
    convert_str_to_d(eq_alg.op1_num_exp_s, &eq_alg.op1_num_exp_d);
    convert_str_to_d(eq_alg.op2_num_base_s, &eq_alg.op2_num_base_d);
    convert_str_to_d(eq_alg.op2_num_exp_s, &eq_alg.op2_num_exp_d);
    calculate_vars(&eq_alg);
    printf("Result after calculating:\n%f%c^%f\n", eq_alg.res_num_base_d, eq_alg.res_num_var, eq_alg.res_num_exp_d);
    convert_d_to_str(eq_alg.res_num_base_d, eq_alg.res_num_base_s);
    convert_d_to_str(eq_alg.res_num_exp_d, eq_alg.res_num_exp_s);
    strcpy(eq_alg.result, eq_alg.res_num_base_s);
    size_t len = strlen(eq_alg.result);
    eq_alg.result[len] = eq_alg.res_num_var;
    eq_alg.result[len + 1] = '^';
    eq_alg.result[len + 2] = '\0';
    strcat(eq_alg.result, eq_alg.res_num_exp_s);
    printf("Result after converting to str:\n%s\n", eq_alg.result);
    collapse_str(bounds.l, bounds.r);
    printf("Collapsed: %s\n", s);
    insert_str(s, eq_alg.result, bounds.l);
    printf("New str:\n%s\n", s);
}

