// Quick Sort Algorithm in Java
public class QuickSort {

    // Method to perform quicksort
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high); // Get the partitioning index
            quickSort(arr, low, pi - 1);  // Recursively sort the left part
            quickSort(arr, pi + 1, high); // Recursively sort the right part
        }
    }

    // Method to partition the array
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choose the rightmost element as pivot
        int i = low - 1; // Index of the smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap arr[i + 1] and pivot (arr[high])
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1; // Return the partitioning index
    }

    // Helper method to print the array
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    // Main method to test the quicksort
    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        int n = arr.length;

        System.out.println("Unsorted array:");
        printArray(arr);

        quickSort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        printArray(arr);
    }
}
