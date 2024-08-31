#include <iostream>
#include <algorithm> 
#include <vector> 
#include <utility>

using namespace std; 

/* -------- Subject --------  
There are n cars traveling to the same destination on a one-lane highway.
You are given two arrays of integers position and speed, both of length n.
- position[i] is the position of the ith car (in miles)
- speed[i] is the speed of the ith car (in miles per hour)
The destination is at position target miles.
A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.
A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.
If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.
Return the number of different car fleets that will arrive at the destination. */ 

int carFleet(int target, vector<int>& position, vector<int>& speed) 
{
    int n = position.size(); 
    vector<pair<double,double>> pairs(n); 
    for(int i = 0; i < n; ++i)
    {
        pairs[i] = make_pair(position[i], speed[i]); 
    }   
    sort(pairs.begin(), pairs.end(), [](const pair<double,double>& p, const pair<double,double> &q)
    {
        return q.first < p.first; 
    }); 

    int compteur = 0; 
    vector<double> time(n); 
    for(int i = 0; i < n; ++i)
    {
        time[i] = (target - pairs[i].first) / pairs[i].second; 
        if(i >= 1 && time[i] <= time[i-1])
        {
            time[i] = time[i-1]; 
        }
        else 
        {
            compteur++; 
        }
    }
    return compteur;
}

int main()
{
    int target = 10;
    vector<int> position{4,1,0,7}, speed{2,2,1,1}; 
    cout << carFleet(target, position, speed) << endl; //Output : 3 
    return 0; 
}