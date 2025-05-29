#include<iostream>
#include<vector>

using namespace std;

//Ampresand(&) it gives the function parameter as pass by reference
void reverse(vector<int>& vec)
{
    int i=0,j=vec.size()-1;

    while(i<j)
    {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    vector<int> vec = {4,2,7,8,1,2,5};

    reverse(vec);

    for(int ele : vec)
    {
        cout << ele << " ";
    }

    return 0;
}