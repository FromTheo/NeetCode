#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std; 

/* -------- Subject --------  
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), 
find the minimum number of days required to schedule all meetings without any conflicts. */

/* -------- Explanation --------
We will create a std::map<int, int>, where we will associate each boundary of the interval with a key. There are two possibilities:
- For the left boundary, we increment (a meeting starts at this time).
- For the right boundary, we decrement (a meeting ends at this time).
Then, we initialize result and temp to 0.
We add all the keys (the times, either positive or negative) to temp, and result will simply be the maximum value that temp reaches. */ 

class Interval 
{
    public:
    int start, end;
    Interval(int start, int end) 
    {
        this->start = start;
        this->end = end;
    }
}; 

int minMeetingRooms(vector<Interval>& intervals) 
{
    map<int, int> count;
    for(Interval& interval : intervals) 
    {
        count[interval.start] ++;
        count[interval.end] --;
    }
    int result = 0, temp = 0; 
    for(const pair<int,int>& p : count) 
    {
        temp += p.second;
        result = max(result, temp);
    }
    return result;
}

int main()
{
    vector<Interval> v1{Interval(0,40),Interval(5,10),Interval(15,20)};    // Output : 2 
    cout << minMeetingRooms(v1) << endl; 
    return 0;
}