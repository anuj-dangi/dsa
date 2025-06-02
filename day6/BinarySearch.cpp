#include<iostream>
using namespace std;

//Binary search -> Time Complexicity O(logn)
//Condition for binary search -> array or vector should be sorted

int binarySearch(int arr[], int size, int target)   //Binary search for ascending sorted array
{
    int l = 0;
    int r = size-1;
    int mid = 0;

    while(l<=r)
    {
        //In some cases when array is so big that its index max value reaches up to INT_MAX then in case of l and r going to end of array
        // l,r -> INT_MAX so the mid also get bigger than INT_MAX before doing divison so to tackel this
        // mid = (l+r)/2; -> overflow issue
        mid = l + (r-l)/2;      //r-l will be less than INT_MAX and dividing with 2 then adding l result in less vlaue in INT_MAX

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 9, 10, 33, 56, 89, 90, 101};
    int target = 101;

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Index : " << binarySearch(arr, size, target) << "\n";
}