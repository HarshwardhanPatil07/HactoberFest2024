/*
Name: Shivadarshan Devadiga
Github: shivadarshan-devadiga
Date:14/10/2024

Heap Sort
Time Complexity:
 - Worst-case: O(n log n)
 - Best-case: O(n log n)
 - Average-case: O(n log n)
 
 Space Complexity: 
  - O(1) (in-place sorting)
Best for:
 - Sorting large datasets with limited extra space.
*/

public class Solution 
{
    public void heapSort(int[] arr) 
    {
        int n = arr.length;
        // Build max heap
        for(int i=n/2-1;i>=0;i--)
            heapify(arr,n,i);
        // Extract elements from heap one by one
        for(int i=n-1;i>0;i--) 
        {
            // Move current root (largest) to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            // Call heapify on the reduced heap
            heapify(arr,i,0);
        }
    }
    // Heapify a subtree rooted at index 'i'
    // 'n' is the size of the heap
    void heapify(int[] arr,int n,int i) 
    {
        int largest = i;  // Initialize largest as root
        int left = 2*i+1;  // Left child
        int right = 2*i+2; // Right child
        if (left<n && arr[left]>arr[largest])
            largest = left;
        if (right<n && arr[right]>arr[largest])
            largest = right;
        // If largest is not root, swap root with the largest element
        if (largest != i) 
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            // Recursively heapify the affected subtree
            heapify(arr,n,largest);
        }
    }
    public static void main(String[] args) 
    {
        Solution solution = new Solution();
        int[] arr = {12,11,13,5,6,7};
        solution.heapSort(arr);
        System.out.println("Sorted array is:");
        for (int i : arr)
            System.out.print(i + " ");
    }
}
