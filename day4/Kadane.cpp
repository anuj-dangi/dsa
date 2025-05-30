#include <iostream>
using namespace std;

int kadanesAlgo(int arr[], int size)
{
    //Give most optimized answer for subarray sum
    //Intitution -> -ve + -ve = -ve (this can't be our greatest sum) so when sum becomes -ve we reset it to 0.

    int maxSum = INT32_MIN;
    int currSum = 0;

    for(int i=0; i<size; i++)
    {
        currSum += arr[i];

        maxSum = max(currSum, maxSum);

        if(currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << kadanesAlgo(arr, size);
    return 0;
}