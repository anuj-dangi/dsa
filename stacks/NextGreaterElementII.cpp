#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//leetcode - 503
vector<int> nextGreater(vector<int> nums)
{
    vector<int> ans(nums.size(), -1);
    vector<int> sq;
    for(int i=nums.size()-2;i>=0;i--)
    {
        sq.push_back(nums[i]);
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!sq.empty() && sq.back() <= nums[i])
        {
            sq.pop_back();
        }

        ans[i] = sq.empty() ? -1 : sq.back();
        sq.push_back(nums[i]);
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