#include <stdio.h>

void print_str(char m[], char s[])
{
    printf("\n%s\n", m);
    int len = strlen(s);
    for (int i = 0; i <= len; i++) {
        printf("[%d] %c\n", i, s[i]);
    }
}
