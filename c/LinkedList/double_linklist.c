#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *addr_next;
	struct Node *addr_prev;
}*start,*prev,*curr;

int main() {
	int c,ch,n,loc;
	start=NULL;
	do{
		printf("\n1.create D_linked list\n2.display\n3.insert first\n4.insert middle\n5.deletefirst\n6.DeleeteMiddle");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the any number:");
				scanf("%d",&n);
				create(n);
				display();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("\nEnter the number to insert first:");
				scanf("%d",&n);
				insertFirst(n);
				display();
				break;
			case 4:
				printf("\nEnter the number and location to insert middle:");
				scanf("%d%d",&n,&loc);
				insertMiddle(n,loc);
				break;
			case 5:
				deleteFirst();
				break;
			case 6:
				printf("\nEnter the location to delete middle:");
				scanf("%d",&loc);
				deleteMiddle(loc);
				
				
		}
	printf("\nDo you wnt to continue then press 1:");
	scanf("%d",&c);	
	}while(c==1);
	
	return 0;
}

void create(int);
void display();
void insertFirst(int);
void insertMiddle(int,int);
void deleteFirst();
void deletemiddle(int);


void create(int n){
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode->data = n;
	newnode->addr_next=NULL;
	newnode->addr_prev=NULL;
	
	if(start==NULL){
		start=newnode;
	}
	else{
		curr=start;
		while(curr->addr_next!=NULL){
			curr= curr->addr_next;
		}
		curr->addr_next=newnode;
		newnode->addr_prev=curr;
	}			
}

void display(){
	if(start==NULL){
		printf("link list is empty...");
	}
	else{
		curr=start;
		while(curr!=NULL){
			printf("| %u | %d | %u|--->",curr->addr_prev,curr->data,curr->addr_next);
			curr = curr->addr_next;
		}
	}
}

void insertFirst(int n){
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode->data=n;
	newnode->addr_next=start;
	newnode->addr_prev=NULL;
	start->addr_prev=newnode;
	start=newnode;
	printf("\nNode inserted......\n");
}

void insertMiddle(int n, int loc){
	struct Node *newnode;
	curr=start;
	prev=NULL;
	int cnt=1;
	while(cnt<loc){
		prev=curr;
		curr=curr->addr_next;
		cnt++;
	}
	
	newnode = malloc(sizeof(struct Node));
	newnode->data=n;
	prev->addr_next=newnode;
	newnode->addr_prev=prev;
	
	newnode->addr_next=curr;
	curr->addr_prev=newnode;
	printf("\nNode is inserted.....");
}

void deleteFirst(){
	curr=start;
	start=start->addr_next;
	start->addr_prev=NULL;
	curr->addr_prev=NULL;
	free(curr);
	printf("\nFirst node is deleted....");
}

void deleteMiddle(int loc){
	int cnt=1;
	struct Node*next;
	prev=NULL;
	curr=start;
	while(cnt<loc){
		prev=curr;
		curr=curr->addr_next;
		cnt++;
	}
	next=curr->addr_next;
	free(curr);
	prev->addr_next=next;
	next->addr_prev=prev;
	
	printf("\nmiddle node is deleted....");
}
		
		
		
		
