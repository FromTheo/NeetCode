#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std; 

/* -------- Subject --------  
You are given an array nums of integers, which that may contain duplicates. Return all possible subsets.
The solution must not contain duplicate subsets. You may return the solution in any order. */ 

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result);

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end()); 

    backtrack(nums, 0, current, result);
        
    return result;    
}

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) 
{
    result.push_back(current); //Add the current subset to the result.
    for (int i = start; i < nums.size(); ++i) //Explore all possible subsets that start with elements after the current index. 
    {
        if (i > start && nums[i] == nums[i - 1]) continue; //Skip the duplicates  
        current.push_back(nums[i]); //Choose. 
        backtrack(nums, i + 1, current, result); //Explore. 
        current.pop_back(); //Unchoose. 
    }
}

int main()
{
    vector<int> nums{1,2,1}; 
    for(const vector<int>& v : subsetsWithDup(nums))
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    \empty
    1 
    1 1 
    1 1 2 
    1 2 
    2 */
    return 0; 
}