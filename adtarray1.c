#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int true_size;
    int used_size;
    int *ptr;
};

void create_array(struct myarray *a , int t_size, int u_size)
{
    a->true_size=t_size;
    a->used_size=u_size;
    a->ptr=(int *)malloc(t_size * sizeof(int));
}

void show(struct myarray *a)
{
    for ( int i = 0; i <a->used_size; i++)
    {
        printf("%d ",(a->ptr)[i]);
    }
}

void set_array(struct myarray *a)
{
    int n;
    for ( int i = 0; i <a->used_size; i++)
   {
    printf("Enter Element %d\n",i);
    scanf("%d",&n);
    (a->ptr)[i]=n;
   }
    
}

int main()
{   
    struct myarray marks;
    create_array(&marks,10,2);
    printf("We are running create_array now\n");
    set_array(&marks);
    printf("We are running show now\n");
    show(&marks);
    return 0;
}