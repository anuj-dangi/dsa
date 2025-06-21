#include <iostream>
#include <vector>
using namespace std;

//Time compleixty - O(8^(n*n))
bool helper(vector<vector<int>> &grid, int row, int col, int count)
{
    if (row >= grid.size() || col >= grid.size() || row < 0 || col < 0 || count != grid[row][col])
        return false;
    if (count == (grid.size() * grid.size())-1)
        return true;


    return (helper(grid, row + 1, col + 2, count + 1) || helper(grid, row + 2, col + 1, count + 1) || helper(grid, row - 1, col + 2, count + 1) || helper(grid, row - 2, col + 1, count + 1) || helper(grid, row - 1, col - 2, count + 1) || helper(grid, row - 2, col - 1, count + 1) || helper(grid, row + 1, col - 2, count + 1) || helper(grid, row + 2, col - 1, count + 1));
}

bool checkValidGrid(vector<vector<int>> &grid)
{
    return helper(grid, 0, 0, 0);
}

int main()
{
    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};

    cout << checkValidGrid(grid) << endl;
    return 0;
}