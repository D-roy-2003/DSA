#include<stdio.h>
void main()
{
    int *ptr,a=10;
    // printf("Enter A");
    // scanf("%d",&a);
     ptr=&a;
    // *ptr+=1;
    printf("\n Value of ptr=%d and val of A=%d",*ptr,a);
    printf("\n add of a=%u",ptr);
    printf("\n add of a=%u",&a);
    printf("\n val a=%u",*ptr);
    printf("\n val of a=%u",ptr);
}