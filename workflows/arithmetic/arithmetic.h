#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "../../main.h"

struct EqAr {

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

};
extern struct EqAr eq_ar;

void parse_arithmetic(char* s, struct EqAr* eq, char** l_bound, char** r_bound);
void process_arithmetic(char* s);
void solve(char* s, struct EqAr* eq);

#endif // ARITHMETIC_H
