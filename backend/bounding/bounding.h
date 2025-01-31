#include <stdbool.h>
#include "../main.h"

bool find_bounds_by_oprtr(const char* start, const char* end,
                          char** l_bound, char** r_bound);
bool find_bounds_by_parens(const char* start, char** l_bound, char** r_bound);
bool find_bounds(const char* start, char** l_bound, char** r_bound);
