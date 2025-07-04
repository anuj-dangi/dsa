#include <iostream>
#include <stack>
using namespace std;

//leetcode - 20
bool isValid(string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }

    stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        else
        {
            if (!stack.empty() &&  (s[i] == stack.top()+2 || s[i] == ')' && stack.top() == '('))
            {
                stack.pop();
            }
            else
                return false;
        }
    }

    return stack.empty();
}

int main()
{
    cout << isValid("()");
    return 0;
}