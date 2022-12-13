#include <stdio.h>

int linearSearch(int arr[8]);
int binarysearch(int arr[8]);
int element;
int main(){
    int array[8]={12,24,36,48,60,72,84,96};
    printf("Enter the element you want to search\n");
    scanf("%d",&element);
    int search=linearSearch(array);
    printf("\nSearching a number using Linear Search\n");
    printf("%d is found at %d index",element,search);
    printf("\nSearching a number using Binary Search\n");
    int b_search=binarysearch(array);
    printf("\n%d is found at %d index",element,b_search);
    return 0;
}
int linearSearch(int arr[8]){
    for(int i=0;i<8;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[8]){
    int min=0;
    int max=7;
    while(min<=max) 
    {
        int mid=(max+min)/2;
        if(arr[mid]==element)
        {
          return mid;
        }
        else if(arr[mid]<element)
        {
            min=mid+1;
        }
        else if(arr[mid]>element)
        {
            max=mid-1;
        }
    }
    return -1; 
}