#include<iostream>
using namespace std;

void swapMaxMin(int arr[], int size)
{
    int maxIndex = 0;
    int minIndex = 0;

    for(int i=0;i<size;i++)
    {
        if(arr[maxIndex] < arr[i])
        {
            maxIndex = i;
        }

        if(arr[minIndex] > arr[i])
        {
            minIndex = i;
        }
    }

    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;

    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4,2,7,8,1,2,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    swapMaxMin(arr, size);
    return 0;
}