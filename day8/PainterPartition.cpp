#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> nums, int n, int m, int mid)
{
    int painter = 1, time = 0;

    for(int i=0;i<n;i++)
    {
        if(time + nums[i] <= mid)
        {
            time += nums[i];
        }
        else
        {
            painter++;
            time = nums[i];
        }
    }

    return painter <= m?true:false;
}

int painterPartition(vector<int> nums, int m)
{
    int n = nums.size();

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
    vector<int> vec = {10, 30, 20 ,20};
    int noOfPainter = 2;

    cout << "Max time : " << painterPartition(vec, noOfPainter);
    return 0;
}