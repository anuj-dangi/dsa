#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int> vec)
{
    stack<int> s;
    vector<int> ans(vec.size(), 0);

    for(int i=vec.size()-1; i >= 0; i--)
    {
        while(!s.empty() && s.top() < vec[i])
        {
            s.pop();
        }

        if(s.empty())
            ans[i] = -1;
        else
        {
            ans[i] = s.top();
        }

        s.push(vec[i]);
    }
    return ans;
}

int main()
{
    vector<int> vec = {6, 8 ,0, 1, 3};
    vector<int> ans = nextGreater(vec);

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}