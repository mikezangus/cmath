#include "../../main.h"
#include "../../general/general.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../utils/utils.h"
#include "algebraic.h"


#include "../../general/parsing/parsing.h"

void solve_alg(char* s)
{
    printf("\n\nStart of solve loop: %s\n", s);
    parse_equation(s, &bounds.l, &bounds.r, eq.op1ns, eq.op1ds, &eq.oprtr, eq.op2ns, eq.op2ds);
    printf("Parsed: %s %c %s\n", eq.op1ns, eq.oprtr, eq.op2ns);
}

