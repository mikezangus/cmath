#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"
#include <stdbool.h>

extern char input[];
extern int l_bound;
extern int r_bound;

void parse()
{
    int i_op1s = 0;
    int i_op2s = 0;
    int oprtr_cnt = 0;
    memset(eq.op1s, '\0', MAXLEN);
    memset(eq.op2s, '\0', MAXLEN);
    eq.oprtr = '\0';
    for (int i = l_bound; i <= r_bound; i++) {
        if (is_oprtr(input[i]) && oprtr_cnt == 0) {
            eq.oprtr = input[i];
            oprtr_cnt++;
            continue;
        } else if ((isdigit(input[i]) || input[i] == '.') && oprtr_cnt == 0) {
            eq.op1s[i_op1s++] = input[i];
            continue;
        } else if ((isdigit(input[i]) || input[i] == '.') && oprtr_cnt == 1) {
            eq.op2s[i_op2s++] = input[i];
            continue;
        } else {
            break;
        }
    }
    printf("Parsed:\n%s %c %s\n", eq.op1s, eq.oprtr, eq.op2s);
}
