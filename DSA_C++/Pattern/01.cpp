#include <iostream>
using namespace std;

// Function for Square Pattern
void squarePattern(int n) {
    // Example: n = 4
    // Output:
    // * * * *
    // * * * *
    // * * * *
    // * * * *
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Function for Right-Angled Triangle
void rightAngledTriangle(int n) {
    // Example: n = 4
    // Output:
    // *
    // * *
    // * * *
    // * * * *
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Function for Inverted Right-Angled Triangle
void invertedRightAngledTriangle(int n) {
    // Example: n = 4
    // Output:
    // * * * *
    // * * *
    // * *
    // *
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Function for Pyramid Pattern
void pyramidPattern(int n) {
    // Example: n = 4
    // Output:
    //    *    
    //   * *   
    //  * * *  
    // * * * *
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print space
        }
        for (int k = 1; k <= i; k++) {
            cout << "* "; // Print stars
        }
        cout << endl;
    }
}

// Function for Inverted Pyramid Pattern
void invertedPyramidPattern(int n) {
    // Example: n = 4
    // Output:
    // * * * * 
    //  * * *  
    //   * *   
    //    *    
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print space
        }
        for (int k = 1; k <= i; k++) {
            cout << "* "; // Print stars
        }
        cout << endl;
    }
}

// Function for Diamond Pattern
void diamondPattern(int n) {
    // Example: n = 4
    // Output:
    //    *    
    //   * *   
    //  * * *  
    // * * * * 
    //  * * *  
    //   * *   
    //    *    
    // Upper part of diamond
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower part of diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Function for Number Pyramid Pattern
void numberPyramidPattern(int n) {
    // Example: n = 4
    // Output:
    //    1    
    //   1 2   
    //  1 2 3  
    // 1 2 3 4 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
}

// Function for Floyd’s Triangle
void floydsTriangle(int n) {
    // Example: n = 5
    // Output:
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// Function for Butterfly Pattern
void butterflyPattern(int n) {
    // Example: n = 4
    // Output:
    // *      *
    // **    **
    // ***  ***
    // ********
    // ********
    // ***  ***
    // **    **
    // *      *
    // Upper part
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower part
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= 2*(n-i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function for Pascal’s Triangle
void pascalsTriangle(int n) {
    // Example: n = 5
    // Output:
    //       1
    //      1 1
    //     1 2 1
    //    1 3 3 1
    //   1 4 6 4 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " "; // Print spaces
        }
        int num = 1;
        for (int k = 0; k <= i; k++) {
            cout << num << " ";
            num = num * (i - k) / (k + 1); // Compute binomial coefficient
        }
        cout << endl;
    }
}

int main() {
    int choice, n;

    cout << "Choose a pattern to print:" << endl;
    cout << "1. Square Pattern" << endl;
    cout << "2. Right-Angled Triangle Pattern" << endl;
    cout << "3. Inverted Right-Angled Triangle Pattern" << endl;
    cout << "4. Pyramid Pattern" << endl;
    cout << "5. Inverted Pyramid Pattern" << endl;
    cout << "6. Diamond Pattern" << endl;
    cout << "7. Number Pyramid Pattern" << endl;
    cout << "8. Floyd’s Triangle" << endl;
    cout << "9. Butterfly Pattern" << endl;
    cout << "10. Pascal’s Triangle" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the number of rows: ";
    cin >> n;

    switch (choice) {
        case 1:
            squarePattern(n);
            break;
        case 2:
            rightAngledTriangle(n);
            break;
        case 3:
            invertedRightAngledTriangle(n);
            break;
        case 4:
            pyramidPattern(n);
            break;
        case 5:
            invertedPyramidPattern(n);
            break;
        case 6:
            diamondPattern(n);
            break;
        case 7:
            numberPyramidPattern(n);
            break;
        case 8:
            floydsTriangle(n);
            break;
        case 9:
            butterflyPattern(n);
            break;
        case 10:
            pascalsTriangle(n);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
