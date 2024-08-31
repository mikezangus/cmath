#include "algebraic.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../../main.h"


void remove_plus0(void)
{
    if (input[0] == '0' && input[1] == '+') {
        collapse_str(input, 0, 1);
    }
}