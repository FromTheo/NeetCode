#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

/* -------- Subject --------  
You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.
Return the area of the largest rectangle that can be formed among the bars. */ 

int largestRectangleArea(vector<int>& heights) 
{
    stack<int> stack;
    stack.push(-1);
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) 
    {
        while (stack.top() != -1 && heights[i] <= heights[stack.top()]) 
        {
            int height = heights[stack.top()];
            stack.pop();
            int width = i - stack.top() - 1;
            max_area = std::max(max_area, height * width);
        }
        stack.push(i);
    }

    while (stack.top() != -1) 
    {
        int height = heights[stack.top()];
        stack.pop();
        int width = heights.size() - stack.top() - 1;
        max_area = std::max(max_area, height * width);
    }

    return max_area;        
}

int main()
{
    vector<int> heights{7,1,7,2,2,4}; 
    cout << largestRectangleArea(heights) << endl; //Output : 8 
    return 0; 
}