#include <iostream>
#include <vector>
#include <set>
using namespace std;

//leetcode - 39
//time complexity - O(exponential)
set<vector<int>> s;
void helper(vector<int> &arr, int target, vector<int> temp, vector<vector<int>> &ans, int i)
{
    if (i == arr.size())
        return;
    if (target == 0)
    {
        if (s.find(temp) == s.end())
        {
            s.insert(temp);
            ans.push_back(temp);
        }
        return;
    }

    if (target < 0)
        return;

    temp.push_back(arr[i]);
     // single
    helper(arr, target - arr[i], temp, ans, i + 1); //more than one
    helper(arr, target - arr[i], temp, ans, i);
    //backtracking
    temp.pop_back();
    //excluding
    helper(arr, target, temp, ans, i + 1);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;
    vector<int> temp;

    helper(candidates, target, temp, ans, 0);

    return ans;
}

int main()
{
    vector<int> arr = {2,3,5};
    vector<vector<int>> ans = combinationSum(arr, 8);

    for(vector<int> vi : ans)
    {
        for(int ele : vi)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}