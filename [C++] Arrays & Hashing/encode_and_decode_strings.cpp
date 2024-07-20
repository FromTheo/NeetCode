#include <iostream>
#include <string>
#include <vector>

using namespace std; 

/* -------- Subject --------  
Design an algorithm to encode a list of strings to a single string. 
The encoded string is then decoded back to the original list of strings. */

/* -------- Explanation --------
- To encode the vector of strings, we will determine the size of each string component, 
then separate them with the character '#'. Once the size is converted to a string using the to_string() function, 
we add everything into the resulting string.
We then obtain a string in the form:
(size_1)#.....(size_2)#.....

- To decode this string, we will use the work done in the previous function. 
We initialize an integer i = 0 to indicate the current index. 
Of course, we stop when we reach the end. For each iteration (for each word, in fact), 
we count the number of letters between two '#'. This will give us the length of the word to decode: 
it will be the word s.substr(j+1, length). Thus, to move to the next word, we set i to the value j + 1 + length. */ 
 
string encode(vector<string>& strs) 
{
    string res = "";   
    for(const string& s : strs)
    {
        res += to_string(s.size()) + "#" + s; 
    }
    return res;
}

vector<string> decode(string s) 
{
    vector<string> result;
        
    int i = 0;
    while (i < s.size()) 
    {
        int j = i;
        while (s[j] != '#') 
        {
            j++;
        }
        int length = stoi(s.substr(i, j - i));
        string str = s.substr(j + 1, length);
        result.push_back(str);
        i = j + 1 + length;
    }
        
    return result;
}

int main()
{
    vector<string> strs1{"neet","code","love","you"}, strs2{"we","say",":","yes"};
    cout << encode(strs1) <<  endl; //Output : 4#neet4#code4#love3#you. 
    cout << encode(strs2) << endl; //Output : 2#we3#say1#:3#yes. 
    for(const string& s : decode(encode(strs1)))
    {
        cout << s << ", " ;
    }
    //Output : neet, code, love, you, 
    cout << endl; 
    for(const string& s : decode(encode(strs2)))
    {
        cout << s << ", " ;
    }
    //Output :we, say, :, yes, 
    cout << endl;
    return 0; 
}
