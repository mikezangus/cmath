#include <string.h>
#include "utils.h"

void expand_str(char *destination_str, char *insertion_str, int i_insertion)
{
    int a_len = strlen(destination_str);
    int b_len = strlen(insertion_str);
    for (int i = a_len + b_len; i >= i_insertion + b_len; i--) {
        destination_str[i] = destination_str[i - b_len];
    }
}
