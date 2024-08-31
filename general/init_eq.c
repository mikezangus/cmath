#include <string.h>
#include "../main.h"

void init_eq(void)
{
    memset(eq.op1ns, '\0', NUM_MAXLEN);
    memset(eq.op1ds, '\0', NUM_MAXLEN);
    eq.oprtr = '\0';
    memset(eq.op2ns, '\0', NUM_MAXLEN);
    memset(eq.op2ds, '\0', NUM_MAXLEN);
    eq.op1nd = 0.0;
    eq.op1dd = 0.0;
    eq.op2nd = 0.0;
    eq.op2dd = 0.0;
    eq.resultnd = 0.0;
    eq.resultdd = 0.0;
    memset(eq.resultns, '\0', NUM_MAXLEN);
    memset(eq.resultds, '\0', NUM_MAXLEN);
    memset(eq.results, '\0', STR_MAXLEN);
}
