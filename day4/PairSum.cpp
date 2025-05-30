#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int>& nums, int target)
{
    vector<int> ans;

    /*Brute-Force approach
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        }
    }
    */
    //Using advantage of sorted array
    /*

    */
    int l = 0;
    int r = nums.size()-1;

    while(l<r)
    {
        int sum = nums[l] + nums[r];
        if(sum == target)
        {
            ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            return ans;
        }
        else if(sum > target)
        {
            r--;
        }
        else
            l++;
    }

    return ans;
}

int main()
{
    //The input vector is sorted
    vector<int> vec = {2, 5, 7, 11};
    int target  = 13;

    vector<int> ans = pairSum(vec, target);
    for(int ele : ans)
    {
        cout << ele << " ";
    }

    return 0;
}