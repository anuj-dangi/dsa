#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPali(string s)
{
    string cs = s;
    reverse(cs.begin(), cs.end());

    return (cs == s);
}

void helper(string s, string &ans, int i)
{
    if (i == 0)
    {
        return;
    }

    for (int j = 0; j < s.size()-i+1; j++)
    {
        if (isPali(s.substr(j, j+i)))
        {
            ans = s.substr(j, j+i);
            return;
        }
    }
    helper(s, ans, i - 1);
}

string longestPalindrome(string s)
{
    string ans = "";
    string temp = "";
    helper(s, ans, s.size());
    return ans;
}

int main()
{
    cout << longestPalindrome("cbbd");
    return 0;
}