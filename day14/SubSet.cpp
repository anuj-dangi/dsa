#include<iostream>
#include <vector>
using namespace std;

//Time complexity - O((2^n)*n)
void printSubSets(vector<int> &arr, vector<int> &ans, int i)
{
    //base condition
    if(i == arr.size())
    {
        for(int ele : ans)
            cout << ele << " ";
        cout << endl;
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubSets(arr, ans, i+1);

    ans.pop_back(); //backtracking
    //exclude
    printSubSets(arr, ans, i+1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    printSubSets(arr, ans, 0);
    return 0;
}