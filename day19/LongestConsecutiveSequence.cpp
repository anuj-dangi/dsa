#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode - 128
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end()); //avg - nlogn

    int count = 0, len = 0;

    //O(n)
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] - nums[i - 1] == 1)
        {
            len++;
        }
        else if (nums[i] == nums[i - 1])
            continue;
        else
            len = 0;

        count = max(count, len);
    }

    return count + 1;
}

int main()
{
    vector<int> nums = {100,4,200,1,3,2};

    cout << longestConsecutive(nums) << endl;
    
    return 0;
}