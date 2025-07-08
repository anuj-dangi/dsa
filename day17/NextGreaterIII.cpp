#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode - 556
int nextGreaterElement(int n)
{
    vector<int> nums;

    while (n > 0)
    {
        nums.push_back(n % 10);
        n = n / 10;
    }
    reverse(nums.begin(), nums.end());
    int index = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = nums.size() - 1; i >= index + 1; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[index], nums[i]);
                break;
            }
        }
    }
    else
    {
        return -1;
    }

    reverse(nums.begin() + index + 1, nums.end());
    long long ans = 0;
    long pow = 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans += nums[i] * pow;
        pow *= 10;
    }

    if (ans > INT32_MAX)
        return -1;

    return ans;
}

int main()
{
    // Give lexicographically next
    cout << nextGreaterElement(315) << endl;
    return 0;
}