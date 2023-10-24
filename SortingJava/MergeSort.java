public class MergeSort {
    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        
        System.out.println("Original Array:");
        printArray(arr);
        
        mergeSort(arr);
        
        System.out.println("\nSorted Array:");
        printArray(arr);
    }
    
    // Merge Sort function
    public static void mergeSort(int[] arr) {
        int length = arr.length;
        
        // Base case: If the array has one or zero elements, it's already sorted
        if (length <= 1) {
            return;
        }
        
        // Split the array into two halves
        int mid = length / 2;
        int[] left = new int[mid];
        int[] right = new int[length - mid];
        
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < length; i++) {
            right[i - mid] = arr[i];
        }
        
        // Recursively sort the left and right halves
        mergeSort(left);
        mergeSort(right);
        
        // Merge the sorted halves
        merge(arr, left, right);
    }
    
    // Merge function to combine two sorted arrays
    public static void merge(int[] arr, int[] left, int[] right) {
        int leftLength = left.length;
        int rightLength = right.length;
        int i = 0, j = 0, k = 0;
        
        // Compare elements from both halves and merge them in sorted order
        while (i < leftLength && j < rightLength) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        
        // Copy any remaining elements from the left and right subarrays
        while (i < leftLength) {
            arr[k++] = left[i++];
        }
        while (j < rightLength) {
            arr[k++] = right[j++];
        }
    }
    
    // Utility function to print an array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
