#include <vector>
#include <iostream>

using namespace std; 

/* -------- Subject -------- 
You are given an array of integers nums and an integer k. 
There is a sliding window of size k that starts at the left edge of the array. 
The window slides one position to the right until it reaches the right edge of the array.
Return a list that contains the maximum element in the window at each step. */  

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> res; 
    for(int i = 0; i < nums.size() - k + 1; ++i)
    {
        vector<int> consec(k); 
        for(int j = 0; j < k; ++j)
        {
            consec[j] = nums[i+j]; 
        }
        res.push_back(*max_element(consec.begin(), consec.end())); 
    }
    return res;
}

int main()
{
    vector<int> nums{1,2,1,0,4,2,6}; 
    int k = 3; 
    for(const int& i : maxSlidingWindow(nums, k))
    {
        cout << i << " ";
    }
    //Output : 2 2 4 4 6
    return 0; 
}
