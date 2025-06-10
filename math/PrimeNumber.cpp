// We can find if a number is prime or not using loop:
//     for i = 0 to i*i<n ;
// this gives time comoplexity of root(n) as we use the prime number property
// ex- factor of(12):    (1*12), (2*6), (4*3)
//     as we can see that for every single factor is present and always a single factor will be present in root(n).
#include <iostream>

using namespace std;

bool isPrime(int num)
{
    for(int i=2;i*i<num;i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "is prime : " << isPrime(47) << endl;
    return 0;
}