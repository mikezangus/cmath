#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 100
char input[MAXLEN];

void get_input(void)
{
    printf("\nEnter your input:\n> ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("\nYour input: %s\n", input);
    } else {
        printf("Error getting input\n");
    }
}

struct {
    char n1[MAXLEN];
    char n2[MAXLEN];
    int n1_count;
    int n2_count;
    char sign;
    double dn1;
    double dn2;
    double result;
} equation;

void separate(void)
{
    equation.n1_count = 0;
    equation.n2_count = 0;
    equation.sign = '0';
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            if (equation.sign == '0') {
                equation.n1[equation.n1_count] = input[i];
                equation.n1_count++;
            } else {
                equation.n2[equation.n2_count] = input[i];
                equation.n2_count++;
            }
        } else if (input[i] == '+' || input[i] == '-') {
            equation.sign = input[i];
        }
    }
    printf("\nn1: ");
    for (int i = 0; equation.n1[i] != '\0'; i++)
        printf("%c", equation.n1[i]);
    printf("\nn2: ");
    for (int i = 0; equation.n2[i] != '\0'; i++)
        printf("%c", equation.n2[i]);
    printf("\nsign: %c\n", equation.sign);
}

void convert(void)
{
    int len1, len2;
    for (len1 = 0; isdigit(equation.n1[len1]); len1++)
        ;;
    for (len2 = 0; isdigit(equation.n2[len2]); len2++)
        ;;
    for (int i = 0; isdigit(equation.n1[i]); i++) {
        equation.dn1 += (equation.n1[i] - '0') * (1 * pow(10, len1 - 1 - i));
    }
    for (int i = 0; isdigit(equation.n2[i]); i++) {
        equation.dn2 += (equation.n2[i] - '0') * (1 * pow(10, len2 - 1 - i));
    }
    printf("N1: %f\n", equation.dn1);
    printf("N2: %f\n", equation.dn2);
}

void calculate(void)
{
    equation.result = 0;
    if (equation.sign == '+') {
        equation.result = equation.dn1 + equation.dn2;
    } else if (equation.sign == '-') {
        equation.result = equation.dn1 - equation.dn2;
    }
}


int main(void)
{
    get_input();
    separate();
    convert();
    calculate();
    printf("Result: %f\n", equation.result);
    return 0;
}
