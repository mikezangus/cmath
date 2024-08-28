#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

int l_special;
int r_special;

static int is_between_digits(int i)
{
    l_special = r_special = 0;
    int l = input[i - 1];
    int r = input[i + 1];
    if (!isdigit(l) && !isdigit(r)) {
        return 0;
    }
    if (isdigit(l)) {
        /* eg 1*(1+1) */
        r_special = !isdigit(r);
    }
    if (isdigit(r)) {
        /* eg (1+1)*1 */
        l_special = !isdigit(l);
    }
    return 1;
}

static void weigh(int i, int *scale)
{
    if (input[i] == '(') {
        (*scale)++;
    } else if (input[i] == ')') {
        (*scale)--;
    }
}

static int handle_l_special(int start)
{
    int scale = 0;
    for (int i = start - 1; input[i] != '\0'; i--) {
        weigh(i, &scale);
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

static int handle_r_special(int start)
{
    int scale = 0;
    for (int i = start + 1; input[i] != '\0'; i++) {
        weigh(i, &scale);
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

static int find_l_digit(int i)
{
    if (l_special) {
        return handle_l_special(i);
    } else {
        int j;
        for (j = i - 1; isdigit(input[j]); j--) {
            ;;
        }
        return j + 1;
    }
}

static int find_r_digit(int i)
{
    if (r_special) {
        return handle_r_special(i);
    } else {
        int j;
        for (j = i + 1; isdigit(input[j]); j++) {
            ;;
        }
        return j - 1;
    }
}

static void add_paren(int i, char p)
{
    if (p != '(' && p != ')') {
        return;
    }
    expand_str(input, " ", i);
    input[i] = p;
}

static int sequence(int *i)
{
    if (!is_between_digits(*i)) {
        return 0;
    }
    int i_l_digit = find_l_digit(*i);
    int i_r_digit = find_r_digit(*i);
    add_paren(i_l_digit, '(');
    add_paren(i_r_digit + 2, ')');
    printf("New input: %s\n", input);
    (*i)++;
    return 1;
}

static void print_status(char p, int i)
{
    printf(
        "\nPrecedent %c [%d/%lu] | %c\nStarting input: %s\n",
        p, i + 1, strlen(input), input[i], input
    );
}

void add_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        print_status('1', i);
        if (is_prec1_oprtr(input[i])) {
            sequence(&i);
        } else {
            printf("No changes\n");
        }
    }
    for (int i = 0; input[i] != '\0'; i++) {
        print_status('2', i);
        if (input[i] == '*') {
            sequence(&i);
        } else {
            printf("No changes\n");
        }
    }
    printf("\nFinal input: %s\n", input);
}
