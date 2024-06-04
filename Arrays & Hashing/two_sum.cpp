#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; 

/* -------- Subject --------  
Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
Return the answer with the smaller index first.*/

/* -------- Explanation --------
I iterate through all the elements of the vector nums with two for loops with an if statement inside.
We could have simply used sort(res.begin(), res.end()) because by default this template sorts the elements
in ascending order (for std::vector<int>). */

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> res; 
    int n = nums.size(); 
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j< n; ++j)
        {
            if(i!=j and nums[i]+nums[j] == target) res = vector<int>{i,j};  
        }
    }
    sort(res.begin(), res.end(), [](const int& i, const int&j)
    {
        return i < j;
    }); 
    return res; 
}

int main()
{
    vector<int> nums1{3,4,5,6}, nums2{4,5,6}, nums3{5,5}; //use c++17
    int target1(7), target2(10);
    for(const int& i : twoSum(nums1,target1))
    {
        cout << i << " ";
    } 
    cout << endl; 
    for(const int& i : twoSum(nums2,target2))
    {
        cout << i << " ";
    } 
    cout << endl;
    for(const int& i : twoSum(nums3,target2))
    {
        cout << i << " ";
    } 
    cout << endl;

    return 0; 
}
