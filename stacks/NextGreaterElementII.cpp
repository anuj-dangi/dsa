#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//leetcode - 503
vector<int> nextGreater(vector<int> nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> s;
    for(int i=nums.size()-2;i>=0;i--)
    {
        s.push(nums[i]);
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!s.empty() && s.top() <= nums[i])
        {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 3};
    vector<int> ans = nextGreater(nums1);

    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}