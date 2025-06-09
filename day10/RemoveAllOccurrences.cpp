#include <iostream>
using namespace std;

string removeOccurrences(string s, string part)
{
    // int m = part.size();

    // int index = 0;
    // while (index <= (int)s.size() - 1)
    // {
    //     int i = 0, e = index;

    //     while (e <= s.size() - 1 && i <= part.size() - 1 && s[e] == part[i])
    //     {
    //         i++;
    //         e++;    
    //     }

    //     if (i == m)
    //     {
    //         s.erase(index, m);
    //         index = 0;
    //         continue;
    //     }
    //     index++;
    // }

    // return s;

    //Can use inbuilt functions

    while(s.size() > 0 && s.size() > s.find(part))
    {
        s.erase(s.find(part), part.size());
    }
    return s;
}

int main()
{
    cout << removeOccurrences("eemckxmckx", "emckx") << endl;
}