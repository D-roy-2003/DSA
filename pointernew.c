#include<stdio.h>
int main()
{
    int num=45;
    int *ptr= &num;
    printf("\nValue of num=%d",num);
    printf("\nAddress of num=%p",&num);
    printf("\nValue of pointer=%d",ptr);
    printf("\nValue of pointer=%u",ptr);
    printf("\nValue of pointer=%p",ptr);
    printf("\nvalue at pointer=%d",*ptr);
}