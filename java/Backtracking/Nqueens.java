package Backtracking;

public class NQueens {
    public static void main(String[] args) {
        // Initialize board
        boolean[][] board = new boolean[8][8];

        // Solve N-Queens problem
        System.out.println(nQueens(8, 0, 0, board));
    }

    /**
     * Solves the N-Queens problem using backtracking.
     *
     * @param n     Number of queens
     * @param temp  Temporary counter
     * @param r     Current row
     * @param board 2D array representing the board
     * @return      Number of solutions
     */
    public static int nQueens(int n, int temp, int r, boolean[][] board) {
        // Base case: all queens placed
        if (n == temp) {
            printBoard(board);
            return 1;
        }

        // Invalid row
        if (r > board.length) {
            return 0;
        }

        int count = 0;

        // Explore all columns
        for (int i = 0; i < board[0].length; i++) {
            // Check safety
            if (isSafe(board, r, i)) {
                // Place queen
                board[r][i] = true;

                // Recurse
                count += nQueens(n, temp + 1, r + 1, board);

                // Backtrack
                board[r][i] = false;
            }
        }
        return count;
    }

    /**
     * Checks if a position is safe for a queen.
     *
     * @param board 2D array representing the board
     * @param r     Row
     * @param c     Column
     * @return      True if safe, false otherwise
     */
    public static boolean isSafe(boolean[][] board, int r, int c) {
        // Check column
        for (int i = 0; i < r; i++) {
            if (board[i][c]) {
                return false;
            }
        }

        // Check upper-left diagonal
        int maxLeft = Math.min(r, c);
        for (int i = 1; i <= maxLeft; i++) {
            if (board[r - i][c - i]) {
                return false;
            }
        }

        // Check upper-right diagonal
        int maxRight = Math.min(r, board[0].length - c - 1);
        for (int i = 1; i <= maxRight; i++) {
            if (board[r - i][c + i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Prints the board.
     *
     * @param board 2D array representing the board
     */
    public static void printBoard(boolean[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j]) {
                    System.out.print("Q ");
                } else {
                    System.out.print("X ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
}