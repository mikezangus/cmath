#include <stdio.h>
#include <ctype.h>
#include "header.h"


void parse(int terms_idx)
{
    printf("\n----------------------------------------\nTERM %d\n", terms_idx + 1);
    printf("\n1. Parse\n");
    for (int i = 0; i <= MAXLEN; i++) {
        eq.op1c[i] = '\0';
    }
    for (int i = 0; i <= MAXLEN; i++) {
        eq.op2c[i] = '\0';
    }
    int op1c_cnt = 0;
    int op2c_cnt = 0;
    int oprtr_cnt = 0;
    char *term = terms[terms_idx];
    for (int i = 0; term[i] != '\0'; i++) {
        if (!terms_idx) {
            if (term[i] == '+' || term[i] == '-' || term[i] == '*' || term[i] == '/' || term[i] == '^') {
                eq.oprtr = term[i];
                oprtr_cnt++;
            } else if (isdigit(term[i])) {
                if (!oprtr_cnt) {
                    eq.op1c[op1c_cnt] = term[i];
                    op1c_cnt++;
                } else {
                    eq.op2c[op2c_cnt] = term[i];
                    op2c_cnt++;
                }
            }
        } else {
            eq.op1c[op1c_cnt] = '0';
            if (term[i] == '+' || term[i] == '-' || term[i] == '*' || term[i] == '/' || term[i] == '^') {
                eq.oprtr = term[i];
            } else if (isdigit(term[i])) {
                eq.op2c[op2c_cnt] = term[i];
                op2c_cnt++;
            }
        }
    }
    printf("Operator: %c\n", eq.oprtr);
    for (int i = 0; eq.op1c[i] != '\0'; i++) {
        printf("Operand 1 [%d]: %c\n", i, eq.op1c[i]);
    }
    for (int i = 0; eq.op2c[i] != '\0'; i++) {
        printf("Operand 2 [%d]: %c\n", i, eq.op2c[i]);
    }
    printf("Previous result: %f\n", eq.result);
}
