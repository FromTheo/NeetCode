#include <vector>
#include <iostream> 
#include <map>          //std::map
#include <stack>        //std::stack

using namespace std; 

/* -------- Subject --------  
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.
The input string s is valid if and only if:
- Every open bracket is closed by the same type of close bracket.
- Open brackets are closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise. */ 

/* -------- Explanation --------
We will create a stack<char> that will contain all the open parentheses: '{', '[' or '('.
Let's also create a map<char,char> that will contain all the corresponding closed parentheses, with the same key but closed.
Now, iterating over the characters of s:
If x is a closing parenthesis:
-- If v is empty, then there is obviously no corresponding opening parenthesis: we return false.
-- If v.top() (the last opening parenthesis encountered and still in v) is different from the one we are looking for: we return false.
-- Otherwise, v.top() matches the opening parenthesis we are looking for, so we remove it from v with pop().
Otherwise, x is an opening parenthesis that we add to v.
After the for loop, if there are remaining elements in v (meaning there are opening parentheses that have never been closed), 
we return false. Otherwise, we return true. */

bool isValid(string s) 
{
    stack<char> v; 
    map<char,char> parentheses = { {')', '('}, {'}', '{'}, {']', '['} }; 
    for(const char& x : s)
    {
        if(parentheses.find(x) != parentheses.end())
        {
            if(v.empty())
            {
                return false; 
            }
            if(v.top() != parentheses[x])
            {
                return false; 
            }
            v.pop();
        }
        else 
        {
            v.push(x);
        }
    }
    return v.empty(); 
}

int main()
{
    string s = "[]", s2 = "([{}])", s3 = "[(])";
    cout << isValid(s) << endl;   //Output : 1.
    cout << isValid(s2) << endl;  //Output : 1.
    cout << isValid(s3) << endl;  //Output : 0.
    return 0; 
}