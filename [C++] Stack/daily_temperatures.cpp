#include <vector>
#include <stack>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.
Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. 
If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead. */

//1st method: 
vector<int> dailyTemperatures(vector<int>& temp)
{
    vector<int> res(temp.size()); 
    stack<int> stack; 
    for(int i = 0; i < temp.size(); ++i)
    {
        while(!stack.empty() && temp[stack.top()] < temp[i])
        {
            res[stack.top()] = i - stack.top(); 
            stack.pop(); 
        }
        stack.push(i);
    }
    return res; 
}

//2nd method: 
vector<int> dailyTemperatures_bis(vector<int>& temperatures) 
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (temperatures[j] > temperatures[i]) 
            {
                res[i] = j - i;
                break;
            }
        }
    }
    return res; 
}

int main()
{
    vector<int> temp{30,38,30,36,35,40,28};
    for(const int& i : dailyTemperatures(temp))
    {
        cout << i << ", "; 
    }
    //Output : 1, 4, 1, 2, 1, 0, 0. 
    return 0; 
}