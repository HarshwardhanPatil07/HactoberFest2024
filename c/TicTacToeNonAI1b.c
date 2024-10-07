#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY '-'

// Function to print the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) printf(" | ");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) printf("---------\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// Function to generate all possible moves
int generatePossibleMoves(char board[BOARD_SIZE][BOARD_SIZE], int moves[BOARD_SIZE * BOARD_SIZE][2]) {
    int moveCount = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                moves[moveCount][0] = i;
                moves[moveCount][1] = j;
                moveCount++;
            }
        }
    }
    return moveCount;
}

// Function to calculate index for a given board state
int calculateBoardIndex(char board[BOARD_SIZE][BOARD_SIZE]) {
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int value;
            if (board[i][j] == PLAYER_X) {
                value = 1;
            } else if (board[i][j] == PLAYER_O) {
                value = 2;
            } else {
                value = 0;
            }
            index = index * 3 + value;
        }
    }
    return index;
}

// Function to evaluate a board node
int evaluateNode(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    char opponent = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    if (checkWin(board, player)) return 60;
    if (checkWin(board, opponent)) return 50;

    int score = 0;
    // Evaluate rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        int playerCountRow = 0, opponentCountRow = 0;
        int playerCountCol = 0, opponentCountCol = 0;
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == player) playerCountRow++;
            if (board[i][j] == opponent) opponentCountRow++;
            if (board[j][i] == player) playerCountCol++;
            if (board[j][i] == opponent) opponentCountCol++;
        }
        if (opponentCountRow == 0 && playerCountRow > 0) score += 1;
        if (playerCountRow == 0 && opponentCountRow > 0) score -= 1;
        if (opponentCountCol == 0 && playerCountCol > 0) score += 1;
        if (playerCountCol == 0 && opponentCountCol > 0) score -= 1;
    }

    // Evaluate diagonals
    int playerCountMainDiag = 0, opponentCountMainDiag = 0;
    int playerCountAntiDiag = 0, opponentCountAntiDiag = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][i] == player) playerCountMainDiag++;
        if (board[i][i] == opponent) opponentCountMainDiag++;
        if (board[i][BOARD_SIZE - i - 1] == player) playerCountAntiDiag++;
        if (board[i][BOARD_SIZE - i - 1] == opponent) opponentCountAntiDiag++;
    }
    if (opponentCountMainDiag == 0 && playerCountMainDiag > 0) score += 1;
    if (playerCountMainDiag == 0 && opponentCountMainDiag > 0) score -= 1;
    if (opponentCountAntiDiag == 0 && playerCountAntiDiag > 0) score += 1;
    if (playerCountAntiDiag == 0 && opponentCountAntiDiag > 0) score -= 1;

    return score;
}

// Function to find the best move
void findBestMove(char board[BOARD_SIZE][BOARD_SIZE], char player, int *bestMoveRow, int *bestMoveCol) {
    int possibleMoves[BOARD_SIZE * BOARD_SIZE][2];
    int moveCount = generatePossibleMoves(board, possibleMoves);
    int bestScore = INT_MIN;
    *bestMoveRow = -1;
    *bestMoveCol = -1;

    for (int i = 0; i < moveCount; ++i) {
        int row = possibleMoves[i][0];
        int col = possibleMoves[i][1];
        board[row][col] = player;

        // Calculate the index for the current board configuration
        int index = calculateBoardIndex(board);
        printf("Evaluating move at (%d, %d), Board Index: %d\n", row, col, index);

        int score = evaluateNode(board, player);
        board[row][col] = EMPTY;

        if (score > bestScore) {
            bestScore = score;
            *bestMoveRow = row;
            *bestMoveCol = col;
        }
    }
}

// Function to check if the board is full
int isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char input[BOARD_SIZE * BOARD_SIZE + 1];

    printf("Enter the current board state as a single string (use X, O, and - for empty cells, e.g., 'XO-X-O---'):\n");
    scanf("%s", input);

    if (strlen(input) != BOARD_SIZE * BOARD_SIZE) {
        printf("Invalid input. Please enter exactly %d characters.\n", BOARD_SIZE * BOARD_SIZE);
        return 1;
    }

    int index = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = input[index++];
        }
    }

    printf("Current board state:\n");
    printBoard(board);

    if (checkWin(board, PLAYER_X)) {
        printf("Player X has already won.\n");
        return 0;
    } else if (checkWin(board, PLAYER_O)) {
        printf("Player O has already won.\n");
        return 0;
    } else if (isBoardFull(board)) {
        printf("The game is a draw.\n");
        return 0;
    }

    int bestMoveRow, bestMoveCol;
    findBestMove(board, PLAYER_X, &bestMoveRow, &bestMoveCol);
    if (bestMoveRow != -1 && bestMoveCol != -1) {
        printf("Best move for player X is: (%d, %d)\n", bestMoveRow, bestMoveCol);

        // Apply the best move to the board
        board[bestMoveRow][bestMoveCol] = PLAYER_X;
        printf("Board after the best move:\n");
        printBoard(board);
    } else {
        printf("No possible moves left.\n");
    }

    return 0;
}
