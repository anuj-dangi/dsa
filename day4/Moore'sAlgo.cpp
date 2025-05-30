#include<iostream>

using namespace std;
//Moore's algo intution is that it focuses on power of element in quse like
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

//Where the majority element has power more than compared to remaining element combined power

int majorityElement(int nums[], int size) 
{
    int freq = 0;
    int ans = 0;

    for(int i=0;i<size;i++)
    {
        if(freq == 0)
            ans = nums[i];

        if(nums[i] == ans)
            freq++;
        else
            freq--;
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,4, 3, 3, 3,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << majorityElement(arr, size);
    return 0;
}