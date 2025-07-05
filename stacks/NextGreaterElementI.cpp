#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//leetcode - 496
vector<int> nextGreater(vector<int> nums1, vector<int> nums2)
{
    unordered_map<int, int> m;

    stack<int> s;
    vector<int> ans(nums1.size(), -1);

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() < nums2[i])
        {
            s.pop();
        }

        if (s.empty())
            m.emplace(nums2[i], -1);
        else
        {
            m.emplace(nums2[i], s.top());
        }

        s.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = m[nums1[i]];
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreater(nums1, nums2);

    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}