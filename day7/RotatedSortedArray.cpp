#include <iostream>
using namespace std;

//Intution -> we will try to find the sorted side and then perform binary seach on that side
int search(int arr[], int size, int target)
{
    int l = 0, r = size-1;
    int mid;

    while(l <= r)
    {
        mid = l + (r-l)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[l] <= arr[mid])
        {
            if(arr[l] <= target && arr[mid] >= target)
                r = mid-1;
            else
                l = mid+1;
        }
        else
        {
            if(arr[mid] <= target && arr[r] >= target)
                l = mid+1;
            else
                r = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {89, 90, 101, 1, 3, 5, 9, 10, 33, 56};
    int target = 10;

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Index : " << search(arr, size, target) << "\n";

    return 0;
}