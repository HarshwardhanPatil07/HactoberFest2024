#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *delete(struct node *tail, int data)
{
    printf("to be done soon \n");
}
struct node  *traverse(struct node *tail)
{
    struct node *p;
    if (tail == NULL)
    {
        printf("the list is empty \n");
        return tail;
    }

    p = tail->next;

    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != tail->next);
}
struct node *addAtBeg(struct node *tail , int data){
    struct node *tmp ;
    tmp= (struct node *)malloc(sizeof(struct node ));
    tmp->data = data;
    tmp->next= tail->next;
    tail->next = tmp;
    return tail;

}


struct node *addAttail(struct node *tail , int data){
        struct node *tmp ;
    tmp= (struct node *)malloc(sizeof(struct node ));
      tmp->data = data;
     
      tmp->next = tail->next ;
      tail->next = tmp;
      tail = tmp;
      return tail;

}

struct node *addToempty (struct node *tail , int data){
 struct node *tmp ;
    tmp= (struct node *)malloc(sizeof(struct node ));
    tmp->data = data;
    tail = tmp;
    tail->next = tail;
    return tail;

}
struct node *insert(struct node *tail ,int item , int data){
    struct node *tmp , *p ;
    p = tail->next;
    do{
        if(p->data==item){
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->next = p->next;
            p->next = tmp;
            if(p==tail){
                tail = tmp;
                return tail;
            }
            
        }
        p=p->next;
    }while( p != tail->next);
    printf("the item was not found! \n");
    return tail;
}
struct node *create(struct node *tail)
{
    int i , n , data;
    printf("enter the number of nodes : ");
    scanf("%d" , &n);

    tail = NULL;
    if(n==0){
        return tail;
    }
    printf("enter the element to be inserted : \n ");
    scanf("%d" , &data);
    tail = addToempty(tail , data );
    for(i = 2 ; i <= n ;i++){
            printf("enter the element to be inserted : \n ");
            scanf("%d" , &data);
            tail = addAttail(tail , data);
    }
    return tail;
}



int main()
{
    struct node *tail = NULL;
    int choice, data, counter;
    int item;
    while (1)
    {

        printf("press 1 for creating a circular linked list \n");
        printf("press 2 for traversing a circular linked list \n");
        printf("press 3 for insertion after a node \n");
        printf("press 3 for exiting the function \n");

        printf("enter your choice ! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tail = create(tail);
            break;
        case 2:
            traverse(tail);
            printf("\n");
            break;
        case 3:
            printf("enter your item to be inserted after : \n");
            scanf("%d", &item);
            printf("enter your data  : \n");
            scanf("%d", &data);
            tail = delete (tail, data);
            break;
        case 4:
            exit(0);

        default:
            printf("invalid choice ! \n");
        }
    }
    return 0;
}
