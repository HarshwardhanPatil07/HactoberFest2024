#include <stdio.h>
#include <stdlib.h>

// structure for dll
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// function for traversing through the dll( double linked list )
void traverse(struct node *head)
{

    if (head == NULL)
    {
        printf("list is empty");
    }

    printf("list is : ");
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
}

// function for adding node at beginning of the list

struct node *addAtBeg(struct node *head, int data)
{
    // incase the list is totally empty
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;

    if (head == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
    }

    head = temp;
    return head;
}

struct node *addtoEmpty(struct node *head, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    head = tmp;
    return head;
}

struct node *addtoEnd(struct node *head, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
    tmp->prev = p;
    tmp->next = NULL;
    return head;
}

struct node *create(struct node *head)
{
    int n, i, data;
    struct node *temp;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    printf("enter your element : ");
    scanf("%d", &data);
    head = addtoEmpty(head, data);
    for (i = 2; i <= n; i++)
    {
        printf("enter your element : ");
        scanf("%d", &data);
        temp = addtoEnd(head, data);
    }

    return head;
}

struct node *deleteOnly(struct node *head)
{
    free(head);
    return NULL;
}

struct node *delete(struct node *head, int data)
{
    struct node *tmp;
    if (head == NULL)
    {
        printf("list is empty \n");
        return head;
    }

    if (head->next == NULL)
    {
        if (head->data == data)
        {
            head = NULL;
            free(head);
            return head;
        }
        else
        {
            printf("data not found \n");
            return head;
        }
    }

    if (head->data == data)
    {
        tmp = head;
        head = head->next;
        head->prev = NULL;
        free(tmp);
        return head;
    }

    tmp = head->next;
    if (tmp->next != NULL)
    {
        if (tmp->data == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return head;
        }
        tmp = tmp->next;
    }

    if (tmp->data == data)
    {
        tmp->prev->next = NULL;
        free(tmp);
        return head;
    }

    printf("data not found \n");
    return head;
}
// function to just count number of nodes in linkedlist
int count(struct node *head, int counter)
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        counter++;
    }
    return counter;
}
int main()
{
    struct node *head = NULL;
    int choice, data, counter;
    while (1)
    {
        counter = count(head, counter);
        printf("press 1 for creating a doubly linked list \n");
        printf("press 2 for traversing a double linked list \n");
        printf("press 3 for deleting a node in  double linked list \n");
        printf("press 3 for exiting the function \n");

        printf("enter your choice ! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            traverse(head);
            printf("\n");
            break;
        case 3:
            printf("enter your data to be delted : \n");
            scanf("%d", &data);
            head = delete (head, data);
            break;
        case 4:
            exit(0);

        default:
            printf("invalid choice ! \n");
        }
    }
    return 0;
}