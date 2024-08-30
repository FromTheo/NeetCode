#include <iostream>
#include <numeric>
#include <vector>

using namespace std; 

/* -------- Subject --------  
There are n gas stations along a circular route. You are given two integer arrays gas and cost where:
    - gas[i] is the amount of gas at the ith station.
    - cost[i] is the amount of gas needed to travel from the ith station to the (i + 1)th station. (The last station is connected to the first station)
You have a car that can store an unlimited amount of gas, but you begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index such that you can travel around the circuit once in the clockwise direction. If it's impossible, then return -1.
It's guranteed that at most one solution exists. */ 

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) 
{
    if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1; 

    int total = 0; 
    int res = 0; 
    for(int i = 0; i < gas.size(); ++i)
    {
        total += (gas[i] - cost[i]); 
        if(total < 0)
        {
            total = 0; 
            res = i+1; 
        } 
    }
    return res;
}

int main()
{
    cout << canCompleteCircuit(vector<int>{1,2,3,4}, vector<int>{2,2,4,1}) << endl; //Output : 3 (starting at the 3th index station)
    return 0; 
}

