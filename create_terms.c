#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAXLEN 100

int terms_idx = 0;
char term[MAXLEN];
int term_idx = 0;

void init_term(void)
{
    term_idx = 0;
    for (int i = 0; i < MAXLEN; i++)
        term[i] = '\0';
}

void populate_terms(void)
{
    strcpy(terms[terms_idx], term);
    terms_idx++;
    init_term();
}

void create_terms(void)
{
    int op_cnt = 0;
    init_term();
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            term[term_idx] = input[i];
            term_idx++;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            if (!op_cnt) {
                term[term_idx] = input[i];
                term_idx++;
                op_cnt++;
            } else if (op_cnt) {
                populate_terms();
                term[term_idx] = input[i];
                term_idx++;
            }
        }
    }
    populate_terms();
    for (int i = 0; i < term_idx; i++)
        printf("OUTPUT [%d] %s", i, terms[i]);
    return 0;
}
