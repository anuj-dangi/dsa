#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

//leetcode - 387
int firstUniqChar(string s)
{
    //brute force 
    //time complexity - O(n*n)
    // for (int i = 0; i < s.size(); i++)
    // {
    //     bool found = false;
    //     for (int j = 0; j < s.size(); j++)
    //     {
    //         if (i != j && s[i] == s[j])
    //             found = true;
    //     }

    //     if (found == false)
    //         return i;
    // }

    // return -1;

    //time complexity - O(n)
    unordered_map<char, int> m;
    queue<char> q;

    for(int i=0;i<s.size();i++)
    {
        if(m.find(s[i]) == m.end())
        {
            m.emplace(s[i], 1);
        }
        else
            m[s[i]]++;
    }

    for(int i=0;i<s.size();i++)
    {
        if(m[s[i]] == 1)
            return i;
    }

    return -1;
}

int main()
{
    cout << firstUniqChar("leetcode") << endl;
    return 0;
}