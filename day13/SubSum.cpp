#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//leetcode - 560
int subArraySum(vector<int> nums, int target)
{
    int count = 0;
    //Time complexity - O(n*n)
    //Space complexity - O(1)
    //brute force
    // for(int i=-0;i<nums.size();i++)
    // {
    //     int sum = 0;
    //     for(int j=i;j<nums.size();j++)
    //     {
    //         sum += nums[j];
    //         if(sum == target)
    //         {
    //             count++;
    //         }
    //     }
    // }

    //Optimize approach - Prefix Sum
    //Time complexity - O(n)
    //Space complexity - O(n)
    vector<int> ps;
    int psum = 0;

    for(int i=0;i<nums.size();i++)
    {
        psum += nums[i];
        ps.push_back(psum);
        if(psum == target)
            count++;
    }

    unordered_map<int, int> m;
    for(int i=0;i<nums.size();i++)
    {
        int val = ps[i] - target;

        if(m.find(val) != m.end())
            count += m[val];
        
        if(m.find(ps[i]) == m.end())
        {
            m[ps[i]] = 0;
        }
        m[ps[i]]++;
    }
    return count;
}

int main()
{
    vector<int> vec = {9,4,20,3,10,5};
    int target = 33;

    cout << subArraySum(vec, target) << endl;
    return 0;
}