#include "../main.h"
#include "../utils/utils.h"

int check_oprtr_exists(void)
{
    for (char *p = input + 1; *p != '\0'; p++) {
        if (is_oprtr(*p) && *p != '/') {
            return 1;
        }
    }
    return 0;
}
