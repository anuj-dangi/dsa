#include <iostream>
#include <vector>
using namespace std;

//Total number of permutation - n!
//leetcode - 46
void printPermutation(vector<int> vec, int pos)
{
    if(pos == vec.size())
    {
        for(int ele : vec)
            cout << ele << " ";
        cout << endl;
        return ;
    }

    for(int i=pos;i<vec.size();i++)
    {
        swap(vec[i], vec[pos]);
        printPermutation(vec, pos+1);
        swap(vec[i], vec[pos]);
    }
}

void permutation(vector<int> vec)
{
    printPermutation(vec, 0);
}

int main()
{
    vector<int> vec = {1, 2, 3};

    permutation(vec);
    return 0;
}