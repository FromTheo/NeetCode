#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std; 

/* -------- Subject --------  
Given a string s, split s into substrings where every substring is a palindrome. Return all possible lists of palindromic substrings.
You may return the solution in any order. */ 

void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& result); 
bool isPalindrome(const string& s, int start, int end); 

vector<vector<string>> partition(string s) 
{
    vector<vector<string>> result;
    vector<string> current;  //To store the current partition. 
        
    backtrack(s, 0, current, result);
        
    return result;
}
    
void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& result)
{
    if (start == s.length()) //If we have explored the entire string s. 
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < s.length(); ++i) 
    {
        if (isPalindrome(s, start, i)) //Check if the substring s[start...i] is a palindrome
        {
            //If it's a palindrome, choose this substring.
            string palindrome = s.substr(start, i - start + 1);
            current.push_back(palindrome);
                
            //Recursively try to partition the rest of the string starting from i+1. 
            backtrack(s, i + 1, current, result);
                
            //Backtrack: remove the last added substring. 
            current.pop_back();
        }
    }
}
    
bool isPalindrome(const string& s, int start, int end) //Function to check if a substring s[start...end] is a palindrome. 
{
    while (start < end) //Using two pointers. 
    {
        if (s[start] != s[end]) 
        {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main()
{
    string s = "aab";
    for(const vector<string>& v : partition(s))
    {
        for(const string& t : v)
        {
            cout << t << " " ; 
        }
        cout << endl; 
    }
    /* Output : 
    a a b 
    aa b */

    return 0; 
}
