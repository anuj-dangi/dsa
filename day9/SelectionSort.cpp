#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int findMin(vector<int> arr, int st, int end)
{
    int minIndex = st;

    for(int i=st+1; i<=end;i++)
    {
        if(arr[minIndex] > arr[i])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

//Intitution -> Select a element(in my case on basis of most min in possible range) and sort in its position
//Time Complexity -> O(n^2) //n*(n-1)*(n-2).....
void selectionSort(vector<int> &arr)
{
    //outer loop iterates n-1 times
    for(int i=0;i<arr.size();i++)
    {
        //Iterates n-i-1
        int minIndex = findMin(arr, i, arr.size()-1);

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    vector<int> vec = {5, 6, 1, 3, 7, 2};

    selectionSort(vec);
    for(int ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}