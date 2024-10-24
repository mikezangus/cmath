#include <stdio.h>
#include "../formatting.h"

void format_neg_frctn(char* num, char* den)
{
    char *n = (*num == '-') ? num : NULL;
    char* d = (*den == '-') ? den : NULL;
    if (!n && !d) {
        return;
    }
    if (n && d) {
        collapse_str(n, n);
        collapse_str(d, d);
        return;
    }
    if (d) {
        collapse_str(d, d);
        insert_str(num, "-", num);
        return;
    }
}
