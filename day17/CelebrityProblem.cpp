#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//time complexity - O(n)
//space complexity - O(n)
int celebrity(vector<vector<int>> vec)
{
    int n = vec.size();
    if(n == 0)  return -1;
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        s.push(i);
    }

    while(s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if(vec[i][j] == 0)
        {
            s.push(i);
        }
        else if(vec[i][j] == 1)
            s.push(j);
    }

    int cel = s.top();

    for(int i=0;i<n;i++)
    {
        if(i!=cel && (vec[i][cel] == 0 || vec[cel][i] == 1))
        {
            return -1;
        }
    }

    return cel;
}

int main()
{
    vector<vector<int>> vec = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    cout << celebrity(vec) << endl;
    return 0;
}