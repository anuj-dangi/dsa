#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int max(vector<int> nums, int i, int j, int &l)
{
    int max = nums[i];
    l = i;

    for (int p = i + 1; p < j; p++)
    {
        if (max < nums[p])
        {
            max = nums[p];
            l = p;
        }
    }
    return max;
}

// leetcode - 239
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // brute force -> gives tle
    //  vector<int> ans;
    //  int index;

    // int m = max(nums, 0, k, index);
    // ans.push_back(m);

    // for(int i=1;i<nums.size()-k+1;i++)
    // {
    //     if(index == i-1)
    //     {
    //         m = max(nums, i, i+k, index);
    //     }
    //     else
    //     {
    //         if(m < nums[i+k-1])
    //         {
    //             m = nums[i+k-1];
    //             index = i+k-1;
    //         }
    //     }
    //     ans.push_back(m);
    // }

    // return ans;

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans = maxSlidingWindow(nums, 3);

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}