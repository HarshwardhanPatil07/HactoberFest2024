#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int addition();
int subtract();
int multiply();
int divide();
int sq();
int sqrt1();
void exit();

int main()
{
    int op;
    do
    {
        printf (" Select an operation to perform the calculation in C Calculator: ");
        printf (" \n 1 Addition  \t \t 2 Subtraction \n 3 Multiplication \t 4 Division \n 5 Square \t \t 6 Square Root \n 7 Exit \n \n Please, Make a choice ");

        scanf ("%d", &op);

    switch (op)
    {
        case 1:
            addition();
            break;

        case 2:
            subtract();
            break;

        case 3:
            multiply();
            break;

        case 4:
            divide();
            break;

        case 5:
            sq();
            break;

        case 6:
            sqrt1();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf(" Something is wrong!! ");
            break;
    }
    printf (" \n \n ********************************************** \n ");
    } while (op != 7);

    return 0;
}

int addition()
{
    int i, sum = 0, num, f_num;
    printf (" How many numbers you want to add: ");
    scanf ("%d", &num);
    printf (" Enter the numbers: \n ");
    for (i = 1; i <= num; i++)
    {
        scanf(" %d", &f_num);
        sum = sum + f_num;
    }
    printf (" Total Sum of the numbers = %d", sum);
    return 0;
}

int subtract()
{
    int n1, n2, res;
    printf (" The first number is: ");
    scanf ("  %d", &n1);
    printf (" The second number is: ");
    scanf ("  %d", &n2);
    res = n1 - n2;
    printf (" The subtraction of %d - %d is: %d", n1, n2, res);
}

int multiply()
{
    int n1, n2, res;
    printf (" The first number is: ");
    scanf ("  %d", &n1);
    printf (" The second number is: ");
    scanf ("  %d", &n2);
    res = n1 * n2;
    printf (" The multiply of %d * %d is: %d", n1, n2, res);
}

int divide()
{
    int n1, n2, res;
    printf (" The first number is: ");
    scanf ("  %d", &n1);
    printf (" The second number is: ");
    scanf ("  %d", &n2);

    if (n2 == 0)
    {
        printf (" \n Divisor cannot be zero. Please enter another value ");
        scanf ("%d", &n2);
    }
    res = n1 / n2;
    printf (" \n The division of %d / %d is: %d", n1, n2, res);
}

int sq()
{
    int n1, res;
    printf (" Enter a number to get the Square: ");
    scanf ("  %d", &n1);

    res = n1 * n1;
    printf (" \n The Square of %d is: %d", n1, res);
}

int sqrt1()
{
    float res;
    int n1;
    printf (" Enter a number to get the Square Root: ");
    scanf ("  %d", &n1);

    res = sqrt(n1);
    printf (" \n The Square Root of %d is: %f", n1, res);
}
