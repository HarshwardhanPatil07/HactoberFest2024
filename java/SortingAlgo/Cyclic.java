import java.util.Arrays;

public class Cyclic {
    public static void main(String[] args) {
        int arr[] = { 3, 5, -1, 2, 3, 4 };

        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[correct] != arr[i]) {
                int temp = arr[correct];
                arr[correct] = arr[i];
                arr[correct] = temp;

            } else {
                i++;
            }

        }

    

        System.out.println(Arrays.toString(arr));
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
