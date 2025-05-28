#include<iostream>
using namespace std;

//Two pointer approach
int main()
{
    int arr[] = {4,2,7,8,1,2,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int j=0, k=size-1;
    while(j<k)
    {
        int temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
        j++;
        k--;
    }

    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
}