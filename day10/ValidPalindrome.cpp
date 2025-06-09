#include <iostream>
using namespace std;

//There is cpp inbuilt function to check if a char is alphanumeric or not
//isalnum();
bool isAlpha(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        return true;
    else
        return false;
}

bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;

    while (l <= r)
    {
        if (tolower(s[l]) == tolower(s[r]))
        {
            l++;
            r--;
        }
        else if (!(isalnum(s[l])))
        {
            l++;
        }
        else if (!isalnum(s[r]))
            r--;
        else
            return false;
    }
    return true;
}

int main()
{
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
}