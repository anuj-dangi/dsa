#include <iostream>
#include <vector>
using namespace std;

//leetcode - 2264
string largestGoodInteger(string nums)
{
    if (nums.size() <= 2)
    {
        return "";
    }

    string output = "";

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int start = i;
        int end = i+2;

        if(nums[start] == nums[start+1] && nums[start+1] == nums[end])
        {
            string sub = nums.substr(i, 3);

            if(output < sub)
            {
                output = sub;
            }
        }
    }

    return output;
}

int main()
{
    cout << largestGoodInteger("6777333") << endl;
    return 0;
}