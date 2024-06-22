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

void copy_term_to_terms(void)
{
    for (int i = 0; term[i] != '\0'; i++) {
        printf("Copying char '%c' from array term[%d] to array terms[%d]\n", term[i], i, terms_idx);
    }
    strcpy(terms[terms_idx], term);
    terms_idx++;
    init_term();
}

void create_terms(void)
{
    int multi_term = 0;
    init_term();
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            term[term_idx] = input[i];
            term_idx++;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            if (!multi_term) {
                term[term_idx] = input[i];
                term_idx++;
                multi_term++;
            } else {
                copy_term_to_terms();
                term[term_idx] = input[i];
                term_idx++;
            }
        }
    }
    copy_term_to_terms();
}
