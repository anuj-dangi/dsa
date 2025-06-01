#include <iostream>
#include <vector>

using namespace std;

void prime(int num)
{
    for(int i=2; (i*i)<=num; i++)
    {
        cout << i;
        if(num%i == 0)
        {
            cout << "Not a prime";
            return;
        }
    }
    
    cout << "Prime number";
    return;
}

int main()
{
    prime(101);
    return 0;
}