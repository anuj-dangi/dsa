#include<iostream>
#include<vector>
using namespace std;

//Leetcode - 74
//Time complexity O(log(m*n))
bool search(vector<vector<int>> vec, int target)
{
    int f = 0, l = vec.size()-1;
    int mid;
    while( f <= l)
    {
        mid = f + (l-f)/2;

        if(vec[mid][0] == target)
        {
            return true;
        }
        else if(vec[mid][0] >= target && vec[mid][vec[mid].size()-1] <= target)
            break;
        else if(vec[mid][0]  <= target && vec[mid][vec[mid].size()-1] >= target)
            break;
        else if(vec[mid][0] > target)
            l = mid -1;
        else 
            f = mid + 1;
    }

    int st = 1, end = vec[f].size()-1;
    f = mid;

    while( st <= end)
    {
        mid = st + (end-st)/2;

        if(vec[f][mid] == target)
        {
            return true;
        }
        else if(vec[f][mid] > target)
        {
            end = mid -1;
        }
        else 
            st = mid +1;
    }

    return false;
}

int main()
{
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16,20},{23, 30, 34, 60}};

    int target = 1;
    cout << "Present : " << search(vec, target) << endl;
    return 0;
}