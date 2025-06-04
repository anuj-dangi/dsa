#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Intitution -> Start from starting and each time sort the element before the current elements
//Time Complexity -> O(n^2)
void insertionSort(vector<int> &arr)
{
    int j;
    //outer loop iterates n-1 times
    for(int i=1;i<arr.size();i++)
    {
        j = i;

        while(j > 0 && arr[j] < arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

int main()
{
    vector<int> vec = {5, 6, 1, 3, 7, 2};

    insertionSort(vec);
    for(int ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}