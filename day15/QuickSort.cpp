#include <iostream>
#include <vector>
using namespace std;

//time complexity - O(n*logn)(average)
//worst case - O(n*n)
int partition(vector<int>& arr, int l, int r)
{
    int idx = l-1, pivot = arr[r];
    for(int i=l;i<r;i++)
    {
        if(arr[i] <= pivot)
        {
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[r]);
    return idx;
}

void quickSort(vector<int>& arr, int l, int r)
{
    if(l<r)
    {
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main()
{
    vector<int> arr = {32, 12, 5, 32, 11, 7, 9};

    quickSort(arr, 0, arr.size()-1);

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}