#include <string.h>

static void expand(char *destination_str, char *insertion_str, int i_insertion)
{
    int a_len = strlen(destination_str);
    int b_len = strlen(insertion_str);
    for (int i = a_len + b_len; i >= i_insertion + b_len; i--) {
        destination_str[i] = destination_str[i - b_len];
    }
}

static void insert(char *destination_str, char *insertion_str, int i_insertion) {
    int j = 0;
    int len = strlen(insertion_str);
    for (int i = i_insertion; i < i_insertion + len; i++) {
        destination_str[i] = insertion_str[j++];
    }
}

void insert_str(char *destination_str, char *insertion_str, int i_insertion)
{
    expand(destination_str, insertion_str, i_insertion);
    insert(destination_str, insertion_str, i_insertion);
}
