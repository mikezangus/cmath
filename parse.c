#include <stdio.h>
#include <ctype.h>
#include "header.h"


void parse(int terms_idx)
{
    printf("ENTERING PARSE\n");
    for (int i = 0; i <= MAXLEN; i++) {
        eq.n1c[i] = '\0';
    }
    for (int i = 0; i <= MAXLEN; i++) {
        eq.n2c[i] = '\0';
    }
    int n1c_cnt = 0;
    int n2c_cnt = 0;
    int sign_cnt = 0;
    char *term = terms[terms_idx];
    for (int i = 0; term[i] != '\0'; i++) {
        if (!terms_idx) {
            printf("FIRST TERM\n");
            if (term[i] == '+' || term[i] == '-' || term[i] == '*' || term[i] == '/') {
                eq.sign = term[i];
                sign_cnt++;
            } else if (isdigit(term[i])) {
                if (!sign_cnt) {
                    eq.n1c[n1c_cnt] = term[i];
                    n1c_cnt++;
                } else {
                    eq.n2c[n2c_cnt] = term[i];
                    n2c_cnt++;
                }
            }
        } else {
            printf("NOT FIRST TERM\n");
            eq.n1c[n1c_cnt] = '0';
            if (term[i] == '+' || term[i] == '-' || term[i] == '*' || term[i] == '/') {
                eq.sign = term[i];
            } else if (isdigit(term[i])) {
                eq.n2c[n2c_cnt] = term[i];
                n2c_cnt++;
            }
        }
    }
    printf("\nPARSE [%d]:\n", terms_idx);
    printf("Sign: %c\n", eq.sign);
    for (int i = 0; eq.n1c[i] != '\0'; i++) {
        printf("n1c [%d] %c\n", i, eq.n1c[i]);
    }
    for (int i = 0; eq.n2c[i] != '\0'; i++) {
        printf("n2c [%d] %c\n", i, eq.n2c[i]);
    }
    printf("Previous result: %f\n", eq.result);
}