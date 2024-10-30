#include<iostream>             /************ at start **************/
using namespace  std;

struct node{
        public:
        int data;
        node* next;
        
        node(int data){
            this->data=data;
            this->next=NULL;

        }
};


void inerstionatthestart(node* &head,int data){
    node* newnode = new node(data);
    newnode -> next = head;
    head = newnode;
    
}



void print(node* &head){
    node* newnode = head;

    while(newnode != NULL){
        cout<<newnode -> data<<" ";
        newnode = newnode -> next;
    }
    cout<<endl;
}



int main (){
    node* head = new node(12);
    
    print(head);
    inerstionatthestart(head,22);
    // inerstionatthestart(head,25);
    // inerstionatthestart(head,26);
    // inerstionatthestart(head,27);
    print(head);

    
    return 0;
}




#include<iostream>
using namespace std;                                   //**********  at ending *********/


class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};



void insertend(node* &tail, int d){
    node* new_node = new node(d);
    tail->next = new_node;
    tail = new_node;
}


void print(node* &head){
    node* new_node = head;

    while(new_node != NULL){
        cout<<new_node -> data<<" ";
        new_node = new_node -> next;
    }
    cout<<endl;
}


int main(){
    node* node1 = new node(10);     //new node
    node* head = node1;
    node* tail = node1;
    print(head);
    insertend(tail,12);
    print(head);
    

    return 0;

}     

