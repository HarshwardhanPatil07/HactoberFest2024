//Github-username-Ansh Verma
//aim-Web developer and ML engineer
//Date-15/10/2023
import java.io.*;

class Main9 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution9 obj = new Solution9();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution9 {

    void printTriangle(int n) {
        for(int i =1; i<=n; i++)
        {
            for(int j =n; j>=i; j--)
            {
                System.out.print("*");
            }
            for(int k =1; k<i; k++)
            {
                System.out.print(" ");
            }
            for(int k =1; k<i; k++)
            {
                System.out.print(" ");
            }
            for(int j =n; j>=i; j--)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i =1; i<=n; i++)
        {
            for(int j =1; j<=i; j++)
            {
                System.out.print("*");
            }
            for(int k =i; k<n; k++)
            {
                System.out.print(" ");
            }
            for(int k =i; k<n; k++)
            {
                System.out.print(" ");
            }
            for(int j =i; j>=1; j--)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        // code here
    }
}
