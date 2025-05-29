#include<iostream>
#include<vector>

using namespace std;

    bool containsDuplicate(vector<int>& nums) {
        //Can you use better sorting algorithms which time complex is less than O(n^2)
        int j;

        for(int i=0;i<nums.size();i++)
        {
            j = i;
            while( j > 0 && nums[j] < nums[j-1])
            {
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                    j--;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i <= nums.size()-2 && nums[i] == nums[i+1])
            {
                return true;
            }
        }
        

        return false;

    }

    int main()
    {
        vector<int> vec = {0};

        cout << containsDuplicate(vec);
    }