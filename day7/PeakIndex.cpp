#include <iostream>
using namespace std;

//Intution -> we will try to find the sorted side and then perform binary seach on that side
int peakIndexInMountainArray(int arr[], int size)
{
    int l = 0, r = size-1;
    int mid;

        while(l<=r)
        {
            mid = l + (r-l)/2;
           
           if(mid+1 < size-1 && arr[mid] < arr[mid+1])
           {
                l = mid+1;
           }
           else if(mid-1 > 0 && arr[mid] < arr[mid-1])
           {
                r = mid-1;
           }
           else
                return mid;
        }
        return mid;
}

int main()
{
    int arr[] = {24,69,100,99,79,78,67,36,26,19};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Index : " << peakIndexInMountainArray(arr, size) << "\n";

    return 0;
}