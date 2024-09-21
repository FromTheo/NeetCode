#include <vector>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given an integer array nums, find a subarray that has the largest product within the array and return it.
A subarray is a contiguous non-empty sequence of elements within an array.
You can assume the output will fit into a 32-bit integer. */ 

int maxProduct(vector<int>& nums) 
{
    int maxProd = nums.front(); 
    int minProd = nums.front(); 
    int resultat = nums.front(); 

    for(int i = 1; i < nums.size(); ++i)
    {
        int tempMax = maxProd; 
        int tempMin = minProd; 
        maxProd = max({nums[i], nums[i] * tempMax, nums[i] * tempMin});    
        minProd = min({nums[i], nums[i] * tempMax, nums[i] * tempMin});
        resultat = max(maxProd, resultat);  
    }

    return resultat; 
}

int main()
{
    vector<int> nums{1,2,-3,4}; 
    cout << maxProduct(nums) << endl; //Output : 4 

    return 0; 
}