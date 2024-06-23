#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"


void parse(int terms_idx)
{
    printf("\n----------------------------------------\nTERM %d\n", terms_idx + 1);
    printf("\n1. Parse\n");
    memset(eq.op1c, '\0', MAXLEN);
    memset(eq.op2c, '\0', MAXLEN);
    int op1c_cnt = 0;
    int op2c_cnt = 0;
    int oprtr_cnt = 0;
    char *term = terms[terms_idx];
    for (int i = 0; term[i] != '\0'; i++) {
        if (term[i] == '+' || term[i] == '-' || term[i] == '*' || term[i] == '/' || term[i] == '^') {
            eq.oprtr = term[i];
            oprtr_cnt++;
        } else if (isdigit(term[i])) {
            if (!oprtr_cnt) {
                eq.op1c[op1c_cnt++] = term[i];
            } else {
                eq.op2c[op2c_cnt++] = term[i];
            }
        }
        if (terms_idx) {
            strcpy(eq.op1c, "0");
        }
    }
    printf("   Operator: %c\n", eq.oprtr);
    for (int i = 0; eq.op1c[i] != '\0'; i++) {
        printf("   Operand 1 [%d]: %c\n", i, eq.op1c[i]);
    }
    for (int i = 0; eq.op2c[i] != '\0'; i++) {
        printf("   Operand 2 [%d]: %c\n", i, eq.op2c[i]);
    }
    printf("   Previous result: %f\n", eq.result);
}
