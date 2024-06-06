#include<stdio.h>
int main()
{
    int i,n , fact=1;
    printf("Enter Number");
    scanf("%d",&n);
    for ( i = n; i>0; i--)
    {
        /* code */
        fact=fact*i;
    }
    printf("\n Factorial=%d",fact);
    
    return 0;
}