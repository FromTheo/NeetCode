#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
Given an array of integers nums, find the subarray with the largest sum and return the sum.
A subarray is a contiguous non-empty sequence of elements within an array. */ 

int maxSubArray(const vector<int>& nums) 
{
    int current = nums.front(); 
    int resultat = nums.front(); 

    for(int i = 1; i < nums.size(); ++i)
    {
        current = max(current + nums[i], nums[i]); 
        resultat = max(resultat, current); 
    }
    return resultat; 
}

int main()
{
    cout << maxSubArray(vector<int>{2,-3,4,-2,2,1,-1,4}); //Output : 8 
    return 0; 
}