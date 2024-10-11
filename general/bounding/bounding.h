#include <stdbool.h>
#include "../../main.h"

bool find_bounds_by_highest_op(char* s, char** l_bound, char** r_bound);
bool find_bounds_by_parens(char* s, char** l_bound, char** r_bound);
bool find_bounds(char* s, char** l_bound, char** r_bound);
void init_bounds(char** l_bound, char** r_bound);
