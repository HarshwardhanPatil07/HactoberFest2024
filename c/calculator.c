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
int percentage();
int exponential();
int log_func();
int sin_func();
int cos_func();
int ln_func();
int tan_func();
void exit_func();

int main() {
    int op;
    do {
        printf("Select an operation to perform the calculation in C Calculator: ");
        printf("\n1 Addition  \t \t 2 Subtraction\n3 Multiplication \t 4 Division\n5 Square \t \t 6 Square Root\n7 Percentage  \t \t 8 Exponential\n9 Logarithm  \t \t 10 Sine\n11 Cosine  \t \t 12 Natural Logarithm\n13 Tangent  \t \t 14 Exit\n\nPlease, Make a choice: ");
        scanf("%d", &op);

        switch (op) {
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
                percentage();
                break;

            case 8:
                exponential();
                break;

            case 9:
                log_func();
                break;

            case 10:
                sin_func();
                break;

            case 11:
                cos_func();
                break;

            case 12:
                ln_func();
                break;

            case 13:
                tan_func();
                break;

            case 14:
                exit_func();
                break;

            default:
                printf("Something is wrong!! ");
                break;
        }
        printf("\n\n**********************************************\n");
    } while (op != 14);

    return 0;
}

void exit_func() {
    exit(0);
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

int percentage() {
    float n1, n2, res;
    printf(" Enter the number: ");
    scanf("%f", &n1);
    printf(" Enter the percentage: ");
    scanf("%f", &n2);
    res = (n1 * n2) / 100;
    printf(" %f%% of %f is: %f", n2, n1, res);
}

int exponential() {
    float n1, res;
    printf(" Enter a number: ");
    scanf("%f", &n1);
    res = pow(2.71828, n1); // Approximate value of e
    printf(" e^%f is: %f", n1, res);
}

int log_func() {
    float n1, res;
    printf(" Enter a number: ");
    scanf("%f", &n1);
    res = log(n1);
    printf(" Log(%f) is: %f", n1, res);
}

int sin_func() {
    float n1, res;
    printf(" Enter an angle in degrees: ");
    scanf("%f", &n1);
    n1 = n1 * M_PI / 180; // Convert degrees to radians
    res = sin(n1);
    printf(" Sin(%f degrees) is: %f", n1 * 180 / M_PI, res);
}

int cos_func() {
    float n1, res;
    printf(" Enter an angle in degrees: ");
    scanf("%f", &n1);
    n1 = n1 * M_PI / 180; // Convert degrees to radians
    res = cos(n1);
    printf(" Cos(%f degrees) is: %f", n1 * 180 / M_PI, res);
}

int ln_func() {
    float n1, res;
    printf("Enter a number: ");
    scanf("%f", &n1);
    res = log(n1);
    printf("ln(%f) is: %f", n1, res);
}

int tan_func() {
    float n1, res;
    printf("Enter an angle in degrees: ");
    scanf("%f", &n1);
    n1 = n1 * M_PI / 180; // Convert degrees to radians
    res = tan(n1);
    printf("Tan(%f degrees) is: %f", n1 * 180 / M_PI, res);
}
