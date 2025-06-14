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
    // for(int i=0;i<vec.size();i++)
    // {
    //     for(int j=i+1;j<vec.size();j++)
    //     {
    //         for(int k=j+1;k<vec.size();k++)
    //         {
    //             if(vec[i] + vec[j] + vec[k] == target)
    //             {
    //                 vector<int> trip = {vec[i], vec[j], vec[k]};
    //                 sort(trip.begin(), trip.end());

    //                 if(s.find(trip) == s.end())
    //                 {
    //                     s.insert(trip);
    //                     ans.push_back(trip);
    //                 }
    //             }
    //         }
    //     }
    // } 
    // return ans;

    //More optimized as time complexity -> O(n*n*log(unique triplets))
    // for(int i=0;i<vec.size();i++)
    // {
    //     int a = -vec[i];
    //     set<int> unique;
    //     for(int j=i+1;j<vec.size();j++)
    //     {
    //         int b = vec[j];
    //         int c = a - b;

    //         if(unique.find(c) != unique.end())
    //         {
    //             vector<int> v = {-a, b, c};

    //             sort(v.begin(), v.end());

    //             if(s.find(v) == s.end())
    //             {
    //                 s.insert(v);
    //                 ans.push_back(v);
    //             }
    //         }
    //         else
    //         {
    //             unique.insert(b);
    //         }
    //     }
    // }
    // return ans;

    //Best optimization using two pointer
    //time complexity - O(logn + n*n)
    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size();i++)
    {
        if(i > 0 && vec[i] == vec[i-1]) continue;
        int j=i+1, k=vec.size()-1;

        while(j < k)
        {
            int sum = vec[i]+vec[j]+vec[k];
            if(sum == 0)
            {
                vector<int> v = {vec[i],vec[j],vec[k]};

                ans.push_back(v);
                j++;    k--;
                while(j<k && vec[j] == vec[j-1])    j++;
            }
            else if(sum < 0)
            {
                j++;
            }
            else
                k--;
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