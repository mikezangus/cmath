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


bool solve_arithmetic(char* s, Bounds* b);


#endif // ARITHMETIC_H
