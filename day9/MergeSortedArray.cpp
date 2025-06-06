#include <iostream>
#include <vector>

using namespace std;

//Time Complexity -> O(m+n)
//Space Complexity -> O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int index = m+n-1;
        int f=m-1, s=n-1;

        while(f>=0 && s>=0)
        {
            if(nums1[f] >= nums2[s])
            {
                nums1[index] = nums1[f];
                f--;
            }
            else
            {
                nums1[index] = nums2[s];
                s--;
            }
            index--;
        }

        
        while(s >= 0)
        {
            nums1[index] = nums2[s];
            s--;
            index--;
        }
    }

int main()
{
    vector<int> nums1 = {1,3,5,0,0,0};
    vector<int> nums2 = {2,4,6};

    merge(nums1, nums1.size()-nums2.size(), nums2, nums2.size());
    for(int ele : nums1)
    {
        cout << ele << " ";
    }
    return 0;
}