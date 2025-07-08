#include <iostream>
#include <vector>
using namespace std;

// leetcode - 42
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(height[i], lmax[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(height[i], rmax[i + 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

int main()
{
    vector<int> vec = {4, 2, 0, 3, 2, 5};
    cout << trap(vec) << endl;
    return 0;
}