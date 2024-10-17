#include <stdbool.h>
#include <string.h>
#include "../utils/utils.h"

bool is_str_operable(char* s)
{
    return is_oprtr_in_str(s) && is_paren_depth_same(s, s + strlen(s));
}
