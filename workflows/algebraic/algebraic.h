#include "../../main.h"

void calculate_vars(char oprtr, char op1_var, char op2_var, char *out_var, double op1_exp, double op2_exp, double *out_exp);
void create_var_str(char *in_var, char *in_exp, char *out);
void init_vars(void);
void insert_1(char *s);
void insert_eqzero(char *s);
void insert_mult(char *s);
void parse_var(char *in, char *out_var, double *out_exp);
int process_algebraic(char *s);
void remove_1(char *s);
void remove_exp1(char *s);
void remove_vars(char *s);
void solve_alg(char *s);
int var_exists(char *s);

struct Variables {
    char op1n_var;
    double op1n_exp;
    char op1d_var;
    double op1d_exp;

    char op2n_var;
    double op2n_exp;
    char op2d_var;
    double op2d_exp;

    char result_varn[STR_MAXLEN];
    double result_expnd;
    char result_expns[STR_MAXLEN];

    char result_vard[STR_MAXLEN];
    double result_expdd;
    char result_expds[STR_MAXLEN];

    char resultns[STR_MAXLEN];
    char resultds[STR_MAXLEN];
};
extern struct Variables vars;
