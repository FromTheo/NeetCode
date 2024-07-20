#include <string>
#include <algorithm> 
#include <iostream> 
#include <map> 
#include <numeric> 

using namespace std; 

/* -------- Subject --------  
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
Each product is guaranteed to fit in a 32-bit integer. */ 

/* -------- Explanation --------
We delete nums[i] with erase() and we compute the product by using std::accumulate(available in <numeric> libary). */

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size()); 
    for(int i = 0; i < nums.size(); i++)
    {
        vector<int> copy = nums; 
        auto it = find(copy.begin(), copy.end(), nums[i]); 
        copy.erase(it); 
        int product = std::accumulate(copy.begin(), copy.end(), 1, [](int acc, const int & d)
        {
            return acc*d; 
        });
        res[i] = product; 
    }
    return res;
}

int main()
{
    vector<int> nums1{-1,0,1,2,3}, nums2{1,2,4,6}; 
    for(const int& i : productExceptSelf(nums1))
    {
        cout << i << " "; 
    }
    //Output : 0 -6 0 0 0 
    cout << endl; 
    for(const int& i : productExceptSelf(nums2))
    {
        cout << i << " ";
    }
    cout << endl; 
    //Output : 48 24 12 8 
    return 0; 
}
