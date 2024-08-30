#include <map> 
#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an array of integers nums, where nums[i] represents the maximum length of a jump towards the right from index i. 
For example, if you are at nums[i], you can jump to any index i + j where:
    - j <= nums[i]
    - i + j < nums.length

You are initially positioned at nums[0].
Return the minimum number of jumps to reach the last position in the array (index nums.length - 1). 
You may assume there is always a valid answer. */

int jump(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 1) return 0;
    
    int jumps = 0;       //Number of jumps.
    int currentEnd = 0;  //Current end of the jump range.
    int farthest = 0;    //Farthest reachable index with the current jumps.


    for (int i = 0; i < n - 1; ++i) 
    {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) 
        {
            jumps++;  
            currentEnd = farthest; 
        }

        if (currentEnd >= n - 1) 
        {
            break;
        }
    }
    return jumps;
}

int main()
{
    vector<int> nums{2,4,1,1,1,1};
    cout << "Answer = " << jump(nums) << endl; //Output : 2 
    return 0; 
}