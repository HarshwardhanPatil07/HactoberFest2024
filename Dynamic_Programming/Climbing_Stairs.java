public class Fibonacci {
    public static void Dpcall(int num)
    {
        int n = num;
        int[] dp = new int[n + 1];

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        System.out.println(dp[n]);
    }
    public static void main(String[] args) {
       Dpcall(3);
    }
}
