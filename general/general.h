void add_parens(void);

void calculate_result(double op1, char oprtr, double op2, double *result);
void convert_d_to_str(double d, char *s);
void convert_str_to_d(char *s, double *d);
void create_result_str(char *n, char *d, char *r);

void equate_denoms(double *p_n1, double *p_d1, double *p_n2, double *p_d2);

void init_eq(void);
void insert_denom(char *d1, char *d2);
void insert_result(char *destination, int l_bound, int r_bound, char *insertion, int sw_alg);

void reduce_fraction(double *n, double *d);
