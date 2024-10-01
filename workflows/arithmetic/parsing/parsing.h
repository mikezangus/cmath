#include <stdbool.h>
#include "../arithmetic.h"

void parse_arithmetic(char* s, struct EqAr* eq, char** l_bound, char** r_bound);
bool parse_division(char** start, char* div_op, char** end, struct EqAr* eq);
void parse_operand(char* start, char* end, char* dst);
