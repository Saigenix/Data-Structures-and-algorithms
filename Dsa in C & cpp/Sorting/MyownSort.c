#include <stdio.h>
 
// Algorithm : First find largest number in array 
// and then swap that number with last postion
// after that perform same step excluding last postion

// array with 5 elements
 int arr[5] ={5,17,12,1,7};
 int n = 5;
// max variable to keep track of max index
int max;
// sort Function 
void sort(){

 // for loop going from 0 to 3
 // we dont need go till last because we dont need to check 
 // last element
 for(int i = 0; i <n-1 ; i++){
 // initially suppose max at  index
  max = 0;
  // second for loop going from 0 to n-i-2
  // for find max elemets index also we dont need to 
  // go till last
  for(int j = 0; j<= n-i-2 ; j++){
// if condition for max
   if (arr[max] < arr[j+1]){
    max = j+1;
    }
   }
  // now our max variable contains postion of max element
  // swapping max element and last element in array
  // for accessing last elements index we are using n-i-1 
  int temp = arr[max];
  arr[max] = arr[n -i - 1];
  arr[n-i-1] = temp;
  }
 }

int main()
{
// calling sort function
 sort();

 // printing sorted array
 for(int p = 0 ; p < n ; p++){
  printf("%d\n",arr[p]);
 }
// Output : 1,5,7,12,17
 return 0;

}