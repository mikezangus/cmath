#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "parsing.h"
#include "../general.h"
#include "../../main.h"
#include "../../utils/utils.h"

static char* parse_oprtr(char* start, char* end)
{
    for (char* p = start; *p && p <= end; p++) {
        if (is_oprtr(*p)) {
            return p;
        }
    }
    return NULL;
}

static void parse_oprnd(char* start, char* end, char* out)
{
    for (char* p = start; *p && p <= end; p++, out++) {
        *out = *p;
    }
    *out = '\0';
}

static void parse_operation(char* left, char* right, char* op1, char* oprtr, char* op2)
{
    char* p_oprtr = parse_oprtr(left, right);
    *oprtr = *p_oprtr;
    parse_oprnd(left, p_oprtr - 1, op1);
    parse_oprnd(p_oprtr + 1, right, op2);
}

bool parse_equation(char* s, char** left, char** right, char* op1n, char* op1d, char* oprtr, char* op2n, char* op2d)
{
    char* temp1_left = NULL;
    char* temp1_right = NULL;
    char temp1_op1[STR_MAXLEN] = {0};
    char temp1_oprtr[2] = {0};
    char temp1_op2[STR_MAXLEN] = {0};
    if (!find_bounds(s, &temp1_left, &temp1_right)) {
        fprintf(stderr, "Failed to find bounds: %s\n", s);
        return false;
    }
    parse_operation(temp1_left, temp1_right, temp1_op1, temp1_oprtr, temp1_op2);
    printf("Parsed 1: %s%s%s\n", temp1_op1, temp1_oprtr, temp1_op2);
    if (equation_is_operable(temp1_op1, temp1_oprtr, temp1_op2)) {
        printf("Equation 1 is operable. Exiting\n");
        return true;
    }


    char* temp2_left = NULL;
    char* temp2_right = NULL;
    char temp2_op1[STR_MAXLEN] = {0};
    char temp2_oprtr[2] = {0};
    char temp2_op2[STR_MAXLEN] = {0};
    char* ptr_temp_oprtr = find_oprtr(temp1_right + 1, NULL);
    if (!find_bounds(ptr_temp_oprtr + 1, &temp2_left, &temp2_right)) {
        fprintf(stderr, "Failed to find bounds: %s\n", s);
        return false;
    }

    parse_operation(temp2_left, temp2_right, temp2_op1, temp2_oprtr, temp2_op2);
    printf("Parsed 2: %s%s%s\n", temp2_op1, temp2_oprtr, temp2_op2);
    if (equation_is_operable(temp2_op1, temp2_oprtr, temp2_op2)) {
        printf("Equation 2 is operable. Exiting\n");
        return true;
    }

    printf("op1n: %s\n", op1n);
    printf("temp1_op1: %s\n", temp1_op1);
    printf("temp1_oprtr: %s\n", temp1_oprtr);
    printf("temp1_op2: %s\n", temp1_op2);
    strcpy(op1n, temp1_op1);
    strcat(op1n, temp1_oprtr);
    strcat(op1n, temp1_op2);

    printf("oprtr: %s\n", oprtr);
    printf("*ptr_temp_oprtr: %c\n", *ptr_temp_oprtr);
    oprtr[0] = *ptr_temp_oprtr;
    oprtr[1] = '\0';

    printf("op2n: %s\n", op2n);
    printf("temp2_op1: %s\n", temp2_op1);
    printf("temp2_oprtr: %s\n", temp2_oprtr);
    printf("temp2_op2: %s\n", temp2_op2);
    strcpy(op2n, temp2_op1);
    strcat(op2n, temp2_oprtr);
    strcat(op2n, temp2_op2);

    printf("PARSED:\n  %s\n  %s\n  %s\n", op1n, oprtr, op2n);
    return false;
}
