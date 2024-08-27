#include <ctype.h>
#include <string.h>
#include "../../main.h"
#include "../../utils/utils.h"
#include "algebraic.h"
#include <stdio.h>

int parens_exist;

static int check_parens_exist()
{
    for (char *p = input; *p != '\0'; p++) {
        if (*p == '(') {
            return 1;
        }
    }
    return 0;
}

static int weigh(int *scale)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            (*scale)++;
        } else if (input[i] == ')') {
            (*scale)--;
        }
        if (*scale == 0) {
            return i;
        }
    }
    return -1;
}

static int find_first_digit(int start, int end)
{
    for (int i = start; i < end; i++) {
        if (isdigit(input[i])) {
            return i;
        }
    }
    return -1;
}

static int find_second_oprtr(int start, int end)
{
    int cnt = 0;
    int i;
    if (parens_exist) {
        start += 2;
    }
    for (i = start; input[i] != '\0' && i <= end; i++) {
        printf("[%d] %c\n", i, input[i]);
        if (is_oprtr(input[i])) {
            printf("%d oprtr #%d\n", i, cnt + 1);
            cnt++;
            if (cnt > 1) {
                return i - 1;
            }
        }
    }
    printf("No op2 found\n");
    return end + 1;
}

static void left_of_eqsign(int i_eqsign)
{
    int scale = 0;
    int start = weigh(&scale);
    bounds.l = find_first_digit(start, i_eqsign);
    bounds.r = find_second_oprtr(start, i_eqsign);
}

static void right_of_eqsign(int i_eqsign)
{
    bounds.l = find_first_digit(i_eqsign, strlen(input));
    bounds.r = find_second_oprtr(i_eqsign + 2, strlen(input));
}

void find_bounds_alg(char c)
{
    parens_exist = check_parens_exist();
    if (c == 'l') {
        left_of_eqsign(i_eqsign);
    } else if (c == 'r') {
        right_of_eqsign(i_eqsign);
    }
    print_str("", input);
    printf("BOUNDS - L: %d | R: %d\n", bounds.l, bounds.r);
}
