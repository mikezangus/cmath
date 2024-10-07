#include <stdbool.h>
#include "../../main.h"

bool find_bounds_by_highest_op(char* s, Bounds* b);
bool find_bounds_by_parens(char* s, Bounds* b);
bool find_bounds(char* s, Bounds* b);
void init_bounds(Bounds* b);


bool find_bounds_by_parens_backwards(char* s, char** l_bound, char** r_bound);