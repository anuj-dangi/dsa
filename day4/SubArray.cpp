#include <iostream>
#include <vector>
using namespace std;

//Have to print all the possible subArrays of the given array
void subArray(int arr[], int size)
{
    /* This approach first print single digit subarrays and then gradually print the remaining one
    for(int i=0;i<size;i++)
    {
        int start;
        int startNew = 0;
        for(int j=0;j<size-i;j++)
        {
            start = startNew;
            for(int k=0;k<i+1;k++)
            {
                cout << arr[start++];
            }
            cout << " ";
            startNew++;
        }

        cout << "\n";
    }
    */

    //Another way of brute force
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int arr[] = {3, 2, 5, 4, 1, 7, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    subArray(arr, size);
    return 0;
}