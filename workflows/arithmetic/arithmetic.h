#ifndef ARITHMETIC_H
#define ARITHMETIC_H


#include <stdbool.h>
#include "../../main.h"


typedef struct OprtnAr {
    char n1s[STR_MAXLEN];
    char d1s[STR_MAXLEN];

    char oprtr;

    char n2s[STR_MAXLEN];
    char d2s[STR_MAXLEN];

    double n1d;
    double d1d;

    double n2d;
    double d2d;

    double rnd;
    double rdd;

    char rns[STR_MAXLEN];
    char rds[STR_MAXLEN];

    char r[STR_MAXLEN]; 
} OprtnAr;


typedef enum  {
    FAIL = 0,
    PARSED_L_TO_PREV = 1,
    PARSED_R_TO_PREV = 2,
    PARSED_TO_NEW = 3,
} DivStatus;


char* extract_num_bwd(char* dst, const char* start, const char* min);
char* extract_num_fwd(char* dst, const char* start);
bool parse_arithmetic(const char* s, const char* start, bool bounds_found,
                      OprtnAr* o, Bounds* b);
bool parse_inoperable_division(const char* s, const char* op1, const char* op2,
                               OprtnAr* o, Bounds* b);
void parse_oprtn(char* dst_op1, char* dst_oprtr, char* dst_op2,
                 const char* src_op1, char src_oprtr, const char* src_op2);
bool solve_arithmetic(char* s, Bounds* b);


#endif // ARITHMETIC_H
