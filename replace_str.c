#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern char input[];
extern int l_bound;
extern int r_bound;

int start = -1;
int end = -1;

static void check_parens(void)
{
    if (input[l_bound - 1] == '(' && input[r_bound + 1] == ')') {
        start = l_bound - 1;
        end = r_bound + 1;
    } else {
        start = l_bound;
        end = r_bound;
    }
}

static void collapse_space(void)
{
    int len = strlen(input);
    for (int i = start; i <= end; i++) {
        input[i] = '\0';
    }
    for (int i = start; i < len; i++) {
        input[i] = input[i + (end - start) + 1];
    }
}

static void add_space(void)
{
    int input_len = strlen(input) - 1;
    int result_len = strlen(eq.results);
    for (int i = input_len + result_len; i >= start + result_len; i--) {
        input[i] = input[i - result_len];
    }
    for (int i = start; i < start + result_len; i++) {
        input[i] = '\0';
    }
}

static void insert_str(void)
{
    int j = 0;
    for (int i = start; i < start + strlen(eq.results); i++) {
        input[i] = eq.results[j++];
    }
}

void replace_str(void)
{
    check_parens();
    collapse_space();
    add_space();
    insert_str();
}
