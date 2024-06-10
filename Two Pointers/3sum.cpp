#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]],
where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
The output should not contain any duplicate triplets. 
You may return the output and the triplets in any order. */

/* -------- Explanation --------
Let's start by sorting the vector nums in ascending order.
We will use the two-pointers approach.
We iterate over the indices i, and we do not consider duplicates.
We initialize j (the left pointer) = i + 1 and k (the right pointer) = nums.size() - 1.
Now, we follow the approach. As long as j < k, we consider the sum (which we want = 0).
If it is > 0, we decrement k so that it becomes larger (hence the importance of ascending order).
If it is < 0, we increment j so that it becomes smaller.
Otherwise, we add it to the resulting vector, and we ignore duplicates on j to start over. */ 

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) 
    {
        if (i > 0 && nums[i] == nums[i-1]) 
        {
            continue;
        }
    
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) 
        {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) 
            {
                k--;
            } 
            else if (total < 0) 
            {
                j++;
            } 
            else 
            {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j-1] && j < k) 
                {
                    j++;
                }
            }
        }
    }
    return res;        
}

int main()
{
    vector<int> nums{-1,0,1,2,-1,-4}, nums2{0,1,1}, nums3{0,0,0}; 
    for(const vector<int>& v : threeSum(nums))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : 
    // -1 -1 2 
    // -1 0 1 
    for(const vector<int>& v : threeSum(nums2))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : {{}}
    for(const vector<int>& v : threeSum(nums3))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : 0 0 0 
    return 0; 
}
