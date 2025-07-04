#include <iostream>
#include <vector>
using namespace std;

//last in first out
class Stack
{
    vector<int> s;

public:
 
    //O(1)
    void push(int val)
    {
        s.push_back(val);
    }
    //O(1)
    void pop()
    {
        s.pop_back();
    }
    //O(1)
    int top()
    {
        return s[s.size()-1];
    }

    bool empty()
    {
        return s.empty();
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