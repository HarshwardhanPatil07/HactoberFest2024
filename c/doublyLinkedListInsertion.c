#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
void printList(struct node* n)
{
    int c=0;
    while (n != NULL) {
         if(c==0)//As there is no data in Head
            n = n->next;
        printf(" %d ", n->data);
        n = n->next;
        c++;
    }
}
void InsertFront(struct node *n,int num)
{
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=num;
    newNode->next=n->next;
    newNode->pre=n;
    n->next=newNode;
}
void Insert(struct node* prev,int num)
{
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=num;
    newNode->next=prev->next;
    prev->next=newNode;
}
void InsertBack(struct node* n,int num )
    {
    while(n->next!=NULL)//First travel to end node
    {
        n=n->next;
    } 
    struct node* newNode;//Add Node at end
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=num;
    newNode->next=NULL;
    n->next=newNode;
    }
int main()
{
    int num,l,opt,add;
    struct node* head=malloc(sizeof(struct node));//ALLOCATE AND DEFINE HEAD
    struct node* n=malloc(sizeof(struct node));
    n=head;
    head->next=NULL;
//SIZE OF LINKED LIST
    printf("enter size : ");
    scanf("%d",&l);
//CREATE LINKED LIST    
    for (int i=1;i<l+1;i++)
    {
        printf("enter element %d :",i);
        scanf("%d",&num);
        InsertBack(head,num);
    }
    printf("\nLinked List Created\n");
    printList(head);
    label:
    printf("\nWhere You Want To Insert\n");
    printf("Enter 1-Front 2-Anywhere 3-Back 4-Exit: ");
    scanf("%d",&opt);
    switch (opt)
    {
        case 1: printf("\nEnter the Number to insert\n");//Insert at front
                scanf("%d",&add);
                InsertFront(head,add);
                printf("\nNow List is : \n");
                printList(head);
                break;
        case 2: printf("\nEnter the Number to insert\n");//Insert anywhere
                scanf("%d",&add);
                printf("\nAter What element\n");
                int pre;
                scanf("%d",&pre);
                while(n->data!=pre)//traversed 
                {
                    n=n->next;
                } 
                Insert(n,add);
                printf("\nNow List is : \n");
                printList(head);
                break;
        case 3: printf("\nEnter the Number to insert\n");//Insert at back
                scanf("%d",&add);
                InsertBack(head,add);
                printf("\nNow List is : \n");
                printList(head);
                break;
        case 4: 
                return 0;        
    }
    goto label;
    return 0;
}
