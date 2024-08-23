#include <string.h>
#include "utils.h"

void insert_str(char *destination_str, char *insertion_str, int i_insertion)
{
    int j = 0;
    int len = strlen(insertion_str);
    for (int i = i_insertion; i < i_insertion + len; i++) {
        destination_str[i] = insertion_str[j++];
    }
}
