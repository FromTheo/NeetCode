#include <iostream>
#include <vector> 
#include <string>
#include <unordered_set>

using namespace std; 

/* -------- Subject --------  
Given a string s, find the length of the longest substring without duplicate characters.
A substring is a contiguous sequence of characters within a string. */ 

/* -------- Explanation --------
We already handle the case where s is empty, in which case we return 0.
We create charSet, a set intended to keep unique characters.
We introduce maxLength to store the maximum length of the substring, and left, right for the window boundaries.
While right < n (i.e., while we haven't traversed all of s):
- If s[right] is not in the set, we add it, update maxLength, and increment right.
- Otherwise, we have a duplicate, so we remove s[left] from the set and increment left. */


int lengthOfLongestSubstring(string s) 
{
    int n = s.size();
    if (n == 0) return 0;

    unordered_set<char> charSet;
    int maxLength = 0, left = 0, right = 0;

    while (right < n) 
    {
        if (charSet.find(s[right]) == charSet.end()) 
        {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } 
        else 
        {
            charSet.erase(s[left]);
            left++;
        }
    }
    return maxLength;
}

int main()
{
    string s = "abcabcbb", t = "bbbbb", u = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl; //Output : 3
    cout << lengthOfLongestSubstring(t) << endl; //Output : 1
    cout << lengthOfLongestSubstring(u) << endl; //Output : 3
    return 0; 
}