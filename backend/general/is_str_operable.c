#include <stdbool.h>
#include <string.h>
#include "../utils/utils.h"

bool is_str_operable(char* s)
{
    return is_oprtr_in_str(s) && (get_paren_depth(s, s + strlen(s)) == 0);
}
