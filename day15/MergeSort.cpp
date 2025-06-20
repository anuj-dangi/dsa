#include <iostream>
#include <vector>
using namespace std;

//time complexity - O(n*logn)
void merge(vector<int> &arr, int l1,int r1, int l2, int r2)
{
    vector<int> arrC;
    int index = l1;
    while(l1<=r1 && l2<=r2)
    {
        if(arr[l1] <= arr[l2])
        {
            arrC.push_back(arr[l1]);
            l1++;
        }
        else
        {
            arrC.push_back(arr[l2]);
            l2++;
        }
    }

    while(l1<=r1)
        arrC.push_back(arr[l1++]);
    while(l2<=r2)
        arrC.push_back(arr[l2++]);

    for(int i=0;i<arrC.size();i++)
    {
        arr[index++] = arrC[i];
    }
    
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if(l<r)
    {
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, mid+1, r);
    }
}

int main()
{
    vector<int> arr = {32, 12, 5, 32, 11, 7, 9};

    mergeSort(arr, 0, arr.size()-1);

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}