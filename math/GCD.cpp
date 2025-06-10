#include<iostream>
#include <algorithm>
using namespace std;

//Greatest common divisor
//Also known as HCF(Highest common factor)
//Time complexity -> O(min(a,b))
//Better approach ->    Euclid's algorithm
int gCD(int a, int b)
{
    int gcd = 1;
    for(int i=2;i<=min(a,b);i++)
    {
        if(a%i == 0 && b%i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int main()
{

    cout << gCD(12, 6) << endl;

    return 0;
}