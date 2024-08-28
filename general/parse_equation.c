#include <ctype.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

void parse_equation(int l_bound, int r_bound)
{
    int i_op1n = 0;
    int i_op1d = 0;
    int i_op2n = 0;
    int i_op2d = 0;
    int cnt = 0;
    int sw_denom = 0;
    for (char *p = &input[l_bound]; p <= &input[r_bound]; p++) {
        if (*p == '/') {
            sw_denom = 1;
        } else if (is_oprtr(*p)) {
            if (!cnt) {
                eq.oprtr = *p;
                sw_denom = 0;
                cnt++;
            } else {
                break;
            }
        } else if (!cnt) {
            if (isdigit(*p) || *p == '.') {
                if (!sw_denom) {
                    eq.op1ns[i_op1n++] = *p;
                } else {
                    eq.op1ds[i_op1d++] = *p;
                }
            }
        } else if (cnt) {
            if (isdigit(*p) || *p == '.') {
                if (!sw_denom) {
                    eq.op2ns[i_op2n++] = *p;
                } else {
                    eq.op2ds[i_op2d++] = *p;
                }
            }
        } else {
            break;
        }
    }
}
