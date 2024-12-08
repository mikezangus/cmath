#include <stdbool.h>
#include <stdio.h>
#include "../main.h"
#include "../utils/utils.h"

void flip_frctn_divisor(char* oprtr, char* n, char* d);
void format_frctn_neg_signs(char* s, char* div_sign, Bounds* b);

bool convert_neg_signs(char* s);
void format_str(char* s);
bool insert_parens(char* s);
bool remove_1_oprtns(char* s);
bool remove_unneeded_parens(char* s);
