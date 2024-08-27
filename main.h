#define MAXLEN 100

void clean_input(void);
void set_workflow(void);

extern char input[];

struct Equation {
    char op1s[MAXLEN];
    char oprtr;
    char op2s[MAXLEN];
    char results[MAXLEN];
    double op1d;
    double op2d;
    double resultd;
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
