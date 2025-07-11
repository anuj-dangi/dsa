#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SUQ
{
    queue<int> q1;
    queue<int> q2;
public:

    SUQ()
    {
        //do nothing
    }

    void push(int data)
    {
        q1.push(data);
    }

    int pop()
    {
        int ele;

        while(!q1.empty())
        {
            ele = q1.front();
            q1.pop();

            if(!q1.empty())
                q2.push(ele);
        }

        q1.swap(q2);
        
        while(!q2.empty())
        {
            q2.pop();
        }

        return ele;
    }

    bool empty()
    {
        return q1.empty();
    }

    int top()
    {
        int ele;

        while(!q1.empty())
        {
            ele = q1.front();
            q1.pop();
            q2.push(ele);
        }

        q1.swap(q2);
        while(!q2.empty())
        {
            q2.pop();
        }
        return ele;
    }

};

int main()
{
    SUQ s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}