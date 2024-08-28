#include <string.h>
#include "../main.h"

void init_eq(void)
{
    memset(eq.op1ns, '\0', MAXLEN);
    memset(eq.op1ds, '\0', MAXLEN);
    memset(eq.op2ns, '\0', MAXLEN);
    memset(eq.op2ds, '\0', MAXLEN);
    memset(eq.resultns, '\0', MAXLEN);
    memset(eq.resultds, '\0', MAXLEN);
    memset(eq.results, '\0', MAXLEN);
    eq.oprtr = '\0';
    eq.op1nd = eq.op1dd = 0.0;
    eq.op2nd = eq.op2dd = 0.0;
    eq.resultnd = eq.resultdd = 0.0;
}
