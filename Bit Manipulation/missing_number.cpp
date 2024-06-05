#include <iostream>
#include <vector>
#include <algorithm>     //std::sort 

using namespace std; 

/* -------- Subject --------  
Given an array nums containing n integers in the range [0, n] without any duplicates, 
return the single number in the range that is missing from nums. */

/* -------- Explanation --------
I will present two methods. The second one is the most effective.
- For the first method, I will sort the vector in ascending order (which std::sort does by default, so there's no need to add a lambda function). 
I will then compare the elements of nums with natural numbers, and return as soon as the equality test fails.
- For the second method, we will initialize an integer res equal to the size of nums. 
We will use a for loop to go through all the elements of nums (not necessarily in ascending order this time) and add to res the value i - nums[i]. 
At the end, this sum will telescope, leaving us with the number that does not appear. */

int missingNumber(vector<int>& nums) 
{
    //Method 1 : 
    /*std::sort(nums.begin(), nums.end()); 
    int compteur = 0; 
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != compteur) break;
        else compteur++; 
    }
    return compteur; */ 


    //Method 2 : 
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++) 
    {
        res += i - nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums1{1,2,3}, nums2{0,2}; 
    cout << missingNumber(nums1) << endl; //Output : 0.
    cout << missingNumber(nums2) << endl; //Output : 1.


    return 0; 
}