#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

void move_exp_to_base_frctn(char* s)
{
    char* exp_sign = strchr(s, '^');
    if (!exp_sign) {
        return;
    }
    if (*(exp_sign - 1) != ')') {
        return;     /* will be continue once looping is built */
    }
    char* div_sign = NULL;
    for (char* p = exp_sign - 2;
         p >= s && (is_num(p, NULL) || is_oprtr(*p));
         p--) {
        if (*p == '/') {
            div_sign = p;
            break;
        }
    }
    if (!div_sign) {
        return;
    }
    char exp[STR_MAXLEN] = {0};
    char* p_exp = exp;
    *p_exp++ = '^';
    *p_exp++ = '(';
    char* start = *(exp_sign + 1) == '(' ? exp_sign + 2 : exp_sign + 1; 
    char* end = extract_num_fwd(p_exp, start);
    p_exp = exp + strlen(exp);
    if (*(end + 1) == '/') {
        *p_exp++ = '/';
        end = extract_num_fwd(p_exp, end + 2);
    }
    *(exp + strlen(exp)) = ')';
    printf("Parsed exponent: %s\n", exp);
    collapse_str(start, end);
}
