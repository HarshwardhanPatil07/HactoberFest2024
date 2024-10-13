class Hactober {
    public static int printNFibonacciNumbers(int n)
    {
        if (n <= 1)return n;
        return printNFibonacciNumbers(n - 1) + printNFibonacciNumbers(n - 2);
    }
    public static void main(String args[])
    {
        int n = 10;
        for (int i = 0; i < n; i++) {
            System.out.print(printNFibonacciNumbers(i) + " ");
        }
    }
}
