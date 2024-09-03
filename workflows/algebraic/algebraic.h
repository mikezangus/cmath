#include "../../main.h"

int process_algebraic(char *s);
void calculate_var_exps(char oprtr, char op1_var, double op1_var_exp, char op2_var, double op2_var_exp, double *out);
void insert_eqzero(char *s);
void insert_mult(char *s);
void parse_var(char *in, char *out_var, double *out_exp);
void remove_vars(char *s);
void solve_alg(char *s);

struct Variables {
    char op1n_var;
    double op1n_var_exp;
    char op1d_var;
    double op1d_var_exp;
    char op2n_var;
    double op2n_var_exp;
    char op2d_var;
    double op2d_var_exp;
    double result_powd;
    char result_pows[STR_MAXLEN];
};
extern struct Variables vars;
