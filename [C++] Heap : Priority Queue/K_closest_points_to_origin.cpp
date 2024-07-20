#include <iostream>
#include <vector> 
#include <queue>      //std::priority_queue
#include <functional> //std::greater 

using namespace std; 


/* -------- Subject -------- 
You are given an 2-D array points where points[i] = [xi, yi] represents the coordinates of a point on an X-Y axis plane. 
You are also given an integer k.
Return the k closest points to the origin (0, 0).
The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).
You may return the answer in any order. */ 

/* -------- Explanation --------
I will present two methods.
- The first method does not use std::priority_queue. We sort the vector points by increasing distance from the origin. 
Then we just need to fill the resulting vector with the first k values from points.
The second method involves creating a priority_queue. We construct the lambda function compare so that it sorts the distances in decreasing order. 
We use decltype() to determine the type of compare and thus construct Q. 
We then fill it with the elements of points, and finally, fill the resulting vector using top() and pop(). */

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
    //Method 1: 
    /* auto compare = [](const vector<int>& s1, const vector<int>& s2)
    {
        return std::sqrt(s1.front()*s1.front()+s1.back()*s1.back()) < std::sqrt(s2.front()*s2.front()+s2.back()*s2.back());
    };
    std::sort(points.begin(), points.end(), compare);
    vector<vector<int>> res(k); 
    for(int i = 0; i < k ; ++i)
    {
        res[i] = points[i]; 
    }
    return res; */ 


    //Method 2: 
    auto compare = [](const vector<int>& s1, const vector<int>& s2)
    {
        return std::sqrt(s1.front()*s1.front()+s1.back()*s1.back()) > std::sqrt(s2.front()*s2.front()+s2.back()*s2.back());
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> Q(compare); 
    vector<vector<int>> res; 

    for(const vector<int>& p : points)
    {
        Q.push({p.front(), p.back()}); 
    }

    for(int i = 0; i < k; ++i)
    {
        res.push_back(Q.top());
        Q.pop(); 
    }
    return res;
}

int main()
{
    vector<vector<int>> points{{0,2}, {2,2}}, points2{{0,2}, {2,0}, {2,2}}; 
    int k = 1, k2 = 2;
    for(const vector<int>& v : kClosest(points, k))
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : 0 2
    for(const vector<int>& v : kClosest(points2, k2))
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    } 
    cout << endl; 
    /* Output : 0 2 
    2 0 */ 
    return 0; 
}