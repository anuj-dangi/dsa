#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//leetcode - 225
//using two queue
// class SUQ
// {
//     queue<int> q1;
//     queue<int> q2;
// public:

//     SUQ()
//     {
//         //do nothing
//     }

//     void push(int data)
//     {
//         q1.push(data);
//     }

//     int pop()
//     {
//         int ele;

//         while(!q1.empty())
//         {
//             ele = q1.front();
//             q1.pop();

//             if(!q1.empty())
//                 q2.push(ele);
//         }

//         q1.swap(q2);
        
//         while(!q2.empty())
//         {
//             q2.pop();
//         }

//         return ele;
//     }

//     bool empty()
//     {
//         return q1.empty();
//     }

//     int top()
//     {
//         int ele;

//         while(!q1.empty())
//         {
//             ele = q1.front();
//             q1.pop();
//             q2.push(ele);
//         }

//         q1.swap(q2);
//         while(!q2.empty())
//         {
//             q2.pop();
//         }
//         return ele;
//     }

// };

//using only one queue
class SUQ
{
    queue<int> q;

public:
    SUQ()
    {
        //do nothing
    }

    bool empty()
    {
        return q.empty();
    }

    void push(int data)
    {
        int size = q.size();
        q.push(data);

        for(int i=0;i<size;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int data = q.front();
        q.pop();
        return data;
    }

    int top()
    {
        return q.front();
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