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

        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        if(index != -1)
        {
            for(int i=nums.size()-1;i>=index+1;i--)
            {
                if(nums[i] > nums[index])
                {
                    swap(nums[index], nums[i]);
                    break;
                }
            }
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

    //Give lexicographically next 
    nextPermutation(nums);

    for(int ele : nums)
    {
        cout << ele << " ";
    }
    return 0;
}