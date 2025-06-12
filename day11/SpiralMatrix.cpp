#include<iostream>
#include<vector>
using namespace std;

//leetcode - 54
//time complexity - o(m*n)
vector<int> spiralOrder(vector<vector<int>> vec)
{
    int m=vec.size()-1, n=vec[0].size()-1;
    int srow=0, scol=0;
    int erow=m, ecol=n;
    vector<int> ans;

    while(srow <= erow && scol <= ecol)
    {
        //top
        for(int i=scol;i<=ecol;i++)
            ans.push_back(vec[srow][i]);

        //right
        for(int i=srow+1;i<=erow;i++)
            ans.push_back(vec[i][ecol]);

        //bottom
        for(int i=ecol-1;i>=scol;i--)
            ans.push_back(vec[erow][i]);
        
        //left
        for(int i=erow-1;i>=srow+1;i--)
        {
            if(ecol == scol)
                break;
            ans.push_back(vec[i][scol]);
        }

        srow++; scol++; erow--; ecol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans = spiralOrder(vec);

    for(int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}