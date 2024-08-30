#include <map> 
#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given a string s which contains only three types of characters: '(', ')' and '*'.
Return true if s is valid, otherwise return false.
A string is valid if it follows all of the following rules:
    - Every left parenthesis '(' must have a corresponding right parenthesis ')'.
    - Every right parenthesis ')' must have a corresponding left parenthesis '('.
    - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    - A '*' could be treated as a right parenthesis ')' character or a left parenthesis '(' character, or as an empty string "". */

bool checkValidString(string s)
{
    int minOpen = 0; // Minimum number of '(' needed
    int maxOpen = 0; // Maximum number of ') possible

    for (const char& c : s) 
    {
        if (c == '(') 
        {
            minOpen++;
            maxOpen++;
        }
        else if (c == ')') 
        {
            minOpen--;
            maxOpen--;
        } 
        else //c == '*'
        {
            minOpen--; //'*' can be ')' or ''
            maxOpen++; //'*' can be '(' or '' 
        }
        if (maxOpen < 0) 
        {
            return false; //Too many closing parentheses
        }

        if (minOpen < 0) 
        {
            minOpen = 0; //Reset minOpen to 0 since we can treat '*' as empty
        }
    }

    return minOpen == 0;
}

int main()
{
    string s = "((**)", t = "(((*)"; 
    cout << checkValidString(s) << endl; //Output : 1
    cout << checkValidString(t) << endl; //Output : 0 
    return 0; 
}

