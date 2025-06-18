#include <iostream>
#include <vector>
using namespace std;

//Total number of permutation - n!
//time complexity - O(n!*n)(total ans * how we reach)
//space complexity - O(n! + n) -> O(n!)
void printPermutation(string s, int pos)
{
    if(pos == s.size())
    {
        for(char ele : s)
            cout << ele << " ";
        cout << endl;
        return ;
    }

    for(int i=pos;i<s.size();i++)
    {
        swap(s[i], s[pos]);
        printPermutation(s, pos+1);
        //backtracking
        swap(s[i], s[pos]);
    }
}

void permutation(string s)
{
    printPermutation(s, 0);
}

int main()
{
    string s = "abc";

    permutation(s);
    return 0;
}