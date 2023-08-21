
public class BubbleSort {

    public static void main(String args[]) {
        int arr[] = {21,20,34,23,34,5};
        SortA(arr);
        SortB(arr);
    }

    private static void SortA(int[] arr) {
            int temp;
            for (int i = 0; i < arr.length-1; i++) // For number of pass
            {
                for (int j = 0; j <arr.length-1 - i ; j++) // For comparison in each pass
                {
                    if(arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp; 
                    }
                }  
            }
            System.out.println("IN asending order");
            for(int i:arr)  System.out.print(i+" ");
            System.out.println(); 
        }
    
    private static void SortB(int[] arr) {
        int temp;
            for (int i = 0; i < arr.length-1; i++) // For number of pass
            {
                for (int j = 0; j <arr.length-1 - i ; j++) // For comparison in each pass
                {
                    if(arr[j]<arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp; 
                    }
                }  
            }
            System.out.println("IN Desending order");
            for(int i:arr)  System.out.print(i+" ");  

    }
}
