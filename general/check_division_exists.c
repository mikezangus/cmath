#include "../main.h"

int check_division_exists(void)
{
    for (char *p = input; *p != '\0'; p++) {
        if (*p == '/') {
            return 1;
        }
    }
    return 0;
}
