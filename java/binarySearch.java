//Github: Tejeshwar-SM
//Aim: Learning how to code, improving skills, and build fun and interesting projects
//Date: 9 October 2024
public class BinarySearch {
    public static void main(String[] args) {
        int [] arr = {-192, -23, -10, -1,0,11, 29, 64, 78, 189};
        int target = 10;
        int ans = binarySearch(arr,target);
        System.out.println(ans);
    }
    static int binarySearch(int [] arr, int target) {
        int start = 0;
        int end = arr.length -1;
        while (start<=end) {
            int mid = start + (end-start)/2;

            if (target < arr[mid]) {
                end = mid-1;
            } else if (target > arr[mid]) {
                start = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
