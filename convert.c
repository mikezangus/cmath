#include <ctype.h>
#include <math.h>
#include "header.h"

void convert(void)
{
    int len1, len2;
    for (len1 = 0; isdigit(eq.n1c[len1]); len1++)
        ;;
    for (len2 = 0; isdigit(eq.n2c[len2]); len2++)
        ;;
    for (int i = 0; isdigit(eq.n1c[i]); i++)
        eq.n1d += (eq.n1c[i] - '0') * (1 * pow(10, len1 - i - 1));
    for (int i = 0; isdigit(eq.n2c[i]); i++)
        eq.n2d += (eq.n2c[i] - '0') * (1 * pow(10, len2 - i - 1));
}