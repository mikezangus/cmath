#define MAXLEN 100

void get_input(void);
void parse(void);
void convert(void);
void calculate(void);

extern char input[MAXLEN];
struct equation {
    char n1c[MAXLEN];
    char n2c[MAXLEN];
    char sign;
    int n1c_cnt;
    int n2c_cnt;
    double n1d;
    double n2d;
    double result;
};
extern struct equation eq;
