//If we want to find the count of prime number in a range this alogrithm will give as 
//better time complexity that using loop of normal prime number finding solution.
#include <iostream>
#include <vector>

using namespace std;
//Sieve means filtering form (chelni)
//Leetcode - 204(count primes)
//1 is nor prime or nor composite
//This algorithm uses its previous prime number and removes the multiple of that prime number as that prime number can't be a prime because that number is mulitple of its trailing values.
int sieveOfErastosenes(int num)
{
    vector<bool> isPrime(num, true);
    int ans = 0;

    for(int i=2;i<num;i++)
    {
        if(isPrime[i])
        {
            ans++;
            for(int j=i*2;j<num;j=j+i)
            {
                isPrime[j] = false;
            }
        }
    }
    return ans;
}

int main()
{
    int n = 47;
    cout << "Count of Prime number under  " << n << " is : " << sieveOfErastosenes(n) << endl;
    return 0;
}