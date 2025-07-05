#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> s;
    int min;

    void push(int val)
    {
        if(s.empty())
        {
            s.push(val);
            min = val;
        }
        else{
            if(val < min)
            {
                s.push(2*val-min);
                min = val;
            }
            else
            {
                s.push(val);
            }
        }
    }

    void pop()
    {
        if (s.top() < min)
        {
            min = (2*min) - s.top();
        }

        s.pop();
    }

    int top()
    {
        if(s.top()  < min)
        {
            return min;
        }
        return s.top();
    }

    int getMin()
    {
        return min;
    }
};

int main()
{
    MinStack m;
    cout << m.getMin() << " ";  //garbage value
    m.push(-2);
    m.push(0);
    m.push(-3);
    cout << m.getMin() << " ";
    m.pop();
    cout << m.top() << " ";
    cout << m.getMin() << " ";
    return 0;
}