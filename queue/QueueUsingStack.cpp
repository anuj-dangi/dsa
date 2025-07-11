#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//leetcode - 232
class MyQueue
{

    stack<int> s1;
    stack<int> s2;
public:
    MyQueue()
    {
        //do nothing
    }

    void push(int x)
    {
        int size = s1.size();
        for(int i=0;i<size;i++)
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        for(int i=0;i<size;i++)
        {
            s1.push(s2.top());
            s2.pop();
        }

    }
                                          
    int pop()
    {
        int data = s1.top();
        s1.pop();

        return data;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << " ";
    q.push(5);
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    return 0;
}