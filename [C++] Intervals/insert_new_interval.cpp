#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents the start and the end time of the ith interval. 
intervals is initially sorted in ascending order by start_i.
You are given another interval newInterval = [start, end].
Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and also intervals still does not have any overlapping intervals. 
You may merge the overlapping intervals if needed.
Return intervals after adding newInterval. */

/* -------- Explanation --------
Let's start by inserting the interval into the vector. 
We sort intervals according to the conditions given in the statements (i.e., in ascending order based on the left bound), using std::sort from <algorithm>.
Next, we want to make the intervals disjoint. To do this, we will create a std::vector<int> named prev, initialized with the first interval from intervals.
Through a for loop, and for each iteration, we will check if two intervals are disjoint. If they are not, we merge them. */ 

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    intervals.push_back(newInterval); 
    std::vector<std::vector<int>> resultat;
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b)
    {
        return a.front() < b.front();
    }); 
    std::vector<int> prev = intervals.front(); 
    for(int i = 1; i<intervals.size(); i++)
    {
        std::vector<int> intervalle = intervals[i]; 
        if(intervalle.front() <= prev.back()) 
        {
            prev.back() = std::max(prev.back(), intervalle.back()); 
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
    vector<vector<int>> v1{{1,3},{4,6}}, v2{{1,2},{3,5},{9,10}}; 
    vector<int> i1{2,5}, i2{6,7}; 

    for(const vector<int> & v : insert(v1,i1))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    // Output : 1 6 

    cout << endl; 
    for(const vector<int> & v : insert(v2,i2))
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output : 
    1 2 
    3 5 
    6 7 
    9 10 */
    return 0; 
}