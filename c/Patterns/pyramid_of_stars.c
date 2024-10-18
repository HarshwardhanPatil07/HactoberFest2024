//A program to draw pyramid for given number of rows
/*

Console Output:
Enter the number of rows: <user input>
5
**Pyramid of 5 rows**
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

*/
#include <stdio.h>
int main() {
   int i, space, rows, k = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   printf("**Pyramid of 5 rows**\n");
   for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
   return 0;
}
