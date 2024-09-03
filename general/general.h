void calculate_result(double op1, char oprtr, double op2, double *result);
void convert_d_to_str(double d, char *s);
void convert_str_to_d(char *s, double *d);
void create_result_str(char *n, char *x_n, char *d, char *r);

void equate_denoms(double *p_n1, double *p_d1, double *p_n2, double *p_d2);

void find_bounds(char *s, int *l_bound, int *r_bound);

void init_eq(void);
void insert_denom(char *d1, char *d2);
void insert_parens(char *s);
void insert_result(char *destination, int l_bound, int r_bound, char *insertion);

void parse_equation(char *in, int l_bound, int r_bound, char *op1_n, char *op1_d, char *oprtr, char *op2_n, char *op2_d);

void reduce_fraction(double *n, double *d);
