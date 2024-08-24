#include "algebraic.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../../main.h"

void remove_x1(void)
{
    for (int i = 0; i <= i_eqsign; i++) {
        if (input[i] == '*' && input[i + 1] == '1') {
            collapse_str(input, i, i + 1);
        }
        if (input[i] == '*' && input[i - 1] == '1') {
            collapse_str(input, i - 1, i);
        }
    }
}