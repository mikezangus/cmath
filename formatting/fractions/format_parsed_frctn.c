#include "../formatting.h"

void format_parsed_frctn(char* num1, char* den1,
                         char* oprtr,
                         char* num2, char* den2)
{
    if (num2 && den2) {
        flip_frctn_divisor(oprtr, num2, den2);
        format_neg_frctn(num2, den2);
    }
    format_neg_frctn(num1, den1);
}
