#ifndef HEADER_H
#define HEADER_H

#define MAXLEN 100

void get_input(void);
void create_terms(void);
void parse(int);
void convert(int);
int calculate(void);

extern char input[MAXLEN];
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
