//Github: Tejeshwar-SM
//Aim: Learning how to code, improving skills, and build fun and interesting projects
//Date: 9 October 2024

public class OrderAgnBinSearch {
    public static void main(String[] args) {
        int [] arr1 = {-142, -13, -12, -6,0,12, 29, 64, 98, 99};
        int target = 29;
        int [] arr2 = {89, 42, 12, 5, 2, 0, -21, -47, -55};
        int target2 = -47;
        System.out.println(orderAgnosticBS(arr2,target2));


    }
    static int orderAgnosticBS(int[] arr, int target) {
        int start = 0;
        int end = arr.length -1;

        boolean isAscending = arr[start] < arr[end];

        while (start<=end) {
            int mid = start + (end-start)/2;

            if (arr[mid]==target) {
                return mid;
            }
            if (isAscending){
                if (target < arr[mid]) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            } else {
                if (target > arr[mid]) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }


        }
        return -1;
    }
}
