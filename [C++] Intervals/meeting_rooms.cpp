#include <iostream>
#include <vector>
#include <algorithm>        //std::sort

using namespace std; 

/* -------- Subject -------- 
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...]
(start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts.*/ 

/* -------- Explanation --------
I will sort 'intervals' in ascending order of start date using std::sort from <algorithm>.
Now, we just need to use a double for loop, comparing the end date of the current interval with the start date of the following ones.
If we find any interval that overlaps, we return false. If no overlapping interval is found, we return true. */

//Definition of Interval:
class Interval 
{
    public:
     int start, end;
     Interval(int start, int end) {this->start = start; this->end = end;}
};  


bool canAttendMeetings(vector<Interval>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](const Interval& i, const Interval& j)
    {
        return i.start < j.start;
    });
    for(int i = 0; i< intervals.size(); ++i)
    {
        for(int j = i+1; j < intervals.size(); ++j)
        {
            if(intervals[i].end > intervals[j].start) return false;
        }
    }
    return true; 
}

int main()
{
    vector<Interval> intervals1{Interval(0,30),Interval(5,10),Interval(15,20)}, intervals2{Interval(5,8), Interval(9,15)}; 
    cout << canAttendMeetings(intervals1) << endl; //Output : 0.
    cout << canAttendMeetings(intervals2) << endl; //Output : 1.
    return 0;
}
