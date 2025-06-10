#include<iostream>
#include <algorithm>
using namespace std;

//Intitution -> instead of finding gcd of gcd(a, b), find gcd of (a-b,b) if a > b and (a, b-a) if b>a and repeat this process.
int gCDEuclid(int a, int b)
{
    // if(a > b)
    //     return gCDEuclid(a-b, b);
    // else if(b > a)
    //     return gCDEuclid(a, b-a);
    // else 
    //     return a;

    //we can still more optimize it using concept of repeated subtraction => divison

    // if(a == 0)
    //     return b;
    // else if(b == 0)
    //     return a;
    // if(a > b)
    //     return gCDEuclid(a%b, b);
    // else if(b > a)
    //     return gCDEuclid(a, b%a);

    //More better recursion approach -> we will assume that a is big and b is always small

    if(b==0)    return a;

    return gCDEuclid(b, a%b);
}


int main()
{

    cout << gCDEuclid(6, 12) << endl;

    return 0;
}