#include <iostream>
#include <vector> 
#include <iterator>      //std::distance 
#include <algorithm>     //std::find 

using namespace std; 

/* -------- Subject --------  
You are given an array of distinct integers nums, sorted in ascending order, and an integer target.
Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1. */ 

/* -------- Explanation --------
Clear by definition of std::find and std::distance. */

int search(vector<int>& nums, int target) 
{
    auto it = std::find(nums.begin(), nums.end(), target);
    if(it != nums.end()) return std::distance(nums.begin(), it); 
    else return -1;
}

int main()
{
    vector<int> nums{-1,0,2,4,6,8};
    int target = 3; 
    int target2 = 4; 
    cout << search(nums,target) << endl;  //Output : -1.
    cout << search(nums,target2) << endl; //Output : 3. 
    return 0; 
}