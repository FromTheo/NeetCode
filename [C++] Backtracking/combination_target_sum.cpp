#include <vector>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an array of distinct integers nums and a target integer target. 
Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
The same number may be chosen from nums an unlimited number of times.
Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
You may return the combinations in any order and the order of the numbers in each combination can be in any order. */ 

void backtrack(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result); 
vector<vector<int>> combinationSum(vector<int>& nums, int target); 

vector<vector<int>> combinationSum(vector<int>& nums, int target) 
{
    vector<vector<int>> result;
    vector<int> current;  // Pour stocker la combinaison courante

    backtrack(nums, target, 0, current, result);
    return result;
}

void backtrack(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result) 
{
    if (target == 0) //If target is reached  
    {
        result.push_back(current); 
        return;
    }
        
        // Parcourir les éléments de nums à partir de l'indice 'start'
    for (int i = start; i < nums.size(); ++i) 
    {
        if (target - nums[i] >= 0) 
        {
            current.push_back(nums[i]); //Choose. 
            backtrack(nums, target - nums[i], i, current, result); //Explore. 
            current.pop_back(); //Unchoose. 
        }
    }
}

int main()
{
    vector<int> v{3,4,5}; 
    int target = 16; 
    for(const vector<int>& vect : combinationSum(v, target))
    {
        for(const int&  i : vect)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output : 
    3 3 3 3 4 
    3 3 5 5 
    3 4 4 5 
    4 4 4 4 */
    
    return 0; 
}
