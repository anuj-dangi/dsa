#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    /*
    for(int i=0;i<nums.size();i++)
    {
        bool contain = false;
        for(int j=0;j<nums.size();j++)
        {
            if(i!=j && nums[i] == nums[j])
            {
                contain = true;
                break;
            }
        }
        if(!contain)
        {
            return nums[i];
        }
    }
    return -1;
    */
    //A better approach that uses bitwise operator-> XOR
    //Use approach that cancels the same number and the unique value remains
    int num = 0;
    for(int ele : nums)
    {
        num = num ^ ele;
    }
    return num;
}

int main()
{
    vector<int> vec = {1, 1, 2, 5, 5};

    cout << singleNumber(vec);
    return 0;
}