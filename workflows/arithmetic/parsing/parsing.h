#include <stdbool.h>
#include "../arithmetic.h"

typedef enum  {
    FAIL = 0,
    PARSED_L_TO_PREV = 1,
    PARSED_R_TO_PREV = 2,
    PARSED_TO_NEW = 3,
} DivStatus;

char* extract_num_bwd(char* dst, char* start, char* min);
char* extract_num_fwd(char* dst, char* start);
bool parse_arithmetic(char* s, char* start, bool bounds_found,
                      EqAr* eq, Bounds* b);
bool parse_inoperable_division(char* s, char* op1, char* op2,
                               EqAr* eq, Bounds* b);
void parse_oprtn(char *dst_op1, char* dst_oprtr, char* dst_op2,
                 char *src_op1, char src_oprtr, char* src_op2);
