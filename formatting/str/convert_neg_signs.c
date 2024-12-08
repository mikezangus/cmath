#include <stdbool.h>
#include <string.h>
#include "../../utils/utils.h"

bool convert_neg_signs(char* s)
{
    bool formatted = false;
    char* p = s + 1;
    while (*p) {
        char* oprtr;
        if (!(oprtr = strchr(p, '-'))) {
            break;
        }
        char* prev_oprtr = oprtr - 1;
        if (*prev_oprtr == '-') {
            *oprtr = '+';
            formatted = true;
        }
        if (*prev_oprtr == '+' || *prev_oprtr == '-') {
            collapse_str(prev_oprtr, prev_oprtr);
            p = oprtr;
            formatted = true;
        } else {
            p = oprtr + 1;
        }
    }
    return formatted;
}
