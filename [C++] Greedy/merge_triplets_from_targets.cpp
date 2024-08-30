#include <map> 
#include <set> 
#include <vector>
#include <string>
#include <iostream> 
#include <algorithm> 

using namespace std; 

/* -------- Subject --------  
You are given a 2D array of integers triplets, where triplets[i] = [ai, bi, ci] represents the ith triplet. 
You are also given an array of integers target = [x, y, z] which is the triplet we want to obtain.

To obtain target, you may apply the following operation on triplets zero or more times:
- Choose two different triplets triplets[i] and triplets[j] and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
* E.g. if triplets[i] = [1, 3, 1] and triplets[j] = [2, 1, 2], triplets[j] will be updated to [max(1, 2), max(3, 1), max(1, 2)] = [2, 3, 2].
- Return true if it is possible to obtain target as an element of triplets, or false otherwise.*/ 

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)
{
    set<int> S; 
    if(find(triplets.begin(), triplets.end(), target) != triplets.end()) return true;
    for(const vector<int> & v : triplets)
    {
        if(target[0] < v[0] || target[1] < v[1] || target[2] < v[2]) continue; 
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] == target[i]) 
            {
                S.insert(i); 
            }
        }
    }
    return S.size() == 3; 
}

/* If we restrict ourselves to the case where we have to choose only 2 triplets, 
it is clear that one of the two (at least) must contain 2 elements from the target. Here is the code: */

vector<int> maximum(const vector<int>& v, const vector<int>& w) 
{
    vector<int> res(v.size());
    transform(v.begin(), v.end(), w.begin(), res.begin(), [](int i, int j) 
    {
        return max(i, j);
    });
    return res;
}

bool mergeTriplets_bis(vector<vector<int>>& triplets, vector<int>& target) 
{
    if (find(triplets.begin(), triplets.end(), target) != triplets.end()) return true;

    int a = target[0], b = target[1], c = target[2];

    auto is_equal = [](const vector<int>& v, const vector<int>& w) 
    {
        return (v[0] == w[0]) && (v[1] == w[1]) && (v[2] == w[2]);
    };

    auto has_two_elements_of_target = [a, b, c](const vector<int>& v) 
    {
        int count = 0;
        if (v[0] == a) count++;
        if (v[1] == b) count++;
        if (v[2] == c) count++;
        return count == 2;
    };

    auto it = find_if(triplets.begin(), triplets.end(), has_two_elements_of_target);
    if (it == triplets.end()) return false;

    vector<int> test = *it;
    for (const vector<int>& v : triplets) 
    {
        if (is_equal(maximum(test, v), target)) return true;
    }

    return false;
}

int main()
{
    vector<vector<int>> triplets = {{1,2,3},{7,1,1}}; 
    vector<int> target ={7,2,3};  
    cout << mergeTriplets(triplets, target) << endl; //Output : 1 
    return 0; 
}

