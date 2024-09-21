#include <vector>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given an array nums of unique integers, return all possible subsets of nums (2^n elements).
The solution set must not contain duplicate subsets. 
You may return the solution in any order. */ 

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result);
vector<vector<int>> subsets(vector<int>& nums);

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> current;

    backtrack(nums, 0, current, result);
        
    return result;
}
    
void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) 
{
    result.push_back(current); //Add the current subset to the result.
    cout << "ajout de current : "; 
    for(const int & i : current)
    {
        cout << i << " "; 
    }
    cout << endl; 
    for (int i = start; i < nums.size(); ++i) //Explore all possible subsets that start with elements after the current index. 
    {
        current.push_back(nums[i]); //Choose. 
        backtrack(nums, i + 1, current, result); //Explore. 
        current.pop_back(); //Unchoose. 
    }
}

int main()
{
    vector<int> nums{1,2,3}; 
    for(const vector<int> &v : subsets(nums))
    {
        for(const int & i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output : 
    \empty
    1 
    1 2 
    1 2 3 
    1 3 
    2 
    2 3 
    3 */ 

    return 0; 
}