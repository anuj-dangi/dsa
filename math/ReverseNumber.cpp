#include <iostream>
#include <math.h>
using namespace std;

int reverseNumber(int num)
{
    int rNum = 0;
    while(num != 0)
    {
        rNum = (rNum*10) + (num%10);
        cout << rNum << endl;
        num /= 10;
    }   

    return rNum;
}

int main()
{
    int n=-1234;

    cout << reverseNumber(n) << endl;
}