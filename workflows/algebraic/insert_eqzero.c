#include <string.h>
#include "../../utils/utils.h"

void insert_eqzero(char* s)
{
    if (!strchr(s, '=')) {
        insert_str(s, "=0", s + strlen(s));
    }
}
