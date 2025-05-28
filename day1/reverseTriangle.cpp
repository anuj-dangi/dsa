#include<iostream>
using namespace std;

int main()
{
    int n = 5;
    char a = 'A';
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            cout << (char)(a+j);
        }
        cout << "\n";
    }
}