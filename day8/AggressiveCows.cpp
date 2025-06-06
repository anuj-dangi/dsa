#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &nums, int m, int mid)     //O(N)
{

    int cows = 1, lastStallPos = nums[0];

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] - lastStallPos >= mid)
        {
            cows++;
            lastStallPos = nums[i];
        }
        if(cows == m)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int m)        //O()
{
    sort(nums.begin(), nums.end());     //O(N*logN)

    int n = nums.size();
    int max=0, min=0;

    for(int ele : nums)
    {
        if(max < ele)
        {
            max = ele;
        }
        if(min > ele)
        {
            min = ele;
        }
    }

    int l=1, r=max-min;
    int mid, ans=-1;

    while(l<=r)     //O(Log(range)*N)
    {
        mid = l + (r-l)/2;

        if(isValid(nums, m, mid))   //Right
        {
            ans = mid;
            l = mid+1;
        }
        else    //Left
            r = mid-1;
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 4, 2, 9};
    int m =2;

    cout << "Min Distance : " << aggressiveCows(vec, m);
    return 0;
}