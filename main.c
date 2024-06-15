#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100
char input[MAXLEN];

typedef struct equation{
    int count;
    int n1;
    int n2;
    char sym;
} Equation;

Equation equation;
int get_input(void);
Equation process(void);
void solve(int, int, char);


int get_input(void)
{
    printf("\nEnter your input:\n> ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("\nYour input: %s\n", input);
    } else {
        printf("Error getting input");
    }
    return 0;
}

Equation process(void)
{
    equation.count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (equation.count > 1)
            solve(equation.n1, equation.n2, equation.sym);
        if (isdigit(input[i])) {
            int num = input[i] - '0';
            if (equation.count == 0)
                equation.n1 = num;
            else if (equation.count == 1)
                equation.n2 = num;
            equation.count++;
        } else if (input[i] == '+' | input[i] == '-') {
            equation.sym = input[i];
        } else {
            printf("Invalid: %c", input[i]);
        }
        printf("[%d]: %c\n", i, input[i]);
    }
    return equation;
}

void solve(int n1, int n2, char sym)
{
    int answer;
    if (sym == '+')
        answer = n1 + n2;
    else if (sym == '-')
        answer = n1 - n2;
    printf("Answer: %d\n", answer);
    equation.n1 = answer;
    equation.n2 = 0;
    equation.count = 1;
    
}

int main(void)
{
    get_input();
    process();
    return 0;
}
