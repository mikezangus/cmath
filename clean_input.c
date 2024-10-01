#include <string.h>

static void remove_spaces(char* s)
{
    char* p1 = s;
    char* p2 = s;
    while (*p1 != '\0') {
        if (*p1 != ' ') {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    *p2 = '\0';
}

static void terminate_newline(char* s)
{
    char* n = strchr(s, '\n');
    n ? *n = '\0' : (void)0;
}

void clean_input(char* s)
{
    remove_spaces(s);
    terminate_newline(s);
}
