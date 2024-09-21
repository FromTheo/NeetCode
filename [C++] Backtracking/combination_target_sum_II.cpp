#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std; 

/* -------- Subject --------  
You are given an array of integers nums, which may contain duplicates, and a target integer target. 
Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
Each element from nums may be chosen at most once within a combination. The solution set must not contain duplicate combinations.
You may return the combinations in any order and the order of the numbers in each combination can be in any order. */ 

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result); 

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    vector<vector<int>> result;
    vector<int> current;  // Pour stocker la combinaison courante
    sort(candidates.begin(), candidates.end());

    backtrack(candidates, target, 0, current, result);
    return result;
}

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result)
{
    if (target == 0) //If target is reached  
    {
        result.push_back(current); 
        return;
    }
    
    for (int i = start; i < candidates.size(); ++i) 
    {
        if (i > start && candidates[i] == candidates[i - 1]) continue; //Skip the duplicates 
        if (target - candidates[i] >= 0)
        {
            current.push_back(candidates[i]); //Choose. 
            backtrack (candidates, target - candidates[i], i+1, current, result); //Explore. 
            current.pop_back(); //Unchoose. 
        }
    }
}

int main()
{
    vector<int> candidates{9,2,2,4,6,1,5}; 
    int target = 8; 
    for(const vector<int>& v : combinationSum2(candidates, target))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl;
    }
    /* Output : 
    1 2 5 
    2 2 4 
    2 6 */
    return 0; 
}