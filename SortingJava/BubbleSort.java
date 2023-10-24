// github user name: kunal-sharma05
// aim: To teach folks how to do bubble sort
// date: 24/10/2023
public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11}; 
        
        int n = arr.length;
        boolean a; 
        
        for (int i = 0; i < n - 1; i++) {
            a = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    arr[j] = arr[j + 1] +arr[j];
                    arr[j + 1] = arr[j]-arr[j+1];
                    arr[j]=arr[j]-arr[j+1];
                    a = true;
                }
            }
            if (!a) {
                break;
            }
        }
        
        System.out.print("Sorted array: ");
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }
}
