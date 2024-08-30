#include <iostream>
#include <map> 
#include <vector> 

using namespace std; 

/* -------- Subject --------  
You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the range [1, n] inclusive.
Every integer appears exactly once, except for one integer which appears two or more times. 
Return the integer that appears more than once. */

// Method 1 : using std::map 
int findDuplicate_1(vector<int>& nums) 
{
    map<int,int> M; 
    for(const int& i : nums)
    {
        M[i]++; 
        if(M[i] > 1) return i;  
    }
    return -1; 
}

// Method 2 : Floyd's algorithm
int findDuplicate(std::vector<int>& nums) 
{
    int slow = nums[0];
    int fast = nums[0];

    // Find the intersection point of the two pointers. 
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Find the entrance of the cycle. 
    slow = nums[0];
    while (slow != fast) 
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vector<int> nums{1,2,3,4,4}; 
    cout << findDuplicate(nums) << endl; //Output : 4.
}