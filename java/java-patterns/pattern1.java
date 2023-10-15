//Github-username-Ansh Verma
//aim-Web developer and ML engineer
//Date-15/10/2023
import java.io.*;
import java.util.*;

class Main1 {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution1 obj = new Solution1();
            obj.printSquare(n);
        }
    }
}



class Solution1 {

    void printSquare(int n) {
        
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}