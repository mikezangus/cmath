#include <stdbool.h>

void balance_chars(char c, int* scale, char plus, char minus);
void collapse_str(char* start, char* end);
char* extract_num_bwd(char* dst, const char* start, const char* min);
char* extract_num_fwd(char* dst, const char* start);
int get_paren_depth(const char* p1, const char* p2);
void insert_str(char* dst_str, const char* src_str, const char* insert_pos);
void print_bounded_str(const char* start, const char* end);

bool is_num(const char* p, const char* start);
bool is_oprtr_in_str(const char* s);

bool is_oprtr(char c);
bool is_prec1_oprtr(char c);
bool is_prec2_oprtr(char c);
bool is_prec3_oprtr(char c);

bool is_paren(char c);
bool is_var(char c);
bool is_oprtn_operable(double op1n, double op1d,
                       char oprtr,
                       double op2n, double op2d);

void d_to_str(char* dst, double src);
char invert_oprtr(char oprtr);
double str_to_d(const char* src);
long long str_to_int(const char* src);

char* find_char(char c, const char* start, const char* end);
char* find_adj_oprtr(const char* s, const char* l_start, const char* r_start);
char* find_oprtr(const char* start, const char* end);
bool find_paren_set(const char* start, char** l_paren, char** r_paren);
char* find_var(const char* start, const char* end);
