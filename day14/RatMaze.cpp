#include <iostream>
#include <vector>
using namespace std;

// void helper(vector<vector<int>> matrix, int row, int col, vector<string> &ans, string temp, vector<vector<char>>& dir)
// {
//     if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix.size() || matrix[row][col] == 0 || dir[row][col] == 'V')
//         return;
//     if(row == matrix.size()-1 && col == matrix.size()-1)
//     {
//         ans.push_back(temp);
//         return;
//     }

//     dir[row][col] = 'V';

//     helper(matrix, row+1, col, ans, temp+'D', dir);
//     helper(matrix, row, col+1, ans, temp+'R', dir);
//     helper(matrix, row, col-1, ans, temp+'L', dir);
//     helper(matrix, row-1, col, ans, temp+'U', dir);

//     dir[row][col] = 'N';

// }

//time complexity - O(4^(n*n))
void helper(vector<vector<int>> matrix, int row, int col, vector<string> &ans, string temp)
{
    if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix.size() || matrix[row][col] == 0 || matrix[row][col] == -1)
        return;
    if(row == matrix.size()-1 && col == matrix.size()-1)
    {
        ans.push_back(temp);
        return;
    }

    matrix[row][col] = -1;

    helper(matrix, row+1, col, ans, temp+'D');
    helper(matrix, row, col+1, ans, temp+'R');
    helper(matrix, row, col-1, ans, temp+'L');
    helper(matrix, row-1, col, ans, temp+'U');

    matrix[row][col] = 1;

}

vector<string> findPath(vector<vector<int>> matrix)
{
    vector<string> ans;
    string temp = "";
    //vector<vector<char>> dir(matrix.size(), vector<char>(matrix.size(), 'N'));

    //helper(matrix, 0, 0, ans, temp, dir);
    helper(matrix, 0, 0, ans, temp);

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1 ,0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findPath(matrix);

    for(string ele : ans)
    {
        cout << ele << endl;
    }
    return 0;
}