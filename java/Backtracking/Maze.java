package Backtracking;

import java.util.ArrayList;

public class Maze {
    // Define directions for movement
    private static final char RIGHT = 'R';
    private static final char DOWN = 'D';
    private static final char UP = 'U';
    private static final char LEFT = 'L';

    public static void main(String[] args) {
        int[][] maze = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
        };

        // Find all paths in the maze
        ArrayList<String> paths = findAllPaths(maze, 0, 0, "");

        // Print all paths
        for (String path : paths) {
            System.out.println(path);
        }
    }

    /**
     * Finds all possible paths in the maze.
     *
     * @param maze  2D array representing the maze
     * @param row   current row
     * @param col   current column
     * @param path  current path
     * @return      list of all possible paths
     */
    public static ArrayList<String> findAllPaths(int[][] maze, int row, int col, String path) {
        // Base case: reached destination
        if (row == maze.length - 1 && col == maze[0].length - 1) {
            ArrayList<String> result = new ArrayList<>();
            result.add(path);
            return result;
        }

        // Mark current cell as visited
        maze[row][col] = 1;

        ArrayList<String> paths = new ArrayList<>();

        // Explore all directions
        if (isValid(maze, row + 1, col)) {
            paths.addAll(findAllPaths(maze, row + 1, col, path + DOWN));
        }
        if (isValid(maze, row - 1, col)) {
            paths.addAll(findAllPaths(maze, row - 1, col, path + UP));
        }
        if (isValid(maze, row, col + 1)) {
            paths.addAll(findAllPaths(maze, row, col + 1, path + RIGHT));
        }
        if (isValid(maze, row, col - 1)) {
            paths.addAll(findAllPaths(maze, row, col - 1, path + LEFT));
        }

        // Unmark current cell
        maze[row][col] = 0;

        return paths;
    }

    /**
     * Checks if a cell is valid for movement.
     *
     * @param maze  2D array representing the maze
     * @param row   target row
     * @param col   target column
     * @return      true if valid, false otherwise
     */
    private static boolean isValid(int[][] maze, int row, int col) {
        return row >= 0 && row < maze.length && col >= 0 && col < maze[0].length && maze[row][col] == 0;
    }
}