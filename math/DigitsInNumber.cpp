#include <iostream>
#include <math.h>
using namespace std;

//Its time complexity is log10(n)   -> as each time its divied by 10
void printDigits(int num)
{
    while(num > 0)
    {
        cout << num%10 << endl;
        num /= 10;
    }
}

void printNoOfDigits(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num /= 10;
    }
    cout << count << endl;
}

int main()
{
    int n=1234;

    printDigits(n);
    printNoOfDigits(n);

    //short trick to get no of digits
    cout << (int)log10(n)+1 << endl;
}