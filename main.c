#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000
char input[MAXLEN];

int get_input(void)
{
    printf("\nEnter your input:\n> ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("\nYour input via get_input():\n%s", input);
    } else {
        printf("Error getting input");
    }
    return 0;
}

typedef struct {
    int n1;
    int n2;
    char sym;
} Equation;

Equation parse_input(void)
{
    int num_count = 0;
    Equation equation;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            int num = input[i] - '0';
            if (num_count == 0)
                equation.n1 = num;
            else if (num_count == 1)
                equation.n2 = num;
            else
                printf("More than 2 numbers: %d", num);
            num_count++;
        } else if (input[i] == '+' | input[i] == '-') {
            equation.sym = input[i];
        } else {
            printf("Invalid: %c", input[i]);
        }
        printf("[%d]: %c\n", i, input[i]);
    }
    return equation;
}

int marshall(int n1, int n2, char sym)
{
    if (sym == '+')
        return n1 + n2;
    else if (sym == '-')
        return n1 - n2;
    else
        return 0;
}

int main(void)
{
    get_input();
    printf("\nYour input via main():\n%s", input);
    Equation equation = parse_input();
    int answer = marshall(equation.n1, equation.n2, equation.sym);
    printf("Answer: %d", answer);
    return 0;
}
