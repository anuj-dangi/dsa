#include<iostream>
#include<vector>
#include<set>
using namespace std;

//leetcode -  15
//brute force //optimized(using sorting)
//best time complexity - O(n)
vector<vector<int>> threeSum(vector<int> vec, int target)
{
        
    vector<vector<int>> ans;
    //brute force
    for(int i=0;i<vec.size();i++)
    {
        for(int j=i+1;j<vec.size();j++)
        {
            for(int k=j+1;k<vec.size();k++)
            {
                if(vec[i] + vec[j] + vec[k] == target)
                {
                        
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    set<int> ans = threeSum(vec, target);

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}