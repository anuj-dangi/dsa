#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//leetcode - 2438
//time complexity - O(M*N)
vector<int> productQueries(int n, vector<vector<int>> &queries)
{

    vector<int> power;
    vector<int> bin;

    while (n > 0)
    {
        bin.push_back(n % 2);

        n = n / 2;
    }

    for (int i = bin.size() - 1; i >= 0; i--)
    {
        if (bin[i] == 1)
        {
            power.push_back(pow(2, i));
        }
    }

    reverse(power.begin(), power.end());

    vector<int> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        long long a = 1;
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            a = (a * power[j]) % ((int)pow(10, 9) + 7);
        }
        ans.push_back(a);
    }

    return ans;
}

int main()
{
    vector<vector<int>> querie = {{1, 2}, {1, 1}};
    vector<int> ans = productQueries(13, querie);

    for (auto ele : ans)
    {
        cout << ele << endl;
    }
    return 0;
}