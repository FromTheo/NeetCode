#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject --------  
You are given a signed 32-bit integer x.
Return x after reversing each of its digits. After reversing, if x goes outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0 instead.
Solve the problem without using integers that are outside the signed 32-bit integer range. */

/* -------- Explanation --------
First, let's check if it's indeed on 32-bit; we return 0 if it's not the case. 
Then, we extract the digits composing x into a std::vector<int>. 
Now, through a for loop, we iterate over the powers of 10 in reverse to build the reverse integer, referred to as rep here. */

int reverse(int x) 
{
    int min = -1*std::pow(2,31);
    int max = std::pow(2,31)-1;

    if(x <= min or x >= max) return 0;

    vector<int> digits;
    int y = std::abs(x); 
    while(y != 0)
    {
        digits.push_back(y%10);
        y /= 10; 
    }
    
    int rep = 0; 
    for(int i = 0; i < digits.size(); ++i) 
    {
        rep += std::pow(10,i) * digits[digits.size()-i-1]; 
    }
    if(rep <= min or rep >= max) return 0;
    if(x>=0) return rep; 
    else return -rep; 
}

int main()
{
    int x = 1234, y = -1234, z = 1234236467;
    cout << reverse(x) << endl; //Output : 4321.
    cout << reverse(y) << endl; //Output : -4321.
    cout << reverse(z) << endl; //Output : 0.
    return 0; 
}