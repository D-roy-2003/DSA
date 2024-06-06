#include<stdio.h>

int linearsearch(int arr[],int element,int size)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==element);
        return i;
    }
    return -1; //return -1 to indicate that the element is not in array
}

int binarysearch(int arr[], int element, int size)
{
    int low,mid,high;
    low=0;
    high=size-1;
      // (&& element != arr[mid]) we can write "element!=arr[mid]" instead of
    //"element!=arr[high]" because when middle element is greater than
    //the search element then there will be no element on the left side so  
    //we need to check only till high otherwise it may go out of boundry
    while(low<=high )
    {
        mid=(low+high)/2;  //integer division
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    // if (low > high) //if low becomes more than high then the element is not present in the list
    // return -1; //so we return -1 indicating that the element is not
    // //present in the array
    // else
    return -1;//else we return position of the element
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);
    int element=6;
    int searchidx = binarysearch(arr,element,size);
    printf("Element %d found at index %d\n",element,searchidx);
    return 0;

}