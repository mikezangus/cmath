#include <stdbool.h>

void balance_chars(char c, int* scale, char plus, char minus);
void collapse_str(char* start, char* end);
void insert_str(char* dst_str, const char* src_str, const char* insert_pos);
void print_bounded_str(char* start, char* end);

bool is_divisible(double num, double den);
bool is_num(char* p, char* start);
bool is_oprtr_in_str(char* s);
bool is_oprtr(char c);
bool is_prec1_oprtr(char c);
bool is_prec2_oprtr(char c);
bool is_prec3_oprtr(char c);
bool is_paren_depth_same(char* p1, char* p2);
bool is_paren(char c);
bool oprtn_is_operable(double num, char oprtr, double den);

void convert_d_to_str(double d, char* s);
double convert_str_to_d(char* s);
long long convert_str_to_int(char* s);

char* find_char(char c, char* start, char* end);
char* find_nearest_oprtr(char* s, char* l_bound, char* r_bound);
char* find_oprtr(char* start, char* end);
bool find_paren_set(char* start, char** l_paren, char** r_paren);
