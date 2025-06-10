#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{

    // int i = 0;
    // while (s[i] == ' ')
    //     i++;

    // s.erase(0, i);

    // i = s.size() - 1;
    // int count = 0;
    // while (s[i] == ' ')
    // {
    //     count++;
    //     i--;
    // }

    // s.erase(i + 1, count);

    // i = s.size() - 1;
    // string output = "";
    // count = 0;
    // string temp = "";
    // while (i >= 0)
    // {
    //     if (s[i] != ' ')
    //     {
    //         if (count > 0)
    //         {
    //             output += temp;
    //             temp = "";
    //             output += " ";
    //             count = 0;
    //         }

    //         temp = s[i] + temp;
    //     }

    //     if (s[i] == ' ')
    //         count++;
    //     i--;
    // }

    // return output + temp;

    //using reverse function

    reverse(s.begin(), s.end());

    string ans = "";
    for(int i=0;i<s.size();i++)
    {
        string word = "";

        while(i<s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        if(word.size() > 0)
        {
            reverse(word.begin(), word.end());

            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main()
{

    cout << reverseWords("  Hello  World  ") << endl;
    return 0;
}