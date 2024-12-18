#include <stdbool.h>

void apply_pow_of_qtnt_rule(char* s);
void apply_prdct_of_pows_rule(char* s);
double calculate_den(double* n1, double* d1, char oprtr, double* n2, double* d2);
double calculate_oprtn(double op1, char oprtr, double op2n, double op2d);
void create_result_str(char* dst, char* n, char* d);
void equate_denoms(double* n1, double* d1, double* n2, double* d2);
void flip_frctn_divisor(char* oprtr, char* n, char* d);
void exp_rules(char* s);
bool is_str_operable(char* s);
void rationalize_denominator(char* src);
void reduce_frctn(double* n, double* d);
