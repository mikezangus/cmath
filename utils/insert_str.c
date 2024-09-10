#include <string.h>

static void expand(char* destination_str, char* insertion_str, char* insert_position)
{
    int a_len = strlen(destination_str);
    int b_len = strlen(insertion_str);
    int position_offset = insert_position - destination_str;
    for (int i = a_len + b_len; i >= position_offset + b_len; i--) {
        destination_str[i] = destination_str[i - b_len];
    }
}

static void insert(char* destination_str, char* insertion_str, char* insert_position) {
    int j = 0;
    int len = strlen(insertion_str);
    int position_offset = insert_position - destination_str;
    for (int i = position_offset; i < position_offset + len; i++) {
        destination_str[i] = insertion_str[j++];
    }
}

void insert_str(char* destination_str, char* insertion_str, char* insert_position)
{
    expand(destination_str, insertion_str, insert_position);
    insert(destination_str, insertion_str, insert_position);
}
