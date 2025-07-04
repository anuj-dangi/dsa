#include <iostream>
#include <vector>
#include <list>
using namespace std;

//last in first out
class Stack
{
    list<int> ll;

public:
 
    //O(1)
    void push(int val)
    {
        ll.push_front(val);
    }
    //O(1)
    void pop()
    {
        ll.pop_front();
    }
    //O(1)
    int top()
    {
        return ll.front();
    }

    bool empty()
    {
        return ll.empty();
    }
};

int main()
{
    Stack stack;
    stack.push(6);
    stack.push(10);
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return 0;
}