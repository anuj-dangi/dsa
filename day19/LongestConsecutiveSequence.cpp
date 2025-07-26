#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// leetcode - 128
int longestConsecutive(vector<int> &nums)
{
     if (nums.size() == 0)
         return 0;
    // sort(nums.begin(), nums.end()); //avg - nlogn

    // int count = 0, len = 0;

    // //O(n)
    // for (int i = nums.size() - 1; i >= 1; i--)
    // {
    //     if (nums[i] - nums[i - 1] == 1)
    //     {
    //         len++;
    //     }
    //     else if (nums[i] == nums[i - 1])
    //         continue;
    //     else
    //         len = 0;

    //     count = max(count, len);
    // }

    // return count + 1;

    //O(n)
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;
    for (int num : numSet)
    {
        // Only start counting from the beginning of a sequence
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentLength = 1;
            while (numSet.find(currentNum + 1) != numSet.end())
            {
                currentNum++;
                currentLength++;
                
            }
            maxLength = max(maxLength, currentLength);
            
        }
        
    }
    return maxLength;
    
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(nums) << endl;

    return 0;
}