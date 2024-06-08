#include <iostream>
#include <vector>
#include <string> 

using namespace std; 

/* -------- Subject --------  
Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. 
It is also case-insensitive and ignores all non-alphanumeric characters. */

/* -------- Explanation --------
We are going to filter the characters in s, keeping only the digits and letters. 
For this, we will need the function isalpha(x) (respectively isdigit(x)) which returns true if x is a letter (respectively a digit).
We will also need to transform all the letters to lowercase using the function std::tolower(). 
Once this is done, we will simply need to check if each element is equal to its symmetrical counterpart. */

bool isPalindrome(string s) 
{   
    std::vector<char> t; 
    char space = ' '; 
    for(char& x: s)
    {   
        if(x != space && (isalpha(x) or isdigit(x)))
        {
            x = std::tolower(x); 
            t.push_back(x);
        }
    }
    for(int i = 0; i<t.size(); i++)
    {
        if(t[i] != t[t.size()-i-1]) return false; 
    }
    return true; 
}

int main()
{
    string s1 = "Was it a car or a cat I saw?";
    string s2 = "tab a cat";  
    cout << isPalindrome(s1) << endl; //Output : 1. 
    cout << isPalindrome(s2) << endl; //Output : 0. 
    return 0; 
}


