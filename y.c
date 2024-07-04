#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

char input[MAXLEN] = "(((1*2) + 3) - 4)";
char terms[MAXLEN][MAXLEN];
char term[MAXLEN];
int term_idx = 0;
int terms_idx = 0;
int l_parens[MAXLEN];
int r_parens[MAXLEN];
int l_parens_i = 0;
int r_parens_i = 0;


struct parentheses {
    int left;
    int right;
} parens;

void find_delta(void)
{
    int min = 100;
    int l_i;
    int r_i;
    for (int l_i = 0; l_i < l_parens_i; l_i++) {
        printf("\n---------------\nLEFT INDEX = %d\n", l_i);
        for (int r_i = 0; r_i < r_parens_i; r_i++) {
            printf("\nRIGHT INDEX = %d\n", r_i);
            printf("Left: %d | Right %d\n", l_parens[l_i], r_parens[r_i]);
            int temp = abs(l_parens[l_i] - r_parens[r_i]);
            printf("Temp: %d\n", temp);
            if (temp < min) {
                parens.left = l_parens[l_i];
                parens.right = r_parens[r_i];
                printf("Struct | Left: %d, Right: %d\n", parens.left, parens.right);
                min = temp;
            }
        }
    }
    printf("\nFinish:\nMin: %d\n", min);
    printf("Left: %d, Right: %d\n", parens.left, parens.right);
}

void init_new_term(void)
{
    term_idx = 0;
    memset(term, '\0', MAXLEN);
}

void copy_term_to_terms(void)
{
    for (int i = 0; term[i] != '\0'; i++) {
        printf("Copying '%c' term[%d] -> terms[%d]\n", term[i], i, terms_idx);
    }
    strcpy(terms[terms_idx++], term);
    init_new_term();
}

void find_parens(int i)
{
    if (input[i] == '(') {
        l_parens[l_parens_i++] = i;
    } else if (input[i] == ')') {
        r_parens[r_parens_i++] = i;
    }
}

int main(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        find_parens(i);
    }
    
    for (int i = 0; i < l_parens_i; i++) {
        printf("L: %d\n", l_parens[i]);
    }
    for (int i = 0; i < r_parens_i; i++) {
        printf("R: %d\n", r_parens[i]);
    }
    find_delta();
    return 0;
}
