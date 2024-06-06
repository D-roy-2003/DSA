#include<stdio.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
    
int arrinsert(int arr[],int size , int element ,  int capacity , int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }   
    arr[index]=element;
    return 1;
}

int arrdel(int arr[],int size, int idx)
{
    for(int i=idx; i<=size-1; i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[100] = {1,2,3,4,5};
    int size=5 , element = 10 , index = 3;
    //displaying the array before inserting an element
    display(arr, size);
    //inserting the element at a specific position in the array
    arrinsert(arr, size,element,  100 , index);
    size+=1;
    display(arr,size);
    arrdel(arr, size ,3);
    display(arr,size);
    return 0;
}

// #include<stdio.h>
 
 
// void display(int arr[], int n){
//     // Code for Traversal
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");   
// }
 
// int indInsertion(int arr[], int size, int element, int capacity, int index){
//     // code for Insertion
//     if(size>=capacity){
//         return -1;
//     }
//     for (int i = size-1; i >=index; i--)
//     {
//         arr[i+1] = arr[i];
//     }
//     arr[index] = element;
//     return 1; 
// }
 
// int main(){
//     int arr[100] = {7, 8, 12, 27, 88};
//     int size = 5, element = 45, index=1;
//     display(arr, size); 
//     indInsertion(arr, size, element, 100, index);
//     size +=1;
//     display(arr, size);
//     return 0;
// }
