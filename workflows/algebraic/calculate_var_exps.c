#include "../../general/general.h"
#include <stdio.h>


static void process_prec2(char oprtr, char op1_var, double op1_var_exp, char op2_var, double op2_var_exp, double *out)
{
    printf("Processing prec 2\n");
    char exp_oprtr = '\0';
    switch (oprtr) {
        case '*': exp_oprtr = '+'; break;
        case '/': exp_oprtr = '-'; break;
    }
    printf("Operator: %c\n", oprtr);
    printf("Exp oprtr: %c\n", exp_oprtr);
    if (op1_var != '\0' && op2_var != '\0') {
        calculate_result(op1_var_exp, exp_oprtr, op2_var_exp, out);
    } else if (op1_var != '\0') {
        *out = op1_var_exp;
    } else if (op2_var != '\0') {
        *out = op2_var_exp;
    } 
}

static void process_prec3(double op1_var_exp, double op2_var_exp, double *out)
{
    if (op1_var_exp != op2_var_exp) {
        return;
    }
    *out = op1_var_exp;
}

void calculate_var_exps(char oprtr, char op1_var, double op1_var_exp, char op2_var, double op2_var_exp, double *out)
{
    printf("Calculating %f %c %f\n", op1_var_exp, oprtr, op2_var_exp);
    switch(oprtr) {
        case '*': process_prec2(oprtr, op1_var, op1_var_exp, op2_var, op2_var_exp, out); return;
        case '/': process_prec2(oprtr, op1_var, op1_var_exp, op2_var, op2_var_exp, out); return;
        case '+': process_prec3(op1_var_exp, op2_var_exp, out); return;
        case '-': process_prec3(op1_var_exp, op2_var_exp, out); return;
    }
}
