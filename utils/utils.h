#include <stdbool.h>

bool char_is_var(char c);

void collapse_str(char* start, char* end);
void copy_bounded_str(char* input_start, char* input_end, char* output);

void insert_str(char* dst_str, const char* src_str, const char* insert_pos);

bool is_oprtr(char c);
bool is_prec1_oprtr(char c);
bool is_prec2_oprtr(char c);
bool is_prec3_oprtr(char c);

void print_str_indexes(char* m, char* s);
void print_bounded_str(char* start, char* end);

bool str_contains_var(char* s);

void weigh_chars(char c, short* scale, char weight1, char weight2);
