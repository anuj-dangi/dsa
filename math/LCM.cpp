#include<iostream>
#include <algorithm>
using namespace std;

//Least common multiple
//lcm = (a*b)/gcd(a, b)
int gCD(int a, int b)
{
    if(b==0)    return a;

    return gCD(b, a%b);
}

int lCM(int a, int b)
{
    return (a*b)/gCD(a, b);
}

int main()
{

    cout << lCM(12, 6) << endl;

    return 0;
}