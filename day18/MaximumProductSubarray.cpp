#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// leetcode - 152
int maxProduct(vector<int> &nums)
{
    //brute force
    // int max = nums[0];

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int mul = 1;
    //     for (int j = i; j < nums.size(); j++)
    //     {
    //         mul *= nums[j];

    //         if (mul > max)
    //         {
    //             max = mul;
    //         }
    //     }
    // }

    // return max;

    //optimized
    //time complexity - O(n)
    int maxEle = nums[0], minEle = nums[0], ans = nums[0];

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<0)
        {
            swap(maxEle, minEle);
        }

        maxEle = max(maxEle, maxEle*nums[i]);
        minEle = min(minEle, minEle*nums[i]);

        ans = max(ans, maxEle);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, -4};
    cout << maxProduct(nums) << endl;
    return 0;
}