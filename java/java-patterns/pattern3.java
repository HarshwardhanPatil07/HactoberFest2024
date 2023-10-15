//Github-username-Ansh Verma
//aim-Web developer and ML engineer
//Date-15/10/2023
import java.io.*;

class Main3 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution3 obj = new Solution3();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution3 {

    void printTriangle(int n) {
        // code here
        for(int i =1; i<=n; i++)
        {
            for(int j =1; j<=i; j++)
            {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}
