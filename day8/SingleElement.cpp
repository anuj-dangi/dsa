#include <iostream>
#include <vector>
using namespace std;

// Intution -> we will try to find the sorted side and then perform binary seach on that side
int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int l = 0, r = nums.size() - 1;
    int mid;

    if (nums[l] != nums[l + 1])
    {
        return nums[l];
    }
    else if (nums[r] != nums[r - 1])
    {
        return nums[r];
    }

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {0, 0, 1, 2, 2};

    cout << "Element : " << singleNonDuplicate(vec) << "\n";

    return 0;
}