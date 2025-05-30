#include <iostream>
#include <vector>

using namespace std;

int maximumSum(int arr[], int size)
{
    /*Time complexity -> O(n^3)
    int maxi = 0;

    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int num = 0;
            for(int k=i;k<=j;k++)
            {
                num += arr[k];
            }
            maxi = max(maxi, num);
        }
    }
    return maxi;
    */

    //Time complexity -> O(n^2)

    int sum = INT32_MIN;
    
    for(int st=0; st<size; st++)
    {
        int currSum = 0;
        for(int end=st; end<size; end++)
        {
            currSum += arr[end];

            sum = max(currSum, sum);
        }
    }
    return sum;
}

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << maximumSum(arr, size);
    return 0;
}