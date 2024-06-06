#include <stdio.h>
int main()
{
	int i,j,temp;
	int a[5]={5,3,4,6,1};
	for(i=0;i<5-1;i++)
	{
		for(j=0;j<5-1-i;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	}
	for(i=0;i<5;i++)
	printf("\n %d",a[i]);
	return 0;
}