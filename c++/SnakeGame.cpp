// Name of Contributer -- Ankita Sinha Ray
// Date of contribution -- 16/10/2024
// github username -- @ankitasray
// aim -- Simple Snake Game :It’s a basic console game where the player controls a snake that grows as it eats food. The game ends when the snake hits the wall or itself.

#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    dir = STOP;
    nTail = 0;
}

void Draw() {
    system("cls"); 

    
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#"; 

            if (i == y && j == x)
                cout << "O"; 
            else if (i == fruitY && j == fruitX)
                cout << "F"; 
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; 
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#"; 
        }
        cout << endl;
    }

    
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    
    cout << "Score: " << score << endl;
}

void Input() {
    char move;
    cout << "Enter direction (w: up, s: down, a: left, d: right): ";
    cin >> move;

    switch (move) {
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        default:
            dir = STOP;
            break;
    }
}

void Logic() {
    // Move the tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    
    switch (dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }

    
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            cout << "Game Over!" << endl;
            exit(0);
        }
    }
}

int main() {
    srand(time(0)); 
    Setup();

    while (true) {
        Draw();
        Input();
        Logic();
    }

    return 0;
}
