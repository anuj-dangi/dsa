#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;

//leetcode -  15
//brute force //optimized(using sorting)
//best time complexity - O(n)
vector<vector<int>> threeSum(vector<int> vec, int target)
{
        
    vector<vector<int>> ans;
    set<vector<int>> s;
    //brute force
    for(int i=0;i<vec.size();i++)
    {
        for(int j=i+1;j<vec.size();j++)
        {
            for(int k=j+1;k<vec.size();k++)
            {
                if(vec[i] + vec[j] + vec[k] == target)
                {
                    vector<int> trip = {vec[i], vec[j], vec[k]};
                    sort(trip.begin(), trip.end());

                    if(s.find(trip) == s.end())
                    {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
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

    vector<vector<int>> ans = threeSum(vec, target);

    for(vector<int> v : ans)
    {
        for(int ele : v)
            cout << ele << " ";
        cout << endl;
    }
    
    return 0;
}