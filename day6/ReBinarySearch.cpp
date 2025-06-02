#include<iostream>
using namespace std;

//Recursive Binary search -> Time Complexicity O(logn)
//Condition for Recursive binary search -> array or vector should be sorted

int reBinarySearch(int arr[], int l, int r, int target)   //Recursive Binary search for ascending sorted array
{
    if(l<=r)
    {
        int mid = l + (r-l)/2;

        if(arr[mid] > target)
        {
            return reBinarySearch(arr, l, mid-1, target);
        }
        else if(arr[mid] < target)
        {
            return reBinarySearch(arr, mid+1, r, target);
        }
        else//arr[mid] == target
        {
            return mid;
        }
    }
    
   return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 9, 10, 33, 56, 89, 90, 101};
    int target = 101;

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Index : " << reBinarySearch(arr, 0, size-1, target) << "\n";
}