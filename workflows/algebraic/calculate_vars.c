#include "../../general/general.h"
#include <stdio.h>

static void process_prec2(char oprtr, char op1_var, char op2_var, char *out_var, double op1_exp, double op2_exp, double *out_exp)
{
    char exp_oprtr = '\0';
    switch (oprtr) {
        case '*':
            exp_oprtr = '+';
            break;
        case '/':
            exp_oprtr = '-';
            break;
    }
    if (op1_var != '\0' && op2_var != '\0') {
        calculate_result(op1_exp, exp_oprtr, op2_exp, out_exp);
        *out_var = op1_var;
    } else if (op1_var != '\0') {
        *out_var = op1_var;
    } else if (op2_var != '\0') {
        *out_var = op2_var;
    } 
}

static void process_prec3(char op1_var, char op2_var, char *out_var, double op1_exp, double op2_exp, double *out_exp)
{
    if ((op1_var != op2_var) || (op1_exp != op2_exp)) {
        return;
    }
    *out_var = op1_var;
    *out_exp = op1_exp;
}

void calculate_vars(char oprtr, char op1_var, char op2_var, char *out_var, double op1_exp, double op2_exp, double *out_exp)
{
    printf("Calulcating %c^%.1f %c %c^%.1f\n", op1_var, op1_exp, oprtr, op2_var, op2_exp);
    switch(oprtr) {
        case '*':
            process_prec2(oprtr, op1_var, op2_var, out_var, op1_exp, op2_exp, out_exp);
            return;
        case '/':
            process_prec2(oprtr, op1_var, op2_var, out_var, op1_exp, op2_exp, out_exp);
            return;
        case '+':
            process_prec3(op1_var, op2_var, out_var, op1_exp, op2_exp, out_exp);
            return;
        case '-':
            process_prec3(op1_var, op2_var, out_var, op1_exp, op2_exp, out_exp);
            return;
        default:
            return;
    }
}
