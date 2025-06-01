#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) 
{
        int minDay = prices[0], maxProfit = 0;

        for(int i=1;i<prices.size();i++)
        {
            if(minDay < prices[i])
            {
                maxProfit = max(maxProfit, prices[i]-minDay);
            }

            minDay = min(minDay, prices[i]);
        }
        return maxProfit;
}

int main()
{
    vector<int> vec = {7, 1, 4, 6, 5};

    cout << maxProfit(vec);
    return 0;
}