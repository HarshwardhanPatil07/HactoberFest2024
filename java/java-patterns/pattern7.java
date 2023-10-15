

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();

            Solution7 ob = new Solution7();
            ob.printDiamond(n);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution7 {

    void printDiamond(int n) {
        // Your code here
        for(int i =1; i<=n; i++)
        {
            for(int j =n; j>i; j--)
            {
                System.out.print(" ");
            }
            for(int k =1; k<=i; k++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i =n; i>=1; i--)
        {
            for(int j =n; j>i; j--)
            {
                System.out.print(" ");
            }
            for(int k =1; k<=i; k++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}

