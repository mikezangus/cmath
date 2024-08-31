#include <stdio.h>
#include <string.h>

void print_str(char *m, char *s)
{
    printf("%s\n", m);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        printf("[%d] %c\n", i, s[i]);
    }
}
