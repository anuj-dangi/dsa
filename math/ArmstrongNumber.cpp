#include <iostream>
#include <math.h>
using namespace std;

bool armstrongNumber(int num)
{
    int noDigits = (int)(log10(num)+1);

    int sum = 0, copyNum = num;

    while(copyNum > 0)
    {
        sum += (int)pow(copyNum%10, noDigits);      //gives wrong ans for 135 as pow function is imprecise result due to floating point aritmetic
        copyNum /= 10;
    }

    if(sum == num)
        return true;
    return false;
}


int main()
{
    int n=371;

    cout << armstrongNumber(n) << endl;

    return 0;
}