#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//time complexity - O(n)
vector<int> stockSpan(vector<int> prices)
{
    stack<int> s;
    vector<int> span;

    //O(n)
    for(int i=0;i<prices.size();i++)
    {
        //constant n
        while(!s.empty() && prices[s.top()] <= prices[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            span.push_back(i+1);
        }
        else
        {
            span.push_back(i-s.top());
        }

        s.push(i);
    }
    return span;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = stockSpan(prices);

    for(int ele : span)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}