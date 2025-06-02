#include <iostream>
#include <vector>
using namespace std;

void change(int* ptr)  //Pass by reference using pointers
{
    *ptr = 20;
}

void change(int &b)  //Pass by reference using alias(references)
{
    b = 30;
}

int main()
{
    int a = 10;

    change(&a);
    cout << a << "\n";  //20

    change(a);
    cout << a << "\n";  //30

    return 0;
}