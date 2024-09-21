#include <vector>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an integer array nums where nums[i] represents the amount of money the ith house has. 
The houses are arranged in a circle, i.e. the first house and the last house are neighbors.
You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically 
alert the police if two adjacent houses were both broken into.
Return the maximum amount of money you can rob without alerting the police. */ 

// Either we rob from the first first to the penultimate house, or we rob from the second to the last house 

int rob(const vector<int>& nums) 
{
    if(nums.size() == 1) return nums.front(); 
    if(nums.size() == 2) return max(nums.front(), nums.back()); 

    auto rob_test = [](vector<int>& v)
    { 
        int rob1 = 0; 
        int rob2 = 0; 
        for(int i = 0; i < v.size(); ++i)
        {
            int temp = max(v[i] + rob1, rob2); 
            rob1 = rob2; 
            rob2 = temp; 
        }
        return rob2; 
    }; 

    vector<int> nums_1(nums.begin(), nums.end()-1); 
    vector<int> nums_2(nums.begin()+1, nums.end()); 
    return max(rob_test(nums_1), rob_test(nums_2)); 
}

int main()
{
    cout << rob(vector<int>{3,4,3}) << endl;       //Output : 4
    cout << rob(vector<int>{2,9,8,3,6}) << endl;   //Output : 15 

    return 0; 
}