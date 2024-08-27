#include <string> 
#include <vector>
#include <iostream>

using namespace std; 

/* -------- Subject -------- 
You are given two strings s1 and s2.
Return true if s2 contains a permutation of s1, or false otherwise. 
That means if a permutation of s1 exists as a substring of s2, then return true.
Both strings only contain lowercase letters. */ 

bool checkInclusion(string s1, string s2) 
{
    int n1 = s1.length();
    int n2 = s2.length();
        
    if (n1 > n2) return false;
        
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
        
    for (int i = 0; i < n1; ++i) 
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    
    if (count1 == count2) return true;
        
    for (int i = n1; i < n2; ++i) 
    {
        count2[s2[i] - 'a']++;
        count2[s2[i - n1] - 'a']--;
        if (count1 == count2) return true;
    }
        
    return false;
}

int main()
{
    string s1 = "abc", s2 = "lecaabee"; 
    cout << checkInclusion(s1, s2) << endl; //Output : 0 

    return 0; 
}
