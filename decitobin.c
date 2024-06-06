#include<stdio.h>
#define ARRAY_SIZE 20  
void main()
{
int remainders[ARRAY_SIZE];
int n,i=0;
printf("Enter the Decimal Number");
scanf("%d",&n);
while(n>0 && i<ARRAY_SIZE)
{
 int remainder=n%2;
 remainders[i]=remainder;
 n=n/2;
 i++;
}
for(int j=i-1;j>=0;j--)
{
    printf("%d",remainders[j]);
}
}