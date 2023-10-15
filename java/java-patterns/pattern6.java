
import java.io.*;

class Main6 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution6 obj = new Solution6();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution6 {

    void printTriangle(int n) {
        // code here
        for(int i =1; i<=n; i++)
        {
            for(int j =n; j>i; j--)
            {
                System.out.print(" ");
            }
            for(int k =1; k<=2*i-1; k++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
