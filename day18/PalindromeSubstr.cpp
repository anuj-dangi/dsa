#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//leetcode - 647
bool isPali(string s)
{
    int i=0,j=s.size()-1;

    while(i<j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;

}

int countSubstrings(string s)
{
    //brute force
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= s.size()-i; j++)
        {
            cout << s.substr(i, j) << endl;
            if (isPali(s.substr(i, j)))
            {
                //cout << i+1 << " " << j << endl;;
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    cout << countSubstrings("abc") << endl;
    return 0;
}