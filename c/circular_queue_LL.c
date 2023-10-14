#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d) 
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = d;
	new->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = new;
		rear->next = front;
	}
	else
	{
		rear->next = new;
		rear = new;
		new->next = front;
	}
} 
int dequeue() 
{
	struct node* temp;
	temp= front;
    int element;
    element=front->data;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");

	else if(front == rear){
		front = rear = NULL;
		free(temp);
	}
	else{
		front = front->next;
		rear->next = front;
		free(temp);
	}
    return element;
	
	
}
void display(){

	struct node* temp;
	temp= front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",temp->data);
			temp = temp->next;
		}while(temp != front);
	}
}
void main()
{
	int ch,n,i=0,num,y;
	printf("Enter Your Choice:-");

	do
    {
    printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

	switch(ch){
		case 1:printf("\nEnter the no. of elements: ");
				scanf("%d",&n);
				printf("\nEnter your data\n");
				while(i<n){
					scanf("%d",&num);
					enqueue(num);
					i++;
				}
				break;
		case 2:printf("Element deleted==>%d",dequeue());
				break;
		case 3:display();
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
        printf("\ndo you want to continue:");
        scanf("%d",&y);
    }while(y==1);

}
