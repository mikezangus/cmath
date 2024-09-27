#include <stdbool.h>
#include "verifications.h"

bool verify(char* s)
{
    return (oprtr_exists(s) && parens_balanced(s));
}
