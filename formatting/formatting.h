#include <stdio.h>
#include "../main.h"
#include "../utils/utils.h"

void flip_frctn_divisor(char* oprtr, char* n, char* d);
void format_frctn_neg_signs(char* s, Bounds* b);

void convert_neg_signs(char* s);
void format_str(char* s);
void insert_parens(char* s);
void remove_unneeded_parens(char* s);
