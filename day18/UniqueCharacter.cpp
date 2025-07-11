#include <iostream>
#include <vector>
using namespace std;

int firstUniqChar(string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < s.size(); j++)
        {
            if (i != j && s[i] == s[j])
                found = true;
        }

        if (found == false)
            return i;
    }

    return -1;
}

int main()
{
    return 0;
}