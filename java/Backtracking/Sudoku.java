package Backtracking;

public class Sudoku {
    public static void main(String[] args) {
        // Initialize Sudoku board
        int[][] board = {
                {3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 1, 0}
        };

        // Solve Sudoku
        if (sudokuSolver(board)) {
            System.out.println("Sudoku found");
        } else {
            System.out.println("Sudoku not found");
        }
    }

    /**
     * Solves the Sudoku puzzle using backtracking.
     *
     * @param sudoku 2D array representing the Sudoku board
     * @return      true if solution found, false otherwise
     */
    public static boolean sudokuSolver(int[][] sudoku) {
        // Find empty cell
        int r = -1;
        int c = -1;
        boolean empty = true;
        for (int i = 0; i < sudoku.length; i++) {
            for (int j = 0; j < sudoku[0].length; j++) {
                if (sudoku[i][j] == 0) {
                    r = i;
                    c = j;
                    empty = false;
                    break;
                }
            }
            if (!empty) {
                break;
            }
        }

        // Base case: no empty cells
        if (empty) {
            printSudoku(sudoku);
            return true;
        }

        // Try values 1-9
        for (int i = 1; i <= 9; i++) {
            // Check safety
            if (isSafe(sudoku, r, c, i)) {
                // Place value
                sudoku[r][c] = i;

                // Recurse
                if (sudokuSolver(sudoku)) {
                    return true;
                } else {
                    // Backtrack
                    sudoku[r][c] = 0;
                }
            }
        }
        return false;
    }

    /**
     * Checks if a value is safe in a cell.
     *
     * @param board 2D array representing the Sudoku board
     * @param r     Row
     * @param c     Column
     * @param val   Value to check
     * @return      true if safe, false otherwise
     */
    public static boolean isSafe(int[][] board, int r, int c, int val) {
        // Check row
        for (int i = 0; i < board.length; i++) {
            if (board[i][c] == val) {
                return false;
            }
        }

        // Check column
        for (int j = 0; j < board[0].length; j++) {
            if (board[r][j] == val) {
                return false;
            }
        }

        // Check box
        int sqr = (int) Math.sqrt(board.length);
        int boxRow = r - r % sqr;
        int boxCol = c - c % sqr;

        for (int i = boxRow; i < boxRow + sqr; i++) {
            for (int j = boxCol; j < boxCol + sqr; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Prints the Sudoku board.
     *
     * @param sudoku 2D array representing the Sudoku board
     */
    public static void printSudoku(int[][] sudoku) {
        for (int i = 0; i < sudoku.length; i++) {
            for (int j = 0; j < sudoku[0].length; j++) {
                System.out.print(sudoku[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}