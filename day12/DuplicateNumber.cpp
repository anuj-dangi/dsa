#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//leetcode - 287

int findDuplicate(vector<int> &nums)
{
    //Time complexity - O(n)
    //Space complexity - O(n)
    // unordered_set<int> s;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (s.find(nums[i]) != s.end())
    //     {
    //         return nums[i];
    //     }
    //     s.insert(nums[i]);
    // }
    // return -1;

    //better approach
    //slow-fast pointer -> based on linked list
    //Time complexity -> O(n)
    //space complexity -> O(1)

    int slow=nums[0], fast=nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 3};

    cout << findDuplicate(vec) << endl;
    return 0;
}