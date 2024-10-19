#include<iostream>
using namespace std;



class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};



void insertnode(node* &head, int d){
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}



void insertend(node* &tail, int d){
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}



void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}



int main(){
    node* node1 = new node(10);     //new node
    // cout<<node1->data <<endl;
    //cout<<node1->next <<endl;
    node* head = node1;
    node* tail = node1;
    //print(head);
    insertend(tail,12);
    
    print(head);

    // insertnode(head , 12);
    // print(head);
    // insertend(tail,)

    return 0;

}

