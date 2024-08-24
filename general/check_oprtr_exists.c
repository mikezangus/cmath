#include "../utils/utils.h"

int check_oprtr_exists(char *s)
{
    for (char *p = s + 1; *p != '\0'; p++) {
        if (is_oprtr(*p)) {
            return 1;
        }
    }
    return 0;
}
