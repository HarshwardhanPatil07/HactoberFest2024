#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int coE;
    int exp;
    struct node *next;
};

struct node *createPoly(struct node *ptr, int terms)
{

    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    int coE, exp;
    char ch;
    printf("Enter %d term value", terms);
    printf("Enter coefficient \n");
    scanf("%d", &tmp->coE);
    printf("Enter coefficient \n");
    scanf("%d", &tmp->exp);
    terms++;

    ptr->next = tmp;
    printf("Do you wish to continue ?");
    ch = getch();
    if (ch == 'Y' || ch == 'y')
    {
        return createPoly(ptr->next, terms);
    }
    else
    {
        return ptr;
    }
}

void displayPoly(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%dx^%d + ", ptr->coE, ptr->exp);
        ptr = ptr->next;
    }
    printf("x");
}

int main()
{

    struct node *head;
    int ch;
     while (1)
    {
    printf("Press 1 for creating polynomial \n");
    printf("Press 2 for displaying polynomial \n");
    printf("Press 1 for creating polynomial \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
   
        switch (ch)
        {
        case 1:
            head = createPoly(head, 1);
            break;

        case 2:
            displayPoly(head);
            break;
        case 3:
            exit(1);
        default:
            printf("enter valid choice !");
        }
    }

    return 0;
}