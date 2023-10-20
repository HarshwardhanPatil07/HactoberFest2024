#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void Traverse(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d->", ptr->info);
        ptr = ptr->next;
    }
}

struct node *addAtBeg(struct node *head , int data ){
    struct node *ptr = (struct node * ) malloc(sizeof(struct node));
    ptr->info = data;
    ptr->next = head;
    
    head = ptr;
    return head;
}


struct node * search(struct node *head , data){
    if(head->info == data){
        printf("data found");
    }

        struct node *ptr  = (struct node * ) malloc(sizeof(struct node));
        while(ptr->next != NULL){
            if(ptr->info == data){
                printf("data found!");
                return data;
            }
        }
        printf("data not found");
        return head;
}


struct node *addtoEnd(struct node *head , int data){
    struct node *ptr  = (struct node * ) malloc(sizeof(struct node));
   ptr->info = data;
   ptr->next = NULL;


 struct node *temp = head;
   while(temp->next != NULL){
    temp = temp->next;
   }

   temp->next = ptr;
   return head;
  
 
}

struct node *create(struct node *head){
    int i  , n ,data;
    printf("enter the number of nodes : \n");
    scanf("%d" , &n);

    head= NULL;

    if(n==0)
      return head;

    printf("enter the element to be entered at beginning \n");
    scanf("%d"  , &data);

    head = addAtBeg(head , data);

   for(i = 2 ; i <=  n ; i++){
    printf("enter the elemtn to be inserted :");
    scanf("%d" , &data);
    head = addtoEnd(head , data);
   }
return head;
}




int main()
{

    struct node *head;
    
    head = create(head);
    Traverse(head);
    return 0;
}