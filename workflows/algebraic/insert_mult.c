#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../../utils/utils.h"


void expand_str(char *destination_str, char *insertion_str, int i_insertion)
{
    int a_len = strlen(destination_str);
    int b_len = strlen(insertion_str);
    for (int i = a_len + b_len; i >= i_insertion + b_len; i--) {
        destination_str[i] = destination_str[i - b_len];
    }
}


void insert_mult(char *s)
{
    int i;
    for (i = 0; s[i] != 'x' && s[i] != '\0'; i++) {
        ;;
    }
    if (isdigit(s[i - 1])) {
        expand_str(s, " ", i);
        s[i] = '*';
    }
}

int main(void)
{
    char input[100] = "2+1x-1-1";
    insert_mult(input);
    printf("Input: %s\n", input);

}