#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val)
{
    if(isFull(ptr))
        printf("\nStack Overflow %d can't be entered",&val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("\nStack Underflow, can't delete any element");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
        
    }
}

void display(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("\n The stack is empty");
    }
    else
    {
        for(int i=0; i<=ptr->top; i++)
        {
            printf("\n %d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    
    
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    push(sp,80);
    push(sp,90);
    push(sp,100);
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    display(sp);
    printf("%d popped from the stack\n",pop(sp));
    printf("%d popped from the stack\n",pop(sp));
    display(sp);
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    return 0;
}
