#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Pop '(' from stack
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

void infix_to_prefix(char infix[], char prefix[]) {
    char reversed_infix[MAX_SIZE];
    char reversed_postfix[MAX_SIZE];

    int len = strlen(infix);
    int i, j;

    // Reverse the infix expression
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        if (infix[i] == '(')
            reversed_infix[j] = ')';
        else if (infix[i] == ')')
            reversed_infix[j] = '(';
        else
            reversed_infix[j] = infix[i];
    }
    reversed_infix[j] = '\0';

    // Convert reversed infix to reversed postfix
    infix_to_postfix(reversed_infix, reversed_postfix);

    // Reverse the postfix expression to get the prefix expression
    len = strlen(reversed_postfix);
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        prefix[j] = reversed_postfix[i];
    }
    prefix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    gets(infix);

    infix_to_prefix(infix, prefix);
    // infix_to_postfix(infix,prefix);


    printf("Infix Expression: %s\n", infix);
    printf("Prefix Expression: %s\n", prefix);
    // printf("Postfix Expression: %s\n", prefix);
    return 0;
}

