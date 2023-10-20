#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Traverse(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

struct node *addAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;

    head = ptr;
    return head;
}

struct node *addtoEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
    return head;
}

struct node *create(struct node *head)
{
    int i, n, data;
    printf("enter the number of nodes : \n");
    scanf("%d", &n);

    head = NULL;

    if (n == 0)
        return head;

    printf("enter the element to be entered at beginning \n");
    scanf("%d", &data);

    head = addAtBeg(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("enter the element to be inserted : \n");
        scanf("%d", &data);
        head = addtoEnd(head, data);
    }
    return head;
}

struct node *deleteAtFirst(struct node *head)
{

    if (head == NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteOnlyNode(struct node *head)
{
    head == NULL;
    return head;
}

struct node *deleteBetween(struct node *head, int valueToBeDel)
{
    struct node *ptr = head;
    struct node *tmp;
    while (ptr != NULL)
    {
        if (ptr->next->data == valueToBeDel)
        {
            tmp = ptr->next;
            ptr->next = tmp->next;
            free(tmp);
            return head;
        }
        ptr = ptr->next;
    }
}

struct node *delete(struct node *head, int valueToBeDel)
{

    struct node *temp, *p;

    if (head == NULL)
    {
        printf("list is empty \n");
        return head;
    }

    if (head->data == valueToBeDel)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    p = head;

    while(p->next != NULL)
    {
        if (p->next->data == valueToBeDel)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return head;
        }
        p = p->next;
    }

    printf("the data was not found in the list \n");
    return head;
}
// a function to count the number of nodes in the list

int count(struct node *head, int counter)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

int main()
{
    struct node *head = NULL;
    int ch, counter = 0, data;

    while (1)
    {
        counter = count(head, counter);
        printf("press 1 for creation of list \n");
        printf("press 2 for deletion of first node in the  list \n");
        printf("press 3 for deletion in between the node \n");
        printf("press 4 for deletion of the node \n");
        printf("press 5 for traversing \n");
        printf("press 6 for exit \n");
        printf("enter your choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            head = counter == 1 ? deleteOnlyNode(head) : deleteAtFirst(head);
            break;
        case 3:
            printf("enter the item to be deleted : ");
            scanf("%d", &data);
            head = deleteBetween(head, data);
            break;
        case 4:
            printf("enter the item to be deleted : ");
            scanf("%d", &data);
            head = delete(head, data);
            break;
        case 5:
            Traverse(head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("enter correct choice ");
        }
    }

    return 0;
}
