/**
#Algorithm : 
*********************************************************************************************************************************************
Algorithm maxSubarraySum(arr, n):
Input: arr - an integer array of length n
       n - the size of the array
Output: res - the maximum subarray sum

1. Initialize two long variables:
   - res to Integer.MIN_VALUE (set to the smallest possible value)
   - sum to 0 (to keep track of the current subarray sum)

2. Iterate through the array elements using a for-each loop:
   For each element e in arr:
   a. Add e to sum, updating the current subarray sum.

   b. Update res to be the maximum of its current value and the sum. This keeps track of the maximum subarray sum encountered so far.

   c. Check if sum is less than 0 (i.e., if the current subarray sum becomes negative):
      - If it is negative, reset sum to 0. This ensures that we start a new subarray whenever the sum becomes negative, as negative sums are not part of the maximum subarray sum.

3. After iterating through all elements in the array, return the value of res, which represents the maximum subarray sum.

4. The function has now successfully computed and returned the maximum subarray sum, and the algorithm terminates.
****************************************************************************************************************************************************************
*/

import java.util.Scanner;

public class Kadanes_Algorithm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n = scan.nextInt();

        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i]=scan.nextInt();
        }
       long res =  maxSubarraySum(arr,n);
        System.out.println(res);
    }

    // function for algo

   public static long maxSubarraySum(int arr[], int n){
        long res = Integer.MIN_VALUE;
        long sum = 0;

        for(int e:arr){
            sum+=e;
            res = Math.max(res,sum);
            if(sum<0)sum=0;

        }

        return res;
    }
}
