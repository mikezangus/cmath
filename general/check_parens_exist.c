#include "../main.h"

int check_parens_exist(void)
{
    int l = 0;
    for (char *p = input; *p != '\0'; p++) {
        if (*p == '(') {
            l = 1;
        }
        if (*p == ')' && l) {
            return 1;
        }
    }
    return 0;
}
