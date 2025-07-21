#include <iostream>
#include <vector>
using namespace std;

//leetcode - 134
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // brute force
    // time complexity - O(n*n)
    //  int totalGas = 0;
    //  int totalCost = 0;

    // for (int i = 0; i < gas.size(); i++)
    // {
    //     totalGas += gas[i];
    //     totalCost += cost[i];
    // }
    // if (totalGas < totalCost)
    //     return -1;

    // int index = 0, currGas = 0;

    // for (int i = 0; i < gas.size(); i++)
    // {
    //     index = i;

    //     for (int j = i; j < gas.size(); j++)
    //     {
    //         currGas = currGas + gas[j] - cost[j];

    //         if (currGas < 0)
    //         {
    //             currGas = 0;
    //             break;
    //         }

    //         if (j == gas.size() - 1)
    //             return index;
    //     }
    // }
    // return -1;

    //time complexity - O(n)
    int totalGas = 0;
    int totalCost = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
    }
    if (totalGas < totalCost)
        return -1;

    totalGas = 0;
    totalCost = 0;

    int index = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];

        if (totalGas < totalCost)
        {
            totalGas = totalCost = 0;
            index = i + 1;
        }
    }

    return index;
}

int main()
{
    return 0;
}