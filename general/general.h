void add_parens(void);
void add_parens_div(void);

void calculate_result(double op1, char oprtr, double op2, double *result);
int check_division_exists(void);
int check_oprtr_exists(void);
int check_parens_balanced(void);
int check_parens_exist(void);
void create_result_str(char *n, char *d, char *r);

void convert_d_to_str(double d, char *s);
void convert_str_to_d(char *s, double *d);

void equate_denoms(double n1, double d1, double n2, double d2);

void find_bounds(void);
void find_nearest_parens(void);

void init_eq(void);
void insert_denom(void);
void insert_result(char *destination, int l_bound, int r_bound, char *insertion);

void parse_equation(int l_bound, int r_bound);

void reduce_fraction(double *n, double *d);

void sequence(int l_bound, int r_bound);
void solve(void);
