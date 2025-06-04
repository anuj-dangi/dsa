#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Intitution -> after one outer iteration the last element of get on correct position
//Time Complexity -> O(n^2)
void bubbleSort(vector<int> &arr)
{
    //outer loop iterates n-1 times
    for(int i=0;i<arr.size();i++)
    {
        bool isSwap = false;
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap)     //Array is already sorted
        {
            break;
        } 
    }
}

int main()
{
    vector<int> vec = {5, 6, 1, 3, 7, 2};

    bubbleSort(vec);
    for(int ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}