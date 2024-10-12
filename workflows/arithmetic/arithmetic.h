#ifndef ARITHMETIC_H
#define ARITHMETIC_H


#include <stdbool.h>
#include "../../main.h"


typedef struct EqAr {

    char op1_num_s[STR_MAXLEN];
    char op1_den_s[STR_MAXLEN];

    char oprtr;

    char op2_num_s[STR_MAXLEN];
    char op2_den_s[STR_MAXLEN];


    double op1_num_d;
    double op1_den_d;

    double op2_num_d;
    double op2_den_d;


    double result_num_d;
    double result_den_d;

    char result_num_s[STR_MAXLEN];
    char result_den_s[STR_MAXLEN];

    char result_s[STR_MAXLEN];
    
} EqAr;


void init_eq(EqAr* eq);
void process_arithmetic(char* s, Bounds* b);
bool solve_arithmetic(char* s, EqAr* eq, Bounds* b);


#endif // ARITHMETIC_H
