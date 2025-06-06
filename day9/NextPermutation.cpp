#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity -> O(m+n)
//Space Complexity -> O(1)
void nextPermutation(vector<int>& nums) 
{
    int index = -1;

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] > nums[i-1])
        {
            index = i-1;
        }
    }

    if(index != -1)
    {
        int minInd = index;

        for(int i=index+1;i<nums.size();i++)
            if(nums[i] > nums[minInd])
                minInd = i;
        
        swap(nums[index], nums[minInd]);
    }

    

    int l=index+1, r=nums.size()-1;

    while(l<r)
    {
        swap(nums[l++], nums[r--]);
    }
}

int main()
{
    vector<int> nums = {3, 1, 5};

    nextPermutation(nums);

    for(int ele : nums)
    {
        cout << ele << " ";
    }
    return 0;
}