#include "../main.h"
#include "../utils/utils.h"

void flip_frctn_divisor(char* oprtr, char* num, char* den);
void format_parsed_frctn(char* num1, char* den1, char* oprtr, char* num2, char* den2);
void format_neg_frctn(char* num, char* den);
void move_external_neg_sign(char* s, Bounds* b);

void insert_div_parens(char* s);
void format_parens(char* s);
void remove_parens(char* s);

void convert_neg_signs(char* s);
