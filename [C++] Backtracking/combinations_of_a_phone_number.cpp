#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given a string digits made up of digits from 2 through 9 inclusive.
Each digit (not including 1) is mapped to a set of characters as shown below:
A digit could represent any one of the characters it maps to.
Return all possible letter combinations that digits could represent. You may return the answer in any order. */

void backtrack(const string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping);

vector<string> letterCombinations(string digits) 
{
    if (digits.empty()) 
    {
        return {};
    }
        
    vector<string> result;
    string current; 
        
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    backtrack(digits, 0, current, result, mapping);
        
    return result;
}
    
void backtrack(const string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping) 
{
    if (index == digits.length()) //If we have processed all digits. 
    {
        result.push_back(current);
        return;
    }
    
    string letters = mapping[digits[index] - '0'];
        
    for (const char& letter : letters) 
    {
        current.push_back(letter);  //Choose.
        backtrack(digits, index + 1, current, result, mapping); //Research. 
        current.pop_back();  //Unchoose. 
    }
}

int main()
{
    string digits = "34"; 
    for(const string& s : letterCombinations(digits))
    {
        cout << s << ", "; 
    }
    cout << endl; 
    //Output : dg, dh, di, eg, eh, ei, fg, fh, fi

    return 0; 
}