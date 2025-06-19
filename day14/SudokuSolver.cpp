#include <iostream>
#include <vector>
using namespace std;

//leetcode - 37
bool isSafe(vector<vector<char>> board, int row, int col, char digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == (char)digit || board[i][col] == (char)digit)
            return false;
    }

    int nrow = (row / 3) * 3, ncol = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[nrow + i][ncol + j] == (char)digit)
                return false;
        }
    }

    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return true;

    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }

    for (char j = '1'; j <= '9'; j++)
    {
        if (isSafe(board, row, col, j))
        {
            board[row][col] = j;
            if (helper(board, nextRow, nextCol))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{

    helper(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '9', '.', '.', '1', '.', '.', '3', '.'},
    {'.', '.', '6', '.', '2', '.', '7', '.', '.'},
    {'.', '.', '.', '3', '.', '4', '.', '.', '.'},
    {'2', '1', '.', '.', '.', '.', '.', '9', '8'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '2', '5', '.', '6', '4', '.', '.'},
    {'.', '8', '.', '.', '.', '.', '.', '1', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
};

    solveSudoku(board);

    for( vector<char> vc : board)
    {
        for(char ele : vc)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}