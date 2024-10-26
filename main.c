#include <stdio.h>
#include <string.h>
#include "main.h"
#include "formatting/formatting.h"

static void process(char* input, char* s)
{
    printf("\n%s\n\n", DASHES);
    printf("\nInput: %s\n", input);
    strcpy(s, input);
    clean_input(s);
    enter_workflow(s);
    remove_unneeded_parens(s);
    printf("\n\nStarting equation:\n  %s\n", input);
    printf("Solved equation:\n  %s\n\n%s\n", s, DASHES);
}

static void terminal_input()
{
    char input[STR_MAXLEN] = {0};
    char s[STR_MAXLEN] = {0};
    printf("\nEnter input:\n> ");
    fgets(input, sizeof(input), stdin);
    process(input, s);
}

static void file_input()
{
    char input[STR_MAXLEN] = {0};
    char s[STR_MAXLEN] = {0};
    FILE* file = fopen("tests/tests4.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to load file\n");
        return;
    }
    while (fgets(input, sizeof(input), file)) {
        input[strcspn(input, "\n")] = 0;
        process(input, s);
    }
    fclose(file);
}

int main(void)
{
    printf("\nGet input from\n [1] Terminal\n [2] File\n> ");
    char flow = getchar();
    getchar();
    switch (flow) {
        case '1': terminal_input(); break;
        case '2': file_input(); break;
        default: printf("Invalid choice\n"); return main();
    }
    return 0;
}
