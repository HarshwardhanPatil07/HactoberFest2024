#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
void insert_at_beginning(struct node** head,int value)
{
    struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //checking if memory allocation failed or not
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //if the list is empty
    if(!(*head))
    {
       temp->next=(*head);
       temp->prev=(*head);
       *head=temp;
       return;
    }
    temp->next=(*head);//connecting temporary node to the first node
    (*head)->prev=temp;//now connecting first node to the temporary node
    temp->prev=NULL;//as now temporary node has become the first node so the its prev should hold NULL
    *head=temp;
    return;
}
void insert_at_end(struct node** head,int value)
{
    struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //if memory allocation fails
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //when no linked list is empty
    if(!(*head))
    {
       temp->next=(*head);
       temp->prev=(*head);
       *head=temp;
       return;
    }
    struct node *itr = *head;
    //traversing to the last node
    while(itr->next)
    itr=itr->next;
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
    return;
}
void insert_before_k(struct node** head,int value,int k)
{
    struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //when no linked list is empty
    if(!(*head))
    {
       temp->next=(*head);
       temp->prev=(*head);
       *head=temp;
       return;
    }
    if((*head)->data==k)
    {
        temp->next=*head;
        temp->prev=NULL;
        (*head)->prev=temp;
        *head=temp;
        return;
    }
    struct node*itr=*head;
    while(itr->next)//traversing till the last node
    {
        if(itr->next->data == k)
        {
            temp->next=itr->next;
            temp->prev=itr;
            temp->next->prev=temp;
            itr->next=temp;
            return;
        }
        itr=itr->next;
    }
    //inserting at the end when node not found
    printf("\n%d is not found so %d is inserted in end",k,value);
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
}
void insert_after_k(struct node** head,int value, int k)
{
    struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //when memory allocation fails
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    if(!(*head))
    {
       temp->next=(*head);
       temp->prev=(*head);
       *head=temp;
       return;
    }
    struct node*itr=*head;
    do
    {
        if(itr->data==k)
        {
            temp->next=itr->next;
            temp->prev=itr;
            if (itr->next) 
            {
                itr->next->prev = temp;
            }
            itr->next=temp;
            return;
        }
        itr=itr->next;
    }while(itr);
    //inserting at the end when node not found
    printf("%d is not found so %d is inserted at the end\n",k,value);
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
}
void delete_by_value(struct node** head,int k)
{
    //when list is empty
   if(!(*head))
   {
        printf("\nEmpty list");
        return;
   }
   struct node*itr=*head;
   if((*head)->data==k)//when the node to delete is head
   {
    *head=(*head)->next;
    (*head)->prev=itr->prev;
    free(itr);
    return;
   }
   while(itr)
   {
    if(itr->data==k)
    {
          if (itr->prev) 
            {
                itr->prev->next = itr->next;
            }
            if (itr->next) 
            {
                itr->next->prev = itr->prev;
            }
            //If the node to delete is the head
            if (*head == itr) 
            {
                *head = itr->next;
            }
        free(itr);
        return;
    }
    itr=itr->next;
   }
   printf("Node with value %d not found\n",k );
}  
void delete_head(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))
    {
        printf("\nEmpty list\n");
        return;
    }
    if(!((*head)->next))//if there is only one node in the linkedlist
    {
        *head=(*head)->next;
        free(*head);
        return;
    }
    *head=(*head)->next;//changing the pointer of head to point at second node in linkedlist
    free((*head)->prev);//freeing the first node
    (*head)->prev=NULL;//freeing the first node
}
void delete_tail(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))//or you can write it as *head==NULL
    {
        printf("\nEmpty list\n");
        return;
    }
    //if there is only one node
    if(!((*head)->next))
    {
        *head=(*head)->next;
        free(*head);
        return;
    }
    struct node*itr=*head;
    //iterating till the tail
    while(itr->next->next)
    {
        itr=itr->next;
    }
    itr->next = NULL;//assigning last node NULL
    free(itr->next);
}
void display_head(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))
    {
        printf("\nEmpty list\n");
        return;
    }
    //printing while traversing till last node
    struct node *itr=*head;
    while(itr)
    {
        printf("%d ----> ", itr->data);
        itr=itr->next;
    }
    printf("NULL\n");//to indicate the address stored by last node
}
void display_tail(struct node** head)
{
    //checking whether list it empty or not
    if(!(*head))
    {
        return;
    }
    //recurrively calling the function
    display_tail(&((*head)->next));
    //printing the node
    printf("%d --->", (*head)->data);//address of first node will be printed as data in this case
}
int main()
{
    struct node * head=NULL;
    char ch;
    int choice,data,value;
    do
    {
       printf("Enter your choice:\n\n1-Insert at beginning\n2-insert at end\n3-insert before a given value\n4-insert after a given value\n5-delete a node by value\n6-delete first node\n7-delete last node\n8-display node from head to tail\n9-display node form tail to head: \n");
       scanf("%d",&choice);
       switch (choice)
       {
            case 1:
            {
                printf("\nEnter the data to be inserted at the beginning: ");
                scanf("%d",&data);
                insert_at_beginning(&head,data);
                break;
            }
            case 2:
            {
                printf("\nEnter the data to be inserted at the end: ");
                scanf("%d",&data);
                insert_at_end(&head,data);
                break;
            }
            case 3:
            {
                printf("\nEnter the data to be inserted: ");
                scanf("%d",&data );
                printf("\nInsert before which value? ");//inserting before that value
                scanf("%d",&value);
                insert_before_k(&head,data,value);
                break;
            }
            case 4:
            {
               //inserting after k
               printf("\nEnter the data to be inserted : ");
               scanf("%d", &data);             
               printf("\nAfter what number you want to enter this element? ");
               scanf("%d",&value);
               insert_after_k(&head,data,value);
               break;
            }
            case 5:
            {
                //deleting a node by value
                printf("\nEnter the value of the node you want to delete: ");
                scanf("%d",&value);
                delete_by_value(&head,value);
                break;
            }
            case 6 :
            {
                //delete first node
                delete_head(&head);
                break;
            }
            case 7:
            {
                //delete last node
                delete_tail(&head);
                break;
            }
            case 8:
            {
                //display node from head to tail
                display_head(&head);
                break;
            }
            case 9:
            {
                //display node from tail to head
                display_tail(&head);
                break;
            }
            default:
            {
                printf("\nInvalid argument\n");
            }
        }
        printf("\nDo you want to continue: Y-yes or N-no: ");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
    while (head) 
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
