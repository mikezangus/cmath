#include <ctype.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

void parse_equation(int l_bound, int r_bound)
{
    memset(eq.op1s, '\0', MAXLEN);
    memset(eq.op2s, '\0', MAXLEN);
    eq.oprtr = '\0';

    int i_op1 = 0;
    int i_op2 = 0;
    int cnt = 0;

    for (char *p = &input[l_bound]; p <= &input[r_bound]; p++) {
        if (is_oprtr(*p) && !cnt) {
            eq.oprtr = *p;
            cnt++;
            continue;
        } else if ((isdigit(*p) || *p == '.') && !cnt) {
            eq.op1s[i_op1++] = *p;
        } else if ((isdigit(*p) || *p == '.') && cnt) {
            eq.op2s[i_op2++] = *p;
            continue;
        } else {
            break;
        }
    }
}
