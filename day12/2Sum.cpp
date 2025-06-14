#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// leetcode -  1
// brute force //optimized(using sorting)
// best time complexity - O(n)
vector<int> twoSum(vector<int> vec, int target)
{
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < vec.size(); i++)
    {
        int ele = target - vec[i];
        if (m.find(ele) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[ele]);
            break;
        }

        m[vec[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> vec = {5, 2, 11, 7, 15};
    int target = 9;

    vector<int> ans = twoSum(vec, target);

    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}