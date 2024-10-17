#include <stdio.h>
#include <string.h>
#include "main.h"
#include "general/general.h"

int main(void)
{
    char input[STR_MAXLEN] = {0};
    char s[STR_MAXLEN] = {0};
    printf("\nEnter input:\n> ");
    fgets(input, sizeof(input), stdin);
    strcpy(s, input);
    clean_input(s);
    enter_workflow(s);
    printf("\n\nStarting equation:\n  %s\n", input);
    printf("Solved equation:\n  %s\n", s);
    return 0;
}
