#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char ch) {
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

int is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void postfix_to_infix(char postfix[], char infix[]) {
    Stack stack;
    initialize(&stack);

    int len = strlen(postfix);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (is_operand(postfix[i])) {
            push(&stack, postfix[i]);
        } else {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);
            infix[j++] = '(';
            infix[j++] = operand1;
            infix[j++] = postfix[i];
            infix[j++] = operand2;
            infix[j++] = ')';
        }
    }

    infix[j] = '\0';
}

int main() {
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE];

    printf("Enter postfix expression: ");
    gets(postfix);

    postfix_to_infix(postfix, infix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Infix Expression: %s\n", infix);

    return 0;
}
