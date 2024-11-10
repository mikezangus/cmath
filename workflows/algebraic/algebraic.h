#ifndef ALGEBRAIC_H
#define ALGEBRAIC_H

#include <stdbool.h>
#include "../../main.h"


typedef struct OprtnAlg {
    char n1bs[STR_MAXLEN];
    char n1v;
    char n1es[STR_MAXLEN];

    char d1bs[STR_MAXLEN];
    char d1v;
    char d1es[STR_MAXLEN];

    char oprtr;

    char n2bs[STR_MAXLEN];
    char n2v;
    char n2es[STR_MAXLEN];

    char d2bs[STR_MAXLEN];
    char d2v;
    char d2es[STR_MAXLEN];

} OprtnAlg;



bool parse_algebraic( char* s,
                     const char* v1, char* oprtr, const char* v2, Bounds* b);

bool is_alg_oprtn_operable(char v1, const char* e1,
                           char oprtr,
                           char v2, const char* e2);

void format_vars(char* s);
void insert_eqzero(char* s);
void rearrange(char* s);
bool solve_algebraic(char* s);

void isolate_num_oprtn(char* s);
void isolate_var_base(char* s);
void isolate_var_exp(char* s);

#endif // ALGEBRAIC_H
