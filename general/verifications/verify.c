#include "verifications.h"

int verify(char *s)
{
    return (!oprtr_exists(s) || !parens_balanced(s)) ? 0 : 1;
}
