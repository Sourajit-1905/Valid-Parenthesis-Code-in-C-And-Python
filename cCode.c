#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int matchedParenthesis(char opening, char closing)
{
    if ((opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']'))
        return 1;

    return 0;
}

int parenthesisMatch(char *exp)
{
    int len = strlen(exp);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1;

    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            stack[++top] = exp[i];
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
                return 0;

            popped_ch = stack[top--];
            if (!matchedParenthesis(popped_ch, exp[i]))
                return 0;
        }
    }

    free(stack);
    return top == -1 ? 1 : 0;
}

int main()
{
    char expression[100];

    printf("Enter an expression with parentheses: ");
    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    if (parenthesisMatch(expression))
        printf("The parentheses are balanced.\n");
    else
        printf("The parentheses are NOT balanced.\n");

    return 0;
}