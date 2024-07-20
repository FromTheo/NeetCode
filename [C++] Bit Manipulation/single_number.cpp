#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>    //std::unordered_map 

using namespace std; 

/* -------- Subject --------  
You are given a non-empty array of integers nums. Every integer appears twice except for one.
Return the integer that appears only once. */

/* -------- Explanation --------
I will create an unordered_map<int,int> (not map<int,int> for optimization reasons), 
in which I will store each element of nums with its occurrence count as the key. 
Then, I will iterate through the elements of M using an iterator until finding the one with a key of 1. 
We know such an element exists and is unique by definition. Therefore, we can safely return 0 at the end of the for loop, 
although it will never be returned by singleNumber().  */

int singleNumber(vector<int>& nums) 
{
    unordered_map<int,int> M; 
        
    for(const int &i : nums)
    {
        M[i]++; 
    }
    for(auto it = M.begin(); it != M.end(); ++it) //The real type of it is : unordered_map<int, int>::iterator. 
    {
        if((*it).second == 1) return (*it).first; 
    }
    return 0; 
}

int main()
{
    vector<int> nums1{3,2,3}, nums2{7,6,6,7,8}; 
    cout << singleNumber(nums1) << endl; //Output : 2. 
    cout << singleNumber(nums2) << endl;  //Output : 8.
    return 0; 
}