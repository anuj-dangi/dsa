#include<iostream>
using namespace std;

int diagonalSum(int mat[][3], int n)
{
    int sum = 0;

    //Time complexity -> O(n*n)
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if( i == j)     //for primary diagonal
    //         {
    //             sum += mat[i][j];
    //         }
    //         else if( j == n-i-1)        //for seconday diagonal
    //         {
    //             sum += mat[i][j];
    //         }
    //     }
    // }

    //better approach as we know that j depend on i
    //Time complexity -> O(n)
    for(int i=0;i<n;i++)
    {
        sum += mat[i][i];
        if(i != n-i-1)
            sum += mat[i][n-i-1];
    }

    return sum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Diagonal Sum : " << diagonalSum(matrix, 3) << endl;
    return 0;
}