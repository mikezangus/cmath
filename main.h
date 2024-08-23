#include <stdbool.h>

#define MAXLEN 100

void add_parens(void);
void calculate_result(void);
int check_oprtr_exists(char *);
int check_parens_exist(char *);
void convert_str_to_d(void);
void convert_d_to_str(void);
void find_bounds(void);
void find_nearest_parens(char *);
void parse_equation(void);
void insert_result(char *);

extern char input[];

struct Equation {
    char op1s[MAXLEN];
    char op2s[MAXLEN];
    char oprtr;
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
};
extern struct Switches sw;
