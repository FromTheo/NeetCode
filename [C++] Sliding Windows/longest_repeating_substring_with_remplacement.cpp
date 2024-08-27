#include <map> 
#include <string> 
#include <vector>
#include <iostream>

using namespace std; 

/* -------- Subject -------- 
You are given a string s consisting of only uppercase english characters and an integer k. 
You can choose up to k characters of the string and replace them with any other uppercase English character.
After performing at most k replacements, return the length of the longest substring which contains only one distinct character. */ 

int characterReplacement(string s, int k) 
{
    map<char, int> char_count;
    int left = 0;
    int max_count = 0;
    int max_length = 0;

    for (int right = 0; right < s.length(); ++right) 
    {
        char_count[s[right]]++;
        max_count = max(max_count, char_count[s[right]]);

        while ((right - left + 1) - max_count > k) 
        {
            char_count[s[left]]--;
            left++;
        }

        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

int main()
{
    string s = "AAABABB";
    int k = 1;
    cout << characterReplacement(s,k) << endl; //Output : 5 

    return 0; 
}