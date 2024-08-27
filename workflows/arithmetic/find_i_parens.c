#include "../../main.h"
#include "arithmetic.h"
#include "../../general/general.h"
#include "../../utils/utils.h"
#include <ctype.h>
#include "stdio.h"
#include <string.h>

static int find_i_l_paren(int start)
{
    for (int i = start; i >= 0; i--) {
        if (input[i] == '(') {
            return i;
        }
    }
    return -1;
}

void find_i_parens(void)
{
    int i_l_paren = -1;
    int i_r_paren = -1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '/' && input[i - 1] == ')') {
            i_r_paren = i - 1;
            i_l_paren = find_i_l_paren(i_r_paren);
            sequence(i_l_paren + 1, i_r_paren - 1);
            printf("\n\nInput after sequence: %s\n\n", input);
            parse_denoms(i_l_paren + 1, i_r_paren - 1);
        }
    }
    printf("Parens:\nL: %d | R: %d\n", i_l_paren, i_r_paren);
}
