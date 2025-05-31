#include<iostream>

using namespace std;

int main()
{
    //Find x^n but with O(logn)

    int x = 5;
    int n = 10;
    double ans = 1;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            ans = ans*x;
        }
        x *= x;
        n /= 2;
    }

    cout << ans << " " << x;
    return 0;
}