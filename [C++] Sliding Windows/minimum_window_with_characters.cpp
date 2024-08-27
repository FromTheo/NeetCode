#include <iostream>
#include <vector>
#include <string>

using namespace std; 

/* -------- Subject --------  
Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. 
If such a substring does not exist, return an empty string "".
You may assume that the correct output is always unique. */ 

/* -------- Explanation --------
Let's start by eliminating the edge cases, which is when s (or t) is empty, or when s is smaller than t (so there is no possible substring).
Initialize map, a vector of size 128, to store the frequencies of the 128 ASCII characters. To fill it, we will iterate over the string t.
Next, we introduce 4 integers: start and end, both initialized to 0, acting as pointers to delimit the search in the string s, minLen initialized to INT_MAX, 
which will contain the smallest length found, and startIndex, the index where we need to be in s to find this sequence.
Now, let's loop until end == s.size().
If the value associated with the current character in map is positive before decrementing it and incrementing end, then decrement count.
When all characters are found (count == 0), if the sequence found is shorter than minLen, update minLen and set startIndex to start.
Finally, if the value associated with the current character in map is zero before incrementing it and incrementing start, then increment count. */

std::string minWindow(std::string s, std::string t) 
{
    if (s.empty() || t.empty() || s.length() < t.length()) 
    {
        return "";
    }

    std::vector<int> map(128, 0);
    for (const char& c : t) 
    {
        map[c]++;
    }

    int count = t.length();
    int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
    
    while (end < s.length()) 
    {
        if (map[s[end++]]-- > 0) 
        {
            count--;
        }

        while (count == 0) 
        {
            if (end - start < minLen) 
            {
                startIndex = start;
                minLen = end - start;
            }

            if (map[s[start++]]++ == 0) 
            {
                count++;
            }
        }
    }

    if(minLen == INT_MAX) return "";
    return s.substr(startIndex, minLen);
}

int main()
{
    string s ="ADOBECODEBANC", t="ABC"; 
    cout << minWindow(s,t) << endl; //Output : BANC
    return 0; 
}
