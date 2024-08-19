#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

extern char input[];

int l_digit;
int r_digit;
bool l_special;
bool r_special;

static void init(void)
{
    l_digit = r_digit = 0;
    l_special = r_special = false;
}

static bool check_surroundings(int pos)
{
    if (!isdigit(input[pos - 1]) && !isdigit(input[pos + 1])) {
        return false;
    } else if (isdigit(input[pos - 1]) && !isdigit(input[pos + 1])) {
        r_special = true;
    } else if (!isdigit(input[pos - 1]) && isdigit(input[pos + 1])) {
        l_special = true;
    }
    return true;
}

static int handle_l_special(int start)
{
    int scale = 0;
    for (int i = start - 1; input[i]  != '\0'; i--) {
        if (input[i] == '(') {
            scale++;
        } else if (input[i] == ')') {
            scale--;
        }
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
        if (input[i] == '(') {
            scale++;
        } else if (input[i] == ')') {
            scale--;
        }
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

static void find_l_digit(int pos)
{
    if (l_special) {
        l_digit = handle_l_special(pos);
    } else {
        int i;
        for (i = pos - 1; isdigit(input[i]); i--) {
            ;;
        }
        l_digit = i + 1;
    }

}

static void find_r_digit(int pos)
{
    if (r_special) {
        r_digit = handle_r_special(pos);
    } else {
        int i;
        for (i = pos + 1; isdigit(input[i]); i++) {
            ;;
        }
        r_digit = i - 1;
    }
}

static bool check_parens(int l, int r)
{
    if (input[l - 1 == '('] && input[r + 1] == ')') {
        return false;
    }
    return true;
}

static void add_paren(int pos, char type)
{
    if (type != '(' && type != ')') {
        return;
    }
    int start = strlen(input) + 1;
    for (int i = start; i >= pos; i--) {
        input[i] = input[i - 1];
    }
    input[pos] = type;
}

static bool sequence(int i)
{
    init();
    if (!check_surroundings(i)) {
        return false;
    }
    find_l_digit(i);
    find_r_digit(i);
    if (!check_parens(l_digit, r_digit)) {
        return false;
    }
    add_paren(l_digit, '(');
    add_paren(r_digit + 2, ')');
    printf("New input: %s\n", input);
    return true;
}

void add_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        printf(
            "\n\nPrecedent 1 [%d/%lu] | %c\nStarting input: %s\n",
            i + 1, strlen(input), input[i], input
        );
        if (is_prec1_oprtr(input[i])) {
            if (sequence(i)) {
                i++;
            }
            continue;
        } else {
            printf("No changes\n");
        }
    }
    for (int i = 0; input[i] != '\0'; i++) {
        printf(
            "\n\nPrecedent 2 [%d/%lu] | %c\nStarting input: %s\n",
            i + 1, strlen(input), input[i], input
        );
        if (is_prec2_oprtr(input[i])) {
            if (sequence(i)) {
                i++;
            }
            continue;
        } else {
            printf("No changes\n");
        }
    }
    printf("\n\n\nFinal input: %s\n", input);
}
