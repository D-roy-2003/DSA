#include<stdio.h>
void main()
{
    int n,num,temp,rev=0,ld1,ld2;
    printf("Enter any number:");
    scanf("%d",&num);
    n=num;
    while (n>=0)
    {
      ld1=n%10;
      rev=rev*10+ld1;
      n=n/10;
    }
    temp=rev;
    while (temp>=0)
    {
    ld2=temp%10;
    if(ld2==0)
    printf("ZERO");
    else if(ld2==1)
    printf("ONE");
    else if(ld2==2)
    printf("TWO");
    else if(ld2==3)
    printf("THREE");
    else if(ld2==4)
    printf("FOUR");
    else if(ld2==5)
    printf("FIVE");
    else if(ld2==6)
    printf("SIX");
    else if(ld2==7)
    printf("SEVEN");
    else if(ld2==8)
    printf("EIGHT");
    else if(ld2==9)
    printf("NINE");
    else
    break;
    }
    
    
}
