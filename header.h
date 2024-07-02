#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

#define MAXLEN 100

void get_input(void);
bool is_oprtr(char);
void create_terms(void);
void parse(int);
void convert(int);
int calculate(void);

extern char input_raw[MAXLEN];
extern char input_parens[MAXLEN];
extern char terms[MAXLEN][MAXLEN];
struct equation {
    char op1c[MAXLEN];
    char op2c[MAXLEN];
    char oprtr;
    double op1d;
    double op2d;
    double result;
};
extern struct equation eq;

#endif
