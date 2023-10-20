
import java.util.*;

class bubble&selection {
    public static void main(String[] args) {
        int a[] = { 4, 3, 2, 7, 8, 2, 3, 1 };

        Cyclic(a);
        // int bubble[] = selecticyclion(a);
        // System.out.print(Arrays.toString(bubble));
    }

    // swap func
    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    // *NOTE*
    // CYCLIC SORT uses the indexes to sort the array when its from 1 to n , meaning
    // {1 ,2, 3 ,4} has the index 1-0 , 2-1 , 3-2 , 4-3 (index = value -1 )
    // swap the value with index(this.value-1)

    static void Cyclic(int arr[]) {
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[correct] != arr[i]) {
                swap(arr, correct, i);

            } else {
                i++;
            }
        }

        System.out.println();
        System.out.print("sorted" + Arrays.toString(arr));
    }


        // *NOTE*
        // for every pass the last element will be at the correct place therefore innerloop will run till length-i times 
    static int[] bubble(int a[]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 1; j < a.length - i; j++) {
                if (a[j] < a[j - 1]) {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }
        return a;
    }



    static int[] selection(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int last = arr.length - i - 1;
            int max = getMaxIndex(arr, 0, last);
            swap(arr, max, last);
        }
        return arr;
    }

    
    static int getMaxIndex(int[] arr, int start, int end) {
        int max = start;
        for (int i = start; i <= end; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        return max;

    }
}