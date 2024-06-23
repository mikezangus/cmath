#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAXLEN 100

int terms_idx = 0;
char term[MAXLEN];
int term_idx = 0;

void init_new_term(void)
{
    term_idx = 0;
    for (int i = 0; i < MAXLEN; i++)
        term[i] = '\0';
}

void copy_term_to_terms(void)
{
    for (int i = 0; term[i] != '\0'; i++) {
        printf("Copying '%c' term[%d] -> terms[%d]\n", term[i], i, terms_idx);
    }
    strcpy(terms[terms_idx++], term);
    init_new_term();
}

void create_terms(void)
{
    int multi_term = 0;
    init_new_term();
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            term[term_idx++] = input[i];
        } else if (is_oprtr(input[i])) {
            if (!multi_term) {
                term[term_idx++] = input[i];
                multi_term++;
            } else {
                copy_term_to_terms();
                term[term_idx++] = input[i];
            }
        }
    }
    copy_term_to_terms();
}
