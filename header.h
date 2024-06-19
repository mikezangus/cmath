#define MAXLEN 100

void get_input(void);
void parse(void);
void convert(void);
int calculate(void);

struct equation {
    char n1c[MAXLEN];
    char n2c[MAXLEN];
    int n1c_cnt;
    int n2c_cnt;
    char sign;
    double n1d;
    double n2d;
    double result;
};
extern struct equation eq;
extern char input[MAXLEN];
