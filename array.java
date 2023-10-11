import java.util.Scanner;

public class array {
    public static int sum(int arr[]) {
        int sum = 0;
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            sum = sum + arr[i];
        }
        return sum;
    }

    public static int average(int arr[]) {
        int len = arr.length;
        int average = sum(arr) / len;
        return average;
    }

    public static void search(int arr[], int a) {
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            if (arr[i] == a) {
                System.out.println("Element Found");
                break;
            } else if (i == len && arr[i] != a) {
                System.out.println("Element Not Found");
            }
        }
    }

    public static int evensum(int arr[]) {
        int len = arr.length;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] % 2 == 0) {
                sum = sum + arr[i];
            }
        }
        return sum;
    }

    public static int[] rev(int arr[]) {
        int len = arr.length;
        int swap = 0;
        for (int i = 0; i < len / 2; i++) {
            swap = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = swap;
        }
        return arr;
    }

    public static void print(int arr[]) {
        int len = arr.length;
        System.out.println("The array is : ");
        for (int i = 0; i < len; i++) {
            System.out.println(arr[i]);
        }
    }

    public static int primecount(int arr[]) {
        int len = arr.length;
        int primecount = 0;
        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int j = 1; j <= arr[i]; j++) {
                if (arr[i] % j == 0) {
                    count++;
                }
            }
            if (count <= 2) {
                primecount++;
            }
        }
        return primecount;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int len = sc.nextInt();
        int arr[] = new int[len];
        int a = 0;
        while (a != 8) {
            System.out.println(
                    "Enter a choice\n0)Insert 1)Sum 2)Average 3)Search 4)Evensum 5)Reverse 6)Primecount 7)Print 8)Exit");
            a = sc.nextInt();
            switch (a) {
                case 0:
                    for (int i = 0; i < len; i++) {
                        System.out.println("Enter the " + (i + 1) + "th element");
                        arr[i] = sc.nextInt();
                    }
                    break;
                case 1:
                    System.out.println("The sum is " + sum(arr));
                    break;
                case 2:
                    System.out.println("The average is " + average(arr));
                    break;
                case 3:
                    System.out.println("Enter the element to search");
                    int s = sc.nextInt();
                    search(arr, s);
                    break;
                case 4:
                    System.out.println("The sum of even numbers in array is " + evensum(arr));
                    break;
                case 5:
                    arr = rev(arr);
                    break;
                case 6:
                    System.out.println("The no of prime no in array are " + primecount(arr));
                    break;
                case 7:
                    print(arr);
                    break;

            }
        }
        sc.close();
    }
}
