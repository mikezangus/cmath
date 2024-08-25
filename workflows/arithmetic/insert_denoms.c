#include "../../main.h"
#include "../../general/general.h"
#include "../../utils/utils.h"
#include <ctype.h>
#include "stdio.h"

int i_first_digit;
int i_last_digit;

static void init(void)
{
    i_first_digit = i_last_digit = -1;
}

static int find_first_digit(int start)
{
    for (int i = start; !is_oprtr(input[i]) && input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            return i;
        }
    }
    return -1;
}

static int find_last_digit(int start)
{
    int i;
    for (i = start; !is_oprtr(input[i]) && input[i] != '\0'; i++) {
        ;;
    }
    return i - 1;
}

static void insert_denom(int *i, int i_insertion)
{
    expand_str(input, "/1", i_insertion);
    insert_str(input, "/1", i_insertion);
    (*i) = (i_insertion + 2);
}

void insert_denoms(void)
{
    init();
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_oprtr(input[i])) {
            init();
            continue;
        }
        if (i_first_digit < 0) {
            i_first_digit = find_first_digit(i);
        }
        if (i_last_digit < 0 && i_first_digit > -1) {
            i_last_digit = find_last_digit(i_first_digit);
        }
        if (input[i_first_digit - 1] != '/' && input[i_last_digit + 1] != '/') {
            insert_denom(&i, i_last_digit + 1);
            init();
            continue;
        }
    }
}
