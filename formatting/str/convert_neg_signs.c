#include <string.h>
#include "../formatting.h"

void convert_neg_signs(char* s)
{
    char* p = s + 1;
    while (*p) {
        char* oprtr = strchr(p, '-');
        if (!oprtr) {
            return;
        }
        char* prev_oprtr = oprtr - 1;
        if (*prev_oprtr == '-') {
            *oprtr = '+';
        }
        if (*prev_oprtr == '+' || *prev_oprtr == '-') {
            collapse_str(prev_oprtr, prev_oprtr);
            p = oprtr;
        } else {
            p = oprtr + 1;
        }
    }
}
