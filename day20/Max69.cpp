#include <iostream>
#include <vector>
using namespace std;

//leetcode - 1323
int maximum69Number(int num)
{
    int cnum = num, dig = 0, i = 0;
    while (cnum > 0)
    {
        if (cnum % 10 == 6)
        {
            dig = i;
        }
        cnum /= 10;
        i++;
    }

    int ans = 0, pow = 1, a = 0;

    for (int j = 0; j < i; j++)
    {
        if (j == dig)
        {
            ans = ans + (9*pow);
            pow *= 10;
            num /= 10;
            continue;
        }

        ans = ans + (num % 10)*pow;

        pow *= 10;
        num /= 10;
    }

    return ans;
}

int main()
{
    cout << maximum69Number(9699);
    return 0;
}