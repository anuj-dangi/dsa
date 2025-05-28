#include<iostream>
using namespace std;

void intersection(int arr1[], int size1, int arr2[], int size2)
{

    for(int i=0;i<size1;i++)
    {
        bool contain = false;
        for(int j=0;j<size2;j++)
        {
            if(arr1[i] == arr2[j])
            {
                contain = true;
            }
        }
        if(contain)
            cout << arr1[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = { 1, 2};

    intersection(arr1, 3, arr2, 2);
    return 0;
}