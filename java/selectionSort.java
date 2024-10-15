
public class selectionSort {
    public static void selctionSorting(int arr[]){
        for (int i = 0; i < arr.length-1; i++) {
            int minValue = i;
            for (int j =i+1 ; j < arr.length; j++) {
                if(arr[minValue] > arr[j]){
                    minValue = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minValue];
            arr[minValue] = temp;   
        }
    } 
    public static void printSelectionSorting(int arr[]){
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
            
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int arr[] = {3,6,2,1,8,7,4,5,3,1};
        selctionSorting(arr);
        printSelectionSorting(arr);
    }

    
}