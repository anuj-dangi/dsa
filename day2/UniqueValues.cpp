#include<iostream>
using namespace std;

void uniqueValues(int arr[], int size)
{/*
    int newArr[10] = {0};

    for(int i=0;i<size;i++)
    {
        newArr[arr[i]]++;
    }

    for(int i=0;i<10;i++)
    {
        if(newArr[i] == 1)
        {
            cout << i << " ";
        }
    }*/

    int output[size] = {0};

    for(int i=0;i<size;i++)
    {
        bool unique = false;
        for(int j=0;j<size;j++)
        {
            if(arr[i] == arr[j] && i != j)
            {
                unique = true;
            }
        }
        if(unique == false)
            cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4,2,7,8,1,2,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    uniqueValues(arr, size);

    return 0;
}