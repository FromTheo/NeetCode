#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase. 
After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor.
You may choose to start at the index 0 or the index 1 floor.
Return the minimum cost to reach the top of the staircase, i.e. just past the last index in cost.  */ 

/* -------- Explanation --------
We will use the very principle of dynamic programming : calculate the Bellman functions, the minimum cost will be J_0. 
Each J_n is calculated based on  higher than n values, in the form of inf{min + transition_cost}. It is not necessary to provide an explicit
exxpression for J_n, n >= 1.
Thus, J_0 will be the minimum beetween the cost at 0 and the cost at 1. 
To visualize this, we can think of a binary tree where each branch represents the number of steps we choose to take. Therefore we seek to find the leftmost values
in the tree. */

int minCostClimbingStairs(vector<int>& cost) {
    for(int i = cost.size()-3; i>=0; --i)
    {
        cost[i] += std::min(cost[i+1], cost[i+2]); 
    }
    return std::min(cost[0], cost[1]); 
}

int main()
{
    vector<int> cost1{1,2,3}, cost2{1,2,1,2,1,1,1};
    cout << minCostClimbingStairs(cost1) << endl; //Output : 2.
    cout << minCostClimbingStairs(cost2) << endl; //Output : 4.

    return 0; 
}