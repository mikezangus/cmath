#include <ctype.h>
#include "header.h"

void convert(void)
{
    eq.n1d = 0.0;
    eq.n2d = 0.0;
    for (int i = 0; i < eq.n1c_cnt; i++)
        eq.n1d = eq.n1d * 10 + (eq.n1c[i] - '0');
    for (int i = 0; i < eq.n2c_cnt; i++)
        eq.n2d = eq.n2d * 10 + (eq.n2c[i] - '0');
}
