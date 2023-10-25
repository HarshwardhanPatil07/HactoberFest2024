/* Program to Print a star pattern 
*******
*** ***
**   **
*     *
*/
// github username -> fi1na
// Date -> 25/oct/2023
#include <iostream>
void printPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (j <= n - i + 1 || j >= n + i - 1)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    int height;
    std::cout << "Enter the height of the pattern: ";
    std::cin >> height;
    printPattern(height);
    return 0;
}
