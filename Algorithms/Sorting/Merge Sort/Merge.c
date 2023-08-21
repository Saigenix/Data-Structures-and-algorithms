#include<stdio.h>

int arr[10] = {15,10,21,13,20,67,55,67,2,1};

void printArray(){
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int mid, int l,int h){
    int temparr[h - l + 1];
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <=  h){
        if(arr[i]<arr[j]){
            temparr[k] = arr[i];
            i++;
        }else{
            temparr[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= h){
            temparr[k] = arr[j];
            j++;k++;
        }
    }else{
        while(i <= mid){
            temparr[k] = arr[i];
            i++;k++;
        }
    }
    int p = 0;
    for (int k = l; k <= h; k++)
    {
        /* code */
        arr[k] = temparr[p++];
    }
}



void MergeSort(int l,int h){
    if(l<h){
    int mid = (l+h)/2;
    MergeSort(l,mid);
    MergeSort(mid+1,h);
    merge(mid,l,h);
    }
}

void main(){
    int l = 0;
    int h = 9;
    // printArray();
    MergeSort(l,h);
    printArray();
}