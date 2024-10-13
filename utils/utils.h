#include <stdbool.h>

void balance_chars(char c, int* scale, char plus, char minus);

void collapse_str(char* start, char* end);
void copy_bounded_str(char* dst, char* src_start, char* src_end);

void insert_str(char* dst_str, const char* src_str, const char* insert_pos);

bool is_oprtr(char c);
bool is_paren_depth_same(char* p1, char* p2);
bool is_prec1_oprtr(char c);
bool is_prec2_oprtr(char c);
bool is_prec3_oprtr(char c);

void print_str_indexes(char* m, char* s);
void print_bounded_str(char* start, char* end);


char* find_nearest_oprtr(char* s, char* l_bound, char* r_bound);