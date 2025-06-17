#include<iostream>
using namespace std;

int recFibonacci(int n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return recFibonacci(n-1) + recFibonacci(n-2);
}

int main()
{
    int n = 3;
    cout << recFibonacci(n);
    return 0;
}