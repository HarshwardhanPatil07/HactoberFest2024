#include <iostream>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class stack
{
    node<T> *head;

public:
    int size;
    stack()
    {
        head = NULL;
        size = 0;
    }
    void push(T element)
    {
        node<T> *newnode = new node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
        return;
    };
    T top()
    {
        if (head == NULL)
        {
            cout << "empty stack" << endl;
            return 0;
        }
        cout << "the element is " << head->data << endl;
        return 0;
    };
    T pop()
    {
        if (head == NULL)
        {
            cout << "empty stack" << endl;
            return 0;
        }
        T ans = head->data;
        node<T> *temp = head;
        head = head->next;
        delete temp;
        size--; 
        return ans;
    };
    bool isEmpty()
    {
        return (head == NULL);
    };

    int getsize()
    {
        return size;
    }
};

int main()
{
    // demo-1
    //  stack<int> s1;
    //  s1.push(9);
    //  s1.push(8);
    //  s1.push(7);
    //  s1.push(4);
    //  s1.pop();
    //  s1.top();
    //  cout<<s1.getsize()<<endl;
    //  cout<<s1.isEmpty()<<endl;

    // demo-2
    stack<char> s2;
    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);
    s2.top();
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.getsize() << endl;
    cout << s2.isEmpty() << endl;
}