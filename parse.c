#include <ctype.h>
#include "header.h"

void parse(void)
{
    eq.n1c_cnt = 0;
    eq.n2c_cnt = 0;
    eq.sign = '0';
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            if (eq.sign == '0') {
                eq.n1c[eq.n1c_cnt] = input[i];
                eq.n1c_cnt++;
            } else {
                eq.n2c[eq.n2c_cnt] = input[i];
                eq.n2c_cnt++;
            }
        } else if (input[i] == '+' || input[i] == '-') {
            eq.sign = input[i];
        }
    }
}