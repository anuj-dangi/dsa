#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> vec, int target)
{
    vector<vector<int>> ans;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if (i > 0 && vec[i] == vec[i - 1])
            continue;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (j > i + 1 && vec[j] == vec[j - 1])
                continue;
            int k = j + 1, l = vec.size() - 1;

            while (k < l)
            {
                long long sum = (long long)vec[i] + (long long)vec[j] + (long long)vec[k] + (long long)vec[l];
                if (sum == target)
                {
                    vector<int> v = {vec[i], vec[j], vec[k], vec[l]};

                    ans.push_back(v);
                    k++;
                    l--;
                    while (k < l && vec[k] == vec[k - 1])
                        k++;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                    l--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (vector<int> v : ans)
    {
        for (int ele : v)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}