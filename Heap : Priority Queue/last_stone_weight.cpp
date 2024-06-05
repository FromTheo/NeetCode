#include <iostream>
#include <vector> 
#include <queue>         //std::priority_queue 
#include <algorithm>     //std::max_element

using namespace std; 

/* -------- Subject --------  
You are given an array of integers stones where stones[i] represents the weight of the ith stone.
We want to run a simulation on the stones as follows:
At each step we choose the two heaviest stones, with weight x and y and smash them togethers : 
- If x == y, both stones are destroyed
- If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
Continue the simulation until there is no more than one stone remaining.
Return the weight of the last remaining stone or return 0 if none remain. */ 

/* -------- Explanation --------
I propose two solutions. They are based on the same principles.
- For the first solution, we use std::max_element to access x and y which we then remove. 
If x < y, we add y-x to stones. We stop as soon as there is at most one element left in stones.
Regarding the second solution, we assume the container std::priority_queue<T> is known. 
We will store all the elements of stones in it, where we can directly access the largest element using top(), and then remove it immediately with pop(). */


int lastStoneWeight(vector<int>& stones) 
{
    //Method 1: 

    /*while(stones.size()>1)
    {
        auto it = max_element(stones.begin(), stones.end()); 
        int y = *it; 
        stones.erase(it); 
        auto it2 = max_element(stones.begin(), stones.end()); 
        int x = *it2; 
        stones.erase(it2); 
        if(x < y) stones.push_back(y-x); 
    }
    if(stones.empty()) return 0; 
    else return stones.front(); */ 


    //Method 2: 
    priority_queue<int> Q; 
        for(const int & i : stones)
        {
            Q.push(i);
        }
        while(Q.size() >1)
        {
            int y = Q.top(); 
            Q.pop();
            int x = Q.top();
            Q.pop(); 
            if(x < y) Q.push(y-x); 
        }
        if(Q.empty()) return 0; 
        else return Q.top(); 
}

int main()
{
    vector<int> v1{2,3,6,2,4}, v2{1,2}; 
    cout << lastStoneWeight(v1) << endl; //Output : 1.
    cout << lastStoneWeight(v2) << endl; //Output : 1. 
    return 0; 
}