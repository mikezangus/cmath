#include <stdbool.h>

double calculate_result(double op1, char oprtr, double op2);
void create_result_str(char* dst, char* num, char* den);
void equate_denoms(double* p_n1, double* p_d1, double* p_n2, double* p_d2);
bool is_str_operable(char* s);
void reduce_frctn(double* n, double* d);
