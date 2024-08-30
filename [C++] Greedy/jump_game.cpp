#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an integer array nums where each element nums[i] indicates your maximum jump length at that position.
Return true if you can reach the last index starting from index 0, or false otherwise. */ 

bool canJump(const vector<int>& nums) 
{
    int target = nums.size() - 1; 

    for(int i = nums.size() - 2; i >=0; i--)
    {
        if(i + nums[i] >= target) target = i; 
    }

    return target == 0;
}

int main()
{
    cout << canJump(vector<int>{1,2,0,1,0}) << endl; //Output : 1 
    return 0; 
}