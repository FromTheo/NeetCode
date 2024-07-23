#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an array non-negative integers heights which represent an elevation map. 
Each value heights[i] represents the height of a bar, which has a width of 1.
Return the maximum area of water that can be trapped between the bars. */

/* -------- Explanation --------
We use the same principle as the previous code in this same folder.
We update l (or r) and then add to rep the volume of trapped water (it's just the difference because the width is assumed to be 1). */

int trap(vector<int>& height) {
    if(height.empty()) return 0; 
    int rep = 0; 
    int left = 0; 
    int right = height.size() - 1;
    int l = height.front();
    int r = height.back(); 
    while(left < right)
    {
        if(l < r)
        {
            left++; 
            l = std::max(l, height[left]); 
            rep += l - height[left]; 
        }
        else
        {
            right--; 
            r = std::max(r, height[right]); 
            rep += r - height[right]; 
        }
    }
    return rep; 
}

int main()
{
    vector<int> height{0,2,0,3,1,0,1,3,2,1}; 
    cout << trap(height) << endl; //Output : 9. 
    return 0; 
}