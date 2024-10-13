#include <stdbool.h>
#include "../main.h"

bool find_bounds_by_highest_oprtr(char* start, char** l_bound, char** r_bound);
bool find_bounds_by_parens(char* start, char** l_bound, char** r_bound);
bool find_bounds(char* start, char** l_bound, char** r_bound);
void init_bounds(char** l_bound, char** r_bound);
