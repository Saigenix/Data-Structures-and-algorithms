#include<stdio.h>

int arr[11] = {15,10,21,13,20,24,15,1,23,77,55};
void printArray(){
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int l,int h){
    int pivot = l; 
    int i = l;
    int j = h;
    while(i<j){
       
       while(arr[i]<=arr[pivot]){
        i++;
       }
       while(arr[j]>arr[pivot]){
         j--;
       }

       if(i<j){
       int temp = arr[j];
       arr[j] = arr[i];
       arr[i] = temp;
       }
    }
       int temp = arr[j];
       arr[j] = arr[pivot];
       arr[pivot] = temp;
    return j;
}

void QuickSort(int l,int h){
    if(l<h){
    int i = partition(l,h);
    QuickSort(l,i-1);
    QuickSort(i+1,h);
    printf("one");
}
}

void main(){
    int l = 0;
    int h = 10;
    // printArray();
    QuickSort(l,h);
    printArray();
}