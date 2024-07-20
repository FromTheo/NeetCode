#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
Given an array of intervals intervals where intervals[i] = [start_i, end_i], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note: Intervals are non-overlapping even if they have a common point. For example, [1, 3] and [2, 4] are overlapping, 
but [1, 2] and [2, 3] are non-overlapping. */

/* -------- Explanation --------
Let's start by sorting the vector intervals using std::sort from <algorithm>. Then, through a for loop, we will check if the intervals are pairwise disjoint. 
There are two cases:
- They are disjoint, we do nothing.
- The right bound of the current interval is greater than the left bound of the next one, in this case, they are not disjoint, 
so we increment `compteur` and update the test value (which actually corresponds to the right bound). */

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](const vector<int>& v, const vector<int>& w)
    {
        return v.front() < w.front();
    }); 

    int compteur = 0;
    int prevEnd = intervals.front().back(); 

    for (int i = 1; i < intervals.size(); i++) 
    {
        int start = intervals[i].front();
        int end = intervals[i].back(); 
        if (start >= prevEnd) 
        {
            prevEnd = end;
        } 
        else 
        {
            compteur++;
            prevEnd = min(end, prevEnd);
        }
    }
    return compteur;
}

int main()
{
    vector<vector<int>> v1{{1,2},{2,4},{1,4}}, v2{{1,2},{2,4}}; 
    cout << eraseOverlapIntervals(v1) << endl;  //Output : 1
    cout << eraseOverlapIntervals(v2) << endl;  //Output : 0
    return 0; 
}