#define MAXLEN 100

void clean_input(void);
void set_workflow(void);

extern char input[];

struct Equation {
    char op1ns[MAXLEN];
    char op1ds[MAXLEN];
    char oprtr;
    char op2ns[MAXLEN];
    char op2ds[MAXLEN];
    double op1nd;
    double op1dd;
    double op2nd;
    double op2dd;
    double resultnd;
    double resultdd;
    char resultns[MAXLEN];
    char resultds[MAXLEN];
    char results[MAXLEN];
};
extern struct Equation eq;

struct Parens {
    int l;
    int r;
};
extern struct Parens parens;

struct Bounds {
    int l;
    int r;
};
extern struct Bounds bounds;

struct Switches {
    int parens_exist;
    int division;
    int arithmetic;
    int alg_1var;
};
extern struct Switches sw;
