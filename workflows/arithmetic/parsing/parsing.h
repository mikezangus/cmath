#include <stdbool.h>
#include "../arithmetic.h"

typedef enum  {
    FAILED_TO_PARSE = 0,
    PARSED_TO_CURRENT = 1,
    PARSED_TO_NEW = 2,
    FIND_NEW_OPERATION = 3,
} Status;

void parse_arithmetic(char* s, EqAr* eq, Bounds* b);
bool parse_division(char* s, char* div_oprtr, EqAr* eq, Bounds* b);
void parse_operand(char* dst, const char* start, const char* end);
