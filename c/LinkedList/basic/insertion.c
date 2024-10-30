#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int info;
    struct node *next;
};

void Traverse(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = head;
    ptr->info = data;

    return ptr;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        return ptr; // If the list is empty, the new node becomes the head
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
    return head;
}

struct node *insertAt(struct node *head, int data, int item)
{
    struct node *temp, *p;
    p = head;

    while (p != NULL)
    {
        if (p->info == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = data;
            temp->next = p->next;
            p->next = temp;
            return head;
        }
        p = p->next; // Move to the next node
    }

    printf("Item not found!\n");
    return head;
}

struct node *insertBefore(struct node *head, int data, int item)
{
    struct node *temp, *p;
    if (head == NULL)
    {
        printf("list is empty \n");
        return head;
    }

    if (data == head->info)
    {
        temp->info = data;
        temp->next = head;
        head = temp;
        return head;
    }

    p = head;
    while (p->next != NULL)
    {
        if (p->next->info == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = data;
            temp->next = p->next;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    printf("item not present in the list \n");
    return head;
}

void search(struct node *head, int data)
{
    int flag = 0;
    struct node *ptr = head; // Start traversing from the head node

    while (ptr != NULL) // Traverse until the end of the list
    {
        if (ptr->info == data)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (flag)
    {
        printf("Data found!\n");
    }
    else
    {
        printf("Data not found\n");
    }
}


int main()
{
    /*here we are creating a nextedlist having
    only item which is the head */
    struct node *head;

    head = (struct node *)malloc(sizeof(struct node));

    head->info = 1;
    head->next = NULL;
    int choice;
    int item;
    do
    {

        printf("Please choose from the following menu : \n");
        printf("press 1 for insertion at beginning\n");
        printf("press 2 for insertion at end\n");
        printf("press 3 for insertion after a node\n");
        printf("press 4 for insertion before a node\n");
        printf("press 5 for searching \n");
        printf("press 6 for exiting\n");

        printf("enter your choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("enter your item to be inserted at the beginning : \n");
            scanf("%d", &item);
            head = insertAtBeg(head, item);
            Traverse(head);
            break;
        case 2:
            printf("enter your item to be inserted at the end: \n");
            scanf("%d", &item);
            head = insertAtEnd(head, item);
            Traverse(head);
            break;

        case 3:
            printf("enter your item to be inserted after: \n");
            scanf("%d", &item);
            printf("enter your data to be inserted after the item: \n");
            int data;
            scanf("%d", &data);
            head = insertAt(head, data, item);
            Traverse(head);
            break;

        case 4:
            printf("enter your item to be inserted before: \n");
            scanf("%d", &item);
            printf("enter your data to be inserted before the item: \n");

            scanf("%d", &data);
            head = insertBefore(head, data, item);
            Traverse(head);
            break;
        case 5:
            printf("enter the item to be searched: \n");
            scanf("%d", &data);
            search(head , data);
            insertBefore(head, data, item);
            
            break;
        case 6:
            exit(0);

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}