#include<stdio.h>
#include<stdlib.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void SectionSort(int arr[],int n){
    int MinEle;
    for (int i = 0; i < n-1; i++)
    {
        MinEle = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[MinEle]){
                MinEle = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[MinEle];
        arr[MinEle] = temp;
    }
    
}

void BubbleSort(int arr[],int n){
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}

void InsertionSort(int arr[],int n){
    // starts from 1 
    for (int i = 1; i < n; i++)
    {
       // printf("i:%d val:%d\n",i,arr[i]);
        int val = arr[i];
        int j = i-1;
        while(j >= 0 && val < arr[j] ){
            //printf("For %d setting value of %d \n",arr[j+1],arr[j]);
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
    
}

void Merge(int *arr,int mid,int l,int h){
    // 3 24 35   6 7 8
    int nArr[100];
    int low = l;
    int j = mid+1;
    int p = 0;
    while(low < j && j<= h){
        if(arr[low]<arr[j]){
            nArr[p++] = arr[low++];
        }else{
            nArr[p++]=arr[j++];
        }
        
    }
    while(low<=j){
        nArr[p++] = arr[low++];
    }
    while(j<=h){
        nArr[p++] = arr[j++];
    }
    int k = 0;
    for (int i = l; i <= h; i++)
    {
        /* code */
        arr[i] = nArr[k++];
    }

}

void MergeSort(int *arr,int l,int h){
    if(l<h){
        int mid = (l + h)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        Merge(arr,mid,l,h);
    }
    
}

int Partition(int arr[],int l ,int h){
    int temp;
    int pivot = l;
    int i = l;
    int j = h;
    while(i<j){
        while(arr[i]<= arr[pivot] && i <= h){
            i++;
        }
        while(arr[j] > arr[pivot]){
            j--;
        }
        if(i<j){
        temp = arr[i];
        arr[i]=arr[j];
        arr[j] = temp;}
    }
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    return j;
}

void QuickSort(int arr[],int l,int h){
    if(l<h){
        int prId = Partition(arr,l,h);
        QuickSort(arr,l,prId-1);
        QuickSort(arr,prId+1,h);
    }
}


void main(){
      int A[15] ={77,55,2,34,22,77,1,11,5,33,88,4,7,17,22};
      int n = 15;
      printArray(A,n);
      // SectionSort(A,n);
      // BubbleSort(A,n);
      // InsertionSort(A,n);
      MergeSort(A,0,14);
      // QuickSort(A,0,14);
      printArray(A,n);

}
// Algorithm	     Time Complexity              Space Complexity
//  	            Best  Average	    Worst	         Worst
// Selection Sort  Ω(n^2)   θ(n^2)	    O(n^2)	          O(1)
// Bubble Sort	   Ω(n)     θ(n^2)	    O(n^2)	            O(1)
// Insertion Sort  Ω(n)	    θ(n^2)	    O(n^2)	            O(1)
// Heap Sort	Ω(n log(n))	θ(n log(n))	O(n log(n))	    O(1)
// Quick Sort	Ω(n log(n))	θ(n log(n))	O(n^2)	        O(n)
// Merge Sort	Ω(n log(n))	θ(n log(n))	O(n log(n))	    O(n)
// Bucket Sort	Ω(n +k)	    θ(n +k)	    O(n^2)	             O(n)
// Radix Sort	Ω(nk)	    θ(nk)	    O(nk)	             O(n + k)
// Count Sort	Ω(n +k)	    θ(n +k)	    O(n +k)	          (k)
// Shell Sort	Ω(n log(n))	θ(n log(n))	O(n^2)	         O(1)
// Tim Sort		Ω(n)        θ(n log(n))	O(n log (n))	 O(n)
// Tree Sort	Ω(n log(n))	θ(n log(n))	O(n^2)	         O(n)
// Cube Sort	Ω(n)	    θ(n log(n))	O(n log(n))	         O(n)