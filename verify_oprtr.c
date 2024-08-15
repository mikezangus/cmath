#include <stdbool.h>
#include <string.h>
#include "header.h"

extern char input[];

bool verify_oprtr(void)
{
    for (int i = 1; i < strlen(input); i++) {
        if (is_oprtr(input[i])) {
            return true;
        }
    }
    return false;
}
