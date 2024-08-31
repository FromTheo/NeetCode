#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses. */

void backtrack(vector<string>& ans, int n, int open, int close, string cur_str) 
{
    if (cur_str.size() == n * 2) 
    {
        ans.push_back(cur_str);
        return;
    }
    if (open < n) backtrack(ans, n, open + 1, close, cur_str + "(");
    if (close < open) backtrack(ans, n, open, close + 1, cur_str + ")");
}

vector<string> generateParenthesis(int n) 
{
    vector<string> ans;
    backtrack(ans, n, 0, 0, "");
    return ans;
}

int main()
{
    for(const string& s : generateParenthesis(4))
    {
        cout << s << ", "; 
    }
    cout << endl; 
    //Output : (((()))), ((()())), ((())()), ((()))(), (()(())), (()()()), (()())(), (())(()), (())()(), ()((())), ()(()()), ()(())(), ()()(()), ()()()(). 
    return 0; 
}
