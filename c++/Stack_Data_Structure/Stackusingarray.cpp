
   // github username - RAGHAVS1304,
   // aim             - Implementation and application of stack data structure
   // date            - 16 October 2023


#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class stackusingarray
{
    T *data;                      
    int nextindex;
    int capacity;

public:
    stackusingarray() 
    {
        data = new T[4];
        nextindex = 0;
        capacity = 4; 
    }

    int size()
    {
        return nextindex;
    };
    bool isEmpty()
    {
        return (nextindex == 0);
    };
    void push(T element)
    { 
        if (nextindex == capacity)
        {
            T *newdata = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
        }

         data[nextindex] = element;
         nextindex++;
         return;
    };
    T top()
    {
         if (isEmpty())
         {
             cout << "stack is empty" << endl;
             return 0; 
         }

         return data[nextindex - 1];
    };
    T pop()
    {
         if (isEmpty())
         {
             cout << "stack is empty " << endl;
             return 0; 
         }
         nextindex--; 
         return data[nextindex];
    };
};
int main()
{

    stackusingarray<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}
