#include <iostream>
#include <vector> 
#include <numeric>

using namespace std; 

/* -------- Subject --------  
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store. */ 

/* -------- Explanation --------
The idea of this algorithm is to iteratively calculate the areas and update maxArea, moving towards the middle of the height vector.
At each iteration, we determine which height is the largest, and accordingly, we move forward (or backward). */

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return maxArea;
}

int main()
{
    std::vector<int> v1{1,8,6,2,5,4,8,3,7};
    std::vector<int> v2{1,1};
    std::vector<int> v3 {1,7,2,5,4,7,3,6}; 
    std::vector<int> v4{2,2,2};
    cout << maxArea(v1) << endl; 
    //Output : 49.
    cout << maxArea(v2) << endl; 
    //Output : 1. 
    cout << maxArea(v3) << endl; 
    //Output : 36. 
    cout << maxArea(v4) << endl; 
    //Output : 4.
    return 0: 
}