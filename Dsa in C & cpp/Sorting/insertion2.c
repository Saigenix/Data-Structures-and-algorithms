#include<stdio.h>

int arr[10] = {15,10,21,13,20,67,55,67,2,1};
int n = 10;
void printArray(){
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Sort(){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j>=0){
            if(arr[i]<arr[j]){
                int temp
                t]
                arr[j+1] = arr[j];
                j--;

            }
            
        }
        /* code */
    }
    
}



void main(){
    int l = 0;
    int h = 9;
    // printArray();
    Sort();
    printArray();
}