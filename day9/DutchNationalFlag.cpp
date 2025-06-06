#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Using three pointer's
void sortArray(vector<int> &arr)
{
    //Complexity of O(n)
    //
    // int zero = 0, one = 0, two = 0;

    // for(int i=0;i<arr.size();i++)
    // {
    //     if(arr[i] == 0) zero++;
    //     else if(arr[i] == 1)    one++;
    //     else    two++;
    // }

    // int index = 0;

    // for(int i=0;i<zero;i++) arr[index++] = 0;
    // for(int i=0;i<one;i++) arr[index++] = 1;
    // for(int i=0;i<two;i++) arr[index++] = 2;

    //MOre optimal  
    //Space Complexity(O(1))
    int l=0, mid=0, r=arr.size()-1;

    while(mid <= r)
    {
        if(arr[mid] == 0) 
        {
            swap(arr[mid], arr[l++]);
            mid++;
        }
        else if(arr[mid] == 1)   mid++;
        else
        {
            swap(arr[mid], arr[r--]);
        }
    }
}

int main()
{
    vector<int> vec = {2, 0, 1};

    sortArray(vec);
    for(int ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}