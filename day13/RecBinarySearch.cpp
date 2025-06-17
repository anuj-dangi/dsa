#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, int l, int r)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binarySearch(nums, target, l, mid - 1);
        else
            return binarySearch(nums, target, mid + 1, r);
    }
    else
        return -1;
}

int main()
{
    vector<int> nums = {1, 4, 5, 6, 7, 11, 34};
    int target = 11;
    cout << binarySearch(nums, target, 0, nums.size()-1);
    return 0;
}
