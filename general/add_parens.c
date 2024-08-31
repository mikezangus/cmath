#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

int l_special;
int r_special;

static int is_between_digits(char *s, int i)
{
    l_special = r_special = 0;
    int l = s[i - 1];
    int r = s[i + 1];
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

static void weigh(char *s, int i, int *scale)
{
    if (s[i] == '(') {
        (*scale)++;
    } else if (s[i] == ')') {
        (*scale)--;
    }
}

static int handle_l_special(char *s, int start)
{
    int scale = 0;
    for (int i = start - 1; s[i] != '\0'; i--) {
        weigh(s, i, &scale);
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

static int handle_r_special(char *s, int start)
{
    int scale = 0;
    for (int i = start + 1; s[i] != '\0'; i++) {
        weigh(s, i, &scale);
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

static int find_l_digit(char *s, int i)
{
    if (l_special) {
        return handle_l_special(s, i);
    } else {
        int j;
        for (j = i - 1; isdigit(s[j]); j--) {
            ;;
        }
        return j + 1;
    }
}

static int find_r_digit(char *s, int i)
{
    if (r_special) {
        return handle_r_special(s, i);
    } else {
        int j;
        for (j = i + 1; isdigit(s[j]); j++) {
            ;;
        }
        return j - 1;
    }
}

static void add_paren(char *s, int i, char p)
{
    if (p != '(' && p != ')') {
        return;
    }
    insert_str(s, " ", i);
    s[i] = p;
}

static int sequence(char *s, int *i)
{
    if (!is_between_digits(s, *i)) {
        return 0;
    }
    int i_l_digit = find_l_digit(s, *i);
    int i_r_digit = find_r_digit(s, *i);
    add_paren(s, i_l_digit, '(');
    add_paren(s, i_r_digit + 2, ')');
    printf("New input: %s\n", s);
    (*i)++;
    return 1;
}

static void print_status(char *s, char p, int i)
{
    printf(
        "\nPrecedent %c [%d/%lu] | %c\nStarting input: %s\n",
        p, i + 1, strlen(s), s[i], s
    );
}

void add_parens(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        print_status(s, '1', i);
        if (is_prec1_oprtr(s[i])) {
            sequence(s, &i);
        } else {
            printf("No changes\n");
        }
    }
    for (int i = 0; s[i] != '\0'; i++) {
        print_status(s, '2', i);
        if (s[i] == '*') {
            sequence(s, &i);
        } else {
            printf("No changes\n");
        }
    }
    printf("\nFinal input: %s\n", s);
}
