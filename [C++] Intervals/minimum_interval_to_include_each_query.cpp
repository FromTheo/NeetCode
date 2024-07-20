#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
You are given a 2D integer array intervals, where intervals[i] = [left_i, right_i] represents the ith interval starting 
at left_i and ending at right_i (inclusive).
You are also given an integer array of query points queries. 
The result of query[j] is the length of the shortest interval i such that left_i <= queries[j] <= right_i. 
If no such interval exists, the result of this query is -1.
Return an array output where output[j] is the result of query[j]. */

/* -------- Explanation --------
We enumerate all the elements of queries, placing in the vector measure all the measures of the intervals that contain the value. 
If this vector is empty, it means no interval was found: we add -1 to output. 
Otherwise, we add to output the smallest measure, accessible via std::min_element from <algorithm>. */ 

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
{
    vector<int> output; 
    for(const int &i : queries)
    {
        vector<int> measures;
        for(int j = 0; j < intervals.size(); ++j)
        {
            if(i <= intervals[j].back() && intervals[j].front() <= i)
            {
                measures.push_back(intervals[j].back()-intervals[j].front()+1);
            }
        }
        if(measures.empty()) output.push_back(-1); 
        else output.push_back(*min_element(measures.begin(), measures.end())); 
    }
    return output; 
}

int main()
{
    vector<vector<int>> v{{1,3},{2,3},{3,7},{6,6}}; 
    vector<int> queries{2,3,1,7,6,8}; 
    for(const int & i : minInterval(v,queries))
    {
        cout << i << " "; 
    }
    // Output : 2 2 3 5 1 -1 
    return 0; 
}

