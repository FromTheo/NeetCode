#include <unordered_map>
#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject -------- 
You are given a stream of points consisting of x-y coordinates on a 2-D plane. Points can be added and queried as follows:
Add :  new points can be added to the stream into a data structure. Duplicate points are allowed and should be treated as separate points.
Query : Given a single query point, count the number of ways to choose three additional points from the data structure such that 
the three points and the query point form a square. The square must have all sides parallel to the x-axis and y-axis, i.e. 
no diagonal squares are allowed. Recall that a square must have four equal sides. */ 

class DetectSquares 
{
    private : 

    unordered_map<int,unordered_map<int,int>> Map; 

    public:
    
    DetectSquares() {}
    
    void add(vector<int> point) 
    {
        Map[point[0]][point[1]]++; 
    }
    
    int count(vector<int> point) 
    {
        int ans = 0, x1 = point[0], y1 = point[1]; 
        for(auto &[y2,_] : Map[x1])
        {
            if(y2 == y1) continue; 
            int dist = abs(y1-y2);
            ans += Map[x1][y2] * (Map[x1-dist][y2]* Map[x1-dist][y1] + Map[x1+dist][y2] * Map[x1+dist][y1]); 
        }
        return ans;
    }
};
