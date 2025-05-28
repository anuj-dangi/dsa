#include<iostream>
using namespace std;

void sumPro(int arr[], int size)
{
    int sum = 0;
    int pro = 1;
    for(int i=0;i<size;i++)
    {
        sum += arr[i];
        pro *= arr[i];
    }

    cout << "Sum : " << sum << "\nProduct : " << pro << "\n";
    return;
}

int main()
{
    int arr[] = {4,2,7,8,1,2,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    sumPro(arr, size);
    return 0;
}