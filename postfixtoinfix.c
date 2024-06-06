#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr) {
    if (ptr->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char* postfixToInfix(char* postfix) {
    struct stack *sp = (struct stack*) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char*) malloc(sp->size * sizeof(char));
    char *infix = (char*) malloc((strlen(postfix) + 1) * sizeof(char));
    int i = 0; // Track postfix traversal
    int j = 0; // Track infix addition
    while (postfix[i] != '\0') {
        if (!isOperator(postfix[i])) {
            infix[j] = postfix[i];
            j++;
            i++;
        } else {
            char op1 = pop(sp);
            char op2 = pop(sp);
            infix[j] = '(';
            j++;
            infix[j] = op2;
            j++;
            infix[j] = ' ';
            j++;
            infix[j] = postfix[i];
            j++;
            infix[j] = ' ';
            j++;
            infix[j] = op1;
            j++;
            infix[j] = ')';
            j++;
            i++;
        }
    }
    infix[j] = '\0';
    return infix;
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int main() {
    char *postfix = "ab+cd*";
    printf("Infix is %s", postfixToInfix(postfix));
    return 0;
}