#include <string.h>
#include "../../utils/utils.h"


int oprtr_exists(char *s)
{
    for (char *p = s + 1; *p != '\0'; p++) {
        if (is_oprtr(*p) && *p != '/' && *p != '^') {
            return 1;
        }
    }
    return 0;
}
