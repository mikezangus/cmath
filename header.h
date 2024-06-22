#define MAXLEN 100

void get_input(void);
void create_terms(void);
void parse(int term_idx);
void convert(int term_idx);
int calculate(void);

extern char input[MAXLEN];
extern char terms[MAXLEN][MAXLEN];
struct equation {
    char n1c[MAXLEN];
    char n2c[MAXLEN];
    char sign;
    double n1d;
    double n2d;
    double result;
};
extern struct equation eq;
