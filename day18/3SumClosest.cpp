#include <iostream>
#include <vector>
using namespace std;

//leetcode - 
int threeSumClosest(vector<int> &nums, int target)
{
    //brute force
    int ans = nums[0]+nums[1]+nums[2];

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (abs(target - ans) >= abs(target - (nums[i] + nums[j] + nums[k])))
                {
                    ans = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {10,20,30,40,50,60,70,80,90};
    cout << threeSumClosest(nums, 1) << endl;
    return 0;
}