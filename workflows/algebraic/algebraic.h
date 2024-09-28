#include "../../main.h"
#include <stdbool.h>


void create_var_str(char* in_var, char* in_exp, char* out);
char* find_var(char* s);
void init_vars(void);
void insert_1(char* s);
void insert_eqzero(char* s);
bool is_var(char c);
void parse_var(char* in, char* out_var, double* out_exp);
void process_algebraic(char* s);
void rearrange(char* s);
void remove_1(char* s);
void remove_exp1(char* s);
void remove_vars(char* s);
void solve_alg(char* s);
int var_exists(char* s);

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



struct EquationAlg {

    char oprtr;


    char op1_num_base_s[STR_MAXLEN];
    char op1_num_var;
    char op1_num_exp_s[STR_MAXLEN];

    char op1_den_base_s[STR_MAXLEN];
    char op1_den_var;
    char op1_den_exp_s[STR_MAXLEN];


    char op2_num_base_s[STR_MAXLEN];
    char op2_num_var;
    char op2_num_exp_s[STR_MAXLEN];

    char op2_den_base_s[STR_MAXLEN];
    char op2_den_var;
    char op2_den_exp_s[STR_MAXLEN];


    double op1_num_base_d;
    double op1_num_exp_d;

    double op1_den_base_d;
    double op1_den_exp_d;


    double op2_num_base_d;
    double op2_num_exp_d;

    double op2_den_base_d;
    double op2_den_exp_d;


    double res_num_base_d;
    double res_num_exp_d;

    char res_num_var;

    char res_num_base_s[STR_MAXLEN];
    char res_num_exp_s[STR_MAXLEN];

    double res_den_base_d;
    double res_den_exp_d;

    char res_den_var;

    char res_den_base_s[STR_MAXLEN];
    char res_den_exp_s[STR_MAXLEN];


    char result[STR_MAXLEN];
    
};
extern struct EquationAlg eq_alg;


void calculate_vars(struct EquationAlg* eq);