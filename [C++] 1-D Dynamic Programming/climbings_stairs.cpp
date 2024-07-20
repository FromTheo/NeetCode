#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an integer n representing the number of steps to reach the top of a staircase.
You can climb with either 1 or 2 steps at a time.
Return the number of distinct ways to climb to the top of the staircase.  */ 

/* -------- Explanation --------
The algorithm for counting the number of ways to climb stairs relies on an iterative principle.
By observing that to reach the nth step, there are two possibilities:
- Take two steps from the (n-2)th step.
- Take one step from the (n-1)th step. Storing this information in a vector rather than making repeated function calls helps reduce complexity. */

int climbStairs(int n) {
    if(n == 0 or n == 1) return 1; 
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
        
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    cout << climbStairs(30) << endl; //Output : 1346269.
    return 0; 
}