#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//leetcode - 84
//Largest Rectangle in Histogram
int largestRectangle(vector<int> heights)
{
    //Brute force - O(n*n)

    //optimal appoach - O(n)
    int area = 0;
    vector<pair<int, int>> sN(heights.size(), {-1, -1});
    stack<int> s;

    for(int i=0;i<heights.size();i++)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        sN[i].first = s.empty() ? -1 : s.top();

        s.push(i);
    }
    while(!s.empty())
    {
        s.pop();
    }
    for(int i=heights.size()-1;i>=0;i--)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }

        sN[i].second = s.empty() ? heights.size() : s.top();

        s.push(i);
    }

    for(int i=0;i<heights.size();i++)
    {
        int width = sN[i].second - sN[i].first - 1;
        int currArea = heights[i]*width;


        area = max(area, currArea);
    }

    return area;
}

int main()
{
    vector<int> heights = {2, 4};
    int area = largestRectangle(heights);
    cout << area << " ";
    return 0;
}