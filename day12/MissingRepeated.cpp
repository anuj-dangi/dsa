#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Time complexity - O(log(n*n))
//leetcode - 2965
vector<int> findMissingRepeatedValues(vector<vector<int>> vec)
{
    int n=vec.size();
    vector<int> ans;
    unordered_set<int> s;
    int a, b;
    int esum=0, asum=0;
    int k=1;

    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            if(s.find(vec[i][j]) != s.end())
            {
                a = vec[i][j];
            }
            s.insert(vec[i][j]);
            asum += vec[i][j];
        }
    }

    esum = (n*n*(n*n+1))/2;
    b = esum + a - asum;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main()
{
    vector<vector<int>> vec = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    vector<int> ans = findMissingRepeatedValues(vec);

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}