#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
You may return the answer in any order. */

/* -------- Explanation --------
We start by sorting the vector intervals using std::sort from <algorithm>. 
Through a for loop, we will check if the intervals are pairwise disjoint, and if they are, we add the last one. 
Otherwise, we replace the test interval with the union of the two. Finally, we return the solution vector. */ 

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<std::vector<int>> resultat;
    sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b)
    {
        return a.front() < b.front();
    }); 
    vector<int> prev = intervals.front(); 
    for(int i = 1; i<intervals.size(); i++)
    {
        vector<int> intervalle = intervals[i]; 
        if(intervalle.front() <= prev.back()) 
        {
            prev.back() = max(prev.back(), intervalle.back()); 
        }
        else
        {
            resultat.push_back(prev); 
            prev = intervalle; 
        }
    }
    resultat.push_back(prev); 
    return resultat; 
}

int main()
{
    vector<std::vector<int> > intervals1{{1,3},{2,6},{8,10},{15,18}}; 
    vector<std::vector<int> > intervals2{{0,5}, {1,4}}; 
    for(const vector<int>& v : merge(intervals1))
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    cout << "\n"; 
    /* Output : 
    1 6 
    8 10 
    15 18 */

    for(const std::vector<int>& v : merge(intervals2))
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    // Output : 0 5 
    return 0; 
}