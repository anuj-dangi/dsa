#include <iostream>
#include <vector>
using namespace std;

//Using sliding window approach
bool checkInclusion(string s1, string s2)
{

    if (s1.size() > s2.size())
        return false;
    vector<int> s1freq(26, 0);

    for (int i = 0; i < s1.size(); i++)
    {
        s1freq[s1[i] - 'a']++;
    }

    int window = s1.size();

    for (int i = 0; i < s2.size() + 1 - window; i++)
    {
        vector<int> s2freq(26, 0);

        for (int j = i; j < i + window; j++)
        {
            s2freq[s2[j] - 'a']++;
        }

        if (s1freq == s2freq)
            return true;
    }

    return false;
}

int main()
{

    cout << checkInclusion("ab", "pekbaoo") << endl;
    return 0;
}