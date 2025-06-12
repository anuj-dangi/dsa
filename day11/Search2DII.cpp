#include<iostream>
#include<vector>
using namespace std;

//Leetcode - 240
//Time complexity O(m+n) > O(log(m*n))
bool search(vector<vector<int>> vec, int target)
{
    int i=0,j=vec[i].size()-1;

    while(i<vec[i].size() && j >= 0)
    {
        if(vec[i][j] == target)
            return true;
        else if(vec[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    vector<vector<int>> vec = {{1,4, 7,11,15}, {2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    int target = 15;
    cout << "Present : " << search(vec, target) << endl;
    return 0;
}