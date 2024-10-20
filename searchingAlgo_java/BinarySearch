import java.util.*;

public class BinarySearch{
    public static void main(String[] args) {
        int[] arr = {1,2,3,4};
        search(arr,3);
    }

    static int search(int[] arr,int x){
        int start = 0;
        int end = arr.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid] == x){
                return mid;
            }
            else if(arr[mid]<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
}