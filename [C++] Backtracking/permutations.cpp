#include <vector>
#include <iostream> 
#include <algorithm>        //std::next_permutation 

using namespace std; 

/* -------- Subject --------  
Given an array nums of unique integers, return all the possible permutations. You may return the answer in any order. */ 

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result);
vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    backtrack(nums, used, current, result);
        
    return result;  
}

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result)
{
    if(current.size() == nums.size()) //If the permutation is "complete". All the elements are reached. 
    {
        result.push_back(current); 
    }

    for (int i = 0; i < nums.size(); ++i) //Explore all possible subsets that start with elements after the current index. 
    {
        if(!used[i])
        {
            current.push_back(nums[i]); //Choose. 
            used[i] = true; 
            backtrack(nums, used, current, result); //Explore. 
            current.pop_back(); //Unchoose. 
            used[i] = false; 
        } 
    }
}

/* An another solution without backstring : */

vector<vector<int>> permute_bis(vector<int>& nums) 
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end()); //Ascending order by default. 
    res.push_back (nums);
    while (next_permutation(nums.begin(),nums.end()))
    {
        res.push_back (nums);
    }
    return res;
}

int main()
{
    vector<int> nums{1,2,3}; 
    for(const vector<int>& v : permute(nums))
    {
        for(const int&  i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output : 
    1 2 3 
    1 3 2 
    2 1 3 
    2 3 1 
    3 1 2 
    3 2 1 */
    return 0; 
}