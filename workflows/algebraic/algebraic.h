#include "../../main.h"
#include <stdbool.h>


struct EqAlg {

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
extern struct EqAlg eq_alg;


void calculate_vars(struct EqAlg* eq_alg);
void create_var_str(char* in_var, char* in_exp, char* out);
char* find_var(char* s);
void init_vars(void);
void insert_eqzero(char* s);
void insert_exp1(char* s);
void insert_mult1(char* s);
bool is_var(char c);
void parse_var(char* in, char* out_var, double* out_exp);
void process_algebraic(char* s);
void rearrange(char* s);
void remove_mult1(char* s);
void remove_exp1(char* s);
void remove_vars(char* s);
void solve_alg(char* s);
int var_exists(char* s);
