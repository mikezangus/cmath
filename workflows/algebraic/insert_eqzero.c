#include <string.h>

void insert_eqzero(char *s)
{
    char t[] = "=0";
    int i = strlen(s);
    for (int j = 0; t[j] != '\0'; j++) {
        s[i++] = t[j];

    }
}
