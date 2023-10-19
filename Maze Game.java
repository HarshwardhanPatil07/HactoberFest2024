import java.util.Scanner;

public class MazeGame {

    public static void main(String[] args) {
        char[][] maze = {
                {'S', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
                {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
                {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
                {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', ' ', 'E'}
        };

        int playerRow = 0;
        int playerCol = 0;

        Scanner scanner = new Scanner(System.in);

        while (true) {
            // Print the current state of the maze
            printMaze(maze);

            // Get the player's move
            System.out.print("Enter your move (U/D/L/R): ");
            String move = scanner.next().toUpperCase();

            // Update the player's position based on the move
            switch (move) {
                case "U":
                    if (playerRow > 0 && maze[playerRow - 1][playerCol] != '#') {
                        maze[playerRow][playerCol] = ' ';
                        playerRow--;
                    }
                    break;
                case "D":
                    if (playerRow < maze.length - 1 && maze[playerRow + 1][playerCol] != '#') {
                        maze[playerRow][playerCol] = ' ';
                        playerRow++;
                    }
                    break;
                case "L":
                    if (playerCol > 0 && maze[playerRow][playerCol - 1] != '#') {
                        maze[playerRow][playerCol] = ' ';
                        playerCol--;
                    }
                    break;
                case "R":
                    if (playerCol < maze[0].length - 1 && maze[playerRow][playerCol + 1] != '#') {
                        maze[playerRow][playerCol] = ' ';
                        playerCol++;
                    }
                    break;
                default:
                    System.out.println("Invalid move. Use U/D/L/R.");
            }

            // Check if the player has reached the exit
            if (maze[playerRow][playerCol] == 'E') {
                System.out.println("Congratulations! You reached the exit.");
                break;
            }
        }

        scanner.close();
    }

    private static void printMaze(char[][] maze) {
        for (char[] row : maze) {
            for (char cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
