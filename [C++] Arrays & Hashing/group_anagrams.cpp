#include <string>
#include <vector>
#include <iostream> 
#include <map> 

using namespace std; 

/* -------- Subject --------  
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different. */ 

/* -------- Explanation --------
The idea here is to iterate through all the elements in strs using a for loop, copy them, and then sort them alphabetically. 
Next, we’ll store the resulting string in a std::map<string, std::vector<int>>, 
where std::vector<int> will contain all the anagrams present in strs. 
Finally, we need to add all these vectors to a std::vector<std::vector<string>> and return the result */

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<string, std::vector<string> > M; 
    for(const string& s: strs)
    {
        string copy = s; 
        sort(copy.begin(), copy.end()); 
        M[copy].push_back(s); 
    }
    vector<vector<string>> res; 
    for(const std::pair<string, std::vector<string>> &p : M)
    {
        res.push_back(p.second); 
    }
    return res; 
}

int main()
{
    vector<string> strs1{"act","pots","tops","cat","stop","hat"}, strs2{"x"}, strs3{""};
    for(const vector<string>& v : groupAnagrams(strs1))
    {
        for(const string& s : v)
        {
            cout << s << " ";
        }
        cout << endl; 
    }
    /* Output :
    act cat 
    hat 
    pots tops stop */ 
    cout << endl; 
    for(const vector<string>& v : groupAnagrams(strs2))
    {
        for(const string& s : v)
        {
            cout << s << " ";
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : x 
    for(const vector<string>& v : groupAnagrams(strs3))
    {
        for(const string& s : v)
        {
            cout << s << " ";
        }
        cout << endl; 
    }
    cout << endl; 
    //Output : ""

    return 0; 
}

