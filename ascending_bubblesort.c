
#include<stdio.h>
int main()
{
    int n,i,j,temp;
    // printf("Enter the range:\n");
    // scanf("%d",&n);
    n=5;
    int num[n];
    printf("Enter %d numbers in an array:\n",n);
     for(i=0;i<n;i++)
     {
       scanf("%d",&num[i]);
     }
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
      {
       if(num[j]>num[j+1])
       {
          temp=num[j];  //Array swapping
          num[j]=num[j+1];
          num[j+1]=temp;
       }
      }
    }
      for(i=0;i<n;i++)
        printf("\n % d",num[i]);
      return 0;
}



