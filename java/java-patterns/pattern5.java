
import java.io.*;

class Main5 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution5 obj=new Solution5();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution5 {

    void printTriangle(int n) {
        // code here
        for(int i =n; i>=1; i--)
        {
            for(int j =1; j<=i; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
