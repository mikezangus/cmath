#include <stdbool.h>

double calculate_result(double op1, char oprtr, double op2);
void convert_d_to_str(double d, char* s);
double convert_str_to_d(char* s);
long long convert_str_to_int(char* s);
void create_result_str(char* n, char* d, char* r);

void equate_denoms(double* p_n1, double* p_d1, double* p_n2, double* p_d2);
bool equation_is_operable(char* op1, char* oprtr, char* op2);

char* find_oprtr(char* start, char* end);

void insert_denom(char* d1, char* d2);
void insert_parens(char* s);

bool is_operable(long long op1, char oprtr, long long op2);

void rearrange(char* s);
void reduce_fraction(double* n, double* d);
