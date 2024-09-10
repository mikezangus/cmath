#include <stdbool.h>

bool find_bounds_by_highest_op(char* s, char** l_bound, char** r_bound);
bool find_bounds_by_parens(char* s, char** l_bound, char** r_bound);
bool find_bounds(char* s, char** l_bound, char** r_bound);
bool parse_equation(char* s, char** l_bound, char** r_bound, char* op1n, char* op1d, char* oprtr, char* op2n, char* op2d);
