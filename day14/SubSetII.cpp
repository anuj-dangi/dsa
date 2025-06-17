#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode - 90
void getSets(vector<int> &arr, vector<int> &ans, vector<vector<int>> &rans, int i)
{
    // base condition
    if (i == arr.size())
    {
        rans.push_back(ans);
        return;
    }

    // include
    ans.push_back(arr[i]);
    getSets(arr, ans, rans, i + 1);

    ans.pop_back(); // backtracking

    int idx = i + 1;
    while( idx < arr.size() && arr[idx] == arr[idx-1])  idx++;
    // exclude
    getSets(arr, ans, rans, idx);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> rans;
    vector<int> ans;

    getSets(nums, ans, rans, 0);

    return rans;
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<int> ans;

    subsetsWithDup(arr);
    return 0;
}