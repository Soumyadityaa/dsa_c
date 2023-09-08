#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0; // Lower precedence for non-operators
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Initialize stacks
    char operatorStack[MAX_SIZE];
    int top = -1;
    char outputStack[MAX_SIZE];
    int outputTop = -1;

    // Reverse the infix expression
    strrev(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ')
            continue;

        if (isOperator(infix[i])) {
            while (top != -1 && precedence(operatorStack[top]) >= precedence(infix[i])) {
                outputStack[++outputTop] = operatorStack[top--];
            }
            operatorStack[++top] = infix[i];
        } else if (infix[i] == ')') {
            operatorStack[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (top != -1 && operatorStack[top] != ')') {
                outputStack[++outputTop] = operatorStack[top--];
            }
            if (top != -1) {
                top--; // Pop the closing parenthesis
            }
        } else {
            // Operand
            int j = i;
            while (infix[j] != ' ' && infix[j] != '\0') {
                outputStack[++outputTop] = infix[j++];
            }
            i = j - 1; // Update i to the last digit of the operand
        }
    }

    // Pop any remaining operators from the operator stack
    while (top != -1) {
        outputStack[++outputTop] = operatorStack[top--];
    }

    // Reverse the output stack to get the prefix expression
    for (int i = outputTop; i >= 0; i--) {
        prefix[outputTop - i] = outputStack[i];
    }
    prefix[outputTop + 1] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
