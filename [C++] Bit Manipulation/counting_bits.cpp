#include <vector>
#include <iostream>

using namespace std;

/* -------- Subject --------  
Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].
Return an array output where output[i] is the number of 1's in the binary representation of i. */

vector<int> countBits(int n) 
{
    vector<int> dp(n + 1);
    int offset = 1;

    for (int i = 1; i <= n; i++) 
    {
        if (offset * 2 == i) 
        {
            offset = i;
        }
        dp[i] = 1 + dp[i - offset];
    }
    return dp;
}

int main()
{
    for(const int& i : countBits(5))
    {
        cout << i << " "; 
    }
    //Output : 0 1 1 2 1 2
    return 0; 
}
