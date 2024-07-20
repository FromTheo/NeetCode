#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std; 

/* -------- Subject --------  
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false. */ 

/* -------- Explanation --------
The idea of my algorithm is to copy nums into a vector copy (to avoid modifying it), and then to empty the vector by
searching with std::find (available in the <algorithm> library). 
We return true if, after an element is removed, another equal element is found. If no duplicates are found, we return false.

Another method is possible by using the find() method of std::set (or std::unordered_set for better efficiency). */

bool hasDuplicate(vector<int>& nums) {
    vector<int> copy = nums; 
    while(!copy.empty())
    {
        int value = copy.front(); 
        auto it = std::find(copy.begin(), copy.end(), value); 
        copy.erase(it);
        it = std::find(copy.begin(), copy.end(), value); 
        if(it != copy.end()) return true; 
    }
    return false; 
}

int main()
{
    vector<int> nums1{1,2,3,4}; //uses c++17 
    vector<int> nums2{1,2,3,3};
    cout << hasDuplicate(nums1) << endl; //Output : 0.
    cout << hasDuplicate(nums2) << endl; //Output : 1.
    return 0; 
}
