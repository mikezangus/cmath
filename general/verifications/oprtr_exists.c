#include <stdbool.h>
#include "../../utils/utils.h"

bool oprtr_exists(char* s)
{
    for (char* p = s + 1; *p; p++) {
        if (is_oprtr(*p) && *p != '/' && *p != '^') {
            return true;
        }
    }
    return false;
}
