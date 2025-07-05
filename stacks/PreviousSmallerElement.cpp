#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> vec)
{
    stack<int> s;
    vector<int> ans(vec.size(), 0);

    for(int i=0; i<vec.size();i++)
    {
        while(!s.empty() && s.top() >= vec[i])
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
    vector<int> vec = {3, 1, 0, 8, 6};
    vector<int> ans = prevSmaller(vec);

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}