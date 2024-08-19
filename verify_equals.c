#include "header.h"
#include <stdbool.h>

extern char input[];

bool verify_equals(void)
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '=') {
            count++;
            if (count > 1) {
                return false;
            }
        }
    }
    return true;
}
