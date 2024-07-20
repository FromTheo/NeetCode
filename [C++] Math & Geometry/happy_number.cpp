#include <iostream>
#include <unordered_set> 

using namespace std; 

/* -------- Subject -------- 
A non-cyclical number is an integer defined by the following algorithm:
- Given a positive integer, replace it with the sum of the squares of its digits.
- Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
- If it stops at 1, then the number is a non-cyclical number.
Given a positive integer n, return true if it is a non-cyclical number, otherwise return false. */ 

/* -------- Explanation --------
Let's first implement a helper function 'nextNumber' that replaces a number with the sum of the squares of its digits.
Within the 'isHappy' function, create a std::unordered_set to store the successive values, and stop as soon as n == 1
or when there is a repetition (which indicates an infinite loop).
We return true if n == 1 and false otherwise. */

int nextNumber(int n)
{
    int newNumber = 0; 
    while(n!=0)
    {
        int num = n%10; 
        newNumber += num*num; 
        n /=10; 
    }
    return newNumber; 
}

bool isHappy(int n)
{
    unordered_set<int> S;
    while(n!=1 && !S.count(n))
    {
        S.insert(n); 
        n = nextNumber(n); 
    }
    return n==1; 
}

int main()
{
    cout << isHappy(100) << endl; //Output : 1.
    cout << isHappy(101) << endl; //Output : 0. 
    return 0; 
}