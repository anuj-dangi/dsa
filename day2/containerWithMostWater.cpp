/*
Container With Most Water Medium
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#include<iostream>
using namespace std;

//Will use two pointer technique
int maxArea(int height[])
{
    int area = 0;
    int p1 = 8;     //height.length-1
    int p2 = (sizeof(height)/sizeof(height[0]))-1;

    while(p1 < p2)
    {
        int newArea = (p2-p1)*min(height[p1], height[p2]);

        area = (newArea > area) ? newArea : area;

        if(height[p1] > height[p2])
            p2--;
        else
            p1++;
    }
    return area;
}

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};

    cout << "Max Area : " << maxArea(height) << "\n";
}