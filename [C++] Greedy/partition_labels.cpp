#include <map> 
#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given a string s consisting of lowercase english letters.
We want to split the string into as many substrings as possible, while ensuring that each letter appears in at most one substring.
Return a list of integers representing the size of these substrings in the order they appear in the string.*/ 



vector<int> partitionLabels(string s) 
{
    vector<int> resultat;
    map<char, int> lastOccurrence;

    for (int i = 0; i < s.size(); ++i) 
    {
        lastOccurrence[s[i]] = i;
    }

    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) 
    {
        end = max(end, lastOccurrence[s[i]]);

        if (i == end)  // If we have reached the end of the current partition 
        {
            resultat.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return resultat;
}

int main()
{
    string s = "xyxxyzbzbbisl", t = "abcabc"; 
    for(const int& i : partitionLabels(s))
    {
        cout << i << " "; 
    }
    cout << endl;
    // Output : 5 5 1 1 1 
    for(const int& i : partitionLabels(t))
    {
        cout << i << " "; 
    }   
    cout << endl; 
    //Output : 6
    return 0; 
}
