//Github-username-Ansh Verma
//aim-Web developer and ML engineer
//Date-15/10/2023
  import java.io.*;

class Main2 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution2 obj = new Solution2();
            obj.printTriangle(n);
        }
    }
}
// } Driver Code Ends


class Solution2 {

    void printTriangle(int n) {
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<=i; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        // code here
    }
}

