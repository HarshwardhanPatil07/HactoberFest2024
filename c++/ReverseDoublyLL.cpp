#include<iostream>
using namespace std;
class Node{
    public:
    int data;
Node* next = NULL;
Node* prev = NULL;
Node(int d){
    this->data = d;
    this->next = NULL;
    this->prev =  NULL;
}
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insert(Node* &head,int d){
    Node* temp  = new Node(d);
temp->next = head;
head->prev = temp;
head = temp;
}
Node* reverse(Node* &head){
    Node* temp = head;

while(temp != NULL){
    Node* store = temp->next;
     temp->next = temp->prev;
temp->prev = store;
head = temp;
temp = store;
}
//for using this condition we have to change print function temp = temp->next to temp = temp->prev
// while(temp != NULL){
//     head = temp;
//     temp = temp->next;
// }
return head;
}
int main(){
Node* node1 = new Node(7);
Node* head = node1;
insert(head,5);
insert(head,3);
insert(head,1);
print(head);
Node* result = reverse(head);
print(result);
  return 0;
}