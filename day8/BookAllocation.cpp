#include <iostream>
#include <vector>
using namespace std;

bool isValid(int nums[], int n, int m, int mid)
{
    int students = 1, page = 0;

    for(int i=0;i<n;i++)
    {
        if(page + nums[i] <= mid)
        {
            page += nums[i];
        }
        else
        {
            students++;
            page = nums[i];
        }
    }

    return students <= m?true:false;
}

// Intution -> we will try to find the sorted side and then perform binary seach on that side
int bookAllocation(int nums[], int n, int m)
{
    if(m > n)
    {
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += nums[i];
    }

    int ans = -1;
    int l=0, r = sum;
    int mid;

    while(l<=r)
    {
        mid = l + (r-l)/2;

        if(isValid(nums, n, m, mid))
        {
            ans = mid;
            r = mid-1;;
        }
        else
            l = mid+1;
    }
    return ans;
}

int main()
{
    int arr[] = {2,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Max Pages : " << bookAllocation(arr,n,2) << "\n";

    return 0;
}