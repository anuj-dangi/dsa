#include <iostream>
#include <vector>

using namespace std;

// 238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

vector<int> productExceptSelf(vector<int>& nums)
{
    //First find the prefix multiplication for all terms and then do same for suffix terms
    int n = nums.size();
    vector<int> ans(n, 1);

    for(int i=1;i<n;i++)
    {
        ans[i] = ans[i-1]*nums[i-1];
    }

    int suffix = 1;
    for(int i=n-2;i>=0;i--)
    {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    vector<int> ans = productExceptSelf(vec);

    for(int ele : ans)
    {
        cout << ele  << " ";
    }
    return 0;
}