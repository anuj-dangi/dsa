#include<iostream>
#include <vector>
using namespace std;

bool sorted(vector<int> nums, int n)
{
    if(n == 1)
        return nums[1] >= nums[0];
    else if(nums[n] >= nums[n-1])
        return sorted(nums, n-1);
    else
        return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size()-1;
    cout << "is the array sorted :" << sorted(nums, n);
    return 0;
}