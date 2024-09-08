#ifndef MAIN_H
#define MAIN_H

#define NUM_MAXLEN 26
#define STR_MAXLEN 100

void clean_input(char *s);
void enter_workflow(char *s);

struct Equation {
    char op1ns[NUM_MAXLEN];
    char op1ds[NUM_MAXLEN];
    char oprtr;
    char op2ns[NUM_MAXLEN];
    char op2ds[NUM_MAXLEN];
    double op1nd;
    double op1dd;
    double op2nd;
    double op2dd;
    double resultnd;
    double resultdd;
    char resultns[NUM_MAXLEN];
    char resultds[NUM_MAXLEN];
    char results[STR_MAXLEN];
};
extern struct Equation eq;

struct Bounds {
    char* l;
    char* r;
};
extern struct Bounds bounds;

#endif // MAIN_H