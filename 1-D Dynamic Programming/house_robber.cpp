#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an integer array nums where nums[i] represents the amount of money the ith house has.
The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.
You are planning to rob money from the houses, but you cannot rob two adjacent houses because
the security system will automatically alert the police if two adjacent houses were both broken into.
Return the maximum amount of money you can rob without alerting the police. */ 

/* -------- Explanation --------
Let's start from the beginning of the row of houses.
We initialize two variables x and y to 0, which correspond to the fortunes due to the binary choice that we must make (to steal or not?).
We iterate over all the elements of nums (in order).
At each iteration, we initialize temp as the maximum between n + x and y, which represents the highest gain if we choose to steal the nth house, 
depending on the previous thefts. Then we replace x with y and store temp in y, and repeat the process, which will indeed give the maximum gain. */

int rob(vector<int>& nums) {
     int x = 0, y = 0;

    for (const int& n : nums) 
    {
        int temp = max(n + x, y);
        x = y;
        y = temp;
    }
    return y;
}

int main()
{
    vector<int> nums1{2,9,8,3,6}, nums2{1,1,3,3};
    cout << rob(nums1) << endl; //Output : 16.
    cout << rob(nums2) << endl; //Output : 4.
    return 0; 
}