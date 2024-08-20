#include <stdbool.h>

#define MAXLEN 100

void add_parens(void);
void calculate(void);
void convert_str_to_d(void);
void convert_d_to_str(void);
bool is_oprtr(char);
bool is_prec1_oprtr(char);
bool is_prec2_oprtr(char);
void parse(void);
void find_bounds(void);
bool verify_parens(void);
void replace_str(void);
bool verify_oprtr(void);
void find_parens(void);
void find_var(void);
void add_mult(void);
bool handle_x1(void);


struct equation {
    char op1s[MAXLEN];
    char op2s[MAXLEN];
    char oprtr;
    double op1d;
    double op2d;
    double resultd;
    char results[MAXLEN];
};
extern struct equation eq;
