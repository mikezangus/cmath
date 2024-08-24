#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "algebraic.h"
#include "../../utils/utils.h"
#include "../../main.h"


static void expand_string(char *destination_str, char *insertion_str, int i_insertion)
{
    int a_len = strlen(destination_str);
    int b_len = strlen(insertion_str);
    for (int i = a_len + b_len; i >= i_insertion + b_len; i--) {
        destination_str[i] = destination_str[i - b_len];
    }
}


void insert_mult(void)
{
    int i;
    for (i = 0; input[i] != 'x' && input[i] != '\0'; i++) {
        ;;
    }
    if (isdigit(input[i - 1])) {
        expand_str(input, " ", i);
        input[i] = '*';
    }
}
