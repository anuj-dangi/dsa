#include <iostream>
#include <vector>
using namespace std;

bool isPali(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void helper(string s, vector<string> &part, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(part);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string subPart = s.substr(0, i + 1);

        if (isPali(subPart))
        {
            part.push_back(subPart);
            helper(s.substr(i + 1), part, ans);
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> part;

    helper(s, part, ans);

    return ans;
}

int main()
{
    string s = "aaba";
    vector<vector<string>> ans = partition(s);

    for(vector<string> vs : ans)
    {
        for(string ele : vs)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}