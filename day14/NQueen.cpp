#include <iostream>
#include <vector>
using namespace std;

//leetcode - 51
//time complexity - O(n!)
bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
            return false;
        if (board[row][i] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            nQueen(board, row + 1, n, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueen(board, 0, n, ans);

    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);

    for(vector<string> vs : ans)
    {
        for(string ele : vs)
        {
            cout << ele << endl;
        }
        cout << endl;
    }
    return 0;
}