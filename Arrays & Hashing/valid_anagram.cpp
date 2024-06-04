#include <string>
#include <algorithm> 
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different. */ 

/* -------- Explanation --------
The idea here is to sort the two strings in alphabetical order and return true if they are equal. */

bool isAnagram(string s, string t)
{
    std::sort(s.begin(), s.end(), [](const char&x, const char& y){
        return x < y; 
    }); 
    std::sort(t.begin(), t.end(), [](const char&x, const char& y){
        return x < y; 
    }); 
    return s == t;
}

int main()
{
    string s1 = "racecar";
    string t1 = "carrace"; 
    string s2 = "jar";
    string t2 = "jam";
    cout << isAnagram(s1,t1) << endl; //Output : 1. 
    cout << isAnagram(s2,t2) << endl; //Output : 0. 

    return 0; 
}
