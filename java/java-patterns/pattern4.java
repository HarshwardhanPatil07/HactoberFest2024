
import java.io.*;

class Main4 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution4 obj = new Solution4();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution4 {

    void printTriangle(int n) {
        // code here
        for(int i =1; i<=n; i++)
        {
            for(int j =1; j<=i; j++)
            {
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}