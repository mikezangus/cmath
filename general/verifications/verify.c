#include "verifications.h"

int verify(char *s)
{
    if (!oprtr_exists(s) || !parens_balanced(s)) {
        return 0;
    }
    return 1;
}
