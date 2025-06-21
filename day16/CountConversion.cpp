#include <iostream>
#include <vector>
using namespace std;

//Time complexity - O(n*logn)
int merge(vector<int>& arr, int l1, int r1, int l2, int r2)
{
    vector<int> temp;
    int index = l1, count=0;

    while(l1<=r1 && l2<=r2)
    {
        if(arr[l1] <= arr[l2])
        {
            temp.push_back(arr[l1++]);
        }
        else
        {
            count = r1-l1+1;
            temp.push_back(arr[l2++]);
        }
    }

    while(l1<=r1)
    {
        temp.push_back(arr[l1++]);
    }
    while(l2<=r2)
        temp.push_back(arr[l2++]);
    
    for(int i=0;i<temp.size();i++)
    {
        arr[index++] = temp[i];
    }
    return count;
}

int countConversion(vector<int>& arr, int l, int r)
{
    // int count = 0;
    //brute force 
    //time complexity - O(n*n)
    // for(int i=0;i<arr.size();i++)
    // {
    //     for(int j=i+1; j<arr.size();j++)
    //     {
    //         if(arr[i] > arr[j])
    //         {
    //             count++;
    //         }
    //     }
    // }
    // return count;
    //aproach based on merge sort

    if(l < r)
    {
        int mid = l + (r-l)/2;

        int leftrec = countConversion(arr, l, mid);
        int rightrec = countConversion(arr, mid+1, r);
        int center = merge(arr, l, mid, mid+1, r);

        return leftrec+rightrec+center;
    }
    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    cout << countConversion(arr, 0, arr.size()-1) << endl;
    return 0;
}